#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt


LInt rotateL(LInt l){
    if(!l) return l;

    LInt aux = l, ret = l->prox;

    while(l->prox)
        l = l->prox;

    l->prox = aux;
    aux->prox = NULL;

    if(ret == NULL)
        return aux;

    return ret;
}
