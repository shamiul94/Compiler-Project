/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "1505038.y" /* yacc.c:339  */

#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include "SymbolTable.h"
#include "Functions.h"
#include <sstream>

	using namespace std;

	int yyparse(void);
	int yylex(void);

	extern FILE *yyin;
	extern int lineCount;

	string varType , retLabel ;

	SymbolTable *myTable = new SymbolTable(11);

	ofstream plogout, perrout , asmout ;

	int warningNo = 0, errorNo = 0, totalArgsNo = 0, typeAndIDArgsNo = 0;
	int passedParamNo = 0;

	vector<SymbolInfo *> Params;
	vector<Data> dataSegment ; 

	void yyerror(const char *s)
	{
		//write your code
		printf("%s\n", s);
	}

	int labelCount=0;
	int tempCount=0;

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	//printf("%s\n",t);
	return t;
}

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}


#line 137 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    INT = 264,
    CHAR = 265,
    FLOAT = 266,
    DOUBLE = 267,
    VOID = 268,
    RETURN = 269,
    SWITCH = 270,
    CASE = 271,
    DEFAULT = 272,
    CONTINUE = 273,
    INCOP = 274,
    DECOP = 275,
    ASSIGNOP = 276,
    BITOP = 277,
    NOT = 278,
    LPAREN = 279,
    RPAREN = 280,
    LCURL = 281,
    RCURL = 282,
    LTHIRD = 283,
    RTHIRD = 284,
    COMMA = 285,
    SEMICOLON = 286,
    PRINTLN = 287,
    COMMENT = 288,
    ERROR = 289,
    ID = 290,
    CONST_INT = 291,
    CONST_STRING = 292,
    CONST_FLOAT = 293,
    CONST_CHAR = 294,
    ADDOP = 295,
    MULOP = 296,
    LOGICOP = 297,
    RELOP = 298,
    LOWER_THAN_ELSE = 299
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define INT 264
#define CHAR 265
#define FLOAT 266
#define DOUBLE 267
#define VOID 268
#define RETURN 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define CONTINUE 273
#define INCOP 274
#define DECOP 275
#define ASSIGNOP 276
#define BITOP 277
#define NOT 278
#define LPAREN 279
#define RPAREN 280
#define LCURL 281
#define RCURL 282
#define LTHIRD 283
#define RTHIRD 284
#define COMMA 285
#define SEMICOLON 286
#define PRINTLN 287
#define COMMENT 288
#define ERROR 289
#define ID 290
#define CONST_INT 291
#define CONST_STRING 292
#define CONST_FLOAT 293
#define CONST_CHAR 294
#define ADDOP 295
#define MULOP 296
#define LOGICOP 297
#define RELOP 298
#define LOWER_THAN_ELSE 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 71 "1505038.y" /* yacc.c:355  */

	SymbolInfo *s;

#line 269 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 286 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,   120,   136,   146,   158,   169,   180,   218,
     253,   415,   554,   577,   598,   618,   641,   658,   640,   679,
     693,   707,   714,   730,   746,   763,   815,   864,   906,   954,
     965,   984,   995,  1006,  1017,  1043,  1063,  1093,  1124,  1143,
    1149,  1168,  1175,  1190,  1202,  1209,  1247,  1306,  1317,  1426,
    1437,  1507,  1518,  1673,  1684,  1725,  1732,  1989,  2032,  2056,
    2068,  2088,  2168,  2181,  2199,  2218,  2258,  2298,  2310,  2318,
    2333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "BREAK", "INT", "CHAR", "FLOAT", "DOUBLE", "VOID", "RETURN", "SWITCH",
  "CASE", "DEFAULT", "CONTINUE", "INCOP", "DECOP", "ASSIGNOP", "BITOP",
  "NOT", "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "PRINTLN", "COMMENT", "ERROR", "ID", "CONST_INT",
  "CONST_STRING", "CONST_FLOAT", "CONST_CHAR", "ADDOP", "MULOP", "LOGICOP",
  "RELOP", "LOWER_THAN_ELSE", "$accept", "start", "program", "unit",
  "func_declaration", "func_definition", "parameter_list",
  "compound_statement", "$@1", "$@2", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -71

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-71)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      92,   -71,   -71,   -71,    36,    92,   -71,   -71,   -71,   -71,
     -27,   -71,   -71,    49,    19,     5,   -26,   -71,    25,   -71,
      -7,    -4,    27,    42,    44,    47,   -71,   -71,     8,    92,
     -71,   -71,    43,   -71,    52,   -71,   -71,    45,    56,    62,
      73,    78,    76,    76,    76,   -71,    80,    67,   -71,   -71,
      76,   -71,   -71,    74,    52,   -71,   -71,    87,     2,   -71,
      68,   -15,    72,   -71,   -71,   -71,   -71,    76,    58,    76,
      10,    33,   -71,    90,    82,    76,    76,   -71,    91,    93,
     -71,   -71,   -71,    76,   -71,   -71,    76,    76,    76,    76,
      96,    58,    97,   -71,   -71,   -71,    98,   -71,    99,    88,
     100,   -71,   -71,   -71,    72,    85,   -71,    52,    76,    52,
      16,   -71,    76,   -71,   122,   102,   -71,   -71,   -71,   -71,
      52,    52,   -71,   -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,    23,    24,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    27,     0,     0,     0,    21,     0,    20,
       0,     0,    15,     0,    25,    16,     9,    11,     0,     0,
      14,    28,     0,    19,     0,     8,    10,    13,     0,     0,
       0,     0,     0,     0,     0,    42,     0,    45,    63,    64,
       0,    33,    31,     0,    17,    29,    32,    60,     0,    47,
      49,    51,    53,    55,    59,    12,    26,     0,     0,     0,
       0,    60,    58,     0,     0,    68,     0,    57,    27,     0,
      30,    65,    66,     0,    44,    43,     0,     0,     0,     0,
       0,     0,     0,    41,    40,    62,     0,    70,     0,    67,
       0,    18,    48,    50,    54,    52,    56,     0,     0,     0,
       0,    61,     0,    46,    35,     0,    37,    39,    38,    69,
       0,     0,    36,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,   123,   -71,   -71,   -71,    -5,   -71,   -71,
      59,    22,   -71,   -71,   -53,   -56,   -43,   -38,   -70,    46,
      48,    50,   -41,   -71,   -71,   -71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    21,    51,    34,    79,
      52,    53,    14,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      71,    80,    72,    84,    70,    97,    73,    71,    13,    77,
      23,    93,    91,   102,     1,    27,     2,   117,     3,    25,
      17,    28,    10,    36,    26,    87,    29,    10,    88,    90,
      20,    92,    71,    85,    25,   108,    11,    22,   100,    35,
      71,    94,   119,    71,    71,    71,    71,   118,   106,    18,
      19,    37,    81,    82,   114,    39,   116,    40,    41,     9,
      24,     1,    30,     2,     9,     3,    42,   122,   123,    71,
     115,    31,    32,    15,    33,    43,    44,    16,    25,    38,
      65,    43,    44,    45,    46,    66,    67,    47,    48,    45,
      49,    75,    50,    47,    48,    76,    49,    68,    50,    43,
      44,     1,    69,     2,    74,     3,    81,    82,    83,    78,
      86,    47,    48,    89,    49,    95,    50,    96,   112,    16,
     101,   107,   109,   110,   111,    87,   120,   121,    12,   113,
       0,     0,   103,     0,     0,     0,   105,   104
};

