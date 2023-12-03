#include <stdio.h>

int contaPal(char s[]){
    int i,c=0;
    if(s[0]!='\0' && s[0]!=' ') c++;
    for(i=0;s[i+1]!='\0';i++){
        if(s[i+1]!=' ' && s[i]==' '){ c++;}
    }

    return c;
}

int main(){
    char s[100];
    printf("Insira uma string\n");
    fgets(s,100,stdin);
    printf("A string tem %d palavras \n",contaPal(s));
    return 0;
}
