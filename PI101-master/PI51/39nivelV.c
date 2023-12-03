#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int nivelV(ABin a, int n, int v[]){
    if(a==NULL) return 0;

    if(n==1){
        *v = a->valor;
        return 1;
    }
    else{
        int d = nivelV(a->esq, n-1,v);
        return d + nivelV(a->dir,n-1,v+d);
    }
}
