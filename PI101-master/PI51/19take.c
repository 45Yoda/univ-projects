#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt

int take(int n,LInt *l){
    int c;
    LInt aux;

    for(c=0;n>0 && *l;c++,n--)
        l = &(*l)->prox;

    while(*l){
        aux = (*l)->prox;
        free(*l);
        *l = aux;
    }

    return c;
}
