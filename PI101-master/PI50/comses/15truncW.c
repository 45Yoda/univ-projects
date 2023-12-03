#include <string.h>
#include <stdio.h>

void truncW(char t[],int n){
    int i,j=0,c=0;

    for(i=0;t[i]!='\0';i++){
        if(t[i]!=' '){
            if(c<n){
                t[j] = t[i];
                c++;j++;
            }
        }
        else{
            t[j]=' ';
            j++; c=0;
        }
    }
    t[j]='\0';
    printf("Truncada: %s\n",t);
}

int main(){
    char t[100];
    int n;
    printf("Introduza uma string e um número\n");
    fgets(t,100,stdin);
    scanf("%d",&n);
    truncW(t,n);
    return 0;
}
