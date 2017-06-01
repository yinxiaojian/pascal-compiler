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
#line 1 "yacc.y" /* yacc.c:339  */

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

extern "C"
{
    void yyerror(const char *s);
    extern int yylex(void);
    extern int line_no;
}

#line 80 "yacc.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yacc.tab.h".  */
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
#line 16 "yacc.y" /* yacc.c:355  */

    int iValue;
    char* sValue;
    char cValue;
    double rValue;
    int sIndex;
    int sysType;
    int syscon;
    int sysProc;
    int sysFunc;

#line 210 "yacc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "yacc.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  261

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   332

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    98,   102,   106,   110,   114,   117,   120,
     123,   125,   129,   131,   133,   135,   137,   141,   143,   146,
     148,   152,   156,   158,   160,   164,   166,   168,   170,   172,
     174,   176,   180,   184,   188,   190,   194,   198,   200,   204,
     206,   209,   211,   215,   219,   221,   223,   225,   226,   229,
     233,   238,   242,   246,   248,   251,   253,   257,   259,   263,
     267,   271,   275,   279,   281,   283,   285,   289,   291,   293,
     295,   297,   299,   301,   303,   305,   309,   311,   313,   317,
     319,   321,   323,   325,   329,   333,   335,   338,   342,   346,
     350,   352,   356,   360,   362,   366,   368,   372,   376,   378,
     382,   384,   386,   388,   390,   392,   394,   398,   400,   402,
     404,   408,   410,   412,   414,   416,   420,   422,   424,   426,
     428,   430,   432,   434,   436,   438,   442,   444
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "STRING", "CHAR", "REAL",
  "ID", "SYS_CON", "SYS_TYPE", "SYS_PROC", "SYS_FUNCT", "SYS_CON_TRUE",
  "SYS_CON_FALSE", "SYS_CON_MAXINT", "SYS_TYPE_INTEGER", "SYS_TYPE_REAL",
  "SYS_TYPE_CHAR", "SYS_TYPE_BOOL", "SYS_FUNCT_ABS", "SYS_FUNCT_CHR",
  "SYS_FUNCT_ODD", "SYS_FUNCT_ORD", "SYS_FUNCT_PRED", "SYS_FUNCT_SQR",
  "SYS_FUNCT_SQRT", "SYS_FUNCT_SUCC", "SYS_PROC_WRITE", "SYS_PROC_WRITELN",
  "DOT", "PROGRAM", "SEMI", "CONST", "EQUAL", "TYPE", "ARRAY", "LB", "RB",
  "OF", "RECORD", "END", "COLON", "COMMA", "LP", "RP", "DOTDOT", "MINUS",
  "VAR", "FUNCTION", "PROCEDURE", "ASSIGN", "READ", "PBEGIN", "IF", "THEN",
  "ELSE", "REPEAT", "UNTIL", "WHILE", "DO", "FOR", "TO", "DOWNTO", "CASE",
  "GOTO", "GE", "GT", "LE", "LT", "UNEQUAL", "PLUS", "OR", "MUL", "DIV",
  "RDIV", "MOD", "AND", "NOT", "$accept", "program", "program_head",
  "routine", "sub_routine", "routine_head", "label_part", "const_part",
  "const_expr_list", "const_value", "type_part", "type_decl_list",
  "type_definition", "type_decl", "simple_type_decl", "array_type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "name_list",
  "var_part", "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "compound_stmt", "stmt_list", "stmt", "non_label_stmt",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332
};
# endif

