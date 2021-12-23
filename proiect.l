%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%
"Print"                                  {return PRINT;}
"Integer"|"Float"|"Char"|"String"|"Bool" {yylval.tip=strdup(yytext);return TIP;}
"Const"                                  {return CONST;}

"daca"     {return DACA;}
"altfel"   {return ALTFEL;}
"pentru"   {return PENTRU;}
"cat_timp" {return CATtIMP;}

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
"+=" {return PLSEQ;}
"-=" {return MINEQ;}
"*=" {return MULEQ;}
"/=" {return DIVEQ;}




"+"                             	{return PLUS;}
"-"                             	{return MINUS;}
"*"                             	{return PROD;}
"/"                             	{return DIV;}
"<"                             	{return LESS;}
">"                             	{return GREATER;}
"++"                                {return INCR;}
"--"                                {return DECR;}

[a-zA-Z]+([a-zA-Z]*[_]*[0-9]*)*	    {strcpy(yylval.string_val, yytext); return ID;}
\'[^ \']\'                          {yylval.char_val=yytext[1]; return CHAR;}
\"[^\"]*\"                         {yylval.string_val=strdup(yytext); return STRING;}
-?([1-9][0-9]*|0)                   {yylval.int_val=atoi(yytext); return NR_INT;}
-?([1-9][0-9]*|0)\.([0-9]*)         {yylval.real_val=atof(yytext); return NR_REAL;}

"#"[^\n\r]* ;
[ \t\r] ;
\n {yylineno++;}
. {return yytext[0];}

