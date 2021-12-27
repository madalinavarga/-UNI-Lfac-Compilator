/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    MAIN = 259,
    RETURN = 260,
    ASSIGN = 261,
    CONST = 262,
    EXIT = 263,
    CLASS = 264,
    TIP = 265,
    DACA = 266,
    ALTFEL = 267,
    PENTRU = 268,
    CATtIMP = 269,
    GEQ = 270,
    EQ = 271,
    LEQ = 272,
    NEQ = 273,
    OR = 274,
    AND = 275,
    LESS = 276,
    GREATER = 277,
    PLUS = 278,
    PROD = 279,
    DIV = 280,
    INCR = 281,
    DECR = 282,
    PLSEQ = 283,
    MINEQ = 284,
    MULEQ = 285,
    DIVEQ = 286,
    ID = 287,
    NR_INT = 288,
    NR_REAL = 289,
    BOOLEAN = 290,
    CHAR = 291,
    STRING = 292,
    MINUS = 293
  };
#endif
/* Tokens.  */
#define PRINT 258
#define MAIN 259
#define RETURN 260
#define ASSIGN 261
#define CONST 262
#define EXIT 263
#define CLASS 264
#define TIP 265
#define DACA 266
#define ALTFEL 267
#define PENTRU 268
#define CATtIMP 269
#define GEQ 270
#define EQ 271
#define LEQ 272
#define NEQ 273
#define OR 274
#define AND 275
#define LESS 276
#define GREATER 277
#define PLUS 278
#define PROD 279
#define DIV 280
#define INCR 281
#define DECR 282
#define PLSEQ 283
#define MINEQ 284
#define MULEQ 285
#define DIVEQ 286
#define ID 287
#define NR_INT 288
#define NR_REAL 289
#define BOOLEAN 290
#define CHAR 291
#define STRING 292
#define MINUS 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "proiect.y"

int int_val;
float real_val;
char* bool_val;
char char_val;
char* string_val;
char* nume_var;
char* tip;

#line 143 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
