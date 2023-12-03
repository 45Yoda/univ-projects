#include <stdio.h>
#include <string.h>

void merge (int r[], int a[], int b[], int na, int nb){
    int i,j=0,w=0;
    for(i=0;i<na+nb;i++){
        if(a[j]<=b[w] && j<na || w==nb) {r[i]=a[j];j++;}
        else if (b[w]<a[j] && w<nb || j==na) {r[i]=b[w];w++;}
    }
}

int main(){
    int r[100];
    printf("cenas da vida");
    return 0;
}
