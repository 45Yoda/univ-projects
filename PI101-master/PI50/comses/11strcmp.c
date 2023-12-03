#include <stdio.h>
#include <string.h>

int strcmp2(char s1[], char s2[]){
    int i=0,r=0,c=0;
    if(s1[i]=='\0' && s2[i]!='\0'){c=s1[i]-s2[i];}
    if(s1[i]!='\0' && s2[i]=='\0'){c=s1[i]-s2[i];}
    else{
        for(i=0;s1[i]!='\0' && s2[i]!='\0' && !r;i++){
            c=s1[i]-s2[i];
            if(c!=0) {r=1;}
        }
    }

    return c;
}

int main(){
    char s1[100];
    char s2[100];
    printf("Insira duas strings para comparar\n");
    scanf("%s",s1);
    scanf("%s",s2);
    printf("O resultado da comparação: %d\n",strcmp2(s1,s2));
    return 0;
}
