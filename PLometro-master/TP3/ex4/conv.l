%{
	#include <stdio.h>
	#include "y.tab.h"
%}

%option noyywrap

%%

^#.* {;};

^%lang.* {
    yylval.str = strdup(yytext+1);
    return LANGS;
};

^%baselang[A-Z ]+ {
    yylval.str = strdup(yytext+1);
    return BASELANG;
};

^%inv.* {
    yylval.str = strdup(yytext+1);
    return INV;
};

^%desc.* {
    yylval.str = strdup(yytext+1);
    return DESC;
}    

^[A-Z-]+$ {
    yylval.str = strdup(yytext);        
    return TERMO;
}

^[^%\t\n ][^A-Z].* {
    yylval.str = strdup(yytext);        
    return TERMO;
};

^[A-Z_]+.+ {
    yylval.str = strdup(yytext);
    return ELEM;
};

^\n {return END;};

.* {;};

%%
