#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#include "base.h"

void litbase_init(litbase_t *lb)
{
    lb->lb_lits_size = 0;
    lb->lb_lits = malloc(0);
}

int32_t litbase_lit(litbase_t *lb, const char *lname)
{
    int32_t lid = litbase_lookup_id(lb, lname);
    if (lid != -1)
        return lid;
    
    lb->lb_lits_size++;
    lb->lb_lits = realloc(lb->lb_lits, lb->lb_lits_size * sizeof(lit_t));
    lb->lb_lits[lb->lb_lits_size-1].l_id = lb->lb_lits_size - 1;
    lb->lb_lits[lb->lb_lits_size-1].l_name = strdup(lname);

    return lb->lb_lits_size - 1;
}

const char *litbase_lookup_name(const litbase_t *lb, int32_t lid)
{
    if (lid < lb->lb_lits_size)
        return lb->lb_lits[lid].l_name;
    else return NULL;
}

int32_t litbase_lookup_id(const litbase_t *lb, const char *lname)
{
    for (size_t i = 0; i < lb->lb_lits_size; i++)
        if (strcmp(lb->lb_lits[i].l_name, lname) == 0)
            return lb->lb_lits[i].l_id;
    return -1;
}

void litbase_print(const litbase_t *lb)
{
    printf("literals[%ld]\n", lb->lb_lits_size);
    for (size_t i = 0; i < lb->lb_lits_size; i++)
        printf(" %d: %s\n", lb->lb_lits[i].l_id, lb->lb_lits[i].l_name);
}


void rulebase_init(rulebase_t *rb)
{
    rb->rb_rules_size = 0;
    rb->rb_rules = malloc(rb->rb_rules_size * sizeof(rule_t));
}

void rulebase_insert(rulebase_t *rb, const rule_t *r)
{
    rb->rb_rules = realloc(rb->rb_rules, (rb->rb_rules_size + 1) * sizeof(rule_t));
    rb->rb_rules[rb->rb_rules_size++] = *r;
}

void rulebase_remove(rulebase_t *rb, const rule_t *r)
{
    if (r < rb->rb_rules || r >= &rb->rb_rules[rb->rb_rules_size])
        return;
    memmove((void*)r, &r[1], &rb->rb_rules[rb->rb_rules_size + 1] - &r[1]);
    rb->rb_rules_size--;
}

