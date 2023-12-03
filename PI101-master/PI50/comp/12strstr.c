#include <stdio.h>
#include <string.h>

char *mystrstr(char s1[],char s2[]){
    int i,r=0;
    char *p=NULL;
    if(s1[0]=='\0' && s2[0]=='\0') return s1;
    for(i=0;s1[i]!='\0' && !r;i++){
        int s=0,j=i;
        for(j;s1[j]!='\0' && s1[j] == s2[s];j++,s++);
        if(s2[s]=='\0'){p=&s1[i];r=1;}
    }
    return p;
}

int main(){
    char s1[100];
    char s2[100];
    printf("Introduza 2 strings:\n");
    scanf("%s",s1);
    scanf("%s",s2);
    printf("Resultado:%s\n",mystrstr(s1,s2));

    return 0;
}
