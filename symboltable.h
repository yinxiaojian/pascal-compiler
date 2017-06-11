/*************************************************************************
	> File Name: symboltable.h
	> Author: yinxiaojian 
	> Mail: jianwen_yin@163.com
	> Created Time: Sat 10 Jun 2017 01:19:20 AM PDT
 ************************************************************************/

#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>
#include "absyn.h"
#include "symboldefine.h"

using namespace std;

class SymbolTable {
private:
    const static int ERROR_RETURN = 0xffff;
    const static int OFFSET_INC = 4;
    const static int MAXSIZE = 256;

    static int currentNestLevel;
    static int offset;

    static unordered_map<string, list<VariableDefinition> > VariableDefinitionHashMap;
    static unordered_map<string, list<TypeDefinition> > TypeDefinitionHashMap;
    static unordered_map<string, list<FunctionDefinition> > FunctionDefinitionHashMap;
    static unordered_map<string, list<ProcedureDefinition> > ProcedureDefinitionHashMap;

	static vector<SubBoundDefinition> sdvector;
	static vector<ArrayDefinition> advector;
	static vector<RecordDefinition> rdvector;

    static int totalOffset[MAXSIZE];

public:
    static int addProcOrFunc(TreeNode headNode);
    static void insertVariable(VariableDefinition VariableDefinition, int lineNumber);
    static void insertType(TypeDefinition TypeDefinition, int lineNumber);

    static VariableDefinition lookupVar(string name);
    static TypeDefinition lookupType(string name);
    static ProcedureDefinition lookupProc(string name);
    static FunctionDefinition lookupFunc(string name);
    static LookupReturn lookupRecord(string rec, string a);

    static void initScope();

    static int enterNewScope(TreeNode t);
    static int leaveScope();

    static int updateSymbolTable(TreeNode syntaxTree);

    static void insertNode(TreeNode t);
};

#endif
