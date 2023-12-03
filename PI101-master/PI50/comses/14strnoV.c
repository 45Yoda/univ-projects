#include <stdio.h>
#include <string.h>

void strnoV (char s[]){
    int i,j=0;
    for(i=0;s[i]!='\0';i++){
        if(!strchr("AEIOUaeiou",s[i])){s[j]=s[i];j++;}
    }
    s[j]='\0';
    printf("A string sem vogais é:%s",s);
}

int main(){
    char s[100];
    printf("Insira uma string\n");
    fgets(s,100,stdin);
    strnoV(s);
    return 0;
}
