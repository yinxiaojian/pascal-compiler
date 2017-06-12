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
#include <string>
#include "absyn.h"
using namespace std;

extern "C"
{
    void yyerror(const char *s);
    extern int yylex(void);
    extern int line_no;

}
extern TreeNode savedTree;
extern vector<string> errMsg;

#line 84 "yacc.tab.c" /* yacc.c:339  */

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
#line 20 "yacc.y" /* yacc.c:355  */

    int ival;
	double dval;
    char* sval;
	TreeNode node;

#line 206 "yacc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 223 "yacc.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   521

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   329

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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    52,    52,    57,    63,    69,    76,    81,    90,    91,
     102,   113,   114,   116,   122,   129,   136,   144,   153,   154,
     157,   168,   171,   177,   184,   191,   199,   200,   203,   214,
     216,   221,   229,   230,   233,   246,   249,   256,   265,   271,
     277,   283,   289,   295,   301,   309,   310,   313,   325,   328,
     333,   340,   341,   342,   344,   347,   359,   361,   367,   375,
     383,   389,   394,   400,   408,   416,   423,   427,   431,   435,
     440,   452,   454,   458,   459,   460,   462,   463,   475,   489,
     495,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   513,   521,   529,   534,   540,   548,   549,   551,   557,
     559,   564,   569,   580,   581,   587,   593,   602,   611,   615,
     620,   626,   631,   635,   640,   651,   653,   654,   655,   656,
     657,   658,   659,   661,   662,   663,   664,   666,   667,   668,
     669,   670,   672,   674,   680,   681,   682,   686,   689,   694,
     699,   703,   707,   711,   716,   720,   724,   728
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_PROGRAM", "T_CONST", "T_TYPE",
  "T_VAR", "T_FUNCTION", "T_PROCEDURE", "T_INT", "T_REAL", "T_ID",
  "T_CHAR", "T_STRING", "T_BEGIN", "T_END", "T_TRUE", "T_FALSE",
  "T_MAXINT", "T_READ", "T_WRITE", "T_WRITELN", "T_ABS", "T_CHR", "T_ODD",
  "T_ORD", "T_PRED", "T_SQR", "T_SQRT", "T_SUCC", "T_IF", "T_THEN",
  "T_ELSE", "T_REPEAT", "T_UNTIL", "T_WHILE", "T_DO", "T_CASE", "T_TO",
  "T_DOWNTO", "T_FOR", "T_EQUAL", "T_UNEQUAL", "T_GE", "T_GT", "T_LE",
  "T_LT", "T_ASSIGN", "T_PLUS", "T_MINUS", "T_MUL", "T_DIV", "T_OR",
  "T_AND", "T_NOT", "T_MOD", "T_LB", "T_RB", "T_LP", "T_RP", "T_SEMI",
  "T_DOT", "T_DOTDOT", "T_COMMA", "T_COLON", "T_INTEGER_TYPE",
  "T_BOOLEAN_TYPE", "T_CHAR_TYPE", "T_REAL_TYPE", "T_STRING_TYPE",
  "T_ARRAY", "T_OF", "T_RECORD", "T_GOTO", "ERROR", "$accept", "program",
  "routine", "routine_head", "routine_part", "function_decl",
  "function_head", "parameters", "para_decl_list", "para_type_list",
  "procedure_decl", "procedure_head", "var_part", "var_decl_list",
  "var_decl", "const_part", "const_expr_list", "const_expr", "const_value",
  "type_part", "type_decl_list", "type_definition", "type_decl",
  "record_type_decl", "field_decl_list", "field_decl", "array_type_decl",
  "simple_type_decl", "name_list", "ID", "routine_body", "compound_stmt",
  "stmt_list", "stmt", "no_label_stmt", "assign_stmt", "goto_stmt",
  "if_stmt", "else_clause", "repeat_stmt", "while_stmt", "case_stmt",
  "case_expr_list", "case_expr", "for_stmt", "proc_stmt", "args_list",
  "expression", "expr", "term", "factor", YY_NULLPTR
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
     325,   326,   327,   328,   329
};
# endif

