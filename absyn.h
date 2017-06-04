/*************************************************************************
	> File Name: absyn.h
	> Author:yinxiaojian 
	> Mail: jianwen_yin@163.com
	> Created Time: Wed 31 May 2017 10:07:49 AM PDT
 ************************************************************************/

#ifndef _ABSYN_H
#define _ABSYN_H 
#include <iostream>
#include <string>

using namespace std;

extern int line_no;

struct program;
struct program_head;
struct routine;
struct routine_head;
struct routine_body;
struct label_part;
struct const_part;
struct type_part;
struct var_part;
struct routine_part;
struct const_expr;
typedef const_expr const_expr_list;
struct const_value;
struct type_definition;
typedef type_definition type_decl_list;
struct type_decl;
struct simple_type_decl;
struct array_type_decl;
struct record_type_decl;
struct name_list;
struct range;
struct idrange;
struct field_decl;
typedef field_decl field_decl_list;
struct var_decl;
typedef var_decl var_decl_list;
struct function_decl;
typedef function_decl function_decl_list;
struct function_head;
struct procedure_decl;
struct procedure_head;
struct sub_routine;
struct parameters;
struct para_type_list;
typedef para_type_list para_decl_list;
typedef name_list var_para_list;
typedef name_list val_para_list;
struct compound_stmt;
struct stmt;
typedef stmt stmt_list;
struct non_label_stmt;
struct assign_stmt;
struct proc_stmt;
struct if_stmt;
struct repeat_stmt;
struct while_stmt;
struct for_stmt;
struct case_stmt;
struct goto_stmt;
struct sys_proc;
struct expression;
typedef expression args_list;
typedef expression expression_list;
struct else_clause;
struct case_expr;
typedef case_expr case_expr_list;
struct expr;
struct term;
struct factor;

struct identifier;
struct sys_funct;
struct sys_proc;

//definition

//operator definition: priority low->high
enum operation
{
    _GE,
    _GT,
    _LE,
    _LT,
    _EQUAL,
    _UNEQUAL,

    _PLUS,
    _MINUS,
    _OR,

    _MUL,
    _DIV,
    _MOD,
    _AND,
    
    _NOT
};

enum sys_type
{
    _CHAR,
    _INTEGER,
    _REAL,
    _STRING
};

enum SYS_PROC
{
    _WRITE,
    _WRITELN
};

enum SYS_FUNCT
{
    _ABS,
    _CHR,
    _ODD,
    _ORD,
    _PRED,
    _SQR,
    _SQRT,
    _SUCC
};

enum sys_con
{
    _FALSE,
    _MAXINT,
    _TRUE
};

struct sys_proc
{
    SYS_PROC child1;
    sys_proc(SYS_PROC token1):child1(token1) {}
};

struct sys_funct
{
    SYS_FUNCT child1;
    sys_funct(SYS_FUNCT token1):child1(token1) {}
};

struct identifier
{
    string name;
    int linenumber;
    int offset;
    int scope;
    
    identifier *next;
    //linked list
    //name_list
    
    identifier(string &token1, identifier *_next)
    {
        name = token1;
        next = _next;
    }
    
};

struct program
{
    program_head *child1;
    routine *child2;
    program(program_head *token1, routine *token2)
    {
        child1 = token1;
        child2 = token2;
    }
};

struct program_head
{
    identifier *child1;
    program_head(identifier *token1):child1(token1){}
};

struct routine
{
    routine_head *child1;
    routine_body *child2;
    routine(routine_head *token1, routine_body *token2)
    {
        child1 = token1;
        child2 = token2;
    }
};

struct sub_routine
{
    routine_head *child1;
    routine_body *child2;
    sub_routine(routine_head *token1, routine_body *token2)
    {
        child1 = token1;
        child2 = token2;
    }
};

