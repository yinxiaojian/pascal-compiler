%{
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
%}

%union 
{
    int iValue;
    char* sValue;
    char cValue;
    double rValue;
    int sIndex;
    int sysType;
    int syscon;
    int sysProc;
    int sysFunc;
}

%token <iValue> INTEGER
%token <sValue> STRING
%token <cValue>  CHAR
%token <rValue> REAL
%token <sValue> ID

%token <syscon> SYS_CON
%token <sysType> SYS_TYPE
%token <sysProc> SYS_PROC
%token <sysFunc> SYS_FUNCT

%token SYS_CON_TRUE SYS_CON_FALSE SYS_CON_MAXINT SYS_TYPE_INTEGER SYS_TYPE_REAL SYS_TYPE_CHAR
%token SYS_TYPE_BOOL SYS_FUNCT_ABS SYS_FUNCT_CHR SYS_FUNCT_ODD SYS_FUNCT_ORD SYS_FUNCT_PRED
%token SYS_FUNCT_SQR SYS_FUNCT_SQRT SYS_FUNCT_SUCC SYS_PROC_WRITE SYS_PROC_WRITELN

%token DOT
%token PROGRAM
%token SEMI
%token CONST
%token EQUAL
%token TYPE
%token ARRAY
%token LB
%token RB
%token OF
%token RECORD
%token END
%token COLON
%token COMMA
%token LP
%token RP
%token DOTDOT
%token MINUS
%token VAR
%token FUNCTION
%token PROCEDURE
%token ASSIGN
%token READ
%token PBEGIN
%token IF
%token THEN
%token ELSE
%token REPEAT
%token UNTIL
%token WHILE
%token DO
%token FOR
%token TO
%token DOWNTO
%token CASE
%token GOTO
%token GE
%token GT
%token LE
%token LT
%token UNEQUAL
%token PLUS
%token OR
%token MUL
%token DIV
%token RDIV
%token MOD
%token AND
%token NOT
%type<iValue> const_value
%%
program : 		program_head  routine  DOT
	{}
	;

program_head : 	PROGRAM  ID  SEMI
	{}
	;

routine : 		routine_head  routine_body
	{}
	;

sub_routine : 	routine_head  routine_body
	{}
	;

routine_head : 	label_part  const_part  type_part  var_part  routine_part
	{}
	;

label_part : 	{}
	;

const_part :	CONST  const_expr_list
	{} 
	|
	{}
	;

const_expr_list :	const_expr_list  ID  EQUAL  const_value  SEMI
	{}
	|	ID  EQUAL  const_value  SEMI
    { cout<<"CONST"<<$1<<" "<<$3<<endl;}
	;

const_value :	INTEGER
	{}
	|	REAL
	{cout<<"REAL"<<$1<<endl;$$=2;}
	|	CHAR
	{}
	|	STRING
	{}
	|	SYS_CON
	{}
	;

type_part : 	TYPE type_decl_list
	{}
	|{}
	;

type_decl_list :	type_decl_list  type_definition
	{}
	|	type_definition
	{}
	;

type_definition :	ID  EQUAL  type_decl  SEMI
	{}
	;

type_decl :		simple_type_decl
	{}
	|	array_type_decl
	{}
	|	record_type_decl
	{}
	;

simple_type_decl :	SYS_TYPE
	{}
	|	ID
	{}  
	|	LP  name_list  RP
	{} 
	|	const_value  DOTDOT  const_value
	{}  
	|	MINUS  const_value  DOTDOT  const_value
	{}
	|	MINUS  const_value  DOTDOT  MINUS  const_value
	{}
	|	ID  DOTDOT  ID
	{}
	;

array_type_decl :	ARRAY  LB  simple_type_decl  RB  OF  type_decl
	{}
	;

record_type_decl :	RECORD  field_decl_list  END
	{}
	;

field_decl_list :	field_decl_list  field_decl  
	{}
	|	field_decl
	{}
	;

field_decl :	name_list  COLON  type_decl  SEMI
	{}
	;

name_list :		name_list  COMMA  ID  
	{}
	|	ID
	{}
	;

var_part :	VAR  var_decl_list  
	{}
	|{}
	;

var_decl_list :		var_decl_list  var_decl
	{}
	|	var_decl
	{}
	;

var_decl :	name_list  COLON  type_decl  SEMI
	{}
	;

