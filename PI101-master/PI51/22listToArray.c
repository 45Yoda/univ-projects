#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt


int listToArray(LInt l, int v[], int N){
    int i;

    for(i=0;l && N>0; i++, N--){
        v[i] = l->valor;
        l = l->prox;
    }

    return i;
}