struct routine_head
{
    label_part *child1;
    const_part *child2;
    type_part *child3;
    var_part *child4;
    routine_part *child5;
    routine_head(label_part *token1, const_part *token2, type_part *token3, var_part *token4, routine_part *token5)
    {
        child1 = token1;
        child2 = token2;
        child3 = token3;
        child4 = token4;
        child5 = token5;
    }
};

struct label_part
{
    //not support...
};

struct const_part
{
    const_expr_list *child1;
    const_part(const_expr_list *token1):child1(token1){}
};

struct const_expr
{
    identifier *child1;
    const_value *child2;
    const_expr *next;
    //linked list
    //const_expr_list

    const_expr(identifier *token1, const_value *token2, const_expr *_next)
    {
        child1 = token1;
        child2 = token2;
        next = _next;
    }
};

struct const_value
{
    int select;
    union
    {
        char pattern1;
        int pattern2;
        float pattern3;
        char* pattern4;
        sys_con pattern5;
    } child1;

    const_value(char token1):select(1){child1.pattern1 = token1;}
    const_value(int token1):select(2){child1.pattern2 = token1;}
    const_value(float token1):select(3){child1.pattern3 = token1;}
    const_value(char* token1):select(4){child1.pattern4 = token1;}
    const_value(sys_con token1):select(5){child1.pattern5 = token1;}
};

struct type_part
{
    type_decl_list *child1;
    type_part(type_decl_list *token1):child1(token1){}
};

struct type_definition
{
    identifier *child1;
    type_decl *child2;
    //type_definition linked list
    //type_decl_list
    type_definition *next;
    type_definition(identifier *token1, type_decl *token2, type_definition *_next)
    {
        child1 = token1;
        child2 = token2;
        next = _next;
    }
};

struct type_decl
{
    int select;
    union
    {
        simple_type_decl *pattern1;
        array_type_decl *pattern2;
        record_type_decl *pattern3;
    } child1;
    type_decl(simple_type_decl *token1):select(1){child1.pattern1 = token1;}
    type_decl(array_type_decl *token1):select(2){child1.pattern2 = token1;}
    type_decl(record_type_decl *token1):select(3){child1.pattern3 = token1;}
};

struct simple_type_decl
{
    int select;
    union
    {
        sys_type pattern1;
        identifier *pattern2;
        name_list *pattern3;
        struct
        {
            const_value *child1;
            const_value *child2;
            int minus_select;
        } pattern4;
        struct
        {
            identifier *child1;
            identifier *child2;
        } pattern5;
    } child1;
    simple_type_decl(sys_type token1)
    {
        select = 1;
        child1.pattern1 = token1;
    }
    simple_type_decl(identifier *token1)
    {
        select = 2;
        child1.pattern2 = token1;
    }
    simple_type_decl(name_list *token1)
    {
        select = 3;
        child1.pattern3 = token1;
    }
    simple_type_decl(const_value *token1, const_value *token2, int _minus_select)
    {
        select = 4;
        child1.pattern4.child1 = token1;
        child1.pattern4.child2 = token2;
        child1.pattern4.minus_select = _minus_select;
    }
    simple_type_decl(identifier *token1, identifier *token2)
    {
        select = 5;
        child1.pattern5.child1 = token1;
        child1.pattern5.child2 = token2;
    }
};

struct array_type_decl
{
    simple_type_decl *child1;
    type_decl *child2;
    array_type_decl(simple_type_decl *token1, type_decl *token2)
    {
        child1 = token1;
        child2 = token2;
    }
};

//TODO replace with record_type_decl
struct record_type_decl
{
    field_decl_list *child1;
    record_type_decl(field_decl_list *token1):child1(token1){}
};

struct field_decl
{
    name_list *child1;
    type_decl *child2;
    field_decl *next;
    field_decl(name_list *token1, type_decl *token2, field_decl *_next)
    {
        child1 = token1;
        child2 = token2;
        next = _next;
    }
};
//name_list

struct name_list
{
    identifier *child1;
    name_list *next;
    name_list(identifier *token1, name_list *_next)
    {
        child1 = token1;
        next = _next;
    }
};

