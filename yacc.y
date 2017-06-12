%{
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
%}

%union
{
    int ival;
	double dval;
    char* sval;
	TreeNode node;
}


%token T_PROGRAM T_CONST T_TYPE T_VAR
%token T_FUNCTION T_PROCEDURE
%token <ival> T_INT
%token <dval> T_REAL
%token <sval> T_ID T_CHAR T_STRING
%token T_BEGIN T_END
%token T_TRUE T_FALSE T_MAXINT
%token T_READ T_WRITE T_WRITELN T_ABS T_CHR T_ODD T_ORD T_PRED T_SQR T_SQRT T_SUCC
%token T_IF T_THEN T_ELSE T_REPEAT T_UNTIL T_WHILE T_DO T_CASE T_TO T_DOWNTO T_FOR
%token T_EQUAL T_UNEQUAL T_GE T_GT T_LE T_LT T_ASSIGN T_PLUS T_MINUS T_MUL T_DIV T_OR T_AND T_NOT T_MOD
%token T_LB T_RB T_LP T_RP T_SEMI T_DOT T_DOTDOT T_COMMA T_COLON
%token T_INTEGER_TYPE T_BOOLEAN_TYPE T_CHAR_TYPE T_REAL_TYPE T_STRING_TYPE
%token T_ARRAY T_OF T_RECORD T_GOTO
%token ERROR

%type <node> program routine routine_head routine_part function_decl function_head parameters para_decl_list para_type_list
%type <node> procedure_decl procedure_head var_part var_decl_list var_decl const_part const_expr_list const_expr const_value
%type <node> type_part  type_decl_list type_definition type_decl record_type_decl field_decl_list field_decl array_type_decl
%type <node> simple_type_decl name_list ID routine_body compound_stmt stmt_list no_label_stmt assign_stmt goto_stmt if_stmt
%type <node> else_clause repeat_stmt case_stmt case_expr_list case_expr for_stmt proc_stmt args_list expr
%type <node> term factor
%type <node> while_stmt expression stmt
%%

