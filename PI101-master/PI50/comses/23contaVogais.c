#include <stdio.h>
#include <string.h>

int contaVogais(char s[]){
    int i, c=0;
    for(i=0;s[i]!='\0';i++){
        if(strchr("AEIOUaeiou",s[i])) c++;
    }

    return c;
}

int main(){
    char s[100]="Kendrick Lamar";
    printf("O número de vogais é: %d\n",contaVogais(s));
    return 0;
}
