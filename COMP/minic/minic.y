%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaSimbolos.h"
#include "listaCodigo.h"

FILE *out = NULL;
int debug = 0;

extern int yylineno;
extern char *yytext;
extern int yylex();

void yyerror();

void print_code(ListaC code);
void print_symtable();
void setup_program();
void symtable_push(const char *id);
void ds_push_word(char *id);
const char* ds_push_asciiz(const char *lstr);
void cl_program(const char *id, ListaC decls, ListaC statements);
ListaC cl_push_const_list(ListaC constl, const char *id, ListaC vl);
ListaC cl_push_lint(const char *lint);
ListaC cl_push_id(const char *id);
ListaC cl_push_ominus_expr(ListaC l);
ListaC cl_push_condop(ListaC cond, ListaC tl, ListaC fl);
ListaC cl_push_binop(const char *inst, ListaC ll, ListaC rl);
ListaC cl_push_rel(const char *inst, ListaC ll, ListaC rl);
ListaC cl_push_assign(const char *id, ListaC l);
ListaC cl_push_if_else(ListaC cond, ListaC ifl, ListaC elsel);
ListaC cl_push_if(ListaC cond, ListaC ifl);
ListaC cl_push_while(ListaC cond, ListaC statementl);
ListaC cl_push_do_while(ListaC statementl, ListaC cond);
ListaC cl_push_for(const char *id, const char *lintinit, ListaC cond, ListaC statementl, int sign, const char *lintstep);
ListaC cl_push_print_expr(ListaC exprl);
ListaC cl_push_print_str(const char *lstr);
ListaC cl_push_read(const char *id);

Lista symtable = NULL;
ListaC dataseg = NULL;
int regs[10] = { 0 };
const char reg_strs[][10] = {
    "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"
};

int string_counter = 0, cond_counter = 0, if_counter = 0, while_counter = 0,
    dowhile_counter = 0, for_counter = 0;

#define insertaLC(l, p, o) { \
    if (debug) { \
        if (o.arg2) \
            fprintf(stderr, "==%d: pushing `%s %s, %s, %s'\n", \
                yylineno, o.op, o.res, o.arg1, o.arg2); \
        else \
            fprintf(stderr, "==%d: pushing `%s %s, %s'\n", \
                yylineno, o.op, o.res, o.arg1); \
    } \
    insertaLC(l, p, o); \
}

#define insertaLS(l, p, s) { \
    if (debug) \
        fprintf(stderr, "==%d: pushing symbol '%s'\n", yylineno, s.nombre); \
    insertaLS(l, p, s); \
}

#define comment(l) { \
    if (debug) { \
        static char buff[16]; \
        snprintf(buff, 16, "# L%d", yylineno); \
        Operacion com = (Operacion){ buff }; \
        insertaLC(l, inicioLC(l), com); \
    } \
} \

%}

%token RVAR RCONST RINT RIF RELSE RWHILE RDO RFOR RPRINT RREAD SEMICOLON COMMA OPLUS OMINUS OASTERISK OSLASH OASSIGN OLESS OGREATER OLESSEQUAL OGREATEREQUAL OEQUALS ONOTEQUALS PARENL PARENR BRACKETL BRACKETR QUESTIONMARK COLON

%token <lex> ID LSTR LINT

%left OLESS OGREATER OLESSEQUAL OGREATEREQUAL OEQUALS ONOTEQUALS
%left OMINUS OPLUS
%left OSLASH OASTERISK
%left OUMINUS

%expect 1

%define parse.trace

%union {
    char *lex;
    ListaC code;
}

%type <code> expr statement statement_list const_list print_list read_list print_item decls

%%

program : { setup_program(); } ID PARENL PARENR BRACKETL decls statement_list BRACKETR { cl_program($2, $6, $7);  }
        ;

