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
#line 1 "tema.y"

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
      char** val2;
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

int nr_obiecte=0;
int nr_clase=0;
char empty[]=" ";
struct parametru aux[100],empty_struct[1]={" "," "};
struct parametru aux_apel[100];

int count_v=0,count_f=0,count_aux=0, count_aux_apel=0;
char fisier_variabile[]="symbol_table.txt";
char fisier_functii[]="symbol_table_functions.txt ";

int variabila_deja_declarata(char* nume,char* vizibilitate);
void declarare_fara_initializare(char* tip,char* nume, int este_const,char* vizibilitate);
void declarare_cu_initializare(char* tip,char* nume,int val,int este_const,char* vizibilitate);
void scrieVariabileFisier();
void scrieFunctiiInFisier();
int get_valoare_dupa_nume(char * nume);
void set_parametrii_functie(char* tip, char* id,struct parametru *aux);
int functie_deja_declarata(char* id,struct parametru *param);
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
void declara_vector(char* tip, char* nume, int dimensiune,char* vizibilitate);
void asignare_pt_element_vector(char* nume,int pozitie, char* valoare, char* tip_val);
void asignare_cu_element_vector(char* nume_var,char* nume_vector,int index_elem);
void set_parametrii_apel(char* tip, struct parametru* aux);
void error_ne_decl_functie(char* nume);
char* get_tip_dupa_nume(char* nume);
int functie_deja_declarata_pt_apel(char* id,struct parametru *param);
int get_valoare_vector_dupa_nume(char* nume,int index_elem);


char *citeste_fisier(char *file);

#line 170 "y.tab.c"

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
#line 102 "tema.y"

    double num;
    char* str;
    int integer;
    float real;
    char* boolean;

#line 298 "y.tab.c"

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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   391

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  259

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
       2,     2,     2,     2,     2,     2,     2,     2,    42,     2,
      38,    39,     2,     2,    35,     2,    37,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
       0,   140,   140,   141,   142,   143,   144,   149,   150,   152,
     153,   154,   155,   157,   158,   159,   162,   163,   164,   165,
     166,   167,   168,   169,   171,   172,   174,   175,   176,   177,
     178,   179,   181,   182,   189,   190,   191,   192,   193,   194,
     195,   196,   198,   201,   214,   215,   216,   218,   219,   220,
     221,   225,   226,   227,   228,   231,   240,   241,   243,   252,
     253,   255,   256,   258,   259,   260,   261,   262,   265,   266,
     268,   270,   271,   272,   273,   279,   281,   282,   284,   285,
     287,   288,   289,   290,   291,   292,   293,   294,   305,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   346,   347,   349,   350,   352,   353,   354,   355,   358,
     360,   361,   362,   365,   366,   369,   370,   371,   372,   373,
     374,   375,   377,   378,   380,   382,   384
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
  "'['", "']'", "'&'", "'{'", "'}'", "$accept", "s", "declaratii_globale",
  "declaratie_globala", "declaratie_locala",
  "variabila_initializata_local", "variabila_declarata_local",
  "variabila_initializata_global", "variabila_declarata_global",
  "expresie", "array_glob", "array_loc", "print", "asignare_globala",
  "functii_clase", "class_definitie", "class_declaratii",
  "class_declaratie", "functii_declaratie", "cod_functii", "cod_f",
  "lista_param", "param", "asignare_functie", "main_prog", "acolade",
  "cod_bloc", "cod", "clasa_noua", "asignare_main", "apel_functie",
  "lista_apel", "param_apel", "statement", "interogari", "conditie",
  "bucle", "functie_while", "functie_for", "for_list", YY_NULLPTR
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
      91,    93,    38,   123,   125
};
# endif

