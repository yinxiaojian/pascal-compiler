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
    float rValue;

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

%token <sysCon> SYS_CON
%token <sysType> SYS_TYPE
%token <sysProc> SYS_PROC
%token <sysFunc> SYS_FUNCT

%token SYS_CON_TRUE SYS_CON_FALSE SYS_CON_MAXINT 
%token SYS_TYPE_INTEGER SYS_TYPE_REAL SYS_TYPE_CHAR SYS_TYPE_BOOL SYS_TYPE_STRING
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
%type <iValue> direction

%%
program : 		program_head  routine  DOT
    {
        $$ = new program($1,$2);
        //absTree = $$;
    }
	;

program_head : 	PROGRAM  ID  SEMI
    {
        identifier *temp = new identifier($2);
        $$ = new program_head(temp); 
    }
    ;

routine : 		routine_head  routine_body
	{ $$ = new routine($1, $2); }
	;

sub_routine : 	routine_head  routine_body
	{ $$ = new sub_routine($1, $2); }
	;

routine_head : 	label_part  const_part  type_part  var_part  routine_part
	{ $$ = new routine_head($1,$2,$3,$4,$5); }
	;

label_part : 	
    { 
        //TODO 
        $$ = new label_part();
    }
	;

const_part :	CONST  const_expr_list
	{ $$ = new const_part($2); } 
	|
	{ $$ = new const_part(NULL); }
	;

const_expr_list :	const_expr_list  ID  EQUAL  const_value  SEMI
    {
        const_expr_list *temp = $1;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next  = new const_expr_list(new identifier($2),$4,NULL);
        $$ = $1;
    }
	|	ID  EQUAL  const_value  SEMI
    { $$ = new const_expr_list(new identifier($1),$3,NULL); }
	;

const_value :	INTEGER
	{ $$ = new const_value($1); }
	|	REAL
	{ $$ = new const_value($1); }
	|	CHAR
	{ $$ = new const_value($1); }
	|	STRING
	{ $$ = new const_value($1); }
	|	SYS_CON
	{
        if($1 == SYS_CON_TRUE)
            $$ = new const_value(_TRUE);
        else if($1 == SYS_CON_FALSE)
            $$ = new const_value(_FALSE);
        else if($1 == SYS_CON_MAXINT)
            $$ = new const_value(_MAXINT);
    }
	;

type_part : 	TYPE type_decl_list
	{ $$ = new type_part($2); }
	|{ $$ = new type_part(NULL); }
	;

type_decl_list :	type_decl_list  type_definition
    {
        type_decl_list *temp = $1;
        while($1!=NULL)
            temp = temp->next;
        temp->next = $2;
        $$ = $1;
    }
	|	type_definition
	{ $$ = (type_decl_list *)$1; }
	;

type_definition :	ID  EQUAL  type_decl  SEMI
	{ $$ = new type_definition(new identifier($1), $3, NULL); }
	;

type_decl :		simple_type_decl
	{ $$ = new type_decl($1); }
	|	array_type_decl
	{ $$ = new type_decl($1); }
	|	record_type_decl
	{ $$ = new type_decl($1); }
	;

simple_type_decl :	SYS_TYPE
	{ 
        if(SYS_TYPE == SYS_TYPE_BOOL)
            $$ = new simple_type_decl(_BOOLEAN);
        else if(SYS_TYPE == SYS_TYPE_CHAR)
            $$ = new simple_type_decl(_CHAR);
        else if(SYS_TYPE == SYS_TYPE_INTEGER)
            $$ = new simple_type_decl(_INTEGER);
        else if(SYS_TYPE == SYS_TYPE_REAL)
            $$ = new simple_type_decl(_REAL);
        else if(SYS_TYPE == SYS_TYPE_STRING)
            $$ = new simple_type_decl(_STRING);
    }
	|	ID
	{ $$ = new simple_type_decl(new identifier($1)); }  
	|	LP  name_list  RP
	{ $$ = new simple_type_decl($2); } 
	|	const_value  DOTDOT  const_value
	{ $$ = new simple_type_decl($1,$3,0); }  
	|	MINUS  const_value  DOTDOT  const_value
	{ $$ = new simple_type_decl($2,$4,1); }
	|	MINUS  const_value  DOTDOT  MINUS  const_value
	{ $$ = new simple_type_decl($2,$5,2); }
	|	ID  DOTDOT  ID
	{ $$ = new simple_type_decl(new identifier($1),new identifier($3)); }
	;

array_type_decl :	ARRAY  LB  simple_type_decl  RB  OF  type_decl
	{ $$ = new array_type_decl($3,$6); }
	;

record_type_decl :	RECORD  field_decl_list  END
	{ $$ = new record_type_decl($2); }
	;

field_decl_list :	field_decl_list  field_decl  
	{
        field_decl_list *temp = $1;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = $2;
        $$ = $1;
    }
	|	field_decl
	{ $$ = (field_decl_list *)$1; }
	;