#define YYPACT_NINF -183

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-183)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,     6,    16,  -183,    13,  -183,    18,    33,    84,  -183,
    -183,  -183,  -183,  -183,   132,   101,   104,   109,   138,   139,
     107,   117,    58,   118,  -183,   122,    15,  -183,    15,   164,
      15,   169,  -183,   142,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,   121,   143,   149,   139,  -183,   168,    11,
     186,   176,    15,    15,    15,    15,    15,  -183,  -183,  -183,
    -183,    28,  -183,   141,    15,    15,    15,  -183,     8,   -32,
      23,  -183,   156,    53,   136,   203,  -183,  -183,   158,   121,
     248,  -183,  -183,    68,   168,  -183,   180,   184,    11,  -183,
     163,  -183,   166,  -183,   148,   210,   255,    -2,   255,    71,
     255,   151,   193,    15,    15,    15,   240,  -183,  -183,    15,
     171,    15,    15,    15,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,   171,    15,   329,  -183,   170,   157,
    -183,   167,   168,   168,   121,   161,   187,  -183,  -183,  -183,
     248,   204,  -183,   172,   172,  -183,  -183,  -183,  -183,    15,
     175,    15,  -183,    15,  -183,  -183,  -183,   249,    89,    92,
    -183,   -32,   162,   -32,   -32,   -32,   -32,   -32,    23,    23,
      23,  -183,  -183,  -183,  -183,   255,  -183,   197,   185,   191,
     145,  -183,  -183,   214,    47,     5,  -183,   128,    96,   183,
     121,  -183,   202,  -183,    -1,   199,  -183,   217,    33,   229,
     255,    15,   255,   255,  -183,  -183,  -183,   171,  -183,  -183,
    -183,    15,   171,   171,  -183,  -183,  -183,   208,  -183,  -183,
     248,  -183,    24,  -183,  -183,   168,   219,     4,  -183,   233,
     239,    47,  -183,  -183,  -183,   255,  -183,   234,   250,   254,
     251,   259,   121,  -183,   219,    -1,  -183,    47,    47,  -183,
     171,  -183,  -183,   248,  -183,  -183,  -183,  -183,  -183,  -183,
    -183
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     9,     3,
       2,    64,     4,    61,     0,    18,     0,     0,     8,     0,
      40,     0,    79,    81,    62,     0,     0,    64,     0,     0,
       0,     0,    69,     0,    66,    67,    68,    70,    71,    72,
      73,    74,    75,     0,     0,     0,    17,    20,     0,    48,
       0,     0,     0,     0,     0,     0,     0,    12,    15,    14,
      13,   116,    16,   118,     0,     0,     0,   120,     0,   106,
     110,   115,     0,     0,     0,     0,    97,    63,     0,     0,
       0,    19,    38,     0,    39,    42,     0,     0,     6,    46,
       0,    47,     0,    65,     0,     0,   127,     0,    76,     0,
      99,     0,     0,     0,     0,     0,     0,   123,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,    26,
      25,     0,     0,     0,     0,     0,     0,    22,    23,    24,
       0,     0,    41,    54,    54,    44,    45,     7,     7,     0,
       0,     0,    80,     0,    82,    83,   125,     0,     0,     0,
     121,   104,    86,   100,   101,   102,   103,   105,   108,   107,
     109,   111,   112,   113,   114,    87,    88,     0,     0,     0,
       0,    94,    10,     0,     0,     0,    35,     0,     0,     0,
       0,    21,     0,    37,     0,     0,    52,     0,     0,     0,
      78,     0,   126,    98,   124,   117,   119,     0,    84,    90,
      91,     0,     0,     0,    92,    93,    31,     0,    33,    34,
       0,    27,     0,    28,    43,     0,    60,     0,    56,     0,
       0,     0,    49,     5,    51,    77,    85,     0,     0,     0,
       0,     0,     0,    29,    59,     0,    53,     0,     0,    50,
       0,    96,    95,     0,    36,    30,    55,    57,    58,    89,
      32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -183,   144,   292,  -183,  -183,  -183,   -43,
    -183,  -183,   252,  -136,  -182,  -183,  -183,  -183,   111,  -122,
    -183,  -183,   213,  -183,   222,  -183,   223,  -183,   160,  -183,
      67,  -183,  -183,   115,    -6,   299,  -107,   269,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,   159,  -183,
    -183,   -21,   216,   -49,   -41,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   197,   198,     8,    15,    18,    67,
      20,    46,    47,   136,   137,   138,   139,   185,   186,    83,
      49,    84,    85,    88,    89,    90,    91,    92,   195,   227,
     228,   229,   230,    12,    32,    16,    33,    34,    35,    36,
      37,   208,    38,    39,    40,   211,    41,   180,   181,    42,
      99,    96,    69,    70,    71,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      78,    13,   217,   162,   192,    68,    82,    73,     1,    75,
     187,   188,    82,     4,   116,   101,     5,   176,    57,    58,
      59,    60,    61,    62,   107,   108,    63,    57,    58,    59,
      60,    95,    62,    98,   100,   245,   128,   135,   117,   118,
     151,   109,   152,   106,     9,   218,   225,    10,   246,   249,
      57,    58,    59,    60,   129,    62,   130,   102,    64,    86,
      87,    65,   110,   187,   103,   257,   258,   168,   169,   170,
     242,   104,   226,   111,   112,   113,   114,   115,   171,   172,
     173,   174,   157,   179,   241,    11,   109,    51,   158,   159,
     133,   189,    66,   134,    52,   119,   120,   135,   121,   122,
     236,    53,   175,   244,   177,   238,   239,    21,    54,   140,
     141,    22,   124,   153,    23,   154,    14,   260,   111,   112,
     113,   114,   115,   226,    57,    58,    59,    60,   200,    62,
     202,   151,   203,   205,   151,    19,   206,   179,   141,    17,
     221,   135,    43,   259,    24,    44,    45,   223,    57,    58,
      59,    60,   178,    62,    48,    25,    11,    26,    50,    21,
      27,    55,    28,    22,    29,    56,    23,    30,    31,   220,
     141,    74,    76,    77,    21,    82,    79,   135,    22,   243,
     235,    23,    80,    94,   105,   214,   125,   143,   135,   127,
     237,   144,    13,    22,   147,   155,    23,   148,   149,   255,
     156,   182,   183,   184,   135,   135,   190,    25,    11,    26,
     135,   193,    27,   123,    28,   194,    29,   207,   191,    30,
      31,   216,    25,    11,    26,   201,   212,    27,   222,    28,
     109,    29,   213,   224,    30,    31,   109,    25,    11,    26,
     231,   126,    27,   109,    28,   240,    29,   150,   232,    30,
      31,    57,    58,    59,    60,   129,    62,   130,   209,   210,
     234,   141,   111,   112,   113,   114,   115,   109,   111,   112,
     113,   114,   115,   109,   247,   111,   112,   113,   114,   115,
     248,   251,   109,   131,   160,   252,   204,   132,   109,   253,
     254,   133,   199,   250,   134,     7,   219,   142,    81,   111,
     112,   113,   114,   115,   196,   111,   112,   113,   114,   115,
     145,   146,   256,   233,   111,   112,   113,   114,   115,    93,
     111,   112,   113,   114,   115,   161,    72,   163,   164,   165,
     166,   167,    57,    58,    59,    60,   178,    62,     0,   215
};

