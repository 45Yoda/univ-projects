#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int depthOrd(ABin a, int x){
    int depth;

    for(depth=1;a;depth++){
        if(a->valor == x)
            return depth;
        else if(x > a->valor)
            a = a->dir;
        else
            a = a->esq;
    }

    return -1;
}
