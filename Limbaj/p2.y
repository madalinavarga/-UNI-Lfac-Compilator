%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern FILE* yyin;
extern char* yytext;
extern int yylineno;

struct variabile{
      char* tip;
      char* id;
      double valoare;
      char* vizibilitate;
      int constante;
      int dimensiune;
}var[100];
int v=0;

int variabila_deja_declarata(char* nume){
        for (int i = 0; i < v; i++)
        {
                if (strcmp(var[i].id, nume) == 0) return i;
                printf("%lf\n",var[i].valoare);
        }
        return -1;
}

void declarare_fara_initializare(char* tip,char* nume, int este_const){
        if(variabila_deja_declarata(nume)!=-1){
                char error_msg[250];
                sprintf(error_msg, "Variabila %s este deja declarata", nume);
                yyerror(error_msg);
                exit(0);
        }
        if(este_const==1){
                char error_msg[250];
                sprintf(error_msg, "Variabila constanta %s nu poate fi declarata fara initializare", nume);
                yyerror(error_msg);
                exit(0);
        }
        var[v].tip=strdup(tip);
        var[v].id=strdup(nume);
        var[v].vizibilitate=strdup("globala");
        var[v].constante=0;
        v++;
}
void declarare_cu_initializare(char* tip,char* nume,double val,int este_const){
        if(variabila_deja_declarata(nume)!=-1){
                char error_msg[250];
                sprintf(error_msg, "Variabila %s este deja declarata", nume);
                yyerror(error_msg);
                exit(0);
        }
        var[v].tip=strdup(tip);
        var[v].id=strdup(nume);
        var[v].valoare=val;
        var[v].constante=este_const;
        var[v].vizibilitate=strdup("globala");
        v++;
}
%}

%union
{
    double num;
    char* str;
}

%token PRINT CONST DACA ALTFEL PENTRU CAT_TIMP MAIN RETURN EXIT CLASS 
%token GEQ EQ LEQ NEQ ASSIGN OR AND 
%token PLUS MINUS PROD DIV LESS GREATER INCR DECR 
%token CHAR STRING  
%token<num>NR_INT NR_REAL
%token<str> ID TIP

%type<num> expresie

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
 | declaratii_globale main_prog 
 | functii_clase main_prog 
 | main_prog 
 | declaratii_globale {printf("program corect sintactic\n");}
 ;
     
/*sectiunea 1*/
declaratii_globale :  declaratie ';'
	   | declaratii_globale declaratie ';'
	   ;
declaratie  : variabila_initializata
            | variabila_declarata
            | array 
            | print
            ;
variabila_initializata: CONST TIP ID ASSIGN expresie {declarare_cu_initializare($2,$3,$5,1);}
                      | TIP ID ASSIGN expresie {declarare_cu_initializare($1,$2,$4,0);}
                      ;
variabila_declarata: TIP ID {declarare_fara_initializare($1,$2,0);}
                   ;
/*
lista_declaratii : ID
                 | lista_declaratii ',' ID
                 ;
*/
expresie : expresie PLUS expresie  {$$ = $1 + $3;}
         | expresie MINUS expresie {$$ = $1 - $3;}
         | expresie PROD expresie {$$ = $1 * $3;}
         | expresie DIV expresie {$$ = $1 / $3;}
         |'(' expresie ')' {$$ = $2;}
         //| ID 
         | NR_INT {$$ = $1;} 
         | NR_REAL {$$ = $1;} 
         //| ID '[' NR_REAL ']'
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
print:  PRINT '(' STRING ',' ID ')'
     ;

/* sectiunea 2 */
functii_clase : functii_declaratie clase_declaratie
              ;
clase_declaratie : class
                 | clase_declaratie class
                 ;
class : CLASS ID  '{' cod_bloc '}' ';'
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