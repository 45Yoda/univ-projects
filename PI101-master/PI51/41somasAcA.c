#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

ABin somasAcA (ABin a){
    if(a==NULL) return NULL;
    else{
        ABin aux1 = somasAcA(a->esq);
        ABin aux2 = somasAcA(a->dir);

        ABin ret = malloc(sizeof(struct nodo));

        int x = 0, y=0;
        if(aux1)
            x = aux1->valor;
        if(aux2)
            y = aux2->valor;

        ret ->valor = x+y+a->valor;
        ret->esq = aux1;
        ret->dir = aux2;

        return ret;
    }
}
