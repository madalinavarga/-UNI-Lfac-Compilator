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
    LESS = 274,
    GREATER = 275,
    PLUS = 276,
    PROD = 277,
    DIV = 278,
    ID = 279,
    NR_INT = 280,
    NR_REAL = 281,
    BOOLEAN = 282,
    CHAR = 283,
    STRING = 284,
    MINUS = 285
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
#define LESS 274
#define GREATER 275
#define PLUS 276
#define PROD 277
#define DIV 278
#define ID 279
#define NR_INT 280
#define NR_REAL 281
#define BOOLEAN 282
#define CHAR 283
#define STRING 284
#define MINUS 285

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

#line 127 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
