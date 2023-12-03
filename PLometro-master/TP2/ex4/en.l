%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void begin_struct();

FILE* dot;
char* tags[512];
char *tag;
int level=-1;


%}


%option noyywrap

%% 




\<[^(?!\/ <)]+> {
    level++;
    
    tag = strtok(yytext,"<");
    tag = strtok(tag,">");
    tags[level] = strdup(tag);
    if(level>1)
        fprintf(dot,"%s -> %s\n",tags[level-1],tags[level]);
     
}


\<[^(?!)].*=.*[^(\/)]> { 
    char* at;
    tag = strtok(yytext,"<");
    tag = strtok(tag," ");
    at = strtok(NULL,"=");
    if (level>=0) 
        fprintf(dot,"%s -> %s\n",tags[level],tag);
    fprintf(dot,"%s -> %s [label=\"%s\"]\n",tag,tag,at); 
    level++;
    tags[level] = strdup(tag);    
}

\<[^(?!)].*=.*\/> {
    char* at;
    tag = strtok(yytext,"<");
    tag = strtok(tag," ");
    at = strtok(NULL,"=");
    if (level>=0) 
        fprintf(dot,"%s -> %s\n",tags[level],tag);
    fprintf(dot,"%s -> %s [label=\"%s\"]\n",tag,tag,at); 
    

}


\<\/.*> {
    if(level>0)
        level--;

}

. ;

%%

//C

int main(int argc, char**argv){

	// abrir ficheiro
	dot = fopen("dia.dot","w");
	
	if(argc == 2)
		yyin = fopen(argv[1],"r");

	begin_struct();

	yylex();

	fprintf(dot,"}");


	return 0;
}

//começar a estrutura em formato dot
void begin_struct(){
	fprintf(dot,"strict digraph g {\n");
}


