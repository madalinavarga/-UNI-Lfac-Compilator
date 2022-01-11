/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "tema2.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern FILE* yyin;
extern char* yytext;
extern int yylineno;

//STRUCTURA ARBORE
enum enum_tip {OP,IDENTIFIER,NUMBER,OTHER} ;
struct ast_node{
        
        char* valoare;
        struct ast_node* stanga; 
        struct ast_node* dreapta; 
        enum enum_tip tip;
};

//STRUCTURA VARIABILE + FUNCTII + OBIECTE
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

struct clase{
        char tip[20];
        int nr_variabile;
        struct variabile class_var[10];
}clase[100];

struct obiecte{
        char* tip_clasa;
        char* id;
        char* vizibilitate;
}obiecte[100];

//DECLARATII FUNCTII + VARIABILE GLOBALE  UTILIZATE
int nr_obiecte=0;
int nr_clase=0;
char empty[]=" ";
struct parametru aux[100],empty_struct[1]={" "," "};
int count_v=0,count_f=0,count_aux=0;
char fisier_variabile[]="symbol_table.txt";
char fisier_functii[]="symbol_table_functions.txt ";


struct ast_node *buildAST(char* val_nod,struct ast_node *stanga, struct ast_node *dreapta,int tip );
int evalAST(struct ast_node *ast);


int variabila_deja_declarata(char* nume,char* vizibilitate);
void declarare_fara_initializare(char* tip,char* nume, int este_const,char* vizibilitate);
void declarare_cu_initializare(char* tip,char* nume,int val,int este_const,char* vizibilitate);
void scrieVariabileFisier();
void scrieFunctiiInFisier();
int get_valoare_dupa_nume(char * nume);
void set_parametrii_functie(char* tip, char* id,struct parametru *aux);
int functie_deja_declarata(char * tip,char* id,struct parametru *param);
void mesaj_functie_existenta(char msg[]);
void creaza_functie(char* tip, char* id,struct parametru *aux);
void asignare_exista_variabila(char* id , char* viziblitate, char* valoare ,int nr_tip);
void creeaza_clasa(char* tip);
void error_decl(char* nume);
int variabila_class_deja_declarata(char* nume, char* vizibilitate);
void declarare_variabila_class(char* tip, char* nume,char* vizibilitate);
int clasa_deja_definita(char* nume);
void error_decl_clasa(char* nume);
int obiect_deja_definit(char* nume);
int obiect_deja_definit(char* nume);
void error_ne_decl_clasa(char* nume);
void obiect_nou(char* clasa,char* nume, char* vizibilitate);
int membru_clasa(int index_clasa,char* nume);
void error_ne_decl_membru(char* nume);
void asignare_pt_data_membru(char* clasa,char* membru,char* valoare,char* tip_valoare);
void print_variabile(char* mesaj ,char* nume);
void verifica_conditia(int nr1, int nr_conditie, int nr2);
void declarare_cu_initializare_diferit_int(char* tip, char* nume, char* valoare, int este_const, char* vizibilitate);
void declarare_cu_initializare_data_membru(char* tip, char* nume ,char* clasa, char* membru,int este_const, char* vizibilitate);
int verificare_exista_variabila(char* nume);
void asignare_cu_data_membru(char* nume, char* clasa, char* membru);
void error_ne_decl_variabila(char* nume);
void error_nepotrivire();
char *citeste_fisier(char *file);

#line 174 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PRINT = 258,
    CONST = 259,
    DACA = 260,
    ALTFEL = 261,
    PENTRU = 262,
    CAT_TIMP = 263,
    MAIN = 264,
    RETURN = 265,
    EXIT = 266,
    CLASS = 267,
    GEQ = 268,
    EQ = 269,
    LEQ = 270,
    NEQ = 271,
    ASSIGN = 272,
    OR = 273,
    AND = 274,
    PLUS = 275,
    MINUS = 276,
    PROD = 277,
    DIV = 278,
    LESS = 279,
    GREATER = 280,
    INCR = 281,
    DECR = 282,
    BOOLEAN = 283,
    CHAR = 284,
    STRING = 285,
    NR_REAL = 286,
    NR_INT = 287,
    ID = 288,
    TIP = 289
  };
#endif
/* Tokens.  */
#define PRINT 258
#define CONST 259
#define DACA 260
#define ALTFEL 261
#define PENTRU 262
#define CAT_TIMP 263
#define MAIN 264
#define RETURN 265
#define EXIT 266
#define CLASS 267
#define GEQ 268
#define EQ 269
#define LEQ 270
#define NEQ 271
#define ASSIGN 272
#define OR 273
#define AND 274
#define PLUS 275
#define MINUS 276
#define PROD 277
#define DIV 278
#define LESS 279
#define GREATER 280
#define INCR 281
#define DECR 282
#define BOOLEAN 283
#define CHAR 284
#define STRING 285
#define NR_REAL 286
#define NR_INT 287
#define ID 288
#define TIP 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 106 "tema2.y"

    double num;
    char* str;
    int integer;
    float real;
    char* boolean;

    struct expresie{
        struct ast_node *AST;
}expresie;

#line 306 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   350

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  242

#define YYUNDEFTOK  2
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,     2,
      38,    39,     2,     2,    35,     2,    37,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   152,   152,   153,   154,   155,   156,   160,   161,   163,
     164,   165,   166,   168,   169,   170,   172,   173,   174,   175,
     176,   177,   178,   179,   181,   182,   184,   185,   187,   188,
     195,   196,   197,   198,   199,   200,   201,   203,   204,   206,
     207,   209,   210,   212,   213,   214,   215,   218,   219,   220,
     222,   223,   224,   225,   229,   230,   231,   232,   235,   244,
     245,   247,   256,   257,   259,   260,   262,   263,   264,   265,
     266,   269,   270,   272,   274,   275,   276,   277,   283,   286,
     287,   290,   291,   294,   295,   296,   297,   298,   299,   300,
     311,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     338,   340,   341,   342,   345,   346,   349,   350,   351,   352,
     353,   354,   355,   357,   358,   360,   362,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "CONST", "DACA", "ALTFEL",
  "PENTRU", "CAT_TIMP", "MAIN", "RETURN", "EXIT", "CLASS", "GEQ", "EQ",
  "LEQ", "NEQ", "ASSIGN", "OR", "AND", "PLUS", "MINUS", "PROD", "DIV",
  "LESS", "GREATER", "INCR", "DECR", "BOOLEAN", "CHAR", "STRING",
  "NR_REAL", "NR_INT", "ID", "TIP", "','", "';'", "'.'", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "'&'", "$accept", "s", "declaratii_globale",
  "declaratie_globala", "declaratie_locala",
  "variabila_initializata_local", "variabila_declarata_local",
  "variabila_initializata_global", "variabila_declarata_global",
  "expresie", "array", "dimensiune", "lista_valori", "valoare", "print",
  "asignare_globala", "functii_clase", "class_definitie",
  "class_declaratii", "class_declaratie", "functii_declaratie",
  "cod_functii", "cod_f", "lista_param", "param", "asignare_functie",
  "main_prog", "acolade", "cod_bloc", "cod", "clasa_noua", "asignare_main",
  "statement", "interogari", "conditie", "bucle", "functie_while",
  "functie_for", "for_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    44,    59,    46,    40,    41,
      91,    93,   123,   125,    38
};
# endif

