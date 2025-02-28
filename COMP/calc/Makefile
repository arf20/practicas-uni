all: calc

calc.tab.c calc.tab.h: calc.y
	bison -d calc.y

lex.yy.c: calc.l calc.tab.h
	flex calc.l

calc: lex.yy.c calc.tab.c calc.tab.h
	gcc -o calc main.c lex.yy.c calc.tab.c calc.tab.h -lfl

clean:
	rm calc lex.yy.c calc.tab.c calc.tab.h calc.c