#define YYPACT_NINF -173

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-173)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      53,    -3,    30,     1,  -173,    68,    58,    71,    98,   119,
    -173,    68,  -173,    93,    87,  -173,  -173,  -173,  -173,    68,
     150,  -173,   209,  -173,   301,    68,  -173,   118,    68,    29,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,   107,   104,  -173,
     121,   134,   135,   457,  -173,   457,   457,    68,   186,   -18,
    -173,   140,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,   393,    68,  -173,     5,  -173,   192,   194,    29,
    -173,     7,  -173,   146,  -173,   403,   457,   457,   457,   151,
     153,   154,   156,   158,   159,   166,   174,   457,   457,   457,
    -173,   -43,   262,    -4,    -1,  -173,   328,   309,    95,   161,
    -173,   457,   457,   457,    68,  -173,   209,    68,  -173,  -173,
    -173,  -173,   177,    68,   172,   176,  -173,  -173,  -173,   175,
    -173,    68,   393,   180,   180,  -173,  -173,    58,   198,    58,
    -173,   181,   -42,   207,    -8,   457,   457,   457,   457,   457,
     457,   457,   457,  -173,  -173,    52,   457,   457,    68,   358,
     457,   457,   457,   457,   457,   457,   227,   457,   457,   457,
     457,   457,   457,   457,   457,   358,   478,   457,   207,   200,
       0,   213,   199,    12,    15,    63,  -173,    25,   209,  -173,
      68,  -173,   203,    28,   201,  -173,   206,  -173,   208,  -173,
    -173,   457,  -173,    27,    41,    46,    66,    67,    83,    88,
      91,  -173,   283,    99,  -173,   227,    -4,    -4,    -4,    -4,
      -4,    -4,   358,  -173,    -1,    -1,    -1,  -173,  -173,  -173,
    -173,   207,  -173,   210,   211,   437,  -173,   459,   220,  -173,
     457,   164,  -173,   215,  -173,  -173,   393,  -173,  -173,  -173,
      68,    47,  -173,    51,    15,  -173,  -173,   207,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
     358,   358,  -173,  -173,   457,   457,   457,   207,   209,  -173,
     216,   217,   100,  -173,    28,    15,  -173,   219,   224,   339,
     384,   207,  -173,   393,  -173,    15,  -173,  -173,  -173,  -173,
     358,   358,  -173,  -173,  -173,  -173
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    32,     1,     0,    32,     5,     0,    45,
      72,    33,    35,     0,     3,     4,    76,     6,    73,     0,
      26,    34,     0,     2,    75,    46,    48,     0,     0,     8,
      38,    39,    40,    41,    42,    43,    44,    37,     0,    74,
       0,     0,   112,     0,    76,     0,     0,     0,     0,   108,
      82,    78,    80,    81,    83,    84,    85,    86,    87,    88,
      89,    47,     0,    27,    29,     0,    71,     0,     0,     7,
      11,    32,    12,     0,    36,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   132,    99,   122,   126,   131,    99,     0,     0,     0,
      93,     0,     0,     0,     0,    77,     0,     0,    66,    67,
      69,    68,     0,     0,     0,    50,    53,    52,    51,    60,
      28,     0,     0,    18,    18,     9,    10,    32,    16,    32,
      79,     0,     0,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   136,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,    49,
       0,    70,    31,     0,     0,    25,    14,    15,     0,   110,
     111,     0,   113,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     0,     0,   139,    96,   120,   121,   116,   117,
     118,   119,    99,    95,   123,   124,   125,   127,   128,   130,
     129,    98,   100,     0,     0,     0,   103,     0,     0,   109,
       0,     0,    61,     0,    54,    55,     0,    62,    65,    30,
       0,     0,    21,     0,     0,    13,    24,   114,   140,   141,
     142,   143,   144,   145,   146,   147,   138,   133,    94,    97,
      99,    99,   101,   102,     0,     0,     0,    92,     0,    63,
       0,    58,     0,    19,     0,     0,    17,     0,     0,     0,
       0,    91,    64,     0,    57,     0,    20,    23,   104,   105,
      99,    99,    59,    22,   106,   107
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,     6,  -173,  -173,   221,  -173,   165,  -173,    14,
     222,  -173,  -173,  -173,   231,  -173,  -173,   285,   -21,  -173,
    -173,   273,  -118,  -173,  -173,   125,  -173,  -172,   -91,    -5,
    -173,   293,   265,   -89,   236,  -173,  -173,  -173,   108,  -173,
    -173,  -173,  -173,    89,  -173,  -173,    49,   -36,   366,    40,
     -41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,     8,    69,    70,    71,   184,   241,   242,
      72,    73,    29,    63,    64,     9,    11,    12,    90,    20,
      25,    26,   115,   116,   175,   176,   117,   118,    65,    91,
      17,    50,    24,    51,    52,    53,    54,    55,   213,    56,
      57,    58,   225,   226,    59,    60,   132,   133,    93,    94,
      95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      13,    37,   233,   156,   182,     5,    13,    92,     3,    97,
      98,     5,    14,   146,    27,   147,   173,   190,   148,    49,
      27,   191,   177,    66,    30,    31,    10,    32,    33,   101,
       4,    34,    35,    36,   240,   131,    67,    68,   102,    10,
     103,   114,    99,   104,   157,   158,   143,   144,   159,   160,
     161,   192,   162,   145,   163,   191,     1,   119,    66,   229,
     205,     6,     5,   191,   106,   168,   169,   127,   121,   122,
      49,   232,   276,   107,    10,   121,   222,   128,   234,    10,
     108,   109,   110,   111,   177,   172,   248,    49,   121,   236,
     191,    49,   243,   150,   151,   152,   153,   154,   155,   171,
     249,   114,    66,   287,   191,   250,   273,   274,    66,   191,
     202,   201,    16,   293,   121,   275,   181,   119,   271,   217,
     218,   219,   220,   259,    19,   251,   252,   134,   221,   191,
     191,   227,    15,   186,    22,   188,   150,   151,   152,   153,
     154,   155,   253,   204,    49,   223,   191,   254,    23,   272,
     255,   191,   170,   114,   191,   247,    28,   237,   257,    62,
      49,   224,   191,   121,   285,   292,   166,    74,    75,   119,
      66,   277,   278,    30,    31,   238,    32,    33,    66,    76,
      34,    35,    36,   243,   193,   194,   195,   196,   197,   198,
     199,   200,    77,    78,   267,   100,   203,   214,   215,   216,
     105,   294,   295,   123,   223,   124,   129,    49,   167,   135,
     269,   136,   137,   268,   138,   114,   139,   140,    30,    31,
     224,    32,    33,   114,   141,    34,    35,    36,   279,   280,
     281,   119,   142,   174,   178,    66,   179,   180,   183,   119,
     189,   150,   151,   152,   153,   154,   155,   282,   150,   151,
     152,   153,   154,   155,   114,    49,    49,   228,   187,   212,
     230,   231,   114,   239,   114,   244,   245,   266,   246,    66,
     119,    38,   270,    10,   260,   261,    16,   284,   119,   288,
     119,    40,    41,    42,   289,    49,    49,   283,   286,   185,
     125,   126,    43,   149,   120,    44,    21,    45,    61,    46,
     235,    18,    47,   150,   151,   152,   153,   154,   155,    96,
      38,   130,    10,   258,   263,    16,    39,     0,     0,     0,
      40,    41,    42,     0,   150,   151,   152,   153,   154,   155,
       0,    43,     0,     0,    44,    48,    45,    38,    46,    10,
     256,    47,    16,     0,     0,   165,     0,    40,    41,    42,
     150,   151,   152,   153,   154,   155,     0,     0,    43,     0,
       0,    44,   164,    45,     0,    46,     0,    38,    47,    10,
       0,     0,    16,     0,    48,   290,     0,    40,    41,    42,
     150,   151,   152,   153,   154,   155,     0,     0,    43,     0,
       0,    44,     0,    45,     0,    46,     0,     0,    47,     0,
       0,    48,    30,    31,    10,    32,    33,     0,     0,    34,
      35,    36,     0,     0,    10,     0,     0,    16,     0,     0,
     291,     0,    40,    41,    42,   150,   151,   152,   153,   154,
     155,    48,     0,    43,     0,     0,    44,     0,    45,     0,
      46,     0,   106,    47,     0,     0,    30,    31,    10,    32,
      33,   107,   262,    34,    35,    36,     0,     0,   108,   109,
     110,   111,     0,   112,     0,   113,    30,    31,    10,    32,
      33,     0,     0,    34,    35,    36,    48,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    30,    31,    10,
      32,    33,     0,     0,    34,    35,    36,   264,   265,     0,
     150,   151,   152,   153,   154,   155,    87,     0,     0,     0,
       0,    88,     0,     0,     0,    89,   206,   207,   208,   209,
     210,   211
};

