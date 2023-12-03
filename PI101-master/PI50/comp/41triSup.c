#include <stdio.h>

int triSup(int N, float m [N][N]){
    int i,j,k=0,r=1;
    for(i=0;i<N;i++,k++){
        for(j=0;j<k;j++)
            if(m[i][j]!=0) r=0;
        }
    return r;
}

int main(){
    float m [3][3]={0,0,0,0,0,0,0,0,0};
    printf("A matriz %d triangular superior\n",triSup(3,m));
    return 0;
}
