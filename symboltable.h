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
    scopeNode(int p, const string &s): parent(p), select(0) { name = "GLOBAL";}
    void print() const { 
        cout<<"PARENT: "<<parent<<endl;
        /*cout id*/
        switch(select) {
            case 0: cout<<"UNIVERSAL"<<endl; break;
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
    hash_map<string, identifier *head> table;//variable and const value

public :
    void printScope();
    void printIdentifier();
    void printConst();

    int insertScope() {//for global scope only
        scope.push_back(scopeNode(-1, "global"));
        return scope.size()-1;
    }

    int insertScope(program *id, int parent_scope) {
        if(lookUpScope(id)!=-1) {
            return NOT_EXIST;
        }
        scope.push_back(scopeNode(parent_scope, id));
        return scope.size()-1;
    }
    int insertScope(function_decl *id, int parent_scope) {
        if(lookUpScope(id)!=-1) {
            return NOT_EXIST;
        }
        scope.push_back(scopeNode(parent_scope, id));
        return scope.size()-1;
    }
    int insertScope(procedure_decl *id, int parent_scope) {
        if(lookUpScope(id)!=-1) {
            return NOT_EXIST;
        }
        scope.push_back(scopeNode(parent_scope, id));
        return scope.size()-1;
    }

    int lookUpScope(program *id);
    int lookUpScope(function_decl *id);
    int lookUpScope(procedure_decl *id);

    scopeNode getScope(int s) const {
        if(s>=scope.size())
        {
            cout<<"error scope address"<<endl;
            exit(1);
        }
        return scope.at(s);
    }
    
    bool insertMap(identifier *id, int scope);
    

    identifier *lookUpMap(const identifier * const id, int s) const ;  
    identifier *lookUpMap(const string &id, int s) const;
};

#endif
