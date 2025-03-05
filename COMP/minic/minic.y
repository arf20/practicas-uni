%{
#include <stdio.h>
extern int yylineno;
extern char *yytext;
extern int yylex();
void yyerror();
%}

%token RVAR RCONST RINT RIF RELSE RWHILE RPRINT RREAD ID LINT LSTR OSEMICOLON OCOMMA OPLUS OMINUS OASTERISK OSLASH OPEQUAL OPARENL OPARENR OBRACKETL OBRACKETR OQUESTIONMARK OCOLON

%%



%%

void
yyerror()
{
    fprintf(stderr, "%d: Syntax error: %s\n", yylineno, yytext);
}
  

