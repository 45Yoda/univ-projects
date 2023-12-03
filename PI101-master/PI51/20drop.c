#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt

int drop(int n, LInt *l){
    LInt a;
    int c=0;

    while(n>0 && *l){
        a = (*l)->prox;
        free(*l);
        *l = a;
        c++;
        n--;
    }
    return c;
}
