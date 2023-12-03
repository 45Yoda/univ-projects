#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1024

int sumatorio();
int maior();
int media();
int segmaior();
int bitsUm();
int trailingZ();
int qDig();
int strlen2();
char *strcat2();
char *strcpy2();
int strcmp2();
char *strstr2();
void strrev();
void strnoV();
void truncW();
char charMaisfreq();
int iguaisConsecutivos();
int difConsecutivos();
int maiorPrefixo();
int maiorSufixo();
int sufPref();
int contaPal();
int contaVogais();
int contida();
int palindrome();
int remRep();
int limpaEspacos();
void insere();
void merge();
int crescente();
int retiraNeg();
int menosFreq();
int maisFreq();

int main(){
    int op, i=0;
    char s1[MAXSIZE];
    char s2[MAXSIZE];
    char s3[MAXSIZE];
    char s4[MAXSIZE];
    int nx[10] = {1,3,6,7,9,5,-2,0,-4,8};
    int ny[5] = {1,4,6,7,9};
    int nz[6] = {2,2,5,5,5,10};
    int nw[9];
    int w[4]={1,2,3,3};
    int l[7] = {1,1,1,2,3,3,4};
    int m[6] = {1,-1,5,-2,4,2};
    strcpy(s1,"Yoda Meister");
    strcpy(s2,"Mei");
    strcpy(s3,"kbcccaac");
    strcpy(s4,"Ola      Yoda");
    do{
        printf("\n Qual é o problema a resolver?\n");
        scanf("%d", &op);
        printf("---\n");
            switch(op){
                case 0 : printf("End.\n");
                         break;
                case 1: sumatorio();
                        break;
                case 2: maior();
                        break;
                case 3: media();
                        break;
                case 4: segmaior();
                        break;
                case 5: bitsUm();
                        break;
                case 6: trailingZ();
                        break;
                case 7: qDig();
                        break;
                case 8: strlen2(s1);
                        break;
                case 9: strcat2(s1,s2);
                        break;
                case 10:strcpy2(s1,s2);
                        break;
                case 11:strcmp2(s1,s2);
                        printf("== %d \n",strcmp2("Ola","Ola"));
                        printf(" > %d \n",strcmp2("Yoda","Master"));
                        printf(" < %d \n",strcmp2("Master","Yoda"));
                        break;
                case 12:strstr2(s1,s2);
                        break;
                case 13:strrev(s1);
                        break;
                case 14:strnoV(s1);
                        break;
                case 15:truncW(s1,2);
                        break;
                case 16:charMaisfreq(s1);
                        break;
                case 17:iguaisConsecutivos(s3);
                        break;
                case 18:difConsecutivos(s3);
                        break;
                case 19:maiorPrefixo("estranho","estramanha");
                        break;
                case 20:maiorSufixo("nananana","banana");
                        break;
                case 21:sufPref("batota","totalidade");
                        break;
                case 22:contaPal("O Yoda foi à pesca");
                        break;
                case 23:contaVogais("Encontrou duas trutas");
                        break;
                case 24:contida("Trutas","Misticas Tru astaas");
                        break;
                case 25:palindrome("tacocat");
                        break;
                case 26:remRep(s3);
                        break;
                case 27:limpaEspacos(s4);
                        break;
                case 28:insere(nx,5,5);
                        for(i=0;i<4;i++)printf("%d",nx[i]);
                        putchar('\n');
                        break;
                case 29:merge(nw,ny,nz,5,4);
                        for(i=0;i<9;i++)printf("%d",nw[i]);
                        putchar('\n');
                        break;
                case 30:crescente(m,1,4);
                        break;
                case 31:retiraNeg(m,6);
                        break;
                case 32:menosFreq(l,7);
                        break;
                case 33:maisFreq(w,4);
                        break;
                default: main();
            }
    } while (op != 0);

    return 0;
}
//1
int sumatorio (){
    int x,s=0;
    printf("Insira uma sequência de números inteiros(terminada com 0)\n");
    while (x!=0){
        scanf("%d",&x);
        s+=x;
    }
    printf("A soma desses números é: %d",s);

    return s;
}
//2
int maior(){
    int x,m=0;
    printf("Insira uma sequência de números inteiros(terminada com 0)\n");
    while(x!=0){
        scanf("%d",&x);
        if (x>m) m=x;
    }
    printf("O maior é: %d",m);

    return m;
}
//3
int media(){
    int x,med=0,c=0;
    printf("Insira uma sequência de números inteiros(terminada com 0)\n");
    while(x!=0){
        scanf("%d",&x);
        med+=x;
        c++;
    }
    med = med/(c-1);
    printf("A média é: %d",med);
    return med;
}
//4
int segmaior(){
    int x, maior=0, segmaior;
    printf("Insira uma sequência de números inteiros(terminada com 0)\n");
    while(x!=0){
        scanf("%d",&x);
        if(x>maior){segmaior = maior; maior = x;}
        else if (x>segmaior) segmaior= x;
    }
    printf("O segundo maior é: %d",segmaior);

    return segmaior;
}

