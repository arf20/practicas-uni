#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#include "sbr.h"
#include "base.h"
#include "iengine.h"


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

    if (rulebase_read(&rb, rulefile) < 0) {
        fprintf(stderr, "error reading rules\n");
        exit(1);
    }

    if (factbase_read(&fb, factfile) < 0) {
        fprintf(stderr, "error reading rules\n");
        exit(1);
    }


    fclose(rulefile);
    fclose(factfile);

    rulebase_print(&rb);
    factbase_print(&fb);
    printf("\n");

    factbase_t solved_fb = { 0 };

    printf("backwards chaining...\n");
    int res = backwards_chaining(&rb, &fb, &solved_fb);
    printf("result = %s\n", (const char*[]){"fail", "success"}[res]);

    factbase_print(&solved_fb);

    free(rb.rb_rules);
    free(fb.fb_facts);

    return 0;
}

