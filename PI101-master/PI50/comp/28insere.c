#include <stdio.h>
#include <string.h>

void insere(int v[],int N, int x){
    int i,j;
    for(i=0;i<N && x>v[i];i++);
    for(j=N;j>i;j--) v[j] = v[j-1];
    v[i]=x;

    printf("O vetor ordenado com a inserção \n");
    for(i=0;i<N+1;i++){
        printf("%d\n",v[i]);
    }
}
int main(){
    int v[100]= {1,2,3,4,6};
    insere(v,5,5);
    return 0;
}
