#include <stdio.h>
#include <string.h>

int mystrcmp(char s1[], char s2[]){
    int i,c=0,r=0;
    for(i=0;s1[i]!='\0' && s2[i]!='\0' && !r;i++){
        c=s1[i]-s2[i];
        if(c!=0) r=1;
    }

    return c;
}

int main(){
    char s1[100];
    char s2[100];
    printf("Insira duas strings\n");
    scanf("%s",s1);
    scanf("%s",s2);
    printf("O resultado da comparação é %d\n",mystrcmp(s1,s2));
    return 0;
}
