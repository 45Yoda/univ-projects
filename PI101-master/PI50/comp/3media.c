#include <stdio.h>

int media(){
    int x, s=0, c=0;
    printf("Insira uma sequência de números terminada em zero\n");
    do{
        scanf("%d",&x);
        s+=x;
        c++;

    }while(x!=0);

    s=s/(c-1);

    return s;
}


int main(){
    printf("A média dos números inseridos é %d\n",media());
    return 0;
}
