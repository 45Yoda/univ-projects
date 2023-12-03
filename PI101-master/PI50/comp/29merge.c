#include <stdio.h>
#include <string.h>

void merge(int r[],int a[], int b[],int na, int nb){
    int i,j=0,k=0;
    for(i=0;i<na+nb;i++){
        if(a[k]<=b[j] && k<na || j==nb) {r[i]=a[k];k++;}
        else if (a[k]>b[j] && j<nb || k==na)  {r[i]=b[j];j++;}
    }

    for(i=0;i<na+nb;i++){
    		printf("%d|",r[i]);
    	}
    	putchar('\n');
}

int main(){
	int r[100];
	int a[4]={10,20,30,35};
	int b[2]={15,40};
	merge(r,a,b,4,2);
	return 0;
}
