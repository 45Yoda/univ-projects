#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt


LInt somasAcL(LInt l){
    LInt aux, prev = NULL, ret;

    while(l){

        if(prev){
            aux = newLInt(prev->valor + l->valor, NULL);
            prev->prox = aux;
            prev = aux;
        }
        else{
            aux = newLInt(l->valor,NULL);
            prev = aux;
            ret = aux;
        }

        l=l->prox;
    }

    return ret;
}
