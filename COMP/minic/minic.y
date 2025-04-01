%{
#include <stdio.h>
#include "listaSimbolos.h"
#include "listaCodigo.h"

void print_symtable();

extern int yylineno;
extern char *yytext;
extern int yylex();
void yyerror();

Lista symtable;

%}

%token <lexem> RVAR RCONST RINT RIF RELSE RWHILE RPRINT RREAD ID LINT LSTR SEMICOLON COMMA OPLUS OMINUS OASTERISK OSLASH OEQUALS PARENL PARENR BRACKETL BRACKETR QUESTIONMARK COLON

%type <code> expr


%union {
    char *lex;
    ListaC code;
}

%%

program : {symtable = creaLS();} ID PARENL PARENR BRACKETL decls statement_list BRACKETR { print_symtable(); liberaLS(symtable);}
        ;

decls : decls RVAR type var_list SEMICOLON
      | decls RCONST type const_list SEMICOLON
      |
      ;

type : RINT
     ;

var_list : ID
         | var_list COMMA ID
         ;

const_list : ID OEQUALS expr
         | const_list COMMA ID OEQUALS expr
         ;

statement_list : statement_list statement
               |
               ;

statement : ID OEQUALS expr SEMICOLON
          | BRACKETL statement_list BRACKETR
          | RIF PARENL expr PARENR statement RELSE statement
          | RIF PARENL expr PARENR statement
          | RWHILE PARENL expr PARENR statement
          | RPRINT PARENL print_list PARENR SEMICOLON
          | RREAD PARENL read_list PARENR SEMICOLON
          ;

print_list : print_item
           | print_list COMMA print_item
           ;

print_item : expr
           | LSTR
           ;

read_list : ID
          | read_list COMMA ID
          ;

expr : expr OPLUS expr {}
     | expr OMINUS expr {}
     | expr OASTERISK expr {}
     | expr OSLASH expr {}
     | PARENL expr QUESTIONMARK expr COLON expr PARENR {}
     | OMINUS expr {}
     | PARENL expr PARENR {}
     | ID {}
     | LINT {}
     ;



%%

void
yyerror()
{
    fprintf(stderr, "%d: Syntax error: %s\n", yylineno, yytext);
}

void
print_code(ListaC code)
{
    PosicionListaC end = finalLC(code);
    for (PosicionListaC it = inicioLC(code); it != end; it = siguienteLC(code, it)) {
        Operacion op = recuperaLC(code, it);
        printf("%s", op.op);
        if (op.res)
            printf(" %s", op.res);
        if (op.arg1)
            printf(", %s", op.arg1);
        if (op.arg2)
            printf(", %s", op.arg2);
    }
} 

void
print_symtable() {

}

