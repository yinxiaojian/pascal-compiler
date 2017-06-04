%{
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "absyn.h"
using namespace std;

extern "C"
{
    void yyerror(const char *s);
    extern int yylex(void);
    //extern int line_no;
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
    int sysCon;
    int sysProc;
    int sysFunc;

    /*non-terminal*/
    program *nt1;
    program_head *nt2;
    routine *nt3;
    routine_head *nt4;
    routine_body *nt5;
    label_part *nt6;
    const_part *nt7;
    type_part *nt8;
    var_part *nt9;
    routine_part *nt10;
    const_expr_list *nt12;
    const_value *nt13;
    type_definition *nt14;
    type_decl_list *nt15;
    type_decl *nt16;
    simple_type_decl *nt17;
    array_type_decl *nt18;
    record_type_decl *nt19;
    name_list *nt20;
    field_decl *nt21;
    field_decl_list *nt22;
    var_decl *nt23;
    var_decl_list *nt24;
    function_decl *nt25;
    function_head *nt27;
    procedure_decl *nt28;
    procedure_head *nt29;
    sub_routine *nt30;
    parameters *nt31;
    para_type_list *nt32;
    para_decl_list *nt33;
    var_para_list *nt34;
    val_para_list *nt35;
    compound_stmt *nt36;
    stmt *nt37;
    stmt_list *nt38;
    non_label_stmt *nt39;
    assign_stmt *nt40;
    proc_stmt *nt41;
    if_stmt *nt42;
    repeat_stmt *nt43;
    while_stmt *nt44;
    for_stmt *nt45;
    case_stmt *nt46;
    goto_stmt *nt47;
    expression *nt48;
    args_list *nt49;
    expression_list *nt50;
    else_clause *nt51;
    case_expr *nt52;
    case_expr_list *nt53;
    expr *nt54;
    term *nt55;
    factor *nt56;
}


%token <iValue> INTEGER
%token <sValue> STRING
%token <cValue> CHAR
%token <rValue> REAL
%token <sValue> ID

%token <syscon> SYS_CON
%token <sysType> SYS_TYPE
%token <sysProc> SYS_PROC
%token <sysFunc> SYS_FUNCT

%token SYS_CON_TRUE SYS_CON_FALSE SYS_CON_MAXINT 
%token SYS_TYPE_INTEGER SYS_TYPE_REAL SYS_TYPE_CHAR SYS_TYPE_BOOL 
%token SYS_FUNCT_ABS SYS_FUNCT_CHR SYS_FUNCT_ODD SYS_FUNCT_ORD SYS_FUNCT_PRED SYS_FUNCT_SQR SYS_FUNCT_SQRT SYS_FUNCT_SUCC 
%token SYS_PROC_WRITE SYS_PROC_WRITELN

%token DOT PROGRAM SEMI CONST EQUAL TYPE ARRAY LB RB OF RECORD END COLON COMMA LP RP DOTDOT
%token MINUS VAR FUNCTION PROCEDURE ASSIGN READ PBEGIN IF THEN ELSE REPEAT UNTIL WHILE
%token DO FOR TO DOWNTO CASE GOTO GE GT LE LT UNEQUAL PLUS OR MUL DIV MOD AND NOT

%type <nt1> program
%type <nt2> program_head
%type <nt3> routine
%type <nt4> routine_head
%type <nt5> routine_body
%type <nt6> label_part
%type <nt7> const_part
%type <nt8> type_part
%type <nt9> var_part
%type <nt10> routine_part
%type <nt12> const_expr_list
%type <nt13> const_value
%type <nt14> type_definition
%type <nt15> type_decl_list
%type <nt16> type_decl
%type <nt17> simple_type_decl
%type <nt18> array_type_decl
%type <nt19> record_type_decl
%type <nt20> name_list
%type <nt21> field_decl
%type <nt22> field_decl_list
%type <nt23> var_decl
%type <nt24> var_decl_list
%type <nt25> function_decl
%type <nt27> function_head
%type <nt28> procedure_decl
%type <nt29> procedure_head
%type <nt30> sub_routine
%type <nt31> parameters
%type <nt32> para_type_list
%type <nt33> para_decl_list
%type <nt34> var_para_list
%type <nt35> val_para_list
%type <nt36> compound_stmt
%type <nt37> stmt
%type <nt38> stmt_list
%type <nt39> non_label_stmt
%type <nt40> assign_stmt
%type <nt41> proc_stmt
%type <nt42> if_stmt
%type <nt43> repeat_stmt
%type <nt44> while_stmt
%type <nt45> for_stmt
%type <nt46> case_stmt
%type <nt47> goto_stmt
%type <nt48> expression
%type <nt49> args_list
%type <nt50> expression_list
%type <nt51> else_clause
%type <nt52> case_expr
%type <nt53> case_expr_list
%type <nt54> expr
%type <nt55> term
%type <nt56> factor

%%
program : 		program_head  routine  DOT
    {
        string st = "sa";
        identifier *a = new identifier(st,NULL);
        cout<<a->name;
    }
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
	{cout<<"test"<<line_no<<endl;}
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
    {}
	;

const_value :	INTEGER
	{}
	|	REAL
	{}
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
	{}
	|
	{}
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

