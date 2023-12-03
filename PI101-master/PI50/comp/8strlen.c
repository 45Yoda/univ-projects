#include <stdio.h>

int mystrlen(char str[]){
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
}

int main(){
    char s[100];
    printf("Insira uma string\n");
    scanf("%s",s);
    printf("O tamanho da string é %d\n",mystrlen(s));
    return 0;
}
