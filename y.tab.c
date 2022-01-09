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


char *citeste_fisier(char *file);

#line 153 "y.tab.c"

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
    CHAR = 283,
    STRING = 284,
    NR_REAL = 285,
    NR_INT = 286,
    ID = 287,
    TIP = 288
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
#define CHAR 283
#define STRING 284
#define NR_REAL 285
#define NR_INT 286
#define ID 287
#define TIP 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 85 "tema.y"

    double num;
    char* str;
    int integer;
    float real;
    int boolean;

#line 279 "y.tab.c"

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
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

#define YYUNDEFTOK  2
#define YYMAXUTOK   288


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,     2,     2,    34,     2,    42,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   123,   123,   124,   125,   126,   127,   132,   133,   135,
     136,   137,   138,   140,   141,   142,   145,   146,   148,   149,
     151,   152,   154,   155,   162,   163,   164,   165,   166,   167,
     168,   170,   171,   173,   174,   176,   177,   179,   180,   181,
     182,   184,   185,   186,   188,   189,   190,   191,   195,   196,
     197,   198,   201,   210,   211,   213,   222,   223,   225,   226,
     228,   229,   230,   231,   234,   235,   237,   239,   240,   241,
     242,   248,   250,   251,   253,   254,   256,   257,   258,   259,
     260,   262,   263,   274,   290,   291,   292,   293,   294,   295,
     298,   299,   300,   301,   302,   303,   304,   305,   307,   308,
     310,   311,   313,   314,   315,   316,   317,   320,   321,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   334,   335,
     337,   339,   341
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
  "LESS", "GREATER", "INCR", "DECR", "CHAR", "STRING", "NR_REAL", "NR_INT",
  "ID", "TIP", "','", "';'", "'('", "')'", "'['", "']'", "'{'", "'}'",
  "'.'", "$accept", "s", "declaratii_globale", "declaratie_globala",
  "declaratie_locala", "variabila_initializata_local",
  "variabila_declarata_local", "variabila_initializata_global",
  "variabila_declarata_global", "expresie", "array", "dimensiune",
  "lista_valori", "valoare", "print", "asignare_globala", "functii_clase",
  "class_definitie", "class_declaratii", "class_declaratie",
  "functii_declaratie", "cod_functii", "cod_f", "lista_param", "param",
  "asignare_functie", "main_prog", "acolade", "cod_bloc", "cod",
  "clasa_noua", "asignare_main", "expr", "apel_functie", "lista_apel",
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
     285,   286,   287,   288,    44,    59,    40,    41,    91,    93,
     123,   125,    46
};
# endif

