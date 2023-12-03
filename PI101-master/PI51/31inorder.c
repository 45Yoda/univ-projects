#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

void inorder(ABin a, LInt *l){
    LInt aux;
    if(a){
        inorder(a->dir,l);
        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;
        inorder(a->esq,&aux);
        *l = aux;
    }
}
