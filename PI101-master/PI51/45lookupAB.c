#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int lookupAB(ABin a, int x){

    while(a!=NULL){
        if(a->valor == x)
            return 1;
        else if(x > a->valor)
            a = a->dir;
        else
            a = a->esq;
    }

    return 0;
}
