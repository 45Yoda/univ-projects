#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

ABin cloneAB(ABin a){
    if(a == NULL) return NULL;

    ABin r;

    r = malloc(sizeof(struct nodo));

    r->valor = a->valor;
    r->dir = cloneAB(a->dir);
    r->esq = cloneAB(a->esq);

    return r;
}
