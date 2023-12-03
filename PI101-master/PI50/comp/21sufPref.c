#include <stdio.h>
#include <string.h>

int sufPref(char s1[], char s2[]){
    int i,j=0;
    for(i=0;s1[i]!='\0' && s2[j]!='\0';i++){
        if(s1[i]==s2[j]) j++;
        else(j=0);
    }
    if(s1[i]!='\0') j=0;
    return j;
}


int main(){
    char s1[100];
    char s2[100];
    printf("Insira duas strings\n");
    scanf("%s",s1);
    scanf("%s",s2);
    printf("O maior sufixo de s1 que é prefixo de s2 é: %d\n",sufPref(s1,s2));
    return 0;
}
