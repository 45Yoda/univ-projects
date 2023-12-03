#include <stdio.h>
#include <string.h>

int maiorPrefixo(char s1[], char s2[]){
    int i,c=0,r=0;
    for(i=0;s1[i]!='\0' && s2[i]!='\0' && !r;i++){
        if(s1[i]==s2[i]) c++;
        else r=1;
    }

    return c;
}

int main(){
    char s1[100];
    char s2[100];
    printf("Insira duas strings\n");
    fgets(s1,100,stdin);
    fgets(s2,100,stdin);
    printf("Maior prefixo é: %d\n", maiorPrefixo(s1,s2));
    return 0;
}
