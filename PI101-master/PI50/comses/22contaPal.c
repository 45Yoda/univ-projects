#include <stdio.h>
#include <string.h>

int contaPal(char s[]){
    int i,c=0;

    if(s[0]!=' ' && s[0]!='\0') c++;

    for(i=0;s[i+1]!='\0';i++){
        if(s[i]==' ' && s[i+1]!=' ') c++;
    }

    if(s[0]=='\0') c=0;

    return c;
}


int main(){
    char s1[100];
    printf("O número de palavras é: %d\n",contaPal("O Yoda foi à pesca"));
    return 0;
}
