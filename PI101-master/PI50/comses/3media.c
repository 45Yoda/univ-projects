#include <stdio.h>

int media(){
    int m=0,s=0,x;
    printf("Insira uma sequência de números terminada em zero\n");
    do{
        scanf("%d",&x);
        s+=x;
        if(x!=0) m++;
    }while(x!=0);
    m=s/m;

    return m;
}

int main(){
    printf("A média é: %d\n",media());
    return 0;
}
