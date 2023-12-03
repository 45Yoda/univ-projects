#include <stdio.h>
#include <string.h>

int remRep(char x[]){
    int i,j=0;
    for(i=0;x[i]!='\0';i++){
        if(x[i]!=x[i+1]){x[j]=x[i];j++;}
    }
    x[j]='\0';
    printf("String resultante %s\n",x);
    return j;
}

int main(){
    char a[100]="aaabaaabbbaaa";
    printf("A string sem repetidos tem tamanho %d\n",remRep(a));
    return 0;
}