#define YYPACT_NINF (-138)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-16)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,   -19,     2,    67,    57,   106,   100,   135,   105,   111,
    -138,  -138,  -138,  -138,  -138,    18,  -138,  -138,  -138,   142,
     145,   156,   169,   262,    -5,  -138,   170,    18,  -138,  -138,
     181,  -138,  -138,  -138,    50,   201,   182,   239,  -138,  -138,
    -138,  -138,  -138,   158,   300,   158,    79,   117,   189,  -138,
    -138,   207,   192,  -138,   158,    11,  -138,   242,   119,  -138,
     146,   158,   158,   158,   158,   300,   244,   233,   113,  -138,
     243,   278,   250,   259,   194,   300,   272,   261,   268,   270,
     285,   286,   223,   301,  -138,   297,  -138,  -138,  -138,  -138,
    -138,    53,  -138,   299,   302,  -138,   303,  -138,  -138,  -138,
    -138,   304,   305,  -138,  -138,   210,   210,  -138,  -138,  -138,
     155,   309,   295,  -138,   306,   310,  -138,  -138,   311,   222,
     312,   222,  -138,  -138,   271,  -138,  -138,  -138,   220,   313,
     104,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   319,
     315,   316,   317,    98,  -138,  -138,  -138,  -138,   155,   296,
    -138,   324,  -138,   314,   158,   264,  -138,    56,   331,   318,
     108,  -138,  -138,  -138,   300,  -138,   308,   165,   336,   158,
     280,    17,  -138,  -138,  -138,   171,  -138,  -138,  -138,  -138,
      -2,  -138,   158,   225,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   320,   323,   321,   322,
     222,  -138,   283,   300,   328,   329,   330,   248,  -138,   296,
    -138,   300,  -138,   308,   308,   308,   308,   241,   241,  -138,
    -138,   308,   308,   337,  -138,    21,   332,    21,    21,   308,
    -138,   300,  -138,  -138,  -138,  -138,  -138,    92,   222,   193,
     203,   351,    63,  -138,  -138,   326,   154,    21,    23,  -138,
     234,  -138
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       9,    10,    23,    11,    12,     0,    50,    49,     5,     0,
       0,     0,     0,     0,    22,     1,     0,     0,     3,     7,
       0,    48,    51,     4,     0,     0,     0,     0,    47,    46,
      45,    30,    29,     0,    44,     0,     0,     0,    31,     8,
       2,     0,     0,    42,     0,     0,    71,     0,     0,    53,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    64,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,    13,    14,    19,    15,
      81,     0,    75,     0,     0,   103,     0,    76,    77,   119,
     118,     0,     0,    54,    28,    24,    25,    26,    27,    66,
       0,     0,     0,    33,     0,     0,    43,    41,     0,     0,
       0,     0,   105,   106,     0,   102,   104,    83,     0,     0,
      18,    78,    73,    74,    82,    80,    79,    55,    52,     0,
       0,     0,    63,     0,    59,    61,    62,    65,     0,     0,
      34,     0,    96,    95,     0,   117,    97,     0,     0,     0,
       0,    87,    86,    85,    84,    98,   100,     0,     0,     0,
       0,    18,    60,    57,    58,     0,    40,    39,    38,    37,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,    17,     0,     0,     0,     0,    56,     0,
      32,    16,    94,   112,   113,   111,   114,    90,    91,    92,
      93,   109,   110,   116,   115,     0,     0,     0,     0,   101,
      88,    89,    70,    69,    68,    67,    35,     0,     0,     0,
       0,   107,     0,   121,   120,     0,     0,     0,     0,   122,
       0,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,   350,  -103,  -138,  -138,  -138,  -138,   -41,
     157,  -138,  -138,   150,     1,  -138,   360,    77,  -138,   325,
     107,   221,  -133,  -138,   260,  -138,   128,  -138,  -137,   -86,
    -138,  -138,  -122,   -55,  -138,   124,  -138,  -118,  -102,  -138,
    -138,  -138
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    85,    86,    87,    10,    11,    44,
      88,    48,   180,   181,    89,    14,    15,    16,    58,    59,
      90,   143,   144,    68,    69,   145,    18,    56,    91,    92,
      93,    94,   155,   156,   167,    96,    97,   157,    98,    99,
     100,   159
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    13,    60,   160,    65,   133,   166,   141,   146,    13,
     174,    74,    45,    75,     1,    76,    77,    19,    78,    79,
     105,   106,   107,   108,     1,    76,    77,     3,    78,    79,
       4,    46,   209,    47,   169,    20,    95,    80,    81,   210,
     141,   146,   174,    82,    83,   141,   146,    80,    81,   125,
     126,    30,    84,    82,    83,    47,     1,    76,    77,   128,
      78,    79,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   141,   146,   194,   195,   223,   224,   229,    80,
      81,   194,   195,   164,    52,    82,    83,    53,   237,    22,
     239,   240,    31,   196,   132,     1,    76,    77,   246,    78,
      79,     1,    76,    21,    31,    78,    79,    17,     1,     2,
     250,   142,    66,   183,     3,    17,    67,     4,    80,    81,
     242,   169,    32,    23,    82,    83,   194,   195,   203,   207,
     139,   140,    24,   241,    32,    25,    28,     5,     6,   173,
      46,   211,    47,    33,   142,   199,    29,   111,    70,   142,
     112,   133,    57,   133,   133,    50,    71,    12,     1,    76,
     102,   231,    78,    79,   133,    12,    61,    62,    63,    64,
      95,    34,    95,    95,     1,    76,   142,    35,    78,    79,
      80,    81,    95,   104,    95,    95,   248,   139,   140,    41,
      42,    95,    95,    36,    43,    95,     1,    76,    77,   200,
      78,    79,   201,   139,   140,    49,     1,    76,    77,    37,
      78,    79,   208,    51,    61,    62,    63,    64,    54,    80,
      81,    73,    55,    41,    42,    82,    83,    72,    43,    80,
      81,   117,    63,    64,   243,    82,    83,     1,    76,    77,
     124,    78,    79,    46,   244,    61,    62,    63,    64,   125,
     126,   152,   153,   152,   153,   127,   154,   165,   154,   128,
      80,    81,   212,   190,   191,   129,    82,    83,    61,    62,
      63,    64,    57,   110,   101,   251,   109,   184,   185,   186,
     187,   115,   113,   235,   188,   189,   190,   191,   192,   193,
      38,    39,    40,    41,    42,   114,   116,   119,    43,   161,
     162,   163,    41,    42,   120,   118,   121,    43,   204,   205,
     206,    41,    42,   230,    41,    42,    43,   122,   123,    43,
      61,    62,    63,    64,   176,   177,   178,   179,   188,   189,
     190,   191,   131,   130,   134,   148,   170,   135,   136,   137,
     138,   182,    66,   151,   158,   168,   149,   171,   197,   150,
     128,   172,   -15,   202,   226,   198,   195,   245,    26,   236,
     225,   227,   228,   232,   233,   234,   247,   238,    27,   175,
     249,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103
};

