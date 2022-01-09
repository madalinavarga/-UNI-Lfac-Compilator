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
      double valoare;
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
bool cautaNume(char* nume, char* vizibilitate);
void declarare_cu_initializare(char* tip,char* nume,double val,int este_const);
void declarare_fara_initializare(char* tip,char* nume, int este_const);

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
%type<real_val> expresie variabila

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
declaratii_globale : declaratie ';'              {var[count_var].vizibilitate=strdup("global");printf("Apel aici ");if(cautaNume(var[count_var].id,"global")==true){printf("global bloc eroare\n");}else count_var++;}
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
variabila_initializata: CONST TIP ID ASSIGN variabila { declarare_cu_initializare($2,$3,$5,1);}
                      | TIP ID ASSIGN expresie //{if(cautaNume($3,var[count_var].vizibilitate)==true){declarare_cu_initializare($2,$3,$5,1);} else{ exit(0);}}
                      | TIP ID ASSIGN apel_functie
                      ;
expresie : variabila
         | variabila PLUS expresie  {$$ = $1 + $3;}            
         | variabila MINUS expresie {$$ = $1 - $3;}          
         | variabila PROD expresie  {$$ = $1 * $3;}           
         | variabila DIV expresie   {$$ = $1 / $3;}
         ;
variabila   : NR_REAL 
            | ID 
            | NR_INT 
            | BOOLEAN 
            
            ;

variabila_string :  CHAR 
                 |  STRING 
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
        | '{' bloc_cod '}'     
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
    | declaratie ';'  {var[count_var].vizibilitate=strdup("local");if(cautaNume(var[count_var].id,"local")==true){printf("main bloc eroare\n");}else count_var++;}
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
    
     fprintf(var_fisier_ptr,"%s %s %f %s %d %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
     
      }
      fclose(var_fisier_ptr);
}

bool cautaNume(char* nume, char* vizibilitate)
{
      printf("%s %s",nume,vizibilitate);
      for(int i=0;i<count_var;i++)
      {
            if ((strcmp(var[i].vizibilitate,vizibilitate)==0) && (strcmp(var[i].id,nume)==0 ))
            {
                  check_compile=0;
                  printf("EROARE: Variabila deja declarata\n");
                  return true;
                  
            }
            
      }
      return false;
}

void declarare_fara_initializare(char* tip,char* nume, int este_const){
        
        if(este_const==1){
                char error_msg[250];
                sprintf(error_msg, "Variabila constanta %s nu poate fi declarata fara initializare", nume);
                yyerror(error_msg);
                exit(0);
        }
        var[count_var].tip=strdup(tip);
        var[count_var].id=strdup(nume);
        var[count_var].constante=0;
        count_var++;
}

void declarare_cu_initializare(char* tip,char* nume,double val,int este_const){

     
        var[count_var].tip=strdup(tip);
        var[count_var].id=strdup(nume);
        var[count_var].valoare=val;
        var[count_var].constante=este_const;
        // count_var++;
       
}


int variabila_deja_declarata(char* nume){
        for (int i = 0; i < count_var; i++)
        {
                if (strcmp(var[i].id, nume) == 0) return i;
                printf("%lf\n",var[i].valoare);
        }
        return -1;
}