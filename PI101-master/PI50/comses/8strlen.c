#include <stdio.h>

int strlen2(char str[]){
    int c=0;
    while(str[c]!='\0') c++;
    return c;
}

int main(){
    char s[100];
    printf("Insira uma string: \n");

    scanf("%s",s);

    printf("O tamanho da string é: %d\n",strlen2(s));
    return 0;
}
