#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt

void remreps(LInt l){
    LInt aux, prev = NULL;

    while(l){
        if(prev && prev->valor == l->valor){
            prev->prox = l->prox;
            aux = l;
            l = l->prox;
            free(aux);
        }
        else{
            prev = l;
            l = l->prox;
        }
    }
}
