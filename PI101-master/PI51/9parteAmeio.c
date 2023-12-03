#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;


LInt parteAmeio (LInt *l){
    int n, i;
    LInt aux, prev;
    LInt rt = *l;

    for(n=0,aux=*l;aux;n++,aux=aux->prox);

    prev = NULL;

    for(i=0, aux=*l;i<n/2;i++,prev = aux, aux = aux->prox);

    if(prev) prev->prox = NULL;
    else rt = NULL;

    *l = aux;

    return rt;
}