#define YYPACT_NINF (-208)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-16)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     113,   -32,    44,    52,    71,    75,    79,   123,   113,    88,
    -208,  -208,  -208,  -208,  -208,    -5,  -208,  -208,  -208,   115,
     103,   109,   108,   269,    33,  -208,   117,    -5,  -208,  -208,
     134,  -208,  -208,  -208,    20,   139,   126,   147,  -208,  -208,
    -208,  -208,   157,    97,   283,   170,   -16,   175,  -208,  -208,
     145,   255,  -208,   293,    49,  -208,   171,    55,  -208,   181,
     173,    97,    97,    97,    97,  -208,  -208,   283,   182,   179,
      99,  -208,   191,   200,   223,  -208,  -208,   283,   180,   199,
     204,   210,   220,   226,   214,   228,  -208,   227,  -208,  -208,
    -208,  -208,  -208,    61,  -208,   235,   236,   237,   245,  -208,
    -208,  -208,  -208,   250,   253,  -208,   251,  -208,     3,     3,
    -208,  -208,  -208,    28,   257,   270,  -208,   256,  -208,   261,
      97,   263,    97,  -208,  -208,   279,  -208,  -208,  -208,   281,
     297,   284,    41,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,   298,   299,   314,   316,   216,  -208,  -208,
    -208,  -208,  -208,    28,  -208,   317,   254,   294,    91,   326,
     312,   329,  -208,  -208,  -208,    23,   283,   347,  -208,   -26,
    -208,   283,   143,  -208,   324,   307,   335,   289,     7,  -208,
    -208,  -208,   222,   311,    97,    97,    97,    97,    97,    97,
     327,    97,   330,   331,   336,   252,   315,   328,  -208,   354,
    -208,  -208,    66,   283,   334,   340,   341,   342,   121,  -208,
    -208,  -208,    81,   283,   283,   283,   283,   283,   283,   283,
     231,   343,   231,   231,  -208,  -208,  -208,  -208,   283,  -208,
     151,  -208,   325,   339,  -208,  -208,  -208,  -208,  -208,   348,
      93,    58,   106,   172,  -208,  -208,  -208,   283,  -208,  -208,
     374,   132,  -208,  -208,  -208,   344,   231,   184,  -208
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       9,    10,    33,    11,    12,     0,    53,    52,     5,     0,
       0,     0,     0,     0,    32,     1,     0,     0,     3,     7,
       0,    51,    54,     4,     0,     0,     0,     0,    50,    49,
      48,    40,    39,     0,    47,     0,     0,     0,     8,     2,
       0,     0,    45,     0,     0,    75,     0,     0,    56,     0,
       0,     0,     0,     0,     0,    31,    30,    29,     0,     0,
       0,    68,     0,     0,     0,    28,    27,    26,     0,     0,
       0,     0,     0,     0,     0,     0,    76,     0,    13,    14,
      25,    15,    86,     0,    79,     0,     0,     0,     0,    80,
      81,   123,   122,     0,     0,    57,     0,    38,    34,    35,
      36,    37,    70,     0,     0,     0,    42,     0,    44,     0,
       0,     0,     0,   111,   112,     0,   109,   110,    88,     0,
       0,     0,    24,    82,    77,    78,    87,    84,    85,    83,
      58,    55,    41,     0,     0,     0,    66,     0,    62,    64,
      67,    65,    69,     0,    46,     0,   121,     0,     0,     0,
       0,     0,    92,    91,    90,    39,    89,     0,   106,    39,
     101,   105,     0,   103,     0,     0,     0,     0,    24,    63,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   102,     0,
      22,    21,    39,    20,     0,     0,     0,     0,     0,    59,
      18,    17,    39,    16,   118,   119,   117,   120,   115,   116,
       0,     0,     0,     0,    97,    96,    95,    93,    94,   107,
       0,   104,     0,     0,    43,    74,    73,    72,    71,     0,
       0,     0,     0,     0,   108,   100,    99,    98,    23,    19,
     113,     0,   126,   125,   124,     0,     0,     0,   114
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -208,  -208,  -208,   375,  -110,  -208,  -208,  -208,  -208,   -23,
    -208,  -208,     2,  -208,   376,   -10,  -208,   332,    19,   229,
    -138,  -208,   271,  -208,    59,  -208,  -207,   -72,  -208,   265,
    -208,   192,   193,   150,  -105,  -121,  -102,  -208,  -208,  -208
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    87,    88,    89,    10,    11,   156,
      12,    90,    91,    14,    15,    16,    57,    58,    92,   147,
     148,    70,    71,   149,    18,    55,    93,    94,    95,    96,
      97,   172,   173,    98,    99,   157,   100,   101,   102,   160
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,   161,    13,   145,     3,    31,    19,     4,   150,   181,
      13,   151,   196,   240,    59,   242,   243,    31,    68,    17,
      60,   135,    67,    69,   175,    63,    64,    17,    74,    30,
      77,     1,    78,    79,    32,    80,    81,   145,   108,   109,
     110,   111,   150,   145,   181,   151,    32,   176,   150,   257,
      45,   151,     1,    78,    79,    51,    80,    81,   175,    52,
     194,   143,   144,    59,     1,    78,    79,    28,    80,    81,
     221,    46,   145,    47,    33,    82,    83,   150,    20,    46,
     151,   176,    84,    85,    82,    83,    49,    82,    83,    56,
      21,   251,    23,    86,    84,    85,     1,    78,    79,   104,
      80,    81,   166,   233,    22,   134,    59,   171,   125,     1,
      78,    79,    24,    80,    81,   146,     1,     2,   239,    82,
      83,    59,     3,    25,    29,     4,    84,    85,   129,    41,
      42,   131,    82,    83,   114,    43,    35,   250,   115,    84,
      85,    61,    62,    63,    64,    34,     5,     6,    36,   146,
     253,    37,   203,    48,   208,   146,    53,   238,   126,   127,
     213,   214,   215,   216,   217,   218,   219,    50,   135,    54,
     135,   135,   228,   171,   171,     1,    78,    79,   197,    80,
      81,    56,   198,    46,   146,   135,   197,     1,    78,    79,
     244,    80,    81,    61,    62,    63,    64,    59,    82,    83,
      65,    66,    41,    42,   103,    84,    85,    72,    43,   247,
      82,    83,   107,   106,   119,   112,   254,    84,    85,     1,
      78,    79,   113,    80,    81,     1,    78,    79,   258,    80,
      81,   125,   116,   117,     1,    78,    79,   120,    80,    81,
     126,   127,   121,    61,    62,    63,    64,   128,   122,   143,
     144,   129,   130,   123,   131,   143,   144,    82,    83,   124,
     180,   132,   118,   133,    84,    85,   209,   184,   185,   186,
     187,   136,   137,   138,    61,    62,    63,    64,   188,   189,
     225,   139,   226,   227,    41,    42,   140,    41,    42,   141,
      43,    68,   142,    43,   155,   154,   158,    73,    38,    39,
      40,    41,    42,    61,    62,    63,    64,    43,   162,   163,
     164,    41,   165,   153,   167,   177,   174,    43,   205,   206,
     207,    41,    42,    75,    76,    41,    42,    43,   168,    41,
     169,    43,   178,   190,   183,    43,   170,   200,   201,    41,
     202,   210,   211,    41,   212,    43,   168,    41,   169,    43,
     179,   192,   -15,    43,   229,   245,   246,    41,    42,   168,
      41,   169,   191,    43,   195,   199,    43,   204,   193,   224,
     220,   232,   248,   222,   223,   234,   235,   236,   237,   241,
     255,   249,   182,    26,    27,   152,   159,   256,   230,   105,
     231,   252
};

