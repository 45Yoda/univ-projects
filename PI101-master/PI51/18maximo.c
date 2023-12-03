#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt

int maximo (LInt l){
    int r=0;

    while(l){
        if(l->valor > r)
            r = l->valor;

        l=l->prox;
    }

    return r;
}