static const yytype_int16 yycheck[] =
{
       5,    22,   174,    92,   122,     4,    11,    43,    11,    45,
      46,     4,     6,    56,    19,    58,   107,    59,    61,    24,
      25,    63,   113,    28,     9,    10,    11,    12,    13,    47,
       0,    16,    17,    18,     6,    76,     7,     8,    56,    11,
      58,    62,    47,    61,    48,    49,    87,    88,    52,    50,
      51,    59,    53,    89,    55,    63,     3,    62,    63,    59,
     149,    60,     4,    63,    49,   101,   102,    60,    63,    64,
      75,    59,   244,    58,    11,    63,   165,    71,    15,    11,
      65,    66,    67,    68,   175,   106,    59,    92,    63,    64,
      63,    96,   183,    41,    42,    43,    44,    45,    46,   104,
      59,   122,   107,   275,    63,    59,    59,    60,   113,    63,
     146,    59,    14,   285,    63,    64,   121,   122,   236,   160,
     161,   162,   163,   212,     5,    59,    59,    78,   164,    63,
      63,   167,    61,   127,    41,   129,    41,    42,    43,    44,
      45,    46,    59,   148,   149,   166,    63,    59,    61,   240,
      59,    63,   103,   174,    63,   191,     6,   178,    59,    41,
     165,   166,    63,    63,    64,   283,    71,    60,    64,   174,
     175,   260,   261,     9,    10,   180,    12,    13,   183,    58,
      16,    17,    18,   274,   135,   136,   137,   138,   139,   140,
     141,   142,    58,    58,   230,     9,   147,   157,   158,   159,
      60,   290,   291,    11,   225,    11,    60,   212,    47,    58,
     231,    58,    58,    49,    58,   236,    58,    58,     9,    10,
     225,    12,    13,   244,    58,    16,    17,    18,   264,   265,
     266,   236,    58,    56,    62,   240,    60,    62,    58,   244,
      59,    41,    42,    43,    44,    45,    46,   268,    41,    42,
      43,    44,    45,    46,   275,   260,   261,    57,    60,    32,
      47,    62,   283,    60,   285,    64,    60,    47,    60,   274,
     275,     9,    57,    11,    64,    64,    14,    60,   283,    60,
     285,    19,    20,    21,    60,   290,   291,    71,   274,   124,
      69,    69,    30,    31,    63,    33,    11,    35,    25,    37,
     175,     8,    40,    41,    42,    43,    44,    45,    46,    44,
       9,    75,    11,   205,   225,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    -1,    41,    42,    43,    44,    45,    46,
      -1,    30,    -1,    -1,    33,    73,    35,     9,    37,    11,
      57,    40,    14,    -1,    -1,    36,    -1,    19,    20,    21,
      41,    42,    43,    44,    45,    46,    -1,    -1,    30,    -1,
      -1,    33,    34,    35,    -1,    37,    -1,     9,    40,    11,
      -1,    -1,    14,    -1,    73,    36,    -1,    19,    20,    21,
      41,    42,    43,    44,    45,    46,    -1,    -1,    30,    -1,
      -1,    33,    -1,    35,    -1,    37,    -1,    -1,    40,    -1,
      -1,    73,     9,    10,    11,    12,    13,    -1,    -1,    16,
      17,    18,    -1,    -1,    11,    -1,    -1,    14,    -1,    -1,
      36,    -1,    19,    20,    21,    41,    42,    43,    44,    45,
      46,    73,    -1,    30,    -1,    -1,    33,    -1,    35,    -1,
      37,    -1,    49,    40,    -1,    -1,     9,    10,    11,    12,
      13,    58,    15,    16,    17,    18,    -1,    -1,    65,    66,
      67,    68,    -1,    70,    -1,    72,     9,    10,    11,    12,
      13,    -1,    -1,    16,    17,    18,    73,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,     9,    10,    11,
      12,    13,    -1,    -1,    16,    17,    18,    38,    39,    -1,
      41,    42,    43,    44,    45,    46,    49,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    58,   150,   151,   152,   153,
     154,   155
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    76,    11,     0,     4,    60,    77,    78,    90,
      11,    91,    92,   104,    77,    61,    14,   105,   106,     5,
      94,    92,    41,    61,   107,    95,    96,   104,     6,    87,
       9,    10,    12,    13,    16,    17,    18,    93,     9,    15,
      19,    20,    21,    30,    33,    35,    37,    40,    73,   104,
     106,   108,   109,   110,   111,   112,   114,   115,   116,   119,
     120,    96,    41,    88,    89,   103,   104,     7,     8,    79,
      80,    81,    85,    86,    60,    64,    58,    58,    58,    22,
      23,    24,    25,    26,    27,    28,    29,    49,    54,    58,
      93,   104,   122,   123,   124,   125,   107,   122,   122,   104,
       9,    47,    56,    58,    61,    60,    49,    58,    65,    66,
      67,    68,    70,    72,    93,    97,    98,   101,   102,   104,
      89,    63,    64,    11,    11,    80,    85,    60,    77,    60,
     109,   125,   121,   122,   121,    58,    58,    58,    58,    58,
      58,    58,    58,   125,   125,   122,    56,    58,    61,    31,
      41,    42,    43,    44,    45,    46,   108,    48,    49,    52,
      50,    51,    53,    55,    34,    36,    71,    47,   122,   122,
     121,   104,    93,   103,    56,    99,   100,   103,    62,    60,
      62,   104,    97,    58,    82,    82,    77,    60,    77,    59,
      59,    63,    59,   121,   121,   121,   121,   121,   121,   121,
     121,    59,   122,   121,   104,   108,   123,   123,   123,   123,
     123,   123,    32,   113,   124,   124,   124,   125,   125,   125,
     125,   122,   108,    93,   104,   117,   118,   122,    57,    59,
      47,    62,    59,   102,    15,   100,    64,    93,   104,    60,
       6,    83,    84,   103,    64,    60,    60,   122,    59,    59,
      59,    59,    59,    59,    59,    59,    57,    59,   113,   108,
      64,    64,    15,   118,    38,    39,    47,   122,    49,    93,
      57,    97,   103,    59,    60,    64,   102,   108,   108,   122,
     122,   122,    93,    71,    60,    64,    84,   102,    60,    60,
      36,    36,    97,   102,   108,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    76,    76,    76,    77,    78,    79,    79,
      79,    79,    79,    80,    80,    80,    80,    81,    82,    82,
      83,    83,    84,    84,    85,    86,    87,    87,    88,    88,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    98,    99,    99,   100,   100,   101,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   104,   105,   106,   106,   107,   107,   107,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   111,   112,   112,   113,   113,   114,   114,
     115,   116,   117,   117,   118,   118,   119,   119,   120,   120,
     120,   120,   120,   120,   121,   121,   122,   122,   122,   122,
     122,   122,   122,   123,   123,   123,   123,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     2,     4,     0,     2,
       2,     1,     1,     4,     3,     3,     2,     5,     0,     3,
       3,     1,     4,     3,     4,     3,     0,     2,     2,     1,
       4,     3,     0,     2,     2,     1,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     2,     1,     4,
       3,     1,     1,     1,     3,     2,     1,     4,     3,     6,
       1,     3,     3,     4,     5,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     2,     0,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     6,     5,     2,     5,     4,     0,     2,     4,     0,
       4,     5,     2,     1,     4,     4,     8,     8,     1,     4,
       4,     4,     1,     4,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     1,     4,     1,     3,     2,     2,     4,     3,
       4,     4,     4,     4,     4,     4,     4,     4
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
#line 53 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node) = (yyvsp[-1].node);
                            (yyval.node)->setAttribute((yyvsp[-3].sval));
                            savedTree = (yyval.node);
                        }
