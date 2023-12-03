#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int iguaisAB(ABin a,ABin b){
    if(a==b) return 1;

    else if(a != NULL && b != NULL && a->valor == b->valor)
        return iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir);
    else
        return 0;
}
