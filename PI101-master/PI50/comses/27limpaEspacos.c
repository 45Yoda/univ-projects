#include <stdio.h>
#include <string.h>

int limpaEspacos(char t[]){
    int i,j=0;
    for(i=0;t[i]!='\0';i++){
        if(t[i]!=' '){t[j]=t[i];j++;}
        if(t[i]==' ' && t[i+1]!=' '){t[j]=' ';j++;}
    }
    t[j]='\0';
    printf("String resultante: %s\n",t);
    return j;
}

int main(){
    char a[100]="ola     yoda";
    printf("O tamanho da string resultante: %d\n",limpaEspacos(a));
    return 0;
}
