%{
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "absyn.h"
#include "yacc.tab.h"
int line_no = 1;

// compile with C
extern "C"
{
    void commentError();
    int yywrap(void);
    int yylex(void);
}

%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^']

%%


{A}{N}{D} return T_AND;
{A}{R}{R}{A}{Y} return T_ARRAY;
{B}{E}{G}{I}{N} return T_BEGIN;
{C}{A}{S}{E} return T_CASE;
{C}{O}{N}{S}{T} return T_CONST;
{D}{O} return T_DO;
{D}{O}{W}{N}{T}{O} return T_DOWNTO;
{E}{L}{S}{E} return T_ELSE;
{E}{N}{D} return T_END;
{F}{O}{R} return T_FOR;
{F}{U}{N}{C}{T}{I}{O}{N} return T_FUNCTION;
{G}{O}{T}{O} return T_GOTO;
{I}{F} return T_IF;
{M}{O}{D} return T_MOD;
{N}{O}{T} return T_NOT;
{O}{F} return T_OF;
{O}{R} return T_OR;
{P}{R}{O}{C}{E}{D}{U}{R}{E} return T_PROCEDURE;
{P}{R}{O}{G}{R}{A}{M} return T_PROGRAM;
{R}{E}{A}{D} return T_READ;
{R}{E}{C}{O}{R}{D} return T_RECORD;
{R}{E}{P}{E}{A}{T} return T_REPEAT;
{T}{H}{E}{N} return T_THEN;
{T}{O} return T_TO;
{T}{Y}{P}{E} return T_TYPE;
{U}{N}{T}{I}{L} return T_UNTIL;
{V}{A}{R} return T_VAR;
{W}{H}{I}{L}{E} return T_WHILE;

{T}{R}{U}{E} return T_TRUE;
{F}{A}{L}{S}{E} return T_FALSE;
{M}{A}{X}{I}{N}{T} return T_MAXINT;

{A}{B}{S} return T_ABS;
{C}{H}{R} return T_CHR;
{O}{D}{D} return T_ODD;
{O}{R}{D} return T_ORD;
{P}{R}{E}{D} return T_PRED;
{S}{Q}{R} return T_SQR;
{S}{Q}{R}{T} return T_SQRT;
{S}{U}{C}{C} return T_SUCC;

{W}{R}{I}{T}{E} return T_WRITE;
{W}{R}{I}{T}{E}{L}{N} return T_WRITELN;

{I}{N}{T}{E}{G}{E}{R} return T_INTEGER_TYPE;
{R}{E}{A}{L} return T_REAL_TYPE;
{C}{H}{A}{R} return T_CHAR_TYPE;
{S}{T}{R}{I}{N}{G} return T_STRING_TYPE;
{B}{O}{O}{L}{E}{A}{N} return T_BOOLEAN_TYPE;

[a-zA-Z]([a-zA-Z0-9_])* {
	yylval.sval = (char*)malloc(strlen(yytext)+1);
	strcpy(yylval.sval,yytext); 
    return T_ID;
}


'({NQUOTE}|'')({NQUOTE}|'')+' {
    yylval.sval = yytext;
    return T_STRING;
}

'({NQUOTE}|'')' {
    yylval.sval = yytext;
    return T_CHAR;
}

[0-9]+ {
    yylval.ival = atoi(yytext);
    return T_INT;
}

[0-9]+"\."[0-9]+ {
    yylval.dval = atof(yytext);
    return T_REAL;
}


":=" return T_ASSIGN;
":" return T_COLON;
"," return T_COMMA;
"." return T_DOT;
".." return T_DOTDOT;
"=" return T_EQUAL;
">=" return T_GE;
">" return T_GT;
"[" return T_LB;
"<=" return T_LE;
"(" return T_LP;
"<" return T_LT;
"-" return T_MINUS;
"<>" return T_UNEQUAL;
"+" return T_PLUS;
"]" return T_RB;

")" return T_RP;
";" return T_SEMI;
"/" return T_DIV;
"*" return T_MUL;
"%" return T_MOD;

"{" {
    register int c;
    while ((c = yyinput()))
    {
        if (c == '}')
            break;
        else if (c == '\n')
            line_no++;
        else if (c == -1)
            commentError();
    }
}

"(*" {
    register int c;
    while ((c = yyinput()))
    {
        if (c=='*')
        {
            if ((c = yyinput()) == ')')
                break;
            else
                unput (c);
        }
        else if (c == '\n')
            line_no++;
        else if(c == -1)
            commentError();
    }
}

[\t\f] {}

"\n" { line_no ++; }

" " {}

. { fprintf (stderr, "'%c' (0%o): illegal charcter at line %d\n",
              yytext[0], yytext[0], line_no); }
 
%%

void commentError()
{
    fprintf (stderr, "unexpected EOF inside comment at line %d\n",line_no);
    exit (1);
}

int yywrap ()
{
	std::cout<<"token finish(line: "<<line_no<<")"<<std::endl;
    return 1;
}
