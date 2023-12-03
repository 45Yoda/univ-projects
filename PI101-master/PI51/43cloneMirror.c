#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

ABin cloneMirror(ABin a){
        if(a==NULL) return NULL;

        ABin aux = malloc(sizeof (struct nodo));
        aux->valor = a->valor;
        aux->esq = cloneMirror(a->dir);
        aux->dir = cloneMirror(a->esq);

        return aux;
}