ssize_t rulebase_read(rulebase_t *rb, litbase_t *lb, FILE *f)
{
    const char *begtoken = ": Si ", *endtoken = " Entonces ";
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    if ((nread = getline(&line, &len, f)) < 0) {
        fprintf(stderr, "error reading: %s\n", strerror(errno));
        return -1;
    }

    rb->rb_rules_size = strtoll(line, NULL, 10);
    rb->rb_rules = malloc(rb->rb_rules_size * sizeof(rule_t));
    memset(rb->rb_rules, 0, rb->rb_rules_size * sizeof(rule_t));

    for (size_t i = 0; i < rb->rb_rules_size; i++) {
        if ((nread = getline(&line, &len, f)) < 0) {
            fprintf(stderr, "error reading: %s\n", strerror(errno));
            goto error;
        }

        /* check rule id prefix R */
        if (line[0] != 'R') {
            fprintf(stderr, "syntax error on line %ld: rid not prefixed by 'R'\n", i);
            goto error;
        }

        char *sep = NULL;   /* separator ": Si " */
        rb->rb_rules[i].r_id = strtoll(&line[1], &sep, 10);

        /* check separator */
        if (strlen(sep) < 5 || strncmp(sep, begtoken, strlen(begtoken)) != 0) {
            fprintf(stderr, "syntax error on line %ld: rid not followed by ': Si '\n", i);
            goto error;
        }

        /* find operator */
        char *lit = sep + strlen(begtoken);
        char *space = strchr(lit, ' '); /* find first space after first literal */
        char op = space[1]; /* assume first space is followed by operator */
        rb->rb_rules[i].r_inputs_size = 0;
        if (op != 'y' && op != 'o' &&
            !(strlen(space) < strlen(endtoken) || strncmp(space, endtoken, strlen(endtoken)) == 0))
        {
            fprintf(stderr, "syntax error on line %ld: invalid operator: %s\n", i, space);
            goto error;
        }

        rb->rb_rules[i].r_oper = op == 'y' ? OPER_AND : OPER_OR;

        /* read literals */
        while (1) {
            /* checkout literal */
            sep = strchr(lit, ' '); /* find space after literal */
            *sep = '\0';
            uint8_t lid = litbase_lit(lb, lit);

            /* store literal */
            rb->rb_rules[i].r_inputs[rb->rb_rules[i].r_inputs_size++] = lid;

            /* check operator */
            if (sep[0] != '\0' || sep[1] != op || sep[2] != ' ') {
                /* check end token */
                if (strlen(sep + 1) - 1 < strlen(endtoken) ||
                    strncmp(sep + 1, endtoken + 1, strlen(endtoken) - 1) == 0)
                {
                    break; /* continue reading output */
                } else {
                    fprintf(stderr, "syntax error on line %ld: wrong separator\n",
                        i);
                    goto error;
                }
            }

            lit = sep + 3;
        }

        char *output = sep + strlen(endtoken);

        /* output literal */
        sep = strchr(output, ',');
        *sep = '\0';
        uint8_t lid = litbase_lit(lb, output);

        /* store output */
        rb->rb_rules[i].r_output = lid;

        /* check FC syntax */
        if (strlen(sep + 1) < 4 || strcmp(sep + 1, " FC=") == 0) {
            fprintf(stderr,
                "syntax error on line %ld: output literal not followed by ', FC='\n",
                i);
            goto error;
        }

        /* store FC */
        rb->rb_rules[i].r_cert = strtof(sep + 5, NULL);
    }

    free(line);
    return rb->rb_rules_size;

error:
    free(rb->rb_rules);
    free(line);
    return -1;
}

void rulebase_print(const rulebase_t *rb, const litbase_t *lb)
{
    printf("rules[%ld]:\n", rb->rb_rules_size);
    for (size_t i = 0; i < rb->rb_rules_size; i++) {
        printf(" r%ld: if ", rb->rb_rules[i].r_id);

        for (int j = 0; j < rb->rb_rules[i].r_inputs_size; j++) {
            printf("%s", litbase_lookup_name(lb, rb->rb_rules[i].r_inputs[j]));
            if (j < rb->rb_rules[i].r_inputs_size - 1)
                printf(" %c ", "^|"[rb->rb_rules[i].r_oper]);
        }
        printf(" -> %s, fc=%f\n", litbase_lookup_name(lb, rb->rb_rules[i].r_output), rb->rb_rules[i].r_cert);
    }
}

void factbase_insert(factbase_t *fb, int32_t l)
{
    fb->fb_facts_size++;
    fb->fb_facts = realloc(fb->fb_facts, fb->fb_facts_size * sizeof(fact_t));
    fb->fb_facts[fb->fb_facts_size - 1].f_lits_size = 1;
    fb->fb_facts[fb->fb_facts_size - 1].f_lits[0] = l;
    fb->fb_facts[fb->fb_facts_size - 1].f_oper = 0;
}