static const yytype_int16 yycheck[] =
{
      23,   122,     0,   113,     9,    15,    38,    12,   113,   147,
       8,   113,    38,   220,    40,   222,   223,    27,    34,     0,
      43,    93,    45,    39,    17,    22,    23,     8,    51,    34,
      53,     3,     4,     5,    15,     7,     8,   147,    61,    62,
      63,    64,   147,   153,   182,   147,    27,    40,   153,   256,
      17,   153,     3,     4,     5,    35,     7,     8,    17,    39,
      37,    33,    34,    40,     3,     4,     5,     8,     7,     8,
     191,    38,   182,    40,    15,    26,    27,   182,    34,    38,
     182,    40,    33,    34,    26,    27,    27,    26,    27,    34,
      38,    33,    17,    44,    33,    34,     3,     4,     5,    44,
       7,     8,   125,    37,    33,    44,    40,   130,    17,     3,
       4,     5,    33,     7,     8,   113,     3,     4,    37,    26,
      27,    40,     9,     0,    36,    12,    33,    34,    37,    32,
      33,    40,    26,    27,    35,    38,    33,    44,    39,    33,
      34,    20,    21,    22,    23,    30,    33,    34,    39,   147,
      44,    43,   175,    36,   177,   153,    17,    36,    26,    27,
     183,   184,   185,   186,   187,   188,   189,    33,   240,    43,
     242,   243,   195,   196,   197,     3,     4,     5,    35,     7,
       8,    34,    39,    38,   182,   257,    35,     3,     4,     5,
      39,     7,     8,    20,    21,    22,    23,    40,    26,    27,
      30,    31,    32,    33,    33,    33,    34,    32,    38,   232,
      26,    27,    39,    32,    34,    33,    44,    33,    34,     3,
       4,     5,    43,     7,     8,     3,     4,     5,    44,     7,
       8,    17,    41,    33,     3,     4,     5,    38,     7,     8,
      26,    27,    38,    20,    21,    22,    23,    33,    38,    33,
      34,    37,    38,    33,    40,    33,    34,    26,    27,    33,
      44,    33,    39,    36,    33,    34,    44,    13,    14,    15,
      16,    36,    36,    36,    20,    21,    22,    23,    24,    25,
      28,    36,    30,    31,    32,    33,    36,    32,    33,    36,
      38,    34,    41,    38,    33,    39,    33,    42,    29,    30,
      31,    32,    33,    20,    21,    22,    23,    38,    29,    30,
      31,    32,    33,    43,    33,    17,    32,    38,    29,    30,
      31,    32,    33,    30,    31,    32,    33,    38,    31,    32,
      33,    38,    33,    39,    17,    38,    39,    30,    31,    32,
      33,    30,    31,    32,    33,    38,    31,    32,    33,    38,
      36,    39,    36,    38,    39,    30,    31,    32,    33,    31,
      32,    33,    36,    38,    17,    41,    38,    32,    39,    33,
      43,    17,    33,    43,    43,    41,    36,    36,    36,    36,
       6,    33,   153,     8,     8,   114,   121,    43,   196,    57,
     197,   241
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     9,    12,    33,    34,    46,    47,    48,
      52,    53,    55,    57,    58,    59,    60,    63,    69,    38,
      34,    38,    33,    17,    33,     0,    48,    59,    69,    36,
      34,    60,    63,    69,    30,    33,    39,    43,    29,    30,
      31,    32,    33,    38,    54,    17,    38,    40,    36,    69,
      33,    35,    39,    17,    43,    70,    34,    61,    62,    40,
      54,    20,    21,    22,    23,    30,    31,    54,    34,    39,
      66,    67,    32,    42,    54,    30,    31,    54,     4,     5,
       7,     8,    26,    27,    33,    34,    44,    49,    50,    51,
      56,    57,    63,    71,    72,    73,    74,    75,    78,    79,
      81,    82,    83,    33,    44,    62,    32,    39,    54,    54,
      54,    54,    33,    43,    35,    39,    41,    33,    39,    34,
      38,    38,    38,    33,    33,    17,    26,    27,    33,    37,
      38,    40,    33,    36,    44,    72,    36,    36,    36,    36,
      36,    36,    41,    33,    34,    49,    57,    64,    65,    68,
      79,    81,    67,    43,    39,    33,    54,    80,    33,    74,
      84,    80,    29,    30,    31,    33,    54,    33,    31,    33,
      39,    54,    76,    77,    32,    17,    40,    17,    33,    36,
      44,    65,    64,    17,    13,    14,    15,    16,    24,    25,
      39,    36,    39,    39,    37,    17,    38,    35,    39,    41,
      30,    31,    33,    54,    32,    29,    30,    31,    54,    44,
      30,    31,    33,    54,    54,    54,    54,    54,    54,    54,
      43,    80,    43,    43,    33,    28,    30,    31,    54,    39,
      76,    77,    17,    37,    41,    36,    36,    36,    36,    37,
      71,    36,    71,    71,    39,    30,    31,    54,    33,    33,
      44,    33,    78,    44,    44,     6,    43,    71,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    47,    47,    48,
      48,    48,    48,    49,    49,    49,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    56,    57,    57,    57,    58,    58,    58,
      58,    59,    59,    59,    59,    60,    61,    61,    62,    63,
      63,    64,    64,    65,    65,    65,    65,    65,    66,    66,
      67,    68,    68,    68,    68,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    78,
      78,    78,    78,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    83,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     7,
       4,     4,     4,     6,     2,     1,     5,     5,     5,     4,
       4,     4,     2,     1,     3,     3,     3,     3,     3,     1,
       1,     4,     5,     5,     6,     4,     7,     3,     3,     3,
       3,     2,     1,     1,     2,     6,     1,     2,     3,     8,
       7,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       2,     4,     4,     4,     4,     4,     2,     3,     2,     1,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     3,
       3,     3,     3,     5,     5,     5,     5,     5,     6,     6,
       6,     3,     4,     1,     3,     1,     1,     3,     4,     2,
       2,     2,     2,     7,    11,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     7,     7,     5
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
#line 140 "tema.y"
                                               {printf("1   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1676 "y.tab.c"
    break;

  case 3:
#line 141 "tema.y"
                                {printf("2   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1682 "y.tab.c"
    break;

  case 4:
#line 142 "tema.y"
                           {printf("3   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1688 "y.tab.c"
    break;

  case 5:
#line 143 "tema.y"
             {printf("4   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1694 "y.tab.c"
    break;

  case 6:
#line 144 "tema.y"
                      {printf("5   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1700 "y.tab.c"
    break;

  case 7:
#line 149 "tema.y"
                                    { var[count_v-1].vizibilitate=strdup("global");}
#line 1706 "y.tab.c"
    break;

  case 8:
#line 150 "tema.y"
                                                       { var[count_v-1].vizibilitate=strdup("global");}
#line 1712 "y.tab.c"
    break;

  case 16:
#line 162 "tema.y"
                                                           {if(strcmp((yyvsp[-3].str),"Integer")==0){declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),1,"main");}else{error_nepotrivire();}}
#line 1718 "y.tab.c"
    break;

  case 17:
#line 163 "tema.y"
                                                    {char valoare[50]; sprintf(valoare,"%7.2f", (yyvsp[0].real)); if(strcmp((yyvsp[-3].str),"Float")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),valoare,1,"main");}else{error_nepotrivire();}}
#line 1724 "y.tab.c"
    break;

  case 18:
#line 164 "tema.y"
                                                   {if(strcmp((yyvsp[-3].str),"String")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].str),1,"main");}else{error_nepotrivire();}}
#line 1730 "y.tab.c"
    break;

  case 19:
#line 165 "tema.y"
                                                      {declarare_cu_initializare_data_membru((yyvsp[-5].str),(yyvsp[-4].str), (yyvsp[-2].str),(yyvsp[0].str),1,"main");}
#line 1736 "y.tab.c"
    break;

  case 20:
#line 166 "tema.y"
                                               {if(strcmp((yyvsp[-3].str),"Integer")==0){declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),0,"main");} else{error_nepotrivire();}}
#line 1742 "y.tab.c"
    break;

  case 21:
#line 167 "tema.y"
                                              {char valoare[50]; sprintf(valoare,"%7.2f", (yyvsp[0].real)); if(strcmp((yyvsp[-3].str),"Float")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),valoare,0,"main");}else{error_nepotrivire();}}
