#include <stdio.h>

int soma(){
    int x,s;
    printf("Insira uma sequência de números terminada em zero\n");
    do{
        scanf("%d",&x);
        s+=x;
    }while(x!=0);

    return s;
}

int main(){
    printf("A soma dos números inseridos é %d\n",soma());
    return 0;
}
