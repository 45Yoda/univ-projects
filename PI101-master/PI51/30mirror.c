#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

void mirror(ABin *a){
    if(*a == NULL) return;

    ABin temp;

    temp = (*a)->dir;

    (*a)->dir = (*a)->esq;
    (*a)->esq = temp;

    mirror(&(*a)->dir);
    mirror(&(*a)->esq);
}
