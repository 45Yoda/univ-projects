#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int deProcura(ABin a){
    if (a == NULL)
        return 1;
    else{
        if(a->esq && (a->esq->valor > a->valor || a->esq->dir && a->esq->dir->valor > a->valor))
            return 0;
        if(a->dir && (a->dir->valor <= a->valor || a->dir->esq && a->dir->esq->valor <= a->valor))
            return 0;
    }

    return deProcura(a->esq) && deProcura(a->dir);
}
