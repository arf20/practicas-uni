%{
#include "calc.tab.h"
%}


%option yylineno
%%
"+"         return PLUS;
"-"         return MINUS;
"*"         return TIMES;
"/"         return SLASH;

"("         return PARO;
")"         return PARC;

";"         return END;

[0-9]+      yylval = atoi(yytext); return NUM;

[ \t\n\r]+  ;
.           fprintf(stderr, "Lexer error: %s\n", yytext);

%%

