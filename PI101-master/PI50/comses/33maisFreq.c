#include <stdio.h>
#include <string.h>

int maisFreq(int v[], int N){
    int i,c=1,f=0,ix=0,cix=0;
    for(i=0;i<N-1;i++){
        if(v[i]==v[i+1]) c++;
        else{
            if(c>f) f=c;ix=cix;
            c=1;cix=i+1;
        }
    }
    return v[ix];
}

int main(){
    int v[6] = {2,2,4,4,4,5};
    printf("O mais frequente é %d\n",maisFreq(v,6));
    return 0;
}
