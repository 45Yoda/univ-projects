#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

void posorderAux(ABin a, LInt *l){
    LInt aux;

    if(a){
        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;
        *l = aux;

        posorderAux(a->dir, l);
        posorderAux(a->esq, l);
    }
}

void posorder(ABin a, LInt *l){
    *l = NULL;

    posorderAux(a,l);
}
