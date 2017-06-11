/*************************************************************************
	> File Name: absyn.h
	> Author: yinxiaojian
	> Mail: jianwen_yin@163.com
	> Created Time: Fri 09 Jun 2017 01:59:25 AM PDT
 ************************************************************************/

#ifndef _ABSYN_H
#define _ABSYN_H
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include "list"
#include "typemap.h"


using namespace std;

/*1-10*/
enum DeclarationKind {
	ROUTINEHEAD = 1,
	FUNCTION,
	FUNCTIONHEAD,
	PROCEDURE,
	PROCEDUREHEAD,
	DK_CONST,
	VAR,
	TYPE,
	VAR_PARA,
	VAL_PARA
};

/*11-16*/
enum ExpressionKind {
    EK_ID = 11,
    EK_CONST,
    OP,
    EK_CASE,
    FUNC_ID,
    FUNC_SYS
};

/*17-26*/
enum ExpressionType {
    VOID = 17,
    INT,
    REAL,
    CHAR,
    STRING,
    BOOL,
    ET_ARRAY,
    ET_RECORD,
    ET_SIMPLE_ENUM,
    ET_SIMPLE_LIMIT
};
/*27-56*/
enum OperationKind {
    TO = 27,
    DOWNTO,
    READ,
    WRITE,
    WRITELN,
    PLUS,
    MINUS,
    MUL,
    DIV,
    MOD,
    LT,
    LE,
    GT,
    GE,
    EQUAL,
    UNEQUAL, 
    NOT, 
    OR, 
    AND, 
    CHR, 
    ABS, 
    ODD, 
    ORD, 
    SQRT, 
    SUCC, 
    PRED, 
    SQR, 
    OK_ID, 
    OK_RECORD, 
    OK_ARRAY
};

/*57-67*/
enum StatementKind {
    LABEL = 57,
    ASSIGN,
    GOTO,
    IF,
    REPEAT,
    WHILE,
    FOR,
    SK_CASE,
    PROC_ID,
    PROC_SYS
};

/*67-72*/
enum TypeKind {
    SIMPLE_SYS = 67,
    SIMPLE_ID,
    TK_SIMPLE_ENUM,
    TK_SIMPLE_LIMIT,
    TK_ARRAY,
    TK_RECORD
};

typedef class TreeDefine *TreeNode;
/* define in symboldefine.h*/
class RecordDefinition;
class SubBoundDefinition;
class ArrayDefinition;

struct Object
{
    int flag;
	int _int;
	double _double;
	string _string;

	RecordDefinition* rd;//5 enum
	list<struct Object> lo;//6 record
	SubBoundDefinition* sd;//7 array index
	ArrayDefinition* ad;//8 array
};

class TreeDefine
{
    private:
	vector<TreeNode> childNode;
    TreeNode siblingNode = NULL;
    int nodeType = 0;//init value
   	Object attribute;
    ExpressionType expressionType;
    ExpressionType runtimeType;
    int lineNumber = 0;
    int columnNumber = 0;
    bitset<32> bitSet;

    public:
    TreeDefine() {}

	TreeDefine(ExpressionKind nodeType, int lineNumber):nodeType(nodeType),lineNumber(lineNumber){ this->expressionType = VOID;}

	TreeDefine(DeclarationKind nodeType, int lineNumber):nodeType(nodeType),lineNumber(lineNumber) {}

	TreeDefine(TypeKind nodeType, int lineNumber):nodeType(nodeType),lineNumber(lineNumber) {}

	TreeDefine(StatementKind nodeType, int lineNumber):nodeType(nodeType),lineNumber(lineNumber) {}

    TreeDefine(TreeNode first, TreeNode second, OperationKind op, int lineNumber) {
  		this->nodeType = OP;
		this->attribute._int = op;
		this->attribute.flag = 4;//expression type
		this->lineNumber = lineNumber;
		this->addChild(first);
		this->addChild(second);
    }

    TreeDefine(OperationKind op, TreeNode child, int lineNumber) {
        this->nodeType = FUNC_SYS;
        this->attribute._int = op;
		this->attribute.flag = 4;//type
        this->lineNumber = lineNumber;
		this->addChild(child);
    }

    vector<TreeNode> getChildren();
    void addChild(TreeNode node);

    TreeNode getSibling();
    void setSibling(TreeNode siblingNode);

    int getLineNumber();
    void setLineNumber(int lineNumber);

    int getNodeType();
	void setNodeType(int nodeType);

    Object getAttribute();
    void setAttribute(Object attribute);
    void setAttribute(int attribute,int flag);
    void setAttribute(double attribute);
    void setAttribute(string attribute);

    ExpressionType getExpType();
    void setExpType(ExpressionType expressionType);

    ExpressionType getRunTimeType();
    void setRunTimeType(ExpressionType runtimeType);

    void printTree(TreeNode root, int level);
};

#endif
