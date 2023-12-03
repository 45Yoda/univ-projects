#include <stdio.h>

int maior(){
    int x,m=0;
    printf("Insira uma sequência de números terminada em zero\n");
    do{
        scanf("%d",&x);
        if(x>m) m=x;
    }while(x!=0);
    return m;
}

int main(){
    printf("O maior número é %d\n",maior());
    return 0;
}
