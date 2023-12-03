#include <stdio.h>

int intersectMSet(int N,int v1[N],int v2[N],int r[N]){
    int i;
    for(i=0;i<N;i++){
        if(v1[i]<=v2[i]) r[i]=v1[i];
        else{if(v1[i]>v2[i]) r[i]=v2[i];
             else r[i]=0;
         }
     }
    for(i=0;i<N;i++){
        printf("%.d|",r[i]);
     }
    printf("\n");
 }


 int main(){
 	int v1[10]={7,4,5,5,9,9,9,9,9,9};
 	int v2[10]={5,4,4,9,9,9,9,9,9,9};
 	int r[10] = {0,0,0,0,0,0,0,0,0,0};
 	intersectMSet(10,v1,v2,r);
 	return 0;
}
