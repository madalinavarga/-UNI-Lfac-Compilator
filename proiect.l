%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"daca" {return daca;}
"altfel" {return altfel;}
"pentru" {return pentru;}
"cat timp" {return catTimp;}
-?([1-9][0-9]*|0) {yylval.intval=atoi(yytext); return nr_int;}
-?([1-9][0-9]*|0)\.([0-9]*) {yylval.realval=atof(yytext); return nr_real;}
[ \t\r] ;
\n {return 0;}
. {return yytext[0];}