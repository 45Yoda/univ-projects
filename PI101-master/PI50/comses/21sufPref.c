#include <stdio.h>
#include <string.h>

int sufPref(char s1[], char s2[]){
    int i, j=0,c=0;
    for(i=0;s1[i]!='\0';i++){
        if(s1[i]==s2[j]) {c++;j++;}
        else {j=0;c=0;}
    }

    return c;
}

int main(){
    char s1[100];
    char s2[100];
    printf("Resultado: %d\n", sufPref("batota","totalidade"));
    return 0;
}