decls : decls RVAR type var_list SEMICOLON { $$ = $1; }
      | decls RCONST type const_list SEMICOLON { concatenaLC($1, $4); $$ = $1; comment($$); }
      | { $$ = creaLC(); }
      ;

type : RINT
     ;

var_list : ID { symtable_push($1); ds_push_word($1); }
         | var_list COMMA ID { symtable_push($3); ds_push_word($3); }
         ;

const_list : ID OASSIGN expr { symtable_push($1); ds_push_word($1); $$ = cl_push_const_list(creaLC(), $1, $3); }
           | const_list COMMA ID OASSIGN expr { symtable_push($3); ds_push_word($3); $$ = cl_push_const_list($1, $3, $5); }
           ;

statement_list : statement_list statement { concatenaLC($1, $2); $$ = $1; }
               | {$$ = creaLC();}
               ;

statement : ID OASSIGN expr SEMICOLON { $$ = cl_push_assign($1, $3); }
          | BRACKETL statement_list BRACKETR { $$ = $2; }
          | RIF PARENL expr PARENR statement RELSE statement { $$ = cl_push_if_else($3, $5, $7); }
          | RIF PARENL expr PARENR statement { $$ = cl_push_if($3, $5); }
          | RWHILE PARENL expr PARENR statement { $$ = cl_push_while($3, $5); }
          | RDO statement RWHILE PARENL expr PARENR SEMICOLON { $$ = cl_push_do_while($2, $5); }
          | RFOR PARENL ID OASSIGN LINT SEMICOLON expr PARENR statement { $$ = cl_push_for($3, $5, $7, $9, 0, "1"); }
          | RFOR PARENL ID OASSIGN LINT SEMICOLON expr SEMICOLON OMINUS LINT PARENR statement { $$ = cl_push_for($3, $5, $7, $12, 1, $10); }
          | RFOR PARENL ID OASSIGN LINT SEMICOLON expr SEMICOLON LINT PARENR statement { $$ = cl_push_for($3, $5, $7, $11, 0, $9); }
          | RPRINT PARENL print_list PARENR SEMICOLON { $$ = $3; comment($$); }
          | RREAD PARENL read_list PARENR SEMICOLON { $$ = $3; comment($$); }
          ;

print_list : print_item { $$ = $1; }
           | print_list COMMA print_item { concatenaLC($1, $3); $$ = $1; }
           ;

print_item : expr { $$ = cl_push_print_expr($1); }
           | LSTR { $$ = cl_push_print_str($1); }
           ;

read_list : ID { $$ = cl_push_read($1); }
          | read_list COMMA ID { concatenaLC($1, cl_push_read($3)); $$ = $1; }
          ;

expr : expr OPLUS expr { $$ = cl_push_binop("add", $1, $3); }
     | expr OMINUS expr { $$ = cl_push_binop("sub", $1, $3); }
     | expr OASTERISK expr { $$ = cl_push_binop("mul", $1, $3); }
     | expr OSLASH expr { $$ = cl_push_binop("div", $1, $3); }
     | expr OLESS expr { $$ = cl_push_rel("slt", $1, $3); }
     | expr OGREATER expr { $$ = cl_push_rel("sgt", $1, $3); }
     | expr OLESSEQUAL expr { $$ = cl_push_rel("sle", $1, $3); }
     | expr OGREATEREQUAL expr { $$ = cl_push_rel("sge", $1, $3); }
     | expr OEQUALS expr { $$ = cl_push_rel("seq", $1, $3); }
     | expr ONOTEQUALS expr { $$ = cl_push_rel("sne", $1, $3); }
     | PARENL expr QUESTIONMARK expr COLON expr PARENR { $$ = cl_push_condop($2, $4, $6); }
     | OMINUS expr %prec OUMINUS { $$ = cl_push_ominus_expr($2); }
     | PARENL expr PARENR { $$ = $2; }
     | ID { $$ = cl_push_id($1); }
     | LINT { $$ = cl_push_lint($1); }
     ;



%%


