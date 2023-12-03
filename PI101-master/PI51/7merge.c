#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

void merge(LInt *r, LInt l1, LInt l2){
    LInt ant = NULL;

    if(!l1) {*r=l2;return;}
    if(!l2) {*r=l1;return;}

    if(l1->valor > l2->valor) {ant = l2; *r=l2;l2=l2->prox;}
    else{ant=l1;*r=l1;l1=l1->prox;}

    while(l1 && l2){
        if(l1->valor > l2->valor){
            ant->prox = l2;
            ant = l2;
            l2 = l2->prox;
        }
        else{
            ant->prox = l1;
            ant = l1;
            l1 = l1->prox;
        }
    }

    if(!l1) ant->prox =l2;
    else if(!l2) ant->prox = l1;
}
