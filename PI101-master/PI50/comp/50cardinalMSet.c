#include <stdio.h>

int cardinalMSet(int N,int v[N]){
    int i,s=0;
    for(i=0;i<N;i++){
        s+=v[i];
    }
    return s;
}

int main(){
	int v[10]={4,7,9,9,9,5,9,9,9,9};
	printf("%d\n",cardinalMSet(10,v));
	return 0;
}
