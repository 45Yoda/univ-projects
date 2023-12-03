#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));

    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

void concatL (LInt *a, LInt b){
    LInt prev = NULL, aux;

    while(*a){
        a = &(*a)->prox
    }

    while(b!=NULL){

        *a = newLInt(b->valor,NULL);

        if(prev)
            prev->prox = *a;

        prev = *a;
        a = &(*a)->prox;
        b = b->prox;
    }
}
