%{
#include "lexer.h"
%}

digit               [[:digit:]]
letter              [[:alpha:]]
integer             {digit}+
escape              (\\.)

%x MULTICOM

%%
[ \n\t]+                                    ;
"//"(.*)[\n]                                ;

"/*"                                        BEGIN MULTICOM;
<MULTICOM>[^*]*                             ;
<MULTICOM>[*]+[^/*]*                        ;
<MULTICOM>[*]+[/]                           BEGIN 0;

main                                        return MAIN;
print                                       return PRINT;
({letter}|_|$)({letter}|{digit}|_|$)*       return ID;
{integer}                                   return LITINT;
\"([^"\n]|{escape})*\"                      return LITSTR; /* any string between " " that doesnt have " or \n */
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

