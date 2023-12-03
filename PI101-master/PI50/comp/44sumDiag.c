#include <stdio.h>

void sumDiag(int N,int m[N][N]){
    int i,j,s=0;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            if(j!=i) s+=m[i][j];
        m[i][i]=s;
        s=0;
    }
    for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
    		printf("%.d|",m[i][j]);
    	}
    printf("\n");
    }
}

int main(){
	int i,j;
	int m[4][4]={{1,2,3,4},
				 {5,6,7,8},
				 {9,10,11,12},
				 {13,14,15,16}};
	sumDiag(4,m);
	return 0;
	}
