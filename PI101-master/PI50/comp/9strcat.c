#include <stdio.h>
#include <string.h>

char *mystrcat(char s1[],char s2[]){
    int n=strlen(s1),i;
    for(i=0;s2[i]!='\0';i++)
        s1[n+i] = s2[i];
    s1[n+i]='\0';
    return s1;
}

int main(){
    char s1[100];
    char s2[100];
    printf("Insira duas strings\n");
    scanf("%s",s1);
    scanf("%s",s2);
    printf("O resultado da concatenação é %s\n",mystrcat(s1,s2));
    return 0;
}
