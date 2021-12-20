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
char* bool_val;
char char_val;
char* string_val;
char* nume_var;
char* tip;
}

//start 
%start s

//token 
%token PRINT MAIN RETURN ASSIGN CONST EXIT
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
 declaratii_globale: 
 // declaratii functii clase sectiunea 2 
functii_clase : functii_declaratie
                ;
functii_declaratie : ID '(' lista_param ')' '{' list '}'
                | ID '(' ')' '{' list '}'
                ;
lista_param : param
            | lista_param ','  param 
            ;
            
param : TIP ID
      ; 
list : TIP ID
     ;
 // main 
main_prog : MAIN'('')' acolade
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

