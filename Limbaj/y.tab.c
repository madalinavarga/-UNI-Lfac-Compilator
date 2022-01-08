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
void asignare_exista_variabila(char* id , char* viziblitate, int valoare);
void creeaza_clasa(char* tip);
void error_decl(char* nume);
int variabila_class_deja_declarata(char* nume, char* vizibilitate);
void declarare_variabila_class(char* tip, char* nume,char* vizibilitate);
int clasa_deja_definita(char* nume);
void error_decl_clasa(char* nume);


char *citeste_fisier(char *file);

#line 138 "y.tab.c"

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
#line 70 "tema.y"

    double num;
    char* str;
    int integer;
    float real;
    int boolean;

#line 264 "y.tab.c"

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

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
      36,    37,     2,     2,    34,     2,     2,     2,     2,     2,
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
       0,   108,   108,   109,   110,   111,   112,   117,   118,   120,
     121,   122,   123,   125,   126,   127,   128,   130,   131,   133,
     135,   136,   138,   145,   146,   147,   148,   149,   150,   151,
     154,   155,   157,   158,   160,   161,   163,   164,   165,   166,
     168,   169,   173,   174,   175,   176,   179,   188,   189,   191,
     200,   201,   203,   204,   206,   207,   208,   209,   212,   213,
     215,   217,   218,   223,   225,   226,   228,   229,   231,   232,
     233,   234,   235,   236,   247,   248,   250,   251,   252,   253,
     254,   255,   256,   257,   259,   260,   262,   263,   265,   266,
     267,   268,   269,   272,   273,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   286,   287,   289,   291,   293
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
  "$accept", "s", "declaratii_globale", "declaratie_globala",
  "declaratie_locala", "variabila_initializata_local",
  "variabila_declarata_local", "variabila_initializata_global",
  "variabila_declarata_global", "expresie", "array", "dimensiune",
  "lista_valori", "valoare", "print", "functii_clase", "class_definitie",
  "class_declaratii", "class_declaratie", "functii_declaratie",
  "cod_functii", "cod_f", "lista_param", "param", "asignare_functie",
  "main_prog", "acolade", "cod_bloc", "cod", "asignare", "expr",
  "apel_functie", "lista_apel", "statement", "interogari", "conditie",
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
     285,   286,   287,   288,    44,    59,    40,    41,    91,    93,
     123,   125
};
# endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-17)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      90,   -27,     6,     9,    26,    46,    48,    90,    52,  -127,
    -127,  -127,  -127,    13,  -127,  -127,  -127,    77,   103,    93,
     162,     4,  -127,   184,    13,  -127,  -127,   191,  -127,  -127,
    -127,   -11,   220,   232,   227,   250,   125,    59,   247,  -127,
    -127,   230,   250,  -127,   250,    24,  -127,   262,   114,  -127,
    -127,  -127,   250,   206,   263,   253,   115,  -127,   248,   279,
     266,   148,   206,   265,   264,   267,   268,   269,   270,    74,
     273,  -127,   271,  -127,  -127,  -127,  -127,  -127,    81,  -127,
     272,  -127,   274,  -127,  -127,  -127,  -127,   275,   276,  -127,
     224,   250,   250,   250,   250,  -127,   231,   280,   259,  -127,
     277,   281,  -127,   282,   252,   283,   252,  -127,  -127,   252,
    -127,  -127,   181,   285,    98,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,    41,    41,  -127,  -127,   291,   286,   284,
     206,   287,   189,  -127,  -127,  -127,  -127,   231,   261,  -127,
     295,  -127,   288,   250,   255,  -127,    16,    38,   290,   289,
     142,   234,  -127,   234,   164,   292,   250,   296,    87,  -127,
    -127,  -127,   200,  -127,  -127,  -127,  -127,    85,  -127,   250,
     228,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   293,   252,   294,   297,   252,  -127,   304,
     206,   300,  -127,   261,  -127,   206,  -127,   234,   234,   234,
     234,   251,   251,  -127,  -127,   234,   234,   309,  -127,    11,
     176,    11,    11,   234,   252,  -127,  -127,   113,   226,   124,
     173,   234,   317,    69,  -127,  -127,  -127,   298,    11,   183,
    -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     6,     0,     9,
      10,    11,    12,     0,    44,    43,     5,     0,     0,     0,
       0,    22,     1,     0,     0,     3,     7,     0,    42,    45,
       4,     0,     0,     0,     0,     0,     0,     0,    30,     8,
       2,     0,     0,    41,     0,     0,    63,     0,     0,    47,
      29,    28,     0,    21,     0,     0,     0,    58,     0,     0,
       0,     0,    20,     0,     0,     0,     0,     0,     0,     0,
       0,    64,     0,    13,    14,    15,    16,    73,     0,    67,
       0,    89,     0,    68,    69,   105,   104,     0,     0,    48,
       0,     0,     0,     0,     0,    60,     0,     0,     0,    32,
       0,     0,    40,     0,     0,     0,     0,    91,    92,     0,
      88,    90,     0,     0,    19,    70,    65,    66,    72,    71,
      49,    46,    27,    23,    24,    25,    26,    28,     0,     0,
      62,    57,     0,    53,    55,    56,    59,     0,     0,    33,
       0,    82,    81,     0,   103,    83,     0,     0,     0,     0,
       0,    74,    84,    86,     0,     0,     0,     0,    19,    54,
      51,    52,     0,    39,    38,    37,    36,     0,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
      18,     0,    50,     0,    31,    17,    80,    98,    99,    97,
     100,    76,    77,    78,    79,    95,    96,   102,   101,     0,
       0,     0,     0,    87,     0,    61,    34,     0,     0,     0,
       0,    75,    93,     0,   108,   107,   106,     0,     0,     0,
      94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,   322,   -85,  -127,  -127,  -127,  -127,   -32,
     182,  -127,  -127,   137,     1,   325,    79,  -127,   299,    17,
     199,  -126,  -127,   242,  -127,   135,  -127,    31,   -76,   235,
    -105,   -45,  -127,   123,  -127,  -101,   -83,  -127,  -127,  -127
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    72,    73,    74,     9,    10,   130,
      75,    38,   167,   168,    76,    13,    14,    48,    49,    77,
     132,   133,    56,    57,   134,    16,    46,    78,    79,    80,
     144,   145,   154,    82,    83,   146,    84,    85,    86,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    12,   117,    53,   151,   150,   161,   153,    12,    17,
      61,   129,    62,   135,     1,    63,    64,    15,    65,    66,
      90,    35,     3,    42,    15,     4,    43,     1,    63,    64,
      29,    65,    66,    81,   181,   182,   161,    67,    68,    18,
      36,    29,    37,    69,    70,    19,    27,   129,    22,   135,
      67,    68,   129,   183,   135,   109,    69,    70,    20,   123,
     124,   125,   126,    93,    94,    71,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   113,   129,    21,   135,
     207,   208,   213,   210,     1,    63,    64,    26,    65,    66,
      58,   109,    28,     1,     2,   110,   111,   131,    59,     3,
     110,   111,     4,    28,   156,   112,    31,    67,    68,   221,
     112,   170,   113,    69,    70,   156,     1,    63,    64,   193,
      65,    66,   116,     5,   190,    37,   194,     1,    63,    64,
      33,    65,    66,   131,    36,    32,    37,   195,   131,    67,
      68,   117,    25,   117,   117,    69,    70,    47,    30,    97,
      67,    68,    98,   117,   222,    88,    69,    70,    54,    40,
     181,   182,    55,   131,    81,   225,    81,    81,    91,    92,
      93,    94,    81,    81,    81,    81,     1,    63,    64,   186,
      65,    66,    11,    81,    81,   102,     1,    63,    64,    11,
      65,    66,     1,    63,   181,   182,    65,    66,   187,    67,
      68,   188,    34,     1,    63,    69,    70,    65,    66,    67,
      68,   218,   141,   142,   226,    69,    70,   143,   152,    39,
      50,   127,   128,    41,   230,    52,    91,    92,    93,    94,
     160,    50,   127,   128,     1,    63,    52,    44,    65,    66,
     217,   192,   219,   220,    91,    92,    93,    94,    91,    92,
      93,    94,    67,    68,   175,   176,   177,   178,   223,   229,
      47,   122,    50,   127,   128,   196,    36,    52,   171,   172,
     173,   174,    45,   177,   178,   175,   176,   177,   178,   179,
     180,    50,    51,   141,   142,    60,    52,    99,   143,   163,
     164,   165,   166,    96,    87,    95,   100,   101,   103,   137,
     104,   107,   108,   105,   106,   114,   115,   118,   157,   119,
     120,   121,   169,    54,   140,   147,   155,   138,   158,   159,
     139,   214,   -16,   227,   112,   184,   185,   191,   182,    23,
     216,   189,    24,   209,   211,   215,   162,   212,   228,   136,
     148,   224,     0,     0,     0,     0,     0,    89
};

