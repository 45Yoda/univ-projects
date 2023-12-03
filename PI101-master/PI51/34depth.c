#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

int depth(ABin a, int x){
    if(a == NULL) return -1;

    if(a->valor == x) return 1;
    else{
        int v,w;
        v = depth(a->esq,x);
        w = depth(a->dir,x);

        if(v>0 && w>0){
            if(v>w)
                return 1+w;
            else
                return 1+v;
        }
        else if(v>0)
            return 1+v;
        else if(w>0)
            return 1+w;
        else
            return v;
    }
}
