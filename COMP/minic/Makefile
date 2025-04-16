CC := gcc
FLEX := flex

all: minicc

minic.tab.c minic.tab.h: minic.y
	bison -v -d --graph minic.y

lex.yy.c: lexer.l minic.tab.h
	flex lexer.l

minicc: lex.yy.c main.c minic.tab.h
	gcc -g -O0 -Wall -pedantic lex.yy.c listaCodigo.c listaSimbolos.c minic.tab.c main.c -lfl -o minicc

.PHONY: clean
clean:
	rm -f minic.tab.c minic.tab.h lex.yy.c minicc