#line 1569 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node) = (yyvsp[0].node);
                            (yyval.node)->setAttribute((yyvsp[-2].sval));
                            savedTree = (yyval.node);
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of end dot");
                        }
#line 1579 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 64 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node) = (yyvsp[-1].node);
                            (yyval.node)->setAttribute((yyvsp[-2].sval));
                            savedTree = (yyval.node);
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
#line 1589 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node) = (yyvsp[0].node);
                            (yyval.node)->setAttribute((yyvsp[-1].sval));
                            savedTree = (yyval.node);
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon and end dot");
                        }
#line 1599 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node) =(yyvsp[-1].node);
                            (yyval.node)->setSibling((yyvsp[0].node));
                        }
#line 1608 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 82 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node) = new TreeDefine(ROUTINEHEAD,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                        }
#line 1620 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node) = NULL;}
#line 1626 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 92 "yacc.y" /* yacc.c:1646  */
    {   TreeNode t=(yyvsp[-1].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-1].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                        }
#line 1641 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 103 "yacc.y" /* yacc.c:1646  */
    {   TreeNode t=(yyvsp[-1].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-1].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                        }
#line 1656 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 113 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1662 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 114 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1668 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 117 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(FUNCTION,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 1678 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 123 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(FUNCTION,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
#line 1689 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 130 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(FUNCTION,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
#line 1700 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 137 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(FUNCTION,line_no);
                            (yyval.node)->addChild((yyvsp[-1].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
#line 1711 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 145 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(FUNCTIONHEAD,line_no);
                            (yyval.node)->setAttribute((yyvsp[-3].sval));
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                        }
#line 1722 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 153 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 1728 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 155 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 1734 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 158 "yacc.y" /* yacc.c:1646  */
    {   TreeNode t=(yyvsp[-2].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-2].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                        }
#line 1749 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 169 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node); }
#line 1755 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 172 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(VAR_PARA,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                        }
#line 1765 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 178 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(VAL_PARA,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                        }
#line 1775 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 185 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(PROCEDURE,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 1785 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 192 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(PROCEDUREHEAD,line_no);
                            (yyval.node)->setAttribute((yyvsp[-1].sval));
                            (yyval.node)->addChild((yyvsp[0].node));
                        }
