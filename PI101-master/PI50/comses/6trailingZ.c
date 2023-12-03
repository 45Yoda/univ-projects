#include <stdio.h>

int trailingZ(unsigned int n){
    int c=0;
    while(n!=0){
        if(n%2==0) c++;
        n/=2;
    }
    return c;
}



int main(){
    int x;
    printf("Insira um número: \n");
    scanf("%d",&x);
    printf("O numero de bits a zero é: %d\n",trailingZ(x));
    return 0;
}