field_decl :	name_list  COLON  type_decl  SEMI
	{ $$ = new field_decl($1,$3,NULL); }
	;

name_list :		name_list  COMMA  ID  
	{ 
        name_list *temp = $1;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = new name_list(new identifier($3), NULL);
        $$ = $1;
    }
	|	ID
	{ $$ = new name_list(new identifier($1),NULL); }
	;

var_part :	VAR  var_decl_list  
	{ $$ = new var_part($2); }
	|{ $$ = new var_part(NULL); }
	;

var_decl_list :		var_decl_list  var_decl
	{ 
        var_decl_list *temp = $1;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = $2;
        $$ = $1;
    }
	|	var_decl
	{ $$ = (var_decl_list *)$1; }
	;

var_decl :	name_list  COLON  type_decl  SEMI
	{ $$ = new var_decl($1,$3,NULL); }
	;

routine_part:	routine_part  function_decl
    {
        function_decl *temp = $1->child1;
        if(temp == NULL)
            $1->child1 = $2;
        else
        {
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = $2;
        }
        $$ = $1;

    }
	|	routine_part  procedure_decl
    {
        procedure_decl *temp = $1->child2;
        if(temp == NULL)
            $1->child2 = $2;
        else
        {
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = $2;
        }
        $$ = $1;
    }	
	|	function_decl
	{ $$ = new routine_part($1,NULL); }	
	|	procedure_decl
	{ $$ = new routine_part(NULL,$1); }
	|
	{ $$ = new routine_part(NULL,NULL); }
	;

function_decl :	function_head  SEMI  sub_routine  SEMI
	{ $$ = new function_decl($1,$3,NULL); }
	;

function_head :	FUNCTION  ID  parameters  COLON  simple_type_decl
    { $$ = new function_head(new identifier($2),$3,$5); }
	;

procedure_decl :	procedure_head  SEMI  sub_routine  SEMI
	{ $$ = new procedure_decl($1,$3,NULL); }
	;

procedure_head :	PROCEDURE ID parameters
	{ $$ = new procedure_head(new identifier($2),$3); }
	;
	
parameters :	LP  para_decl_list  RP  
	{ $$ = new parameters($2); }
	|{$$ = NULL;}
	;

para_decl_list :	para_decl_list  SEMI  para_type_list
	{ 
        para_type_list *temp = $1;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = $3;
        $$ = $1;
    }
	|	para_type_list
	{ $$ = (para_decl_list *)$1; }
	;

para_type_list :	var_para_list COLON  simple_type_decl
	{ $$ = new para_type_list($1,$3,NULL); }
	|	val_para_list  COLON  simple_type_decl
	{ $$ = new para_type_list($1,$3,NULL, 0);}
	;

var_para_list :	VAR  name_list
	{ $$ = (var_para_list *)$2; }
	;

val_para_list :	name_list
	{ $$ = (val_para_list *)$1; }
	;

routine_body :	compound_stmt
	{ $$ = new routine_body($1); }
	;

compound_stmt :	PBEGIN  stmt_list  END
	{ $$ = new compound_stmt($2); }
	;

stmt_list :		stmt_list  stmt  SEMI
	{ 
        stmt_list *temp = $1;
        if(temp == NULL)
            $1 = (stmt_list *)$2;
        else
        {
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next = $2;
        }
        $$ = $1;
    }
	|{ $$ = NULL; }
	;
stmt :		INTEGER  COLON  non_label_stmt
	{ $$ = new stmt($1,$3,NULL); }
	|	non_label_stmt
	{ $$ = new stmt($1,NULL); }
	;

non_label_stmt :	assign_stmt 
	{ $$ = new non_label_stmt($1); }
	|	proc_stmt
	{ $$ = new non_label_stmt($1); }	
	|	compound_stmt
	{ $$ = new non_label_stmt($1); }
	|	if_stmt
	{ $$ = new non_label_stmt($1); }
	|	repeat_stmt
	{ $$ = new non_label_stmt($1); }	
	|	while_stmt
	{ $$ = new non_label_stmt($1); } 
	|	for_stmt
	{ $$ = new non_label_stmt($1); }
	|	case_stmt
	{ $$ = new non_label_stmt($1); }
	|	goto_stmt
	{ $$ = new non_label_stmt($1); }
	;

assign_stmt :	ID  ASSIGN  expression
	{ $$ = new assign_stmt(new identifier($1),$3); }
	|	ID LB expression RB ASSIGN expression
	{ $$ = new assign_stmt(new identifier($1),$3,$6); }
	|	ID  DOT  ID  ASSIGN  expression
	{ $$ = new assign_stmt(new identifier($1),new identifier($3),$5); }
	;

