conv : y.tab.o lex.yy.o
	gcc -o conv `pkg-config --cflags --libs glib-2.0` y.tab.o lex.yy.o -ll -lm 

y.tab.o : y.tab.c
	gcc -c y.tab.c `pkg-config --cflags --libs glib-2.0`

lex.yy.o : lex.yy.c
	gcc -c lex.yy.c  

y.tab.c y.tab.h : conv.y
		yacc -d --debug --verbose conv.y

lex.yy.c : conv.l y.tab.h
	flex conv.l

clean:
	rm conv lex.yy.o lex.yy.c y.tab.c y.tab.h y.tab.o 