#define YYPACT_NINF (-205)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-16)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,   -35,    15,    27,    38,    64,    67,   105,    65,    72,
    -205,  -205,  -205,  -205,  -205,    50,  -205,  -205,  -205,    80,
      83,    74,    87,   260,    -2,  -205,    86,    50,  -205,  -205,
      98,  -205,  -205,  -205,   -19,   129,   108,   119,  -205,  -205,
    -205,  -205,  -205,   107,   212,   107,   -17,    31,   123,  -205,
    -205,   140,   153,  -205,   107,    21,  -205,   156,    48,  -205,
     115,   107,   107,   107,   107,   212,   163,   168,   109,  -205,
     176,   210,   189,   203,   151,   212,   208,   207,   213,   214,
     217,   220,    97,   223,  -205,   224,  -205,  -205,  -205,  -205,
    -205,    53,  -205,   225,   226,   227,  -205,  -205,  -205,  -205,
     235,   243,  -205,  -205,   170,   170,  -205,  -205,  -205,   236,
     251,   242,  -205,   244,   205,   218,  -205,   254,   107,   261,
     107,  -205,  -205,   270,  -205,  -205,  -205,   262,    77,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,   279,   264,   268,
     269,   215,  -205,  -205,  -205,  -205,  -205,   236,   152,  -205,
    -205,   289,   252,   281,    14,   271,   282,   288,  -205,  -205,
    -205,   222,   212,   302,   284,   280,    -6,  -205,  -205,  -205,
     221,  -205,  -205,  -205,  -205,   -16,  -205,   293,   107,   107,
     107,   107,   107,   107,   286,   107,   287,   290,   297,   250,
    -205,  -205,   296,   212,   298,   299,   300,   180,  -205,   152,
    -205,  -205,  -205,   301,   212,   212,   212,   212,   212,   212,
     212,    99,   303,    99,    99,  -205,  -205,  -205,  -205,   212,
     304,  -205,  -205,  -205,  -205,  -205,   307,    85,    94,   161,
     172,  -205,  -205,   335,   187,  -205,  -205,  -205,   305,    99,
     204,  -205
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       9,    10,    29,    11,    12,     0,    56,    55,     5,     0,
       0,     0,     0,     0,    28,     1,     0,     0,     3,     7,
       0,    54,    57,     4,     0,     0,     0,     0,    53,    52,
      51,    36,    35,     0,    50,     0,     0,     0,    37,     8,
       2,     0,     0,    48,     0,     0,    78,     0,     0,    59,
       0,     0,     0,     0,     0,    27,     0,     0,     0,    71,
       0,     0,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,    13,    14,    25,    15,
      88,     0,    82,     0,     0,     0,    83,    84,   114,   113,
       0,     0,    60,    34,    30,    31,    32,    33,    73,     0,
       0,     0,    39,     0,     0,     0,    47,     0,     0,     0,
       0,   102,   103,     0,   100,   101,    90,     0,    24,    85,
      80,    81,    89,    87,    86,    61,    58,     0,     0,     0,
      69,     0,    65,    67,    70,    68,    72,     0,     0,    40,
      49,     0,   112,     0,     0,     0,     0,     0,    94,    93,
      92,    35,    91,     0,     0,     0,    24,    66,    63,    64,
       0,    46,    45,    44,    43,     0,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    21,    35,    20,     0,     0,     0,     0,    62,     0,
      38,    18,    17,    35,    16,   109,   110,   108,   111,   106,
     107,     0,     0,     0,     0,    99,    98,    97,    95,    96,
       0,    77,    76,    75,    74,    41,     0,     0,     0,     0,
       0,    23,    19,   104,     0,   117,   116,   115,     0,     0,
       0,   105
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -205,  -205,   334,  -104,  -205,  -205,  -205,  -205,   -22,
      45,  -205,  -205,   144,     0,  -205,   336,    -9,  -205,   291,
      70,   198,  -137,  -205,   238,  -205,    68,  -205,  -204,   -78,
    -205,   231,   118,   -97,  -118,   -95,  -205,  -205,  -205
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    85,    86,    87,    10,    11,   152,
      88,    48,   175,   176,    89,    14,    15,    16,    58,    59,
      90,   141,   142,    68,    69,   143,    18,    56,    91,    92,
      93,    94,    95,    96,   153,    97,    98,    99,   156
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    44,   157,    19,   169,   139,    31,   227,    13,   229,
     230,   164,   144,   131,   145,    45,    52,    66,    31,   199,
      53,    60,    67,    65,     1,    76,    77,   200,    78,    79,
      74,   123,    75,   169,    47,   240,    46,   139,    47,   104,
     105,   106,   107,   139,   144,    12,   145,    80,    81,    20,
     144,   127,   145,    12,    82,    83,     1,    76,    77,     3,
      78,    79,     4,    70,    84,    21,   139,   212,     1,     2,
      17,    22,    71,   144,     3,   145,    28,     4,    17,    80,
      81,    23,    57,    33,    30,    32,    82,    83,     1,    76,
      77,   101,    78,    79,   164,    50,   130,    32,     5,     6,
      24,   162,     1,    76,    77,    25,    78,    79,    29,   140,
      34,    80,    81,    36,   123,    46,    35,    47,    82,    83,
      80,    81,    49,   124,   125,    80,    81,   234,   233,    37,
     126,    51,    82,    83,   127,    61,    62,    63,    64,    41,
      42,   140,   193,   197,   110,    43,    54,   140,   111,   131,
      55,   131,   131,    57,   103,   204,   205,   206,   207,   208,
     209,   210,   131,    72,     1,    76,    77,   219,    78,    79,
     140,    61,    62,    63,    64,     1,    76,    77,    46,    78,
      79,   171,   172,   173,   174,    41,    42,    80,    81,   100,
     116,    43,    63,    64,    82,    83,   108,    73,    80,    81,
      61,    62,    63,    64,   236,    82,    83,     1,    76,    77,
     109,    78,    79,   124,   125,   237,   224,   112,     1,    76,
      77,   114,    78,    79,     1,    76,    77,   113,    78,    79,
      80,    81,    61,    62,    63,    64,   115,    82,    83,     1,
      76,    77,   117,    78,    79,   118,   149,   241,   137,   138,
     121,   119,   120,   122,   137,   138,   128,   150,   168,   188,
     129,   132,   133,   134,   198,   178,   179,   180,   181,   137,
     138,   135,    61,    62,    63,    64,   182,   183,   216,   136,
     217,   218,    41,    42,   147,    66,   148,   151,    43,    38,
      39,    40,    41,    42,   154,   163,   165,   166,    43,   158,
     159,   160,    41,   161,   167,   -15,   177,   185,    43,   194,
     195,   196,    41,    42,   190,   191,    41,   192,    43,   189,
     184,   186,    43,   201,   202,    41,   203,   187,   211,   213,
     215,    43,   214,   220,   221,   222,   223,   231,   226,   228,
     232,   238,    26,   225,    27,   170,   235,   239,   146,   102,
     155
};

