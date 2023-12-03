#include <stdio.h>

int qDig(unsigned int n){
    int c=0;
    while(n!=0){
        c++;
        n/=10;
    }
    return c;
}

int main(){
    int x;
    printf("Insira um número\n");
    scanf("%d",&x);
    printf("O número de digitos necessários é %d\n",qDig(x));
    return 0;
}
