typedef struct lligada{
    int valor;
    struct lligada *prox;
}*LInt;

void imprimeL(LInt l){
    while(l){
        printf("%d\n",l->valor);
        l=l->prox;
    }
}
