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

LInt cloneL(LInt l){
    LInt ret = NULL, prev = NULL, aux;

    while(l){
        if(!ret) ret = l;

        aux = newLInt(l->valor,NULL);

        if(prev) prev->prox = aux;

        prev = aux;
        l = l->prox;
    }

    return ret;
}
