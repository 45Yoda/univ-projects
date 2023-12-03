#include <stdio.h>

int maior(){
    int m=0,x;
    printf("Insira uma sequência de números terminada em zero\n");
    do{
        scanf("%d",&x);
        if(x>m){m=x;}

    }while(x!=0);
    return m;
}

int main(){
    printf("O maior é: %d\n",maior());
    return 0;
}
