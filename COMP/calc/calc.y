%{
#include <stdio.h>
extern int yylineno;
extern char *yytext;
extern int yylex();
void yyerror();
%}

%token PLUS MINUS TIMES SLASH PARO PARC NUM END
%%

input : input line  {}
      |
      ;

line : E END        {printf("=%d\n", $1);}
     ;


E : E PLUS T        {$$=$1+$3;}
  | E MINUS T       {$$=$1+$3;}
  | T
  ;

T : T TIMES F       {$$=$1*$3;}
  | T SLASH F       {$$=$1/$3;}
  | F
  ;

F : PARO E PARC     {$$=$2;}
  | NUM
  | MINUS F         {$$=-$2;}
  ;

// by default {$$=$1;}

%%

void
yyerror()
{
    fprintf(stderr, "%d: Syntax error: %s\n", yylineno, yytext);
}