static const yytype_int16 yycheck[] =
{
      55,     0,    43,   121,    45,    91,   128,   110,   110,     8,
     143,    52,    17,    54,     3,     4,     5,    36,     7,     8,
      61,    62,    63,    64,     3,     4,     5,     9,     7,     8,
      12,    36,    34,    38,    17,    33,    91,    26,    27,    41,
     143,   143,   175,    32,    33,   148,   148,    26,    27,    26,
      27,    33,    41,    32,    33,    38,     3,     4,     5,    36,
       7,     8,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   175,   175,    18,    19,   194,   195,   200,    26,
      27,    18,    19,   124,    34,    32,    33,    37,   225,    32,
     227,   228,    15,    37,    41,     3,     4,     5,    35,     7,
       8,     3,     4,    36,    27,     7,     8,     0,     3,     4,
     247,   110,    33,   154,     9,     8,    37,    12,    26,    27,
     238,    17,    15,    17,    32,    33,    18,    19,   169,   170,
      32,    33,    32,    41,    27,     0,     8,    32,    33,    41,
      36,   182,    38,    15,   143,    37,    35,    34,    31,   148,
      37,   237,    33,   239,   240,    27,    39,     0,     3,     4,
      41,   202,     7,     8,   250,     8,    20,    21,    22,    23,
     225,    29,   227,   228,     3,     4,   175,    32,     7,     8,
      26,    27,   237,    37,   239,   240,    32,    32,    33,    31,
      32,   246,   247,    37,    36,   250,     3,     4,     5,    34,
       7,     8,    37,    32,    33,    35,     3,     4,     5,    40,
       7,     8,    41,    32,    20,    21,    22,    23,    17,    26,
      27,    29,    40,    31,    32,    32,    33,    38,    36,    26,
      27,    37,    22,    23,    41,    32,    33,     3,     4,     5,
      17,     7,     8,    36,    41,    20,    21,    22,    23,    26,
      27,    31,    32,    31,    32,    32,    36,    37,    36,    36,
      26,    27,    37,    22,    23,    42,    32,    33,    20,    21,
      22,    23,    33,    40,    32,    41,    32,    13,    14,    15,
      16,    31,    39,    35,    20,    21,    22,    23,    24,    25,
      28,    29,    30,    31,    32,    17,    37,    36,    36,    28,
      29,    30,    31,    32,    36,    33,    36,    36,    28,    29,
      30,    31,    32,    30,    31,    32,    36,    32,    32,    36,
      20,    21,    22,    23,    28,    29,    30,    31,    20,    21,
      22,    23,    35,    32,    35,    40,    17,    35,    35,    35,
      35,    17,    33,    32,    32,    32,    40,    32,    17,    39,
      36,    35,    35,    17,    31,    37,    19,     6,     8,   209,
      40,    40,    40,    35,    35,    35,    40,    35,     8,   148,
     246,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     9,    12,    32,    33,    44,    45,    46,
      50,    51,    53,    57,    58,    59,    60,    63,    69,    36,
      33,    36,    32,    17,    32,     0,    46,    59,    69,    35,
      33,    60,    63,    69,    29,    32,    37,    40,    28,    29,
      30,    31,    32,    36,    52,    17,    36,    38,    54,    35,
      69,    32,    34,    37,    17,    40,    70,    33,    61,    62,
      52,    20,    21,    22,    23,    52,    33,    37,    66,    67,
      31,    39,    38,    29,    52,    52,     4,     5,     7,     8,
      26,    27,    32,    33,    41,    47,    48,    49,    53,    57,
      63,    71,    72,    73,    74,    76,    78,    79,    81,    82,
      83,    32,    41,    62,    37,    52,    52,    52,    52,    32,
      40,    34,    37,    39,    17,    31,    37,    37,    33,    36,
      36,    36,    32,    32,    17,    26,    27,    32,    36,    42,
      32,    35,    41,    72,    35,    35,    35,    35,    35,    32,
      33,    47,    57,    64,    65,    68,    81,    67,    40,    40,
      39,    32,    31,    32,    36,    75,    76,    80,    32,    84,
      80,    28,    29,    30,    52,    37,    75,    77,    32,    17,
      17,    32,    35,    41,    65,    64,    28,    29,    30,    31,
      55,    56,    17,    52,    13,    14,    15,    16,    20,    21,
      22,    23,    24,    25,    18,    19,    37,    17,    37,    37,
      34,    37,    17,    52,    28,    29,    30,    52,    41,    34,
      41,    52,    37,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    80,    80,    40,    31,    40,    40,    75,
      30,    52,    35,    35,    35,    35,    56,    71,    35,    71,
      71,    41,    80,    41,    41,     6,    35,    40,    32,    78,
      71,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    44,    44,    44,    45,    45,    46,
      46,    46,    46,    47,    47,    47,    48,    48,    49,    49,
      50,    50,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    57,    57,    57,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    61,    61,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    66,    66,    67,    68,    68,    68,
      68,    69,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    73,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      82,    83,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       5,     4,     2,     1,     3,     3,     3,     3,     3,     1,
       1,     3,     8,     3,     4,     3,     1,     1,     1,     1,
       1,     6,     4,     6,     3,     3,     3,     3,     2,     1,
       1,     2,     6,     1,     2,     3,     8,     7,     2,     1,
       2,     1,     1,     1,     1,     3,     2,     4,     4,     4,
       4,     4,     2,     3,     2,     1,     1,     1,     2,     2,
       2,     1,     2,     2,     3,     3,     3,     3,     5,     5,
       3,     3,     3,     3,     3,     1,     1,     1,     3,     4,
       1,     3,     2,     1,     2,     2,     2,     7,    11,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       7,     7,     7
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
#line 123 "tema.y"
                                               {printf("1   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1657 "y.tab.c"
    break;

  case 3:
#line 124 "tema.y"
                                {printf("2   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1663 "y.tab.c"
    break;

  case 4:
#line 125 "tema.y"
                           {printf("3   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1669 "y.tab.c"
    break;

  case 5:
#line 126 "tema.y"
             {printf("4   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1675 "y.tab.c"
    break;

  case 6:
#line 127 "tema.y"
                      {printf("5   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1681 "y.tab.c"
    break;

  case 7:
#line 132 "tema.y"
                                    { var[count_v-1].vizibilitate=strdup("global");}
#line 1687 "y.tab.c"
    break;

  case 8:
#line 133 "tema.y"
                                                       { var[count_v-1].vizibilitate=strdup("global");}
#line 1693 "y.tab.c"
    break;

  case 16:
#line 145 "tema.y"
                                                           {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),1,"main");}
#line 1699 "y.tab.c"
    break;

  case 17:
#line 146 "tema.y"
                                               {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),0,"main");}
#line 1705 "y.tab.c"
    break;

  case 18:
#line 148 "tema.y"
                                  {declarare_fara_initializare((yyvsp[-1].str),(yyvsp[0].str),0,"main");}
#line 1711 "y.tab.c"
    break;

  case 20:
#line 151 "tema.y"
                                                            {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),1,"global");}
#line 1717 "y.tab.c"
    break;

  case 21:
#line 152 "tema.y"
                                               {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),0,"global");}
#line 1723 "y.tab.c"
    break;

  case 22:
#line 154 "tema.y"
                                   {declarare_fara_initializare((yyvsp[-1].str),(yyvsp[0].str),0,"global");}
#line 1729 "y.tab.c"
    break;

  case 24:
#line 162 "tema.y"
                                   {(yyval.integer) = (yyvsp[-2].integer) + (yyvsp[0].integer);}
#line 1735 "y.tab.c"
    break;

  case 25:
#line 163 "tema.y"
                                   {(yyval.integer) = (yyvsp[-2].integer) - (yyvsp[0].integer);}
#line 1741 "y.tab.c"
    break;

  case 26:
#line 164 "tema.y"
                                  {(yyval.integer) = (yyvsp[-2].integer) * (yyvsp[0].integer);}
#line 1747 "y.tab.c"
    break;

  case 27:
#line 165 "tema.y"
                                 {(yyval.integer) = (yyvsp[-2].integer) / (yyvsp[0].integer);}
#line 1753 "y.tab.c"
    break;

  case 28:
#line 166 "tema.y"
                           {(yyval.integer) = (yyvsp[-1].integer);}
#line 1759 "y.tab.c"
    break;

  case 29:
#line 167 "tema.y"
              {(yyval.integer)=get_valoare_dupa_nume((yyvsp[0].str));}
#line 1765 "y.tab.c"
    break;

  case 30:
#line 168 "tema.y"
                  {(yyval.integer) = (yyvsp[0].integer);}
#line 1771 "y.tab.c"
    break;

  case 41:
#line 184 "tema.y"
                                            {printf("%s %d\n",(yyvsp[-3].str),(yyvsp[-1].integer));}
#line 1777 "y.tab.c"
    break;

  case 42:
#line 185 "tema.y"
                              {printf("%s\n",(yyvsp[-1].str));}
#line 1783 "y.tab.c"
    break;

  case 43:
#line 186 "tema.y"
                                         {print_variabile((yyvsp[-3].str),(yyvsp[-1].str));}
#line 1789 "y.tab.c"
    break;

  case 44:
#line 188 "tema.y"
                                        {char count_str[]="global"; char str_valoare[50]; snprintf(str_valoare,50,"%d",(yyvsp[0].integer)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,0);}
#line 1795 "y.tab.c"
    break;

  case 45:
#line 189 "tema.y"
                                      {char count_str[]="global"; char str_valoare[50]; snprintf(str_valoare,50,"%f",(yyvsp[0].real)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,1);}
#line 1801 "y.tab.c"
    break;

  case 46:
#line 190 "tema.y"
                                       {char count_str[]="global"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),2);}
#line 1807 "y.tab.c"
    break;

  case 47:
#line 191 "tema.y"
                                      {char count_str[]="global"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),3);}