proc_stmt :		ID
	{ $$ = new proc_stmt(new identifier($1)); }
	|	ID  LP  args_list  RP
	{ $$ = new proc_stmt(new identifier($1),$3); }
	|	SYS_PROC
    { 
        if($1 == SYS_PROC_WRITE)
            $$ = new proc_stmt(new sys_proc(_WRITE));
        else if($1 == SYS_PROC_WRITELN)
            $$ = new proc_stmt(new sys_proc(_WRITELN));
    }
	|	SYS_PROC  LP  expression_list  RP
	{ 
        if($1 == SYS_PROC_WRITE)
            $$ = new proc_stmt(new sys_proc(_WRITE),$3);
        else if($1 == SYS_PROC_WRITELN)
            $$ = new proc_stmt(new sys_proc(_WRITELN),$3); 
    }
	|	READ  LP  factor  RP
	{ $$ = new proc_stmt($3); }
	;

if_stmt :	IF  expression  THEN  stmt  else_clause
	{ $$ = new if_stmt($2,$4,$5); }
	;

else_clause :	ELSE stmt 
	{ $$ = new else_clause($2); }
	|{ $$ = new else_clause(NULL); }
	;

repeat_stmt :	REPEAT  stmt_list  UNTIL  expression
	{ $$ = new repeat_stmt($2,$4); }
	;

while_stmt :	WHILE  expression  DO stmt
	{ $$ = new while_stmt($2,$4); }
	;

for_stmt :		FOR  ID  ASSIGN  expression  direction  expression  DO stmt
	{ $$ = new for_stmt(new identifier($2), $4,$5,$6,$8); }
	;

direction :		TO
	{ $$ = 1; }
	|	DOWNTO
	{ $$ = 2; }
	;

case_stmt :		CASE expression OF case_expr_list  END
	{ $$ = new case_stmt($2,$4); }
	;

case_expr_list :	case_expr_list  case_expr  
	{ 
        case_expr_list *temp = $1;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = $2;
        $$ = $1;
    }
	|	case_expr
	{ $$ = (case_expr_list *)$1; }
	;

case_expr :		const_value  COLON  stmt  SEMI
	{ $$ = new case_expr($1,$3,NULL); }
	|	ID  COLON  stmt  SEMI
	{ $$ = new case_expr(new identifier($1),$3,NULL); }
	;

goto_stmt :		GOTO  INTEGER
	{ $$ = new goto_stmt($2); }
	;

expression_list :	expression_list  COMMA  expression  
	{ 
        expression_list *temp = $1;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = $3;
        $$ = $1;
    }
	|	expression
	{ $$ = (expression_list *)$1; }
	;

expression :	expression  GE  expr
	{ $$ = new expression($1,1,$3,NULL); }
	|	expression  GT  expr
	{ $$ = new expression($1,2,$3,NULL); }
	|	expression  LE  expr
	{ $$ = new expression($1,3,$3,NULL); }	
	|  expression  LT  expr
    { $$ = new expression($1,4,$3,NULL); }
	|  expression  EQUAL  expr 
	{ $$ = new expression($1,5,$3,NULL); } 
	|  expression  UNEQUAL  expr  
	{ $$ = new expression($1,6,$3,NULL); }
	|  expr
	{ $$ = new expression(NULL,1,$1,NULL); }
	;

expr :			expr  PLUS  term
	{ $$ = new expr($1,1,$3); }
	|	expr  MINUS  term
	{ $$ = new expr($1,2,$3); }
	|	expr  OR  term
	{ $$ = new expr($1,3,$3); }
	|	term
	{ $$ = new expr(NULL,1,$1); }
	;

term :			term  MUL  factor
	{ $$ = new term($1,1,$3); }
	|	term  DIV  factor
	{ $$ = new term($1,2,$3); }
	|	term  MOD  factor 
	{ $$ = new term($1,3,$3); }
	|	term  AND  factor
	{ $$ = new term($1,4,$3); }
	|	factor
	{ $$ = new term(NULL,1,NULL); }
	;

factor :		ID
	{ $$ = new factor(new identifier($1)); }
	|	ID  LP  args_list  RP  
	{ $$ = new factor(new identifier($1), $3); }
	|	SYS_FUNCT
	{  }
	|	SYS_FUNCT  LP  args_list  RP  
	{  }
	|	const_value
	{ $$ = new factor($1); }
	|	LP  expression  RP
	{ $$ = new factor($2); }
	|  	NOT  factor
	{ $$ = new factor($2,7); }
	|	MINUS  factor
	{ $$ = new factor($2,8); }
	|	ID  LB  expression  RB
	{ $$ = new factor(new identifier($1),$3); }
	|	ID  DOT  ID
	{ $$ = new factor(new identifier($1),new identifier($3)); }
	;

args_list :		args_list  COMMA  expression
    {
        args_list *temp = $1;
        while(temp->next=NULL)
            temp = temp->next;
        temp->next = $3;
        $$ = $1;
    }
	|	expression
	{ $$ = (args_list *)$1; }
	;

%%


void yyerror(const char *s)
{
	cerr<<s<<" | line:"<<line_no<<endl;					//out error information
}

