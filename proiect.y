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

declaratie  : variabila_initializata
            | variabila_declarata
            | array 
            | print
            ;
variabila_declarata:  CONST TIP ID 
                    | TIP lista_declaratii
                    ;
variabila_initializata: CONST TIP ID ASSIGN ID 
                      | CONST TIP ID ASSIGN valoare_tip_date
                      | TIP ID ASSIGN valoare_tip_date
                      | TIP ID ASSIGN ID 
                    ;

valoare_tip_date : NR_REAL
                 | NR_INT 
                 | CHAR 
                 | STRING 
                 ;
lista_declaratii : ID
                 | lista_declaratii ',' ID
                 ;
//de modificat
array: TIP ID dimensiune
     | TIP ID '[' ']' ASSIGN '[' lista_valori ']'
     | TIP ID '[' ']' ASSIGN '[' ']'
     ;
dimensiune: '['NR_INT']'
          | dimensiune '['NR_INT']'
          ;
lista_valori : valoare_tip_date
             | lista_valori ',' valoare_tip_date
            ;
print: PRINT '(' STRING ',' ID ')'
            ;
 // declaratii functii clase SECTIUNEA 2
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


 // MAIN SECTIUNEA 3 
main_prog : MAIN'('')' acolade
           ;
acolade : '{' '}'
        | '{' main_list '}'
        ;
main_list : cod
           | main_list cod
           | declaratie_main
           | main_list declaratie_main
           | print 
          ;
declaratie_main : declaratie ';'
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
interogare : DACA '(' conditii ')' acolade
           | DACA '(' conditii ')' acolade ALTFEL acolade
           ;
// lipsa 
conditii :  '(' conditie ')' OR '(' conditii ')'
            | '(' conditie ')' AND '(' conditii ')'
            |conditie
            ;			  
conditie:    variabile LESS variabile 				
		| variabile GREATER variabile 			
		| variabile LEQ variabile 				
		| variabile GEQ variabile 			
		| variabile EQ variabile 
            | variabile NEQ variabile 				
		;
variabile : ID
         | NR_INT
         | NR_REAL
         | variabile PLUS variabile              
         | variabile MINUS variabile            
         | variabile PROD variabile              
         | variabile DIV variabile
         ;
bucle : bucle bucla 
      | bucla
      ;
bucla : PENTRU ID acolade
     | CATtIMP variabile acolade
     ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
