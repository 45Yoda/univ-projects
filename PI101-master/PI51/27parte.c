#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt

LInt parte (LInt l){
    LInt ret, prev1 = NULL; //lista resultante
    LInt prev2 = NULL; //lista original
    int i;

    for(i=1;l;i++,l=l->prox){
        if(i%2 !=0){
            if(prev1) prev1->prox = l;

            prev1 = l;
        }

        else{
            if(prev2) prev2->prox = l;
            else ret = l;

            prev2 = l;
        }
    }
    if(prev1) prev1->prox = NULL;
    if(prev2) prev2->prox = NULL;

    return ret;
}
