#include <stdio.h>

void ascii(){
    char a;
    for(a='A';a<='Z';a++)
        printf("%c - %d\n",a,a);
    for(a='a';a<='z';a++)
        printf("%c - %d\n",a,a);
}

int main(){
    ascii();
    return 0;
}
