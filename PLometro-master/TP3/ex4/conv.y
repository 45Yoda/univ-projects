%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <glib.h>
    #include "html.c"
    extern char* yytext;
    extern int yylineno;
    extern int yylex();
    void yyerror(char*);
    int isLang(char* tok);
    void addL(GHashTable* g, char* tok);
    void addR (GHashTable* g, char* tok);
    char* langs[16];
    char* base;
    GHashTable *inv = NULL;
    GHashTable *desc = NULL;
    int sl=0;
    GHashTable *table;
    typedef struct conceito {
        GHashTable *traducoes;
        GHashTable *relacoes;
        int nr;
    } *Conc;
    char** getElems(char* string);
    Conc addElems(Conc c,char** elems);
    void printConc(void* key,void* c,void* extra);
    void printTrad(void* key, void* value, void* extra);
    void printRel(void* key, void* values, void* extra);  
    void invHTML (void* key, void* value, void* extra);
    void setLinks (void* key, void* value, void* extra);
    void setLink (void* key, void* extra);
    void genRelacoes(void* key, void* value, void* extra);
%}

%union{
    double num;
    char* str;
  char** list;
}

%type <str> LANGS BASELANG REL TERMO ELEM END INV DESC Conceito Elementos Elemento

%token LANGS BASELANG REL TERMO ELEM END INV DESC

%% 

Gramatica: Diretivas Conceitos{
         int file = open("html/index.html",O_WRONLY | O_TRUNC | O_CREAT, 0666);
         starthtml(file);
         generate_header(file,"<b>Gramática Thesaurus ISO 2788</b>");
         generate_paragraph(file,"<b>Relações Inversas:</b>");
         g_hash_table_foreach(inv,invHTML,&file);
         generate_paragraph(file,"<b>Descrição de relações:</b>");
         g_hash_table_foreach(desc,invHTML,&file);    
         generate_paragraph(file,"<b>Conceitos:</b>");
         g_hash_table_foreach(table,setLinks,&file);
         endhtml(file);
         close(file);
         g_hash_table_foreach(table,printConc,NULL);
}        



Diretivas: Diretiva Diretivas     
| Diretiva;

Diretiva: LANGS {
        char* tok = strtok($1," ");
        tok = strtok(NULL," ");
        while(tok!=NULL) {
            langs[sl] = strdup(tok);
            tok = strtok(NULL," ");
            sl++;
        }
        langs[sl] = NULL;
    }
        | BASELANG {
        char* tok = strtok($1," ");
        tok = strtok(NULL," ");
        base = strdup(tok);
    }   
        | INV {
        char* tok = strtok($1," ");
        char* key = strtok(NULL," ");
        char* value= strtok(NULL," ");
        if(inv == NULL) inv = g_hash_table_new(g_str_hash,g_str_equal);
        g_hash_table_insert(inv,g_strdup(key),g_strdup(value));
    }
        | DESC {
        char* tok = strtok($1," ");
        char* key = strtok(NULL," ");
        char* value= strtok(NULL,"");
        if(desc == NULL) desc = g_hash_table_new(g_str_hash,g_str_equal);
        g_hash_table_insert(desc,g_strdup(key),g_strdup(value));
    }
        | END;

Conceitos: Conceito Conceitos
            | Conceito;

Conceito: TERMO Elementos END{
        int i;
        Conc c = malloc(sizeof(struct conceito));
        char** elems = getElems($2);
        c = addElems(c,elems);
        //free(elems);
        char* filename = malloc(strlen($1)+21);
        sprintf(filename,"html/conceitos/%s.html",$1);
        int fd = open(filename,O_WRONLY|O_CREAT|O_TRUNC, 0666);
        starthtml(fd);
        generate_header(fd,$1);
        generate_paragraph(fd,"<b>Traduções:</b>");
        g_hash_table_foreach(c->traducoes,invHTML,&fd);
        generate_paragraph(fd,"<b>Relações:</b>");
        g_hash_table_foreach(c->relacoes,genRelacoes,&fd);
        endhtml(fd);
        close(fd);
        g_hash_table_insert(table,strdup($1),c);      
}

Elementos: Elemento Elementos {
        $$ = malloc(strlen($1)+strlen($2)+3);
        sprintf($$,"%s::%s",$1,$2);  
}
| Elemento {
    $$ = ($1);
}
|
    ;

