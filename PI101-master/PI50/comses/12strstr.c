#include <stdio.h>
#include <string.h>

char *strstr2(char s1[],char s2[]){
    int i,j;
    if(s1[0]=='\0' && s2[0]=='\0') return s1;
    for(i=0;s1[i]!='\0';i++){
        int s=0; j=i;
        while(s1[j]==s2[s] && s1[j]!='\0'){
            s++;j++;
        }
        if(s2[s]=='\0'){
            return &s1[i];break;
        }
    }
    return NULL;
}
int main(){
    char s1[100];
    char s2[100];
    printf("Introduza 2 strings:\n");
    scanf("%s",s1);
    scanf("%s",s2);
    printf("Resultado:%s\n",strstr2(s1,s2));

    return 0;
}
