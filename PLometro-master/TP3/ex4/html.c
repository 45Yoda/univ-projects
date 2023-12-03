#include <string.h>

void starthtml(int file){
	write(file,"<!DOCTYPE html> <html><head><meta charset='UTF-8'> </head> <body bgcolor = '#DDDDDD' > \n ",95);
}

void  endhtml(int file){
	write(file,"</body> </html>",15);
}

void  generate_header(int file, char* header) {
	write(file,"<h1> ",5); 
    write(file,header,strlen(header)); 
    write(file," </h1> <hr>",11);
}

void generate_paragraph(int file, char* par) {
	write(file,"<p> ",4); 
    write(file,par,strlen(par)); 
    write(file," </p>",5);
}

void generate_paragraph2(int file, char* par1, char* par2) {
    write(file,"<p> ",4); 
    write(file,par1,strlen(par1));
    write(file," :: ",4);
    write(file,par2,strlen(par2)); 
    write(file," </p>",5);
}

void generate_link(int file,char* link_url,char* link_name) {
	write(file,"<a href='",9); 
    write(file,link_url,strlen(link_url)); 
    write(file,"'> ",3); 
    write(file,link_name,strlen(link_name)); 
    write(file," </a> <br>",10);
}
