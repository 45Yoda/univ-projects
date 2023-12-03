#include <stdio.h>
#include <string.h>

char *mystrcpy(char *dest,char source[]){
    int i;
    for(i=0;source[i]!='\0';i++){
        dest[i]=source[i];
    }
    dest[i]='\0';
    return dest;
}

int main(){
    char s1[100];
    char s2[100];
    printf("Insira uma string\n");
    scanf("%s",s2);
    printf("O resultado da cópia é %s\n",mystrcpy(s1,s2));
    return 0;
}
