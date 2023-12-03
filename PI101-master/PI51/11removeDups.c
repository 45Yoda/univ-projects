#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

int removeDups (LInt *l){
    LInt aux, prev = NULL, aux2;
    int c = 0, flag;

    aux = *l;

    while(aux){
        for(aux2 = *l;aux2 != aux; aux2 = aux2->prox){
            flag = 0;
            if(aux2->valor == aux->valor){
                flag = 1;
                break;
            }
        }

        if(flag==1){
            prev->prox = aux->prox;
            free(aux);
            aux = prev->prox;
            c++;
        }
        else{
            prev = aux;
            aux = aux->prox;
        }
    }

    return c;
}