#line 1795 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 199 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node) = NULL;}
#line 1801 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 201 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node);}
#line 1807 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 204 "yacc.y" /* yacc.c:1646  */
    {   TreeNode t = (yyvsp[-1].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-1].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                        }
#line 1822 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 214 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 1828 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 217 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(VAR,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 1837 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 222 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(VAR,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
#line 1847 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 229 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node) = NULL; }
#line 1853 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 231 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node); }
#line 1859 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 234 "yacc.y" /* yacc.c:1646  */
    {
                            TreeNode t = (yyvsp[-1].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-1].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                        }
#line 1875 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 247 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node); }
#line 1881 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 250 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(DK_CONST,line_no);
                            (yyval.node)->setAttribute((yyvsp[-3].node)->getAttribute());
                            (yyval.node)->addChild((yyvsp[-1].node));
                            (yyval.node)->setExpType((yyvsp[-1].node)->getExpType());
                        }
#line 1892 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 257 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(DK_CONST,line_no);
                            (yyval.node)->setAttribute((yyvsp[-2].node)->getAttribute());
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setExpType((yyvsp[0].node)->getExpType());
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
#line 1904 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 266 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node) =new TreeDefine(EK_CONST,line_no);
                            (yyval.node)->setExpType(INT);
                            (yyval.node)->setAttribute((yyvsp[0].ival));
                        }
