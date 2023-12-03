#include <stdio.h>

void transposta (int N, float m[N][N]){
    int i, j;
    float tmp;
    for(i=0;i<N;i++){
        for(j=i;j>=0;j--){
            tmp=m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }
    for(i=0;i<N;i++){
    	for(j=0;j<N;j++){
    		printf("%.0f|",m[i][j]);
    	}
    printf("\n");
    }
}

int main(){
	int i,j,N=4;
	float a[4][4]={{1,2,3,4},
				 {0,1,2,3},
				 {0,0,1,2},
				 {0,0,0,1}};
	transposta(N,a);
	return 0;
}
