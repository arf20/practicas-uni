%{
#include "calc.tab.h"
%}


%option yylineno
%%
"+"             return PLUS;
"-"             return MINUS;
"*"             return TIMES;
"/"             return SLASH;
"%"             return MOD;
"="             return EQUALS;

"("             return PARO;
")"             return PARC;

";"             return END;

[0-9]+          yylval.inte = atoi(yytext); return NUM;
[a-zA-Z]+[0-9]* yylval.str = strdup(yytext); return ID;

[[:space:]]     ;
[\t\n\r]+       ;
[^a-zA-Z0-9+\-*/%();]               fprintf(stderr, "Lexer error: %s\n", yytext);

%%