#line 1748 "y.tab.c"
    break;

  case 22:
#line 168 "tema.y"
                                             {if(strcmp((yyvsp[-3].str),"String")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].str),0,"main");}else{error_nepotrivire();}}
#line 1754 "y.tab.c"
    break;

  case 23:
#line 169 "tema.y"
                                                {declarare_cu_initializare_data_membru((yyvsp[-5].str),(yyvsp[-4].str), (yyvsp[-2].str),(yyvsp[0].str),0,"main");}
#line 1760 "y.tab.c"
    break;

  case 24:
#line 171 "tema.y"
                                  {declarare_fara_initializare((yyvsp[-1].str),(yyvsp[0].str),0,"main");}
#line 1766 "y.tab.c"
    break;

  case 26:
#line 174 "tema.y"
                                                            {if(strcmp((yyvsp[-3].str),"Integer")==0){declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),1,"global");}else{error_nepotrivire();}}
#line 1772 "y.tab.c"
    break;

  case 27:
#line 175 "tema.y"
                                                    {char valoare[50]; sprintf(valoare,"%7.2f", (yyvsp[0].real)); if(strcmp((yyvsp[-3].str),"Float")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),valoare,1,"global");}else{error_nepotrivire();}}
#line 1778 "y.tab.c"
    break;

  case 28:
#line 176 "tema.y"
                                                   {if(strcmp((yyvsp[-3].str),"String")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].str),1,"global");}else{error_nepotrivire();}}
#line 1784 "y.tab.c"
    break;

  case 29:
#line 177 "tema.y"
                                               {if(strcmp((yyvsp[-3].str),"Integer")==0){declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),0,"global");} else{error_nepotrivire();}}
#line 1790 "y.tab.c"
    break;

  case 30:
#line 178 "tema.y"
                                              {char valoare[50]; sprintf(valoare,"%7.2f", (yyvsp[0].real)); if(strcmp((yyvsp[-3].str),"Float")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),valoare,0,"global");}else{error_nepotrivire();}}
#line 1796 "y.tab.c"
    break;

  case 31:
#line 179 "tema.y"
                                             {if(strcmp((yyvsp[-3].str),"String")==0) { declarare_cu_initializare_diferit_int((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].str),0,"global");}else{error_nepotrivire();}}
#line 1802 "y.tab.c"
    break;

  case 32:
#line 181 "tema.y"
                                   {declarare_fara_initializare((yyvsp[-1].str),(yyvsp[0].str),0,"global");}
#line 1808 "y.tab.c"
    break;

  case 34:
#line 189 "tema.y"
                                   {(yyval.integer) = (yyvsp[-2].integer) + (yyvsp[0].integer);}
#line 1814 "y.tab.c"
    break;

  case 35:
#line 190 "tema.y"
                                   {(yyval.integer) = (yyvsp[-2].integer) - (yyvsp[0].integer);}
#line 1820 "y.tab.c"
    break;

  case 36:
#line 191 "tema.y"
                                  {(yyval.integer) = (yyvsp[-2].integer) * (yyvsp[0].integer);}
