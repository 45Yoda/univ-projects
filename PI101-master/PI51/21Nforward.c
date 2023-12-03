#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt

LInt NForward(LInt l, int N){

    for(;N>0;N--)
        l=l->prox;

    return l;
}