#line 1813 "y.tab.c"
    break;

  case 52:
#line 201 "tema.y"
                                                         {if(clasa_deja_definita((yyvsp[-4].str))==-1){
                                                                creeaza_clasa((yyvsp[-4].str));
                                                                }
                                                        else{
                                                               error_decl_clasa((yyvsp[-4].str)); 
                                                        }
                                                }
#line 1825 "y.tab.c"
    break;

  case 55:
#line 213 "tema.y"
                             { if(variabila_class_deja_declarata((yyvsp[-1].str),"class")==-1){
                                   declarare_variabila_class((yyvsp[-2].str),(yyvsp[-1].str),"class");   
                                }
                                else{
                                        error_decl((yyvsp[-1].str));
                                }
                        }
#line 1837 "y.tab.c"
    break;

  case 56:
#line 222 "tema.y"
                                                                    { if(functie_deja_declarata((yyvsp[-7].str),(yyvsp[-6].str),aux)==0){ creaza_functie((yyvsp[-7].str),(yyvsp[-6].str),aux);} else {count_aux=0;mesaj_functie_existenta((yyvsp[-6].str)); } }
#line 1843 "y.tab.c"
    break;

  case 57:
#line 223 "tema.y"
                                                        {if(functie_deja_declarata((yyvsp[-6].str),(yyvsp[-5].str),empty_struct)==0){ creaza_functie((yyvsp[-6].str),(yyvsp[-5].str),empty_struct);} else {count_aux=0;mesaj_functie_existenta((yyvsp[-5].str)); } }