routine_part:	routine_part  function_decl
	{}
	|	routine_part  procedure_decl
	{}	
	|	function_decl
	{}	
	|	procedure_decl
	|{}
	;

function_decl :	function_head  SEMI  sub_routine  SEMI
	{}
	;

function_head :	FUNCTION  ID  parameters  COLON  simple_type_decl
    {
    }
	;

procedure_decl :	procedure_head  SEMI  sub_routine  SEMI
	{}
	;

procedure_head :	PROCEDURE ID parameters
	{}
	;
	
parameters :	LP  para_decl_list  RP  
	{}
	|{}
	;

para_decl_list :	para_decl_list  SEMI  para_type_list
	{}
	|	para_type_list
	{}
	;

para_type_list :	var_para_list COLON  simple_type_decl
	{}
	|	val_para_list  COLON  simple_type_decl
	{}
	;

var_para_list :	VAR  name_list
	{}
	;

val_para_list :	name_list
	{}
	;

routine_body :	compound_stmt
	{}
	;

compound_stmt :	PBEGIN  stmt_list  END
	{}
	;

stmt_list :		stmt_list  stmt  SEMI
	{}
	|{}
	;
stmt :		INTEGER  COLON  non_label_stmt
	{}
	|	non_label_stmt
	{}
	;

non_label_stmt :	assign_stmt 
	{}
	|	proc_stmt
	{}	
	|	compound_stmt
	{}
	|	if_stmt
	{}
	|	repeat_stmt
	{}	
	|	while_stmt
	{} 
	|	for_stmt
	{}
	|	case_stmt
	{}
	|	goto_stmt
	{}
	;

assign_stmt :	ID  ASSIGN  expression
	{}
	|	ID LB expression RB ASSIGN expression
	{}
	|	ID  DOT  ID  ASSIGN  expression
	{}
	;

proc_stmt :		ID
	{}
	|	ID  LP  args_list  RP
	{}
	|	SYS_PROC
    {}
	|	SYS_PROC  LP  expression_list  RP
	{}
	|	READ  LP  factor  RP
	{}
	;

if_stmt :	IF  expression  THEN  stmt  else_clause
	{}
	;

else_clause :	ELSE stmt 
	{}
	|{}
	;

repeat_stmt :	REPEAT  stmt_list  UNTIL  expression
	{}
	;

while_stmt :	WHILE  expression  DO stmt
	{}
	;

for_stmt :		FOR  ID  ASSIGN  expression  direction  expression  DO stmt
	{}
	;

direction :		TO
	{}
	|	DOWNTO
	{}
	;

case_stmt :		CASE expression OF case_expr_list  END
	{}
	;

case_expr_list :	case_expr_list  case_expr  
	{}
	|	case_expr
	{}
	;

case_expr :		const_value  COLON  stmt  SEMI
	{}
	|	ID  COLON  stmt  SEMI
	{}
	;

goto_stmt :		GOTO  INTEGER
	{}
	;

expression_list :	expression_list  COMMA  expression  
	{}
	|	expression
	{}
	;

expression :	expression  GE  expr
	{}
	|	expression  GT  expr
	{}
	|	expression  LE  expr
	{}	
	|  expression  LT  expr
	{}
	|  expression  EQUAL  expr 
	{} 
	|  expression  UNEQUAL  expr  
	{}
	|  expr
	{}
	;

expr :			expr  PLUS  term
	{}
	|	expr  MINUS  term
	{}
	|	expr  OR  term
	{}
	|	term
	{}
	;

term :			term  MUL  factor
	{}
	|	term  DIV  factor
	{}
	|	term  MOD  factor 
	{}
	|	term  AND  factor
	{}
	|	factor
	{}
	;

factor :		ID
	{}
	|	ID  LP  args_list  RP  
	{}
	|	SYS_FUNCT
	{}
	|	SYS_FUNCT  LP  args_list  RP  
	{}
	|	const_value
	{}
	|	LP  expression  RP
	{}
	|  	NOT  factor
	{}
	|	MINUS  factor
	{}
	|	ID  LB  expression  RB
	{}
	|	ID  DOT  ID
	{}
	;

args_list :		args_list  COMMA  expression
	{}
	|	expression
	{}
	;

%%


void yyerror(const char *s)
{
	cerr<<s<<" | line:"<<line_no<<endl;					//out error information
}

