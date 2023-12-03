#include <stdio.h>
#include <string.h>

char *strcpy2(char *dest, char source[]){
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
    scanf("%s",s1);
    printf("A string copiada: %s\n",strcpy2(s2,s1));
    return 0;
}
