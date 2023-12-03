#include <stdio.h>
#include <string.h>

void strrev2(char s[]){
    int i, n=strlen(s);
    char t;
    for(i=0;i<n/2;i++){
        t=s[n-i-1];
        s[n-i-1] = s[i];
        s[i] = t;
    }
    printf("A string ao contrário é: %s\n",s);
}


int main(){
    char s[100];
    printf("Insira uma string: \n");
    fgets(s,100,stdin);
    strrev2(s);
    return 0;
}