#line 1826 "y.tab.c"
    break;

  case 37:
#line 192 "tema.y"
                                 {(yyval.integer) = (yyvsp[-2].integer) / (yyvsp[0].integer);}
#line 1832 "y.tab.c"
    break;

  case 38:
#line 193 "tema.y"
                           {(yyval.integer) = (yyvsp[-1].integer);}
#line 1838 "y.tab.c"
    break;

  case 39:
#line 194 "tema.y"
              {(yyval.integer)=get_valoare_dupa_nume((yyvsp[0].str));}
#line 1844 "y.tab.c"
    break;

  case 40:
#line 195 "tema.y"
                  {(yyval.integer) = (yyvsp[0].integer);}
#line 1850 "y.tab.c"
    break;

  case 41:
#line 196 "tema.y"
                             {(yyval.integer)=get_valoare_vector_dupa_nume((yyvsp[-3].str),(yyvsp[-1].integer));}
#line 1856 "y.tab.c"
    break;

  case 42:
#line 198 "tema.y"
                                   {declara_vector((yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-1].integer),"global");}
#line 1862 "y.tab.c"
    break;

  case 43:
#line 201 "tema.y"
                                  {declara_vector((yyvsp[-4].str),(yyvsp[-3].str),(yyvsp[-1].integer),"main");}
#line 1868 "y.tab.c"
    break;

  case 44:
#line 214 "tema.y"
                                            {printf("%s %d\n",(yyvsp[-3].str),(yyvsp[-1].integer));}
#line 1874 "y.tab.c"
    break;

  case 45:
#line 215 "tema.y"
                              {printf("%s\n",(yyvsp[-1].str));}
#line 1880 "y.tab.c"
    break;

  case 46:
#line 216 "tema.y"
                                        {print_variabile((yyvsp[-4].str),(yyvsp[-1].str));}
#line 1886 "y.tab.c"
    break;

  case 47:
#line 218 "tema.y"
                                        {char count_str[]="global"; char str_valoare[50]; snprintf(str_valoare,50,"%d",(yyvsp[0].integer)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,0);}
#line 1892 "y.tab.c"
    break;

  case 48:
#line 219 "tema.y"
                                      {char count_str[]="global"; char str_valoare[50]; snprintf(str_valoare,50,"%f",(yyvsp[0].real)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,1);}
#line 1898 "y.tab.c"
    break;

  case 49:
#line 220 "tema.y"
                                       {char count_str[]="global"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),2);}
#line 1904 "y.tab.c"
    break;

  case 50:
#line 221 "tema.y"
                                      {char count_str[]="global"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),3);}
#line 1910 "y.tab.c"
    break;

  case 55:
#line 231 "tema.y"
                                                         {if(clasa_deja_definita((yyvsp[-4].str))==-1){
                                                                creeaza_clasa((yyvsp[-4].str));
                                                                }
                                                        else{
                                                               error_decl_clasa((yyvsp[-4].str)); 
                                                        }
                                                }
#line 1922 "y.tab.c"
    break;

  case 58:
#line 243 "tema.y"
                             { if(variabila_class_deja_declarata((yyvsp[-1].str),"class")==-1){
                                   declarare_variabila_class((yyvsp[-2].str),(yyvsp[-1].str),"class");   
                                }
                                else{
                                        error_decl((yyvsp[-1].str));
                                }
                        }
#line 1934 "y.tab.c"
    break;

  case 59:
#line 252 "tema.y"
                                                                    { if(functie_deja_declarata((yyvsp[-6].str),aux)==0){ creaza_functie((yyvsp[-7].str),(yyvsp[-6].str),aux);} else {count_aux=0;mesaj_functie_existenta((yyvsp[-6].str)); } }
#line 1940 "y.tab.c"
    break;

  case 60:
#line 253 "tema.y"
                                                        {if(functie_deja_declarata((yyvsp[-5].str),empty_struct)==0){ creaza_functie((yyvsp[-6].str),(yyvsp[-5].str),empty_struct);} else {count_aux=0;mesaj_functie_existenta((yyvsp[-5].str)); } }
#line 1946 "y.tab.c"
    break;

  case 63:
#line 258 "tema.y"
                              {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); var[count_v-1].vizibilitate=strdup(count_str);}
#line 1952 "y.tab.c"
    break;

  case 70:
#line 268 "tema.y"
              { set_parametrii_functie((yyvsp[-1].str),(yyvsp[0].str),aux);}
#line 1958 "y.tab.c"
    break;

  case 71:
#line 270 "tema.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); char str_valoare[50]; snprintf(str_valoare,50,"%d",(yyvsp[-1].integer)); asignare_exista_variabila((yyvsp[-3].str),count_str,str_valoare,0);}
#line 1964 "y.tab.c"
    break;

  case 72:
#line 271 "tema.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); char str_valoare[50]; snprintf(str_valoare,50,"%f",(yyvsp[-1].real)); asignare_exista_variabila((yyvsp[-3].str),count_str,str_valoare,1);}
#line 1970 "y.tab.c"
    break;

  case 73:
#line 272 "tema.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); asignare_exista_variabila((yyvsp[-3].str),count_str,(yyvsp[-1].str),2);}
#line 1976 "y.tab.c"
    break;

  case 74:
#line 273 "tema.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); asignare_exista_variabila((yyvsp[-3].str),count_str,(yyvsp[-1].str),3);}
#line 1982 "y.tab.c"
    break;

  case 82:
#line 289 "tema.y"
                           {var[count_v-1].vizibilitate=strdup("main");}
#line 1988 "y.tab.c"
    break;

  case 88:
#line 305 "tema.y"
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
#line 2007 "y.tab.c"
    break;

  case 89:
