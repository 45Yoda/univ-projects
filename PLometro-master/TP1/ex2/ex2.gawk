#!/usr/bin/awk -f
#gawk -f ex2.gawk fl0 

BEGIN {
	FS = " ";
	extratos=1;
}
{	
if(!NF)
	extratos++;
}
END{
	print extratos;
}
