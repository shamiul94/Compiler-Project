/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 36 "Parser.y" /* yacc.c:1909  */

	SymbolInfo *s; 

#line 146 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