#line 1914 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 272 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node) = new TreeDefine(EK_CONST,line_no);
                            (yyval.node)->setExpType(REAL);
                            (yyval.node)->setAttribute((yyvsp[0].dval));
                        }
#line 1924 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 278 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node) = new TreeDefine(EK_CONST,line_no);
                            (yyval.node)->setExpType(CHAR);
                            (yyval.node)->setAttribute((yyvsp[0].sval));
                        }
#line 1934 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 284 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node) = new TreeDefine(EK_CONST,line_no);
                            (yyval.node)->setExpType(STRING);
                            (yyval.node)->setAttribute((yyvsp[0].sval));
                        }
#line 1944 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 290 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(EK_CONST,line_no);
                            (yyval.node)->setExpType(BOOL);
                            (yyval.node)->setAttribute(1);
                        }
#line 1954 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 296 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(EK_CONST,line_no);
                            (yyval.node)->setExpType(BOOL);
                            (yyval.node)->setAttribute(0);
                        }
#line 1964 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 302 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(EK_CONST,line_no);
                            (yyval.node)->setExpType(INT);
                            (yyval.node)->setAttribute(2147483647);
                        }
#line 1974 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 309 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=NULL;}
#line 1980 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 311 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node);}
#line 1986 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 314 "yacc.y" /* yacc.c:1646  */
    {
                            TreeNode t=(yyvsp[-1].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-1].node);
                            }
                            else
                              (yyval.node)=(yyvsp[0].node);
                        }
#line 2002 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 326 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node);}
#line 2008 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 329 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(TYPE,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2017 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 334 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(TYPE,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
#line 2027 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 340 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2033 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 341 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2039 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 342 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2045 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 345 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[-1].node); }
#line 2051 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 348 "yacc.y" /* yacc.c:1646  */
    {
                            TreeNode t=(yyvsp[-1].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-1].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                        }
#line 2067 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 359 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2073 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 362 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(TK_RECORD,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2083 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 368 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(TK_RECORD,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
#line 2094 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 376 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(TK_ARRAY,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setExpType(ET_ARRAY);
                        }
#line 2105 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 384 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(SIMPLE_ID,line_no);
                            (yyval.node)->setAttribute((yyvsp[0].node)->getAttribute());
                            //free($1);
                        }
#line 2115 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 390 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(TK_SIMPLE_ENUM,line_no);
                            (yyval.node)->addChild((yyvsp[-1].node));
                            (yyval.node)->setExpType(ET_SIMPLE_ENUM);
                        }
#line 2124 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 395 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(TK_SIMPLE_LIMIT,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setExpType(ET_SIMPLE_LIMIT);
                        }
#line 2134 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 401 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(TK_SIMPLE_LIMIT,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->getChildren().at(0)->setAttribute((yyval.node)->getChildren().at(0)->getAttribute()._int*(-1));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setExpType(ET_SIMPLE_LIMIT);
                        }
