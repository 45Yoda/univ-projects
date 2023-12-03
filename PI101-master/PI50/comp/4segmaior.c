#include <stdio.h>

int segmaior(){
    int x,m=0,s=0;
    printf("Insira uma sequência de números terminada em zero\n");
    do{
        scanf("%d",&x);
        if(x>m) {s=m;m=x;}
        else if(x>s) s=x;
    }while(x!=0);

    return s;
}


int main(){
    printf("O segundo maior é %d\n",segmaior());
    return 0;
}
