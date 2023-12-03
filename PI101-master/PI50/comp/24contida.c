#include <stdio.h>
#include <string.h>

int contida(char a[],char b[]){
    int i,r=1;
    for(i=0;a[i]!='\0' && r;i++)
        if(!strchr(b,a[i])) r=0;
    return r;
}

int main(){
    char a[100];
    char b[100];
    printf("Insira duas strings\n");
    fgets(a,100,stdin);
    fgets(b,100,stdin);
    printf("O resultado da função é %d\n",contida(a,b));
    return 0;
}
