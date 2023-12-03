#include <stdio.h>

int comunsOrd(int a[], int na, int b[], int nb){
    int i,j,c=0;
    for(i=0,j=0;i<na && j<nb;){
        if(a[i]>b[j]) {j++;}
        else{if(a[i]<b[j]){i++;}
             else{c++;j++,i++;}}
    }
    return c;
}

int main(){
    int a[5]={1,2,3,4,5};
    int b[5]={2,4,5,8,9};
    printf("Os vetores tẽm %d elementos comuns\n",comunsOrd(a,5,b,5));
    return 0;
}
