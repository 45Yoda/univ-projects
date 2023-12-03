#include <stdio.h>

void addTo(int N, int M, int a[N][M],int b[N][M]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++)
            a[i][j]+=b[i][j];
    }
    for(i=0;i<N;i++){
	        for(j=0;j<M;j++){
		        printf("%.d|",a[i][j]);
	        }
        printf("\n");
    }
}







int main(){
	int i,j,N=3,M=4;;
	int a[3][4]={{1,2,3,4},
				 {0,1,2,3},
				 {1,3,1,2}};
	int b[3][4]={{1,2,3,4},
				 {5,1,2,3},
				 {0,0,1,2}};
	addTo(N,M,a,b);
	return 0;
}
