#include <stdio.h>
#include <string.h>

char charMaisfreq(char s[]){
    int i,l=0,c=1,j;
    char m,n;
    if(s[0]=='\0') return 0;

    for(i=0;s[i+1]!='\0';i++){
        n=s[i];
        for(j=i+1;s[j]!='\0' && n!=' ';j++){
            if(n==s[j]) c++;
        }
        if(c>l){m=n;l=c;c=0;}
        else c=0;
    }

    return m;
}

int main(){
    char s[100];
    printf("Insira uma string\n");
    fgets(s,100,stdin);
    printf("O char mais frequente é: %c\n",charMaisfreq(s));
    return 0;
}