int factbase_read(factbase_t *fb, litbase_t *lb, FILE *f)
{
    const char *endtoken = ", FC=";
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    if ((nread = getline(&line, &len, f)) < 0) {
        fprintf(stderr, "error reading: %s\n", strerror(errno));
        return -1;
    }

    fb->fb_facts_size = strtoll(line, NULL, 10);
    fb->fb_facts = malloc(fb->fb_facts_size * sizeof(fact_t));
    memset(fb->fb_facts, 0, fb->fb_facts_size * sizeof(fact_t));

    for (size_t i = 0; i < fb->fb_facts_size; i++) {
        if ((nread = getline(&line, &len, f)) < 0) {
            fprintf(stderr, "error reading: %s\n", strerror(errno));
            goto error;
        }

        /* find operator */
        char *lit = line;
        char *space = strchr(lit, ' '); /* find first space after first literal */
        char op = space[1]; /* assume first space is followed by operator */
        fb->fb_facts[i].f_lits_size = 0;
        if (op != 'y' && op != 'o' &&
            !(strlen(space) < 10 || strncmp(space, endtoken, 10) == 0))
        {
            fprintf(stderr, "syntax error on line %ld: invalid operator\n", i);
            goto error;
        }

        fb->fb_facts[i].f_oper = op == 'y' ? OPER_AND : OPER_OR;

        char *sep = NULL;

        /* read literals */
        while (1) {
            /* check literal */
            sep = strpbrk(lit, ", ");
            *sep = '\0';
            int32_t lid = litbase_lit(lb, lit);

            /* store literal */
            fb->fb_facts[i].f_lits[fb->fb_facts[i].f_lits_size++] = lid;

            /* check operator */
            if (sep[0] != '\0' || sep[1] != op || sep[2] != ' ') {
                /* check end token */
                if (strlen(sep + 1) < strlen(endtoken + 1) ||
                    strncmp(sep + 1, endtoken + 1, strlen(endtoken + 1)) == 0)
                {
                    break; /* continue reading output */
                } else {
                    fprintf(stderr, "syntax error on line %ld: wrong separator: '%s'\n",
                        i, sep + 1);
                    goto error;
                }
            }

            lit = sep + 3;
        }

        /* store FC */
        fb->fb_facts[i].f_cert = strtof(sep + 5, NULL);
    }

    /* read objective end token */
    if ((nread = getline(&line, &len, f)) < 0) {
        fprintf(stderr, "error reading: %s\n", strerror(errno));
        goto error;
    }

    char *lterm = NULL;
    if ((lterm = strstr(line, "\r\n"))) {
        lterm[0] = '\n';
        lterm[1] = '\0';
    }
    if ((lterm = strchr(line, '\n'))) {
        lterm[0] = '\0';
    }

    if (strcmp(line, "Objetivo") != 0) {
        fprintf(stderr, "syntax error on line %ld: 'Objetivo' expected: '%s'\n", nread, line);
        goto error;
    }

    /* read objective */
    if ((nread = getline(&line, &len, f)) < 0) {
        fprintf(stderr, "error reading: %s\n", strerror(errno));
        goto error;
    }

    char *end = strpbrk(line, "\r\n");
    *end = '\0';
    int32_t lid = litbase_lit(lb, line);

    fb->fb_goal = lid;

    free(line);
    return fb->fb_facts_size;

error:
    free(fb->fb_facts);
    free(line);
    return -1;
}

void factbase_print(const factbase_t *fb, const litbase_t *lb)
{
    printf("facts[%ld]:\n", fb->fb_facts_size);
    for (size_t i = 0; i < fb->fb_facts_size; i++) {
        printf(" f: ");

        for (int j = 0; j < fb->fb_facts[i].f_lits_size; j++) {
            printf("%s", litbase_lookup_name(lb, fb->fb_facts[i].f_lits[j]));
            if (j < fb->fb_facts[i].f_lits_size - 1)
                printf(" %c ", "^|"[fb->fb_facts[i].f_oper]);
        }
        printf(", fc=%f\n", fb->fb_facts[i].f_cert);
    }
    printf(" goal: %s\n", litbase_lookup_name(lb, fb->fb_goal));
}

void factbase_clone(factbase_t *ofb, const factbase_t *ifb)
{
    ofb->fb_goal = ifb->fb_goal;
    ofb->fb_facts_size = ifb->fb_facts_size;
    if (ofb->fb_facts)
        ofb->fb_facts = realloc(ofb->fb_facts, ifb->fb_facts_size * sizeof(fact_t));
    else
        ofb->fb_facts = malloc(ifb->fb_facts_size * sizeof(fact_t));
    memcpy(ofb->fb_facts, ifb->fb_facts, ifb->fb_facts_size * sizeof(fact_t));
}

