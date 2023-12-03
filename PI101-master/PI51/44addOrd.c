#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int addOrd(ABin *a, int x){
    ABin aux = *a, prev = NULL;

    while(aux){
        if(aux->valor == x)
            return 1;

        prev = aux;

        if(x>aux->valor)
            aux = aux->dir;
        else
            aux = aux->esq;
    }

    aux = malloc(sizeof(struct nodo));
    aux->valor = x;
    aux->esq = aux->dir = NULL;

    if(prev==NULL)
        *a = aux;
    else{
        if(x>prev->valor)
            prev->dir = aux;
        else
            prev->esq = aux;
    }

    return 0;
}
