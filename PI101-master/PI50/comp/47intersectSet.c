#include <stdio.h>

int intersectSet(int N, int v1[N],int v2[N],int r[N]){
    int i;
    for(i=0;i<N;i++){
        if(v1[i]==1 && v2[i]==1) r[i]=1;
        else{r[i]=0;}
    }
    for(i=0;i<N;i++){
        printf("%.d|",r[i]);
    }
    printf("\n");
}

int main(){
    int v1[10]={0,1,1,1,0,0,1,0,1,0};
    int v2[10]={1,0,0,0,1,1,1,0,1,0};
    int r[10] = {0,0,0,0,0,0,0,0,0,0};
    intersectSet(10,v1,v2,r);
    return 0;
}
