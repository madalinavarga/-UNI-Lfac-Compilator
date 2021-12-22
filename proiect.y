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
variabila_initializata: CONST TIP ID ASSIGN variabila
                      | TIP ID ASSIGN expresie
                      ;
expresie : variabila
         | variabila PLUS expresie              
         | variabila MINUS expresie            
         | variabila PROD expresie              
         | variabila DIV expresie
         ;
variabila   : ID
            | NR_REAL
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
lista_valori : variabila
             | lista_valori ',' variabila
            ;
print: PRINT '(' STRING ',' ID ')'
            ;
 // declaratii functii clase SECTIUNEA 2
functii_clase : functii_declaratie clase_declaratie
              ;
clase_declaratie : class
                 | clase_declaratie class
                 ;
class : CLASS ID '{' continut_clasa'}' ';'
      ;
continut_clasa : declaratie ';'
            | continut_clasa declaratie ';'
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
          ;


//de completat la cod 
cod : interogari
    | bucle
    | ID '(' ')' ';'
    | ID '(' lista_param ')' ';'
    | ID ASSIGN ID '(' lista_param ')' ';'
    | ID ASSIGN ID '('  ')' ';'
    | ID ASSIGN expresie ';'
    | declaratie ';'
    
    
    ;
//if = interogari 
interogari : interogari interogare
           | interogare
           ;
interogare : DACA '(' conditii ')' acolade
           | DACA '(' conditii ')' acolade ALTFEL acolade
           ;
// lipsa 
conditii :  '(' conditii ')' OR '(' conditii ')'
            | '(' conditii ')' AND '(' conditii ')'
            | conditie
            ;			  
conditie    : expresie LESS expresie 				
		| expresie GREATER expresie 			
		| expresie LEQ expresie 				
		| expresie GEQ expresie 			
		| expresie EQ expresie 
            | expresie NEQ expresie 				
		;
bucle : bucle bucla 
      | bucla
      ;
//de modificat 
bucla : PENTRU '(' ')' acolade
     | CATtIMP '(' conditie ')' acolade
     ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