Elemento: ELEM {
    $$ = strdup($1);
};


%%

int main(int argc, char* argv[]){
    table = g_hash_table_new(g_str_hash,g_str_equal);
    int file = open(argv[1],O_RDONLY);
    dup2(file,0);
    yyparse();
    return 0;
}

void yyerror(char* erro){
    fprintf(stderr, "%s, %s, %d \n", erro, yytext, yylineno);
}

char** getElems(char* string) {
    char** ret = malloc(1 * sizeof(char*));
    char* tok;
    int i = 0;
    tok = strtok(string,"::");
    
    while(tok!=NULL) {
        if(i>0)
            ret = realloc(ret,(i+1)* sizeof(char*));
        ret[i] = strdup(tok);
        i++;
        tok = strtok(NULL,"::");
    }
    ret = realloc(ret,(i+1)*sizeof(char*));
    ret[i] = NULL; 
    return ret;
}

Conc addElems(Conc c,char** elems) {
    GHashTable* tr = g_hash_table_new(g_str_hash,g_str_equal);
    GHashTable* rel = g_hash_table_new(g_str_hash,g_str_equal); 
    int i = 0;
    char* tok,*aux;
    while(elems[i]!=NULL) {
        //tok = strtok(elems[i]," ");

        tok = elems[i];

        if(isLang(tok))
            addL(tr,tok);
        else
            addR(rel,tok);
        i++;
    }

    c->traducoes = tr;
    c->relacoes = rel;
    return c;
}

int isLang(char* tok) {
    int i,i2;
    if (!tok) return 0;
    
    for(i=0;tok[i]!=' ';i++);
    char* t = malloc(i+1);   
    strncpy(t,tok,i);
    for(i=0;i<sl;i++) {
        if(!strcmp(t,langs[i])){
            free(t);
            return 1;}
    }
    free(t);
    return 0;
}

void addL(GHashTable* g, char* tok) {

    char* value = strstr(tok," ")+1;

    char* key = strtok(tok," "); 
    g_hash_table_insert(g,g_strdup(key),g_strdup(value));
    free(tok);
}


void addR (GHashTable* g, char* tok) {
    char* t;
        int i = 0;
    char* key = strtok(tok," ");
    gpointer v = g_hash_table_lookup(g,key);
    if (v==NULL) {
        GPtrArray  *values = g_ptr_array_new();
        while((t=strtok(NULL,",")) != NULL)  
            g_ptr_array_add (values,(gpointer)g_strdup(t));
        g_hash_table_insert(g,g_strdup(key),values);
    }
    else {
        while((t=strtok(NULL,", ")) != NULL)  
            g_ptr_array_add (v,(gpointer)g_strdup(t));
    } 
    
    free(tok);
}

void printConc(void* key,void* c,void* extra) {
    //printf("%s:{\n",key);
    //Conc cc = (Conc) c;
    //g_hash_table_foreach((cc->traducoes),printTrad,NULL);
    //g_hash_table_foreach((cc->relacoes),(GHFunc)printRel,(void*)cc);
    //printf("\n}\n");

}   

void printTrad(void* key, void* value, void* extra) {
    printf("    %s: %s\n",key,value);

}

void printRel(void* key, void* values, void* extra) {
    printf("    %s: \n",key);
    g_ptr_array_foreach(values,(GFunc)printf,NULL);
    printf("\n");
}

void invHTML (void* key, void* value, void* extra) {    
    int fd = *((int *) extra);
    generate_paragraph2(fd,key,value);
}

void setLinks (void* key, void* value, void* extra) {
    int fd = *((int *) extra);
    char* con = malloc(strlen((char*) key)+21);
    sprintf(con,"conceitos/%s.html",(char*)key);
    generate_link(fd,con,(char*)key);
}

void setLink(gpointer key, gpointer extra) {
    int fd = *((int *) extra);
    char* con = malloc(strlen((char*) key)+21);
    sprintf(con,"%s.html",(char*)key);
    generate_link(fd,con,(char*)key);
}

void genRelacoes(void* key, void* value, void* extra) {
    GPtrArray  *array = (GPtrArray*) value;
    int fd = *((int *) extra);
    
    char* d= g_hash_table_lookup(desc,(char*)key);
    if(d!=NULL) generate_paragraph(fd,d);
    else generate_paragraph(fd,key);

    g_ptr_array_foreach(array,setLink,extra);
}

