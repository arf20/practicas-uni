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
    "MAIN",
    "PRINT",
    "LITINT",
    "ID",

    "PARENL",
    "PARENR",
    "BRACKETL",
    "BRACKETR",
    "SEMICOLON",
    "COMMA",

    "OPEQUAL",
    "OPPLUS",
    "OPMINUS"   
};



void
usage()
{
    printf("usage: lexer <file>\n");
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
        printf("TOKEN %s ", strings[code-1]);
        if(code == ID) printf("LEXEM %s LENGTH %d\n", yytext, yyleng);
        else printf("\n");
    }

    fclose(file);
    return 0;
}
