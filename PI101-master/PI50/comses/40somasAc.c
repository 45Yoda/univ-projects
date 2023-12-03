#include <stdio.h>

void somasAc(int v[], int Ac[], int N){
    int i,soma=0;
    for(i=0;i<N;i++){
        soma+=v[i];
        Ac[i]=soma;
    }

    printf("As somas acumuladas são:\n");
    for(i=0;i<N;i++){
        printf("%5i = %d\n",i,Ac[i]);
    }
}


int main(){
    int v[3]={1,2,3};
    int ac[3];
    printf("Vai a codeboard ver");
    somasAc(v,ac,3);
    return 0;
}
