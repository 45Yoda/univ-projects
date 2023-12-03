#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int contaFolhas(ABin a){
    if(a==NULL) return 0;

    if(a->dir == NULL && a->esq == NULL)
        return 1;

    return contaFolhas(a->dir) + contaFolhas(a->esq);
}