#line 2146 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 409 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(TK_SIMPLE_LIMIT,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->getChildren().at(0)->setAttribute((yyval.node)->getChildren().at(0)->getAttribute()._int*(-1));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->getChildren().at(1)->setAttribute((yyval.node)->getChildren().at(1)->getAttribute()._int*(-1));
                            (yyval.node)->setExpType(ET_SIMPLE_LIMIT);
                        }
#line 2158 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 417 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(TK_SIMPLE_LIMIT,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setExpType(ET_SIMPLE_LIMIT);
                        }
#line 2169 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 424 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(SIMPLE_SYS,line_no);
                            (yyval.node)->setExpType(INT);
                        }
#line 2177 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 428 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(SIMPLE_SYS,line_no);
                            (yyval.node)->setExpType(BOOL);
                        }
#line 2185 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 432 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(SIMPLE_SYS,line_no);
                            (yyval.node)->setExpType(REAL);
                        }
#line 2193 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 436 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(SIMPLE_SYS,line_no);
                            (yyval.node)->setExpType(CHAR);
                        }
#line 2201 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 441 "yacc.y" /* yacc.c:1646  */
    {
                            TreeNode t=(yyvsp[-2].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-2].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                        }
#line 2217 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 452 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node); }
#line 2223 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 455 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(EK_ID,line_no);
                            (yyval.node)->setAttribute((yyvsp[0].sval));
                        }
#line 2231 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 458 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2237 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 459 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2243 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 460 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node); errMsg.push_back("error at line " + to_string(line_no) + ", lack of end");}
#line 2249 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 462 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2255 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 464 "yacc.y" /* yacc.c:1646  */
    {
                            TreeNode t=(yyvsp[-2].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[-1].node));
                                (yyval.node)=(yyvsp[-2].node);
                            }
                            else
                                (yyval.node)=(yyvsp[-1].node);
                        }
#line 2271 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 476 "yacc.y" /* yacc.c:1646  */
    {
                            TreeNode t=(yyvsp[-1].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-1].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                           errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
#line 2288 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 490 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(LABEL,line_no);
                            (yyval.node)->setAttribute((yyvsp[-2].ival));
                            (yyval.node)->addChild((yyvsp[0].node));
                        }
#line 2298 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 496 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node);}
#line 2304 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 498 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2310 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 499 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2316 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 500 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2322 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 501 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2328 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 502 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2334 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 503 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2340 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 504 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2346 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 505 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2352 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 506 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2358 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 508 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(ASSIGN,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setAttribute(OK_ID,4);
                        }
#line 2368 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 514 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(ASSIGN,line_no);
                            (yyval.node)->addChild((yyvsp[-5].node));
                            ((yyval.node)->getChildren().at(0))->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setAttribute(OK_ARRAY,4);
                        }
#line 2379 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 522 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(ASSIGN,line_no);
                            (yyval.node)->addChild((yyvsp[-4].node));
                            ((yyval.node)->getChildren().at(0))->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setAttribute(OK_RECORD,4);
                        }
#line 2390 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 530 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(GOTO,line_no);
                            (yyval.node)->setAttribute((yyvsp[0].ival));
                        }
#line 2398 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 535 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(IF,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                        }
#line 2408 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 541 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(IF,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                             errMsg.push_back("error at line " + to_string(line_no) + ", lack of then");
                        }
#line 2419 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 548 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=NULL;}
#line 2425 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 549 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2431 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 552 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(REPEAT,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                        }
#line 2441 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 557 "yacc.y" /* yacc.c:1646  */
    {}
#line 2447 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 560 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(WHILE,line_no);
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                        }
#line 2456 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 565 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(SK_CASE,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2465 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 570 "yacc.y" /* yacc.c:1646  */
    {   TreeNode t=(yyvsp[-1].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-1].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                        }
#line 2480 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 580 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2486 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 582 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(EK_CASE,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2496 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 588 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(EK_CASE,line_no);
                            (yyval.node)->addChild((yyvsp[-3].node));
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2506 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 594 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(FOR,line_no);
                            (yyval.node)->addChild((yyvsp[-6].node));
                            (yyval.node)->addChild((yyvsp[-4].node));
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setAttribute(TO,4);
                        }
#line 2519 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 603 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(FOR,line_no);
                            (yyval.node)->addChild((yyvsp[-6].node));
                            (yyval.node)->addChild((yyvsp[-4].node));
                            (yyval.node)->addChild((yyvsp[-2].node));
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setAttribute(DOWNTO,4);
                        }
