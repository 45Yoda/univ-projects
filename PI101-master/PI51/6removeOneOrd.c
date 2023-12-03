#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;



int removeOneOrd (LInt *l, int x){
    LInt aux;

    while(*l && x > (*l)->valor)
        l = &(*l)->prox;

    if(!(*l)) return 1;

    aux = *l;
    *l = aux->prox;
    return 0;
}
