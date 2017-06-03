/*************************************************************************
	> File Name: symboltable.h
	> Author: yinxiaojian
	> Mail: jianwen_yin@163.com
	> Created Time: Fri 02 Jun 2017 11:44:43 AM PDT
 ************************************************************************/

#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H

#include <iostream>
#include <vector>
#include <hash_map>
#include <string>
#include <assert.h>
#include "declare.h"

#define NOT_EXIST -1
using namespace std;

/*
    Segmented storage
    every segment is a hash table 
    use hash_map to generate a hash table
    every hash table node is a linked list
    every list stores identifier with same name but in different scope 
 */

struct scopeNode
{
	// parent start from 0, 0 is root 0->1->... format
    int parent;
    int select;
    string name;
    union {
        program *type1;
        function_decl *type2;
        procedure_decl *type3;
    } type;
    scopeNode(int p, program *t):parent(p),select(1) { type.type1 = t; name = t->child1->child1->name;}
    scopeNode(int p, function_decl *t):parent(p),select(2) { type.type2 = t; name = t->child1->child1->name;}
    scopeNode(int p, procedure_decl *t):parent(p),select(3) { type.type3 = t; name = t->child1->child1->name;}
    scopeNode(int p):parent(p),select(0) { name = "ROOT"; }
    //scopeNode(int p, const string &s): parent(p), select(0) { name = "ROOT";}
    void print() const { 
        cout<<"PARENT: "<<parent<<" || ";
        /*cout id*/
        switch(select) {
            //case 0: cout<<"UNIVERSAL"<<endl; break;
            case 1: cout<<"PROGRAM : "<<name<<endl; break;
            case 2: cout<<"FUNCTION : "<<name<<endl; break;
            case 3: cout<<"PROCEDURE : "<<name<<endl; break;
            default: cout<<"INVALID SCOPE TYPE"<<endl; break;
        }
    }
};

class symbolTable {
private :
    vector<scopeNode> scope;
    unordered_map<string, vector<identifier *>> hashTable;//variable and const value

public :
    void printScope();			//print all scope from root
    void printSymbolTable();	//print all symbol : const var ..

	int insertScope(program *id, int parent_scope);
	int insertScope(function_decl *id, int parent_scope);
	int insertScope(procedure_decl *id, int parent_scope);

    int lookUpScope(function_decl *id);
    int lookUpScope(procedure_decl *id);
    
    bool insertSymbol(identifier *id, int scope);
    identifier *lookUpSymbol(const string &id, int s) const;

    scopeNode getScope(int s) const {
        assert(s<s.size())
        return scope.at(s);
    }
};

#endif