static const yytype_uint8 yycheck[] =
{
       0,    23,   120,    38,   141,   109,    15,   211,     8,   213,
     214,    17,   109,    91,   109,    17,    35,    34,    27,    35,
      39,    43,    39,    45,     3,     4,     5,    43,     7,     8,
      52,    17,    54,   170,    40,   239,    38,   141,    40,    61,
      62,    63,    64,   147,   141,     0,   141,    26,    27,    34,
     147,    37,   147,     8,    33,    34,     3,     4,     5,     9,
       7,     8,    12,    32,    43,    38,   170,   185,     3,     4,
       0,    33,    41,   170,     9,   170,     8,    12,     8,    26,
      27,    17,    34,    15,    34,    15,    33,    34,     3,     4,
       5,    43,     7,     8,    17,    27,    43,    27,    33,    34,
      33,   123,     3,     4,     5,     0,     7,     8,    36,   109,
      30,    26,    27,    39,    17,    38,    33,    40,    33,    34,
      26,    27,    36,    26,    27,    26,    27,    33,    43,    42,
      33,    33,    33,    34,    37,    20,    21,    22,    23,    32,
      33,   141,   164,   165,    35,    38,    17,   147,    39,   227,
      42,   229,   230,    34,    39,   177,   178,   179,   180,   181,
     182,   183,   240,    40,     3,     4,     5,   189,     7,     8,
     170,    20,    21,    22,    23,     3,     4,     5,    38,     7,
       8,    29,    30,    31,    32,    32,    33,    26,    27,    33,
      39,    38,    22,    23,    33,    34,    33,    44,    26,    27,
      20,    21,    22,    23,    43,    33,    34,     3,     4,     5,
      42,     7,     8,    26,    27,    43,    36,    41,     3,     4,
       5,    32,     7,     8,     3,     4,     5,    17,     7,     8,
      26,    27,    20,    21,    22,    23,    33,    33,    34,     3,
       4,     5,    34,     7,     8,    38,    41,    43,    33,    34,
      33,    38,    38,    33,    33,    34,    33,    39,    43,    37,
      36,    36,    36,    36,    43,    13,    14,    15,    16,    33,
      34,    36,    20,    21,    22,    23,    24,    25,    28,    36,
      30,    31,    32,    33,    42,    34,    42,    33,    38,    29,
      30,    31,    32,    33,    33,    33,    17,    33,    38,    29,
      30,    31,    32,    33,    36,    36,    17,    36,    38,    29,
      30,    31,    32,    33,    30,    31,    32,    33,    38,    17,
      39,    39,    38,    30,    31,    32,    33,    39,    42,    42,
      33,    38,    42,    37,    36,    36,    36,    33,    37,    36,
      33,     6,     8,   199,     8,   147,   228,    42,   110,    58,
     119
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     9,    12,    33,    34,    46,    47,    48,
      52,    53,    55,    59,    60,    61,    62,    65,    71,    38,
      34,    38,    33,    17,    33,     0,    48,    61,    71,    36,
      34,    62,    65,    71,    30,    33,    39,    42,    29,    30,
      31,    32,    33,    38,    54,    17,    38,    40,    56,    36,
      71,    33,    35,    39,    17,    42,    72,    34,    63,    64,
      54,    20,    21,    22,    23,    54,    34,    39,    68,    69,
      32,    41,    40,    44,    54,    54,     4,     5,     7,     8,
      26,    27,    33,    34,    43,    49,    50,    51,    55,    59,
      65,    73,    74,    75,    76,    77,    78,    80,    81,    82,
      33,    43,    64,    39,    54,    54,    54,    54,    33,    42,
      35,    39,    41,    17,    32,    33,    39,    34,    38,    38,
      38,    33,    33,    17,    26,    27,    33,    37,    33,    36,
      43,    74,    36,    36,    36,    36,    36,    33,    34,    49,
      59,    66,    67,    70,    78,    80,    69,    42,    42,    41,
      39,    33,    54,    79,    33,    76,    83,    79,    29,    30,
      31,    33,    54,    33,    17,    17,    33,    36,    43,    67,
      66,    29,    30,    31,    32,    57,    58,    17,    13,    14,
      15,    16,    24,    25,    39,    36,    39,    39,    37,    17,
      30,    31,    33,    54,    29,    30,    31,    54,    43,    35,
      43,    30,    31,    33,    54,    54,    54,    54,    54,    54,
      54,    42,    79,    42,    42,    33,    28,    30,    31,    54,
      37,    36,    36,    36,    36,    58,    37,    73,    36,    73,
      73,    33,    33,    43,    33,    77,    43,    43,     6,    42,
      73,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    47,    47,    48,
      48,    48,    48,    49,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      60,    60,    60,    60,    61,    61,    61,    61,    62,    63,
      63,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    68,    68,    69,    70,    70,    70,    70,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    79,    79,    79,    79,
      79,    79,    79,    80,    80,    81,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     7,
       4,     4,     4,     6,     2,     1,     5,     4,     2,     1,
       3,     3,     3,     3,     3,     1,     1,     3,     8,     3,
       4,     3,     1,     1,     1,     1,     1,     6,     4,     7,
       3,     3,     3,     3,     2,     1,     1,     2,     6,     1,
       2,     3,     8,     7,     2,     1,     2,     1,     1,     1,
       1,     1,     3,     2,     4,     4,     4,     4,     4,     2,
       3,     2,     1,     1,     1,     2,     2,     2,     1,     2,
       2,     3,     3,     3,     3,     5,     5,     5,     5,     5,
       2,     2,     2,     2,     7,    11,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     7,     7,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 152 "tema2.y"
                                               {printf("Program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1670 "y.tab.c"
    break;

  case 3:
#line 153 "tema2.y"
                                {printf("Program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1676 "y.tab.c"
    break;

  case 4:
#line 154 "tema2.y"
                           {printf("Program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1682 "y.tab.c"
    break;

  case 5:
#line 155 "tema2.y"
             {printf("Program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1688 "y.tab.c"
    break;

  case 6:
#line 156 "tema2.y"
                      {printf("Program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1694 "y.tab.c"
    break;

  case 7:
#line 160 "tema2.y"
                                             { var[count_v-1].vizibilitate=strdup("global");}
#line 1700 "y.tab.c"
    break;

  case 8:
#line 161 "tema2.y"
                                                               { var[count_v-1].vizibilitate=strdup("global");}
#line 1706 "y.tab.c"
    break;

  case 16:
#line 172 "tema2.y"
                                                           {if(strcmp((yyvsp[-3].str),"Integer")==0){declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),evalAST((yyvsp[0].expresie).AST),1,"main");}else{error_nepotrivire();}}
#line 1712 "y.tab.c"
    break;

  case 17:
#line 173 "tema2.y"
                                                          {char valoare[50]; sprintf(valoare,"%7.2f", (yyvsp[0].real)); if(strcmp((yyvsp[-3].str),"Float")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),valoare,1,"main");}else{error_nepotrivire();}}
#line 1718 "y.tab.c"
    break;

  case 18:
#line 174 "tema2.y"
                                                         {if(strcmp((yyvsp[-3].str),"String")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].str),1,"main");}else{error_nepotrivire();}}
#line 1724 "y.tab.c"
    break;

  case 19:
#line 175 "tema2.y"
                                                            {declarare_cu_initializare_data_membru((yyvsp[-5].str),(yyvsp[-4].str), (yyvsp[-2].str),(yyvsp[0].str),1,"main");}
#line 1730 "y.tab.c"
    break;

  case 20:
#line 176 "tema2.y"
                                                     {if(strcmp((yyvsp[-3].str),"Integer")==0){declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),evalAST((yyvsp[0].expresie).AST),0,"main");} else{error_nepotrivire();}}
#line 1736 "y.tab.c"
    break;

  case 21:
#line 177 "tema2.y"
                                                    {char valoare[50]; sprintf(valoare,"%7.2f", (yyvsp[0].real)); if(strcmp((yyvsp[-3].str),"Float")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),valoare,0,"main");}else{error_nepotrivire();}}
