#include <stdio.h>
#include <stdlib.h>

ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}

typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int altura(ABin a){

    if(!a) return NULL;


    return 1+(max(altura(a->esq),altura(a->dir)));
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}
