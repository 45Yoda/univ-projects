#include <stdio.h>
#include <string.h>


char *strcat2(char s1[], char s2[]){
    int n=strlen(s1);
    int i;
    for(i=0;s2[i]!='\0';i++){
        s1[n+i]=s2[i];
    }

    return s1;
}

int main(){
    char s1[100];
    char s2[100];
    printf("Insira duas strings\n");
    scanf("%s",s1);
    scanf("%s",s2);
    printf("As strings concatendas são %s\n",strcat2(s1,s2));
    return 0;
}
