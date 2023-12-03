#include <stdio.h>

int minInd(int v[], int n){
    int i, ix=0;
    for(i=0;i<n;i++)
        if(v[i]<v[ix]) ix=i;

    return ix;
}

int main(){
    int v[5]={1,2,3,4,5};
    printf("O indice do menor elemento é %d\n",minInd(v,5));
    return 0;
}
