#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int maiorAB(ABin a){

    while(a->dir){
        a = a->dir;
    }

    return a->valor;
}
