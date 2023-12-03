#include <stdio.h>

int comuns(int a[], int na, int b[], int nb){
    int i, j, c=0;
    for(i=0;i<na;i++)
        for(j=0;j<nb;j++)
            if(b[j] == a[i]){
                    c++;
                    break;
            }
    return c;
}

int main(){
    int a[5]={1,2,3,4,5};
    int b[5]={2,4,5,8,9};
    printf("Os vetores tẽm %d elementos comuns\n",comuns(a,5,b,5));
    return 0;
}
