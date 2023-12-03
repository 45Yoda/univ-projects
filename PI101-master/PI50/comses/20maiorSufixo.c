#include <stdio.h>
#include <string.h>

int maiorSufixo(char s1[],char s2[]){
    int i,c=0,r=0,n1=strlen(s1),n2=strlen(s2);
    for(i=0;i<n1 && i<n2 && !r; i++){
        if(s1[n1-i-1]==s2[n2-i-1]) c++;
        else{r=1;}
    }
    return c;
}


int main(){
    char s1[100];
    char s2[100];
    printf("Insira duas strings\n");
    fgets(s1,100,stdin);
    fgets(s2,100,stdin);
    printf("Maior sufixo é: %d\n", maiorSufixo(s1,s2));
    return 0;
}
