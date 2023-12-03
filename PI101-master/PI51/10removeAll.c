#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;


int removeAll(LInt *l, int x){
    int c=0;
    LInt aux = *l, prev=NULL;

    for(;aux;aux=aux->prox){
        if(aux->valor == x){
            if(prev){
                prev->prox = aux->prox;
            }

            else
                *l = aux->prox;

            c++;
            free(aux);
        }
        else
            prev = aux;
    }
    return c;
}
