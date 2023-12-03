#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int valor;
	struct nodo *esq, *dir;
}*ABin;

LInt nivelL(ABin a, int n){
    if(a==NULL) return NULL;
    else{
        LInt aux, aux2, p, prev;

        if(n==1){
            aux = malloc(sizeof(struct lligada));
            aux->valor = a->valor;
            aux->prox = NULL;
            return aux;
        }
        else{
            aux = nivelL(a->esq,n-1);
            aux2 = nivelL(a->dir,n-1);

            for(p=aux,prev=aux;p!=NULL;p=p->prox)
                prev = p;

            if(aux != NULL){
                prev->prox = aux2;
                return aux;
            }
            else
                return aux2;
        }
    }
}


LInt concat(LInt a,LInt b){
	LInt head=a;

	if(a==NULL) return b;
	else{
		while(a->prox!=NULL){
			a=a->prox;
		}
		a->prox=b;
	}
	a=head;

	return a;
}
LInt nivelL(ABin a,int n){
	LInt e,d,r;
	if(n==0) r= NULL;

	if(a!=NULL){
		if(n!=0){
			e=nivelL(a->esq,n-1);
			d=nivelL(a->dir,n-1);
			r=concat(e,d);
		}
		if(n==1){
			r=(LInt) malloc(sizeof(ABin));
			r->valor=a->valor;
			r->prox=NULL;
		}

	}

	else r=NULL;

	return r;

}
