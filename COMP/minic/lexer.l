%{
#include "minic.tab.h"
#include <limits.h>

int check_id();
int check_lint();

%}

digit               [[:digit:]]
letter              [[:alpha:]]
integer             {digit}+
escape              (\\.)

%x MULTICOM

%option yylineno

%%

[ \n\t]+                                    ;
"//"(.*)[\n]                                ;

"/*"                                        BEGIN MULTICOM;
<MULTICOM>[^*]*                             ;
<MULTICOM>[*]+[^/*]*                        ;
<MULTICOM>[*]+[/]                           BEGIN 0;

var                                         return RVAR;
const                                       return RCONST;
int                                         return RINT;
if                                          return RIF;
else                                        return RELSE;
while                                       return RWHILE;
print                                       return RPRINT;
read                                        return RREAD;

({letter}|_|$)({letter}|{digit}|_|$)*       return check_id();

{integer}                                   return check_lint();
\"([^\"\n\\]|{escape})*\"                   return LSTR; /* any string between " " that doesnt have " or \n */

";"                                         return SEMICOLON;
","                                         return COMMA;
"+"                                         return OPLUS;
"-"                                         return OMINUS;
"*"                                         return OASTERISK;
"/"                                         return OSLASH;
"="                                         return OEQUALS;
"("                                         return PARENL;
")"                                         return PARENR;
"{"                                         return BRACKETL;
"}"                                         return BRACKETR;
"?"                                         return QUESTIONMARK;
":"                                         return COLON;
[^a-zA-Z0-9;,+\-*/=(){}?:\"]+                  printf("%d: Lexical2 error %s\n", yylineno, yytext);

.                                           printf("%d: Lexical error %s\n", yylineno, yytext);
%%

int
check_lint()
{
    long long int v = strtol(yytext, NULL, 0);
    if (v >= INT_MAX || v <= INT_MIN) {
        fprintf(stderr, "%d: Lexical error: int literal out of range: %s\n", yylineno, yytext);
        return -1;
    } else return LINT;
}

int
check_id()
{
    if (yyleng > 32) {
        fprintf(stderr, "%d: Lexical error: identifier exceeds maximum length: %s\n", yylineno, yytext);
        return -1;
    } else return ID;
}

/*[^a-zA-Z0-9;,+\-/=(){}?:]+                  printf("%d: Lexical error %s\n", yylineno, yytext);*/

