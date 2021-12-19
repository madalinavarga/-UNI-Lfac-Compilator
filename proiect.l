%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"Print"                                  {return PRINT;}
"Integer"|"Float"|"Char"|"String"|"Bool" {yylval.string=strdup(yytext);return TIP} // not sure asa sau fiecare separat 

"daca" {return DACA;}
"altfel" {return ALTFEL;}
"pentru" {return PENTRU;}
"cat timp" {return CATtIMP;}

"main"      {return MAIN;}
"return"    {return RETURN; }

">=" { return GEQ; }
"==" { return EQ; }
"<=" { return LEQ; }
"!=" { return NEQ; }
"=" {return ASSIGN;}


[a-zA-Z]+([a-zA-Z]*[_]*[0-9]*)*	    {strcpy(yylval.string, yytext); return ID;}
\'[^ \']\'                          {yylval.caraval=yytext[1]; return CHAR;}
\"[^ \"]*\"                         {yylval.sirval=strdup(yytext); return STRING;}
-?([1-9][0-9]*|0)                   {yylval.intval=atoi(yytext); return NR_INT;}
-?([1-9][0-9]*|0)\.([0-9]*)         {yylval.realval=atof(yytext); return NR_REAL;}
("false")|("true")                  {yylval.bulval=strdup(yytext); return BOOLEAN;}
"#"[^\n\r]* ;
[ \t\r] ;
\n {return 0;}
. {return yytext[0];}