struct var_part
{
    var_decl_list *child1;
    var_part(var_decl_list *token1):child1(token1){}
};

struct var_decl
{
    name_list *child1;
    type_decl *child2;
    var_decl *next;
    var_decl(name_list *token1, type_decl *token2, var_decl *_next)
    {
        child1 = token1;
        child2 = token2;
        next = _next;
    }
};

struct routine_part
{
    function_decl_list *child1;
    procedure_decl *child2;
    routine_part(function_decl_list *token1, procedure_decl *token2)
    {
        child1 = token1;
        child2 = token2;
    }
};

struct function_decl
{
    function_head *child1;
    sub_routine *child2;
    function_decl *next;
    function_decl(function_head *token1, sub_routine *token2, function_decl *_next)
    {
        child1 = token1;
        child2 = token2;
        next = _next;
    }
};

struct function_head
{
    identifier *child1;
    parameters *child2;
    simple_type_decl *child3;
    function_head(identifier *token1, parameters *token2, simple_type_decl *token3)
    {
        child1 = token1;
        child2 = token2;
        child3 = token3;
    }
};

struct procedure_decl
{
    procedure_head *child1;
    sub_routine *child2;
    procedure_decl *next;

    procedure_decl(procedure_head *token1, sub_routine *token2, procedure_decl *_next)
    {
        child1 = token1;
        child2 = token2;
        next = _next;
    }
};

struct procedure_head
{
    identifier *child1;
    parameters *child2;
    procedure_head(identifier *token1, parameters *token2)
    {
        child1 = token1;
        child2 = token2;
    }
};

struct parameters
{
    para_decl_list *child1;
    parameters(para_type_list *token1):child1(token1){}
};

struct para_type_list
{
    union
    {
        struct
        {
            var_para_list *child1;
            simple_type_decl *child2;
        } pattern1;

        struct
        {
            val_para_list *child1;
            para_type_list *child2;
        } pattern2;
    } child1;
    para_type_list *next;

    para_type_list(var_para_list *token1, simple_type_decl *token2, para_type_list *_next)
    {
        child1.pattern1.child1 = token1;
        child1.pattern1.child2 = token2;
        next = _next;
    }

    para_type_list(var_para_list *token1, para_type_list *token2, para_type_list *_next)
    {
        child1.pattern2.child1 = token1;
        child1.pattern2.child2 = token2;
        next = _next;
    }
};

struct routine_body
{
    compound_stmt *child1;
    routine_body(compound_stmt *token1):child1(token1){}
};

struct compound_stmt
{
    // TODO:waitting for check
    stmt_list *child1;
    compound_stmt(stmt_list *token1):child1(token1){}
};

struct stmt
{
    int select;
    int child1;
    non_label_stmt *child2;
    stmt *next;
    //linked list
    //stmt->stmt->stmt
    
    stmt(int token1, non_label_stmt *token2, stmt *_next)
    {
        select = 1;
        child1 = token1;
        child2 = token2;
        next = _next;
    }

    stmt(non_label_stmt *token1, stmt *_next)
    {
        select = 2;
        child2 = token1;
        next = _next;
    }
};

struct non_label_stmt
{
    int select;
    union
    {
        assign_stmt *pattern1;
        proc_stmt *pattern2;
        compound_stmt *pattern3;
        if_stmt *pattern4;
        repeat_stmt *pattern5;
        while_stmt *pattern6;
        for_stmt *pattern7;
        case_stmt *pattern8;
        goto_stmt *pattern9;
    } child1;

