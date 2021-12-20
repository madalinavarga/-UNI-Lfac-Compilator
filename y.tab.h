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
    TIP = 263,
    DACA = 264,
    ALTFEL = 265,
    PENTRU = 266,
    CATtIMP = 267,
    GEQ = 268,
    EQ = 269,
    LEQ = 270,
    NEQ = 271,
    LESS = 272,
    GREATER = 273,
    PLUS = 274,
    PROD = 275,
    DIV = 276,
    ID = 277,
    NR_INT = 278,
    NR_REAL = 279,
    BOOLEAN = 280,
    CHAR = 281,
    STRING = 282,
    MINUS = 283
  };
#endif
/* Tokens.  */
#define PRINT 258
#define MAIN 259
#define RETURN 260
#define ASSIGN 261
#define CONST 262
#define TIP 263
#define DACA 264
#define ALTFEL 265
#define PENTRU 266
#define CATtIMP 267
#define GEQ 268
#define EQ 269
#define LEQ 270
#define NEQ 271
#define LESS 272
#define GREATER 273
#define PLUS 274
#define PROD 275
#define DIV 276
#define ID 277
#define NR_INT 278
#define NR_REAL 279
#define BOOLEAN 280
#define CHAR 281
#define STRING 282
#define MINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "proiect.y"

int int_val;
float real_val;
char* bool_val;
char char_val;
char* string_val;
char* nume_var;
char* tip;

#line 123 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