//5
int bitsUm (){
    int x,c=0;
    printf("Introduza um número\n");
    scanf("%d",&x);
    while(x!=0){
        if (x%2 == 1) c++;
        x /= 2;
    }
    printf("O número tem %d bits a um\n",c);

    return c;
}

//6
int trailingZ(){
    int x, c=0;
    printf("Introduza um número\n");
    scanf("%d",&x);
    while(x!=0){
        if(x%2 == 0) c++;
        x /= 2 ;
    }
    printf("O número tem %d bits a zero\n", c );

    return c;
}

//7
int qDig(){
    int x, c=0;
    printf("Introduza um número\n");
    scanf("%d",&x);
    while(x!=0){
        c++;
        x/=10;
    }
    printf("O número tem %d digitos\n",c);

    return c;
}

//8
int strlen2(char s1[]){
    int i,c =0;

    for(i=0;s1[i]!='\0';i++){
        c++;
    }
    printf("O tamanho da string é %d\n",c);
    return c;
}

//9
char *strcat2(char s1[],char s2[]){
    int n = strlen(s1);

    strcpy(s1+n,s2);

    printf("%s",s1);

    return s1;
}

//10
char *strcpy2(char s1[],char s2[]){
    int i;

    for(i=0;s2[i]!='\0';i++){
        s1[i]=s2[i];
    }

    printf("%s",s1);

    return s1;
}

//11
int strcmp2(char s1[],char s2[]){
    int i=0,n;

    do{
        n=s1[i] -s2[i];
        i++;
    }while(n==0 && s1[i] != '\0');

    printf("%d\n",n);
    return n;
}

//12
char *strstr2 (char s1[], char s2[]) { //10 em 10
	int i, j;
	if(s1[0]=='\0' && s2[0]=='\0') return s1;
	for (i=0; s1[i]!='\0'; i++) {
		int s=0; j=i;
		while (s1[j]==s2[s] && s1[j]!='\0') {
			s++; j++;
		}
		if (s2[s]=='\0') {
		    return &s1[i]; break;}
	}
	return NULL;
}



/*
char *strstr2 (char s1[], char s2[]) {


    int i=0, j=0;
    char *p = NULL;

    do{

        if (s1[i] == s2[j]) {
            j++;
            if (p==NULL) p=&s1[i];

        }   else {
            p = NULL;
            j = 0;
        }

        i++;
    } while (s1[i] != '\0' && s2[j] != '\0');

    if (s1[i] == '\0')
        if (s2[j] != '\0') p = NULL;

    printf("%s",p);
    return p;
}
*/

//13
void strrev (char s[]){
    int i;
    int n=strlen(s);
    char t;
    for(i=0;i<n/2;i++){
        t=s[i];
        s[i] = s[n-(i+1)];
        s[n-(i+1)] = t;
    }
    printf("%s",s);
}

//14
int isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U' ) return 1;
    else return 0;
}

void strnoV(char s[]){
    int i,j=0;
    for(i=0;s[i]!='\0';i++){
        if(!(isVowel(s[i]))){s[j]=s[i];j++;}
    }
    s[j] = '\0';
    printf("%s",s);
}

//15
void truncW (char t[], int n){
    int i,j=0,c=0;

    for(i=0;t[i]!='\0';i++){
        if (t[i]!=' '){
            if(c<n){
                t[j] = t[i];
                c++;
                j++;
            }
        }
        else{
            t[j]=' ';
            j++;
            c=0;
            }
        }
    t[j]='\0';
    printf("%s\n",t);
}

//16
char charMaisfreq(char s[]){
    int i,j,x=0,m=0;
    char c,l;
    for (i=0;s[i]!='\0';i++){
        c = s[i];
        for(j=i+1;s[j]!='\0';j++){if(s[j]==c){x++;}}
        if(x>m){m=x;l=c;}
        x=0;

        }
    printf("%c",l);

    return l;

}

//17
int iguaisConsecutivos(char s[]){
    int i,a=1,m=1;
    for (i=0; s[i+1]!='\0';i++){
        if(s[i+1] == s[i]) a++;
        else a=1;

        if(a>m) m=a;
    }

    printf("%d\n",m);
    return m;
}

//18
int difConsecutivos(char s[]){
    int i, a=1,m=0;
    for (i=0;s[i+1]!='\0';i++){
        if(s[i+1] != s[i]) a++;
        else a=1;

        if(a>m) m=a;
    }

    printf("%d\n",m);
    return m;
}

