/*************************************************************************
	> File Name: symboldefine.h
    > Author: yinxiaojian
	> Mail: jianwen_yin@163.com
	> Created Time: Fri 09 Jun 2017 10:13:48 PM PDT
 ************************************************************************/

#ifndef _SYMBOLDEFINE_H
#define _SYMBOLDEFINE_H
#include <iostream>
#include <string>
#include <list>
#include "absyn.h"
using namespace std;

/* three type kind
 * type_decl ： simple_type_decl  |  array_type_decl  |  record_type_decl
 */

//simple type
class SimpleType {
public:
	string name;
	ExpressionType type;
	bool isVar;//variable jugde
	
	SimpleType():name("undifined"){}
	SimpleType(string name, ExpressionType type, bool isVar):name(name),type(type),isVar(isVar){}
};

// array index 
class SubBoundDefinition {
    public:
	ExpressionType boundType;
	Object LowerBound;
	Object UpperBound;

	SubBoundDefinition(){}
	SubBoundDefinition(ExpressionType boundType, Object lowerBound, Object upperBound) {
		this->boundType = boundType;
		LowerBound = lowerBound;
		UpperBound = upperBound;
	}
};

//array type
class RecordDefinition;
class ArrayDefinition
{
    public:
	ExpressionType arrayType;
	SubBoundDefinition subBound;

	ArrayDefinition(){}
	ArrayDefinition(ExpressionType arrayType, ExpressionType boundType, Object upper, Object lower)
	{
		this->arrayType = arrayType;
		this->subBound = SubBoundDefinition(boundType, upper, lower);
	}
};

//record
enum RecordType
{
    ANONYMOUS = 72,
	DEFINED = 73
};
//record look up return
class LookupReturn
{
public:
	int totalOff;
	int jumpLevel;
	ExpressionType type;

	LookupReturn(){}
	LookupReturn(int totalOff, int jumpLevel, ExpressionType type)
	{
		this->totalOff = totalOff;
		this->jumpLevel = jumpLevel;
		this->type = type;
	}
};
//record definition
class TypeDefinition;
class RecordDefinition 
{
    public:
	RecordType type;
	list<TypeDefinition> ptr;

	RecordDefinition(){}
	RecordDefinition(RecordType type, list<TypeDefinition> ptr):type(type),ptr(ptr){}
};


/* four symboltable format
 * 1 variable
 * 2 type
 * 3 function
 * 4 procedure
 */

//memory position
//used for mark the data offset
class MemPos 
{
public:
    int basePos;
    int offset;
	MemPos(){}
    MemPos(int basePos, int offset):basePos(basePos),offset(offset){}
};

// variable
class VariableDefinition 
{
public:
	string name;
	ExpressionType type;
	bool isConst;
	int nestLevel;
	Object pAttr;
	MemPos memPos;
    VariableDefinition():name("undefined"){}
	VariableDefinition(string name, ExpressionType type, bool isConst, int nestLevel, Object pAttr, int offset) {
		this->name = name;
		this->type = type;
		this->isConst = isConst;
		this->nestLevel = nestLevel;
		this->pAttr = pAttr;
		this->memPos = MemPos(0, offset);
	}
};

//type
class TypeDefinition
{
public:
	string name;
	ExpressionType type;
	int nestLevel;
	struct Object pAttr;
	int size;

	TypeDefinition():name("undefined"){}
	TypeDefinition(string name):name(name){}
	TypeDefinition(string name, ExpressionType type, int nestLevel, struct Object pAttr, int size)
	{
		this->name = name;
		this->type = type;
		this->nestLevel = nestLevel;
		this->pAttr = pAttr;
		this->size = size;
	}

};

//function
class FunctionDefinition
{
public:
	string name;
	list<SimpleType> paraList;
	ExpressionType retType; 
	int nestLevel; 
	FunctionDefinition():name("undefined"){}
	FunctionDefinition(string name, list<SimpleType> paraList, ExpressionType retType, int nestLevel)
	{
		this->name = name;
		this->paraList = paraList;
		this->retType = retType;
		this->nestLevel = nestLevel;
	}
};

//procedure
class ProcedureDefinition
{
public:
	string name;
	list<SimpleType> paraList;
	int nestLevel; 
	ProcedureDefinition():name("undefined"){}
	ProcedureDefinition(string name, list<SimpleType> paraList, int nestLevel)
	{
		this->name = name;
		this->paraList = paraList;
		this->nestLevel = nestLevel;
	}
};

#endif