/* =================================== util ================================= */

void
yyerror()
{
    fprintf(stderr, "%d: syntax error at `%s'\n", yylineno, yytext);
}

void
print_code(ListaC code)
{
    PosicionListaC end = finalLC(code);
    for (PosicionListaC it = inicioLC(code); it != end; it = siguienteLC(code, it)) {
        Operacion op = recuperaLC(code, it);
        if (op.op[0] != '#' && (op.op[0] == '.' || op.op[strlen(op.op)-1] != ':'))
            fprintf(out, "\t");
        fprintf(out, "%s", op.op);
        if (op.res)
            fprintf(out, " %s", op.res);
        if (op.arg1)
            fprintf(out, ", %s", op.arg1);
        if (op.arg2)
            fprintf(out, ", %s", op.arg2);
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
} 

void
print_symtable() {
    PosicionLista end = finalLS(symtable);
    fprintf(stderr, "symbol table:\nsymbol\n======\n");
    for (PosicionLista t = inicioLS(symtable); t != end; t = siguienteLS(symtable, t)) {
        Simbolo s = recuperaLS(symtable, t);
        fprintf(stderr, "%s\n", s.nombre);
    }
    fprintf(stderr, "\n");
}

const char*
alloc_reg()
{
    for (int i = 0; i < 10; i++) {
        if (regs[i] == 0) {
            regs[i] = 1;
            return reg_strs[i];
        }
    }

    fprintf(stderr, "error: ran out of registers\n");
    return "";
}

void
free_reg(const char *reg)
{
    if (!reg)
        return;
    int i = (reg - (const char*)reg_strs) / sizeof(char*);
    regs[i] = 0;
}

char*
if_end_label()
{
    static char buff[32];
    snprintf(buff, 32, "if%dend", if_counter);
    return strdup(buff);
}

char*
if_else_label()
{
    static char buff[32];
    snprintf(buff, 32, "if%delse", if_counter);
    return strdup(buff);
}

char*
cond_false_label()
{
    static char buff[32];
    snprintf(buff, 32, "cond%dfalse", cond_counter);
    return strdup(buff);
}

char*
cond_end_label()
{
    static char buff[32];
    snprintf(buff, 32, "cond%dend", cond_counter);
    return strdup(buff);
}

char*
while_label()
{
    static char buff[32];
    snprintf(buff, 32, "while%d", while_counter);
    return strdup(buff);
}

char*
while_end_label()
{
    static char buff[32];
    snprintf(buff, 32, "while%dend", while_counter);
    return strdup(buff);
}

char*
do_label()
{
    static char buff[32];
    snprintf(buff, 32, "do%d", dowhile_counter);
    return strdup(buff);
}

char*
for_label()
{
    static char buff[32];
    snprintf(buff, 32, "for%d", for_counter);
    return strdup(buff);
}

char*
for_end_label()
{
    static char buff[32];
    snprintf(buff, 32, "for%dend", for_counter);
    return strdup(buff);
}

char*
next_string_label()
{
    static char buff[32];
    snprintf(buff, 32, "$str%d", string_counter++);
    return strdup(buff);
}


char*
label_colon(const char *label)
{
    int len = strlen(label);
    char *labelc = malloc(len + 2);
    strcpy(labelc, label);
    labelc[len] = ':';
    labelc[len + 1] = '\0';
    return labelc;
}

/* =================================== main ================================= */

void
symtable_push(const char *id)
{
    static char buff[256];
    snprintf(buff, 256, "_%s", id);

    if (buscaLS(symtable, buff) == finalLS(symtable)) {
        insertaLS(symtable, finalLS(symtable), ((Simbolo){strdup(buff), VARIABLE, 0}));
    }
    else
        fprintf(stderr, "%d: error: symbol `%s' redefined\n", yylineno, id);
}


void
setup_program()
{
    symtable = creaLS();
    dataseg = creaLC();
    
    Operacion op = { ".data" };
    insertaLC(dataseg, finalLC(dataseg), op);
}


void
ds_push_word(char *id)
{
    static char buff[256];
    snprintf(buff, 256, "_%s", id);

    Operacion op = { label_colon(buff) };
    insertaLC(dataseg, finalLC(dataseg), op);

    op = (Operacion){ ".word 0" };
    insertaLC(dataseg, finalLC(dataseg), op);
}

const char*
ds_push_asciiz(const char *lstr)
{
    const char *label = next_string_label();
    Operacion op = { label_colon(label) };
    insertaLC(dataseg, finalLC(dataseg), op);

    op = (Operacion){ ".asciiz", lstr };
    insertaLC(dataseg, finalLC(dataseg), op);

    return label;
}

void
cl_program(const char *id, ListaC decls, ListaC statements)
{
    print_symtable();
    liberaLS(symtable);

    ListaC textseg = creaLC();
    Operacion op = { ".text" };
    insertaLC(textseg, finalLC(textseg), op);
    op = (Operacion){ ".globl main" };
    insertaLC(textseg, finalLC(textseg), op);
    op = (Operacion){ "main:" };
    insertaLC(textseg, finalLC(textseg), op);
    concatenaLC(textseg, decls);
    concatenaLC(textseg, statements);
    
    op = (Operacion){ "# program end" };
    insertaLC(textseg, finalLC(textseg), op);
    op = (Operacion){ "li", "$v0", "10" };
    insertaLC(textseg, finalLC(textseg), op);
    op = (Operacion){ "syscall" };
    insertaLC(textseg, finalLC(textseg), op);

    ListaC program = creaLC();
    concatenaLC(program, dataseg);
    concatenaLC(program, textseg);

    print_code(program);
}

ListaC
cl_push_const_list(ListaC constl, const char *id, ListaC vl)
{
    static char buff[256];
    snprintf(buff, 256, "_%s", id);

    concatenaLC(constl, vl);
    Operacion op = { "sw", recuperaResLC(vl), strdup(buff) };
    insertaLC(constl, finalLC(constl), op);
    free_reg(recuperaResLC(vl));
    return constl;
}


ListaC
cl_push_read(const char *id)
{
    static char buff[256];
    snprintf(buff, 256, "_%s", id);

    if (buscaLS(symtable, buff) == finalLS(symtable))
        fprintf(stderr, "%d: error: undeclared symbol `%s'\n", yylineno, buff);
    
    ListaC rl = creaLC();
    Operacion op = { "li", "$v0", "5" };
    insertaLC(rl, finalLC(rl), op);
    op = (Operacion){ "syscall" };
    insertaLC(rl, finalLC(rl), op);
    op = (Operacion){ "sw", "$v0", strdup(buff) };
    insertaLC(rl, finalLC(rl), op);

    return rl;
}

ListaC
cl_push_print_expr(ListaC exprl)
{
    Operacion op = { "li", "$v0", "1" };
    insertaLC(exprl, finalLC(exprl), op);
    op = (Operacion){ "move", "$a0", recuperaResLC(exprl) };
    insertaLC(exprl, finalLC(exprl), op);
    op = (Operacion){ "syscall" };
    insertaLC(exprl, finalLC(exprl), op);

    free_reg(recuperaResLC(exprl));

    return exprl;
}

ListaC
cl_push_print_str(const char *lstr)
{
    const char *strlbl = ds_push_asciiz(lstr);
   
    ListaC pl = creaLC();   
    Operacion op = { "li", "$v0", "4" };
    insertaLC(pl, finalLC(pl), op);
    op = (Operacion){ "la", "$a0", strlbl };
    insertaLC(pl, finalLC(pl), op);
    op = (Operacion){ "syscall" };
    insertaLC(pl, finalLC(pl), op);

    return pl;
}

ListaC
cl_push_while(ListaC cond, ListaC statementl)
{
    const char *looplbl = while_label();
    const char *loopendlbl = while_end_label();

    ListaC ll = creaLC();
    comment(ll);   
    
    // loop start label
    Operacion op = { label_colon(looplbl) };
    insertaLC(ll, finalLC(ll), op);
    // condition
    concatenaLC(ll, cond);
    op = (Operacion){ "beqz", recuperaResLC(cond), loopendlbl };
    insertaLC(ll, finalLC(ll), op);
    // body
    concatenaLC(ll, statementl);
    // loop over
    op = (Operacion){ "j", looplbl };
    insertaLC(ll, finalLC(ll), op);
    // loop end label
    op = (Operacion){ label_colon(loopendlbl) };
    insertaLC(ll, finalLC(ll), op);

    while_counter++;

    free_reg(recuperaResLC(cond));

    return ll;
}

ListaC
cl_push_do_while(ListaC statementl, ListaC cond)
{
    const char *looplbl = do_label();

    ListaC ll = creaLC();
    comment(ll);   
    
    // loop start label
    Operacion op = { label_colon(looplbl) };
    insertaLC(ll, finalLC(ll), op);
    // body
    concatenaLC(ll, statementl);
    // condition
    concatenaLC(ll, cond);
    op = (Operacion){ "bnez", recuperaResLC(cond), looplbl };
    insertaLC(ll, finalLC(ll), op);

    dowhile_counter++;

    free_reg(recuperaResLC(cond));

    return ll;
}

ListaC
cl_push_for(const char *id, const char *lintinit,
    ListaC cond, ListaC statementl, int sign, const char *lintstep)
{
    const char *looplbl = for_label();
    const char *loopendlbl = for_end_label();

    const char *iter_reg = alloc_reg();
   
    static char buff[256];
    snprintf(buff, 256, "_%s", id);

    ListaC ll = creaLC();
    comment(ll);

    // loop start label
    Operacion op = { label_colon(looplbl) };
    insertaLC(ll, finalLC(ll), op);
    // condition
    concatenaLC(ll, cond);
    op = (Operacion){ "beqz", recuperaResLC(cond), loopendlbl };
    insertaLC(ll, finalLC(ll), op);
    // body
    concatenaLC(ll, statementl);
    // iterator
    op = (Operacion){ "lw", iter_reg, buff };
    insertaLC(ll, finalLC(ll), op);
    op = (Operacion){ sign ? "sub" : "add", buff, buff, lintstep };
    insertaLC(ll, finalLC(ll), op);
    op = (Operacion){ "sw", iter_reg, buff };
    insertaLC(ll, finalLC(ll), op);
    // loop over
    op = (Operacion){ "j", looplbl };
    insertaLC(ll, finalLC(ll), op);
    // loop end label
    op = (Operacion){ label_colon(loopendlbl) };
    insertaLC(ll, finalLC(ll), op);

    for_counter++;

    free_reg(iter_reg);

    return ll;
}

ListaC
cl_push_if(ListaC cond, ListaC ifl)
{
    ListaC res = creaLC();
    comment(res); 

    concatenaLC(res, cond);

    char *ifendlabel = if_end_label(); 
    
    // continue to if or go to else
    Operacion op = { "beqz", recuperaResLC(cond), ifendlabel };
    insertaLC(res, finalLC(res), op);
    // if block
    concatenaLC(res, ifl);
    // end label
    op = (Operacion){ label_colon(ifendlabel) };
    insertaLC(res, finalLC(res), op);

    if_counter++;

    free_reg(recuperaResLC(cond));

    return res;
}

ListaC
cl_push_if_else(ListaC cond, ListaC ifl, ListaC elsel)
{
    ListaC res = creaLC();
    comment(res); 

    concatenaLC(res, cond);

    char *elselabel = if_else_label();
    char *ifendlabel = if_end_label();
    
    // continue to if or go to else
    Operacion op = { "beqz", recuperaResLC(cond), elselabel };
    insertaLC(res, finalLC(res), op);
    // if block
    concatenaLC(res, ifl);
    // prevent fall through
    op = (Operacion){ "j", ifendlabel };
    insertaLC(res, finalLC(res), op);
    // else label
    op = (Operacion){ label_colon(elselabel) };
    insertaLC(res, finalLC(res), op);
    // else block
    concatenaLC(res, elsel);
    // end label
    op = (Operacion){ label_colon(ifendlabel) };
    insertaLC(res, finalLC(res), op);

    if_counter++;

    free_reg(recuperaResLC(cond));

    return res;
}

ListaC
cl_push_assign(const char *id, ListaC l)
{
    static char buff[256];
    snprintf(buff, 256, "_%s", id);

    comment(l); 
    Operacion op = { "sw", recuperaResLC(l), strdup(buff) };
    insertaLC(l, finalLC(l), op);
    free_reg(recuperaResLC(l));
    return l; 
}

ListaC
cl_push_binop(const char *inst, ListaC ll, ListaC rl)
{
    ListaC res = creaLC();
    concatenaLC(res, ll);
    concatenaLC(res, rl);

    const char *reg = alloc_reg();

    Operacion op = { inst, reg, recuperaResLC(ll), recuperaResLC(rl) };
    insertaLC(res, finalLC(res), op);
    
    guardaResLC(res, reg);
    free_reg(recuperaResLC(ll));
    free_reg(recuperaResLC(rl));

    return res;
}

ListaC
cl_push_rel(const char *inst, ListaC ll, ListaC rl)
{
    ListaC res = creaLC();
    concatenaLC(res, ll);
    concatenaLC(res, rl);

    const char *reg = alloc_reg();

    Operacion op = { inst, reg, recuperaResLC(ll), recuperaResLC(rl) };
    insertaLC(res, finalLC(res), op);

    guardaResLC(res, reg);
    free_reg(recuperaResLC(ll));
    free_reg(recuperaResLC(rl));
    
    return res;
}

ListaC
cl_push_condop(ListaC cond, ListaC tl, ListaC fl)
{
    ListaC res = creaLC();
    concatenaLC(res, tl);
    concatenaLC(res, fl);
    concatenaLC(res, cond);

    const char *reg = alloc_reg();
    const char *falselabel = cond_false_label();
    const char *endlabel = cond_end_label();
    Operacion op = { "beqz", recuperaResLC(cond), falselabel };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ "move", reg, recuperaResLC(tl) };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ "j", endlabel };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ falselabel };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ "move", reg, recuperaResLC(fl) };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ endlabel };
    insertaLC(res, finalLC(res), op);

    guardaResLC(res, reg);

    free_reg(recuperaResLC(cond));
    free_reg(recuperaResLC(tl));
    free_reg(recuperaResLC(fl));

    cond_counter++;

    return res;
}

ListaC
cl_push_ominus_expr(ListaC l)
{
    const char *reg = recuperaResLC(l);
    Operacion op = { "neg", reg, reg };
    insertaLC(l, finalLC(l), op);
    return l;
}

ListaC
cl_push_id(const char *id)
{
    static char buff[256];
    snprintf(buff, 256, "_%s", id);

    ListaC l = creaLC();
    if (buscaLS(symtable, buff) == finalLS(symtable))
        fprintf(stderr, "%d: error: undeclared symbol `%s'\n", yylineno, buff);
    const char *reg = alloc_reg();
    Operacion op = { "lw", reg, strdup(buff) };
    insertaLC(l, finalLC(l), op);
    guardaResLC(l, reg);
    return l;
}

ListaC
cl_push_lint(const char *lint)
{
    ListaC l = creaLC();
    const char *reg = alloc_reg();
    Operacion op = { "li", reg, strdup(lint) };
    insertaLC(l, finalLC(l), op);
    guardaResLC(l, reg);
    return l;
}

