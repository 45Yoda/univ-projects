#include <stdio.h>
#include <string.h>

int maxCresc(int v[], int N){
    int i,c=1,f=0;
    for(i=0;i<N;i++){
        if(v[i]<=v[i+1]) c++;
        else{
            if(c>f) f=c;
            c=1;
            }
    }

    return f;
}

int main(){
    int v[5]={1,2,3,5,4};
    printf("A maior sequência de elementos crescentes tem o tamanho %d\n",maxCresc(v,5));
    return 0;
}