    non_label_stmt(assign_stmt *token1):select(1){ child1.pattern1 = token1; }
    non_label_stmt(proc_stmt *token1):select(2){ child1.pattern2 = token1; }
    non_label_stmt(compound_stmt *token1):select(3){ child1.pattern3 = token1; }
    non_label_stmt(if_stmt *token1):select(4){ child1.pattern4 = token1; }
    non_label_stmt(repeat_stmt *token1):select(5){ child1.pattern5 = token1; }
    non_label_stmt(while_stmt *token1):select(6){ child1.pattern6 = token1; }
    non_label_stmt(for_stmt *token1):select(7){ child1.pattern7 = token1; }
    non_label_stmt(case_stmt *token1):select(8){ child1.pattern8 = token1; }
    non_label_stmt(goto_stmt *token1):select(9){ child1.pattern9 = token1; }
};

struct assign_stmt
{
    int select;
    union
    {
        struct
        {
            identifier *child1;
            expression *child2;
        } pattern1;
        
        struct
        {
            identifier *child1;
            expression *child2;
            expression *child3;
        } pattern2;

        struct
        {
            identifier *child1;
            identifier *child2;
            expression *child3;
        } pattern3;
   } child1;

    assign_stmt(identifier *token1, expression *token2)
    {
        select = 1;
        child1.pattern1.child1 = token1;
        child1.pattern1.child2 = token2;
    }

    assign_stmt(identifier *token1, expression *token2, expression *token3)
    {
        select = 2;
        child1.pattern2.child1 = token1;
        child1.pattern2.child2 = token2;
        child1.pattern2.child3 = token3;
    }

    assign_stmt(identifier *token1, identifier *token2, expression *token3)
    {
        select = 3;
        child1.pattern3.child1 = token1;
        child1.pattern3.child2 = token2;
        child1.pattern3.child3 = token3;
    }
};

struct proc_stmt
{
    int select;
    union
    {
        identifier *pattern1;
        struct
        {
            identifier *child1;
            args_list *child2;
        } pattern2;
        sys_proc *pattern3;
        struct
        {
            sys_proc *child1;
            expression_list *child2;
        } pattern4;
        factor *pattern5;
    } child1;

    proc_stmt(identifier *token1)
    {
        select = 1;
        child1.pattern1 = token1;
    }

    proc_stmt(identifier *token1, args_list *token2)
    {
        select = 2;
        child1.pattern2.child1 = token1;
        child1.pattern2.child2 = token2;
    }

    proc_stmt(sys_proc *token1)
    {
        select = 3;
        child1.pattern3 = token1;
    }

    proc_stmt(sys_proc *token1, expression_list *token2)
    {
        select = 4;
        child1.pattern4.child1 = token1;
        child1.pattern4.child2 = token2;
    }

    proc_stmt(factor *token1)
    {
        select = 5;
        child1.pattern5 = token1;
    }
};

struct if_stmt
{
    expression *child1;
    stmt *child2;
    else_clause *child3;
    if_stmt(expression *token1, stmt *token2, else_clause *token3)
    {
        child1 = token1;
        child2 = token2;
        child3 = token3;
    }
};

struct else_clause
{
    int select;
    stmt_list *child1;
    else_clause(stmt *token1):child1(token1){ select = 1; }
    else_clause(){ select = 2; }
};

struct repeat_stmt
{
    stmt_list *child1;
    expression *child2;
    repeat_stmt(stmt_list *token1, expression *token2)
    {
        child1 = token1;
        child2 = token2;
    }
};

struct while_stmt
{
    expression *child1;
    stmt *child2;
    while_stmt(expression *token1, stmt *token2)
    {
        child1 = token1;
        child2 = token2;
    }
};

struct for_stmt
{
    identifier *child1;
    expression *child2;
    int direction;
    expression *child3;
    stmt *child4;
    for_stmt(identifier *token1, expression *token2,
            int _direction, expression *token3, stmt *token4)
    {
        child1 = token1;
        child2 = token2;
        direction = _direction;
        child3 = token3;
        child4 = token4;
    }
};

struct case_stmt
{
    expression *child1;
    case_expr_list *child2;
    case_stmt(expression *token1, case_expr_list *token2)
    {
        child1 = token1;
        child2 = token2;
    }
};

