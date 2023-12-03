#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

void insertOrd (LInt *l, int x){

    while(*l && x>(*l)->valor){
        l = &(*l)->prox;
    }
    *l = newLInt(x,*l);
}
