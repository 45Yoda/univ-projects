#include <stdio.h>

int soma(){
    int s=0,x;
    printf("Insira uma sequência terminada em zero\n");
    do{
        scanf("%d",&x);
        s+=x;
    }while(x!=0);

    return s;
}

int main(){
    printf("O resultado da soma é: %d \n",soma());
    return 0;
}
