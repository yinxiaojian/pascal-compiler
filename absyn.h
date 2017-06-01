/*************************************************************************
	> File Name: absyn.h
	> Author:yinxiaojian 
	> Mail: jianwen_yin@163.com
	> Created Time: Wed 31 May 2017 10:07:49 AM PDT
 ************************************************************************/

#ifndef _ABSYN_H
#define 
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
struct const_expr_list;
struct const_value;
struct type_definition;
typedef type_definition type_decl_list;
struct type_decl;
struct simple_type_decl;
struct array_type_decl;
struct record_type_decl;
//struct sys_type;
struct name_list;
struct range;
struct idrange;
struct field_decl;
typedef field_decl field_decl_list;
struct var_decl;
typedef var_decl var_decl_list;
struct function_decl;
//typedef function_decl function_decl_list;
struct function_head;
struct procedure_decl;
//typedef procedure_decl procedure_decl_list;
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

//definition

//operator definition: priority low->high
enum operator
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

struct compound_stmt
{
    stmt_list *child1;
    stmt_list(stmt_list *token1):child1(token1){}
}

struct stmt
{
    int select;
    int child1;
    non_label_stmt *child2;
    stmt *next
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
}

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
}

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
        }
    } child1;

    assign_stmt(identifier *token1, expression *token2)
    {
        select = 1;
        child1.pattern1.child1 = token1
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
}

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

    proc_stmt(sys_func *token1, expression_list *token2)
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
}

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
}

struct else_clause
{
    int select;
    stmt_list *child1;
    else_clause(stmt *token1):child1(token1){ select = 1; }
    else_clause(){ select = 2; }
}

struct repeat_stmt
{
    stmt_list *child1;
    expression *child2;
    repeat_stmt(stmt_list *token1, expression *token2)
    {
        child1 = token1;
        child2 = token2;
    }
}

struct while_stmt
{
    expression *child1;
    stmt *child2;
    while_stmt(expression *token1, stmt *token2)
    {
        child1 = token1;
        child2 = token2;
    }
}

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
}

struct case_stmt
{
    expression *child1;
    case_expr_list *child2;
    case_stmt(expression *token1, case_expr_list *token2)
    {
        child1 = token1;
        child2 = token2;
    }
}

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
}
struct goto_stmt
{
    int child1;//goto: integer 
    goto_stmt(int token1):child1(token1);
}

struct expression
{
    expression *child1;
    operator child2;
    expr *child3;
    expression *next;
    //expression_list is a linked list
    //like:expression->expression->expression

    expression(expression *token1, int operator, expr *token2, expression *_next)
    {
        child1 = token1;
        child3 = token2;
        next = _next;
        switch(operator)
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
}

struct expr
{
    expr *child1;
    operator child2;
    term *child3;
    
    expr(expr *token1, int operator, term *token2)
    {
        child1 = token1;
        child3 = token2;
        switch(operator)
        {
            case 1: child2 = _PLUS; break;
            case 2: child2 = _MINUS; break;
            case 3: child2 = _OR; break;
            default: break;
        }
    }
}

struct term 
{
    term *child1;
    operator child2;
    factor *child3;

    term(term *token1, int operator, factor *token2)
    {
        child1 = token1;
        child3 = token2;
        switch(operator)
        {
            case 1: child2 = _MUL; break;
            case 2: child2 = _DIV; break;
            case 3: child2 = _MOD; break;
            case 4: child2 = _AND; break;
            default: break;
        }
    }
}

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

    factor(const_part *token1)
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
            child1.pattern8 = token2;
    }

    factor(identifier *token1,  expression *token2)
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
}

struct identifier
{
}
#endif
