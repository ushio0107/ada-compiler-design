/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <iostream>
#include <string>
#include "symtype.hpp"
#include "symbol.hpp"
#include "codegeneration.hpp"
#include "lex.yy.cpp"


#define Trace(t) if (Opt_P) cout << "TRACE***\t" << t << "\t***"<< endl;
int Opt_P = 0; 
int scope = 0; //scope 1 mean global
int level = 0;

extern int linenum;
extern FILE *yyin;

string filename;
ofstream fout;

bool declaring = false;
int yyerror(string msg);
vector<SymbolTable>  symtable_list;
vector<vector<Vartype>> functions;
bool haveReturn = false;
bool cane = false;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 245 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 258 "y.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   627

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  224

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    17,    19,    22,    25,    28,
      31,    33,    35,    37,    39,    42,    43,    44,    52,    53,
      63,    64,    72,    73,    79,    84,    87,    95,    97,    99,
     101,   103,   105,   107,   109,   111,   113,   117,   118,   122,
     124,   128,   129,   130,   145,   148,   149,   151,   152,   156,
     158,   160,   161,   167,   168,   175,   177,   182,   184,   186,
     190,   193,   197,   201,   205,   209,   213,   217,   221,   225,
     229,   233,   237,   240,   244,   248,   250,   252,   254,   256,
     259,   261,   262,   265,   267,   270,   272,   277,   285,   286,
     291,   292,   297,   301,   304,   308,   311,   312,   323,   324,
     338,   340,   342,   343,   344,   356,   357,   358
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    -1,    -1,    59,    32,    45,    63,    36,
      60,    89,    37,    61,    37,    45,    -1,     4,    -1,    64,
      62,    -1,    67,    62,    -1,    70,    62,    -1,    76,    62,
      -1,    76,    -1,    64,    -1,    67,    -1,    70,    -1,    35,
      62,    -1,    -1,    -1,    45,     3,    17,     8,    65,    87,
      61,    -1,    -1,    45,     3,    17,     3,    71,     8,    66,
      87,    61,    -1,    -1,    45,     3,    71,     8,    68,    87,
      61,    -1,    -1,    45,     8,    69,    87,    61,    -1,    45,
       3,    71,    61,    -1,    45,    61,    -1,    45,     3,    71,
       5,    87,     6,    61,    -1,    18,    -1,    22,    -1,    19,
      -1,    21,    -1,    42,    -1,    41,    -1,    44,    -1,    25,
      -1,    26,    -1,     9,    74,    10,    -1,    -1,    74,    61,
      75,    -1,    75,    -1,    45,     3,    71,    -1,    -1,    -1,
      33,    45,    77,    73,    79,    78,    63,    36,    89,    37,
      61,    37,    45,    61,    -1,    34,    71,    -1,    -1,    81,
      -1,    -1,    81,    11,    82,    -1,    82,    -1,    87,    -1,
      -1,    45,    84,     9,    80,    10,    -1,    -1,    86,    63,
      36,    89,    37,    61,    -1,    45,    -1,    45,     5,    87,
       6,    -1,    72,    -1,    83,    -1,     9,    87,    10,    -1,
      52,    87,    -1,    87,    55,    87,    -1,    87,    54,    87,
      -1,    87,    53,    87,    -1,    87,    52,    87,    -1,    87,
      16,    87,    -1,    87,    51,    87,    -1,    87,    50,    87,
      -1,    87,     7,    87,    -1,    87,    49,    87,    -1,    87,
      48,    87,    -1,    87,    15,    87,    -1,    14,    87,    -1,
      87,    47,    87,    -1,    87,    46,    87,    -1,    93,    -1,
      97,    -1,    99,    -1,    83,    -1,    89,    88,    -1,    88,
      -1,    -1,    91,    92,    -1,    85,    -1,    92,    93,    -1,
      93,    -1,    45,     8,    87,    61,    -1,    45,     5,    87,
       6,     8,    87,    61,    -1,    -1,    39,    94,    87,    61,
      -1,    -1,    38,    95,    87,    61,    -1,    40,    45,    61,
      -1,    34,    61,    -1,    34,    87,    61,    -1,    87,    61,
      -1,    -1,    23,     9,    87,    10,    31,    96,    90,    37,
      23,    61,    -1,    -1,    23,     9,    87,    10,    31,    96,
      90,    24,    98,    90,    37,    23,    61,    -1,   100,    -1,
     103,    -1,    -1,    -1,    27,   101,     9,    87,    10,    29,
     102,    90,    37,    29,    61,    -1,    -1,    -1,    28,     9,
      45,    13,    87,   104,    12,    12,    87,    10,    29,   105,
      90,    37,    29,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    71,    64,    85,    87,    89,    91,    93,
      95,    97,    99,   101,   104,   105,   109,   108,   132,   131,
     155,   154,   183,   182,   206,   226,   246,   274,   277,   280,
     283,   287,   293,   300,   307,   314,   323,   324,   327,   329,
     331,   346,   357,   345,   383,   389,   395,   396,   399,   401,
     404,   413,   412,   440,   440,   457,   476,   488,   502,   504,
     510,   520,   531,   541,   554,   565,   576,   587,   597,   608,
     618,   628,   637,   647,   658,   670,   672,   674,   676,   679,
     681,   683,   683,   693,   695,   697,   699,   710,   724,   723,
     734,   733,   743,   748,   754,   760,   767,   772,   787,   786,
     807,   809,   817,   821,   816,   844,   858,   843
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COLON", "SEMICOLON", "LEFTBRACKETS",
  "RIGHTBRACKETS", "EQUAL", "ASSIGN", "LEFTPARENTHESES",
  "RIGHTPARENTHESES", "COMMA", "PERIOD", "IN", "NOT", "N_EQUAL",
  "REMAINDER", "CONSTANT", "INTEGER", "BOOLEAN", "CHARACTER", "STRING",
  "FLOAT", "IF", "ELSE", "TRUE", "FALSE", "WHILE", "FOR", "LOOP", "DO",
  "THEN", "PROGRAM", "PROCEDURE", "RETURN", "DECLARE", "BEG", "END",
  "PRINT", "PRINTLN", "READ", "num_real", "num_integer", "bool_val",
  "string_val", "identifier", "OR", "AND", "GT", "GE", "LE", "LT", "MINUS",
  "PLUS", "SLASH", "MULT", "UMINUS", "$accept", "program", "@1", "@2",
  "semi", "declarationsTypes", "declarations", "constant_dec", "@3", "@4",
  "var_dec", "@5", "@6", "array_dec", "data_types", "constant_exp",
  "optional_formalarg", "formal_arg", "arg", "function_dec", "@7", "@8",
  "return_type", "com_expr", "comma_separated_expressions", "function_exp",
  "func_proce_invocation", "@9", "block", "@10", "expression",
  "statements", "statements_list", "conditional_blockOrStatements", "@11",
  "simple_statements_list", "simple_statements", "@12", "@13", "ifBegin",
  "conditional_statement", "@14", "loop_statement", "while_statement",
  "@15", "@16", "for_statements", "@17", "@18", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    59,    60,    58,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    65,    64,    66,    64,
      68,    67,    69,    67,    67,    67,    70,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    77,    78,    76,    79,    79,    80,    80,    81,    81,
      82,    84,    83,    86,    85,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    89,
      89,    91,    90,    90,    92,    92,    93,    93,    94,    93,
      95,    93,    93,    93,    93,    93,    96,    97,    98,    97,
      99,    99,   101,   102,   100,   104,   105,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,    11,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     2,     0,     0,     7,     0,     9,
       0,     7,     0,     5,     4,     2,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     3,     1,
       3,     0,     0,    14,     2,     0,     1,     0,     3,     1,
       1,     0,     5,     0,     6,     1,     4,     1,     1,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     1,     1,     1,     1,     2,
       1,     0,     2,     1,     2,     1,     4,     7,     0,     4,
       0,     4,     3,     2,     3,     2,     0,    10,     0,    13,
       1,     1,     0,     0,    11,     0,     0,    16
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,    15,     0,     0,     0,     0,
      14,    11,    12,    13,    10,     3,    41,     0,     5,    22,
      25,     6,     7,     8,     9,     0,    37,     0,    27,    29,
      30,    28,     0,     0,     0,     0,     0,    34,    35,   102,
       0,     0,    90,    88,     0,    32,    31,    33,    55,     0,
      57,    78,     0,    80,     0,    75,    76,    77,   100,   101,
       0,    45,     0,    16,     0,    20,    24,    55,    58,     0,
       0,    72,     0,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,    79,
       0,     0,    39,     0,    42,     0,     0,     0,     0,     0,
      23,    59,     0,     0,     0,    94,     0,     0,    92,     0,
       0,    47,    68,    71,    65,    74,    73,    70,    69,    67,
      66,    64,    63,    62,    61,     0,     0,    36,     0,    44,
      15,    18,     0,     0,     0,     0,     0,     0,     0,    91,
      89,    56,    86,     0,    46,    49,    50,     0,    40,    38,
       0,     0,    17,    26,    21,    56,    96,     0,   105,     0,
      52,     0,     4,     0,     0,    81,   103,     0,     0,    48,
       0,    19,    83,    15,     0,     0,    81,     0,    87,     0,
       0,    98,     0,    82,    85,     0,     0,     0,     0,    81,
       0,    84,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,     0,   104,   106,    43,    54,     0,    81,    99,
       0,     0,     0,   107
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    25,    20,    10,     7,    11,   106,   161,
      12,   108,    33,    13,    32,    50,    61,   101,   102,    14,
      26,   140,   104,   153,   154,   155,    68,    82,   182,   183,
      52,    53,    54,   184,   185,   193,    55,    78,    77,   175,
      56,   199,    57,    58,    73,   186,    59,   177,   218
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -183
static const yytype_int16 yypact[] =
{
    -183,    15,    -9,  -183,   -20,    -3,   -26,    -1,   -19,    25,
    -183,   -26,   -26,   -26,   -26,  -183,  -183,    74,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,   554,    29,    31,  -183,  -183,
    -183,  -183,    37,    56,    56,    56,    78,  -183,  -183,  -183,
      90,   429,  -183,  -183,    -5,  -183,  -183,  -183,    59,    56,
    -183,     6,   148,  -183,   452,  -183,  -183,  -183,  -183,  -183,
      38,    72,    53,  -183,    56,  -183,  -183,    68,  -183,   148,
     251,   398,    56,    98,    69,  -183,   148,    56,    56,   109,
      56,    56,   106,   100,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,  -183,   109,  -183,
     115,     1,  -183,    53,  -183,   111,    56,   176,    56,    56,
    -183,  -183,   276,    56,   107,  -183,   148,   148,  -183,   202,
     148,    56,    -4,    -4,   349,   374,   398,    -4,    -4,    -4,
      -4,     8,     8,   100,   100,    84,    53,  -183,    38,  -183,
      -3,  -183,   148,   109,   148,   227,    93,   300,    56,  -183,
    -183,   119,  -183,   118,   132,  -183,   349,   102,  -183,  -183,
     112,    56,  -183,  -183,  -183,  -183,  -183,   116,   349,    56,
    -183,    56,  -183,   554,   148,    54,  -183,   138,   148,  -183,
     486,  -183,  -183,    -3,   -10,   575,    54,   147,  -183,   109,
     124,  -183,   139,   575,  -183,   128,    56,   130,   554,    54,
     109,  -183,   141,   325,   126,   520,   135,  -183,   109,   144,
     109,   109,   152,  -183,  -183,  -183,  -183,   109,    54,  -183,
     140,   151,   109,  -183
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -183,   -32,    91,  -137,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,   -60,  -183,  -183,  -183,    23,  -183,
    -183,  -183,  -183,  -183,  -183,    13,   -24,  -183,  -183,  -183,
      45,   -36,  -167,  -182,  -183,  -183,  -177,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      66,    51,   105,   160,   195,    18,   180,     8,   194,    75,
     -58,   137,    86,   -58,   191,     3,   201,   206,    99,     9,
      97,   -58,   -58,     4,    86,     5,    16,   192,    17,    18,
      51,   205,     6,    19,    62,    15,   220,   110,    60,    63,
      79,    18,    64,   139,   115,    65,   190,   118,    93,    94,
      95,    96,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,    95,    96,    80,    34,   135,    81,   -51,   138,
      35,    28,    29,   109,    30,    31,   158,   -51,    69,    70,
      71,    37,    38,   100,   149,   150,    76,    72,   152,   -53,
     -53,    27,    28,    29,    83,    30,    31,    45,    46,    74,
      47,    67,    21,    22,    23,    24,   103,   113,    49,   107,
     162,   163,   164,    18,   114,   121,    86,   112,   136,   141,
     148,   157,   116,   117,   166,   119,   120,   169,   170,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   181,   171,    99,   176,   188,   172,   173,    51,
     187,   142,    18,   144,   145,    84,    51,   197,   147,   196,
     198,   159,   200,    85,    86,   202,   156,   204,   207,    99,
     208,   210,   212,   214,    51,   217,   213,   221,   215,   216,
     222,    51,   143,    84,   179,   219,     0,     0,     0,     0,
     223,    85,    86,   168,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,     0,     0,   174,     0,   151,    84,
       0,     0,     0,     0,   178,     0,   156,    85,    86,     0,
       0,     0,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,     0,   165,    84,     0,     0,     0,     0,     0,
       0,   203,    85,    86,     0,     0,     0,     0,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    84,     0,
       0,   111,     0,     0,     0,     0,    85,    86,     0,     0,
       0,     0,     0,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    84,     0,     0,   146,     0,     0,     0,
       0,    85,    86,     0,     0,     0,     0,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    84,     0,     0,
     167,     0,     0,     0,     0,    85,    86,     0,     0,     0,
       0,     0,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    84,     0,     0,   209,     0,     0,     0,     0,
      85,    86,     0,     0,     0,     0,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    84,     0,     0,     0,
       0,     0,     0,     0,    85,    86,     0,     0,     0,     0,
       0,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    84,     0,     0,     0,     0,     0,     0,     0,    85,
      86,     0,     0,     0,     0,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    84,     0,     0,     0,     0,
       0,     0,     0,    85,    86,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,     0,    18,     0,     0,     0,     0,    34,     0,
       0,     0,     0,    35,     0,     0,    89,    90,    91,    92,
      93,    94,    95,    96,    37,    38,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,    35,     0,     0,     0,
      45,    46,     0,    47,    67,    36,     0,    37,    38,    39,
      40,    49,     0,     0,     0,     0,    41,     0,     0,    98,
      42,    43,    44,    45,    46,    34,    47,    48,     0,     0,
      35,     0,     0,     0,    49,     0,     0,     0,     0,    36,
       0,    37,    38,    39,    40,     0,     0,     0,     0,     0,
      41,     0,     0,   189,    42,    43,    44,    45,    46,    34,
      47,    48,     0,     0,    35,     0,     0,     0,    49,     0,
       0,     0,     0,    36,     0,    37,    38,    39,    40,     0,
       0,     0,     0,     0,    41,     0,     0,   211,    42,    43,
      44,    45,    46,    34,    47,    48,     0,     0,    35,     0,
       0,     0,    49,     0,     0,     0,     0,    36,     0,    37,
      38,    39,    40,     0,    34,     0,     0,     0,    41,    35,
       0,     0,    42,    43,    44,    45,    46,     0,    47,    48,
      37,    38,     0,     0,     0,     0,    49,     0,     0,    41,
       0,     0,     0,    42,    43,    44,    45,    46,     0,    47,
      48,     0,     0,     0,     0,     0,     0,    49
};

