#include <stdio.h>
#include <string.h>

void mystrrev(char s[]){
    int i,n=strlen(s);
    char tmp;
    for(i=0;i<n/2;i++){
        tmp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = tmp;
    }
    printf("String invertida : %s\n",s);
}

int main(){
    char s[100];
    printf("Insira uma string \n");
    scanf("%s",s);
    mystrrev(s);
    return 0;
}