#line 321 "tema.y"
                                       {char count_str[]="main"; char str_valoare[50]; snprintf(str_valoare,50,"%d",(yyvsp[0].integer)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,0);}
#line 2013 "y.tab.c"
    break;

  case 90:
#line 322 "tema.y"
                                      {char count_str[]="main"; char str_valoare[50]; snprintf(str_valoare,50,"%f",(yyvsp[0].real)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,1);}
#line 2019 "y.tab.c"
    break;

  case 91:
#line 323 "tema.y"
                                      {char count_str[]="main"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),2);}
#line 2025 "y.tab.c"
    break;

  case 92:
#line 324 "tema.y"
                                      {char count_str[]="main"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),3);}
#line 2031 "y.tab.c"
    break;

  case 93:
#line 325 "tema.y"
                                           {char valoare[50];  snprintf(valoare,50,"%7.2f",(yyvsp[0].real));  asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),valoare,"Float");}
#line 2037 "y.tab.c"
    break;

  case 94:
#line 326 "tema.y"
                                            {char valoare[50]; sprintf(valoare,"%d",(yyvsp[0].integer));  asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),valoare,"Integer");}
#line 2043 "y.tab.c"
    break;

  case 95:
#line 327 "tema.y"
                                          { asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str),"String");}
#line 2049 "y.tab.c"
    break;

  case 96:
#line 328 "tema.y"
                                           {asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].boolean),"Bool");}
#line 2055 "y.tab.c"
    break;

  case 97:
#line 329 "tema.y"
                                      {asignare_cu_data_membru((yyvsp[-4].str),(yyvsp[-2].str),(yyvsp[0].str));}
#line 2061 "y.tab.c"
    break;

  case 98:
#line 330 "tema.y"
                                                    { char valoare[50]; sprintf(valoare,"%d",(yyvsp[0].integer)); asignare_pt_element_vector((yyvsp[-5].str),(yyvsp[-3].integer),valoare, "Integer");}
#line 2067 "y.tab.c"
    break;

  case 99:
#line 331 "tema.y"
                                                   {char valoare[50]; sprintf(valoare,"%7.2f",(yyvsp[0].real)); asignare_pt_element_vector((yyvsp[-5].str),(yyvsp[-3].integer),valoare, "Float");}
#line 2073 "y.tab.c"
    break;

  case 100:
#line 332 "tema.y"
                                                  { asignare_pt_element_vector((yyvsp[-5].str),(yyvsp[-3].integer),(yyvsp[0].str), "String");}
#line 2079 "y.tab.c"
    break;

  case 101:
#line 346 "tema.y"
                              {if(functie_deja_declarata_pt_apel((yyvsp[-2].str),empty_struct)==0){count_aux_apel=0; error_ne_decl_functie((yyvsp[-2].str));}else{count_aux_apel=0; }}
#line 2085 "y.tab.c"
    break;

  case 102:
#line 347 "tema.y"
                                    {int verific=functie_deja_declarata_pt_apel((yyvsp[-3].str),aux_apel); if(verific==0){count_aux_apel=0; error_ne_decl_functie((yyvsp[-3].str));}else{count_aux_apel=0; }}
#line 2091 "y.tab.c"
    break;

  case 105:
#line 352 "tema.y"
                      { set_parametrii_apel("Integer",aux_apel);}
#line 2097 "y.tab.c"
    break;

  case 106:
#line 353 "tema.y"
                     {set_parametrii_apel("Float",aux_apel);}
#line 2103 "y.tab.c"
    break;

  case 107:
#line 354 "tema.y"
                         {if(functie_deja_declarata((yyvsp[-2].str),empty_struct)==0){count_aux_apel=0; error_ne_decl_functie((yyvsp[-2].str));} else{count_aux_apel=0; char* tip_apel; tip_apel=strdup(get_tip_dupa_nume((yyvsp[-2].str)));  set_parametrii_apel(tip_apel,aux_apel);}}
#line 2109 "y.tab.c"
    break;

  case 108:
#line 355 "tema.y"
                                  {int verific=functie_deja_declarata_pt_apel((yyvsp[-3].str),aux_apel); if(verific==0){count_aux_apel=0; error_ne_decl_functie((yyvsp[-3].str));} else{count_aux_apel=0; char* tip_apel; tip_apel=strdup(get_tip_dupa_nume((yyvsp[-3].str)));  set_parametrii_apel(tip_apel,aux_apel);}}
#line 2115 "y.tab.c"
    break;

  case 109:
#line 358 "tema.y"
                   {int verificare=verificare_exista_variabila((yyvsp[-1].str)); if(verificare==-1){error_ne_decl_variabila((yyvsp[-1].str));}}
#line 2121 "y.tab.c"
    break;

  case 110:
#line 360 "tema.y"
                   {int verificare=verificare_exista_variabila((yyvsp[-1].str)); if(verificare==-1){error_ne_decl_variabila((yyvsp[-1].str));}}
#line 2127 "y.tab.c"
    break;

  case 111:
#line 361 "tema.y"
                   {int verificare=verificare_exista_variabila((yyvsp[0].str)); if(verificare==-1){error_ne_decl_variabila((yyvsp[0].str));}}
#line 2133 "y.tab.c"
    break;

  case 112:
#line 362 "tema.y"
                   {int verificare=verificare_exista_variabila((yyvsp[0].str)); if(verificare==-1){error_ne_decl_variabila((yyvsp[0].str));}}
#line 2139 "y.tab.c"
    break;

  case 115:
#line 369 "tema.y"
                                  {verifica_conditia((yyvsp[-2].integer),1,(yyvsp[0].integer));}
#line 2145 "y.tab.c"
    break;

  case 116:
