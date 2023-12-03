#include <stdio.h>
#include <string.h>

int palindorome (char s[]){
    int i,n=strlen(s),r=1;
    for(i=0;i<n/2 && r;i++){
        if(s[i]!=s[n-i-1]) r=0;
    }

    return r;
}

int main(){
    char t[100]="tacocat";
    printf("A palavra é %d palindorome\n",palindorome(t));
    return 0;
}
