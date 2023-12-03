#include <stdio.h>
#include <string.h>

int crescente(int a[], int i, int j){
    int r=1;
    for(;i<j && r;i++){
        if(a[i]>a[i+1]) r=0;
    }

    return r;
}

int main(){
    int a[5]= {1,2,3,4,5};
    printf("Entre as posições o vetor é %d ordenado\n",crescente(a,2,4));
    return 0;
}