#line 370 "tema.y"
                                     {verifica_conditia((yyvsp[-2].integer),2,(yyvsp[0].integer));}
#line 2151 "y.tab.c"
    break;

  case 117:
#line 371 "tema.y"
                                 {verifica_conditia((yyvsp[-2].integer),3,(yyvsp[0].integer));}
#line 2157 "y.tab.c"
    break;

  case 118:
#line 372 "tema.y"
                                 {verifica_conditia((yyvsp[-2].integer),4,(yyvsp[0].integer));}
#line 2163 "y.tab.c"
    break;

  case 119:
#line 373 "tema.y"
                                 {verifica_conditia((yyvsp[-2].integer),5,(yyvsp[0].integer));}
#line 2169 "y.tab.c"
    break;

  case 120:
#line 374 "tema.y"
                                 {verifica_conditia((yyvsp[-2].integer),6,(yyvsp[0].integer));}
#line 2175 "y.tab.c"
    break;

  case 121:
#line 375 "tema.y"
                                 {verifica_conditia(1,7,1);}
#line 2181 "y.tab.c"
    break;


#line 2185 "y.tab.c"

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
#line 387 "tema.y"

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
        var[count_v].vizibilitate=strdup(vizibilitate);
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
                 else{
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
void print_variabile(char* mesaj ,char* nume) // momentan in lucru ...
{
        
        char* ptr=nume;
        //strcpy(ptr,ptr+1);
       // ptr=strtok(nume,"\"");
       
        int gasit=0;
        
        for (int i = 0; i < count_v; i++)
         {
                 //printf("variabile: %s %s\n",var[i].id,var[i].tip);
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
{
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
                  if(strcmp(var[i].vizibilitate,"global")==0) var[i].valoare=strdup(valoare);
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
                                //printf("variabila trebuie declarata inainte\n"); exit(0);
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

void set_parametrii_apel(char* tip, struct parametru *aux){
        
        aux[count_aux_apel].tip=(char*)malloc(strlen(tip));
        strcpy(aux[count_aux_apel].tip,tip);
        count_aux_apel++; 
}

char* get_tip_dupa_nume(char* nume){
        for(int i=0; i<count_f;i++){
              if(strcmp(functii[i].id,nume)==0){
                      printf("returnez: %s\n",functii[i].tip_return);
                      return functii[i].tip_return;
              }  
        }
}



void scrieVariabileFisier()
{
      FILE* var_fisier_ptr;
      var_fisier_ptr=fopen(fisier_variabile,"w+"); // dechidere fisier 
      fprintf(var_fisier_ptr,"tip  id  valoare  vizibilitate  este_const  dimensiune\n");
      fprintf(var_fisier_ptr,"---------------------------------------------------------\n");
      fprintf(var_fisier_ptr,"\n\nGLOBAL:\n");
      for(int i=0;i<count_v;i++){
              if(strcmp(var[i].vizibilitate,"global")==0)
              if(var[i].dimensiune==0){
                fprintf(var_fisier_ptr,"%s  %s  %s  %s  %d  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              }
              else{
                fprintf(var_fisier_ptr,"%s  %s ", var[i].tip, var[i].id); 
                for(int j=0;j<var[i].dimensiune;j++){
                        fprintf(var_fisier_ptr,"%s ",var[i].val2[j]);
                }
                fprintf(var_fisier_ptr,"%s  %d  %d\n", var[i].vizibilitate,var[i].constante,var[i].dimensiune);   
              }
              
      }
      fprintf(var_fisier_ptr,"\n\nMAIN:\n");
       for(int i=0;i<count_v;i++){
              if(strcmp(var[i].vizibilitate,"main")==0)
              if(var[i].dimensiune==0){
                fprintf(var_fisier_ptr,"%s  %s  %s  %s  %d  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              }
              else{
                fprintf(var_fisier_ptr,"%s  %s ", var[i].tip, var[i].id); 
                for(int j=0;j<var[i].dimensiune;j++){
                        fprintf(var_fisier_ptr,"%s ",var[i].val2[j]);
                }
                fprintf(var_fisier_ptr,"%s  %d  %d\n", var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              }
              
      }

       fprintf(var_fisier_ptr,"\n\nFUNCTII:\n");
       for(int i=0;i<count_v;i++){
              if(strstr(var[i].vizibilitate,"functie"))
                fprintf(var_fisier_ptr,"%s  %s  %s  %s  %d  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              
      }

       fprintf(var_fisier_ptr,"\n\nCLASE:\n");
       for(int i=0;i<count_v;i++){
              if(strstr(var[i].vizibilitate,"clas"))
                fprintf(var_fisier_ptr,"%s  %s  %s  %s  %d  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              
      }


      fclose(var_fisier_ptr);
}

int functie_deja_declarata(char* id,struct parametru *param)
{       
        
        int size_param=count_aux;
        for(int i=0; i<count_f;i++){
                if(strcmp(functii[i].id,id)==0){//daca gasesc o functie cu acelasi nume
                        if(functii[i].nr_parametrii==size_param){//acelasi numar de parametri
                                int gasit=0;
                                for(int j=0;j<functii[i].nr_parametrii; j++){ //verific tipul fiecarui parametru
                                        if(strcmp(functii[i].parametrii_functie[j].tip,param[j].tip)==0){
                                                gasit++;
                                        }
                                }
                                if(gasit==functii[i].nr_parametrii){
                                        return -1;
                                }
                        }
                }
        }

        return 0;

       
        /*
        for(int i=0;i<count_f;i++)
        {
               //overloading 
               //nume + tip identic => parametrii diferiti
                if(strcmp(functii[i].tip_return,tip)==0 && strcmp(functii[i].id,id)==0){
                        //verific nr parametrii egal 
                        
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
        */

}

int functie_deja_declarata_pt_apel(char* id,struct parametru *param){
        int size_param=count_aux_apel;
        for(int i=0; i<count_f;i++){
                if(strcmp(functii[i].id,id)==0){//daca gasesc o functie cu acelasi nume
                        if(functii[i].nr_parametrii==size_param){//acelasi numar de parametri
                                int gasit=0;
                                for(int j=0;j<functii[i].nr_parametrii; j++){ //verific tipul fiecarui parametru
                                        if(strcmp(functii[i].parametrii_functie[j].tip,param[j].tip)==0){
                                                gasit++;
                                        }
                                }
                                if(gasit==functii[i].nr_parametrii){
                                        return -1;
                                }
                        }
                }
        }

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

void scrieFunctiiInFisier()
{
        //id,tip,parametri,variabile
        FILE* functii_fisier_ptr;
        functii_fisier_ptr=fopen(fisier_functii,"w+");
        fprintf(functii_fisier_ptr,"tip  id nr_parametrii     parametrii \n");
        fprintf(functii_fisier_ptr,"---------------------------------------------------------\n");
        for(int i=0;i<count_f;i++) {
          // afisare tip, nume si nr parametrii
          fprintf(functii_fisier_ptr,"%s %s %d ",functii[i].tip_return,functii[i].id,functii[i].nr_parametrii);

          // afisare parametrii functie
          for(int j=0; j<functii[i].nr_parametrii; j++) {
                  fprintf(functii_fisier_ptr, "%s %s ", functii[i].parametrii_functie[j].tip, functii[i].parametrii_functie[j].id);
          }

          fprintf(functii_fisier_ptr, "\n");
        }


        fclose(functii_fisier_ptr);

}

void creeaza_clasa(char* tip){
        strcpy(clase[nr_clase].tip,tip);
        clase[nr_clase].nr_variabile=0;
        nr_clase++;
}

void error_ne_decl_functie(char* nume){
        char error_msg[250];
        sprintf(error_msg, "Functia %s nu este declarata", nume);
        yyerror(error_msg); 
        exit(0);
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

void declara_vector(char* tip, char* nume, int dimensiune,char* vizibilitate){
        int index=verificare_exista_variabila(nume);
        if(index!=-1){
                char error_msg[250];
                strcat(error_msg, "Vector deja declarat");
                yyerror(error_msg);
                exit(0);  
        }
        else{   
                var[count_v].tip=strdup(tip);
                var[count_v].id=strdup(nume);
                var[count_v].constante=0;
                var[count_v].vizibilitate=strdup(vizibilitate);
                var[count_v].val2=(char**)malloc(dimensiune * sizeof(char*));
                for(int j=0;j<dimensiune;j++){
                        var[count_v].val2[j]=strdup("0");
                }
                var[count_v].dimensiune=dimensiune;
                count_v++;  
        }
}

void asignare_pt_element_vector(char* nume,int pozitie, char* valoare, char* tip_val){
        int index=verificare_exista_variabila(nume);
        if(index==-1){
                char error_msg[250];
                strcat(error_msg, "Vector  nedeclarat");
                yyerror(error_msg);
                exit(0);  
        }
        else{
                if(strcmp(var[index].tip,tip_val)==0){
                        if(pozitie>=0 && pozitie<var[index].dimensiune){
                             var[index].val2[pozitie]=strdup(valoare);   
                        }
                        else{
                              char error_msg[250];
                                bzero(error_msg,250);
                                strcat(error_msg, "Index invalid");
                                yyerror(error_msg);
                                exit(0);    
                        }
                }
                else{
                        char error_msg[250];
                        strcat(error_msg, "Nepotrivire tipuri");
                        yyerror(error_msg);
                        exit(0); 
                }
        }
}

void asignare_cu_element_vector(char* nume_var,char* nume_vector,int index_elem){
        int index_variabila=verificare_exista_variabila(nume_var);

        if(index_variabila==-1){
                error_ne_decl_variabila(nume_var);
        }
        else{
              int index_vector=verificare_exista_variabila(nume_vector); 
              if(index_vector==-1){
                      error_ne_decl_variabila(nume_vector);
              }
              else{
                      if(index_elem>=var[index_vector].dimensiune || index_elem<0){
                        char error_msg[250];
                        bzero(error_msg,250);
                        strcat(error_msg, "Index invalid");
                        yyerror(error_msg);
                        exit(0);   
                      }
                      else{
                              if(strcmp(var[index_variabila].tip,var[index_vector].tip)!=0){
                                char error_msg[250];
                                bzero(error_msg,250);
                                strcat(error_msg, "Nepotrivire tipuri");
                                yyerror(error_msg);
                                exit(0);  
                              }
                              else{
                                      var[index_variabila].valoare=strdup(var[index_vector].val2[index_elem]);
                              }
                      }
              } 
        }
}

int get_valoare_vector_dupa_nume(char* nume,int index_elem){
        int index_vector=verificare_exista_variabila(nume); 
        if(index_vector==-1){
                error_ne_decl_variabila(nume);
        }
        else{
               if(index_elem>=var[index_vector].dimensiune || index_elem<0){
                        char error_msg[250];
                        bzero(error_msg,250);
                        strcat(error_msg, "Index invalid");
                        yyerror(error_msg);
                        exit(0);   
                } 
                else{
                        if(strcmp(var[index_vector].tip,"Integer")!=0){
                               char error_msg[250];
                                bzero(error_msg,250);
                                strcat(error_msg, "Expresie poate fi doar integer");
                                yyerror(error_msg);
                                exit(0);   
                        }
                        else{
                                return atoi(var[index_vector].val2[index_elem]);
                        }
                }
        }
}
        
