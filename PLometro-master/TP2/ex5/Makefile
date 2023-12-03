ex5 : lex.yy.o
	gcc -g -o ex5 lex.yy.o dynamic.c -lfl

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c

lex.yy.c : gps.l
	flex gps.l

clean :
	rm ex5 lex.yy.o lex.yy.c res.kml
