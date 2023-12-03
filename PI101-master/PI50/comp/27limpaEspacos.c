#include <stdio.h>
#include <string.h>

int limpaEspacos(char t[]){
    int i,j=0,c=0;
    for(i=0;t[i]!='\0';i++){
        if(t[i]!=' ') {t[j]=t[i];j++;c++;}
        else{
            if(t[i+1]!=' ') {t[j]=t[i];j++;c++;}
        }
    }
    t[j]='\0';
    return c;
}

int main(){
    char a[100]="ola     yoda";
    printf("O tamanho da string resultante: %d\n",limpaEspacos(a));
    return 0;
}
