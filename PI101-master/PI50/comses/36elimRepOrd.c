#include <stdio.h>
#include <string.h>

int elimRepOrd(int v[],int n){
    int i, j, r=n;
    for(i=0;r>1 && i<r;i++){
        if(v[i]==v[i+1]){
            for(j=i+1;j<r;j++)
                v[j] = v[j+1];
            r--;
            i--;
        }
    }
    return r;
}

int main(){
    int v[5]={1,2,3,5,4};
    printf("O número de elementos restantes é %d\n",elimRepOrd(v,5));
    return 0;
}