static const yytype_int16 yycheck[] =
{
      32,    25,    62,   140,   186,     4,   173,    33,   185,    41,
       4,    10,    16,     7,    24,     0,   193,   199,    54,    45,
      52,    15,    16,    32,    16,    45,    45,    37,     3,     4,
      54,   198,    35,     8,     3,    36,   218,    69,     9,     8,
      45,     4,     5,   103,    76,     8,   183,    79,    52,    53,
      54,    55,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    54,    55,     5,     9,    98,     8,     9,   101,
      14,    18,    19,     5,    21,    22,   136,     9,    33,    34,
      35,    25,    26,    45,   116,   117,    41,     9,   120,    35,
      36,    17,    18,    19,    49,    21,    22,    41,    42,     9,
      44,    45,    11,    12,    13,    14,    34,     9,    52,    64,
     142,   143,   144,     4,    45,     9,    16,    72,     3,     8,
      13,    37,    77,    78,    31,    80,    81,     8,    10,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   174,    11,   180,    29,   178,    45,    36,   173,
      12,   106,     4,   108,   109,     7,   180,   189,   113,    12,
      36,   138,    23,    15,    16,    37,   121,    37,   200,   205,
      29,    45,    37,    29,   198,    23,   208,    37,   210,   211,
      29,   205,     6,     7,   171,   217,    -1,    -1,    -1,    -1,
     222,    15,    16,   148,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,   161,    -1,     6,     7,
      -1,    -1,    -1,    -1,   169,    -1,   171,    15,    16,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    15,    16,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     7,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     7,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    15,    16,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      15,    16,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     7,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    25,    26,    -1,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      41,    42,    -1,    44,    45,    23,    -1,    25,    26,    27,
      28,    52,    -1,    -1,    -1,    -1,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,     9,    44,    45,    -1,    -1,
      14,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    23,
      -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,
      34,    -1,    -1,    37,    38,    39,    40,    41,    42,     9,
      44,    45,    -1,    -1,    14,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    23,    -1,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    34,    -1,    -1,    37,    38,    39,
      40,    41,    42,     9,    44,    45,    -1,    -1,    14,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    23,    -1,    25,
      26,    27,    28,    -1,     9,    -1,    -1,    -1,    34,    14,
      -1,    -1,    38,    39,    40,    41,    42,    -1,    44,    45,
      25,    26,    -1,    -1,    -1,    -1,    52,    -1,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    -1,    44,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,    59,     0,    32,    45,    35,    63,    33,    45,
      62,    64,    67,    70,    76,    36,    45,     3,     4,     8,
      61,    62,    62,    62,    62,    60,    77,    17,    18,    19,
      21,    22,    71,    69,     9,    14,    23,    25,    26,    27,
      28,    34,    38,    39,    40,    41,    42,    44,    45,    52,
      72,    83,    87,    88,    89,    93,    97,    99,   100,   103,
       9,    73,     3,     8,     5,     8,    61,    45,    83,    87,
      87,    87,     9,   101,     9,    61,    87,    95,    94,    45,
       5,     8,    84,    87,     7,    15,    16,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    61,    37,    88,
      45,    74,    75,    34,    79,    71,    65,    87,    68,     5,
      61,    10,    87,     9,    45,    61,    87,    87,    61,    87,
      87,     9,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    61,     3,    10,    61,    71,
      78,     8,    87,     6,    87,    87,    10,    87,    13,    61,
      61,     6,    61,    80,    81,    82,    87,    37,    71,    75,
      63,    66,    61,    61,    61,     6,    31,    10,    87,     8,
      10,    11,    45,    36,    87,    96,    29,   104,    87,    82,
      89,    61,    85,    86,    90,    91,   102,    12,    61,    37,
      63,    24,    37,    92,    93,    90,    12,    61,    36,    98,
      23,    93,    37,    87,    37,    89,    90,    61,    29,    10,
      45,    37,    37,    61,    29,    61,    61,    23,   105,    61,
      90,    37,    29,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
#line 64 "parser.y"
    {   
                    CG_OutputAss();
                    symtable_list.push_back(SymbolTable());
                    CG_initBegin();

                }
    break;

  case 3:
#line 71 "parser.y"
    {
                    CG_progBeg();
                    level = 0;
                }
    break;

  case 4:
#line 76 "parser.y"
    {
                    Trace("Program");
                    if(Opt_P) symtable_dump(symtable_list, 0);
                    if(symtable_list.size() > 1) symtable_list.pop_back(); 
                    CG_progEnd(); 
                    CG_initEnd();                        
                }
    break;

  case 16:
#line 109 "parser.y"
    {
                    declaring = true;
                }
    break;

  case 17:
#line 113 "parser.y"
    {
                    Trace("Constant Declaration (no type)");
                    if((yyvsp[(6) - (7)].var)->var_kind != KIND_CONSTANT && (yyvsp[(6) - (7)].var)->var_kind != KIND_VARIABLE) yyerror("expression's return value is no a constant.");
                    (yyvsp[(6) - (7)].var)->var_kind = KIND_CONSTANT;
                    (yyvsp[(6) - (7)].var)->declar = true;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*(yyvsp[(1) - (7)].stringVal), *(yyvsp[(6) - (7)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_Localinsert(*$1, *$6) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*(yyvsp[(1) - (7)].stringVal), *(yyvsp[(6) - (7)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    //if(symbolTable.symbol_insert(*$1) == -1) yyerror("id redefined (constant declaration)");
                    declaring = false;
                }
    break;

  case 18:
#line 132 "parser.y"
    {
                    declaring = true;
                }
    break;

  case 19:
#line 136 "parser.y"
    {
                    Trace("Constant Declaration (with) type)\n");
                    if((yyvsp[(8) - (9)].var)->var_kind != KIND_CONSTANT && (yyvsp[(8) - (9)].var)->var_kind != KIND_VARIABLE) yyerror("expression's return value is no a constant.");
                    (yyvsp[(8) - (9)].var)->var_kind = KIND_CONSTANT;
                    (yyvsp[(8) - (9)].var)->type = (yyvsp[(5) - (9)].dtype);
                    (yyvsp[(8) - (9)].var)->declar = true;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*(yyvsp[(1) - (9)].stringVal), *(yyvsp[(8) - (9)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *$8) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*(yyvsp[(1) - (9)].stringVal), *(yyvsp[(8) - (9)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    declaring = false;
                }
    break;

  case 20:
#line 155 "parser.y"
    {
                    declaring = true;
                    cane = true;
                }
    break;

  case 21:
#line 160 "parser.y"
    {
                    Trace("Variable declaration (with type and expr)");
                    if((yyvsp[(6) - (7)].var)->var_kind != KIND_CONSTANT && (yyvsp[(6) - (7)].var)->var_kind != KIND_VARIABLE) yyerror("expr is not a constant value");
                    if((yyvsp[(3) - (7)].dtype) != (yyvsp[(6) - (7)].var)->type) yyerror("The variable declaration data type is not the data type of the expr");
                    (yyvsp[(6) - (7)].var)->var_kind = KIND_VARIABLE;
                    (yyvsp[(6) - (7)].var)->type = (yyvsp[(3) - (7)].dtype);
                    (yyvsp[(6) - (7)].var)->declar = true;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*(yyvsp[(1) - (7)].stringVal), *(yyvsp[(6) - (7)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *$5) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*(yyvsp[(1) - (7)].stringVal), *(yyvsp[(6) - (7)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    Vartype *var = symtableList_lookup(*(yyvsp[(1) - (7)].stringVal), symtable_list, level);
                    CG_VarDeclar(*(yyvsp[(1) - (7)].stringVal), *var);
                    declaring = false;
                    cane = false;
                }
    break;

  case 22:
#line 183 "parser.y"
    {
                    declaring = true;
                }
    break;

  case 23:
#line 187 "parser.y"
    {
                    Trace("Variable declaration (with expr)");
                    if((yyvsp[(4) - (5)].var)->var_kind != KIND_CONSTANT && (yyvsp[(4) - (5)].var)->var_kind != KIND_VARIABLE) yyerror("expr is not a constant value");
                    (yyvsp[(4) - (5)].var)->var_kind = KIND_VARIABLE;
                    (yyvsp[(4) - (5)].var)->declar = true;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*(yyvsp[(1) - (5)].stringVal), *(yyvsp[(4) - (5)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *$3) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*(yyvsp[(1) - (5)].stringVal), *(yyvsp[(4) - (5)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    Vartype *var = symtableList_lookup(*(yyvsp[(1) - (5)].stringVal), symtable_list, level);
                    if(level == 0) CG_VarDeclar(*(yyvsp[(1) - (5)].stringVal), *var);
                    declaring = false;               
                }
    break;

  case 24:
#line 207 "parser.y"
    {
                    Trace("Variable declaration (with type)");
                    Vartype *new_var = new Vartype();
                    new_var->var_kind = KIND_VARIABLE;
                    new_var->type = (yyvsp[(3) - (4)].dtype);
                    //cout << "scope::" << scope << endl;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*(yyvsp[(1) - (4)].stringVal), *new_var) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *new_var) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*(yyvsp[(1) - (4)].stringVal), *new_var) == -1) yyerror("id redefined (constant declaration)");
                    }
                    Vartype *var = symtableList_lookup(*(yyvsp[(1) - (4)].stringVal), symtable_list, level);
                    if(level == 0) CG_VarDeclar(*(yyvsp[(1) - (4)].stringVal), *var);       
                }
    break;

  case 25:
#line 227 "parser.y"
    {
                    Trace("Variable declaration (no type and expr)");
                    Vartype *new_var = new Vartype();
                    new_var->var_kind = KIND_VARIABLE;
                    new_var->type = TYPE_INT;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*(yyvsp[(1) - (2)].stringVal), *new_var) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *new_var) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*(yyvsp[(1) - (2)].stringVal), *new_var) == -1) yyerror("id redefined (constant declaration)");
                    }
                    Vartype *var = symtableList_lookup(*(yyvsp[(1) - (2)].stringVal), symtable_list, level);
                    //cout << "var global" << var->global << endl;
                    if(level == 0) CG_VarDeclar(*(yyvsp[(1) - (2)].stringVal), *var);     
                }
    break;

  case 26:
#line 247 "parser.y"
    {
                    Trace("Array declaration");
                    if((yyvsp[(5) - (7)].var)->var_kind != KIND_CONSTANT && (yyvsp[(5) - (7)].var)->var_kind != KIND_VARIABLE) yyerror("the size of array is not a constant");
                    if((yyvsp[(5) - (7)].var)->type != TYPE_INT) yyerror("the size of array is not a int");
                    if((yyvsp[(5) - (7)].var)->var_val.int_val < 1) yyerror("the size of array can't be less than 1");
                    Vartype *new_sym = new Vartype();
                    new_sym->var_kind = KIND_VARIABLE;
                    new_sym->type = TYPE_ARRAY;
                    new_sym->var_val.array_val = vector<Vartype>((yyvsp[(5) - (7)].var)->var_val.int_val);
                    for(int i = 0; i < (yyvsp[(5) - (7)].var)->var_val.int_val; ++i)
                    {
                        new_sym->var_val.array_val[i].arr_index = -1;
                        new_sym->var_val.array_val[i].type = (yyvsp[(3) - (7)].dtype);
                        new_sym->var_val.array_val[i].var_kind = KIND_VARIABLE;
                    }
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*(yyvsp[(1) - (7)].stringVal), *(yyvsp[(5) - (7)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *$5) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*(yyvsp[(1) - (7)].stringVal), *(yyvsp[(5) - (7)].var)) == -1) yyerror("id redefined (constant declaration)");
                    }
                    // no CG
                }
    break;

  case 27:
#line 275 "parser.y"
    {(yyval.dtype) = TYPE_INT;}
    break;

  case 28:
#line 278 "parser.y"
    {(yyval.dtype) = TYPE_REAL;}
    break;

  case 29:
#line 281 "parser.y"
    {(yyval.dtype) = TYPE_BOOLEAN;}
    break;

  case 30:
#line 284 "parser.y"
    {(yyval.dtype) = TYPE_STRING;}
    break;

  case 31:
#line 288 "parser.y"
    {
                    Trace("num_int");
                    (yyval.var) = new_constantInsert(TYPE_INT, &(yyvsp[(1) - (1)].int_val));
                }
    break;

  case 32:
#line 294 "parser.y"
    {
                    Trace("num_real");
                    float val = (yyvsp[(1) - (1)].real_val);
                    (yyval.var) = new_constantInsert(TYPE_REAL, &val);
                }
    break;

  case 33:
#line 301 "parser.y"
    {
                    Trace("string_val");
                    (yyval.var) = new_constantInsert(TYPE_STRING, (yyvsp[(1) - (1)].stringVal));
                    free((yyvsp[(1) - (1)].stringVal));
                }
    break;

  case 34:
#line 308 "parser.y"
    {
                    Trace("boolean_true");
                    bool val = true;
                    (yyval.var) = new_constantInsert(TYPE_BOOLEAN, &val);
                }
    break;

  case 35:
#line 315 "parser.y"
    {
                    Trace("boolean_false");
                    bool val = false;
                    (yyval.var) = new_constantInsert(TYPE_BOOLEAN, &val);
                }
    break;

  case 40:
#line 332 "parser.y"
    {
            Trace("ARG");
            Vartype *arg = new Vartype();
            arg->var_kind = KIND_VARIABLE;
            arg->type = (yyvsp[(3) - (3)].dtype);
            //cout << "scope: " << scope << endl;
            //cout << "sym_list size: " << symtable_list.size() << endl;
            //if(symtable_list[scope].sym_insert(*$1, *arg) == -1) yyerror("id redefined (arg)");
            if(symtable_list[1].sym_Localinsert(*(yyvsp[(1) - (3)].stringVal), *arg) == -1) yyerror("id redefined (arg)");
            symtable_list[0].addProceArg(*(yyvsp[(1) - (3)].stringVal), *arg);
        }
    break;

  case 41:
#line 346 "parser.y"
    {
                    Vartype *func = new Vartype();
                    //cout << "scope: " << scope << endl;
                    func->var_kind = KIND_FUNCTION;
                    if(symtable_list[0].sym_Globalinsert(*(yyvsp[(2) - (2)].stringVal), *func) == -1 ) yyerror("id redefined (function declaration)");
                    symtable_list.push_back(SymbolTable());
                    ++scope;
                    ++level;
                    //cout << symtable_list.size() << endl;
                }
    break;

  case 42:
#line 357 "parser.y"
    {
                    Vartype *func = symtableList_lookup(*(yyvsp[(2) - (5)].stringVal), symtable_list, level - 1);
                    CG_ProceFuncBegin(*func);
                }
    break;

  case 43:
#line 362 "parser.y"
    {
                    if(!haveReturn) 
                    {
                        symtable_list[0].changeKind(*(yyvsp[(2) - (14)].stringVal), KIND_PROCEDURE);
                        CG_ProceFuncEnd(KIND_PROCEDURE);
                        Trace("Procedure declar");
                    }
                    else 
                    {
                        CG_ProceFuncEnd(KIND_FUNCTION);
                        Trace("Function declar");
                    }

                    if(Opt_P) symtable_dump(symtable_list, scope);
                    if(symtable_list.size() > 1) symtable_list.pop_back(); 
                    haveReturn = false;
                    --level;
                    //--scope;
                }
    break;

  case 44:
#line 384 "parser.y"
    {
                    symtable_list[0].setProceType((yyvsp[(2) - (2)].dtype));
                    haveReturn = true;
                }
    break;

  case 45:
#line 389 "parser.y"
    {
                    symtable_list[0].setProceType(TYPE_VOID);
                    haveReturn = false;
                }
    break;

  case 50:
#line 405 "parser.y"
    {
                    Trace("function_exp");
                    //cout << $1->id << " "<< $1->type << endl;
                    
                    functions[functions.size() - 1].push_back(*(yyvsp[(1) - (1)].var));
                }
    break;

  case 51:
#line 413 "parser.y"
    {
                            Trace("function invocation");
                            //cout << *$1 << endl;
                            functions.push_back(vector<Vartype>());
                        }
    break;

  case 52:
#line 419 "parser.y"
    {
                            //cout << "OK : psss"<< endl;
                            Vartype *func = symtableList_lookup(*(yyvsp[(1) - (5)].stringVal), symtable_list, level);
                            if(func == NULL) yyerror("haven't declare before invocate");
                            if(func->var_kind != KIND_FUNCTION && func->var_kind != KIND_PROCEDURE) yyerror("This is not a function or procedure");
                            vector<Vartype> p = func->var_val.funcArg;
                            if(p.size() != functions[functions.size() - 1].size()) yyerror("the size of the function parameter is different from the function declaration");
                            for(int i = 0; i < p.size(); ++i)
                            {
                                //cout << "type" << p[i].type<< endl;
                                //cout << "type2" << functions[functions.size() - 1].at(i).type <<endl;                                
                                if(p[i].type != functions[functions.size() - 1].at(i).type) yyerror("the type of the function parameter is different from the function declaration");
                            }
                            (yyval.var) = func;

                            CG_ProceFuncInvocation(*func);
                            functions.pop_back();
                        }
    break;

  case 53:
#line 440 "parser.y"
    {
            Trace("Block");
            ++scope;
            ++level;
            //cout << "level" << level << endl;
            symtable_list.push_back(SymbolTable()); 
        }
    break;

  case 54:
#line 449 "parser.y"
    {
            --level;
            if(Opt_P) symtable_dump(symtable_list, scope);
            if(symtable_list.size() > 1) symtable_list.pop_back();
            //--scope;              
        }
    break;

  case 55:
#line 458 "parser.y"
    {
                    Trace("expr: id");
                    //cout << *$1 << endl;
                    //cout << "level"<<level <<endl;
                    Vartype *expr = symtableList_lookup(*(yyvsp[(1) - (1)].stringVal), symtable_list, level);   
                    //cout << "level" << level <<endl;
                    //cout << *$1 << endl;                 
                    if(expr == NULL) yyerror("haven't declare before invocate");
                    (yyval.var) = expr;

                    if(!declaring) 
                    {
                        if(expr->var_kind == KIND_CONSTANT) CG_ExprConst(*expr);
                        else CG_ExprVar(*expr);
                    }
                    free((yyvsp[(1) - (1)].stringVal));
                }
    break;

  case 56:
#line 477 "parser.y"
    {  
                    Trace("expr: array type");
                    Vartype *arr = symtableList_lookup(*(yyvsp[(1) - (4)].stringVal), symtable_list, level);
                    if(arr == NULL) yyerror("undeclared identifier");
                    if(arr->var_kind != KIND_VARIABLE) yyerror("not a variable");
                    if(arr->type != TYPE_ARRAY) yyerror("not array type");
                    if((yyvsp[(3) - (4)].var)->type != TYPE_INT) yyerror("invalid index");
                    if((yyvsp[(3) - (4)].var)->var_val.int_val >= arr->var_val.array_val.size() || (yyvsp[(3) - (4)].var)->var_val.int_val < 0) yyerror("index out of range");
                    (yyval.var) = new Vartype(arr->var_val.array_val[(yyvsp[(3) - (4)].var)->var_val.int_val]);
                }
    break;

  case 57:
#line 489 "parser.y"
    {
                    Trace("constant_exp");
                    
                    if(declaring == true && cane == true && level != 0)
                    {
                    }
                    else if(!declaring) 
                    {
                        CG_ExprConst(*(yyvsp[(1) - (1)].var));
                    }
                    
                }
    break;

  case 59:
#line 505 "parser.y"
    {
                    Trace("(expr)");
                    (yyval.var) = (yyvsp[(2) - (3)].var);
                }
    break;

  case 60:
#line 511 "parser.y"
    {
                Trace("-expression");
                if((yyvsp[(2) - (2)].var)->type != TYPE_INT && (yyvsp[(2) - (2)].var)->type != TYPE_REAL) yyerror("The expr must be a int or real");
                if((yyvsp[(2) - (2)].var)->var_kind == KIND_PROCEDURE) yyerror("a procedure can't be a factor");

                (yyval.var) = new_variable(KIND_VARIABLE, (yyvsp[(2) - (2)].var)->type);
                CG_ExprArith('n');                
                }
    break;

  case 61:
#line 521 "parser.y"
    {
                Trace("expression * expression");
                // this mean if expr1 = string/boolean, expr2 = string/boolean, their type must be the same, however, int or real is allowed to be expr1 or expr2 at the same time.
                if((((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) || ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) && ((yyvsp[(1) - (3)].var)->type != (yyvsp[(3) - (3)].var)->type)) yyerror("expr must be a int or real"); 
                if((yyvsp[(1) - (3)].var)->type == TYPE_REAL || (yyvsp[(3) - (3)].var)->type == TYPE_REAL) (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '*', KIND_VARIABLE, TYPE_REAL);
                else (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '*', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('*');
                }
    break;

  case 62:
#line 532 "parser.y"
    {
                Trace("expression / expression");
                if((((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) || ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) && ((yyvsp[(1) - (3)].var)->type != (yyvsp[(3) - (3)].var)->type)) yyerror("expr must be a int or real"); 
                if((yyvsp[(1) - (3)].var)->type == TYPE_REAL || (yyvsp[(3) - (3)].var)->type == TYPE_REAL) (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '/', KIND_VARIABLE, TYPE_REAL);
                else (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '/', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('/');
                }
    break;

  case 63:
#line 542 "parser.y"
    {
                Trace("expression + expression");
                if((((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) || ((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL)) && ((yyvsp[(1) - (3)].var)->type != (yyvsp[(3) - (3)].var)->type)) yyerror("expr must be a int or real"); 
                if((yyvsp[(1) - (3)].var)->type == TYPE_REAL || (yyvsp[(3) - (3)].var)->type == TYPE_REAL) 
                {
                    (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '+', KIND_VARIABLE, TYPE_REAL);
                }
                else (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '+', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('+');
                }
    break;

  case 64:
#line 555 "parser.y"
    {
                Trace("expression - expression");

                if((((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) || ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) && ((yyvsp[(1) - (3)].var)->type != (yyvsp[(3) - (3)].var)->type)) yyerror("expr must be a int or real"); 
                if((yyvsp[(1) - (3)].var)->type == TYPE_REAL || (yyvsp[(3) - (3)].var)->type == TYPE_REAL) (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '-', KIND_VARIABLE, TYPE_REAL);
                else (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '-', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('-');
                }
    break;

  case 65:
#line 566 "parser.y"
    {
                Trace("expression % expression");

                if((((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) || ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) && ((yyvsp[(1) - (3)].var)->type != (yyvsp[(3) - (3)].var)->type)) yyerror("expr must be a int or real"); 
                if((yyvsp[(1) - (3)].var)->type == TYPE_REAL || (yyvsp[(3) - (3)].var)->type == TYPE_REAL) (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '%', KIND_VARIABLE, TYPE_REAL);
                else (yyval.var) = exprArith(*(yyvsp[(1) - (3)].var), *(yyvsp[(3) - (3)].var), '%', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('%');
                }
    break;

  case 66:
#line 577 "parser.y"
    {
                Trace("expression < expression");
                if(((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) || ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");
                // only int or real can compare
                (yyval.var) = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);

                //if(!declaring)
                CG_ExprBool(0);
                }
    break;

  case 67:
#line 588 "parser.y"
    {
                Trace("expression <= expression");
                if(((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) || ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");

                (yyval.var) = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(3);
                }
    break;

  case 68:
#line 598 "parser.y"
    {
                Trace("expression = expression");
                //this mean expr1 = string/boolean and expr2 = string/boolean, and their type must be same
                if(((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) && ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");
                
                (yyval.var) = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(2);
                }
    break;

  case 69:
#line 609 "parser.y"
    {
                Trace("expression >= expression");

                if(((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) || ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");
                (yyval.var) = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(4);
                }
    break;

  case 70:
#line 619 "parser.y"
    {
                Trace("expression > expression");

                if(((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) || ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");
                (yyval.var) = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(1);
                }
    break;

  case 71:
#line 629 "parser.y"
    {
                Trace("expression /= expression");
                if((((yyvsp[(1) - (3)].var)->type != TYPE_INT && (yyvsp[(1) - (3)].var)->type != TYPE_REAL) && ((yyvsp[(3) - (3)].var)->type != TYPE_INT && (yyvsp[(3) - (3)].var)->type != TYPE_REAL)) && (yyvsp[(1) - (3)].var)->type != (yyvsp[(3) - (3)].var)->type) yyerror("type of expr1 and type of expr2 are different"); 
                (yyval.var) = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(5);
                }
    break;

  case 72:
#line 638 "parser.y"
    {
                Trace("NOT expression");

                if((yyvsp[(2) - (2)].var)->type != TYPE_BOOLEAN) yyerror("expr must be a boolean");
                (yyval.var) = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprArith('x');
                }
    break;

  case 73:
#line 648 "parser.y"
    {
                Trace("expression AND expression");

                if((yyvsp[(1) - (3)].var)->type != TYPE_BOOLEAN || (yyvsp[(3) - (3)].var)->type != TYPE_BOOLEAN) yyerror("expr must be a boolean");

                (yyval.var) = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprArith('a');
                }
    break;

  case 74:
#line 659 "parser.y"
    {
                Trace("expression OR expression");

                if((yyvsp[(1) - (3)].var)->type != TYPE_BOOLEAN || (yyvsp[(3) - (3)].var)->type != TYPE_BOOLEAN) yyerror("expr must be a boolean"); 

                (yyval.var) = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprArith('o');
                }
    break;

  case 81:
#line 683 "parser.y"
    {
                                    /*++scope;
                                    ++level;
                                    symtable_list.push_back(SymbolTable());  */
                                }
    break;

  case 82:
#line 689 "parser.y"
    {
                                    //--level;
                                }
    break;

  case 86:
#line 700 "parser.y"
    {
                        Trace("simple statement: assign");
                        Vartype *temp = symtableList_lookup(*(yyvsp[(1) - (4)].stringVal), symtable_list, level);
                        //cout << "OK" << endl;
                        if(temp == NULL) yyerror("haven't declared before invocate");
                        if(temp->var_kind != KIND_VARIABLE) yyerror("this is not a variable / this kind can't be assigned");
                        if(((temp->type != TYPE_INT && temp->type != TYPE_REAL) || ((yyvsp[(3) - (4)].var)->type != TYPE_INT && (yyvsp[(3) - (4)].var)->type != TYPE_REAL)) && temp->type != (yyvsp[(3) - (4)].var)->type) yyerror("the type of the identifier is not the same type as expr");
                        CG_StateAssign(*(yyvsp[(1) - (4)].stringVal), *temp);
                    }
    break;

  case 87:
#line 711 "parser.y"
    {
                        Trace("simple statement: array assign");
                        Trace("array type");
                        Vartype *arr = symtableList_lookup(*(yyvsp[(1) - (7)].stringVal), symtable_list, level);     
                        if(arr == NULL) yyerror("haven't declared");
                        if(arr->var_kind != KIND_VARIABLE) yyerror("not a variable");
                        if(arr->type != TYPE_ARRAY) yyerror("not array type");
                        if((yyvsp[(3) - (7)].var)->type != TYPE_INT) yyerror("index must be a int");
                        if((yyvsp[(3) - (7)].var)->var_val.int_val >= arr->var_val.array_val.size() || (yyvsp[(3) - (7)].var)->var_val.int_val < 0) yyerror("index out of range");
                        if(arr->var_val.array_val[0].type != (yyvsp[(3) - (7)].var)->type) yyerror("the type of the array is not the same as the type assigned");
                    }
    break;

  case 88:
#line 724 "parser.y"
    {
                        CG_StatePrintBegin();
                    }
    break;

  case 89:
#line 728 "parser.y"
    {
                        Trace("println expr");
                        CG_StatePrintEnd(false, *(yyvsp[(3) - (4)].var));
                    }
    break;

  case 90:
#line 734 "parser.y"
    {
                        CG_StatePrintBegin();
                    }
    break;

  case 91:
#line 738 "parser.y"
    {
                        Trace("print expr");
                        CG_StatePrintEnd(true, *(yyvsp[(3) - (4)].var));
                    }
    break;

  case 92:
#line 744 "parser.y"
    {
                        Trace("read id");
                    }
    break;

  case 93:
#line 749 "parser.y"
    {
                        Trace("return");
                        fout << "\t\treturn" << endl;
                    }
    break;

  case 94:
#line 755 "parser.y"
    {
                        Trace("return expr");
                        fout << "\t\tireturn" << endl;
                    }
    break;

  case 95:
#line 761 "parser.y"
    {
                        Trace("expression");
                    }
    break;

  case 96:
#line 767 "parser.y"
    {
                CG_StateIfBegin();
            }
    break;

  case 97:
#line 773 "parser.y"
    {
                            Trace("conditional statement: if");           
                            if((yyvsp[(3) - (10)].var)->type != TYPE_BOOLEAN) yyerror("expr is not a boolean");

                            CG_StateCondEnd(false);

                            //--level;
                            //if(Opt_P) symtable_dump(symtable_list, scope);
                            //if(symtable_list.size() > 1) symtable_list.pop_back();
                            //--scope;
                            //cout <<"condition level"<<level<<endl;   
                        }
    break;

  case 98:
#line 787 "parser.y"
    {
                            CG_StateElseBegin();
                            //--level;
                        }
    break;

  case 99:
#line 792 "parser.y"
    {
                            Trace("conditional statement: if and else");      
                            if((yyvsp[(3) - (13)].var)->type != TYPE_BOOLEAN) yyerror("expr is not a boolean");

                            CG_StateCondEnd(true);
                            //--level;
                            
                            //if(Opt_P) symtable_dump(symtable_list, scope);
                            //if(symtable_list.size() > 1) symtable_list.pop_back();
                            //if(symtable_list.size() > 1) symtable_list.pop_back();
                            //cout <<"condition level"<<level<<endl;              
                            //--scope;        
                        }
    break;

  case 102:
#line 817 "parser.y"
    {
                        CG_StateLoopBegin();
                    }
    break;

  case 103:
#line 821 "parser.y"
    {
                        Trace("while statement");
                        if((yyvsp[(4) - (6)].var)->type != TYPE_BOOLEAN) yyerror("expr is not a boolean"); 

                        CG_StateLoopExpr();
                        //++level;
                    }
    break;

  case 104:
#line 829 "parser.y"
    {
                        CG_StateLoopEnd();

                        //--level;
                        //if(Opt_P) symtable_dump(symtable_list, scope);
                        //if(symtable_list.size() > 1) symtable_list.pop_back();
                        //Trace("OUT");
                        //--scope;  
                    }
    break;

  case 105:
#line 844 "parser.y"
    {
                        Vartype *temp = symtableList_lookup(*(yyvsp[(3) - (5)].stringVal), symtable_list, level);
                        if(temp == NULL) yyerror("id hasn't been defined");
                        if(temp->var_kind != KIND_VARIABLE) yyerror("this isn't a variable");
                        if(temp->type != TYPE_INT) yyerror("this isn't a integer");
                        if((yyvsp[(5) - (5)].var)->var_kind != KIND_CONSTANT) yyerror("expr is not a cont");
                        if((yyvsp[(5) - (5)].var)->type != TYPE_INT) yyerror("expr is not a int");
                        temp->var_val.int_val = (yyvsp[(5) - (5)].var)->var_val.int_val;
                        CG_StateAssign(*(yyvsp[(3) - (5)].stringVal), *temp); 

                        CG_StateLoopBegin();
                        CG_ExprVar(*temp);
                    }
    break;

  case 106:
#line 858 "parser.y"
    {
                        Trace("For statement");
                        //++scope;
                        //symtable_list.push_back(SymbolTable());  
                        if((yyvsp[(9) - (11)].var)->var_kind != KIND_CONSTANT) yyerror("expr is not a cont");
                        if((yyvsp[(9) - (11)].var)->type != TYPE_INT) yyerror("expr is not a int");
                        if((yyvsp[(5) - (11)].var)->var_val.int_val > (yyvsp[(9) - (11)].var)->var_val.int_val) yyerror("the begin value must be less than the end value");

                        CG_ExprBool(3);
                        CG_StateLoopExpr();
                    }
    break;

  case 107:
#line 870 "parser.y"
    {
                        Vartype *temp = symtableList_lookup(*(yyvsp[(3) - (16)].stringVal), symtable_list, level);
                        CG_StateLoop_ForEnd(*(yyvsp[(3) - (16)].stringVal), *temp); 
                        CG_StateLoopEnd();

                        //--level;
                        //if(Opt_P) symtable_dump(symtable_list, scope);
                        //if(symtable_list.size() > 1) symtable_list.pop_back();
                    }
    break;


/* Line 1267 of yacc.c.  */
#line 2638 "y.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 880 "parser.y"


int yyerror(string msg)
{
    cerr << msg << endl;
    exit(1);
}

int main(int argc, char **argv)
{
    /* open the source program file */
    if (argc != 2) 
    {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    else
    {
        yyin = fopen(argv[1], "r");         /* open input file */
        if(!yyin)
        {
            cerr << "Error opening the order file" << endl;
            exit(1);
        }
    }
    
    string fin = string(argv[1]);
    filename = fin.substr(0, fin.find_last_of("."));
    fout.open(filename + ".jasm");

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
    
    return 0;
}

