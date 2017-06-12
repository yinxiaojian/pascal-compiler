/*************************************************************************
	> File Name: codegen.h
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Jun 2017 01:16:28 AM PDT
 ************************************************************************/

#ifndef _CODEGEN_H
#define _CODEGEN_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "symboltable.h"
#include "absyn.h"
class Generator;
class CodeGenerator{

private:
	string dataSegment;
	string codeSegment;
	static CodeGenerator *instance;
	static map<int, Generator*> generators;

public:

	CodeGenerator(){
		dataSegment = "";
		codeSegment = "";
	}

	static CodeGenerator* getinstance();
	static void init(CodeGenerator *instance);

	void writeDataLine(string line);
	void writeCodeLine(string line);
	void generate(TreeNode node);
	void generate(TreeNode node, string fileName);
	void generateCode(TreeNode node);
	void generateCode(TreeNode node, bool travelSibling);

	void error(int lineNumber, string message);

	void beforeGen(TreeNode node);
	void afterGen();
	void writeFile(string fileName);
};

#endif
