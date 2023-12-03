#include <stdio.h>
#include <string.h>

int menosFreq(int v[],int N){
    int i,f=1,mef=N,ix=0,cix=0;
    for(i=0;i<N-1;i++){
        if(v[i]==v[i+1]) f++;
        else{
            if(f<mef) {mef=f;ix=cix;}
            f=1;cix=i+1;
        }
    }
    if(v[i]!=v[i-1] && mef>1) ix=i;

    return v[ix];
}

int main(){
    int v[6] = {2,2,2,4,4,5};
    printf("O menos frequente é %d\n",menosFreq(v,6));
    return 0;
}
