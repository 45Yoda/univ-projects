ex4 : lex.yy.o
	gcc -o ex4 lex.yy.o -ll

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

lex.yy.c : en.l
	flex en.l

clean :
	rm ex4 lex.yy.o lex.yy.c dia.dot
