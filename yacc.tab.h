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
    INTEGER = 258,
    STRING = 259,
    CHAR = 260,
    REAL = 261,
    ID = 262,
    SYS_CON = 263,
    SYS_TYPE = 264,
    SYS_PROC = 265,
    SYS_FUNCT = 266,
    SYS_CON_TRUE = 267,
    SYS_CON_FALSE = 268,
    SYS_CON_MAXINT = 269,
    SYS_TYPE_INTEGER = 270,
    SYS_TYPE_REAL = 271,
    SYS_TYPE_CHAR = 272,
    SYS_TYPE_BOOL = 273,
    SYS_FUNCT_ABS = 274,
    SYS_FUNCT_CHR = 275,
    SYS_FUNCT_ODD = 276,
    SYS_FUNCT_ORD = 277,
    SYS_FUNCT_PRED = 278,
    SYS_FUNCT_SQR = 279,
    SYS_FUNCT_SQRT = 280,
    SYS_FUNCT_SUCC = 281,
    SYS_PROC_WRITE = 282,
    SYS_PROC_WRITELN = 283,
    DOT = 284,
    PROGRAM = 285,
    SEMI = 286,
    CONST = 287,
    EQUAL = 288,
    TYPE = 289,
    ARRAY = 290,
    LB = 291,
    RB = 292,
    OF = 293,
    RECORD = 294,
    END = 295,
    COLON = 296,
    COMMA = 297,
    LP = 298,
    RP = 299,
    DOTDOT = 300,
    MINUS = 301,
    VAR = 302,
    FUNCTION = 303,
    PROCEDURE = 304,
    ASSIGN = 305,
    READ = 306,
    PBEGIN = 307,
    IF = 308,
    THEN = 309,
    ELSE = 310,
    REPEAT = 311,
    UNTIL = 312,
    WHILE = 313,
    DO = 314,
    FOR = 315,
    TO = 316,
    DOWNTO = 317,
    CASE = 318,
    GOTO = 319,
    GE = 320,
    GT = 321,
    LE = 322,
    LT = 323,
    UNEQUAL = 324,
    PLUS = 325,
    OR = 326,
    MUL = 327,
    DIV = 328,
    RDIV = 329,
    MOD = 330,
    AND = 331,
    NOT = 332
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "yacc.y" /* yacc.c:1909  */

    int iValue;
    char* sValue;
    char cValue;
    double rValue;
    int sIndex;
    int sysType;
    int syscon;
    int sysProc;
    int sysFunc;

#line 144 "yacc.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
