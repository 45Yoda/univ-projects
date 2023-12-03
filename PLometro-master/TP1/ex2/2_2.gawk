#!/usr/bin/awk -f
#gawk -f ex2.gawk fl0 

BEGIN {
	FS = " ";
	index1 = "nomes.html"
	nomes = "characters.html"
	back = "<a href='" index1 "'> Back </a> <br> <br> " 


}


{	
if(match($5,/^NP$/))
	names[$2]++
}


function starthtml(file_name){

	print "<!DOCTYPE html> <html><head><meta charset='UTF-8'> </head> <body bgcolor = '#DDDDDD' > \n " > file_name

}
function endhtml(file_name){
		print "</body> </html>" > file_name
}

function generate_header(file_name, header) {
	print "<h1> " header " </h1> <hr>" > file_name
}

function generate_paragraph(file_name, par) {
	print "<p> " par " </p>" > file_name
}

function generate_link(file_name, link_url, link_name) {
	print "<a href='" link_url "'> " link_name " </a> <br>" > file_name
}

function generate_html() {
		starthtml(index1)
		generate_header(index1,"Processador de textos preanotados com Freeling")
		generate_paragraph(index1,"De seguida é apresentado a lista dos personagens do Harry Potter (nomes próprios) e respectivo número de ocorrências")
		generate_link(index1,nomes, "Personagens")
		endhtml(index1)
}


END{
	generate_html()
	starthtml(nomes)
	print back > nomes
	print "<ul>" > nomes
	for(n in names)
		print "<li> " n  " -> Ocorrências : " names [n] "</li> <br>"> nomes 
	
}
