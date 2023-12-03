#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));

    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

LInt arrayToList (int v[], int N){
    LInt ret = NULL;

    for(;N>0;N--)
        ret = newLInt(v[N-1],ret);

    return ret;
}
