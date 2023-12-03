#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

void init(LInt *l){
    LInt aux, prev = NULL;

    if(!aux) return;

    for(aux=*l;aux->prox;prev = aux,aux=aux->prox);

    if(!prev)
        *l = NULL;
    else{
        prev->prox = NULL;
        free(aux);
    }
}
