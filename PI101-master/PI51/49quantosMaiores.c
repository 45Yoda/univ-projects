#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;


int quantosMaiores(ABin a, int x){

    if(a == NULL) return 0;
    else if(a->valor <= x)
        return quantosMaiores(a->dir,x);
    else
        return 1+ quantosMaiores(a->dir,x) + quantosMaiores(a->esq,x);
}
