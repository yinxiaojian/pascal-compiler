/*************************************************************************
	> File Name: codegen.cpp
	> Author: yinxiaojian
	> Mail: jianwen_yin@163.com
	> Created Time: Mon 12 Jun 2017 12:25:49 AM PDT
 ************************************************************************/

#include <iostream>
#include "codegen.h"
#include "gendefine.h"
using namespace std;

CodeGenerator * CodeGenerator::instance = new CodeGenerator();
map<int, Generator*> CodeGenerator::generators;

CodeGenerator* CodeGenerator::getinstance()
{
    return instance;//starve singleton
}

void CodeGenerator::init(CodeGenerator *instance)
{
    generators.insert(pair<int,Generator*>(ASSIGN,new StmtAssignGenerator(instance)));
    generators.insert(pair<int,Generator*>(IF,new StmtIfGenerator(instance)));
    generators.insert(pair<int,Generator*>(FOR,new StmtForGenerator(instance)));
    generators.insert(pair<int,Generator*>(WHILE,new StmtWhileGenerator(instance)));
    generators.insert(pair<int,Generator*>(REPEAT,new StmtRepeatGenerator(instance)));
    generators.insert(pair<int,Generator*>(SK_CASE,new StmtCaseGenerator(instance)));
    generators.insert(pair<int,Generator*>(LABEL,new StmtLabelGenerator(instance)));
    generators.insert(pair<int,Generator*>(PROC_ID,new StmtProcIdGenerator(instance)));
    generators.insert(pair<int,Generator*>(PROC_SYS,new StmtProcSysGenerator(instance)));
    generators.insert(pair<int,Generator*>(EK_ID,new ExpIdGenerator(instance)));
    generators.insert(pair<int,Generator*>(OP,new ExpOpGenerator(instance)));
    generators.insert(pair<int,Generator*>(EK_CONST,new ExpConstGenerator(instance)));
    generators.insert(pair<int,Generator*>(EK_CASE,new ExpCaseGenerator(instance)));
    generators.insert(pair<int,Generator*>(FUNC_ID,new ExpFuncIdGenerator(instance)));
    generators.insert(pair<int,Generator*>(ROUTINEHEAD,new RoutineHeadGenerator(instance)));
    generators.insert(pair<int,Generator*>(FUNCTION,new FuncDeclGenerator(instance)));
    generators.insert(pair<int,Generator*>(PROCEDURE,new ProcDeclGenerator(instance)));
}

void CodeGenerator::writeDataLine(string line)
{
    string tmp = line + '\n';
	dataSegment += tmp;
}

void CodeGenerator::writeCodeLine(string line)
{
    string tmp = line + '\n';
	codeSegment += tmp;
}

void CodeGenerator::generate(TreeNode node)
{
    generate(node,"default.asm");
}

void CodeGenerator::generate(TreeNode node, string fileName)
{
    beforeGen(node);
	generateCode(node);
	afterGen();
	writeFile(fileName);
}

void CodeGenerator::generateCode(TreeNode node)
{
    generateCode(node,true);
}
void CodeGenerator::generateCode(TreeNode node, bool travelSibling)
{
    generators[node->getNodeType()]->generateCode(node);
	if (travelSibling){
		if (node->getSibling() != NULL){
			generateCode(node->getSibling(), true);
		}
	}
}

void CodeGenerator::error(int lineNumber, string message)
{
    lineNumber++;
    if(lineNumber>0)
        cout<<"code generate error (line: "<<to_string(lineNumber)<<"): "<<message<<endl;
    else
        cout<<"code generate error: "<<message<<endl;
    exit(1);
}

void CodeGenerator::beforeGen(TreeNode node)
{
    writeDataLine(".386");
	writeDataLine(".model flat,stdcall");
	writeDataLine("option casemap:none");
	writeDataLine("include msvcrt.inc");
	writeDataLine("includelib msvcrt.lib");
    writeDataLine("printf  proto C:dword,:dword");

	writeDataLine(".data");
	writeDataLine("lb_write_int db '%d',0");
	writeDataLine("lb_writeln_int db '%d',0ah,0dh,0");
	writeDataLine("lb_write_real db '%lf',0");
	writeDataLine("lb_writeln_real db '%lf',0ah,0dh,0");
	writeDataLine("lb_tmp db 0, 0, 0, 0, 0, 0, 0, 0");
	writeDataLine("lb_read_int db '%d',0");
	writeDataLine("lb_read_real db '%f',0");

	writeCodeLine(".code");
	SymbolTable::initScope();
	node->setAttribute("main");
}

void CodeGenerator::afterGen()
{
    int size = SymbolTable::leaveScope();
    writeCodeLine("add esp, " + to_string(size));
	writeCodeLine("ret");
	writeCodeLine("main ENDP");
	writeCodeLine("END main");
}

void CodeGenerator::writeFile(string fileName)
{
    ofstream outfile(fileName);
	if (!outfile)
	{
		cout << "open "<<fileName<<" failed!" << endl;
		return;
	}
	outfile << dataSegment << endl;
	outfile << codeSegment << endl;
    outfile.close();
}
