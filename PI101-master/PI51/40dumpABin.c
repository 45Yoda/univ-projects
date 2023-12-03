#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int dumpABin(ABin a, int v[], int N){
    if(a == NULL) return 0;
    else if(N > 0){
        int d = dumpABin(a->esq,v,N-1);
        *(v+d) = a->valor;
        return 1+d+dumpABin(a->dir,v+d+1,N-d-1);
        }
        else
            return 0;
}