#line 1849 "y.tab.c"
    break;

  case 60:
#line 228 "tema.y"
                              {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); var[count_v-1].vizibilitate=strdup(count_str);}
#line 1855 "y.tab.c"
    break;

  case 66:
#line 237 "tema.y"
              { set_parametrii_functie((yyvsp[-1].str),(yyvsp[0].str),aux);}
#line 1861 "y.tab.c"
    break;

  case 67:
#line 239 "tema.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); char str_valoare[50]; snprintf(str_valoare,50,"%d",(yyvsp[-1].integer)); asignare_exista_variabila((yyvsp[-3].str),count_str,str_valoare,0);}
#line 1867 "y.tab.c"
    break;

  case 68:
#line 240 "tema.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); char str_valoare[50]; snprintf(str_valoare,50,"%f",(yyvsp[-1].real)); asignare_exista_variabila((yyvsp[-3].str),count_str,str_valoare,1);}
#line 1873 "y.tab.c"
    break;

  case 69:
#line 241 "tema.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); asignare_exista_variabila((yyvsp[-3].str),count_str,(yyvsp[-1].str),2);}
#line 1879 "y.tab.c"
    break;

  case 70:
#line 242 "tema.y"
                                         {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); asignare_exista_variabila((yyvsp[-3].str),count_str,(yyvsp[-1].str),3);}
