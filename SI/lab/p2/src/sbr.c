#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "sbr.h"

int read_rules(FILE *f, rule_t **rules)
{

    return 0;
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

    if (read_rules(rulefile, &rules) < 0) {
        fprintf(stderr, "error reading rules\n");
        exit(1);
    }

    if (read_facts(factfile, &facts) < 0) {
        fprintf(stderr, "error reading rules\n");
        exit(1);
    }

    fclose(rulefile);
    fclose(factfile);


    return 0;
}

