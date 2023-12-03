#include <stdio.h>
#include <string.h>

int difConsecutivos(char s[]){
    int i,c=1,m=0;
    for(i=0;s[i+1]!='\0';i++){
        if(s[i]!=s[i+1]) c++;
        else c=1;

        if(c>m){m=c;}
    }
    return m;
}

int main(){
    char s[100];
    printf("Insira uma string\n");
    fgets(s,100,stdin);
    printf("O maior número de diferentes consecutivos é: %d\n",difConsecutivos(s));
    return 0;
}
