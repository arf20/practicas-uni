#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "lexer.h"

extern char *yytext;
extern int  yyleng;
extern int  yylineno;
extern FILE *yyin;
extern int yylex();

const char *strings[] = {
    "RVAR",
    "RCONST",
    "RINT",
    "RIF",
    "RELSE",
    "RWHILE",
    "RPRINT",
    "RREAD",
    "ID",
    "LINT",
    "LSTR",
    "OSEMICOLON",
    "OCOMMA",
    "OPLUS",
    "OMINUS",
    "OASTERISK",
    "OSLASH",
    "OPEQUAL",
    "OPARENL",
    "OPARENR",
    "OBRACKETL",
    "OBRACKETR",
    "OQUESTIONMARK",
    "OCOLON"
};


void
usage()
{
    printf("usage: minicc <file>\n");
}

int
main(int argc, char **argv)
{
    if (argc != 2) {
        usage();
        return 1;
    }



    FILE *file;
    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    yyin = file;
    int code;
    while (code = yylex()) {
        if (code < 0) continue;
        printf("%s", strings[code-1]);
        switch (code) {
            case ID: printf("(%d): %s\n", yyleng, yytext); break;
            case LINT: printf("(%d): %s\n", yyleng, yytext); break;
            case LSTR: printf("(%d): %s\n", yyleng, yytext); break;
            default: printf("\n");
        }
    }

    fclose(file);
    return 0;
}

