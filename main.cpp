/*************************************************************************
	> File Name: main.cpp
	> Author:yinxiaojian 
	> Mail: jianwen_yin@163.com
	> Created Time: Wed 31 May 2017 03:38:38 AM PDT
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "absyn.h"
#include "symboltable.h"
#include "codegen.h"
using namespace std;
extern int yyparse(void);
extern FILE* yyin;
TreeNode savedTree;
vector<string> errMsg;
CodeGenerator* instance = NULL;
StmtAssignGenerator* stmtAssignGenerator;
StmtIfGenerator* stmtIfGenerator;
StmtForGenerator* stmtForGenerator;
StmtWhileGenerator* stmtWhileGenerator;
StmtRepeatGenerator* stmtRepeatGenerator;
StmtCaseGenerator* stmtCaseGenerator;
StmtGotoGenerator* stmtGotoGenerator;
StmtLabelGenerator* stmtLabelGenerator;
StmtProcIdGenerator* stmtProcIdGenerator;
StmtProcSysGenerator* stmtProcSysGenerator;
StmtFuncAndProcGenerator* stmtFuncAndProcGenerator;
ExpIdGenerator* expIdGenerator;
ExpOpGenerator* expOpGenerator;
ExpConstGenerator* expConstGenerator;
ExpCaseGenerator* expCaseGenerator;
ExpFuncIdGenerator* expFuncIdGenerator;
FuncDeclGenerator* funcDeclGenerator;
ProcDeclGenerator* procDeclGenerator;
RoutineHeadGenerator* routineHeadGenerator;
void init(){

	instance = new CodeGenerator();
	stmtAssignGenerator = new StmtAssignGenerator(instance);
	stmtIfGenerator = new StmtIfGenerator(instance);
	stmtForGenerator = new StmtForGenerator(instance);
	stmtWhileGenerator = new StmtWhileGenerator(instance);
	stmtRepeatGenerator = new StmtRepeatGenerator(instance);
	stmtCaseGenerator = new StmtCaseGenerator(instance);
	stmtGotoGenerator = new StmtGotoGenerator(instance);
	stmtLabelGenerator = new StmtLabelGenerator(instance);
	stmtProcIdGenerator = new StmtProcIdGenerator(instance);
	stmtProcSysGenerator = new StmtProcSysGenerator(instance);
	stmtFuncAndProcGenerator = new StmtFuncAndProcGenerator(instance);
	expIdGenerator = new ExpIdGenerator(instance);
	expOpGenerator = new ExpOpGenerator(instance);
	expConstGenerator = new ExpConstGenerator(instance);
	expCaseGenerator = new ExpCaseGenerator(instance);
	expFuncIdGenerator = new ExpFuncIdGenerator(instance);
	funcDeclGenerator = new FuncDeclGenerator(instance);
	procDeclGenerator = new ProcDeclGenerator(instance);
	routineHeadGenerator = new RoutineHeadGenerator(instance);
}


int main()
{
    FILE *fp = fopen("test.spl", "r");
    if(fp == NULL)
    {
        cout<<"can not open file"<<endl;
        return -1;
    }
    yyin = fp;
    cout<<"compile begin"<<endl;
    yyparse();
    fclose(fp);
    cout<<"compile end"<<endl;
	if(errMsg.size()==0)
	{
		savedTree->printTree(savedTree,0);
		if (instance == NULL)
			init();
		instance->generate(savedTree, "out.asm");
	}	
	else
		for(int i = 0; i < errMsg.size(); i++)
			cout<<errMsg.at(i)<<endl;
    return 0;
}
