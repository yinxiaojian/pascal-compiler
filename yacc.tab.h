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

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
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
    T_PROGRAM = 258,
    T_CONST = 259,
    T_TYPE = 260,
    T_VAR = 261,
    T_FUNCTION = 262,
    T_PROCEDURE = 263,
    T_INT = 264,
    T_REAL = 265,
    T_ID = 266,
    T_CHAR = 267,
    T_STRING = 268,
    T_BEGIN = 269,
    T_END = 270,
    T_TRUE = 271,
    T_FALSE = 272,
    T_MAXINT = 273,
    T_READ = 274,
    T_WRITE = 275,
    T_WRITELN = 276,
    T_ABS = 277,
    T_CHR = 278,
    T_ODD = 279,
    T_ORD = 280,
    T_PRED = 281,
    T_SQR = 282,
    T_SQRT = 283,
    T_SUCC = 284,
    T_IF = 285,
    T_THEN = 286,
    T_ELSE = 287,
    T_REPEAT = 288,
    T_UNTIL = 289,
    T_WHILE = 290,
    T_DO = 291,
    T_CASE = 292,
    T_TO = 293,
    T_DOWNTO = 294,
    T_FOR = 295,
    T_EQUAL = 296,
    T_UNEQUAL = 297,
    T_GE = 298,
    T_GT = 299,
    T_LE = 300,
    T_LT = 301,
    T_ASSIGN = 302,
    T_PLUS = 303,
    T_MINUS = 304,
    T_MUL = 305,
    T_DIV = 306,
    T_OR = 307,
    T_AND = 308,
    T_NOT = 309,
    T_MOD = 310,
    T_LB = 311,
    T_RB = 312,
    T_LP = 313,
    T_RP = 314,
    T_SEMI = 315,
    T_DOT = 316,
    T_DOTDOT = 317,
    T_COMMA = 318,
    T_COLON = 319,
    T_INTEGER_TYPE = 320,
    T_BOOLEAN_TYPE = 321,
    T_CHAR_TYPE = 322,
    T_REAL_TYPE = 323,
    T_STRING_TYPE = 324,
    T_ARRAY = 325,
    T_OF = 326,
    T_RECORD = 327,
    T_GOTO = 328,
    ERROR = 329
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "yacc.y" /* yacc.c:1909  */

    int ival;
	double dval;
    char* sval;
	TreeNode node;

#line 136 "yacc.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
