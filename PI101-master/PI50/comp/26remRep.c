#include <stdio.h>
#include <string.h>

int remRep(char x[]){
    int i,j=0,c=0;
    for(i=0;x[i]!='\0';i++){
        if(x[i]!=x[i+1]){x[j]=x[i]; c++;j++}
    }
    x[j]='\0';

    return c;
}

int main(){
    char x[100];
    printf("Insira uma string\n");
    scanf("%s",x);
    printf("A string sem repetidos tem %d elementos\n",remRep(x));
    return 0;
}
