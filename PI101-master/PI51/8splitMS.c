#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;


void splitMS(LInt l, int x, LInt *mx, LInt *Mx){
    LInt fmx = *mx = NULL;
    LInt fMx = *Mx = NULL;

    while(l){
        if(!fmx && l->valor < x){
            *mx = l;
            fmx = l;
            l = l->prox;
            fmx->prox = NULL;
        }

        else if (!fMx && l->valor >=x){
            *Mx = l;
            fMx = l;
            l = l->prox;
            fMx->prox = NULL;
        }

        else if (l->valor < x){
            fmx->prox = l;
            l = l->prox;
            fmx = fmx->prox;
            fmx->prox = NULL;
        }

        else{
            fMx->prox = l;
            l = l->prox;
            fMx = fMx->prox;
            fMx->prox = NULL;
        }
    }
}
