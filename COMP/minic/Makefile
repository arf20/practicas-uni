CC := gcc
FLEX := flex

all: minicc

minic.tab.c minic.tab.h: minic.y
	bison -d minic.y

lex.yy.c: lexer.l minic.tab.h
	flex lexer.l

minicc: lex.yy.c main.c minic.tab.h
	gcc -g -O0 -Wall -pedantic lex.yy.c main.c -lfl -o minicc