static const yytype_int16 yycheck[] =
{
      43,     7,   184,   110,   140,    26,     7,    28,    30,    30,
     132,   133,     7,     7,    46,    56,     0,   124,     3,     4,
       5,     6,     7,     8,    65,    66,    11,     3,     4,     5,
       6,    52,     8,    54,    55,    31,    79,    80,    70,    71,
      42,    33,    44,    64,    31,    40,    47,    29,    44,   231,
       3,     4,     5,     6,     7,     8,     9,    29,    43,    48,
      49,    46,    54,   185,    36,   247,   248,   116,   117,   118,
      46,    43,   194,    65,    66,    67,    68,    69,   119,   120,
     121,   122,   103,   126,   220,    52,    33,    29,   104,   105,
      43,   134,    77,    46,    36,    72,    73,   140,    75,    76,
     207,    43,   123,   225,   125,   212,   213,     3,    50,    41,
      42,     7,    59,    42,    10,    44,    32,   253,    65,    66,
      67,    68,    69,   245,     3,     4,     5,     6,   149,     8,
     151,    42,   153,    44,    42,    34,    44,   180,    42,     7,
      44,   184,    33,   250,    40,     7,     7,   190,     3,     4,
       5,     6,     7,     8,    47,    51,    52,    53,    41,     3,
      56,    43,    58,     7,    60,    43,    10,    63,    64,    41,
      42,     7,     3,    31,     3,     7,    33,   220,     7,   222,
     201,    10,    33,     7,    43,    40,    50,     7,   231,    31,
     211,     7,   198,     7,    31,    44,    10,    31,    50,   242,
       7,    31,    45,    36,   247,   248,    45,    51,    52,    53,
     253,     7,    56,    57,    58,    43,    60,    55,    31,    63,
      64,     7,    51,    52,    53,    50,    41,    56,    45,    58,
      33,    60,    41,    31,    63,    64,    33,    51,    52,    53,
      41,    38,    56,    33,    58,    37,    60,    37,    31,    63,
      64,     3,     4,     5,     6,     7,     8,     9,    61,    62,
      31,    42,    65,    66,    67,    68,    69,    33,    65,    66,
      67,    68,    69,    33,    41,    65,    66,    67,    68,    69,
      41,    31,    33,    35,    44,    31,    37,    39,    33,    38,
      31,    43,   148,    59,    46,     3,   185,    84,    46,    65,
      66,    67,    68,    69,   144,    65,    66,    67,    68,    69,
      88,    88,   245,   198,    65,    66,    67,    68,    69,    50,
      65,    66,    67,    68,    69,   109,    27,   111,   112,   113,
     114,   115,     3,     4,     5,     6,     7,     8,    -1,   180
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    79,    80,     7,     0,    81,    83,    84,    31,
      29,    52,   111,   112,    32,    85,   113,     7,    86,    34,
      88,     3,     7,    10,    40,    51,    53,    56,    58,    60,
      63,    64,   112,   114,   115,   116,   117,   118,   120,   121,
     122,   124,   127,    33,     7,     7,    89,    90,    47,    98,
      41,    29,    36,    43,    50,    43,    43,     3,     4,     5,
       6,     7,     8,    11,    43,    46,    77,    87,   129,   130,
     131,   132,   113,   129,     7,   129,     3,    31,    87,    33,
      33,    90,     7,    97,    99,   100,    48,    49,   101,   102,
     103,   104,   105,   115,     7,   129,   129,   133,   129,   128,
     129,   132,    29,    36,    43,    43,   129,   132,   132,    33,
      54,    65,    66,    67,    68,    69,    46,    70,    71,    72,
      73,    75,    76,    57,    59,    50,    38,    31,    87,     7,
       9,    35,    39,    43,    46,    87,    91,    92,    93,    94,
      41,    42,   100,     7,     7,   102,   104,    31,    31,    50,
      37,    42,    44,    42,    44,    44,     7,   129,   133,   133,
      44,   130,   114,   130,   130,   130,   130,   130,   131,   131,
     131,   132,   132,   132,   132,   129,   114,   129,     7,    87,
     125,   126,    31,    45,    36,    95,    96,    97,    97,    87,
      45,    31,    91,     7,    43,   106,   106,    82,    83,    82,
     129,    50,   129,   129,    37,    44,    44,    55,   119,    61,
      62,   123,    41,    41,    40,   126,     7,    92,    40,    96,
      41,    44,    45,    87,    31,    47,    97,   107,   108,   109,
     110,    41,    31,   111,    31,   129,   114,   129,   114,   114,
      37,    91,    46,    87,    97,    31,    44,    41,    41,    92,
      59,    31,    31,    38,    31,    87,   108,    92,    92,   114,
      91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    80,    81,    82,    83,    84,    85,    85,
      86,    86,    87,    87,    87,    87,    87,    88,    88,    89,
      89,    90,    91,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    93,    94,    95,    95,    96,    97,    97,    98,
      98,    99,    99,   100,   101,   101,   101,   101,   101,   102,
     103,   104,   105,   106,   106,   107,   107,   108,   108,   109,
     110,   111,   112,   113,   113,   114,   114,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   116,   116,   116,   117,
     117,   117,   117,   117,   118,   119,   119,   120,   121,   122,
     123,   123,   124,   125,   125,   126,   126,   127,   128,   128,
     129,   129,   129,   129,   129,   129,   129,   130,   130,   130,
     130,   131,   131,   131,   131,   131,   132,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   133,   133
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     5,     0,     2,     0,
       5,     4,     1,     1,     1,     1,     1,     2,     0,     2,
       1,     4,     1,     1,     1,     1,     1,     3,     3,     4,
       5,     3,     6,     3,     2,     1,     4,     3,     1,     2,
       0,     2,     1,     4,     2,     2,     1,     1,     0,     4,
       5,     4,     3,     3,     0,     3,     1,     3,     3,     2,
       1,     1,     3,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     6,     5,     1,
       4,     1,     4,     4,     5,     2,     0,     4,     4,     8,
       1,     1,     5,     2,     1,     4,     4,     2,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     1,     4,     1,     4,
       1,     3,     2,     2,     4,     3,     3,     1
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
#line 95 "yacc.y" /* yacc.c:1646  */
    {}
#line 1519 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 99 "yacc.y" /* yacc.c:1646  */
    {}
#line 1525 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "yacc.y" /* yacc.c:1646  */
    {}
#line 1531 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "yacc.y" /* yacc.c:1646  */
    {}
#line 1537 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 111 "yacc.y" /* yacc.c:1646  */
    {}
#line 1543 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "yacc.y" /* yacc.c:1646  */
    {}
#line 1549 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 118 "yacc.y" /* yacc.c:1646  */
    {}
#line 1555 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 120 "yacc.y" /* yacc.c:1646  */
    {}
#line 1561 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 124 "yacc.y" /* yacc.c:1646  */
    {}
#line 1567 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 126 "yacc.y" /* yacc.c:1646  */
    { cout<<"CONST"<<(yyvsp[-3].sValue)<<" "<<(yyvsp[-1].iValue)<<endl;}
#line 1573 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 130 "yacc.y" /* yacc.c:1646  */
    {}
#line 1579 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 132 "yacc.y" /* yacc.c:1646  */
    {cout<<"REAL"<<(yyvsp[0].rValue)<<endl;(yyval.iValue)=2;}
#line 1585 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 134 "yacc.y" /* yacc.c:1646  */
    {}
#line 1591 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "yacc.y" /* yacc.c:1646  */
    {}
#line 1597 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 138 "yacc.y" /* yacc.c:1646  */
    {}
#line 1603 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 142 "yacc.y" /* yacc.c:1646  */
    {}
#line 1609 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "yacc.y" /* yacc.c:1646  */
    {}
#line 1615 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 147 "yacc.y" /* yacc.c:1646  */
    {}
#line 1621 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 149 "yacc.y" /* yacc.c:1646  */
    {}
#line 1627 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 153 "yacc.y" /* yacc.c:1646  */
    {}
#line 1633 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 157 "yacc.y" /* yacc.c:1646  */
    {}
#line 1639 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 159 "yacc.y" /* yacc.c:1646  */
    {}
#line 1645 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 161 "yacc.y" /* yacc.c:1646  */
    {}
#line 1651 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 165 "yacc.y" /* yacc.c:1646  */
    {}
#line 1657 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 167 "yacc.y" /* yacc.c:1646  */
    {}
#line 1663 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 169 "yacc.y" /* yacc.c:1646  */
    {}
#line 1669 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 171 "yacc.y" /* yacc.c:1646  */
    {}
#line 1675 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 173 "yacc.y" /* yacc.c:1646  */
    {}
#line 1681 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 175 "yacc.y" /* yacc.c:1646  */
    {}
#line 1687 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 177 "yacc.y" /* yacc.c:1646  */
    {}
#line 1693 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "yacc.y" /* yacc.c:1646  */
    {}
#line 1699 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 185 "yacc.y" /* yacc.c:1646  */
    {}
#line 1705 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 189 "yacc.y" /* yacc.c:1646  */
    {}
#line 1711 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 191 "yacc.y" /* yacc.c:1646  */
    {}
#line 1717 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 195 "yacc.y" /* yacc.c:1646  */
    {}
#line 1723 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 199 "yacc.y" /* yacc.c:1646  */
    {}
#line 1729 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 201 "yacc.y" /* yacc.c:1646  */
    {}
#line 1735 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 205 "yacc.y" /* yacc.c:1646  */
    {}
#line 1741 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 206 "yacc.y" /* yacc.c:1646  */
    {}
#line 1747 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 210 "yacc.y" /* yacc.c:1646  */
    {}
#line 1753 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 212 "yacc.y" /* yacc.c:1646  */
    {}
#line 1759 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 216 "yacc.y" /* yacc.c:1646  */
    {}
#line 1765 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 220 "yacc.y" /* yacc.c:1646  */
    {}
#line 1771 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 222 "yacc.y" /* yacc.c:1646  */
    {}
#line 1777 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 224 "yacc.y" /* yacc.c:1646  */
    {}
#line 1783 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 226 "yacc.y" /* yacc.c:1646  */
    {}
#line 1789 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 230 "yacc.y" /* yacc.c:1646  */
    {}
#line 1795 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 234 "yacc.y" /* yacc.c:1646  */
    {
    }
#line 1802 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 239 "yacc.y" /* yacc.c:1646  */
    {}
#line 1808 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 243 "yacc.y" /* yacc.c:1646  */
    {}
#line 1814 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 247 "yacc.y" /* yacc.c:1646  */
    {}
#line 1820 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 248 "yacc.y" /* yacc.c:1646  */
    {}
#line 1826 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 252 "yacc.y" /* yacc.c:1646  */
    {}
#line 1832 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 254 "yacc.y" /* yacc.c:1646  */
    {}
#line 1838 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 258 "yacc.y" /* yacc.c:1646  */
    {}
#line 1844 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 260 "yacc.y" /* yacc.c:1646  */
    {}
#line 1850 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 264 "yacc.y" /* yacc.c:1646  */
    {}
#line 1856 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 268 "yacc.y" /* yacc.c:1646  */
    {}
#line 1862 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 272 "yacc.y" /* yacc.c:1646  */
    {}
#line 1868 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 276 "yacc.y" /* yacc.c:1646  */
    {}
#line 1874 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 280 "yacc.y" /* yacc.c:1646  */
    {}
#line 1880 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 281 "yacc.y" /* yacc.c:1646  */
    {}
#line 1886 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 284 "yacc.y" /* yacc.c:1646  */
    {}
#line 1892 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 286 "yacc.y" /* yacc.c:1646  */
    {}
#line 1898 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 290 "yacc.y" /* yacc.c:1646  */
    {}
#line 1904 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 292 "yacc.y" /* yacc.c:1646  */
    {}
#line 1910 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 294 "yacc.y" /* yacc.c:1646  */
    {}
#line 1916 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 296 "yacc.y" /* yacc.c:1646  */
    {}
#line 1922 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 298 "yacc.y" /* yacc.c:1646  */
    {}
#line 1928 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 300 "yacc.y" /* yacc.c:1646  */
    {}
#line 1934 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 302 "yacc.y" /* yacc.c:1646  */
    {}
#line 1940 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 304 "yacc.y" /* yacc.c:1646  */
    {}
#line 1946 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 306 "yacc.y" /* yacc.c:1646  */
    {}
#line 1952 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 310 "yacc.y" /* yacc.c:1646  */
    {}
#line 1958 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 312 "yacc.y" /* yacc.c:1646  */
    {}
#line 1964 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 314 "yacc.y" /* yacc.c:1646  */
    {}
#line 1970 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 318 "yacc.y" /* yacc.c:1646  */
    {}
#line 1976 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 320 "yacc.y" /* yacc.c:1646  */
    {}
#line 1982 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 322 "yacc.y" /* yacc.c:1646  */
    {}
#line 1988 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 324 "yacc.y" /* yacc.c:1646  */
    {}
#line 1994 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 326 "yacc.y" /* yacc.c:1646  */
    {}
#line 2000 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 330 "yacc.y" /* yacc.c:1646  */
    {}
#line 2006 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 334 "yacc.y" /* yacc.c:1646  */
    {}
#line 2012 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 335 "yacc.y" /* yacc.c:1646  */
    {}
#line 2018 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 339 "yacc.y" /* yacc.c:1646  */
    {}
#line 2024 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 343 "yacc.y" /* yacc.c:1646  */
    {}
#line 2030 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 347 "yacc.y" /* yacc.c:1646  */
    {}
#line 2036 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 351 "yacc.y" /* yacc.c:1646  */
    {}
#line 2042 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 353 "yacc.y" /* yacc.c:1646  */
    {}
#line 2048 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 357 "yacc.y" /* yacc.c:1646  */
    {}
#line 2054 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 361 "yacc.y" /* yacc.c:1646  */
    {}
#line 2060 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 363 "yacc.y" /* yacc.c:1646  */
    {}
#line 2066 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 367 "yacc.y" /* yacc.c:1646  */
    {}
#line 2072 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 369 "yacc.y" /* yacc.c:1646  */
    {}
#line 2078 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 373 "yacc.y" /* yacc.c:1646  */
    {}
#line 2084 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 377 "yacc.y" /* yacc.c:1646  */
    {}
#line 2090 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 379 "yacc.y" /* yacc.c:1646  */
    {}
#line 2096 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 383 "yacc.y" /* yacc.c:1646  */
    {}
#line 2102 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 385 "yacc.y" /* yacc.c:1646  */
    {}
#line 2108 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 387 "yacc.y" /* yacc.c:1646  */
    {}
#line 2114 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 389 "yacc.y" /* yacc.c:1646  */
    {}
#line 2120 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 391 "yacc.y" /* yacc.c:1646  */
    {}
#line 2126 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 393 "yacc.y" /* yacc.c:1646  */
    {}
#line 2132 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 395 "yacc.y" /* yacc.c:1646  */
    {}
#line 2138 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 399 "yacc.y" /* yacc.c:1646  */
    {}
#line 2144 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 401 "yacc.y" /* yacc.c:1646  */
    {}
#line 2150 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 403 "yacc.y" /* yacc.c:1646  */
    {}
#line 2156 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 405 "yacc.y" /* yacc.c:1646  */
    {}
#line 2162 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 409 "yacc.y" /* yacc.c:1646  */
    {}
#line 2168 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 411 "yacc.y" /* yacc.c:1646  */
    {}
#line 2174 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 413 "yacc.y" /* yacc.c:1646  */
    {}
#line 2180 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 415 "yacc.y" /* yacc.c:1646  */
    {}
#line 2186 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 417 "yacc.y" /* yacc.c:1646  */
    {}
#line 2192 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 421 "yacc.y" /* yacc.c:1646  */
    {}
#line 2198 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 423 "yacc.y" /* yacc.c:1646  */
    {}
#line 2204 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 425 "yacc.y" /* yacc.c:1646  */
    {}
#line 2210 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 427 "yacc.y" /* yacc.c:1646  */
    {}
#line 2216 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 429 "yacc.y" /* yacc.c:1646  */
    {}
#line 2222 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 431 "yacc.y" /* yacc.c:1646  */
    {}
#line 2228 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 433 "yacc.y" /* yacc.c:1646  */
    {}
#line 2234 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 435 "yacc.y" /* yacc.c:1646  */
    {}
#line 2240 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 437 "yacc.y" /* yacc.c:1646  */
    {}
#line 2246 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 439 "yacc.y" /* yacc.c:1646  */
    {}
#line 2252 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 443 "yacc.y" /* yacc.c:1646  */
    {}
#line 2258 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 445 "yacc.y" /* yacc.c:1646  */
    {}
#line 2264 "yacc.tab.c" /* yacc.c:1646  */
    break;


#line 2268 "yacc.tab.c" /* yacc.c:1646  */
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
#line 448 "yacc.y" /* yacc.c:1906  */



void yyerror(const char *s)
{
	cerr<<s<<" | line:"<<line_no<<endl;					//out error information
}