static const yytype_int16 yycheck[] =
{
      45,     0,    78,    35,   109,   106,   132,   112,     7,    36,
      42,    96,    44,    96,     3,     4,     5,     0,     7,     8,
      52,    17,     9,    34,     7,    12,    37,     3,     4,     5,
      13,     7,     8,    78,    18,    19,   162,    26,    27,    33,
      36,    24,    38,    32,    33,    36,    33,   132,     0,   132,
      26,    27,   137,    37,   137,    17,    32,    33,    32,    91,
      92,    93,    94,    22,    23,    41,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    38,   162,    32,   162,
     181,   182,   187,   184,     3,     4,     5,    35,     7,     8,
      31,    17,    13,     3,     4,    26,    27,    96,    39,     9,
      26,    27,    12,    24,    17,    36,    29,    26,    27,   214,
      36,   143,    38,    32,    33,    17,     3,     4,     5,    34,
       7,     8,    41,    33,   156,    38,    41,     3,     4,     5,
      37,     7,     8,   132,    36,    32,    38,   169,   137,    26,
      27,   217,     7,   219,   220,    32,    33,    33,    13,    34,
      26,    27,    37,   229,    41,    41,    32,    33,    33,    24,
      18,    19,    37,   162,   209,    41,   211,   212,    20,    21,
      22,    23,   217,   218,   219,   220,     3,     4,     5,    37,
       7,     8,     0,   228,   229,    37,     3,     4,     5,     7,
       7,     8,     3,     4,    18,    19,     7,     8,    34,    26,
      27,    37,    40,     3,     4,    32,    33,     7,     8,    26,
      27,    35,    31,    32,    41,    32,    33,    36,    37,    35,
      31,    32,    33,    32,    41,    36,    20,    21,    22,    23,
      41,    31,    32,    33,     3,     4,    36,    17,     7,     8,
     209,    41,   211,   212,    20,    21,    22,    23,    20,    21,
      22,    23,    26,    27,    20,    21,    22,    23,    32,   228,
      33,    37,    31,    32,    33,    37,    36,    36,    13,    14,
      15,    16,    40,    22,    23,    20,    21,    22,    23,    24,
      25,    31,    32,    31,    32,    38,    36,    39,    36,    28,
      29,    30,    31,    40,    32,    32,    17,    31,    33,    40,
      36,    32,    32,    36,    36,    32,    35,    35,    17,    35,
      35,    35,    17,    33,    32,    32,    31,    40,    32,    35,
      39,    17,    35,     6,    36,    35,    37,    31,    19,     7,
     193,    39,     7,    40,    40,    35,   137,    40,    40,    97,
     105,   218,    -1,    -1,    -1,    -1,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     9,    12,    33,    43,    44,    45,    49,
      50,    52,    56,    57,    58,    61,    67,    36,    33,    36,
      32,    32,     0,    45,    57,    67,    35,    33,    58,    61,
      67,    29,    32,    37,    40,    17,    36,    38,    53,    35,
      67,    32,    34,    37,    17,    40,    68,    33,    59,    60,
      31,    32,    36,    51,    33,    37,    64,    65,    31,    39,
      38,    51,    51,     4,     5,     7,     8,    26,    27,    32,
      33,    41,    46,    47,    48,    52,    56,    61,    69,    70,
      71,    73,    75,    76,    78,    79,    80,    32,    41,    60,
      51,    20,    21,    22,    23,    32,    40,    34,    37,    39,
      17,    31,    37,    33,    36,    36,    36,    32,    32,    17,
      26,    27,    36,    38,    32,    35,    41,    70,    35,    35,
      35,    35,    37,    51,    51,    51,    51,    32,    33,    46,
      51,    56,    62,    63,    66,    78,    65,    40,    40,    39,
      32,    31,    32,    36,    72,    73,    77,    32,    71,    81,
      77,    72,    37,    72,    74,    31,    17,    17,    32,    35,
      41,    63,    62,    28,    29,    30,    31,    54,    55,    17,
      51,    13,    14,    15,    16,    20,    21,    22,    23,    24,
      25,    18,    19,    37,    35,    37,    37,    34,    37,    39,
      51,    31,    41,    34,    41,    51,    37,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    77,    77,    40,
      77,    40,    40,    72,    17,    35,    55,    69,    35,    69,
      69,    72,    41,    32,    75,    41,    41,     6,    40,    69,
      41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    43,    44,    44,    45,
      45,    45,    45,    46,    46,    46,    46,    47,    47,    48,
      49,    49,    50,    51,    51,    51,    51,    51,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    55,    55,
      56,    56,    57,    57,    57,    57,    58,    59,    59,    60,
      61,    61,    62,    62,    63,    63,    63,    63,    64,    64,
      65,    66,    66,    67,    68,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      75,    75,    75,    76,    76,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    79,    80,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       5,     4,     2,     3,     3,     3,     3,     3,     1,     1,
       3,     8,     3,     4,     3,     1,     1,     1,     1,     1,
       6,     4,     2,     1,     1,     2,     6,     1,     2,     3,
       8,     7,     2,     1,     2,     1,     1,     1,     1,     3,
       2,     4,     1,     4,     2,     3,     2,     1,     1,     1,
       2,     2,     2,     1,     3,     6,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     4,     1,     3,     2,     1,
       2,     2,     2,     7,    11,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     7,     7,     5
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
#line 108 "tema.y"
                                               {printf("1   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1619 "y.tab.c"
    break;

  case 3:
#line 109 "tema.y"
                                {printf("2   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1625 "y.tab.c"
    break;

  case 4:
#line 110 "tema.y"
                           {printf("3   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1631 "y.tab.c"
    break;

  case 5:
#line 111 "tema.y"
             {printf("4   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1637 "y.tab.c"
    break;

  case 6:
#line 112 "tema.y"
                      {printf("5   program corect sintactic\n"); scrieVariabileFisier();scrieFunctiiInFisier();}
#line 1643 "y.tab.c"
    break;

  case 7:
#line 117 "tema.y"
                                    { var[count_v-1].vizibilitate=strdup("global");}
#line 1649 "y.tab.c"
    break;

  case 8:
#line 118 "tema.y"
                                                       { var[count_v-1].vizibilitate=strdup("global");}
#line 1655 "y.tab.c"
    break;

  case 17:
#line 130 "tema.y"
                                                           {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),1,"main");}
#line 1661 "y.tab.c"
    break;

  case 18:
#line 131 "tema.y"
                                               {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),0,"main");}
#line 1667 "y.tab.c"
    break;

  case 19:
#line 133 "tema.y"
                                  {declarare_fara_initializare((yyvsp[-1].str),(yyvsp[0].str),0,"main");}
#line 1673 "y.tab.c"
    break;

  case 20:
#line 135 "tema.y"
                                                            {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),1,"global");}
#line 1679 "y.tab.c"
    break;

  case 21:
#line 136 "tema.y"
                                               {declarare_cu_initializare((yyvsp[-3].str),(yyvsp[-2].str),(yyvsp[0].integer),0,"global");}
#line 1685 "y.tab.c"
    break;

  case 22:
#line 138 "tema.y"
                                   {declarare_fara_initializare((yyvsp[-1].str),(yyvsp[0].str),0,"global");}
#line 1691 "y.tab.c"
    break;

  case 23:
#line 145 "tema.y"
                                   {(yyval.integer) = (yyvsp[-2].integer) + (yyvsp[0].integer);}
#line 1697 "y.tab.c"
    break;

  case 24:
#line 146 "tema.y"
                                   {(yyval.integer) = (yyvsp[-2].integer) - (yyvsp[0].integer);}
#line 1703 "y.tab.c"
    break;

  case 25:
#line 147 "tema.y"
                                  {(yyval.integer) = (yyvsp[-2].integer) * (yyvsp[0].integer);}
#line 1709 "y.tab.c"
    break;

  case 26:
#line 148 "tema.y"
                                 {(yyval.integer) = (yyvsp[-2].integer) / (yyvsp[0].integer);}
#line 1715 "y.tab.c"
    break;

  case 27:
#line 149 "tema.y"
                           {(yyval.integer) = (yyvsp[-1].integer);}
#line 1721 "y.tab.c"
    break;

  case 28:
#line 150 "tema.y"
              {(yyval.integer)=get_valoare_dupa_nume((yyvsp[0].str));}
#line 1727 "y.tab.c"
    break;

  case 29:
#line 151 "tema.y"
                  {(yyval.integer) = (yyvsp[0].integer);}
#line 1733 "y.tab.c"
    break;

  case 40:
#line 168 "tema.y"
                                          {printf("%s %d\n",(yyvsp[-3].str),(yyvsp[-1].integer));}
#line 1739 "y.tab.c"
    break;

  case 41:
#line 169 "tema.y"
                             {printf("%s\n",(yyvsp[-1].str));}
#line 1745 "y.tab.c"
    break;

  case 46:
#line 179 "tema.y"
                                                         {if(clasa_deja_definita((yyvsp[-4].str))==-1){
                                                                creeaza_clasa((yyvsp[-4].str));
                                                                }
                                                        else{
                                                               error_decl_clasa((yyvsp[-4].str)); 
                                                        }
                                                }
#line 1757 "y.tab.c"
    break;

  case 49:
#line 191 "tema.y"
                             { if(variabila_class_deja_declarata((yyvsp[-1].str),"class")==-1){
                                   declarare_variabila_class((yyvsp[-2].str),(yyvsp[-1].str),"class");   
                                }
                                else{
                                        error_decl((yyvsp[-1].str));
                                }
                        }
#line 1769 "y.tab.c"
    break;

  case 50:
#line 200 "tema.y"
                                                                    { if(functie_deja_declarata((yyvsp[-7].str),(yyvsp[-6].str),aux)==0){ creaza_functie((yyvsp[-7].str),(yyvsp[-6].str),aux);} else {count_aux=0;mesaj_functie_existenta((yyvsp[-6].str)); } }
#line 1775 "y.tab.c"
    break;

  case 51:
#line 201 "tema.y"
                                                        {if(functie_deja_declarata((yyvsp[-6].str),(yyvsp[-5].str),empty_struct)==0){ creaza_functie((yyvsp[-6].str),(yyvsp[-5].str),empty_struct);} else {count_aux=0;mesaj_functie_existenta((yyvsp[-5].str)); } }
#line 1781 "y.tab.c"
    break;

  case 54:
#line 206 "tema.y"
                              {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); var[count_v-1].vizibilitate=strdup(count_str);}
#line 1787 "y.tab.c"
    break;

  case 60:
#line 215 "tema.y"
              { set_parametrii_functie((yyvsp[-1].str),(yyvsp[0].str),aux);}
#line 1793 "y.tab.c"
    break;

  case 61:
#line 217 "tema.y"
                                       {char count_str[100]; snprintf(count_str,100,"functie-%d",count_f); asignare_exista_variabila((yyvsp[-3].str),count_str,(yyvsp[-1].integer)); }
#line 1799 "y.tab.c"
    break;

  case 70:
#line 233 "tema.y"
                           {var[count_v-1].vizibilitate=strdup("main");}
#line 1805 "y.tab.c"
    break;


#line 1809 "y.tab.c"

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
#line 296 "tema.y"

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
void asignare_exista_variabila(char* id , char* viziblitate ,int valoare)
{
        char str_valoare[50];
        snprintf(str_valoare,50,"%d",valoare);
        for (int i = 0; i < count_v; i++){
                if(strcmp(var[i].id,id)==0) // acelasi nume
                  if(strcmp(var[i].vizibilitate,"global")==0) strcpy(var[i].valoare,str_valoare);
                  else
                   if(strcmp(var[i].vizibilitate,viziblitate)==0)  strcpy(var[i].valoare,str_valoare);
                else{ printf("variabila trebuie declarata inainte\n"); exit(0);}
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
      for(int i=0;i<count_v;i++){
    
       fprintf(var_fisier_ptr,"%s  %s  %s  %s  %d  %d\n", var[i].tip, var[i].id,var[i].valoare, var[i].vizibilitate,var[i].constante,var[i].dimensiune);
       //modificari nr spatii => modifica si in get valoare dupa nume
     
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
}

void error_decl_clasa(char* nume){
        char error_msg[250];
        sprintf(error_msg, "Clasa %s este deja declarata", nume);
        yyerror(error_msg); 
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
        clase[nr_clase-1].class_var[clase[nr_clase-1].nr_variabile].tip=strdup(tip);
        clase[nr_clase-1].class_var[clase[nr_clase-1].nr_variabile].id=strdup(nume);
        char buf[20];
        sprintf(buf,"%s-%d",vizibilitate,nr_clase);
        declarare_fara_initializare(tip,nume, 0, buf);
        clase[nr_clase-1].nr_variabile++;
}

int clasa_deja_definita(char* nume){
        for(int i=0;i<nr_clase;i++){
                if(strcmp(clase[i].tip,nume)==0){
                        return i;
                }
        }
        return -1;
}