program             :   T_PROGRAM T_ID T_SEMI routine T_DOT
                        {   $$ = $4;
                            $$->setAttribute($2);
                            savedTree = $$;
                        }
                    | 	T_PROGRAM T_ID T_SEMI routine
                        {   $$ = $4;
                            $$->setAttribute($2);
                            savedTree = $$;
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of end dot");
                        }
                    | 	T_PROGRAM T_ID routine T_DOT
                        {   $$ = $3;
                            $$->setAttribute($2);
                            savedTree = $$;
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
                    | 	T_PROGRAM T_ID routine
                    	{   $$ = $3;
                            $$->setAttribute($2);
                            savedTree = $$;
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon and end dot");
                        }
                    ;
routine             :   routine_head routine_body
                        {
                            $$ =$1;
                            $$->setSibling($2);
                        };
routine_head        :   const_part type_part var_part routine_part
                        {
                            $$ = new TreeDefine(ROUTINEHEAD,line_no);
                            $$->addChild($1);
                            $$->addChild($2);
                            $$->addChild($3);
                            $$->addChild($4);
                        };
routine_part        :
                        {   $$ = NULL;}
                    |   routine_part function_decl
                        {   TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($2);
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |   routine_part procedure_decl
                        {   TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($2);
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |   function_decl   {$$=$1;}
                    |   procedure_decl  {$$=$1;}
                    ;
function_decl       :   function_head T_SEMI routine T_SEMI
                        {
                            $$=new TreeDefine(FUNCTION,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                        }
                    |	function_head T_SEMI routine
                        {
                            $$=new TreeDefine(FUNCTION,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
                    |	function_head routine T_SEMI
                        {
                            $$=new TreeDefine(FUNCTION,line_no);
                            $$->addChild($1);
                            $$->addChild($2);
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
                    |	function_head routine
                        {
                            $$=new TreeDefine(FUNCTION,line_no);
                            $$->addChild($1);
                            $$->addChild($2);
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
                    ;
function_head       :   T_FUNCTION T_ID parameters  T_COLON simple_type_decl
                        {
                            $$=new TreeDefine(FUNCTIONHEAD,line_no);
                            $$->setAttribute($2);
                            $$->addChild($3);
                            $$->addChild($5);
                        }
                    ;
parameters          :
                        {$$=NULL;}
                    |   T_LP para_decl_list T_RP
                        {$$=$2;}
                    ;
para_decl_list      :   para_decl_list  T_SEMI  para_type_list
                        {   TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($3);
                                $$=$1;
                            }
                            else
                                $$=$3;
                        }
                    |   para_type_list
                        {   $$=$1; }
                    ;
para_type_list      :   T_VAR name_list T_COLON simple_type_decl
                        {
                            $$=new TreeDefine(VAR_PARA,line_no);
                            $$->addChild($2);
                            $$->addChild($4);
                        }
                    |   name_list T_COLON simple_type_decl
                        {
                            $$=new TreeDefine(VAL_PARA,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                        }
                    ;
procedure_decl      :   procedure_head T_SEMI routine T_SEMI
                        {
                            $$=new TreeDefine(PROCEDURE,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                        }
                    ;
procedure_head      :   T_PROCEDURE T_ID parameters
                        {
                            $$=new TreeDefine(PROCEDUREHEAD,line_no);
                            $$->setAttribute($2);
                            $$->addChild($3);
                        }
                    ;
var_part            :
                        {   $$ = NULL;}
                    |   T_VAR var_decl_list
                        {   $$=$2;}
                    ;
var_decl_list       :   var_decl_list var_decl
                        {   TreeNode t = $1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($2);
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |   var_decl    {$$=$1;}
                    ;
var_decl            :   name_list T_COLON type_decl T_SEMI
                        {   $$=new TreeDefine(VAR,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                        }
                    |   name_list T_COLON type_decl
                        {   $$=new TreeDefine(VAR,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
                    ;
const_part          :
                        {   $$ = NULL; }
                    |   T_CONST const_expr_list
                        {   $$=$2; }
                    ;
const_expr_list     :   const_expr_list const_expr
                        {
                            TreeNode t = $1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($2);
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }

                    |   const_expr
                        {   $$=$1; }
                    ;
const_expr          :    ID T_EQUAL const_value T_SEMI
                        {
                            $$=new TreeDefine(DK_CONST,line_no);
                            $$->setAttribute($1->getAttribute());
                            $$->addChild($3);
                            $$->setExpType($3->getExpType());
                        }
                    |	ID T_EQUAL const_value
                        {
                            $$=new TreeDefine(DK_CONST,line_no);
                            $$->setAttribute($1->getAttribute());
                            $$->addChild($3);
                            $$->setExpType($3->getExpType());
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
                    ;
const_value         :   T_INT
                        {
                            $$ =new TreeDefine(EK_CONST,line_no);
                            $$->setExpType(INT);
                            $$->setAttribute($1);
                        }
                    |   T_REAL
                        {
                            $$ = new TreeDefine(EK_CONST,line_no);
                            $$->setExpType(REAL);
                            $$->setAttribute($1);
                        }
                    |   T_CHAR
                        {
                            $$ = new TreeDefine(EK_CONST,line_no);
                            $$->setExpType(CHAR);
                            $$->setAttribute($1);
                        }
                    |   T_STRING
                        {
                            $$ = new TreeDefine(EK_CONST,line_no);
                            $$->setExpType(STRING);
                            $$->setAttribute($1);
                        }
                    |   T_TRUE
                        {
                            $$=new TreeDefine(EK_CONST,line_no);
                            $$->setExpType(BOOL);
                            $$->setAttribute(1);
                        }
                    |   T_FALSE
                        {
                            $$=new TreeDefine(EK_CONST,line_no);
                            $$->setExpType(BOOL);
                            $$->setAttribute(0);
                        }
                    |   T_MAXINT
                        {
                            $$=new TreeDefine(EK_CONST,line_no);
                            $$->setExpType(INT);
                            $$->setAttribute(2147483647);
                        }
                    ;
type_part           :
                        {   $$=NULL;}
                    |   T_TYPE type_decl_list
                        {   $$=$2;}
                    ;
type_decl_list      :   type_decl_list  type_definition
                        {
                            TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($2);
                                $$=$1;
                            }
                            else
                              $$=$2;
                        }
                    |   type_definition
                        {   $$=$1;}
                    ;
type_definition     :   ID T_EQUAL type_decl T_SEMI
                        {   $$=new TreeDefine(TYPE,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                        }
                    |   ID T_EQUAL type_decl
                        {   $$=new TreeDefine(TYPE,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
                    ;
type_decl           :   simple_type_decl    {$$=$1;}
                    |   array_type_decl     {$$=$1;}
                    |   record_type_decl    {$$=$1;}
                    ;
record_type_decl    :   T_RECORD field_decl_list T_END
                        {   $$=$2; }
                    ;
field_decl_list     :   field_decl_list field_decl
                        {
                            TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($2);
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |   field_decl {$$=$1;}
                    ;
field_decl          :   name_list T_COLON type_decl T_SEMI
                        {
                            $$=new TreeDefine(TK_RECORD,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                        }
                    |   name_list T_COLON type_decl
                        {
                            $$=new TreeDefine(TK_RECORD,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                            errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
                    ;
array_type_decl     :   T_ARRAY T_LB simple_type_decl T_RB T_OF type_decl
                        {
                            $$=new TreeDefine(TK_ARRAY,line_no);
                            $$->addChild($3);
                            $$->addChild($6);
                            $$->setExpType(ET_ARRAY);
                        }
                    ;
simple_type_decl    :   ID
                        {
                            $$=new TreeDefine(SIMPLE_ID,line_no);
                            $$->setAttribute($1->getAttribute());
                            //free($1);
                        }
                    |   T_LP name_list T_RP
                        {   $$=new TreeDefine(TK_SIMPLE_ENUM,line_no);
                            $$->addChild($2);
                            $$->setExpType(ET_SIMPLE_ENUM);
                        }
                    |   const_value T_DOTDOT const_value
                        {   $$=new TreeDefine(TK_SIMPLE_LIMIT,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                            $$->setExpType(ET_SIMPLE_LIMIT);
                        }
                    |   T_MINUS const_value T_DOTDOT const_value
                        {
                            $$=new TreeDefine(TK_SIMPLE_LIMIT,line_no);
                            $$->addChild($2);
                            $$->getChildren().at(0)->setAttribute($$->getChildren().at(0)->getAttribute()._int*(-1));
                            $$->addChild($4);
                            $$->setExpType(ET_SIMPLE_LIMIT);
                        }
                    |   T_MINUS const_value T_DOTDOT T_MINUS const_value
                        {   $$=new TreeDefine(TK_SIMPLE_LIMIT,line_no);
                            $$->addChild($2);
                            $$->getChildren().at(0)->setAttribute($$->getChildren().at(0)->getAttribute()._int*(-1));
                            $$->addChild($5);
                            $$->getChildren().at(1)->setAttribute($$->getChildren().at(1)->getAttribute()._int*(-1));
                            $$->setExpType(ET_SIMPLE_LIMIT);
                        }
                    |   ID T_DOTDOT ID
                        {
                            $$=new TreeDefine(TK_SIMPLE_LIMIT,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                            $$->setExpType(ET_SIMPLE_LIMIT);
                        }
                    |   T_INTEGER_TYPE
                        {   $$=new TreeDefine(SIMPLE_SYS,line_no);
                            $$->setExpType(INT);
                        }
                    |   T_BOOLEAN_TYPE
                        {   $$=new TreeDefine(SIMPLE_SYS,line_no);
                            $$->setExpType(BOOL);
                        }
                    |   T_REAL_TYPE
                        {   $$=new TreeDefine(SIMPLE_SYS,line_no);
                            $$->setExpType(REAL);
                        }
                    |   T_CHAR_TYPE
                        {   $$=new TreeDefine(SIMPLE_SYS,line_no);
                            $$->setExpType(CHAR);
                        }
                    ;
name_list           :   name_list T_COMMA ID
                        {
                            TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($3);
                                $$=$1;
                            }
                            else
                                $$=$3;
                        }
                    |   ID {   $$=$1; }
                    ;
ID                  :   T_ID
                        {   $$=new TreeDefine(EK_ID,line_no);
                            $$->setAttribute($1);
                        } ;
routine_body        :   compound_stmt   {$$=$1;} ;
compound_stmt       :   T_BEGIN stmt_list T_END {$$=$2;} 
					|	T_BEGIN stmt_list {$$=$2; errMsg.push_back("error at line " + to_string(line_no) + ", lack of end");} ;
stmt_list           :
                        {$$=NULL;}
                    |   stmt_list stmt T_SEMI
                        {
                            TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($2);
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |	stmt_list stmt
                        {
                            TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($2);
                                $$=$1;
                            }
                            else
                                $$=$2;
                           errMsg.push_back("error at line " + to_string(line_no) + ", lack of semicolon");
                        }
                    ;
stmt                :   T_INT T_COLON no_label_stmt
                        {
                            $$=new TreeDefine(LABEL,line_no);
                            $$->setAttribute($1);
                            $$->addChild($3);
                        }
                    |   no_label_stmt
                        {   $$=$1;}
                    ;
no_label_stmt       :   assign_stmt {$$=$1;}
                    |   compound_stmt   {$$=$1;}
                    |   goto_stmt   {$$=$1;}
                    |   if_stmt     {$$=$1;}
                    |   repeat_stmt {$$=$1;}
                    |   while_stmt  {$$=$1;}
                    |   case_stmt   {$$=$1;}
                    |   for_stmt    {$$=$1;}
                    |   proc_stmt   {$$=$1;};
assign_stmt         :   ID T_ASSIGN expression
                        {   $$=new TreeDefine(ASSIGN,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                            $$->setAttribute(OK_ID,4);
                        }
                    |   ID T_LB expression T_RB T_ASSIGN expression
                        {   $$=new TreeDefine(ASSIGN,line_no);
                            $$->addChild($1);
                            ($$->getChildren().at(0))->addChild($3);
                            $$->addChild($6);
                            $$->setAttribute(OK_ARRAY,4);
                        }
                    |
                        ID T_DOT ID T_ASSIGN expression
                        {   $$=new TreeDefine(ASSIGN,line_no);
                            $$->addChild($1);
                            ($$->getChildren().at(0))->addChild($3);
                            $$->addChild($5);
                            $$->setAttribute(OK_RECORD,4);
                        }
                    ;
goto_stmt           :   T_GOTO  T_INT
                        {   $$=new TreeDefine(GOTO,line_no);
                            $$->setAttribute($2);
                        }
                    ;
if_stmt             :   T_IF expression T_THEN stmt  else_clause
                        {   $$=new TreeDefine(IF,line_no);
                            $$->addChild($2);
                            $$->addChild($4);
                            $$->addChild($5);
                        }
                    |	T_IF expression  stmt  else_clause
                        {   $$=new TreeDefine(IF,line_no);
                            $$->addChild($2);
                            $$->addChild($3);
                            $$->addChild($4);
                             errMsg.push_back("error at line " + to_string(line_no) + ", lack of then");
                        }
                    ;
else_clause         :   {$$=NULL;}
                    |   T_ELSE  stmt    {$$=$2;}
                    ;
repeat_stmt         :   T_REPEAT stmt_list T_UNTIL expression
                        {
                            $$=new TreeDefine(REPEAT,line_no);
                            $$->addChild($2);
                            $$->addChild($4);
                        }
                    |	{}
                    ;
while_stmt          :   T_WHILE expression T_DO stmt
                        {   $$=new TreeDefine(WHILE,line_no);
                            $$->addChild($2);
                            $$->addChild($4);
                        };
case_stmt           :   T_CASE expression T_OF case_expr_list T_END
                        {   $$=new TreeDefine(SK_CASE,line_no);
                            $$->addChild($2);
                            $$->addChild($4);
                        };
case_expr_list      :   case_expr_list  case_expr
                        {   TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($2);
                                $$=$1;
                            }
                            else
                                $$=$2;
                        }
                    |   case_expr   {$$=$1;};
case_expr           :   const_value T_COLON stmt T_SEMI
                        {
                            $$=new TreeDefine(EK_CASE,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                        }
                    |   ID  T_COLON stmt T_SEMI
                        {
                            $$=new TreeDefine(EK_CASE,line_no);
                            $$->addChild($1);
                            $$->addChild($3);
                        };
for_stmt            :   T_FOR ID T_ASSIGN expression T_TO expression T_DO stmt
                        {
                            $$=new TreeDefine(FOR,line_no);
                            $$->addChild($2);
                            $$->addChild($4);
                            $$->addChild($6);
                            $$->addChild($8);
                            $$->setAttribute(TO,4);
                        }
                    |   T_FOR ID T_ASSIGN expression T_DOWNTO expression T_DO stmt
                        {
                            $$=new TreeDefine(FOR,line_no);
                            $$->addChild($2);
                            $$->addChild($4);
                            $$->addChild($6);
                            $$->addChild($8);
                            $$->setAttribute(DOWNTO,4);
                        };
proc_stmt           :   ID
                        {   $$=new TreeDefine(PROC_ID,line_no);
                            $$->setAttribute($1->getAttribute());
                        }
                    |   ID T_LP args_list T_RP
                        {   $$=new TreeDefine(PROC_ID,line_no);
                            $$->setAttribute($1->getAttribute());
                            $$->addChild($3);
                        }
                    |   T_READ T_LP factor T_RP
                        {
                            $$=new TreeDefine(PROC_SYS,line_no);
                            $$->setAttribute(READ,4);
                            $$->addChild($3);
                        }
                    |   T_WRITE T_LP args_list T_RP
                        {   $$=new TreeDefine(PROC_SYS,line_no);
                            $$->setAttribute(WRITE,4);
                            $$->addChild($3);
                        }
                    |   T_WRITELN
                        {   $$=new TreeDefine(PROC_SYS,line_no);
                            $$->setAttribute(WRITELN,4);
                        }
                    |   T_WRITELN T_LP args_list T_RP
                        {   $$=new TreeDefine(PROC_SYS,line_no);
                            $$->setAttribute(WRITELN,4);
                            $$->addChild($3);
                        };
args_list           :   args_list T_COMMA expression
                        {   TreeNode t=$1;
                            if(t!=NULL){
                                while(t->getSibling()!=NULL)
                                  t=t->getSibling();
                                t->setSibling($3);
                                $$=$1;
                            }
                            else
                                $$=$3;
                        }
                    |   expression  {$$=$1;};

expression          :   expression T_GE expr {   $$=new TreeDefine($1,$3,GE,line_no); }
                    |   expression T_GT expr {   $$=new TreeDefine($1,$3,GT,line_no); }
                    |   expression T_LE expr {   $$=new TreeDefine($1,$3,LE,line_no); }
                    |   expression T_LT expr {   $$=new TreeDefine($1,$3,LT,line_no); }
                    |   expression T_EQUAL expr {   $$=new TreeDefine($1,$3,EQUAL,line_no); }
                    |   expression T_UNEQUAL expr {  $$=new TreeDefine($1,$3,UNEQUAL,line_no); }
                    |   expr {   $$=$1;} ;

expr                :   expr T_PLUS term  {   $$=new TreeDefine($1,$3,PLUS,line_no); }
                    |   expr T_MINUS term  {  $$=new TreeDefine($1,$3,MINUS,line_no); }
                    |   expr T_OR term  {     $$=new TreeDefine($1,$3,OR,line_no); }
                    |   term {   $$=$1;} ;

term                :   term T_MUL factor {   $$=new TreeDefine($1,$3,MUL,line_no); }
                    |   term T_DIV factor {   $$=new TreeDefine($1,$3,DIV,line_no); }
                    |   term T_MOD factor {   $$=new TreeDefine($1,$3,MOD,line_no); }
                    |   term T_AND factor {   $$=new TreeDefine($1,$3,AND,line_no); }
                    |   factor {$$=$1;} ;

factor              :   ID
                        {$$=$1;}
                    |   ID T_LP args_list T_RP
                        {
                            $$=new TreeDefine(FUNC_ID,line_no);
                            $$->setAttribute($1->getAttribute());
                            $$->addChild($3);
                        }
                    |   const_value {$$=$1;}
                    |   T_LP expression T_RP    {$$=$2;}
                    |   T_NOT factor
                        {
                           $$=new TreeDefine($2,NULL,NOT,line_no);
                        }
                    |   T_MINUS factor
                        {   $$=new TreeDefine($2, NULL, MINUS, line_no);
                        }
                    |   ID T_LB expression T_RB
                        {   $$=$1;
                            $$->addChild($3);
                            $$->setExpType(ET_ARRAY);
                        }
                    |   ID T_DOT ID
                        {   $$=$1;
                            $$->addChild($3);
                            $$->setExpType(ET_RECORD);
                        }
                    |   T_ABS T_LP args_list T_RP
                        {
                            $$=new TreeDefine(ABS, $3,line_no);
                        }
                    |   T_CHR T_LP args_list T_RP
                        {
                            $$=new TreeDefine(CHR, $3,line_no);
                        }
                    |   T_ODD T_LP args_list T_RP
                        {
                            $$=new TreeDefine(ODD, $3,line_no);
                        }
                    |   T_ORD T_LP args_list T_RP
                        {

                            $$=new TreeDefine(ORD, $3,line_no);
                        }
                    |   T_PRED T_LP args_list T_RP
                        {
                            $$=new TreeDefine(PRED, $3,line_no);
                        }
                    |   T_SQR T_LP args_list T_RP
                        {
                            $$=new TreeDefine(SQR, $3,line_no);
                        }
                    |   T_SQRT T_LP args_list T_RP
                        {
                            $$=new TreeDefine(SQRT, $3,line_no);
                        }
                    |   T_SUCC T_LP args_list T_RP
                        {   $$=new TreeDefine(SUCC, $3,line_no);
                        }
                    ;
%%
   
void yyerror(const char *s)
{
	cerr<<s<<" | line:"<<line_no<<endl;					//out error information
}

