#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

void freeL(LInt l){
    LInt aux;

    while(l){
        aux = l;
        l = l->prox;
        free(aux);
    }
    free(l);
}
