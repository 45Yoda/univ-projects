#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dynamic.h"

struct array{
    char** coords;
    long used;
    long size;
};

Array initArray(int initialSize){
    Array a = (Array) malloc(sizeof(struct array));
    a->coords = (char**) malloc(initialSize*sizeof(char*));
    a->used = 0;
    a->size = initialSize;
    return a;
}

Array insertArray(Array a,char* str){
    if(a->used >= (a->size *0.80)){
        a->size *=2;
        a->coords = realloc(a->coords,a->size * sizeof(char*));
    }

    a->coords[a->used++] = strdup(str);

    return a;
}

Array insertInPos(Array a,char* str,int pos){
  a->coords[pos] = strdup(str);

  return a;

}

void freeArray(Array a){
    int i;

    for(i=0; i<a->used;i++){
        free(a->coords[i]);
    }

    free(a->coords);
    free(a);
}

int getPosArray(Array a){
    return a->used;
}

char* getNameArray(Array a,int pos){
    char* novo;

    if(pos > a->used) return NULL;
    novo=malloc((strlen(a->coords[pos]))*sizeof(char));

    strcpy(novo,a->coords[pos]);
    return novo;
}
