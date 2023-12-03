#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;


void removeMaiorA(ABin *a){
    ABin aux;

    while((*a)->dir)
        a = &(*a)->dir;

    if((*a)->esq){
        aux = *a;
        *a = (*a)->esq;
        free(aux);
    }
    else{
        free(*a);
        *a = NULL;
    }
}
