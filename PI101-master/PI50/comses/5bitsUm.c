#include <stdio.h>

int bitsUm (unsigned int n){
    int c=0;
    while(n!=0){
        if(n%2 == 1) c++;
        n/=2;
    }

    return c;
}

int main(){
    int x;
    printf("Insira um número: \n");
    scanf("%d",&x);
    printf("O numero de bits a um é: %d\n",bitsUm(x));
    return 0;
}
