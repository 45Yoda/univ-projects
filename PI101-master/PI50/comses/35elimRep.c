#include <stdio.h>
#include <string.h>

int elimRep(int v[], int n){
    int i,j,p=1,e=0;
    int nv[n];
    for(i=1;i<n;i++){
        for(j=p-1;j>=0 && e==0;j--)
            if(v[i] == v[j]) e++;
        if(e==0){v[p]=v[i];p++;}
        e=0;
    }
    return p;
}

int main(){
    int v[5]={1,2,3,5,4};
    printf("O número de elementos restantes é %d\n",elimRep(v,5));
    return 0;
}
