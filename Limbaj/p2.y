%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}

%union
{
    int num;
    char* str;
}

%token PRINT CONST DACA ALTFEL PENTRU CAT_TIMP MAIN RETURN EXIT CLASS 
%token GEQ EQ LEQ NEQ ASSIGN OR AND 
%token PLUS MINUS PROD DIV LESS GREATER INCR DECR 
%token ID CHAR STRING NR_INT NR_REAL TIP

%start s

//prioritati 
%right ASSIGN

%left EQ
%left ','
%left GEQ LEQ LESS GREATER

%left PLUS MINUS
%left PROD DIV

%left OR
%left AND
%left NEQ
%left INCR DECR


%%
s: declaratii_globale functii_clase  main_prog {printf("program corect sintactic\n");}
     ;
/*sectiunea 1*/
declaratii_globale :  declaratie ';'
	   | declaratii_globale declaratie ';'
	   ;
declaratie  : variabila_initializata
            | variabila_declarata
            | array 
            ;
variabila_initializata: CONST TIP ID ASSIGN expresie 
                      | TIP ID ASSIGN expresie 
                      ;
variabila_declarata: TIP lista_declaratii
                   ;
lista_declaratii : ID
                 | lista_declaratii ',' ID
                 ;
expresie : expresie PLUS expresie
         | expresie MINUS expresie
         | expresie PROD expresie
         | expresie DIV expresie
         |'(' expresie ')'
         | ID
         | NR_INT
         | NR_REAL
         | ID '[' NR_REAL ']'
         ;
array : TIP ID dimensiune
      | TIP ID '[' ']' ASSIGN '{' lista_valori '}'
      ;
dimensiune : '['NR_INT']'
          | dimensiune '['NR_INT']'
          ; 
lista_valori : lista_valori ',' valoare
             | valoare
             ;
valoare :  NR_INT
        | NR_REAL
        | STRING
        ;

/* sectiunea 2 */
functii_clase : functii_declaratie clase_declaratie
              ;
clase_declaratie : class
                 | clase_declaratie class
                 ;
class : CLASS ID acolade ';'
      ;

functii_declaratie :TIP ID '(' lista_param ')' acolade
                | TIP ID '(' ')' acolade
                ;
lista_param : TIP ID 
            | lista_param ','  TIP ID
            ;

/*sectiunea 3 */
main_prog : MAIN '('  ')' acolade
     ;
acolade : '{' '}'
        | '{' cod_bloc '}'
        ;
cod_bloc : cod_bloc cod
         | cod
         ;
cod: interogari
   | functie_for
   | functie_while
   | declaratie ';'
   | statement ';'
   | asignare ';'
   | functii_declaratie //
   ;
asignare : ID ASSIGN expr
         | ID '['NR_INT ']' ASSIGN expr
         ;
expr: expr PLUS expr
    | expr MINUS expr
    | expr PROD expr
    | expr DIV expr
    |'(' expresie ')'
    | ID
    | NR_INT
    | NR_REAL
    | ID '[' NR_REAL ']'
    | apel_functie
    ;
apel_functie :  ID '(' ')'              
             | ID '(' lista_apel')' 
             ;
lista_apel: expr
          | lista_apel',' expr
          ;
statement: ID INCR
         | apel_functie
         | ID DECR
         | INCR ID
         | DECR ID 
         ;
    
interogari: DACA '(' conditie ')' '{' cod_bloc '}'
          | DACA '(' conditie ')' '{' cod_bloc '}' ALTFEL '{' cod_bloc '}'
          ;
			  
conditie : expr LESS expr				
         | expr GREATER expr			
	 | expr LEQ expr 				
	 | expr GEQ expr			
	 | expr EQ expr 
         | expr NEQ expr
         | conditie AND conditie
         | conditie OR conditie
         | expr			
	 ;

functie_while : CAT_TIMP '(' conditie')' '{' cod_bloc '}'
              ;
functie_for: PENTRU '('for_list')' '{' cod_bloc '}'
           ;
for_list: asignare ';' conditie ';' statement
        ;

%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 