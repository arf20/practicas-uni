%{
#include "lexer.h"
%}

digit               [[:digit:]]
letter              [[:alpha:]]
integer             {digit}+

%%
[ \n\t]+                                    ;
"//"(.*)[\n]                                ;
main                                        return MAIN;
print                                       return PRINT;
({letter}|_|$)({letter}|{digit}|_|$)*       return ID;
{integer}                                   return LITINT;
"("                                         return PARENL;
")"                                         return PARENR;
"{"                                         return BRACKETL;
"}"                                         return BRACKETR;
";"                                         return SEMICOLON;
","                                         return COMMA;
"="                                         return OPEQUAL;
"+"                                         return OPPLUS;
"-"                                         return OPMINUS;
.                                           printf("%d: Unrecognised lexem %s\n", yylineno, yytext);
%%

