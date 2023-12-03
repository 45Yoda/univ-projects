#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

int removeMaiorL(LInt *l){
    int m;
    LInt aux = *l, prev =NULL;

    m = !aux ? 0 : aux->valor;

    while(aux){
        if(aux->valor > m)
            m = aux->valor;
        aux = aux->prox;
    }

    aux = *l;

    while(aux != NULL){
        if(aux->valor == m){
            if(prev == NULL){
                free(*l);
                *l = aux->prox;
                break;
            }
            else{
                prev -> prox = aux->prox;
                free(aux);
                aux = prev->prox;
                break;
            }
        }
        else{
            prev = aux;
            aux = aux->prox;
        }
    }

    return m;
}
