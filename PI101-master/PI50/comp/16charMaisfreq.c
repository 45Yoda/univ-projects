#include <stdio.h>
#include <string.h>

char charMaisfreq(char s[]){
    int i,j=0,c=0,m=0,ix=0;
    for(i=0;s[i]!='\0';i++){
        j=i;
        for(j;s[j]!='\0';j++){
            if(s[j]==s[i]) c++;
        }
        if(c>m) {m=c;ix=i;c=0;}
    }

    return s[ix];
}


int main(){
    char s[100];
    printf("Insira uma string\n");
    scanf("%s",s);
    printf("O caracter mais frequente é %c\n",charMaisfreq(s));
    return 0;

}
