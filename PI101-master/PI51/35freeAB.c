#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int freeAB(ABin a){
    int i=0;

    if(a == NULL) return 0;

    i+=freeAB(a->esq);
    i+=freeAB(a->dir);

    free(a);
    i++;

    return i;
}
