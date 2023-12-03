#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));

    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

void appendL(LInt *l, int x){

    if(!(*l)) *l=newLInt(x,NULL);
    else{
        for(;*l;l=&(*l)->prox);
        *l=newLInt(x,NULL);
    }
}
