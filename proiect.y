%{
#include <stdio.h>     /* C declarations used in actions */
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h> 

//Esentiale
extern FILE* yyin;
extern char* yytext;
extern int yylineno;

// programul compileaza corect
int check_compile = 1;
int count_var;
char fisier_variabile[]="symbol_table.txt";
char fisier_functii[]="symbol_table_functions.txt ";

struct variabile{
      char* tip;
      char* id;
      char* valoare;
      char* vizibilitate;
      int constante;
      int dimensiune;
}var[100];

struct parametru{
      char* tip;
      char* id;
};

struct functii{
      char* tip_return;
      char* id;
      struct parametru parametrii_functii[10];
      struct variabile variabile_functii[100];

}functii[100];

FILE *functii_fisier_ptr, *var_fisier_ptr;

// declarare functii + implementare jos dupa seciuni

void openFileWrite(FILE* fd,char * fileName);
void scrieVariabileFisier();
bool cautaVariabila(char* nume, char* tip, char* vizibilitate);
void seteazaAtributeStruct(char* tip, char* id, char* valoare, int constante, int dimensiune);

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
%token<tip> TIP
%token DACA ALTFEL PENTRU CATtIMP
%token GEQ EQ LEQ NEQ
%token OR AND
%token LESS GREATER PLUS PROD DIV
%token INCR DECR PLSEQ MINEQ MULEQ DIVEQ

%token<nume_var> ID
%token<int_val> NR_INT
%token<real_val> NR_REAL
%token<bool_val> BOOLEAN
%token<char_val> CHAR 
%token<string_val> STRING

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
declaratii_globale : declaratie ';'              {var[count_var].vizibilitate=strdup("global");}
             | declaratii_globale declaratie ';' {var[count_var].vizibilitate=strdup("global");}
             ;

declaratie  : variabila_initializata 
            | variabila_declarata
            | array 
            | print
            ;
variabila_declarata:  CONST TIP ID 
                    | TIP lista_declaratii
                    ;
variabila_initializata: CONST TIP ID ASSIGN variabila {if(cautaNume($3,var[count_var].vizibilitate)==true){seteazaAtributeStruct($2,$3,$5,1,NaN),count_var++;} else{ exit(0);}}
                      | TIP ID ASSIGN expresie
                      | TIP ID ASSIGN apel_functie
                      ;
expresie : variabila
         | variabila PLUS expresie              
         | variabila MINUS expresie            
         | variabila PROD expresie              
         | variabila DIV expresie
         ;
variabila   :  NR_REAL
            | ID
            | NR_INT 
            | CHAR 
            | STRING 
            | BOOLEAN
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
class : CLASS ID acolade ';'
      ;

functii_declaratie :TIP ID '(' lista_param ')' acolade {var[count_var].vizibilitate=strdup("local");}
                | TIP ID '(' ')' acolade               {var[count_var].vizibilitate=strdup("local");}
                ;
lista_param : TIP ID 
            | lista_param ','  TIP ID
            ;


 // MAIN SECTIUNEA 3 
main_prog : MAIN'('')' acolade  
           ;
acolade : '{' '}'              {var[count_var].vizibilitate=strdup("local");}
        | '{' bloc_cod '}'      {var[count_var].vizibilitate=strdup("local");}
        ;

bloc_cod : cod               
           | bloc_cod cod
           ;


//de completat la cod 
cod : interogari                    
    | bucle                    
    | apel_functie ';'              
    | ID ASSIGN apel_functie ';'    
    | ID ASSIGN expresie ';' 
    | ID '[' NR_INT ']' ASSIGN expresie ';'       
    | declaratie ';' 
    | functii_declaratie               
    | print
    ;
apel_functie: ID '(' ')'              
            | ID '(' lista_variabile ')' 
            ;
lista_variabile: variabila
               | lista_variabile ',' variabila
               ;
//if = interogari 

interogari : DACA '(' conditii ')' acolade 
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
            | expresie				
		;

bucle:  functie_for 
     | functie_while
     ;
     
functie_while: CATtIMP '(' conditii ')' acolade
            ;

functie_for: PENTRU '('for_list')' acolade
           ;
for_list: asignare ';' conditie ';' statement
        ;
asignare: ID ASSIGN variabila
        ;

statement : ID INCR
          | ID DECR
          | INCR ID
          | DECR ID
          | ID ASSIGN expresie
          | ID PLSEQ expresie 
          | ID MINEQ expresie 
          | ID MULEQ expresie
          | ID DIVEQ expresie
          ; 



%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 



void openFileWrite(FILE* fd,char * fileName)
{
      fd=fopen(fileName,"w");
}


void scrieVariabileFisier()
{
      var_fisier_ptr=fopen(fisier_variabile,"a"); // dechidere fisier 
      for(int i=0;i<count_var;i++){
    
     fprintf(var_fisier_ptr,"%s %s %s %s %d %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
     
      }
      fclose(var_fisier_ptr);
}

bool cautaVariabila(char* nume, char* vizibilitate)
{
      for(int i=0;i<count_var;i++)
      {
            if ((strcmp(var[i].vizibilitate,vizibilitate)==0) && (strcmp(var[i].id,nume)==0 ))
            {
                  check_compile=0;
                  printf("EROARE: Variabila deja declarata\n");
                  return false;
                  
            }
            
      }
      return true;
}

void seteazaAtributeStruct(char* tip, char* id, char* valoare, int constante, int dimensiune)
{
      var[count_var].tip=(char*) malloc(strlen(tip));
      strcpy(var[count_var].tip,tip);

      var[count_var].id=(char*) malloc(strlen(id));
      strcpy(var[count_var].id,id);

      var[count_var].valoare=(char*) malloc(strlen(valoare));
      strcpy(var[count_var].valoare,valoare);

      var[count_var].constante=constante;
      var[count_var].dimensiune=dimensiune;
      
}