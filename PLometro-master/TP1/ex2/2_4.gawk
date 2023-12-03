#!/usr/bin/awk -f
#gawk -f ex2.gawk fl0

BEGIN {
	FS = " ";
	index1 = "dicionario.html"
	dicionario = "di.html"

	back = "<a href='" index1 "'> Back </a> <br> <br> "
}
{
list[$3][$2]
listB[$3]=$5

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
		generate_paragraph(index1,"De seguida apresentamos o dicionário implícito no corpora – lista contendo os lema, pos e palavras dele derivadas.")
		generate_link(index1, dicionario, "Dicionário")
		endhtml(index1)
}

END{

	generate_html()
	starthtml(dicionario)
	print back > dicionario
	print "<ul>" > dicionario
	for(l in list){
		print "<li> Lema: " l " Pos : " listB[l] "<br>-> Palavras : <ul>" > dicionario
		for(word in list[l])

		print "<li>" word "</li>" > dicionario
		print " </ul> </li> <br> " > dicionario

	}
	print "</ul>" > dicionario

	endhtml(dicionario)
}
