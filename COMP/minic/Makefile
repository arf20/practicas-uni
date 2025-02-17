CC := gcc
FLEX := flex

all: minicc

lex.yy.c: lexer.l
	flex lexer.l

minicc: lex.yy.c main.c lexer.h
	gcc -g -O0 -Wall -pedantic lex.yy.c main.c -lfl -o minicc


