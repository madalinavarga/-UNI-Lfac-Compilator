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
      int nr_parametrii;
      char* id;
      struct parametru parametrii_functie[10];

}functii[100];
struct parametru aux[100];
int count_v=0,count_f=0,count_aux=0;
char fisier_variabile[]="symbol_table.txt";
char fisier_functii[]="symbol_table_functions.txt ";

int variabila_deja_declarata(char* nume,char* vizibilitate);
void declarare_fara_initializare(char* tip,char* nume, int este_const,char* vizibilitate);
void declarare_cu_initializare(char* tip,char* nume,int val,int este_const,char* vizibilitate);
void scrieVariabileFisier();
void scrieFunctiiInFisier();
int get_valoare_dupa_nume(char * nume);
void set_parametrii_functie(char* tip, char* id,struct parametru *aux);
int functie_deja_declarata(char * tip,char* id,struct parametru *param);
void creaza_functie(char* tip, char* id,struct parametru *aux);

char *citeste_fisier(char *file);
%}

%union
{
    double num;
    char* str;
    int integer;
    float real;
    int boolean;
}

%token PRINT CONST DACA ALTFEL PENTRU CAT_TIMP MAIN RETURN EXIT CLASS 
%token GEQ EQ LEQ NEQ ASSIGN OR AND 
%token PLUS MINUS PROD DIV LESS GREATER INCR DECR 
//%token<boolean> BOOLEAN
%token<str> CHAR STRING  
%token<real>NR_REAL
%token<integer>NR_INT
%token<str> ID TIP
%type<integer> expresie


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
s: declaratii_globale functii_clase  main_prog {printf("1   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
 | declaratii_globale main_prog {printf("2   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
 | functii_clase main_prog {printf("3   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
 | main_prog {printf("4   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
 | declaratii_globale {printf("5   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
 ;
     
/*sectiunea 1*/
declaratii_globale : 
             declaratie_globala ';' { var[count_v-1].vizibilitate=strdup("global");}
	   | declaratii_globale declaratie_globala ';' { var[count_v-1].vizibilitate=strdup("global");}
	   ;
 declaratie_globala:variabila_initializata_global
            | variabila_declarata_global
            | array 
            | print
            ;          
declaratie_locala  : variabila_initializata_local
            | variabila_declarata_local
            | array 
            | print
            ;
variabila_initializata_local: CONST TIP ID ASSIGN expresie {declarare_cu_initializare($2,$3,$5,1,"local");}
                      | TIP ID ASSIGN expresie {declarare_cu_initializare($1,$2,$4,0,"local");}
                      ;
variabila_declarata_local: TIP ID {declarare_fara_initializare($1,$2,0,"local");}
                   ;
variabila_initializata_global: CONST TIP ID ASSIGN expresie {declarare_cu_initializare($2,$3,$5,1,"global");}
                      | TIP ID ASSIGN expresie {declarare_cu_initializare($1,$2,$4,0,"global");}
                      ;
variabila_declarata_global: TIP ID {declarare_fara_initializare($1,$2,0,"global");}
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
         | ID {$$=get_valoare_dupa_nume($1);} 
         | NR_INT {$$ = $1;} 
         //| ID '[' NR_INT ']'
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
        | CHAR
        ;
print:  PRINT '(' STRING ',' expresie ')' {printf("%s %d\n",$3,$5);}
     |  PRINT '(' STRING ')' {printf("%s\n",$3);}
     ;

/* sectiunea 2 */
functii_clase : functii_clase clase_declaratie
                | functii_declaratie 
                | clase_declaratie
                | functii_clase functii_declaratie
              ;

clase_declaratie : CLASS ID  '{' cod_bloc '}' ';'
      ;

functii_declaratie : TIP ID '(' lista_param ')' '{' cod_functii '}' { if(functie_deja_declarata($1,$2,aux)==0){ creaza_functie($1,$2,aux);} else {printf("else creez functie\n");count_aux=0; } }
                   | TIP ID '(' ')' '{' cod_functii '}' { }
                   ;
cod_functii : declaratie_locala ';' {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); var[count_v-1].vizibilitate=strdup(count_str);}
            | interogari
            ;

lista_param : param
            | lista_param ','  param 
            ;
param: TIP ID { set_parametrii_functie($1,$2,aux);}
     ;

/*sectiunea 3 */
main_prog :
           MAIN '('  ')' acolade
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
   | declaratie_locala ';' {var[count_v-1].vizibilitate=strdup("local");}
   | statement ';'
   | asignare ';'
   | functii_declaratie 
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



int variabila_deja_declarata(char* nume,char* vizibilitate){
        
        for (int i = 0; i < count_v; i++)
        {
                if (strcmp(var[i].id, nume) == 0 && strcmp(var[i].vizibilitate, vizibilitate) == 0 ) 
                { //printf("%lf\n",var[i].valoare);
                return i;
                }
        }
        return -1;
}

void declarare_fara_initializare(char* tip,char* nume, int este_const,char* vizibilitate){
        if(variabila_deja_declarata(nume,vizibilitate)!=-1){
                char error_msg[250];
                sprintf(error_msg, "Variabila %s este deja declarata", nume);
                yyerror(error_msg);
                //exit(0);
        }
        if(este_const==1){
                char error_msg[250];
                sprintf(error_msg, "Variabila constanta %s nu poate fi declarata fara initializare", nume);
                yyerror(error_msg);
                exit(0);
        }
        var[count_v].tip=strdup(tip);
        var[count_v].id=strdup(nume);
        var[count_v].constante=0;
        count_v++;
}
void declarare_cu_initializare(char* tip,char* nume,int val,int este_const,char* vizibilitate){
        //verificare daca exista 
        

        if(variabila_deja_declarata(nume,vizibilitate)!=-1){
                char error_msg[250];
                sprintf(error_msg, "Variabila %s este deja declarata", nume);
                yyerror(error_msg);
                exit(0);
        }
        //seteaza valorile si incrementeaza
        var[count_v].tip=strdup(tip);
        var[count_v].id=strdup(nume);
        char valoare[50];
        snprintf(valoare,50,"%d",val);
        var[count_v].valoare=strdup(valoare);
        var[count_v].constante=este_const;
        count_v++;
      
}

int get_valoare_dupa_nume(char * nume)
{ 
       // printf("Nume cautat: %s\n",nume);
        int gasit=0;
         for (int i = 0; i < count_v; i++)
         {
                 //printf("variabile: %s %s\n",var[i].id,var[i].tip);
                 if(strcmp(var[i].id,nume)==0 && strcmp(var[i].tip,"Integer")==0){
                 gasit++;
                // printf("return:%s\n",var[i].valoare);
                 int valoare=atoi(var[i].valoare);
                 return valoare;
                 }
         }

         if(gasit==0) 
         {
                char error_msg[250];
                sprintf(error_msg, "Variabila nu exista");
                yyerror(error_msg);
                exit(0);
         }

}
void creaza_functie(char* tip, char* id,struct parametru *aux)
{
        functii[count_f].nr_parametrii=count_aux;
        functii[count_f].tip_return=(char*)malloc(strlen(tip));
        strcpy(functii[count_f].tip_return,tip);
        functii[count_f].id=(char*)malloc(strlen(id));
        strcpy(functii[count_f].id,id);
        for(int i =0;i<count_aux;i++)
        {
                functii[count_f].parametrii_functie[i].id=strdup(aux[i].id);
                functii[count_f].parametrii_functie[i].tip=strdup(aux[i].tip);
        }
        count_f++;
        count_aux=0;

}

void set_parametrii_functie(char* tip, char* id,struct parametru *aux)
{
       
        aux[count_aux].id=(char*)malloc(strlen(id));
        strcpy(aux[count_aux].id,id);
        aux[count_aux].tip=(char*)malloc(strlen(tip));
        strcpy(aux[count_aux].tip,tip);
        count_aux++;    
}


void scrieVariabileFisier()
{
      FILE* var_fisier_ptr;
      var_fisier_ptr=fopen(fisier_variabile,"w+"); // dechidere fisier 
      fprintf(var_fisier_ptr,"tip  id  valoare  vizibilitate  este_const  dimensiune\n");
      fprintf(var_fisier_ptr,"---------------------------------------------------------\n");
      for(int i=0;i<count_v;i++){
    
       fprintf(var_fisier_ptr,"%s  %s  %s  %s  %d  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
       //modificari nr spatii => modifica si in get valoare dupa nume
     
      }
      fclose(var_fisier_ptr);
}

int functie_deja_declarata(char * tip,char* id,struct parametru *param)
{       
        int size_param=count_aux;
        int gasit=0;
       

        for(int i=0;i<count_f;i++)
        {
               
                if(strcmp(functii[i].tip_return,tip)==0 && strcmp(functii[i].id,id)==0){
                        //verific nr parametrii egal 
                        if(functii[i].nr_parametrii!=size_param)
                        return 0;

                        //verific parametrii
                        for(int j=0;j<functii[i].nr_parametrii;j++) //pentru fiecare parametru 
                           if(strcmp(param[j].id,functii[i].parametrii_functie[j].id)==0) gasit++;
                           
                      
                }
        }
        if(gasit==count_aux) return 1;
        return 0;

}



void scrieFunctiiInFisier()
{
        //id,tip,parametri,variabile
        FILE* functii_fisier_ptr;
        functii_fisier_ptr=fopen(fisier_functii,"w+");
        fprintf(functii_fisier_ptr,"tip  id parametrii \n");
        fprintf(functii_fisier_ptr,"---------------------------------------------------------\n");
        for(int i=0;i<count_f;i++)
          fprintf(functii_fisier_ptr,"%s %s %d\n",functii[i].tip_return,functii[i].id,functii[i].nr_parametrii);



        fclose(functii_fisier_ptr);

}