#line 1885 "y.tab.c"
    break;

  case 78:
#line 258 "tema.y"
                           {var[count_v-1].vizibilitate=strdup("main");}
#line 1891 "y.tab.c"
    break;

  case 83:
#line 274 "tema.y"
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
#line 1910 "y.tab.c"
    break;

  case 84:
#line 290 "tema.y"
                                       {char count_str[]="main"; char str_valoare[50]; snprintf(str_valoare,50,"%d",(yyvsp[0].integer)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,0);}
#line 1916 "y.tab.c"
    break;

  case 85:
#line 291 "tema.y"
                                      {char count_str[]="main"; char str_valoare[50]; snprintf(str_valoare,50,"%f",(yyvsp[0].real)); asignare_exista_variabila((yyvsp[-2].str),count_str,str_valoare,1);}
#line 1922 "y.tab.c"
    break;

  case 86:
#line 292 "tema.y"
                                      {char count_str[]="main"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),2);}
#line 1928 "y.tab.c"
    break;

  case 87:
#line 293 "tema.y"
                                      {char count_str[]="main"; asignare_exista_variabila((yyvsp[-2].str),count_str,(yyvsp[0].str),3);}
#line 1934 "y.tab.c"
    break;

  case 88:
#line 294 "tema.y"
                                           {char valoare[50];  snprintf(valoare,50,"%f",(yyvsp[0].real));  asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),valoare,"Float");}
