#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;


int lengthl(LInt l);
LInt init(int val);

int main(){
    int v = 200;
    int i=0,d=0;
    LInt new = init(v);
    LInt new2 = init(v);

    i=lengthl(new);

    new->prox = new2;

    d=lengthl(new);

    printf("%d %d\n",i,d);


    return 0;
}

LInt init(int val){
    LInt new = (LInt) malloc (sizeof(struct lligada));

    if(new!=NULL){
        new->valor = val;
        new->prox = NULL;
    }

    return new;
}

int lengthl(LInt l){
    int i=0;
    while(l){
        i++;
        l=l->prox;
    }
    return i;

}
