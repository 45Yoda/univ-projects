#include <stdio.h>
#include <string.h>

int maiorPrefixo(char s1[], char s2[]){
    int i;
    for(i=0;s1[i]!='\0' && s2[i]!='\0' && s1[i]==s2[i];i++);
    return i;
    }

int main(){
    char s1[100];
    char s2[100];
    printf("Insira duas strings\n");
    scanf("%s",s1);
    scanf("%s",s2);
    printf("O maior prefixo comum entre as duas strings é: %d\n",maiorPrefixo(s1,s2));
    return 0;
}
