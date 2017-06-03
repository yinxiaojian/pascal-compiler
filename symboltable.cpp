/*************************************************************************
	> File Name: symboltable.cpp
	> Author: yinxiaojian
	> Mail: jianwen_yin@163.com
	> Created Time: Fri 02 Jun 2017 11:44:54 AM PDT
 ************************************************************************/

#include<iostream>
#include <vector>
#include <hash_map>
#include <string>
#include"symboltable.h"

using namespace std;

int symbolTable::insertScope(program *id, int parent_scope) 
{
	if(lookUpScope(id)!=-1)
		return NOT_EXIST;
	scope.push_back(scopeNode(parent_scope, id));
	return scope.size()-1;
}

int symbolTable::insertScope(function_decl *id, int parent_scope) 
{
	if(lookUpScope(id)!=-1)
		return NOT_EXIST;
	scope.push_back(scopeNode(parent_scope, id));
	return scope.size()-1;
}	

int symbolTable::insertScope(procedure_decl *id, int parent_scope) 
{
	if(lookUpScope(id)!=-1) 
		return NOT_EXIST;
	scope.push_back(scopeNode(parent_scope, id));
        return scope.size()-1;
}

int symbolTable::lookUpScope(program *id) {
	for(int i=0; i<scope.size(); ++i)
		if(scope.at(i).select==1 && scope.at(i).name==id->child1->child1->name) {
			return i;
	}
	return -1;
}

int symbolTable::lookUpScope(function_decl *id) {

	for(int i=0; i<scope.size(); ++i)
		if(scope.at(i).select==2 && scope.at(i).name==id->child1->child1->name)
			return i;
	return -1;
}

int symbolTable::lookUpScope(procedure_decl *id) {

	for(int i=0; i<scope.size(); ++i)
		if(scope.at(i).select==3 && scope.at(i).name==id->child1->child1->name)
			return i;
	return -1;
}

// hash map insert
bool symbolTable::insertSymbol(identifier *id, int s) 
{
	assert(s>=0 && s<scope.size());

	identifier *temp = lookUp(id, s);
	if(temp != NULL)
		return false;
	//constant time find() O(1)
	unordered_map<string, vector<identifier *>>::iterator it;
	if((it = hashTable.find(id->name)) == hashTable.end())
	{
		hashTable.insert(make_pair<string, vector<identifier *>>(id->name, vector<identifier *>()));
		it = hashTable.find(id->name);
	}
	it->second.push_back(id);
	id->scope = s;
	return true;
}

//look up hash table with name and scope
//null: not found node
identifier *symbolTable::lookUpSymbol(const std::string &name, int s) const 
{
	assert(s>=0 && s<scope.size());
	unordered_map<string, vector<identifier *>>::iterator it;
	if((it = hashTable.find(name)) == table.end())
		return NULL;
	vector<identifier *> symbol = iter->second;
	for(int i = 0; i < symbol.size(); i ++)
		if(symbol[i]->scope == s)
			return symbol[i];
	return NULL;
}

void symbolTable::printScope() {
	for(int i=0; i<scope.size(); ++i) {
		cout<<"SCOPE : "<<i<<endl;
		scope[i].print();
	}
}

void symbolTable::printSymbolTable() {
	for(unordered_map<string,vector<identifier *> >::iterator it = hashTable.begin(); iter!=hashTable.end(); it ++) 
	{
		printf("NAME : %s, USE SCOPE : ", iter->first.c_str());
		cout<<"NAME : "<<it->first<<" || "<<"USE SCOPE : "<<endl;
		for(int i=0; i< it->second.size(); ++i)
			cout<<it->second[i]->scope<<" ";
		cout<<endl;
	}
}
