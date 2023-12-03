#include <stdio.h>
#include <string.h>

int retiraNeg(int v[],int N){
    int i,j=0;
    for(i=0;i<N;i++){
        if(v[i]>=0) {v[j]=v[i];j++;}
    }
    return j;
}

int main(){
	int a[10]={-10,20,-3,4,54,-12,21,-1,1,1};
	printf("%d\n",retiraNeg(a,10));
	return 0;
	}
