CC := gcc
FLEX := flex

all: lexer

lex.yy.c: lexer.l
	flex lexer.l

lexer: lex.yy.c main.c lexer.h
	gcc -g -O0 -Wall -pedantic lex.yy.c main.c -lfl -o lexer


