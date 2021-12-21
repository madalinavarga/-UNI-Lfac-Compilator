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
%token PRINT MAIN RETURN ASSIGN CONST EXIT CLASS 
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
s : program
{     
      if(check_compile == 1)
            printf("Limbaj acceptat! Well done!\n");
      else printf("Eroare de compilare! \n");
}
program: declaratii_globale functii_clase main_prog 
 | declaratii_globale main_prog 
 | functii_clase main_prog 
 | main_prog 
 ;

 // declaratii globale sectiune 1 
declaratii_globale : declaratie ';'
             | declaratii_globale declaratie ';'
             ;

declaratie  : CONST TIP ID 
            | TIP lista_declaratii
            | CONST TIP ID ASSIGN NR_INT
            | TIP ID ASSIGN NR_INT
            | CONST TIP ID ASSIGN ID 
            | TIP ID ASSIGN ID 
            | TIP ID dimensiune 
            ;
lista_declaratii : ID
                 | lista_declaratii ',' ID
                 ;

dimensiune: '[' NR_INT ']'
           | dimensiune '['NR_INT']'
           ;
    
 // declaratii functii clase sectiunea 2 
functii_clase : functii_declaratie clase_declaratie
              ;
clase_declaratie : class
                 | clase_declaratie class
                 ;
class : CLASS ID '{' date_membru'}' ';'
      ;
date_membru : data_membru ';'
            | date_membru data_membru ';'
            ;
data_membru : TIP ID
            ;

functii_declaratie : ID '(' lista_param ')' '{' list '}'
                | ID '(' ')' '{' list '}'
                ;
lista_param : param 
            | lista_param ','  param 
            ;
            
param : TIP ID
      ; 
list : TIP ID ';'
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
