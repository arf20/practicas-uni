#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

extern FILE* yyin;
extern int yyparse();
extern FILE* out;

void
usage()
{
    printf("usage: minicc <file>\n");
}

int
main(int argc, char **argv)
{
    if (argc < 2) {
        usage();
        return 1;
    }

    FILE *file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Error opening input file: %s\n", strerror(errno));
        return 1;
    }

    if ((out = fopen((argc == 3 ? argv[2] : "minic.out"), "w")) == NULL) {
        printf("Error opening output file: %s\n", strerror(errno));
        return 1;
    }

    yyin = file;

    yyparse();

    fclose(file);
    return 0;
}