#line 1742 "y.tab.c"
    break;

  case 22:
#line 178 "tema2.y"
                                                   {printf("aici\n"); if(strcmp((yyvsp[-3].str),"String")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].str),0,"main");}else{error_nepotrivire();}}
#line 1748 "y.tab.c"
    break;

  case 23:
#line 179 "tema2.y"
                                                      {declarare_cu_initializare_data_membru((yyvsp[-5].str),(yyvsp[-4].str), (yyvsp[-2].str),(yyvsp[0].str),0,"main");}
#line 1754 "y.tab.c"
    break;

  case 24:
#line 181 "tema2.y"
                                  {declarare_fara_initializare((yyvsp[-1].str),(yyvsp[0].str),0,"main");}
#line 1760 "y.tab.c"
    break;

  case 26:
#line 184 "tema2.y"
                                                            {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),evalAST((yyvsp[0].expresie).AST),1,"global");}
#line 1766 "y.tab.c"
    break;

  case 27:
#line 185 "tema2.y"
                                                      {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),evalAST((yyvsp[0].expresie).AST),0,"global");}
#line 1772 "y.tab.c"
    break;

  case 28:
#line 187 "tema2.y"
                                   {declarare_fara_initializare((yyvsp[-1].str),(yyvsp[0].str),0,"global");}
#line 1778 "y.tab.c"
    break;

  case 30:
#line 195 "tema2.y"
                                                 {(yyval.expresie).AST = buildAST("+", (yyvsp[-2].expresie).AST, (yyvsp[0].expresie).AST, OP); }
#line 1784 "y.tab.c"
    break;

  case 31:
#line 196 "tema2.y"
                                                 {(yyval.expresie).AST = buildAST("-", (yyvsp[-2].expresie).AST, (yyvsp[0].expresie).AST, OP) ;}
#line 1790 "y.tab.c"
    break;

  case 32:
#line 197 "tema2.y"
                                                 {(yyval.expresie).AST = buildAST("*", (yyvsp[-2].expresie).AST, (yyvsp[0].expresie).AST, OP) ;}
#line 1796 "y.tab.c"
    break;

  case 33:
#line 198 "tema2.y"
                                                 {(yyval.expresie).AST = buildAST("/", (yyvsp[-2].expresie).AST, (yyvsp[0].expresie).AST, OP) ;}
#line 1802 "y.tab.c"
    break;

  case 34:
#line 199 "tema2.y"
                                                 {char str_val[50]; snprintf(str_val,50,"%d",evalAST((yyvsp[-1].expresie).AST)); (yyval.expresie).AST = buildAST(str_val, NULL, NULL, NUMBER);}
#line 1808 "y.tab.c"
    break;

  case 35:
#line 200 "tema2.y"
                                                 {(yyval.expresie).AST = buildAST((yyvsp[0].str), NULL, NULL, IDENTIFIER);}
#line 1814 "y.tab.c"
    break;

  case 36:
#line 201 "tema2.y"
                                                 {char str_val[50]; snprintf(str_val,50,"%d",(yyvsp[0].integer)); (yyval.expresie).AST = buildAST(str_val, NULL, NULL, NUMBER);}
#line 1820 "y.tab.c"
    break;

  case 47:
#line 218 "tema2.y"
                                            {printf("%s %d\n",(yyvsp[-3].str),evalAST((yyvsp[-1].expresie).AST));}
#line 1826 "y.tab.c"
    break;

  case 48:
#line 219 "tema2.y"
                              {printf("%s\n",(yyvsp[-1].str));}
#line 1832 "y.tab.c"
    break;

  case 49:
#line 220 "tema2.y"
                                        {print_variabile((yyvsp[-4].str),(yyvsp[-1].str));}
#line 1838 "y.tab.c"
    break;

  case 50:
#line 222 "tema2.y"
                                        {char count_str[]="global"; char str_valoare[50]; snprintf(str_valoare,50,"%d",evalAST((yyvsp[0].expresie).AST)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,0);}
#line 1844 "y.tab.c"
    break;

  case 51:
#line 223 "tema2.y"
                                      {char count_str[]="global"; char str_valoare[50]; snprintf(str_valoare,50,"%f",(yyvsp[0].real)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,1);}
#line 1850 "y.tab.c"
    break;

  case 52:
#line 224 "tema2.y"
                                       {char count_str[]="global"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),2);}
#line 1856 "y.tab.c"
    break;

  case 53:
#line 225 "tema2.y"
                                      {char count_str[]="global"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),3);}
#line 1862 "y.tab.c"
    break;

  case 58:
#line 235 "tema2.y"
                                                         {if(clasa_deja_definita((yyvsp[-4].str))==-1){
                                                                creeaza_clasa((yyvsp[-4].str));
                                                                }
                                                        else{
                                                               error_decl_clasa((yyvsp[-4].str)); 
                                                        }
                                                }
#line 1874 "y.tab.c"
    break;

  case 61:
#line 247 "tema2.y"
                             { if(variabila_class_deja_declarata((yyvsp[-1].str),"class")==-1){
                                   declarare_variabila_class((yyvsp[-2].str),(yyvsp[-1].str),"class");   
                                }
                                else{
                                        error_decl((yyvsp[-1].str));
                                }
                        }
