%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"Print"                                  {yylval.str = strdup(yytext);return PRINT;}
"Integer"|"Float"|"Char"|"String"|"Bool" {yylval.str = strdup(yytext);return TIP;}
"Const"                                  {yylval.str = strdup(yytext);return CONST;}


"daca"     {return DACA;}
"altfel"   {return ALTFEL;}
"pentru"   {return PENTRU;}
"cat_timp" {return CAT_TIMP;}

"Main"      {return MAIN;}
"return"    {return RETURN;}
"exit"      {return EXIT;}
"Class"     {return CLASS;}

">=" { return GEQ; }
"==" { return EQ; }
"<=" { return LEQ; }
"!=" { return NEQ; }
"="  {return ASSIGN;}
"||" {return OR;}
"&&" {return AND;}




"+"                             	{return PLUS;}
"-"                             	{return MINUS;}
"*"                             	{return PROD;}
"/"                             	{return DIV;}
"<"                             	{return LESS;}
">"                             	{return GREATER;}
"++"                                {return INCR;}
"--"                                {return DECR;}

adevarat                           {yylval.boolean=strdup(yytext);return BOOLEAN;}
fals                             {yylval.boolean=strdup(yytext); return BOOLEAN;}
[a-zA-Z]+([a-zA-Z]*[_]*[0-9]*)*	     {yylval.str=strdup(yytext); return ID;}
\"[^\"]*\"                           {yylval.str=strdup(yytext); return STRING;}

([1-9][0-9]*|0)                      {yylval.integer=atoi(yytext); return NR_INT;}
([1-9][0-9]*|0)\.([0-9]*)            {yylval.real=atof(yytext); return NR_REAL;}


"#"[^\n\r]* ;
[ \t\r] ;
\n {yylineno++;}
. {return yytext[0];}