#line 2532 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 612 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(PROC_ID,line_no);
                            (yyval.node)->setAttribute((yyvsp[0].node)->getAttribute());
                        }
#line 2540 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 616 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(PROC_ID,line_no);
                            (yyval.node)->setAttribute((yyvsp[-3].node)->getAttribute());
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2549 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 621 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(PROC_SYS,line_no);
                            (yyval.node)->setAttribute(READ,4);
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2559 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 627 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(PROC_SYS,line_no);
                            (yyval.node)->setAttribute(WRITE,4);
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2568 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 632 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(PROC_SYS,line_no);
                            (yyval.node)->setAttribute(WRITELN,4);
                        }
#line 2576 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 636 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(PROC_SYS,line_no);
                            (yyval.node)->setAttribute(WRITELN,4);
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2585 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 641 "yacc.y" /* yacc.c:1646  */
    {   TreeNode t=(yyvsp[-2].node);
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling((yyvsp[0].node));
                                (yyval.node)=(yyvsp[-2].node);
                            }
                            else
                                (yyval.node)=(yyvsp[0].node);
                        }
#line 2600 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 651 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2606 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 653 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),GE,line_no); }
#line 2612 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 654 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),GT,line_no); }
#line 2618 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 655 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),LE,line_no); }
#line 2624 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 656 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),LT,line_no); }
#line 2630 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 657 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),EQUAL,line_no); }
#line 2636 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 658 "yacc.y" /* yacc.c:1646  */
    {  (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),UNEQUAL,line_no); }
#line 2642 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 659 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node);}
#line 2648 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 661 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),PLUS,line_no); }
#line 2654 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 662 "yacc.y" /* yacc.c:1646  */
    {  (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),MINUS,line_no); }
#line 2660 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 663 "yacc.y" /* yacc.c:1646  */
    {     (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),OR,line_no); }
#line 2666 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 664 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[0].node);}
#line 2672 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 666 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),MUL,line_no); }
#line 2678 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 667 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),DIV,line_no); }
#line 2684 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 668 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),MOD,line_no); }
#line 2690 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 669 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[-2].node),(yyvsp[0].node),AND,line_no); }
#line 2696 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 670 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2702 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 673 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2708 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 675 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(FUNC_ID,line_no);
                            (yyval.node)->setAttribute((yyvsp[-3].node)->getAttribute());
                            (yyval.node)->addChild((yyvsp[-1].node));
                        }
#line 2718 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 680 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);}
#line 2724 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 681 "yacc.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[-1].node);}
#line 2730 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 683 "yacc.y" /* yacc.c:1646  */
    {
                           (yyval.node)=new TreeDefine((yyvsp[0].node),NULL,NOT,line_no);
                        }
#line 2738 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 687 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine((yyvsp[0].node), NULL, MINUS, line_no);
                        }
#line 2745 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 690 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[-3].node);
                            (yyval.node)->addChild((yyvsp[-1].node));
                            (yyval.node)->setExpType(ET_ARRAY);
                        }
#line 2754 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 695 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=(yyvsp[-2].node);
                            (yyval.node)->addChild((yyvsp[0].node));
                            (yyval.node)->setExpType(ET_RECORD);
                        }
#line 2763 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 700 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(ABS, (yyvsp[-1].node),line_no);
                        }
#line 2771 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 704 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(CHR, (yyvsp[-1].node),line_no);
                        }
#line 2779 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 708 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(ODD, (yyvsp[-1].node),line_no);
                        }
#line 2787 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 712 "yacc.y" /* yacc.c:1646  */
    {

                            (yyval.node)=new TreeDefine(ORD, (yyvsp[-1].node),line_no);
                        }
#line 2796 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 717 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(PRED, (yyvsp[-1].node),line_no);
                        }
#line 2804 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 721 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(SQR, (yyvsp[-1].node),line_no);
                        }
#line 2812 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 725 "yacc.y" /* yacc.c:1646  */
    {
                            (yyval.node)=new TreeDefine(SQRT, (yyvsp[-1].node),line_no);
                        }
#line 2820 "yacc.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 729 "yacc.y" /* yacc.c:1646  */
    {   (yyval.node)=new TreeDefine(SUCC, (yyvsp[-1].node),line_no);
                        }
#line 2827 "yacc.tab.c" /* yacc.c:1646  */
    break;


#line 2831 "yacc.tab.c" /* yacc.c:1646  */
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
#line 732 "yacc.y" /* yacc.c:1906  */

   
void yyerror(const char *s)
{
	cerr<<s<<" | line:"<<line_no<<endl;					//out error information
}

