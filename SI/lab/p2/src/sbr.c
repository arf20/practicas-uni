#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#include "sbr.h"

#define VEC_INIT_SIZE   32

ssize_t read_rules(FILE *f, rule_t **rules)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    if ((nread = getline(&line, &len, f)) < 0) {
        fprintf(stderr, "error reading: %s\n", strerror(errno));
        return -1;
    }

    size_t nrules = strtoll(line, NULL, 10);
    *rules = malloc(nrules * sizeof(rule_t));
    memset(*rules, 0, nrules * sizeof(rule_t));

    for (size_t i = 0; i < nrules; i++) {
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
        (*rules)[i].r_id = strtoll(&line[1], &sep, 10);

        /* check separator */
        if (strlen(sep) < 5 || strncmp(sep, ": Si ", 5) != 0) {
            fprintf(stderr, "syntax error on line %ld: rid not followed by ': Si '\n", i);
            goto error;
        }

        /* find operator */
        char *lit = sep + 5;
        char *space = strchr(lit, ' '); /* find first space after first literal */
        char op = space[1]; /* assume first space is followed by operator */
        (*rules)[i].r_inputs_size = 0;
        if (op != 'y' && op != 'o' &&
            !(strlen(space) < 10 || strncmp(space, " Entonces ", 10) == 0))
        {
            fprintf(stderr, "syntax error on line %ld: invalid operator\n", i);
            goto error;
        }

        (*rules)[i].r_oper = op == 'y' ? OPER_AND : OPER_OR;

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
            (*rules)[i].r_inputs[(*rules)[i].r_inputs_size++] = strtol(lit + 1, &sep, 10);

            /* check operator */
            if (sep[0] != ' ' || sep[1] != op || sep[2] != ' ') {
                /* check end token */
                if (strlen(sep) < 10 || strncmp(sep, " Entonces ", 10) == 0) {
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
        (*rules)[i].r_output = strtol(&output[1], &sep, 10);

        /* check FC syntax */
        if (strlen(sep) < 5 || strcmp(sep, ", FC=") == 0) {
            fprintf(stderr,
                "syntax error on line %ld: output literal not followed by ', FC='\n",
                i);
            goto error;
        }

        (*rules)[i].r_cert = strtof(sep + 5, NULL);
    }

    free(line);
    return nrules;

error:
    free(*rules);
    free(line);
    return -1;
}

void print_rules(rule_t *rules, ssize_t nrules) {
    printf("rules[%ld]:\n", nrules);
    for (size_t i = 0; i < nrules; i++) {
        printf(" r%ld: if ", rules[i].r_id);

        for (int j = 0; j < rules[i].r_inputs_size; j++) {
            printf("h%d", rules[i].r_inputs[j]);
            if (j < rules[i].r_inputs_size - 1)
                printf(" %c ", "^|"[rules[i].r_oper]);
        }
        printf(" -> h%d, fc=%f\n", rules[i].r_output, rules[i].r_cert);
    }
}

int read_facts(FILE *f, fact_t **facts)
{

    return 0;
}

int main(int argc, char **argv)
{
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

    rule_t *rules = NULL;
    fact_t *facts = NULL;
    ssize_t nrules = 0, nfacts = 0;

    if ((nrules = read_rules(rulefile, &rules)) < 0) {
        fprintf(stderr, "error reading rules\n");
        exit(1);
    }

    print_rules(rules, nrules);

    if ((nfacts = read_facts(factfile, &facts)) < 0) {
        fprintf(stderr, "error reading rules\n");
        exit(1);
    }

    fclose(rulefile);
    fclose(factfile);

    return 0;
}