static const yytype_int8 yycheck[] =
{
      43,    54,    43,     1,    42,    75,    44,    50,    35,    50,
      36,     1,    68,    83,     9,    20,    11,     1,    13,    26,
       1,    25,     0,    28,    31,    40,    30,     5,    43,    67,
      25,    69,    75,    31,    26,    91,     0,    15,    76,    31,
      83,    31,   112,    86,    87,    88,    89,    31,    89,    30,
      31,    29,    19,    20,   107,     3,   109,     5,     6,     0,
      35,     9,    35,    11,     5,    13,    14,   120,   121,   112,
     108,    29,    28,    24,    27,    23,    24,    28,    26,    36,
      35,    23,    24,    31,    32,    29,    24,    35,    36,    31,
      38,    24,    40,    35,    36,    28,    38,    24,    40,    23,
      24,     9,    24,    11,    24,    13,    19,    20,    21,    35,
      42,    35,    36,    41,    38,    25,    40,    35,    30,    28,
      27,    25,    25,    25,    25,    40,     4,    25,     5,    29,
      -1,    -1,    86,    -1,    -1,    -1,    88,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    11,    13,    46,    47,    48,    49,    50,    55,
      56,     0,    48,    35,    57,    24,    28,     1,    30,    31,
      25,    51,    56,    36,    35,    26,    31,    52,    25,    30,
      35,    29,    28,    27,    53,    31,    52,    56,    36,     3,
       5,     6,    14,    23,    24,    31,    32,    35,    36,    38,
      40,    52,    55,    56,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    35,    29,    24,    24,    24,
      62,    61,    67,    62,    24,    24,    28,    67,    35,    54,
      59,    19,    20,    21,     1,    31,    42,    40,    43,    41,
      62,    60,    62,     1,    31,    25,    35,    63,    69,    70,
      62,    27,    63,    64,    66,    65,    67,    25,    60,    25,
      25,    25,    30,    29,    59,    62,    59,     1,    31,    63,
       4,    25,    59,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    50,    51,    51,    51,    51,    53,    54,    52,    52,
      55,    55,    56,    56,    56,    57,    57,    57,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     0,     0,     5,     2,
       3,     3,     1,     1,     1,     3,     6,     1,     4,     1,
       2,     1,     1,     1,     7,     5,     7,     5,     5,     5,
       3,     3,     1,     2,     2,     1,     4,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     2,     1,
       1,     4,     3,     1,     1,     2,     2,     1,     0,     3,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
#line 86 "1505038.y" /* yacc.c:1646  */
    {

	plogout << "At line no: " << lineCount << " : "
			<< "start : program" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);

	//if(errorNo == 0)
	{
		//$1->assemblyCode +="\n\n DEC_OUT PROC NEAR\n\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tor ax,ax\n \tjge enddif\n\tpush ax\n\tmov dl,'-'\n\tmov ah,2\n\tint 21h\n\tpop ax\n\tneg ax\nenddif:\n\txor cx,cx\n\tmov bx,10d\nrepeat:\n\txor dx,dx\n\tdiv bx\n\t push dx\n\tinc cx\n\tor ax,ax\n\tjne repeat\n\tmov ah,2\nprint_loop:\n\tpop dx\n\tor dl,30h\n\tint 21h\n\tloop print_loop\n\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\n\nDEC_OUT  ENDP\n";

		asmout <<".model small\n.stack 100h\n\n.data\n" ; 

		for(int i = 0 ; i < dataSegment.size(); i++)
		{
			if(dataSegment[i].IdType == "VAR")
			{
					asmout << dataSegment[i].varName << " " << "   dw    ?\n" ; 
			}
			else if(dataSegment[i].IdType == "ARR")
			{
				asmout << dataSegment[i].varName << "   dw   " << dataSegment[i].initValue  << "    dup(?)  "  << endl ; 
			}
		}
}
	
	asmout << ".code" << endl ; 
	asmout << (yyval.s) -> assemblyCode << endl ; 
}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 121 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "program : program unit" << endl
			<< endl;

	plogout << (yyvsp[-1].s)->codeSegment << " " << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-1].s)->codeSegment + " " + (yyvsp[0].s)->codeSegment;

	(yyval.s) -> assemblyCode = (yyvsp[-1].s) -> assemblyCode ; 
	(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 137 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "program : unit" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl;
	(yyval.s) = (yyvsp[0].s);
}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 147 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "unit : var_declaration" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
	
}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 159 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "unit : func_declaration" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 170 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "unit : func_definition" << endl
			<< endl;
	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 181 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON" << endl
			<< endl;

	plogout << (yyvsp[-5].s)->codeSegment << " " << (yyvsp[-4].s)->getSymbolName() << "(" << (yyvsp[-2].s)->codeSegment << ") ;" << endl << endl;

	//plogout << $1 -> getSymbolType() << endl<< $2 -> getSymbolName() << endl << endl ;

	SymbolInfo *tem = myTable->lookUpInCurr((yyvsp[-4].s)->getSymbolName(), "ID");

	if (tem == 0)
	{
		SymbolInfo *func = new SymbolInfo((yyvsp[-4].s)->getSymbolName(), "ID");
		func = myTable->insert(func);

		func->setIdType("FUNC");
		func->setFuncReturnType(varType);
		func->setParamNo(totalArgsNo);
		func->setParamList(Params);
		func->funcDeclared = true;
		initializeParam();
	}
	else
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << (yyvsp[-4].s)->getSymbolName() << "\" has already been declared before in this scope." << endl
				<< endl;
		myTable->printAllScopeTable(perrout);
	}

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-5].s)->codeSegment + " " + (yyvsp[-4].s)->getSymbolName() + "(" + (yyvsp[-2].s)->codeSegment + ") ;";

	//asmout << $$ -> assemblyCode << endl ; 
}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 219 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON" << endl
			<< endl;

	plogout << (yyvsp[-4].s)->codeSegment << " " << (yyvsp[-3].s)->getSymbolName() << "("
			<< ") ;" << endl
			<< endl;

	SymbolInfo *tem = myTable->lookUpInCurr((yyvsp[-3].s)->getSymbolName(), "ID");

	if (tem == 0)
	{
		SymbolInfo *func = new SymbolInfo((yyvsp[-3].s)->getSymbolName(), "ID");
		func = myTable->insert(func);
		func->setIdType("FUNC");
		func->setFuncReturnType(varType);
		func->setParamNo(0);
		func->funcDeclared = true;
		initializeParam();
	}
	else
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << (yyvsp[-3].s)->getSymbolName() << "\" has already been declared before in this scope." << endl
				<< endl;
		myTable->printAllScopeTable(perrout);
	}

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-4].s)->codeSegment + " " + (yyvsp[-3].s)->getSymbolName() + "(" + ") ;";
}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 254 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement" << endl
			<< endl;

	plogout << (yyvsp[-5].s)->codeSegment << " " << (yyvsp[-4].s)->getSymbolName() << "( " << (yyvsp[-2].s)->codeSegment << " ) " << endl
			<< (yyvsp[0].s)->codeSegment << endl
			<< endl;

	//plogout << $2 -> getSymbolName() << endl << endl ;

	SymbolInfo *tem = myTable->lookUpInCurr((yyvsp[-4].s)->getSymbolName(), "ID");

	//cout << typeAndIDArgsNo << " " << totalArgsNo << endl ;

	if (tem == 0)
	{
		SymbolInfo *func = new SymbolInfo((yyvsp[-4].s)->getSymbolName(), "ID");
		func = myTable->insert(func);
		func->setIdType("FUNC");
		//cout << $1 -> getSymbolName() << endl ;
		func->setFuncReturnType((yyvsp[-5].s)->getSymbolName());
		func->setParamNo(totalArgsNo);
		func->setParamList(Params);
		func->setIsFuncDefined();



		initializeParam();
	}
	else if (tem->getIdType() != "FUNC")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << tem->getSymbolName() << " has been declared as " << tem->getIdType() << " so, can not be defined as function now." << endl
				<< endl;

		initializeParam();
	}
	else if (tem->funcDeclared == true && tem->getParamNo() != typeAndIDArgsNo)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
				<< " Argument number mismatch between Function definition and declaration of function " << (yyvsp[-4].s)->getSymbolName() << "." << endl
				<< endl;
		initializeParam();
	}
	else if (totalArgsNo != typeAndIDArgsNo)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
				<< " Parameter mismatch for Function " << (yyvsp[-4].s)->getSymbolName() << endl
				<< endl;

		initializeParam();
	}
	else
	{
		if (tem->checkIfFuncDefined() == true)
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function" << (yyvsp[-4].s)->getSymbolName() << " has been already defined." << endl
					<< endl;

			initializeParam();
		}
		else
		{
			// check if it's really function. not var/array
			if (tem->getFuncReturnType() != (yyvsp[-5].s)->getSymbolName())
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Return Type of Function " << (yyvsp[-4].s)->getSymbolName() << " doesn't match." << endl
						<< endl;
				initializeParam();
			}
			else if (tem->getParamNo() != totalArgsNo)
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
						<< " Parameter mismatch for Function " << (yyvsp[-4].s)->getSymbolName() << endl
						<< endl;

				initializeParam();
			}
			else if (tem->paramList.size() == Params.size())
			{
				bool err = false;

				for (int i = 0; i < tem->paramList.size(); i++)
				{
					//cout << "RUMMAN " << Params[i] -> getVarType() << " " << tem -> paramList[i] -> getVarType() << endl ;
					if (Params[i]->getVarType() != tem->paramList[i]->getVarType())
					{
						//cout << Params[i] -> getVarType() << " " << tem -> paramList[i] -> getVarType() << endl ;
						errorNo++;
						perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
								<< " Parameter mismatch for Function " << (yyvsp[-4].s)->getSymbolName() << "  because " << tem->paramList[i]->getVarType() << " doesn't match with " << Params[i]->getVarType() << "." << endl
								<< endl;
						err = true;

						initializeParam();
					}
				}
				if (err == false)
				{
					tem->setIdType("FUNC");
					tem->setFuncReturnType((yyvsp[-5].s)->getSymbolName());
					tem->setParamNo(totalArgsNo);
					tem->setParamList(Params);
					tem->setIsFuncDefined();
					//initializeParam();
				}
			}
		}
	}

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;

	(yyval.s)->codeSegment = (yyvsp[-5].s)->codeSegment + " " + (yyvsp[-4].s)->getSymbolName() + "( " + (yyvsp[-2].s)->codeSegment + " ) " + "\n" + (yyvsp[0].s)->codeSegment;

	


	 //type_specifier ID LPAREN parameter_list RPAREN compound_statement

	 (yyval.s) -> setAsmVarName((yyvsp[-4].s) -> getSymbolName());

	(yyval.s) -> assemblyCode += (yyvsp[-4].s) -> getSymbolName() + " PROC NEAR\n"; 
	(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 

	if((yyvsp[-4].s) -> getSymbolName() == "main")
	{
		(yyval.s)->assemblyCode +="mov ah , 4ch\nint 21h\n";
	}
	else {
		
		(yyval.s) -> assemblyCode +=  retLabel + " : \n" ; 

		if(Params.size() != 0)
		{
			(yyval.s) -> assemblyCode += "pop bp\n";
		}
		
		(yyval.s) -> assemblyCode += "ret  " ; 
	

		if(2 * Params.size() != 0)
		{
			(yyval.s) -> assemblyCode +=  IntToString(2*Params.size()) + "\n" ;
		}
	}

	(yyval.s) -> assemblyCode += (yyvsp[-4].s) -> getSymbolName() + " ENDP\n" ; 

	initializeParam();
	retLabel = "";

	asmout << "problem ..."  << (yyval.s) -> assemblyCode << endl ; 
	
}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 416 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "func_definition : type_specifier ID LPAREN RPAREN compound_statement" << endl
			<< endl;

	plogout << (yyvsp[-4].s)->codeSegment << " " << (yyvsp[-3].s)->getSymbolName() << "( ) " << endl
			<< (yyvsp[0].s)->codeSegment << endl
			<< endl;

	//plogout << $2 -> getSymbolName() << endl << endl ;

	SymbolInfo *tem = myTable->lookUpInCurr((yyvsp[-3].s)->getSymbolName(), "ID");

	//cout << tem -> getParamNo() << " " << totalArgsNo << endl ;

	if (tem == 0)
	{
		SymbolInfo *func = new SymbolInfo((yyvsp[-3].s)->getSymbolName(), "ID");
		func = myTable->insert(func);
		func->setIdType("FUNC");
		func->setFuncReturnType((yyvsp[-4].s)->getSymbolName());
		func->setParamNo(0);
		func->setIsFuncDefined();

		initializeParam();

	SymbolInfo* x = new SymbolInfo();
	(yyval.s) = x ;

	(yyval.s)->codeSegment = (yyvsp[-4].s)->codeSegment + " " + (yyvsp[-3].s)->getSymbolName() + "( ) \n" + (yyvsp[0].s)->codeSegment;
	

	// type_specifier ID LPAREN RPAREN compound_statement

	 (yyval.s) -> setAsmVarName((yyvsp[-3].s) -> getSymbolName());

	(yyval.s) -> assemblyCode += (yyvsp[-3].s) -> getSymbolName() + " PROC NEAR\n"; 
	(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 

	if((yyvsp[-3].s) -> getSymbolName() == "main")
	{
		(yyval.s)->assemblyCode +="mov ah , 4ch\nint 21h\n";
	}
	else {
		(yyval.s) -> assemblyCode +=  retLabel + " : \n" ; 

		(yyval.s) -> assemblyCode += "ret  " ; 
	
		if(2 * Params.size() != 0)
		{
			(yyval.s) -> assemblyCode +=  IntToString(2*Params.size()) + "\n" ;
		}
	}

	(yyval.s) -> assemblyCode += (yyvsp[-3].s) -> getSymbolName() + "  ENDP\n" ; 

	initializeParam();
	retLabel = "";


	}
	else
	{
		if (tem->checkIfFuncDefined() == true)
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function" << (yyvsp[-3].s)->getSymbolName() << " has been already defined." << endl
					<< endl;

			initializeParam();
		}
		else
		{
			// check if it's really function. not var/array
			if (tem->getIdType() != "FUNC")
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << (yyvsp[-3].s)->getSymbolName() << " has been already declared as Variable or Array." << endl
						<< endl;

				initializeParam();
			}
			else if (tem->getFuncReturnType() != (yyvsp[-4].s)->getSymbolName())
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Return Type of Function " << (yyvsp[-3].s)->getSymbolName() << " doesn't match." << endl
						<< endl;
				initializeParam();
			}
			else if (tem->getParamNo() != totalArgsNo)
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
						<< " Parameter mismatch for Function " << (yyvsp[-3].s)->getSymbolName() << endl
						<< endl;

				initializeParam();
			}
		}

			(yyval.s) = tem ;

	(yyval.s)->codeSegment = (yyvsp[-4].s)->codeSegment + " " + (yyvsp[-3].s)->getSymbolName() + "( ) \n" + (yyvsp[0].s)->codeSegment;
	

	// type_specifier ID LPAREN RPAREN compound_statement

	 (yyval.s) -> setAsmVarName((yyvsp[-3].s) -> getSymbolName());

	(yyval.s) -> assemblyCode += (yyvsp[-3].s) -> getSymbolName() + " PROC NEAR\n"; 
	(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 

	if((yyvsp[-3].s) -> getSymbolName() == "main")
	{
		(yyval.s)->assemblyCode +="mov ah , 4ch\nint 21h\n";
	}
	else {
		(yyval.s) -> assemblyCode +=  retLabel + " : \n" ; 

		(yyval.s) -> assemblyCode += "ret  " ; 
	
		if(2 * Params.size() != 0)
		{
			(yyval.s) -> assemblyCode +=  IntToString(2*Params.size()) + "\n" ;
		}
	}

	(yyval.s) -> assemblyCode += (yyvsp[-3].s) -> getSymbolName() + " ENDP\n" ; 

	initializeParam();
	retLabel = "";
	}

	


}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 555 "1505038.y" /* yacc.c:1646  */
    {

	plogout << "At line no: " << lineCount << " : "
			<< "parameter_list  : parameter_list COMMA type_specifier ID" << endl
			<< endl;

	plogout << (yyvsp[-3].s)->codeSegment << " , " << (yyvsp[-1].s)->codeSegment << " " << (yyvsp[0].s)->getSymbolName() << endl
			<< endl;

	totalArgsNo++;
	typeAndIDArgsNo++;

	SymbolInfo *tem = new SymbolInfo((yyvsp[0].s)->getSymbolName(), "ID");
	tem->setIdType("VAR");

	tem->setVarType((yyvsp[-1].s)->getSymbolName());
	Params.push_back(tem);

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-3].s)->codeSegment + " , " + (yyvsp[-1].s)->codeSegment + " " + (yyvsp[0].s)->getSymbolName();
}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 578 "1505038.y" /* yacc.c:1646  */
    {

	totalArgsNo++;

	plogout << "At line no: " << lineCount << " : "
			<< "parameter_list  : parameter_list COMMA type_specifier" << endl
			<< endl;

	plogout << (yyvsp[-2].s)->codeSegment << " , " << (yyvsp[0].s)->codeSegment << endl;

	SymbolInfo *tem = new SymbolInfo("#", "ID");
	tem->setIdType("VAR");
	tem->setVarType((yyvsp[0].s)->getSymbolName());

	Params.push_back(tem);

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-2].s)->codeSegment + " , " + (yyvsp[0].s)->codeSegment;
}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 599 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "parameter_list  : type_specifier ID" << endl
			<< endl;

	plogout << (yyvsp[-1].s)->codeSegment << " " << (yyvsp[0].s)->getSymbolName() << endl
			<< endl;
	totalArgsNo++;
	typeAndIDArgsNo++;

	SymbolInfo *tem = new SymbolInfo((yyvsp[0].s)->getSymbolName(), "ID");
	tem->setVarType((yyvsp[-1].s)->getSymbolName());
	tem->setIdType("VAR");
	Params.push_back(tem);

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-1].s)->codeSegment + " " + (yyvsp[0].s)->getSymbolName();
}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 619 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "parameter_list  : type_specifier" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	totalArgsNo++;

	SymbolInfo *tem = new SymbolInfo("#", "ID");
	tem->setIdType("VAR");
	tem->setVarType((yyvsp[0].s)->getSymbolName());

	Params.push_back(tem);

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[0].s)->codeSegment;
}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 641 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "compound_statement : LCURL statements RCURL" << endl
			<< endl;

	myTable->enterScope();
	for (int i = 0; i < Params.size(); i++)
	{
		if (Params[i]->getSymbolName() != "#")
		{
			SymbolInfo *t = myTable->insert(Params[i]);
			t->setIdType(Params[i]->getIdType());
			t->setVarType(Params[i]->getVarType());
		}
	}
}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 658 "1505038.y" /* yacc.c:1646  */
    {
}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 661 "1505038.y" /* yacc.c:1646  */
    {

	(yyval.s) = (yyvsp[-2].s) ; 
	//asmout << $$ -> assemblyCode  << endl ; 

	(yyval.s)->codeSegment = "{\n" + (yyvsp[-2].s)->codeSegment + "\n}\n";

	plogout << (yyval.s)->codeSegment << endl
			<< endl;

	myTable->printAllScopeTable(plogout);
	plogout << endl
			<< endl;

	myTable->exitScope();
	plogout << "Scope exited" << endl
			<< endl;
}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 680 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "compound_statement : LCURL RCURL" << endl
			<< endl;

	plogout << "{ }" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	(yyval.s) = tem;
	(yyval.s)->codeSegment = "{ }";
}
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 694 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "var_declaration : type_specifier declaration_list SEMICOLON" << endl
			<< endl;

	plogout << (yyvsp[-2].s)->codeSegment << " " << (yyvsp[-1].s)->codeSegment << " ;" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	(yyval.s) = tem;

	(yyval.s)->codeSegment = (yyvsp[-2].s)->codeSegment + " " + (yyvsp[-1].s)->codeSegment + " ;\n";
}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 708 "1505038.y" /* yacc.c:1646  */
    {
	errorNo++;
	perrout << "Error No: " << errorNo << " at line no: " << lineCount << " ; missing." << endl
			<< endl;
}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 715 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "type_specifier	: INT" << endl
			<< endl;

	plogout << "int" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo("INT");
	(yyval.s) = tem;

	(yyval.s)->codeSegment = "int";

	varType = "INT";
}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 731 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "type_specifier	: FLOAT" << endl
			<< endl;

	plogout << "float" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo("FLOAT");
	(yyval.s) = tem;

	(yyval.s)->codeSegment = "float";

	varType = "FLOAT";
}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 747 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "type_specifier	: VOID" << endl
			<< endl;

	plogout << "void" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo("VOID");
	(yyval.s) = tem;

	(yyval.s)->codeSegment = "void";

	varType = "VOID";
}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 764 "1505038.y" /* yacc.c:1646  */
    {

	plogout << "At line no: " << lineCount << " : "
			<< "declaration_list : declaration_list COMMA ID" << endl
			<< endl;

	plogout << (yyvsp[-2].s)->codeSegment << " , " << (yyvsp[0].s)->getSymbolName() << endl
			<< endl;

	//plogout << $3 -> getSymbolName() << endl << endl ;

	if (varType == "VOID")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << (yyvsp[0].s)->getSymbolName() << "\" can not be of type VOID." << endl
				<< endl;
	}
	else
	{
		SymbolInfo *tem = myTable->lookUpInCurr((yyvsp[0].s)->getSymbolName(), "ID");

		if (tem == 0)
		{
			SymbolInfo *t = new SymbolInfo((yyvsp[0].s)->getSymbolName(), "ID");

			t = myTable->insert(t);
			t->setVarType(varType);
			t->setIdType("VAR");
			char* temp = newTemp();
			t-> setAsmVarName(string(temp));
			dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		}
		else
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << (yyvsp[0].s)->getSymbolName() << "\" has already been declared before in this scope." << endl
					<< endl;
		}
	}

	myTable->printAllScopeTable(plogout);

	plogout << endl
			<< endl;

	SymbolInfo *x = new SymbolInfo();

	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-2].s)->codeSegment + " , " + (yyvsp[0].s)->getSymbolName();

}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 816 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD" << endl
			<< endl;

	plogout << (yyvsp[-5].s)->codeSegment << " , " << (yyvsp[-3].s)->getSymbolName() << "[" << (yyvsp[-1].s)->getSymbolName() << "]" << endl
			<< endl;

	//plogout << $3 -> getSymbolName() << endl << $5 -> getSymbolName() << endl << endl ;

	if (varType == "VOID")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Array \"" << (yyvsp[-3].s)->getSymbolName() << "[]\" can not be of type VOID." << endl
				<< endl;
	}
	else
	{
		SymbolInfo *tem = myTable->lookUpInCurr((yyvsp[-3].s)->getSymbolName(), "ID");

		if (tem == 0)
		{
			int arraySize = stoi((yyvsp[-1].s)->getSymbolName());

			SymbolInfo *t = new SymbolInfo((yyvsp[-3].s)->getSymbolName(), "ID");

			t = myTable->insert(t);
			t->setArraySize(arraySize);
			t->fillArray();
			t->setVarType(varType);
			t->setIdType("ARR");

			char* temp = newTemp();
			t-> setAsmVarName(string(temp));
			dataSegment.push_back(Data(string(temp), "ARR", (yyvsp[-1].s) -> getSymbolName()));
		}
		else
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << (yyvsp[-3].s)->getSymbolName() << "\" has already been declared before in this scope." << endl
					<< endl;
		}
	}

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-5].s)->codeSegment + " , " + (yyvsp[-3].s)->getSymbolName() + "[" + (yyvsp[-1].s)->getSymbolName() + "]";
}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 865 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "declaration_list : ID" << endl
			<< endl;

	plogout << (yyvsp[0].s)->getSymbolName() << endl
			<< endl;

	if (varType == "VOID")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << (yyvsp[0].s)->getSymbolName() << "\" can not be of type VOID." << endl
				<< endl;
	}
	else
	{
		SymbolInfo *tem = myTable->lookUpInCurr((yyvsp[0].s)->getSymbolName(), "ID");

		if (tem == 0)
		{
			SymbolInfo *t = new SymbolInfo((yyvsp[0].s)->getSymbolName(), "ID");
			t = myTable->insert(t);
			t->setVarType(varType);
			t->setIdType("VAR");

			char* temp = newTemp();
			t-> setAsmVarName(string(temp));
			dataSegment.push_back(Data(string(temp)  , "VAR", "0"));
		}
		else
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << (yyvsp[0].s)->getSymbolName() << "\" has already been declared before in this scope." << endl
					<< endl;
		}
	}

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[0].s)->getSymbolName();
}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 907 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "declaration_list : ID LTHIRD CONST_INT RTHIRD" << endl
			<< endl;

	plogout << (yyvsp[-3].s)->getSymbolName() << "[" << (yyvsp[-1].s)->getSymbolName() << "]" << endl
			<< endl;

	if (varType == "VOID")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Array \"" << (yyvsp[-3].s)->getSymbolName() << "[]\" can not be of type VOID." << endl
				<< endl;
	}
	else
	{
		SymbolInfo *tem = myTable->lookUpInCurr((yyvsp[-3].s)->getSymbolName(), "ID");

		if (tem == 0)
		{
			int arraySize = stoi((yyvsp[-1].s)->getSymbolName());

			SymbolInfo *t = new SymbolInfo((yyvsp[-3].s)->getSymbolName(), "ID");

			t = myTable->insert(t);
			t->setVarType(varType);
			t->setIdType("ARR");
			t->setArraySize(arraySize);
			t->fillArray();

			char* temp = newTemp();
			t-> setAsmVarName(string(temp));
			dataSegment.push_back(Data(string(temp) , "ARR", (yyvsp[-1].s) -> getSymbolName()));
		}
		else
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : ID \"" << (yyvsp[-3].s)->getSymbolName() << "\" has already been declared before in this scope." << endl
					<< endl;
		}
	}

	SymbolInfo *x = new SymbolInfo();
	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-3].s)->getSymbolName() + "[" + (yyvsp[-1].s)->getSymbolName() + "]";
}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 955 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statements : statement" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 966 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statements : statements statement" << endl
			<< endl;

	plogout << (yyvsp[-1].s)->codeSegment << endl
			<< (yyvsp[0].s)->codeSegment << endl;

	SymbolInfo *tem = new SymbolInfo();

	(yyval.s) = tem;
	(yyval.s)->codeSegment = (yyvsp[-1].s)->codeSegment + " " + (yyvsp[0].s)->codeSegment;

	(yyval.s) -> assemblyCode = (yyvsp[-1].s) -> assemblyCode ; 
	(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
	//asmout << "statemnt  " << $2 -> assemblyCode << endl ; 
}
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 985 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statement : var_declaration" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s); 
}
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 996 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statement : expression_statement" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 1007 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statement : compound_statement" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 2500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 1018 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement" << endl
			<< endl;

	plogout << "for(" << (yyvsp[-4].s)->codeSegment << (yyvsp[-3].s)->codeSegment << (yyvsp[-2].s)->codeSegment << ")" << (yyvsp[0].s)->codeSegment;

	(yyval.s) = (yyvsp[-4].s);
	(yyval.s)->codeSegment = "for(" + (yyvsp[-4].s)->codeSegment + (yyvsp[-3].s)->codeSegment + (yyvsp[-2].s)->codeSegment + ")" + (yyvsp[0].s)->codeSegment;


	char *label1 = newLabel();
	char *label2 = newLabel();

	(yyval.s)->assemblyCode += string(label1) + ":\n";
	(yyval.s)->assemblyCode+=(yyvsp[-3].s)->assemblyCode;
	(yyval.s)->assemblyCode+="mov ax , "+(yyvsp[-3].s)->getAsmVarName() +"\n";
	(yyval.s)->assemblyCode+="cmp ax , 0\n";
	(yyval.s)->assemblyCode+="je "+string(label2)+"\n";
	(yyval.s)->assemblyCode+=(yyvsp[0].s)->assemblyCode;
	(yyval.s)->assemblyCode+=(yyvsp[-2].s)->assemblyCode;
	(yyval.s)->assemblyCode+="jmp "+string(label1)+"\n";
	(yyval.s)->assemblyCode+=string(label2)+":\n";

}
#line 2530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 1044 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statement : IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE" << endl
			<< endl;

	plogout << "if(" << (yyvsp[-2].s)->codeSegment << ")" << (yyvsp[0].s)->codeSegment << endl;

	(yyval.s) = (yyvsp[-2].s);
	(yyval.s)->codeSegment = "if(" + (yyvsp[-2].s)->codeSegment + ")" + (yyvsp[0].s)->codeSegment;

	char* label = newLabel();
	(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() + " \n";
	(yyval.s) -> assemblyCode += "cmp ax , 0\n" ; 
	(yyval.s) -> assemblyCode += "je " + string(label) + "\n";
	(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
	(yyval.s) -> assemblyCode += string(label) + " : \n";
	  
	(yyval.s) -> setAsmVarName("if");
}
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 1064 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statement : IF LPAREN expression RPAREN statement ELSE statement" << endl
			<< endl;

	plogout << "if (" << (yyvsp[-4].s)->codeSegment << ") " << (yyvsp[-2].s)->codeSegment << " else " << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();

	(yyval.s) = tem;
	(yyval.s)->codeSegment = "if (" + (yyvsp[-4].s)->codeSegment + ") " + (yyvsp[-2].s)->codeSegment + " else " + (yyvsp[0].s)->codeSegment;

	char* else_  = newLabel();
	char* exit_ = newLabel();

	(yyval.s) -> assemblyCode = (yyvsp[-4].s) -> assemblyCode ; 
	(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-4].s) -> getAsmVarName() + "\n";
	(yyval.s) ->assemblyCode += "cmp ax , 0\n";
	(yyval.s) -> assemblyCode += "je " + string(else_) + "\n" ; 
	(yyval.s) -> assemblyCode += (yyvsp[-2].s) -> assemblyCode ; 
	(yyval.s) -> assemblyCode += "jmp " + string(exit_); 

	(yyval.s) -> assemblyCode += string(else_) + " : \n"; 
	(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 

	(yyval.s) -> assemblyCode += string(exit_) + " : \n" ; 

}
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 1094 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statement : WHILE LPAREN expression RPAREN statement" << endl
			<< endl;

	plogout << "while(" << (yyvsp[-2].s)->codeSegment << ") " << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	(yyval.s) = tem;

	(yyval.s)->codeSegment = "while(" + (yyvsp[-2].s)->codeSegment + ") " + (yyvsp[0].s)->codeSegment;

	char* whileLabel = newLabel(); 
	char* exitLabel = newLabel();

	(yyval.s) -> assemblyCode = string(whileLabel) + " : \n"; 
	(yyval.s) -> assemblyCode += (yyvsp[-2].s) -> assemblyCode ; 
	(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() ; 
	(yyval.s) -> assemblyCode += "cmp ax , 0\n";
	(yyval.s) -> assemblyCode += "je " + string(exitLabel) + "\n" ;

	(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
	(yyval.s) -> assemblyCode += "jmp " + string(whileLabel)  + "\n" ; 

	(yyval.s) -> assemblyCode += string(exitLabel) + " : \n" ; 

	(yyval.s) -> setAsmVarName("while") ; 

}
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 1125 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statement : PRINTLN LPAREN ID RPAREN SEMICOLON" << endl
			<< endl;

	plogout << "println(" << (yyvsp[-2].s)->getSymbolName() << ");\n"
			<< endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	(yyval.s) = tem;

	(yyval.s)->codeSegment = "println(" + (yyvsp[-2].s)->getSymbolName() + ");\n";

	(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() + " \n " ; 
	(yyval.s) -> assemblyCode += "call DEC_OUT\n" ; 

}
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 1144 "1505038.y" /* yacc.c:1646  */
    {
	errorNo++;
	perrout << "Error No: " << errorNo << " at line no: " << lineCount << " ; missing." << endl << endl;

}
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1150 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "statement : RETURN expression SEMICOLON" << endl
			<< endl;

	plogout << "return " << (yyvsp[-1].s)->codeSegment << " ;" << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo();
	(yyval.s) = tem;

	(yyval.s)->codeSegment = "return " + (yyvsp[-1].s)->codeSegment + " ;";

	(yyval.s) -> assemblyCode = (yyvsp[-1].s) -> assemblyCode ; 
	(yyval.s)->assemblyCode+="\tmov dx , "+(yyvsp[-1].s)->getAsmVarName()+"\n";
	(yyval.s)->assemblyCode+="\tjmp  "+string(retLabel)+"\n";

}
#line 2679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1169 "1505038.y" /* yacc.c:1646  */
    {
	errorNo++;
	perrout << "Error No: " << errorNo << " at line no: " << lineCount << " ; missing." << endl
			<< endl;
}
#line 2689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1176 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "expression_statement 	: SEMICOLON" << endl
			<< endl;

	plogout << ";" << endl
			<< endl;

	SymbolInfo *x = new SymbolInfo();

	(yyval.s) = x;
	(yyval.s)->codeSegment = ";\n";
	(yyval.s)->assemblyCode="";
}
#line 2708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1191 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "expression_statement 	: expression SEMICOLON" << endl
			<< endl;

	plogout << (yyvsp[-1].s)->codeSegment << ";" << endl
			<< endl;

	(yyval.s) = (yyvsp[-1].s);
	(yyval.s)->codeSegment = (yyvsp[-1].s)->codeSegment + ";\n";
}
#line 2724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1203 "1505038.y" /* yacc.c:1646  */
    {
	errorNo++;
	perrout << "Error No: " << errorNo << " at line no: " << lineCount << " ; missing." << endl
			<< endl;
}
#line 2734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1210 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "variable : ID" << endl
			<< endl;

	plogout << (yyvsp[0].s)->getSymbolName() << endl
			<< endl;

	SymbolInfo *tem = myTable->lookUp((yyvsp[0].s)->getSymbolName(), "ID");

	if (tem == 0)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << (yyvsp[0].s)->getSymbolName() << "\" was not declared before." << endl
				<< endl;
	}
	else
	{
		if (tem->getIdType() != "VAR")
		{

			//myTable -> printAllScopeTable(perrout) ;
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << (yyvsp[0].s)->getSymbolName() << " was declared before as " << tem->getIdType() << ". So, it can not be used as a variable now." << endl
					<< endl;
		}
		else
		{
				(yyval.s) = tem ;
				(yyval.s)->codeSegment = (yyvsp[0].s)->getSymbolName();

				(yyval.s)-> assemblyCode = "" ;
				(yyval.s) -> setAsmVarName(tem -> getAsmVarName() ) ;
		}
	}
	
}
#line 2776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1248 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "variable : ID LTHIRD expression RTHIRD" << endl
			<< endl;

	plogout << (yyvsp[-3].s)->getSymbolName() << "[" << (yyvsp[-1].s)->codeSegment << "]" << endl
			<< endl;

	SymbolInfo *tem = myTable->lookUp((yyvsp[-3].s)->getSymbolName(), "ID");

	if ((yyvsp[-1].s)->getVarType() == "FLOAT")
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " Array index must be an integer." << endl
				<< endl;
	}
	else if (tem == 0)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Variable \"" << (yyvsp[-3].s)->getSymbolName() << "\" was not declared before." << endl
				<< endl;
	}
	else
	{
		if (tem->getIdType() != "ARR")
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : " << (yyvsp[-3].s)->getSymbolName() << " was declared before as " << tem->getIdType() << ". So, it can not be used as an array now." << endl
					<< endl;
		}
		else
		{
			if (tem->arraySize <= (yyvsp[-1].s)->intVarValue)
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Size of Array " << (yyvsp[-3].s)->getSymbolName() << " is " << tem->arraySize << ", so index " << (yyvsp[-1].s)->intVarValue << " can not be accessed." << endl
						<< endl;
			}
			else
			{
				(yyval.s) = tem;

				(yyval.s) -> assemblyCode = (yyvsp[-1].s) -> assemblyCode ; 
				(yyval.s) -> assemblyCode += "mov bx , " + (yyvsp[-1].s) -> getAsmVarName()  + "\n";
				(yyval.s) -> assemblyCode += "add bx , bx \n";
				(yyval.s) -> assemblyCode += "mov ax , " + tem -> getAsmVarName() + "[bx] \n"; 
				char* temp = newTemp();
				(yyval.s) -> assemblyCode += "mov " + string(temp) + " , ax\n"; 
				(yyval.s) -> setAsmVarName(string(temp) ) ;
				dataSegment.push_back(Data((yyval.s) -> getAsmVarName() , "VAR", "0"));
			}
		}
	}

		(yyval.s)->codeSegment = (yyvsp[-3].s)->getSymbolName() + "[" + (yyvsp[-1].s)->codeSegment + "]";
	
}
#line 2838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1307 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "expression : logic_expression" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 2853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1318 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "expression : variable ASSIGNOP logic_expression" << endl
			<< endl;

	plogout << (yyvsp[-2].s)->codeSegment << " = " << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[-2].s) ; 

	if ((yyvsp[-2].s)->getIdType() == "VAR")
	{
		if ((yyvsp[0].s)->getIdType() == "VAR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Float value is assigned to Int value (Type casting)." << endl
						<< endl;
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Int value is assigned to Float value (Type casting)." << endl
						<< endl;
			}
		}
		else if ((yyvsp[0].s)->getIdType() == "ARR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Float value is assigned to Int value (Type casting)." << endl
						<< endl;

			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Int value is assigned to Float value (Type casting)." << endl
						<< endl;

			}
		}

		(yyval.s) -> assemblyCode = (yyvsp[0].s) -> assemblyCode + (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[0].s) -> getAsmVarName() + " \n";
		(yyval.s) -> assemblyCode += "mov  " +  (yyvsp[-2].s) -> getAsmVarName() + " , ax\n";

		(yyval.s) -> setAsmVarName((yyvsp[-2].s) -> getAsmVarName()) ; 

	}
	else if ((yyvsp[-2].s)->getIdType() == "ARR")
	{
		if ((yyvsp[0].s)->getIdType() == "VAR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Float value is assigned to Int value (Type casting)." << endl
						<< endl;

			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Int value is assigned to Float value (Type casting)." << endl
						<< endl;
			}
		}
		else if ((yyvsp[0].s)->getIdType() == "ARR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Float value is assigned to Int value (Type casting)." << endl
						<< endl;

			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				warningNo++;
				perrout << "Warning No: " << warningNo << " at line no: " << lineCount << " : "
						<< " Int value is assigned to Float value (Type casting)." << endl
						<< endl;

			}
		}


		(yyval.s) -> assemblyCode = (yyvsp[0].s) -> assemblyCode + (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[0].s) -> getAsmVarName() + "\n";
		(yyval.s) -> assemblyCode += "mov " +  (yyvsp[-2].s) -> getAsmVarName() + "[bx] , ax\n";

		(yyval.s) -> setAsmVarName((yyvsp[-2].s) -> getAsmVarName()) ; 

	}

	(yyval.s)->codeSegment = (yyvsp[-2].s)->getSymbolName() + " = " + (yyvsp[0].s)->codeSegment;
}
#line 2965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1427 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "logic_expression : rel_expression" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 2980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1438 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "logic_expression : rel_expression LOGICOP rel_expression" << endl
			<< endl;

	plogout << (yyvsp[-2].s)->codeSegment << (yyvsp[-1].s)->getSymbolName() << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	SymbolInfo *tem = new SymbolInfo("", "ID");

	(yyval.s) = tem;

	tem->setVarType("INT");
	tem->setIdType("VAR");

	char * label1 = newLabel();
	char * label2 = newLabel();
	char * temp = newTemp();

	if ((yyvsp[-1].s)->getSymbolName() == "&&")
	{
		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
	    (yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 

		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() + " \n";
		(yyval.s) -> assemblyCode += "cmp ax , 0\n";
		(yyval.s) -> assemblyCode += "je " + string(label1) + "\n" ;
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[0].s) -> getAsmVarName() + " \n";
		(yyval.s) -> assemblyCode += "cmp ax , 0\n";
		(yyval.s) -> assemblyCode += "je " + string(label1);
		(yyval.s) -> assemblyCode += "mov " + string(temp) + " ,  1\n";
		(yyval.s) -> assemblyCode += "jmp " + string(label2) + "\n";
		(yyval.s) -> assemblyCode += string(label1) + " : \n"; 
		(yyval.s) -> assemblyCode += "mov " + string(temp) + " , 0\n";
		(yyval.s) -> assemblyCode += string(label2) + " : \n";

		(yyval.s) -> setAsmVarName(string(temp));

		dataSegment.push_back(Data(string(temp) , "VAR", "0"));

	}
	else if ((yyvsp[-1].s)->getSymbolName() == "||")
	{
		 
		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
	    (yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 

		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() + " \n";
		(yyval.s) -> assemblyCode += "cmp ax , 0\n";
		(yyval.s) -> assemblyCode += "jne " + string(label1) + "\n" ;
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[0].s) -> getAsmVarName() + " \n";
		(yyval.s) -> assemblyCode += "cmp ax , 0\n";
		(yyval.s) -> assemblyCode += "jne " + string(label1);
		(yyval.s) -> assemblyCode += "mov " + string(temp) + " ,  0\n";
		(yyval.s) -> assemblyCode += "jmp " + string(label2) + "\n";
		(yyval.s) -> assemblyCode += string(label1) + " : \n"; 
		(yyval.s) -> assemblyCode += "mov " + string(temp) + " , 1\n";
		(yyval.s) -> assemblyCode += string(label2) + " : \n";

		(yyval.s) -> setAsmVarName(string(temp));

		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
 
	}

	tem->codeSegment = (yyvsp[-2].s)->codeSegment + (yyvsp[-1].s)->getSymbolName() + (yyvsp[0].s)->codeSegment;
	
}
#line 3053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1508 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "rel_expression	: simple_expression" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 3068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1519 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "rel_expression	: simple_expression RELOP simple_expression" << endl
			<< endl;

	plogout << (yyvsp[-2].s)->codeSegment << (yyvsp[-1].s)->getSymbolName() << (yyvsp[0].s)->codeSegment << endl
			<< endl;


		char* temp = newTemp();
		char *label1=newLabel();
		char *label2=newLabel();

	if ((yyvsp[-1].s)->getSymbolName() == "==")
	{
		if ((yyvsp[-2].s)->getVarType() != (yyvsp[0].s)->getVarType())
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
					<< "Type mismatch on both side of == operator." << endl
					<< endl;
		}
		else
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				SymbolInfo *tem = new SymbolInfo("IIEQUAL", "ID");
				tem->setVarType("INT");
				tem->setIdType("VAR");
				tem->intVarValue = (int)((yyvsp[-2].s)->intVarValue == (yyvsp[0].s)->intVarValue);
				(yyval.s) = tem;
			}
			if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				SymbolInfo *tem = new SymbolInfo("FFEQUAL", "ID");
				tem->setVarType("INT");
				tem->setIdType("VAR");
				tem->intVarValue = (int)((yyvsp[-2].s)->floatVarValue == (yyvsp[0].s)->floatVarValue);
				(yyval.s) = tem;
			}
		}


		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
		
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName()  + "\n" ; 
		(yyval.s) -> assemblyCode += "cmp ax , " + (yyvsp[0].s) -> getAsmVarName() + "\n" ; 

		(yyval.s) -> assemblyCode += "je " + string(label1) + "\n";

	}
	else if ((yyvsp[-1].s)->getSymbolName() == "!=")
	{
		if ((yyvsp[-2].s)->getVarType() != (yyvsp[0].s)->getVarType())
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : "
					<< "Type mismatch on both side of != operator." << endl
					<< endl;
		}
		else
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				SymbolInfo *tem = new SymbolInfo("IINotEQUAL", "ID");
				tem->setVarType("INT");
				tem->setIdType("VAR");
				(yyval.s) = tem;
			}
			if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				SymbolInfo *tem = new SymbolInfo("FFNotEQUAL", "ID");
				tem->setVarType("INT");
				tem->setIdType("VAR");
				(yyval.s) = tem;
			}
		}

		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
		
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) ->  getAsmVarName()  + "\n" ; 
		(yyval.s) -> assemblyCode += "cmp ax , " + (yyvsp[0].s) ->  getAsmVarName()   + "\n" ; 

		(yyval.s) -> assemblyCode += "jne " + string(label1) + "\n";

	}
	else if ((yyvsp[-1].s)->getSymbolName() == ">=")
	{
		(yyval.s) = relationOperator((yyvsp[-2].s), (yyvsp[-1].s), 1);

		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
		
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName()   + "\n" ; 
		(yyval.s) -> assemblyCode += "cmp ax , " + (yyvsp[0].s) -> getAsmVarName()   + "\n" ; 

		(yyval.s) -> assemblyCode += "jge " + string(label1) + "\n";
	}
	else if ((yyvsp[-1].s)->getSymbolName() == ">")
	{
		(yyval.s) = relationOperator((yyvsp[-2].s), (yyvsp[-1].s), 2);

		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
		
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName()   + "\n" ; 
		(yyval.s) -> assemblyCode += "cmp ax , " + (yyvsp[0].s) -> getAsmVarName()   + "\n" ; 

		(yyval.s) -> assemblyCode += "jg " + string(label1) + "\n";

	}
	else if ((yyvsp[-1].s)->getSymbolName() == "<=")
	{
		(yyval.s) = relationOperator((yyvsp[-2].s), (yyvsp[-1].s), 3);

		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
		
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName()   + "\n" ; 
		(yyval.s) -> assemblyCode += "cmp ax , " + (yyvsp[0].s) -> getAsmVarName()   + "\n" ; 

		(yyval.s) -> assemblyCode += "jle " + string(label1) + "\n";

	}
	else if ((yyvsp[-1].s)->getSymbolName() == "<")
	{
		(yyval.s) = relationOperator((yyvsp[-2].s), (yyvsp[-1].s), 4);

		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 
		
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) ->getAsmVarName()   + "\n" ; 
		(yyval.s) -> assemblyCode += "cmp ax , " + (yyvsp[0].s) ->getAsmVarName()   + "\n" ; 

		(yyval.s) -> assemblyCode += "jl " + string(label1) + "\n";
	}

	(yyval.s) -> assemblyCode += "mov " + string(temp) + " , 0\n"; 
	(yyval.s) -> assemblyCode += "jmp " + string(label2) + "\n";
	(yyval.s) -> assemblyCode += string(label1) + " :  \n" ; 
	(yyval.s) -> assemblyCode += "mov " + string(temp) + " , 1\n";

	(yyval.s) -> assemblyCode += string(label2) + " : \n";
	(yyval.s) -> setAsmVarName(string(temp));
	dataSegment.push_back(Data(string(temp) , "VAR", "0"));

	plogout << (yyvsp[-2].s)->codeSegment << (yyvsp[-1].s)->getSymbolName() << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s)->codeSegment = (yyvsp[-2].s)->codeSegment + (yyvsp[-1].s)->getSymbolName() + (yyvsp[0].s)->codeSegment;
}
#line 3226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1674 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "simple_expression : term" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 3241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 1685 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "simple_expression : simple_expression ADDOP term" << endl
			<< endl;

	plogout << (yyvsp[-2].s)->codeSegment << (yyvsp[-1].s)->getSymbolName() << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[-2].s) ; 

	if ((yyvsp[-1].s)->getSymbolName() == "+")
	{
		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 

		char* temp = newTemp();
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() + "\n";
		(yyval.s) -> assemblyCode += "add ax , " + (yyvsp[0].s) -> getAsmVarName() + "\n";
		(yyval.s) -> assemblyCode += "mov " + string(temp) +  " , ax\n"; 
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		(yyval.s) -> setAsmVarName(string(temp));
	}
	else if ((yyvsp[-1].s)->getSymbolName() == "-")
	{
		(yyval.s) -> assemblyCode = (yyvsp[-2].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += (yyvsp[0].s) -> assemblyCode ; 

		char* temp = newTemp();
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() + "\n";
		(yyval.s) -> assemblyCode += "sub ax , " + (yyvsp[0].s) -> getAsmVarName() + "\n";
		(yyval.s) -> assemblyCode += "mov " + string(temp) + " , ax \n"; 
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		(yyval.s) -> setAsmVarName(string(temp));
	}

	//plogout << $1 -> codeSegment << " " << $2 -> getSymbolName() << $3 -> codeSegment ;

	(yyval.s)->codeSegment = (yyvsp[-2].s)->codeSegment + (yyvsp[-1].s)->getSymbolName() + (yyvsp[0].s)->codeSegment;
}
#line 3285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1726 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "term :	unary_expression" << endl
			<< endl;
	(yyval.s) = (yyvsp[0].s);
}
#line 3296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1733 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "term :	term MULOP unary_expression" << endl
			<< endl;

	plogout << (yyvsp[-2].s)->codeSegment << " " << (yyvsp[-1].s)->getSymbolName() << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	if ((yyvsp[-1].s)->getSymbolName() == "*")
	{

		if ((yyvsp[-2].s)->getIdType() == "VAR" && (yyvsp[0].s)->getIdType() == "VAR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VVIIM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = VVIFM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VVFIM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = VVFFM((yyvsp[-2].s), (yyvsp[0].s));
			}
		}
		else if ((yyvsp[-2].s)->getIdType() == "VAR" && (yyvsp[0].s)->getIdType() == "ARR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VAIIM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = VAIFM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VAFIM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = VAFFM((yyvsp[-2].s), (yyvsp[0].s));
			}
		}
		else if ((yyvsp[-2].s)->getIdType() == "ARR" && (yyvsp[0].s)->getIdType() == "VAR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AVIIM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = AVIFM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AVFIM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = AVFFM((yyvsp[-2].s), (yyvsp[0].s));
			}
		}
		else if ((yyvsp[-2].s)->getIdType() == "ARR" && (yyvsp[0].s)->getIdType() == "ARR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AAIIM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = AAIFM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AAFIM((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = AAFFM((yyvsp[-2].s), (yyvsp[0].s));
			}
		}

		char* temp = newTemp();
		(yyval.s) -> assemblyCode =  (yyvsp[-2].s) -> assemblyCode + (yyvsp[0].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() + "\n";
		(yyval.s) -> assemblyCode += "mov bx , " + (yyvsp[0].s) -> getAsmVarName() + "\n"; 
		(yyval.s) -> assemblyCode += "mul bx\n";
		(yyval.s) -> assemblyCode += "mov " + string(temp) + " , ax\n";
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		(yyval.s) -> setAsmVarName(string(temp));


	}
	else if ((yyvsp[-1].s)->getSymbolName() == "/")
	{
		if ((yyvsp[-2].s)->getIdType() == "VAR" && (yyvsp[0].s)->getIdType() == "VAR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VVIID((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = VVIFD((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VVFID((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = VVFFD((yyvsp[-2].s), (yyvsp[0].s));
			}
		}
		else if ((yyvsp[-2].s)->getIdType() == "VAR" && (yyvsp[0].s)->getIdType() == "ARR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VAIID((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = VAIFD((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VAFID((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = VAFFD((yyvsp[-2].s), (yyvsp[0].s));
			}
		}
		else if ((yyvsp[-2].s)->getIdType() == "ARR" && (yyvsp[0].s)->getIdType() == "VAR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AVIID((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = AVIFD((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AVFID((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = AVFFD((yyvsp[-2].s), (yyvsp[0].s));
			}
		}
		else if ((yyvsp[-2].s)->getIdType() == "ARR" && (yyvsp[0].s)->getIdType() == "ARR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AAIID((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = AAIFD((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AAFID((yyvsp[-2].s), (yyvsp[0].s));
			}
			else if ((yyvsp[-2].s)->getVarType() == "FLOAT" && (yyvsp[0].s)->getVarType() == "FLOAT")
			{
				(yyval.s) = AAFFD((yyvsp[-2].s), (yyvsp[0].s));
			}
		}


		char* temp = newTemp();
		(yyval.s) -> assemblyCode =  (yyvsp[-2].s) -> assemblyCode + (yyvsp[0].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += "xor dx , dx\n";
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() + "\n";
		(yyval.s) -> assemblyCode += "mov bx , " + (yyvsp[0].s) -> getAsmVarName() + "\n"; 
		(yyval.s) -> assemblyCode += "div bx\n";
		(yyval.s) -> assemblyCode += "mov " + string(temp) + " , ax\n";
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		(yyval.s) -> setAsmVarName(string(temp));

	}

	else if ((yyvsp[-1].s)->getSymbolName() == "%")
	{
		if ((yyvsp[-2].s)->getIdType() == "VAR" && (yyvsp[0].s)->getIdType() == "VAR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VVIIMOD((yyvsp[-2].s), (yyvsp[0].s));
			}
			else
			{
				modNotBothIntError();
			}
		}
		else if ((yyvsp[-2].s)->getIdType() == "VAR" && (yyvsp[0].s)->getIdType() == "ARR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = VAIIMOD((yyvsp[-2].s), (yyvsp[0].s));
			}
			else
			{
				modNotBothIntError();
			}
		}
		else if ((yyvsp[-2].s)->getIdType() == "ARR" && (yyvsp[0].s)->getIdType() == "VAR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AVIIMOD((yyvsp[-2].s), (yyvsp[0].s));
			}
			else
			{
				modNotBothIntError();
			}
		}
		else if ((yyvsp[-2].s)->getIdType() == "ARR" && (yyvsp[0].s)->getIdType() == "ARR")
		{
			if ((yyvsp[-2].s)->getVarType() == "INT" && (yyvsp[0].s)->getVarType() == "INT")
			{
				(yyval.s) = AAIIMOD((yyvsp[-2].s), (yyvsp[0].s));
			}
			else
			{
				modNotBothIntError();
			}
		}

		char* temp = newTemp();
		(yyval.s) -> assemblyCode =  (yyvsp[-2].s) -> assemblyCode + (yyvsp[0].s) -> assemblyCode ; 
		(yyval.s) -> assemblyCode += "xor dx , dx\n";
		(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-2].s) -> getAsmVarName() + "\n";
		(yyval.s) -> assemblyCode += "mov bx , " + (yyvsp[0].s) -> getAsmVarName() + "\n"; 
		(yyval.s) -> assemblyCode += "div bx\n";
		(yyval.s) -> assemblyCode += "mov " + string(temp) + " , dx\n";
		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		(yyval.s) -> setAsmVarName(string(temp));


	}

	//plogout << $1 -> codeSegment << " " << $2 -> getSymbolName() << $3 -> codeSegment << endl << endl ;

	(yyval.s)->codeSegment = (yyvsp[-2].s)->codeSegment + (yyvsp[-1].s)->getSymbolName() + (yyvsp[0].s)->codeSegment;
}
#line 3556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1990 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "unary_expression : ADDOP unary_expression " << endl
			<< endl;

	plogout << (yyvsp[-1].s)->getSymbolName() << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	SymbolInfo *tem = (yyvsp[0].s);

	tem->codeSegment = (yyvsp[-1].s)->getSymbolName() + (yyvsp[0].s)->codeSegment;

	if ((yyvsp[-1].s)->getSymbolName() == "-")
	{
		char* temp = newTemp();
		(yyvsp[0].s) -> assemblyCode += "mov ax , " + (yyvsp[0].s) -> getAsmVarName() + "\n";
		(yyvsp[0].s) -> assemblyCode += "neg ax\n" ; 
		(yyvsp[0].s) -> assemblyCode += "mov " + string(temp) + " , ax\n"; 
		(yyvsp[0].s) -> setAsmVarName(string(temp));

		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		//asmout << $2 -> assemblyCode << endl ; 

			if (tem->getVarType() == "CHAR")
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Can not put " << (yyvsp[-1].s)->getSymbolName() << "operator before Char variable \"" << (yyvsp[0].s)->getSymbolName() << endl
						<< endl;
			}
	}
	else if ((yyvsp[-1].s)->getSymbolName() == "+")
	{
			if (tem->getVarType() == "CHAR")
			{
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Can not put " << (yyvsp[-1].s)->getSymbolName() << "operator before Char variable \"" << (yyvsp[0].s)->getSymbolName() << endl
						<< endl;
			}
	}

	(yyval.s) = tem;
}
#line 3603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 2033 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "unary_expression : NOT unary_expression" << endl
			<< endl;

	plogout << "!" << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	SymbolInfo *tem = (yyvsp[0].s);

		char* temp = newTemp();
		(yyvsp[0].s) -> assemblyCode += "mov ax , " + (yyvsp[0].s) -> getAsmVarName() + "\n";
		(yyvsp[0].s) -> assemblyCode += "not ax\n" ; 
		(yyvsp[0].s) -> assemblyCode += "mov " + string(temp) + " , ax\n"; 
		(yyvsp[0].s) -> setAsmVarName(string(temp));

		dataSegment.push_back(Data(string(temp) , "VAR", "0"));
		//asmout << $2 -> assemblyCode << endl ; 

		tem->codeSegment = "!" + (yyvsp[0].s)->codeSegment;

		(yyval.s) = tem;
}
#line 3631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 2057 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "unary_expression : NOT unary_expression" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 3646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 2069 "1505038.y" /* yacc.c:1646  */
    {
	(yyval.s) = (yyvsp[0].s);
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: variable " << endl
			<< endl;

			plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

			if((yyvsp[0].s) -> getIdType() == "ARR")
			{
				char* temp = newTemp();
				(yyvsp[0].s) -> assemblyCode +=  "mov ax , " + (yyvsp[0].s) -> getAsmVarName() + "[bx]\n" ;
				(yyvsp[0].s) -> assemblyCode += "mov "+string(temp)+ " , ax\n" ; 
				(yyvsp[0].s) -> setAsmVarName(string(temp));

				dataSegment.push_back(Data(string(temp) , "VAR" , "0"));
			}
}
#line 3670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 2089 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: ID LPAREN argument_list RPAREN  " << endl
			<< endl;

	plogout << (yyvsp[-3].s)->getSymbolName() << "(" << (yyvsp[-1].s)->codeSegment << ")" << endl
			<< endl;

	SymbolInfo *tem = myTable->lookUp((yyvsp[-3].s)->getSymbolName(), "ID");
	//cout << tem -> getSymbolName() << " " <<  tem -> getFuncReturnType() << endl ;

	//cout << passedParamNo << endl ;
	if (tem == 0)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function \"" << (yyvsp[-3].s)->getSymbolName() << "\" wasn't declared before." << endl
				<< endl;
	}
	if (tem->isFuncDefined == false)
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Undefined call to Function " << (yyvsp[-3].s)->getSymbolName() << "." << endl
				<< endl;
	}
	if (passedParamNo < tem->getParamNo())
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Too few arguments for function " << (yyvsp[-3].s)->getSymbolName() << "." << endl
				<< endl;
		passedParamNo = 0;
	}
	if (passedParamNo > tem->getParamNo())
	{
		errorNo++;
		perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Too many arguments for function " << (yyvsp[-3].s)->getSymbolName() << "." << endl
				<< endl;
		passedParamNo = 0;
	}
	else
	{
		if (tem->getIdType() != "FUNC")
		{
			errorNo++;
			perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Function \"" << (yyvsp[-3].s)->getSymbolName() << "\" wasn't declared before." << endl
					<< endl;
		}
		else
		{
			if (tem->getFuncReturnType() == "VOID")
			{
				//cout << "RUMMAN" << endl ;
				errorNo++;
				perrout << "Error No: " << errorNo << " at line no: " << lineCount << " : Return type of function \"" << (yyvsp[-3].s)->getSymbolName() << "\" is void. So, it can not be called to return a value." << endl
						<< endl;
			}
			else
			{
				SymbolInfo *t = new SymbolInfo("Factor", "ID");

				if (tem->getFuncReturnType() == "INT")
				{
					t->intVarValue = 0;
				}
				else if (tem->getFuncReturnType() == "FLOAT")
				{
					t->floatVarValue = 0;
				}
				else if (tem->getFuncReturnType() == "CHAR")
				{
					t->charVarValue = '\0';
				}

				t->codeSegment = t->codeSegment + (yyvsp[-3].s)->getSymbolName() + "(" + (yyvsp[-1].s)->codeSegment + ")";

				(yyval.s) = t;
			}
		}
	}
}
#line 3754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 2169 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: LPAREN expression RPAREN " << endl
			<< endl;

	plogout << "(" << (yyvsp[-1].s)->codeSegment << ")" << endl
			<< endl;

	(yyvsp[-1].s)->codeSegment = "(" + (yyvsp[-1].s)->codeSegment + ")";

	(yyval.s) = (yyvsp[-1].s);
}
#line 3771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 2182 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: CONST_INT " << endl
			<< endl;

	plogout << (yyvsp[0].s)->getSymbolName() << endl
			<< endl;

	SymbolInfo *tem = (yyvsp[0].s);
	tem->setVarType("INT");
	tem->setIdType("VAR");

	tem->codeSegment = tem->codeSegment + (yyvsp[0].s)->getSymbolName();

	tem -> asmVarName = tem->getSymbolName() ; 
	(yyval.s) = tem;
}
#line 3793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 2200 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: CONST_FLOAT " << endl
			<< endl;

	plogout << (yyvsp[0].s)->getSymbolName() << endl
			<< endl;

	SymbolInfo *tem = (yyvsp[0].s);
	tem->setVarType("FLOAT");
	tem->setIdType("VAR");

	tem->codeSegment = tem->codeSegment + (yyvsp[0].s)->getSymbolName();

	tem -> asmVarName = tem->getSymbolName() ; 

	(yyval.s) = tem;
}
#line 3816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 2219 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: variable INCOP " << endl
			<< endl;

	plogout << (yyvsp[-1].s)->codeSegment << "++" << endl
			<< endl;

	SymbolInfo *tem = (yyvsp[-1].s);
	(yyval.s) = tem;

	if (tem->getIdType() == "VAR")
	{
		if (tem->getVarType() == "INT")
		{
			(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-1].s) -> getAsmVarName() + "\n" ; 
			(yyval.s) -> assemblyCode += "inc ax\n"; 
			(yyval.s) -> assemblyCode += "mov " + (yyvsp[-1].s) -> getAsmVarName() + " , ax\n" ; 
			(yyval.s) -> setAsmVarName((yyvsp[-1].s) -> getAsmVarName());
		}
	}
	else if (tem->getIdType() == "ARR")
	{
		if (tem->getVarType() == "INT")
		{
			char* temp = newTemp();
			(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-1].s) -> getAsmVarName() + "[bx]\n"; 
			(yyval.s) -> assemblyCode += "inc ax\n";
			(yyval.s) -> assemblyCode += "mov " + (yyvsp[-1].s) -> getAsmVarName() + "[bx] , ax\n" ; 
			(yyval.s) -> assemblyCode += "mov " + string(temp) + " ,  " + (yyvsp[-1].s) -> getAsmVarName() + "[bx]\n"; 
			(yyval.s) -> setAsmVarName(string(temp)); 
			dataSegment.push_back(Data(string(temp)  , "VAR", "0"));
		}
	}

	//asmout << "incop  " <<  $$ -> assemblyCode << endl ; 

	tem->codeSegment = tem->codeSegment + "++";
}
#line 3860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 2259 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "factor	: variable DECOP " << endl
			<< endl;

	plogout << (yyvsp[-1].s)->codeSegment << "--" << endl
			<< endl;

	SymbolInfo *tem = (yyvsp[-1].s);
	(yyval.s) = tem;


	if (tem->getIdType() == "VAR")
	{
		if (tem->getVarType() == "INT")
		{
			(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-1].s) -> getAsmVarName() + "\n" ; 
			(yyval.s) -> assemblyCode += "dec ax\n"; 
			(yyval.s) -> assemblyCode += "mov " + (yyvsp[-1].s) -> getAsmVarName() + "  ,  ax\n" ; 
			(yyval.s) -> setAsmVarName((yyvsp[-1].s) -> getAsmVarName());
		}
	}
	else if (tem->getIdType() == "ARR")
	{
		if (tem->getVarType() == "INT")
		{
			char* temp = newTemp();
			(yyval.s) -> assemblyCode += "mov ax , " + (yyvsp[-1].s) -> getAsmVarName() + "[bx]\n"; 
			(yyval.s) -> assemblyCode += "dec ax\n";
			(yyval.s) -> assemblyCode += "mov " + (yyvsp[-1].s) -> getAsmVarName() + "[bx] , ax\n" ; 
			(yyval.s) -> assemblyCode += "mov " + string(temp) + " ,  " + (yyvsp[-1].s) -> getAsmVarName() + "[bx]\n"; 
			(yyval.s) -> setAsmVarName(string(temp)); 
		  	dataSegment.push_back(Data(string(temp)  , "VAR", "0"));
		}
	}

	tem->codeSegment = tem->codeSegment + (yyvsp[-1].s)->codeSegment + "--";
}
#line 3903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 2299 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "argument_list : arguments" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	(yyval.s) = (yyvsp[0].s);
}
#line 3918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 2310 "1505038.y" /* yacc.c:1646  */
    {
	initializeParam();
	SymbolInfo *x = new SymbolInfo();

	(yyval.s) = x;
	(yyval.s)->codeSegment = " ";
}
#line 3930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 2319 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "arguments : arguments COMMA logic_expression " << endl
			<< endl;
	passedParamNo++;

	plogout << (yyvsp[-2].s)->codeSegment << " , " << (yyvsp[0].s)->codeSegment << endl
			<< endl;

	SymbolInfo *x = new SymbolInfo();

	(yyval.s) = x;
	(yyval.s)->codeSegment = (yyvsp[-2].s)->codeSegment + "," + (yyvsp[0].s)->codeSegment;
}
#line 3949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 2334 "1505038.y" /* yacc.c:1646  */
    {
	plogout << "At line no: " << lineCount << " : "
			<< "arguments : logic_expression" << endl
			<< endl;

	plogout << (yyvsp[0].s)->codeSegment << endl;

	passedParamNo++;

	(yyval.s) = (yyvsp[0].s);

}
#line 3966 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3970 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
  return yyresult;
}
#line 2347 "1505038.y" /* yacc.c:1906  */


int main(int argc, char *argv[])
{
	FILE *fp;

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Cannot Open Input File No. 1.\n");
		exit(1);
	}

	asmout.open("assembly.asm");
	plogout.open("plog.txt");
	perrout.open("perror.txt");

	//asmout << "gkh" << endl ; 

	yyin = fp;
	yyparse();

	plogout.close();
	perrout.close();
	asmout.close();

	return 0;
}