#line 1886 "y.tab.c"
    break;

  case 62:
#line 256 "tema2.y"
                                                                    { if(functie_deja_declarata((yyvsp[-7].str),(yyvsp[-6].str),aux)==0){ creaza_functie((yyvsp[-7].str),(yyvsp[-6].str),aux);} else {count_aux=0;mesaj_functie_existenta((yyvsp[-6].str)); } }
#line 1892 "y.tab.c"
    break;

  case 63:
#line 257 "tema2.y"
                                                        {if(functie_deja_declarata((yyvsp[-6].str),(yyvsp[-5].str),empty_struct)==0){ creaza_functie((yyvsp[-6].str),(yyvsp[-5].str),empty_struct);} else {count_aux=0;mesaj_functie_existenta((yyvsp[-5].str)); } }
#line 1898 "y.tab.c"
    break;

  case 66:
#line 262 "tema2.y"
                                    {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); var[count_v-1].vizibilitate=strdup(count_str);}
#line 1904 "y.tab.c"
    break;

  case 73:
#line 272 "tema2.y"
              { set_parametrii_functie((yyvsp[-1].str),(yyvsp[0].str),aux);}
#line 1910 "y.tab.c"
    break;

  case 74:
#line 274 "tema2.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); char str_valoare[50]; snprintf(str_valoare,50,"%d",evalAST((yyvsp[-1].expresie).AST)); asignare_exista_variabila((yyvsp[-3].str),count_str,str_valoare,0);}
#line 1916 "y.tab.c"
    break;

  case 75:
#line 275 "tema2.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); char str_valoare[50]; snprintf(str_valoare,50,"%f",(yyvsp[-1].real)); asignare_exista_variabila((yyvsp[-3].str),count_str,str_valoare,1);}
#line 1922 "y.tab.c"
    break;

  case 76:
#line 276 "tema2.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); asignare_exista_variabila((yyvsp[-3].str),count_str,(yyvsp[-1].str),2);}
#line 1928 "y.tab.c"
    break;

  case 77:
#line 277 "tema2.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); asignare_exista_variabila((yyvsp[-3].str),count_str,(yyvsp[-1].str),3);}
#line 1934 "y.tab.c"
    break;

  case 85:
#line 296 "tema2.y"
                           {var[count_v-1].vizibilitate=strdup("main");}
#line 1940 "y.tab.c"
    break;

  case 90:
#line 311 "tema2.y"
                   { if(clasa_deja_definita((yyvsp[-1].str))!=-1){
                                if(obiect_deja_definit((yyvsp[0].str))==-1){
                                        obiect_nou((yyvsp[-1].str),(yyvsp[0].str),"main");
                                }
                                else{
                                        error_decl((yyvsp[0].str));
                                }
                                
                        }
                        else{
                               error_ne_decl_clasa((yyvsp[-1].str)); 
                        }

                }
#line 1959 "y.tab.c"
    break;

  case 91:
#line 327 "tema2.y"
                                       {printf("id:%s expresie: %d\n",(yyvsp[-2].str),evalAST((yyvsp[0].expresie).AST)); char count_str[]="main"; char str_valoare[50]; snprintf(str_valoare,50,"%d",evalAST((yyvsp[0].expresie).AST)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,0);}
#line 1965 "y.tab.c"
    break;

  case 92:
#line 328 "tema2.y"
                                      {char count_str[]="main"; char str_valoare[50]; snprintf(str_valoare,50,"%f",(yyvsp[0].real)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,1);}
#line 1971 "y.tab.c"
    break;

  case 93:
#line 329 "tema2.y"
                                      {char count_str[]="main"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),2);}
#line 1977 "y.tab.c"
    break;

  case 94:
#line 330 "tema2.y"
                                      {char count_str[]="main"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),3);}
#line 1983 "y.tab.c"
    break;

  case 95:
#line 331 "tema2.y"
                                           {char valoare[50];  snprintf(valoare,50,"%7.2f",(yyvsp[0].real));  asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),valoare,"Float");}
#line 1989 "y.tab.c"
    break;

  case 96:
#line 332 "tema2.y"
                                            {char valoare[50]; sprintf(valoare,"%d",evalAST((yyvsp[0].expresie).AST));  asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),valoare,"Integer");}
#line 1995 "y.tab.c"
    break;

  case 97:
#line 333 "tema2.y"
                                          { asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str),"String");}
#line 2001 "y.tab.c"
    break;

  case 98:
#line 334 "tema2.y"
                                           {asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].boolean),"Bool");}
#line 2007 "y.tab.c"
    break;

  case 99:
#line 335 "tema2.y"
                                      {asignare_cu_data_membru((yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str));}
#line 2013 "y.tab.c"
    break;

  case 100:
#line 338 "tema2.y"
                   {int verificare=verificare_exista_variabila((yyvsp[-1].str)); if(verificare==-1){error_ne_decl_variabila((yyvsp[-1].str));}}
#line 2019 "y.tab.c"
    break;

  case 101:
#line 340 "tema2.y"
                   {int verificare=verificare_exista_variabila((yyvsp[-1].str)); if(verificare==-1){error_ne_decl_variabila((yyvsp[-1].str));}}
#line 2025 "y.tab.c"
    break;

  case 102:
#line 341 "tema2.y"
                   {int verificare=verificare_exista_variabila((yyvsp[0].str)); if(verificare==-1){error_ne_decl_variabila((yyvsp[0].str));}}
#line 2031 "y.tab.c"
    break;

  case 103:
#line 342 "tema2.y"
                   {int verificare=verificare_exista_variabila((yyvsp[0].str)); if(verificare==-1){error_ne_decl_variabila((yyvsp[0].str));}}
#line 2037 "y.tab.c"
    break;

  case 106:
#line 349 "tema2.y"
                                  {verifica_conditia(evalAST((yyvsp[-2].expresie).AST),1,evalAST((yyvsp[0].expresie).AST));}
#line 2043 "y.tab.c"
    break;

  case 107:
#line 350 "tema2.y"
                                     {verifica_conditia(evalAST((yyvsp[-2].expresie).AST),2,evalAST((yyvsp[0].expresie).AST));}
#line 2049 "y.tab.c"
    break;

  case 108:
#line 351 "tema2.y"
                                 {verifica_conditia(evalAST((yyvsp[-2].expresie).AST),3,evalAST((yyvsp[0].expresie).AST));}
#line 2055 "y.tab.c"
    break;

  case 109:
#line 352 "tema2.y"
                                  {verifica_conditia(evalAST((yyvsp[-2].expresie).AST),4,evalAST((yyvsp[0].expresie).AST));}
#line 2061 "y.tab.c"
    break;

  case 110:
#line 353 "tema2.y"
                                  {verifica_conditia(evalAST((yyvsp[-2].expresie).AST),5,evalAST((yyvsp[0].expresie).AST));}
#line 2067 "y.tab.c"
    break;

  case 111:
