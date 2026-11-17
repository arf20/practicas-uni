#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#include "sbr.h"

#define VEC_INIT_SIZE   32

ssize_t read_rules(FILE *f, rulebase_t *rb)
{
    const char *endtoken = " Entonces ";
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
        if (strlen(sep) < 5 || strncmp(sep, ": Si ", 5) != 0) {
            fprintf(stderr, "syntax error on line %ld: rid not followed by ': Si '\n", i);
            goto error;
        }

        /* find operator */
        char *lit = sep + 5;
        char *space = strchr(lit, ' '); /* find first space after first literal */
        char op = space[1]; /* assume first space is followed by operator */
        rb->rb_rules[i].r_inputs_size = 0;
        if (op != 'y' && op != 'o' &&
            !(strlen(space) < 10 || strncmp(space, endtoken, 10) == 0))
        {
            fprintf(stderr, "syntax error on line %ld: invalid operator\n", i);
            goto error;
        }

        rb->rb_rules[i].r_oper = op == 'y' ? OPER_AND : OPER_OR;

        /* read literals */
        while (1) {
            /* check literal prefix h */
            if (lit[0] != 'h') {
                fprintf(stderr,
                    "syntax error on line %ld: literal not prefixed by 'h'\n",
                    i);
                goto error;
            }

            /* store literal */
            rb->rb_rules[i].r_inputs[rb->rb_rules[i].r_inputs_size++] = strtol(lit + 1, &sep, 10);

            /* check operator */
            if (sep[0] != ' ' || sep[1] != op || sep[2] != ' ') {
                /* check end token */
                if (strlen(sep) < strlen(endtoken) ||
                    strncmp(sep, endtoken, strlen(endtoken)) == 0)
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

        char *output = sep + 10;

        /* output literal prefix h */
        if (output[0] != 'h') {
            fprintf(stderr,
                "syntax error on line %ld: output literal not prefixed by 'h': %s\n",
                i, output);
            goto error;
        }

        /* store output */
        rb->rb_rules[i].r_output = strtol(&output[1], &sep, 10);

        /* check FC syntax */
        if (strlen(sep) < 5 || strcmp(sep, ", FC=") == 0) {
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

void print_rules(const rulebase_t *rb) {
    printf("rules[%ld]:\n", rb->rb_rules_size);
    for (size_t i = 0; i < rb->rb_rules_size; i++) {
        printf(" r%ld: if ", rb->rb_rules[i].r_id);

        for (int j = 0; j < rb->rb_rules[i].r_inputs_size; j++) {
            printf("h%d", rb->rb_rules[i].r_inputs[j]);
            if (j < rb->rb_rules[i].r_inputs_size - 1)
                printf(" %c ", "^|"[rb->rb_rules[i].r_oper]);
        }
        printf(" -> h%d, fc=%f\n", rb->rb_rules[i].r_output, rb->rb_rules[i].r_cert);
    }
}

int read_facts(FILE *f, factbase_t *fb)
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
            /* check literal prefix h */
            if (lit[0] != 'h') {
                fprintf(stderr,
                    "syntax error on line %ld: literal not prefixed by 'h'\n",
                    i);
                goto error;
            }

            /* store literal */
            fb->fb_facts[i].f_lits[fb->fb_facts[i].f_lits_size++] = strtol(lit + 1, &sep, 10);

            /* check operator */
            if (sep[0] != ' ' || sep[1] != op || sep[2] != ' ') {
                /* check end token */
                if (strlen(sep) < strlen(endtoken) ||
                    strncmp(sep, endtoken, strlen(endtoken)) == 0)
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

    if (line[0] != 'h') {
        fprintf(stderr, "syntax error on line %ld: literal not prefixed by 'h' \n",
            nread + 1);
        goto error;
    }

    fb->fb_goal = strtol(&line[1], NULL, 10);

    free(line);
    return fb->fb_facts_size;

error:
    free(fb->fb_facts);
    free(line);
    return -1;
}

void print_facts(const factbase_t *fb) {
    printf("facts[%ld]:\n", fb->fb_facts_size);
    for (size_t i = 0; i < fb->fb_facts_size; i++) {
        printf(" f: ");

        for (int j = 0; j < fb->fb_facts[i].f_lits_size; j++) {
            printf("h%d", fb->fb_facts[i].f_lits[j]);
            if (j < fb->fb_facts[i].f_lits_size - 1)
                printf(" %c ", "^|"[fb->fb_facts[i].f_oper]);
        }
        printf(", fc=%f\n", fb->fb_facts[i].f_cert);
    }
    printf(" goal: h%d\n", fb->fb_goal);
}

int main(int argc, char **argv)
{
    printf("ssii sbr by arf20\n");

    if (argc != 3) {
        fprintf(stderr, "usage: %s <bc file> <bh file>\n", argv[0]);
        exit(1);
    }

    FILE *rulefile = fopen(argv[1], "r");
    if (!rulefile) {
        fprintf(stderr, "error opening %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    FILE *factfile = fopen(argv[2], "r");
    if (!rulefile) {
        fprintf(stderr, "error opening %s: %s\n", argv[2], strerror(errno));
        exit(1);
    }

    rulebase_t rb = { 0 };
    factbase_t fb = { 0 };

    if (read_rules(rulefile, &rb) < 0) {
        fprintf(stderr, "error reading rules\n");
        exit(1);
    }

    if (read_facts(factfile, &fb) < 0) {
        fprintf(stderr, "error reading rules\n");
        exit(1);
    }


    fclose(rulefile);
    fclose(factfile);

    print_rules(&rb);
    print_facts(&fb);



    free(rb.rb_rules);
    free(fb.fb_facts);

    return 0;
}

