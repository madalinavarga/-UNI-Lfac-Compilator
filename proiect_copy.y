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
%token OR AND
%token LESS GREATER PLUS PROD DIV

%token<nume_var> ID
%token<int_val> NR_INT
%token<real_val> NR_REAL
%token<bool_val> BOOLEAN
%token<char_val> CHAR 
%token<string_val> STRING

//prioritati 
%right ASSIGN

%left EQ
%left GEQ LEQ LESS GREATER

%left PLUS MINUS
%left PROD DIV

%left OR
%left AND
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
main_list : cod
           | main_list cod
           | declaratie_main
           | main_list declaratie_main
          ;
declaratie_main : TIP ID ';'
                ;
//de completat la cod 
cod : interogari
    | bucle
    | ID '(' ')'
    | ID ASSIGN ID ';'
    
    ;
//if = interogari 
interogari : interogari interogare
           | interogare
           ;
interogare : DACA '(' conditie ')' acolade
           | DACA '(' conditie ')' acolade ALTFEL acolade
           ;
// lipsa 
conditie : terminal                     	
     	| '(' conditie ')'			  
       	| conditie PLUS conditie              
       	| conditie MINUS conditie            
       	| conditie PROD conditie              
        | conditie DIV conditie          	   	

		| conditie AND conditie              	
		| conditie OR conditie               
		| conditie LESS conditie 				
		| conditie GREATER conditie 			
		| conditie LEQ conditie 				
		| conditie GEQ conditie 			
		| conditie EQ conditie 				
		;
terminal : ID
         | NR_INT
         | NR_REAL
bucle : bucle bucla 
      | bucla
      ;
bucla : PENTRU ID acolade
     | CATtIMP conditie acolade
     ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
