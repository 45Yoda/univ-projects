#!/usr/bin/awk -f
 

BEGIN {
	FS = " ";
	v=0
	index1 = "index.html"
	verbos = "verbs.html"
	subs= "nouns.html"
	adject = "adjectives.html"
	adverb = "adverbs.html"
	back = "<a href='" index1 "'> Back </a> <br> <br> " 
}
{	
	if(match($5,/^V/)){
		verbs[$2]++;

	}
	
	if(match($5,/^N/)){
		nouns[$2]++;
	}
	
	if(match($5,/^A/)){
		adjectives[$2]++;
	}
	
	if(match($5,/^R/)){
		adverbs[$2]++;
	}
}
 function conta(a){
 	k=0
 	for (i in a) k++
 	return k
 }



function starthtml(file_name){

	print "<!DOCTYPE html> <html><head><meta charset='UTF-8'> </head> <body bgcolor = '#DDDDDD' > \n " > file_name

}
function endhtml(file_name){
		print "</body> </html>" > file_name
}

function generate_paragraph(file_name, par) {
	print "<p> " par " </p>" > file_name
}

function funcao(){
		starthtml(index1)
		print "<h1>  Processador de textos preanotados com Freeling </h1> <hr>" > index1
		generate_paragraph(index1,"De seguida apresentamos a lista dos Verbos, Substantivos, Adjetivos e Advérbios.")
		print "<a href='" verbos "'> Verbos </a> <br>" > index1
		print "<a href='"subs"'> Substantivos </a> <br>" > index1
		print "<a href='"adject"'> Adjetivos </a> <br>" > index1
		print "<a href='"adverb"'> Adverbios </a> <br>" > index1

		endhtml(index1)
	}

END{

	funcao()

	starthtml(verbos)
	print "<h1> Verbos </h1> <hr>" > verbos
	print back > verbos 
	print "<h3> Número de entradas : " conta(verbs) "</h3>" > verbos
	print "<ul>" > verbos
	for(v in verbs)
		print  "<li>" v "</li>" > verbos;	
	print "</ul>" > verbos
	endhtml(verbos)


	starthtml(subs)
	print "<h1> Substantivos </h1> <hr>" > subs
	print back > subs
	print "<h3> Número de entradas : " conta(nouns) "</h3>" > subs
	print "<ul>" > subs
	for(n in nouns)
		print "<li>" n "</li>" > subs;
		print "</ul>" > subs 
	endhtml(subs)


	starthtml(adject)
	print "<h1> Adjetivos </h1> <hr>" > adject
	print back > adject
	print "<h3> Número de entradas : " conta(adjectives) "</h3>" > adject
	print "<ul>" > adject
	for(a in adjectives)
		print "<li>" a "</li>" > adject
		print "</ul>" > adject;		
	endhtml(adject)


	starthtml(adverb)
	print "<h1> Advérbios </h1> <hr>" > adverb
	print back > adverb
	print "<h3> Número de entradas : " conta(adverbs) "</h3>" > adverb
	print "<ul>" > adverb
	for(a in adverbs)	
		print "<li>" a "</li>" > adverb
		print "</ul" > adverb
	endhtml(adverb)
}

