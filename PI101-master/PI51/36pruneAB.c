#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int pruneAB (ABin *a, int l){
    int r;
    if(*a == NULL) return 0;

    if(l==0){
        r = 1+pruneAB(&(*a)->esq,0)+pruneAB(&(*a)->dir,0);
        free(*a);
        *a = NULL;
        return r;
    }
    else
        return pruneAB(&(*a)->esq,l-1) + pruneAB(&(*a)->dir,l-1);
}
