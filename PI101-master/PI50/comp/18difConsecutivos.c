#include <stdio.h>
#include <string.h>

int difConsecutivos(char s[]){
    int i,c=1,m=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]!=s[i+1]) c++;
        else{if(c>m) {m=c;c=1;}}
    }
    return m;
}

int main(){
    char s[100];
    printf("Insira uma string\n");
    scanf("%s",s);
    printf("A maior sub-string com caracteres diferentes %d\n",difConsecutivos(s));
    return 0;
}