struct case_expr
{
    int select;
    union
    {
        const_value *pattern1;
        identifier *pattern2;
    } child1;
    stmt *child2;
    case_expr *next;
    //case_expr_list is a linked list
    //like:case_expr->case_expr->case_expr

    case_expr(const_value *token1, stmt *token2, case_expr *_next)
    {
        select = 1;
        child1.pattern1 = token1;
        child2 = token2;
        next = _next;
    }

    case_expr(identifier *token1, stmt *token2, case_expr *_next)
    {
        select = 2;
        child1.pattern2 = token1;        
        child2 = token2;
        next = _next;
    }
};

struct goto_stmt
{
    int child1;//goto: integer 
    goto_stmt(int token1):child1(token1){};
};

struct expression
{
    expression *child1;
    operation child2;
    expr *child3;
    expression *next;
    //expression_list is a linked list
    //like:expression->expression->expression

    expression(expression *token1, int _operator, expr *token2, expression *_next)
    {
        child1 = token1;
        child3 = token2;
        next = _next;
        switch(_operator)
        {
            case 1: child2 = _GE; break;
            case 2: child2 = _GT; break;
            case 3: child2 = _LE; break;
            case 4: child2 = _LT; break;
            case 5: child2 = _EQUAL; break;
            case 6: child2 = _UNEQUAL; break;
            default: break;
        }
    }
};

struct expr
{
    expr *child1;
    operation child2;
    term *child3;
    
    expr(expr *token1, int _operator, term *token2)
    {
        child1 = token1;
        child3 = token2;
        switch(_operator)
        {
            case 1: child2 = _PLUS; break;
            case 2: child2 = _MINUS; break;
            case 3: child2 = _OR; break;
            default: break;
        }
    }
};

struct term 
{
    term *child1;
    operation child2;
    factor *child3;

    term(term *token1, int _operator, factor *token2)
    {
        child1 = token1;
        child3 = token2;
        switch(_operator)
        {
            case 1: child2 = _MUL; break;
            case 2: child2 = _DIV; break;
            case 3: child2 = _MOD; break;
            case 4: child2 = _AND; break;
            default: break;
        }
    }
};

struct factor
{
    int select;
    union
    {
        identifier *pattern1;
        struct 
        {
            identifier *child1;
            args_list *child2;
        } pattern2;
        sys_funct *pattern3;
        struct
        {
            sys_funct *child1;
            args_list *child2;
        } pattern4;
        const_value *pattern5;
        expression *pattern6;
        factor *pattern7;   //NOT factor
        factor *pattern8;   //MINUS factor
        struct
        {
            identifier *child1;
            expression *child2;
        } pattern9;
        struct
        {
            identifier *child1;
            identifier *child2;
        } pattern10;
    } child1;
    
    factor(identifier *token1)
    {
        select = 1; 
        child1.pattern1=token1;
    }

    factor(identifier *token1, args_list *token2)
    {
        select = 2;
        child1.pattern2.child1 = token1;
        child1.pattern2.child2 = token2;
    }

    factor(sys_funct *token1)
    {
        select = 3;
        child1.pattern3 = token1;
    }

    factor(sys_funct *token1, args_list *token2)
    {
        select = 4;
        child1.pattern4.child1 = token1;
        child1.pattern4.child2 = token2;
    }

    factor(const_value *token1)
    {
        select = 5;
        child1.pattern5 = token1;
    }

    factor(expression *token1)
    {
        select = 6;
        child1.pattern6 = token1;
    }

    factor(factor *token1, int _select) //_select equal select
    {
        select = _select;
        if(_select == 7)
            child1.pattern7 = token1;
        else if(_select == 8)
            child1.pattern8 = token1;
    }

    factor(identifier *token1,  expression *token2, int overload)
    {
        select = 9;
        child1.pattern9.child1 = token1;
        child1.pattern9.child2 = token2;
    }

    factor(identifier *token1, identifier *token2)
    {
        select = 10;
        child1.pattern10.child1 = token1;
        child1.pattern10.child2 = token2;
    }
};

#endif
