%{
#include <stdio.h>     /* C declarations used in actions */
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//Esentiale
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

// programul compileaza corect
int check_compile = 1;
%}

%union {
int int_val;
float real_val;
int bool_val;
char char_val;
char* string_val;
char* nume_var;
char* tip;
}

//start 
%start program

//token 
%token PRINT MAIN RETURN ASSIGN 
%token TIP
%token DACA ALTFEL PENTRU CATtIMP
%token GEQ EQ LEQ NEQ

%token<nume_var> ID
%token<int_val> NR_INT
%token<real_val> NR_REAL
%token<bool_val> BOOLEAN
%token<char_val> CHAR 
%token<string_val> STRING

//prioritati 

%%
program : 
