%{
#include <stdio.h>
extern int yylineno;
extern char *yytext;
extern int yylex();
void yyerror();

int i = 0;

%}

%union {
    int inte;
    char *str;
}



%token PARO PARC EQUALS END
%token <inte> NUM
%token <str> ID
%left PLUS MINUS
%left TIMES SLASH MOD
%left UMINUS


%type <inte> E input


%%

input :             {$$=1;}
      | input {printf("[%d]: ", $1);} line  {$$=$1+1;}
      ;

line : E END        {printf("=%d\n", $1);}
     | ID EQUALS E END {printf("%s=%d\n", $1, $3);}
     | error END    {}
     ;


E : E PLUS E        {$$=$1+$3;}
  | E MINUS E       {$$=$1+$3;}
  | E TIMES E       {$$=$1*$3;}
  | E SLASH E       {$$=$1*$3;}
  | E MOD E         {$$=$1%$3;}
  | PARO E PARC     {$$=$2;}
  | MINUS E %prec UMINUS {$$=-$2;}
  | NUM
  ;

// every {} counts like new $var

// by default {$$=$1;}

%%

void
yyerror()
{
    fprintf(stderr, "%d: Syntax error: %s\n", yylineno, yytext);
}


