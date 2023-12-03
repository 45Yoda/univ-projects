#include <stdio.h>

int minInd(int v[],int N){
    int i,ix=0;
    for(i=0;i<N;i++){
        if(v[i]<v[ix]) ix=i;
    }
    return ix;
}

int main(){
    int v[5]={3,2,1,4,5};
    printf("O indice do menor elemento é %d\n",minInd(v,5));
    return 0;
}
