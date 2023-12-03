#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

void listToBTree(LInt l, ABin *a){

    if(l == NULL)
        *a = NULL;
    else{
        LInt arg = l, aux = l->prox, prev = NULL;

        while(aux){
            prev = arg;
            arg = arg->prox;

            if(aux->prox == NULL)
                aux = NULL;
            else
                aux = aux->prox->prox;
        }

        *a = malloc(sizeof(struct nodo));
        (*a)->valor = arg->valor;

        if(prev) prev->prox = NULL;

        if(l != arg)
            listToBTree(l, &(*a)->esq);
        else
            (*a)->esq = NULL;

        if(arg)
            listToBTree(arg->prox,&(*a)->dir);
        else
            (*a)->dir = NULL;
    }
}