#line 354 "tema2.y"
                                  {verifica_conditia(evalAST((yyvsp[-2].expresie).AST),6,evalAST((yyvsp[0].expresie).AST));}
#line 2073 "y.tab.c"
    break;

  case 112:
#line 355 "tema2.y"
                                  {verifica_conditia(0,7,0);}
#line 2079 "y.tab.c"
    break;


#line 2083 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 367 "tema2.y"

int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 



int variabila_deja_declarata(char* nume,char* vizibilitate){
        //cautare in structura nume + vizibilitate 
        for (int i = 0; i < count_v; i++)
        {
                if (strcmp(var[i].id, nume) == 0 && strcmp(var[i].vizibilitate, vizibilitate) == 0 ) 
                { 
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
                exit(0);
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
        var[count_v].vizibilitate=strdup(vizibilitate);
        count_v++;
}
void declarare_cu_initializare(char* tip,char* nume,int val,int este_const,char* vizibilitate){
        //verifica existenta variabilei in struct 
        if(variabila_deja_declarata(nume,vizibilitate)!=-1){
                char error_msg[250];
                sprintf(error_msg, "Variabila %s este deja declarata", nume);
                yyerror(error_msg);
                exit(0);
        }
        //Negativ: seteaza valorile si incrementeaza
        var[count_v].tip=strdup(tip);
        var[count_v].id=strdup(nume);
        char valoare[50];
        snprintf(valoare,50,"%d",val);
        var[count_v].valoare=strdup(valoare);
        var[count_v].constante=este_const;
        var[count_v].vizibilitate=strdup(vizibilitate);
        count_v++;
      
}

int get_valoare_dupa_nume(char * nume)
{ 
      
        int gasit=0;
        for (int i = 0; i < count_v; i++)
         {
                //doar pentru Integer , expresie poate lua doar acest tip 
                 if(strcmp(var[i].id,nume)==0 && strcmp(var[i].tip,"Integer")==0){
                 gasit++;
                 int valoare=atoi(var[i].valoare);
                 return valoare;
                 }
                 else{ // gasesc variabila dar este alt tip 
                         if(strcmp(var[i].id,nume)==0 && strcmp(var[i].tip,"Integer")!=0){
                                char error_msg[250];
                                sprintf(error_msg, "Expresie poate fi doar Integer");
                                yyerror(error_msg);
                                exit(0);
                         }
                 }
         }

         if(gasit==0) 
         {
                char error_msg[250];
                sprintf(error_msg, "Variabila %s nu exista", nume);
                yyerror(error_msg);
                exit(0);
         }

}
void print_variabile(char* mesaj ,char* nume) 
{
        
        char* ptr=nume;
        int gasit=0;
        
        for (int i = 0; i < count_v; i++)
         {
                 
                 if(strcmp(var[i].id,nume)==0){
                         gasit++;
                         printf("%s: %s\n",mesaj,var[i].valoare);
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
{     // pentru ca nu exista functia, iau valorile din structura aux si le adg in struct functii 
        functii[count_f].nr_parametrii=count_aux;
        functii[count_f].tip_return=strdup(tip);
        functii[count_f].id=strdup(id);
        for(int i =0;i<count_aux;i++)
        {
                functii[count_f].parametrii_functie[i].id=strdup(aux[i].id);
                functii[count_f].parametrii_functie[i].tip=strdup(aux[i].tip);
        }
        count_f++;
        count_aux=0;

}
void asignare_exista_variabila(char* id , char* viziblitate ,char* valoare, int nr_tip)
{
        //verificari 
        int index=verificare_exista_variabila(id);
        if(index==-1){
                error_ne_decl_variabila(id);
        }
        else{
                if(var[index].constante==1){
                        char error_msg[250];
                        sprintf(error_msg, "Variabila %s este const", id);
                        yyerror(error_msg);
                        exit(0);
                }
        for (int i = 0; i < count_v; i++){
                if(strcmp(var[i].id,id)==0){ // acelasi nume
                       
                  if(strcmp(var[i].vizibilitate,"global")==0) var[i].valoare=strdup(valoare); //global => pot folosi oriunde 
                  else
                   if(strcmp(var[i].vizibilitate,viziblitate)==0) 
                   {
                           if(nr_tip==0 && strcmp(var[i].tip,"Integer")==0) { // int , expresie deja verificat
                            var[i].valoare=strdup(valoare);
                           }else
                           if(nr_tip==1 && strcmp(var[i].tip,"Float")==0)
                           {
                                   var[i].valoare=strdup(valoare);
                                   
                           }else
                           if(nr_tip==2 && strcmp(var[i].tip,"String")==0){
                                   var[i].valoare=strdup(valoare);
                           }else
                           if(nr_tip==3 && strcmp(var[i].tip,"Char")==0)
                           {
                                   var[i].valoare=strdup(valoare);
                           }else
                           {
                                
                                char error_msg[250];
                                sprintf(error_msg, "Nepotrivire tipuri");
                                yyerror(error_msg);
                                exit(0);
                           }
                   }
                }
                   
        }
        }

       
}

void set_parametrii_functie(char* tip, char* id,struct parametru *aux)
{
       
        aux[count_aux].id=(char*)malloc(strlen(id));
        strcpy(aux[count_aux].id,id);
        aux[count_aux].tip=(char*)malloc(strlen(tip));
        strcpy(aux[count_aux].tip,tip);
        count_aux++;    
}


int functie_deja_declarata(char * tip,char* id,struct parametru *param)
{       
        
        int size_param=count_aux;
        int gasit=-1;
       

        for(int i=0;i<count_f;i++)
        {
               //overloading 
               //nume + tip identic => parametrii diferiti

                if(strcmp(functii[i].tip_return,tip)==0 && strcmp(functii[i].id,id)==0){
                        //verific nr parametrii egal => nu
                        if(functii[i].nr_parametrii==size_param)
                        return 1;
                        } 
                else  
                   if(strcmp(functii[i].id,id)==0){  // nume identic dar parametrii diferiti ok 
                        //verific nr parametrii egal 
                        if(functii[i].nr_parametrii!=size_param)
                          return 0;
                        else // nr parametrii egali => nume diferit la cel putin 1
                           for(int j=0;j<functii[i].nr_parametrii;j++) //pentru fiecare parametru 
                                if(strcmp(param[j].id,functii[i].parametrii_functie[j].id)==0) gasit++;
                   }
                                      
                
        }
     
        if(gasit==count_aux) return 1;
        return 0;

}

void mesaj_functie_existenta(char msg[]){
     char error_msg[250];
     sprintf(error_msg, "functia %s este deja declarata", msg);
     yyerror(error_msg);
     exit(0);
}

void verifica_conditia(int nr1, int nr_conditie, int nr2)
{
       int variabila=0;
        switch (nr_conditie) {
        case 1:
            if(nr1<nr2) {printf("Conditie indeplinita\n"); variabila++;}
            else printf("Conditie neindeplinita\n");
            break;
        case 2:
            if(nr1>nr2) printf("Conditie indeplinita\n");
            else printf("Conditie neindeplinita\n");
            break;
        case 3:
            if(nr1<=nr2) printf("Conditie indeplinita\n");
            else printf("Conditie neindeplinita\n");
            break;
        case 4:
            if(nr1>=nr2) printf("Conditie indeplinita\n");
            else printf("Conditie neindeplinita\n");
            break;
        case 5:
            if(nr1==nr2) printf("Conditie indeplinita\n");
            else printf("Conditie neindeplinita\n");
            break;
        case 6:
            if(nr1!=nr2) printf("Conditie indeplinita\n");
            else printf("Conditie neindeplinita\n");
            break;
        case 7:
            printf("Bucla Infinita\n");
            break;
        default:
              printf("Nu cunosc conditia\n");
                exit(0);
        }
}


void creeaza_clasa(char* tip){
        strcpy(clase[nr_clase].tip,tip);
        clase[nr_clase].nr_variabile=0;
        nr_clase++;
}

void error_decl(char* nume){
        char error_msg[250];
        sprintf(error_msg, "Variabila %s este deja declarata", nume);
        yyerror(error_msg); 
        exit(0);
       
        
}

void error_decl_clasa(char* nume){
        char error_msg[250];
        sprintf(error_msg, "Clasa %s este deja declarata", nume);
        yyerror(error_msg); 
        exit(0);
}

void error_ne_decl_clasa(char* nume){
        char error_msg[250];
        sprintf(error_msg, "Clasa %s nu a fost definita", nume);
        yyerror(error_msg);
        exit(0);
}

void error_ne_decl_membru(char* nume){
        char error_msg[250];
        sprintf(error_msg, "Membrul %s nu a fost definit", nume);
        yyerror(error_msg);
        exit(0);
}

void error_ne_decl_variabila(char* nume){
        char error_msg[250];
        sprintf(error_msg, "Variabila %s nu a fost declarata", nume);
        yyerror(error_msg);
        exit(0);
}

void error_nepotrivire(){
        char error_msg[250];
        sprintf(error_msg, "Nepotrivire tipuri");
        yyerror(error_msg);
        exit(0);
}

int variabila_class_deja_declarata(char* nume,char* vizibilitate){
        for(int i=0;i<clase[nr_clase-1].nr_variabile;i++){
                if(strcmp(nume, clase[nr_clase-1].class_var[i].id)==0)
                        return i;
        }
        return -1;
}

void declarare_variabila_class(char* tip, char* nume,char* vizibilitate){
        //clase[nr_clase].nr_variabile++;
        clase[nr_clase].class_var[clase[nr_clase].nr_variabile].tip=strdup(tip);
        clase[nr_clase].class_var[clase[nr_clase].nr_variabile].id=strdup(nume);
        char buf[20];
        sprintf(buf,"%s-%d",vizibilitate,nr_clase);
        declarare_fara_initializare(tip,nume, 0, buf);
        clase[nr_clase].nr_variabile++;
        //printf("pentru clasa cu indexul: %d am ajuns la nr: %d\n",nr_clase,clase[nr_clase].nr_variabile);
}

int clasa_deja_definita(char* nume){
        for(int i=0;i<nr_clase;i++){
                if(strcmp(clase[i].tip,nume)==0){
                        return i;
                }
        }
        return -1;
}

int obiect_deja_definit(char* nume){
        for(int i=0;i<nr_obiecte;i++){
                if(strcmp(obiecte[i].id,nume)==0){
                        return i;
                }
        }
        return -1;
}

void obiect_nou(char* clasa,char* nume, char* vizibilitate){
        obiecte[nr_obiecte].id=strdup(nume);
        obiecte[nr_obiecte].tip_clasa=strdup(clasa);
        obiecte[nr_obiecte].vizibilitate=strdup(vizibilitate);
        declarare_fara_initializare(clasa,nume,0,vizibilitate);
        nr_obiecte++;
}

int membru_clasa(int index_clasa, char* nume){
        //printf("index clasa in care caut: %d, nr variabile: %d\n",index_clasa,clase[index_clasa].nr_variabile);
        for(int i=0;i<10;i++){
                if(strcmp(clase[index_clasa].class_var[i].id,nume)==0){
                        return i;
                }
        }
        return -1;
}

void asignare_pt_data_membru(char* clasa,char* membru,char* valoare,char* tip_valoare){
        int index_clasa=obiect_deja_definit(clasa);
        
        if(index_clasa==-1){
                error_ne_decl_clasa(clasa); 
        }
        else{   
                int index_membru=membru_clasa(index_clasa,membru);
                if(index_membru==-1){
                        error_ne_decl_membru(membru);
                }
                else{
                        char id_variabila[20];
                        bzero(id_variabila,20);
                        strcat(id_variabila,obiecte[index_clasa].id);
                        strcat(id_variabila,".");
                        strcat(id_variabila,membru);
                        if(strcmp(clase[index_clasa].class_var[index_membru].tip,tip_valoare)==0){
                               if(strcmp(tip_valoare,"Integer")==0){
                                        int val=atoi(valoare);
                                        int index=variabila_deja_declarata(id_variabila,"main");
                                        if(index==-1){
                                                declarare_cu_initializare(tip_valoare,id_variabila,val,0,"main");
                                        }
                                        else{
                                                var[index].valoare=strdup(valoare);
                                                //clase[index_clasa].class_var[index_membru].valoare=strdup(valoare);
                                        }
                                }
                                else if(strcmp(tip_valoare,"Float")==0){
                                        //float val=atof(valoare);
                                        int index=variabila_deja_declarata(id_variabila,"main");
                                        if(index==-1){
                                                declarare_cu_initializare_diferit_int(tip_valoare,id_variabila,valoare,0,"main");
                                        }
                                        else{
                                               var[index].valoare=strdup(valoare);  
                                        }
                                }
                                else if(strcmp(tip_valoare,"String")==0){
                                        int index=variabila_deja_declarata(id_variabila,"main");
                                        if(index==-1){
                                                declarare_cu_initializare_diferit_int(tip_valoare,id_variabila,valoare,0,"main");
                                        }
                                        else{
                                               var[index].valoare=strdup(valoare);  
                                        }
                                }
                                else if(strcmp(tip_valoare,"Bool")==0){
                                        printf("am gasit bool\n");
                                        int index=variabila_deja_declarata(id_variabila,"main");
                                        if(index==-1){
                                                declarare_cu_initializare_diferit_int(tip_valoare,id_variabila,valoare,0,"main");
                                        }
                                        else{
                                               var[index].valoare=strdup(valoare);  
                                        }
                                }
                        }
                        else{
                                char error_msg[250];
                                sprintf(error_msg, "Nepotrivire tipuri");
                                yyerror(error_msg);
                                exit(0);
                        }
                }
        }
}

void declarare_cu_initializare_diferit_int(char* tip, char* nume, char* valoare, int este_const, char* vizibilitate){
        if(variabila_deja_declarata(nume,vizibilitate)!=-1){
                char error_msg[250];
                sprintf(error_msg, "Variabila %s este deja declarata", nume);
                yyerror(error_msg);
                exit(0);
        }
        //seteaza valorile si incrementeaza
        var[count_v].tip=strdup(tip);
        var[count_v].id=strdup(nume);
        var[count_v].valoare=strdup(valoare);
        var[count_v].constante=este_const;
        var[count_v].vizibilitate=strdup(vizibilitate);
        count_v++;
}

void declarare_cu_initializare_data_membru(char* tip, char* nume ,char* clasa, char* membru,int este_const, char* vizibilitate){
        char id_data_membru[20];
        bzero(id_data_membru,20);
        strcat(id_data_membru,clasa);
        strcat(id_data_membru,".");
        strcat(id_data_membru,membru);
        int index=verificare_exista_variabila(id_data_membru);
        if(index==-1){
                char error_msg[250];
                sprintf(error_msg, "Variabila %s nu este declarata", id_data_membru);
                yyerror(error_msg);
                exit(0);  
        }
        else{
                if(strcmp(tip,var[index].tip)==0){
                        declarare_cu_initializare_diferit_int(tip,nume,var[index].valoare,este_const,vizibilitate);
                }
                else{
                       char error_msg[250];
                        strcat(error_msg, "Nepotrivire tipuri");
                        yyerror(error_msg);
                        exit(0); 
                }
        }
}

int verificare_exista_variabila(char* nume){
        for (int i = 0; i < count_v; i++){
               if(strcmp(var[i].id,nume)==0)
               {
                      
                       return i;
               } 
        }
        return -1;
}

void asignare_cu_data_membru(char* nume, char* clasa, char* membru){
        char id_data_membru[20];
        bzero(id_data_membru,20);
        strcat(id_data_membru,clasa);
        strcat(id_data_membru,".");
        strcat(id_data_membru,membru);

        int index_variabila=verificare_exista_variabila(nume);
        if(index_variabila==-1){ 
                char error_msg[250];
                sprintf(error_msg, "Variabila %s nu este declarata", nume);
                yyerror(error_msg);
                exit(0);
        }
        else{
                int index_membru=verificare_exista_variabila(id_data_membru);
                if(index_membru==-1){
                       char error_msg[250];
                        sprintf(error_msg, "Variabila %s nu este declarata", nume);
                        yyerror(error_msg);
                        exit(0); 
                }
                else{
                        if(strcmp(var[index_membru].tip,var[index_variabila].tip)==0){
                               var[index_variabila].valoare=strdup(var[index_membru].valoare); 
                        }
                        else{
                               char error_msg[250];
                        strcat(error_msg, "Nepotrivire tipuri");
                        yyerror(error_msg);
                        exit(0);  
                        }
                }
        }
}

void scrieFunctiiInFisier()
{
        //id,tip,parametri,variabile
        FILE* functii_fisier_ptr;
        functii_fisier_ptr=fopen(fisier_functii,"w+");
        fprintf(functii_fisier_ptr,"tip | id nr_parametrii   |  parametrii \n");
        fprintf(functii_fisier_ptr,"---------------------------------------------------------\n");
        for(int i=0;i<count_f;i++) {
          // afisare tip, nume si nr parametrii
          fprintf(functii_fisier_ptr,"%s | %s | %d: ",functii[i].tip_return,functii[i].id,functii[i].nr_parametrii);

          // afisare parametrii functie
          for(int j=0; j<functii[i].nr_parametrii; j++) {
                  fprintf(functii_fisier_ptr, "%s %s ", functii[i].parametrii_functie[j].tip, functii[i].parametrii_functie[j].id);
          }

          fprintf(functii_fisier_ptr, "\n");
        }


        fclose(functii_fisier_ptr);

}
void scrieVariabileFisier()
{
      FILE* var_fisier_ptr;
      var_fisier_ptr=fopen(fisier_variabile,"w+"); // dechidere fisier 
      fprintf(var_fisier_ptr,"tip | id  |  valoare | vizibilitate | este_const | dimensiune\n");
      fprintf(var_fisier_ptr,"---------------------------------------------------------\n");
      fprintf(var_fisier_ptr,"\n\nGLOBAL:\n");
      for(int i=0;i<count_v;i++){
              if(strcmp(var[i].vizibilitate,"global")==0)
                fprintf(var_fisier_ptr,"%s  |  %s  |  %s  |  %s  |  %d  |  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              
      }
      fprintf(var_fisier_ptr,"\n\nMAIN:\n");
       for(int i=0;i<count_v;i++){
              if(strcmp(var[i].vizibilitate,"main")==0)
                fprintf(var_fisier_ptr,"%s  |  %s  |  %s  |  %s  |  %d  |  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              
      }

       fprintf(var_fisier_ptr,"\n\nFUNCTII:\n");
       for(int i=0;i<count_v;i++){
              if(strstr(var[i].vizibilitate,"functie"))
                fprintf(var_fisier_ptr,"%s  |  %s  |  %s  |  %s  |  %d  |  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              
      }

       fprintf(var_fisier_ptr,"\n\nCLASE:\n");
       for(int i=0;i<count_v;i++){
              if(strstr(var[i].vizibilitate,"clas"))
                fprintf(var_fisier_ptr,"%s  |  %s  |  %s  |  %s  |  %d  |  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              
      }


      fclose(var_fisier_ptr);
}

struct ast_node *buildAST(char* val_nod,struct ast_node *stanga, struct ast_node *dreapta,int tip )
{       //creez nod nou si il returnez
        struct ast_node *nodNou=(struct ast_node*)malloc(sizeof(struct ast_node));
        nodNou->stanga=stanga;
        nodNou->dreapta=dreapta;
        nodNou->valoare=strdup(val_nod);
        nodNou->tip=tip;
        return(nodNou);
}

int evalAST(struct ast_node *ast)
{
        

  if(ast != NULL ){
       if(ast->tip == NUMBER ) return atoi(ast->valoare);
       else 
       if(ast->tip == IDENTIFIER) return get_valoare_dupa_nume(ast->valoare);
       else{
             
                if(ast->tip == OP)
                {
                        if(strcmp(ast->valoare,"+")==0) return (evalAST(ast->stanga) + evalAST(ast->dreapta));
                        else
                        if(strcmp(ast->valoare,"-")==0) return (evalAST(ast->stanga) - evalAST(ast->dreapta));
                        else
                        if(strcmp(ast->valoare,"*")==0) return (evalAST(ast->stanga) * evalAST(ast->dreapta));
                        else
                        if(strcmp(ast->valoare,"/")==0) return (evalAST(ast->stanga) / evalAST(ast->dreapta));
                }
                else
                {
               // printf("ramura altceva \n");
                return 0;
                }
        }
  }

  return 0;
        
}
