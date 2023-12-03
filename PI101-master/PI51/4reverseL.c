#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

LInt reverseL (LInt l){
    LInt prev = NULL;
    LInt next;

    while(l){
        next = l->prox;
        l->prox = prev;
        prev = l;
        l = next;
    }
    l=prev;

    return l;
}
