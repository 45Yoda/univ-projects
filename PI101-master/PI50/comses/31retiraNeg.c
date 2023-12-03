#include <stdio.h>

int retiraNeg(int v[],int N){
    int i,j=0;
    for(i=0;i<N;i++){
        if(v[i]>=0){v[j]=v[i];j++;}
    }

    return j;
}


int main(){
    int v[5]={1,-2,3,-4,5};
    printf("O vetor ficou com %d elementos\n",retiraNeg(v,5));
    return 0;
}
