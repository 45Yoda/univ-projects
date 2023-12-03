#include <stdio.h>
#include <string.h>

int contida(char a[], char b[]){
    int i, j=0,r=0;
    for(i=0;b[i]!='\0' && a[j]!='\0' && !r;i++){
        int s=i;
        for(s;b[s]!='\0';s++){
            if(a[j]==b[s]) {j++;}
        }
        if(b[s]=='\0') r=1;
    }

    if(a[j]=='\0') r=1;

    return r;
}

int main(){
    char a[100]="cat";
    char b[100]="catabolismo";
    printf("Resultado : %d\n",contida(a,b));
    return 0;
}