#line 1940 "y.tab.c"
    break;

  case 89:
#line 295 "tema.y"
                                            {char valoare[50]; sprintf(valoare,"%d",(yyvsp[0].integer));  asignare_pt_data_membru((yyvsp[-4].str),(yyvsp[-2].str),valoare,"Integer");}
#line 1946 "y.tab.c"
    break;


#line 1950 "y.tab.c"

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
#line 344 "tema.y"

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
         }

         if(gasit==0) 
         {
                char error_msg[250];
                sprintf(error_msg, "Variabila nu exista");
                yyerror(error_msg);
                exit(0);
         }

}
void print_variabile(char* mesaj ,char* nume) // momentan in lucru ...
{
        
        char* ptr=nume;
        strcpy(ptr,ptr+1);
        ptr=strtok(nume,"\"");
       
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
        
        for (int i = 0; i < count_v; i++){
                if(strcmp(var[i].id,id)==0) // acelasi nume
                  if(strcmp(var[i].vizibilitate,"global")==0) var[i].valoare=strdup(valoare);
                  else
                   if(strcmp(var[i].vizibilitate,viziblitate)==0) 
                   {
                           if(nr_tip==0) { // int , expresie deja verificat
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
                                   printf("variabila trebuie declarata inainte\n"); exit(0);
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


void scrieVariabileFisier()
{
      FILE* var_fisier_ptr;
      var_fisier_ptr=fopen(fisier_variabile,"w+"); // dechidere fisier 
      fprintf(var_fisier_ptr,"tip  id  valoare  vizibilitate  este_const  dimensiune\n");
      fprintf(var_fisier_ptr,"---------------------------------------------------------\n");
      fprintf(var_fisier_ptr,"\n\nGLOBAL:\n");
      for(int i=0;i<count_v;i++){
              if(strcmp(var[i].vizibilitate,"global")==0)
                fprintf(var_fisier_ptr,"%s  %s  %s  %s  %d  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              
      }
      fprintf(var_fisier_ptr,"\n\nMAIN:\n");
       for(int i=0;i<count_v;i++){
              if(strcmp(var[i].vizibilitate,"main")==0)
                fprintf(var_fisier_ptr,"%s  %s  %s  %s  %d  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
              
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

int functie_deja_declarata(char * tip,char* id,struct parametru *param)
{       
        
        int size_param=count_aux;
        int gasit=-1;
       

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

}

void mesaj_functie_existenta(char msg[]){
     char error_msg[250];
     sprintf(error_msg, "functia %s este deja declarata", msg);
     yyerror(error_msg);
     exit(0);
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
                                                declarare_cu_initializare(clasa,id_variabila,val,0,"main");
                                        }
                                        else{
                                                var[index].valoare=strdup(valoare);
                                                //clase[index_clasa].class_var[index_membru].valoare=strdup(valoare);
                                        }
                                }
                                else if(strcmp(tip_valoare,"Float")==0){
                                        float val=atof(valoare);
                                        int index=variabila_deja_declarata(id_variabila,"main");
                                        if(index==-1){
                                                declarare_cu_initializare(clasa,id_variabila,val,0,"main");
                                        }
                                        else{
                                               var[index].valoare=strdup(valoare);  
                                        }
                                }
                        }
                }
        }
}


