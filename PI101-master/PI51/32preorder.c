#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

void preorderAux(ABin a, LInt *l){
    LInt aux;
    if(a){
        preorderAux(a->dir,l);
        preorderAux(a->esq,l);

        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;
    }
}

void preorder(ABin a, LInt *l){
    *l = NULL;

    preorderAux(a,l);
}