//19
int maiorPrefixo (char s1[], char s2 []){
    int i,r=0;
    for(i=0;s1[i]!='\0' && s2[i]!='\0';i++){
        if(s1[i]==s2[i]){r++;}
        else{break;}
    }
    printf("%d\n",r);
    return r;
}

//20
int maiorSufixo (char s1[], char s2[]){
    int i, c=0;
    for(i=0;s1[i]!='\0' && s2[i]!='\0';i++){
        if(s1[i] == s2[i]){c++;}
        else{c=0;}
    }
    printf("%d\n",c);
    return c;
}

//21
int sufPref(char s1[], char s2[]){
    int i,j=0, c=0;
    for(i=0;s1[i]!='\0';i++){
        if(s1[i]==s2[j]){j++;c++;}
        else{j=0;c=0;}
    }
    printf("%d\n",c);
    return c;
}

//22
int contaPal(char s[]){
    int i,p=0;
    if(s[0]!=' ' && s[0]!='\0') p++;

    for(i=0;s[i+1]!='\0';i++)
        if(s[i]==' ' && s[i+1]!=' ') p++;

    printf("%d\n",p);
    return p;
}

//23
int contaVogais(char s[]){
    int i,v=0;
    for(i=0;s[i]!='\0';i++){
        if(strchr("AEIOUaeiou",s[i])) {v++;}
    }
    printf("%d\n",v);
    return v;
}

//24
int contida(char a[], char b[]){
    int i,r=1;
    for(i=0;a[i]!='\0' && r==1; i++)
        if(strchr(b,a[i])==NULL) r=0;
    printf("%d\n",r);
    return r;
}

//25
int palindrome (char s[]){
    int i, n, r=0;
    n=strlen(s)-1;
    for(i=0;i<(n+1)/2;i++)
        if(s[i] == s[n-i]) r=1;
        else r=0;

    printf("%d\n",r);
    return r;
}

//26
int remRep(char x[]){
    int i,j=0,r=0;
    for (i=0;x[i]!='\0';i++){
        if (x[i]!=x[i+1]) {x[j]=x[i]; j++; r++;}
    }

    x[j] ='\0';
    printf("%d,%s\n",r,x);
    return r;
}

//27
int limpaEspacos(char t[]){
    int i, j=0, c=0;
    for(i=0;t[i]!='\0';i++){
        if(t[i]==' ' && t[i+1]==' ');
        else{t[j] = t[i]; j++;}
    }

    t[j]='\0';
    c=strlen(t);
    printf("%s, %d\n",t,c);

    return c;
}

//28
void insere(int v[], int N, int x){
    int i;
    for (i=N;i>=0;i--)
        if(v[i]<x) {v[i+1] = x; i=0;}
        else v[i+1] = v[i];
}

//29
void merge(int r[], int a[], int b[], int na, int nb){
    int i,j;
    for(i=0;i<na;i++)
        r[i] = a[i];
    for(j=0;j<nb;j++)
        for(i=na-1+j;i>=0;i--)
            if (r[i]<b[j]){r[i+1]=b[j];i=0;}
            else r[i+1] = r[i];

    printf("%s",r);
}

//30
int crescente(int a[], int i, int j){
    int l,r=1;
    for(l=i;l<=j && a[l+1] !='\0';l++){
        if(a[l]>a[l+1]){r=0;break;}
    }

    printf("%d\n",r);
    return r;
}

//31
int retiraNeg(int v[],int N){
    int i,j=0,n=0;

    for(i=0;i<N;i++){
        if(v[i]>=0){v[j]=v[i];j++;n++;}
    }

    for(i=0;i<n;i++){
        printf("%d",v[i]);
    }
    putchar('\n');
    printf("%d \n",n);

    return n;

}

//32
int menosFreq(int v[], int N){
    int i,f=1,c=0,m=N,ix=0;
    for(i=0;i<N;i++){
        if(v[i]==v[i+1]) f++;
        else{
            if(m>f){m=f;ix=c;}
            f=1;c=i+1;
        }
    }
    if(v[i]!=v[i-1] && m>1) ix=1;

    printf("%d\n",ix);

    return ix;
}

//33
int maisFreq(int v[],int N){
    int i,f=1,c=0,m=0,ix=0;
    for(i=0;i<N;i++){
        if(v[i]==v[i+1]) f++;
        else{
            if(m<f){m=f;ix=c;}
            f=1;c=i+1;
        }
    }

    printf("%d\n",ix);

    return ix;
}

//34
int maxCresc (int v[], int N){
    int i,f=1,m=0;
    for(i=0;i<N;i++){
        if(v[i]<v[i+1])
    }
}
