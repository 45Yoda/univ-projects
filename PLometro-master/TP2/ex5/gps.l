%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic.h"

void trataLatLon(char*);
void trataEle(char*);
void startStruct(int);
void beginKML();
void endKML();
void gatherCoords();

FILE* res;
Array arr;
int i=-1;
%}

%option noyywrap

%%

\ lat=\".*\"  {trataLatLon(yytext);}



\<ele>.*<\/ele> {trataEle(yytext);}

%%
//C

int main(int argc, char**argv){

	// abrir ficheiro
	res = fopen("res.kml","w");

//	yyout = res;

	//aponta para o ficheiro de input que deve ser scanned
	if(argc == 2)
		yyin = fopen(argv[1],"r");

	startStruct(10);
  beginKML();
	yylex();
	gatherCoords();
	endKML();

	return 0;
}

void startStruct(int size){
	arr = initArray(size);
}


void beginKML(){
  fprintf(res,"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
  fprintf(res,"<kml xmlns=\"http://earth.google.com/kml/2.1\">\n");
  fprintf(res,"<Document>\n");
  fprintf(res,"	<Style id=\"route\">\n");
  fprintf(res,"		<LineStyle>\n");
  fprintf(res,"			<color>64FFFFFF</color>\n");
  fprintf(res,"			<width>2</width>\n");
  fprintf(res,"		</LineStyle>\n");
  fprintf(res," 	</Style>\n");
  fprintf(res,"	<Placemark>\n");
  fprintf(res,"		<name>Rota 1</name>\n");
  fprintf(res,"		<styleUrl>#route</styleUrl>\n");
  fprintf(res,"	<LineString>\n");
  fprintf(res,"		<tessellate>1</tessellate>\n");
  fprintf(res,"		<coordinates>");
}

void endKML(){
  fprintf(res,"\n		</coordinates>\n");
  fprintf(res,"	</LineString>\n");
  fprintf(res,"	</Placemark>\n");
  fprintf(res,"</Document>\n");
  fprintf(res,"</kml>\n");
}

void gatherCoords(){
	int sizeA = getPosArray(arr);
	char* coords;
	printf("%d\n",sizeA);

	for(int i=0;i<sizeA;i++){
		coords = getNameArray(arr,i);
		fprintf(res,"\n\t\t%s",coords);
	}

}

void trataLatLon(char* str){
	char* pch;
	char* lat;
	char* lon;
	char* result;

	char* tmp = malloc(strlen(str)*sizeof(char));
	strcpy(tmp,str);

	// Latitude
	pch = strtok(tmp, " ");
	pch= strtok(pch,"\"");
	lat = strtok(NULL," ");

	strcpy(tmp,str);

	// Longitude
	pch = strtok(tmp, " ");
	pch = strtok(NULL," ");
	pch = strtok(pch,"\"");
	lon = strtok(NULL," ");


  lat[strlen(lat)-1] = ',';
	lon[strlen(lon)-1] = ',';
	int fullsize = strlen(lat) + strlen(lon);
	result = malloc(fullsize*sizeof(char));

	strcpy(result,lon);

	strcat(result,lat);

	printf("%s\n\n\n\n\n\n\n",result);
	insertArray(arr,result);
	++i;

}

void trataEle(char* str){
	char* pch;
	char* ele;
	char* coord;
	char* result;

	char* tmp = malloc(strlen(str)*sizeof(char));
	strcpy(tmp,str);

	pch = strtok(tmp, ">");
	ele = strtok(NULL, "</");


	coord = getNameArray(arr,i);

	int size = strlen(coord)+strlen(ele);

	result = (char*) malloc(size*sizeof(char)+1);

	strcpy(result,coord);

	strcat(result,ele);


	printf("%s\n\n\n",result);

	insertInPos(arr,result,i);

}
