/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     COLON = 258,
     SEMICOLON = 259,
     LEFTBRACKETS = 260,
     RIGHTBRACKETS = 261,
     EQUAL = 262,
     ASSIGN = 263,
     LEFTPARENTHESES = 264,
     RIGHTPARENTHESES = 265,
     COMMA = 266,
     PERIOD = 267,
     IN = 268,
     NOT = 269,
     N_EQUAL = 270,
     REMAINDER = 271,
     CONSTANT = 272,
     INTEGER = 273,
     BOOLEAN = 274,
     CHARACTER = 275,
     STRING = 276,
     FLOAT = 277,
     IF = 278,
     ELSE = 279,
     TRUE = 280,
     FALSE = 281,
     WHILE = 282,
     FOR = 283,
     LOOP = 284,
     DO = 285,
     THEN = 286,
     PROGRAM = 287,
     PROCEDURE = 288,
     RETURN = 289,
     DECLARE = 290,
     BEG = 291,
     END = 292,
     PRINT = 293,
     PRINTLN = 294,
     READ = 295,
     num_real = 296,
     num_integer = 297,
     bool_val = 298,
     string_val = 299,
     identifier = 300,
     OR = 301,
     AND = 302,
     GT = 303,
     GE = 304,
     LE = 305,
     LT = 306,
     MINUS = 307,
     PLUS = 308,
     SLASH = 309,
     MULT = 310,
     UMINUS = 311
   };
#endif
/* Tokens.  */
#define COLON 258
#define SEMICOLON 259
#define LEFTBRACKETS 260
#define RIGHTBRACKETS 261
#define EQUAL 262
#define ASSIGN 263
#define LEFTPARENTHESES 264
#define RIGHTPARENTHESES 265
#define COMMA 266
#define PERIOD 267
#define IN 268
#define NOT 269
#define N_EQUAL 270
#define REMAINDER 271
#define CONSTANT 272
#define INTEGER 273
#define BOOLEAN 274
#define CHARACTER 275
#define STRING 276
#define FLOAT 277
#define IF 278
#define ELSE 279
#define TRUE 280
#define FALSE 281
#define WHILE 282
#define FOR 283
#define LOOP 284
#define DO 285
#define THEN 286
#define PROGRAM 287
#define PROCEDURE 288
#define RETURN 289
#define DECLARE 290
#define BEG 291
#define END 292
#define PRINT 293
#define PRINTLN 294
#define READ 295
#define num_real 296
#define num_integer 297
#define bool_val 298
#define string_val 299
#define identifier 300
#define OR 301
#define AND 302
#define GT 303
#define GE 304
#define LE 305
#define LT 306
#define MINUS 307
#define PLUS 308
#define SLASH 309
#define MULT 310
#define UMINUS 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 29 "parser.y"
{
    int     int_val;
    string *stringVal;
    float   real_val;
    bool boolean_val;
    Vartype *var;
    int     dtype;
}
/* Line 1529 of yacc.c.  */
#line 170 "y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

