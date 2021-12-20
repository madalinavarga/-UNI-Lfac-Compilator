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
%start s

//token 
%token PRINT MAIN RETURN ASSIGN CONST
%token TIP
%token DACA ALTFEL PENTRU CATtIMP
%token GEQ EQ LEQ NEQ
%token LESS GREATER PLUS PROD DIV

%token<nume_var> ID
%token<int_val> NR_INT
%token<real_val> NR_REAL
%token<bool_val> BOOLEAN
%token<char_val> CHAR 
%token<string_val> STRING

//prioritati 
%left PLUS MINUS
%left PROD DIV
%%
s: declaratii_globale functii_clase main_prog {printf("program corect sintactic\n");}
 | declaratii_globale main_prog {printf("program corect sintactic\n");}
 | functii_clase main_prog {printf("program corect sintactic\n");}
 | main_prog {printf("program corect sintactic\n");}
 ;

 // declaratii globale sectiune 1 
 // declaratii functii clase sectiunea 2 
 // main 
main_prog : main'('')' acolade
           ;
acolade : '{' '}'
        | '{' main_list '}'
        ;
main_list : TIP ID // de modificat 
          ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 

