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
#include <sstream>
#include <unordered_map>
#include "symboltable.h"
#include "absyn.h"

class CodeGenerator{

public:

	CodeGenerator(){
		dataSegment = "";
		codeSegment = "";
	}

	void writeDataLine(string line){
		string tmp = line + '\n';
		dataSegment += tmp;
	}

	void writeCodeLine(string line){
		string tmp = line + '\n';
		codeSegment += tmp;
	}

	void generate(TreeNode node, string fileName){
		beforeGen(node);
		generateCode(node);
		afterGen();
		writeFile(fileName);
	}

	void generateCode(TreeNode node){
		generateCode(node, true);
	}

	//TODO
	void generateCode(TreeNode node, bool travelSibling);

	void error(int lineNumber, string message){
		lineNumber++;
		stringstream ss;
		string str;
		ss << lineNumber;
		ss >> str;
		if (lineNumber > 0){
			printf("Code Generation Error(line ");
			printf("%d", lineNumber);
			cout << "):" + message << endl;
		}
		else{
			cout << "Code Generation Error: " + message << endl;
		}
		exit(1);
	}

	string dataSegment;
	string codeSegment;

	StatementKind Statementkind;

	void beforeGen(TreeNode node){
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

	void afterGen(){
		int paraSize = SymbolTable::leaveScope();
		stringstream ss;
		string str;
		ss << paraSize;
		ss >> str;
		writeCodeLine("add esp, " + str);
		writeCodeLine("ret");
		writeCodeLine("main ENDP");
		writeCodeLine("END main");
	}

	void writeFile(string fileName){
		ofstream outfile(fileName);

		if (!outfile)
		{
			cout << "failed!" << endl;
			return;
		}

		outfile << dataSegment << endl;
		outfile << codeSegment << endl;

		outfile.close();
	}
};

extern CodeGenerator* instance;

class Generator{
public:
	CodeGenerator *codeGenerator;

	Generator(){

	}

	Generator(CodeGenerator *codeGeneratorr){
		codeGenerator = codeGeneratorr;
	}

	void generateCode(TreeNode node);
};


class LabelManager{
private:
	static int countLabel;
	static int countRealData;
	static const string labelHeader;
	static const string codeLabelHeader;
	static const string realDataLabelHeader;
	static unordered_map<double, string> realConstPool;
	static string createDataLabel(double realData, CodeGenerator *codeGenerator){
		stringstream ss;
		string str;
		ss << countRealData;
		ss >> str;
		countRealData++;
		string label = realDataLabelHeader + str;
		stringstream ss1;
		string str1;
		ss1 << realData;
		ss1 >> str1;
		instance->writeDataLine(label + " dd " + str1);
		return label;
	}

public:

	static string createLabel(){
		stringstream ss2;
		string str2;
		ss2 << countLabel;
		ss2 >> str2;
		countLabel++;
		string label = labelHeader + str2;
		return label;
	}

	static string getLabel(int number){
		stringstream ss3;
		string str3;
		ss3 << number;
		ss3 >> str3;
		string label = labelHeader + str3;
		return label;
	}

	static string buildCodeLabel(int number){
		stringstream ss4;
		string str4;
		ss4 << number;
		ss4 >> str4;
		return buildCodeLabel(str4);
	}

	static string buildCodeLabel(string label){
		return (codeLabelHeader + label);
	}

	static string getDataLabel(double realData, CodeGenerator *codeGenerator){
		string label = realConstPool[realData];
		if (label.empty()){
			label = createDataLabel(realData, codeGenerator);
			realConstPool.insert(pair<double, string>(realData, label));
		}
		return label;
	}

};

int LabelManager::countLabel = 0;
int LabelManager::countRealData = 0;
const string LabelManager::labelHeader = "_LABEL_";
const string LabelManager::codeLabelHeader = "_CODE_LABEL_";
const string LabelManager::realDataLabelHeader = "_REAL_DATA_";
unordered_map<double, string> LabelManager::realConstPool = unordered_map<double, string>();

class OptimizationUtils{
public:
	static const int ALWAYS_TRUE = 0;
	static const int ALWAYS_FALSE = 1;
	static const int CANNOT_DETERMINE = 2;
	static int alwaysTrue(TreeNode cond) {
		int ret = CANNOT_DETERMINE;
		if (!(cond->getExpType() == 0))
			return ret;
		if (cond->getExpType() == ExpressionType::BOOL) {
			if (cond->getAttribute()._int == 0) {
				ret = ALWAYS_FALSE;
			}
			else {
				ret = ALWAYS_TRUE;
			}
		}
		return ret;
	}
	static bool compareForCond(TreeNode cond1, TreeNode cond2, TreeNode op) {
		if ((cond1->getNodeType() < 10) || (cond1->getNodeType() > 15))
			return false;
		if ((cond2->getNodeType() < 10) || (cond2->getNodeType() > 15))
			return false;
		if (cond1->getNodeType() != ExpressionKind::EK_CONST || cond2->getNodeType() != ExpressionKind::EK_CONST)
			return false;
		if (cond1->getExpType() != ExpressionType::INT && cond1->getExpType() != ExpressionType::CHAR)
			return false;
		if (cond2->getExpType() != ExpressionType::INT && cond2->getExpType() != ExpressionType::CHAR)
			return false;
		int startVal, endVal;
		startVal = cond1->getAttribute()._int;
		endVal = cond2->getAttribute()._int;
		OperationKind Operationkind = (OperationKind)(op->getAttribute()._int);
		if (Operationkind == OperationKind::TO && startVal > endVal)
			return true;
		if (Operationkind == OperationKind::DOWNTO && startVal < endVal)
			return true;
		return false;
	}

};

class ExpCaseGenerator : public Generator{
public:
	ExpCaseGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	ExpCaseGenerator(){}

	void generateCode(TreeNode node){
		string nextCaseLabel = LabelManager::createLabel();

		codeGenerator->generateCode(node->getChildren()[0]);
		codeGenerator->writeCodeLine("pop ebx");
		codeGenerator->writeCodeLine("cmp ebx, eax");
		codeGenerator->writeCodeLine("jne " + nextCaseLabel);
		codeGenerator->generateCode(node->getChildren()[1]);
		codeGenerator->writeCodeLine(nextCaseLabel + ":");
		if (node->getSibling() != 0) {
			codeGenerator->writeCodeLine("push ebx");
		}
	}
};

class ExpConstGenerator : public Generator{
public:
	ExpConstGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	ExpConstGenerator(){}

	void generateCode(TreeNode node){
		if (node->getExpType() != ExpressionType::REAL){
			int value;
			if (node->getExpType() == ExpressionType::CHAR){
				value = (char)node->getNodeType();
			}
			else{
				value = node->getAttribute()._int;
			}
			stringstream ss;
			string str;
			ss << value;
			ss >> str;
			codeGenerator->writeCodeLine("mov eax, " + str);
			node->setRunTimeType(ExpressionType::INT);
		}
		else{
			double value = node->getAttribute()._double;
			string realDataLabel = LabelManager::getDataLabel(value, codeGenerator);
			codeGenerator->writeCodeLine("mov eax, " + realDataLabel);
			node->setRunTimeType(ExpressionType::REAL);
		}
	}
};

class StmtFuncAndProcGenerator : public Generator{
public:
	StmtFuncAndProcGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtFuncAndProcGenerator(){}

	void codeGeneratorPushParam(TreeNode node){
		if (node->getSibling() != NULL){
			codeGeneratorPushParam(node->getSibling());
		}
		codeGenerator->generateCode(node, false);
		codeGenerator->writeCodeLine("push eax");
	}

	void codeGeneratorPopParam(TreeNode node, list<SimpleType> paraList){
		if (node == NULL || paraList.size() == 0)
			return;
		list<SimpleType>::iterator a;
		for (a = paraList.begin(); a != paraList.end(); a++){
			if (node == NULL){
				break;
			}
			if (a->isVar){
				codeGenerator->generateCode(node, false);
				codeGenerator->writeCodeLine("pop eax");
				codeGenerator->writeCodeLine("mov [esi],eax");
			}
			else{
				codeGenerator->writeCodeLine("pop eax");
			}
			node = node->getSibling();
		}
	}
};

class ExpFuncIdGenerator : public Generator{
public:
	ExpFuncIdGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	ExpFuncIdGenerator(){}

	void generateCode(TreeNode node){
		FunctionDefinition PosalVar = SymbolTable::lookupFunc(node->getAttribute()._string);
		StmtFuncAndProcGenerator m;

		codeGenerator->writeCodeLine("push eax");
		m.codeGeneratorPushParam(node->getChildren()[0]);
		codeGenerator->writeCodeLine("push ecx");
		codeGenerator->writeCodeLine("mov ecx, esp");
		codeGenerator->writeCodeLine("call " + node->getAttribute()._string);
		codeGenerator->writeCodeLine("pop ecx");
		m.codeGeneratorPopParam(node->getChildren()[0], PosalVar.paraList);
		codeGenerator->writeCodeLine("pop eax");
	}
};

class ExpIdGenerator : public Generator{
public:
	ExpIdGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	ExpIdGenerator(){}

	void generateCode(TreeNode node){
		int level, offset;
		int lower = 0;
		ExpressionType type;
		LookupReturn recordInfo;
		VariableDefinition varInfo = SymbolTable::lookupVar(node->getAttribute()._string);

		if (varInfo.name == "null"){
			codeGenerator->error(node->getLineNumber(), "Undefined variable: " + node->getAttribute()._string);
		}

		type = varInfo.type;

		if (type == ExpressionType::ET_ARRAY){
			if (varInfo.pAttr.flag == 0){
				codeGenerator->error(node->getLineNumber(), "Variable: " + node->getAttribute()._string + " is not an array.");
			}
			ArrayDefinition* m = varInfo.pAttr.ad;
			lower = (m->subBound).LowerBound._int;
			level = varInfo.memPos.basePos;
			offset = varInfo.memPos.offset;
		}
		else if (type == ExpressionType::ET_RECORD) {
			recordInfo = SymbolTable::lookupRecord(node->getAttribute()._string, node->getChildren()[0]->getAttribute()._string);
			level = recordInfo.jumpLevel;
			offset = recordInfo.totalOff;
		}
		else {
			level = varInfo.memPos.basePos;
			offset = varInfo.memPos.offset;
		}

		stringstream sslower, ssoffset;
		string strlower, stroffset;
		sslower << lower;
		ssoffset << offset;
		sslower >> strlower;
		ssoffset >> stroffset;

		if (type == ExpressionType::ET_ARRAY) {
			codeGenerator->generateCode(node->getChildren()[0], false); 	// 计算数组下标的值
			codeGenerator->writeCodeLine("mov ebx, " + strlower);
			codeGenerator->writeCodeLine("sub eax, ebx");
			codeGenerator->writeCodeLine("mov ebx, 4");
			codeGenerator->writeCodeLine("imul eax,ebx");
			codeGenerator->writeCodeLine("mov edi, " + stroffset);
			codeGenerator->writeCodeLine("add edi, eax");
		}
		else {
			codeGenerator->writeCodeLine("mov edi, " + stroffset);
		}

		if (type == ExpressionType::ET_ARRAY) {
			ArrayDefinition* m = varInfo.pAttr.ad;
			type = m->arrayType;
		}
		else if (type == ExpressionType::ET_RECORD) {
			type = recordInfo.type;
		}

		codeGenerator->writeCodeLine("mov esi, ecx");
		while (level > 0){
			codeGenerator->writeCodeLine("mov eax, [esi]");
			codeGenerator->writeCodeLine("mov esi, eax");
			level--;
		}
		codeGenerator->writeCodeLine("add esi, edi");

		if (type == ExpressionType::INT || type == ExpressionType::CHAR || type == ExpressionType::BOOL){
			codeGenerator->writeCodeLine("mov eax, [esi]; calculate ExpId ");
			node->setRunTimeType(ExpressionType::INT);
		}
		else if (type == ExpressionType::REAL){
			codeGenerator->writeCodeLine("mov eax, dword ptr [esi]; calculate ExpId(type: real)");
			node->setRunTimeType(ExpressionType::REAL);
		}
		else {
			stringstream ss3;
			string str3;
			ss3 << node->getChildren()[0]->getRunTimeType();
			ss3 >> str3;
			codeGenerator->error(node->getLineNumber(), "Unknown running type: " + str3);
		}

	}

};

class ExpOpGenerator : public Generator{
public:
	ExpOpGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	ExpOpGenerator(){}

	void generateCode(TreeNode node){
		if (node->getChildren()[0] != NULL && node->getChildren()[1] != NULL){
			TreeNode child1 = node->getChildren()[0];
			TreeNode child2 = node->getChildren()[1];

			codeGenerator->generateCode(child1);
			codeGenerator->writeCodeLine("push eax");
			codeGenerator->generateCode(child2);
			codeGenerator->writeCodeLine("push eax");

			if (child1->getRunTimeType() != child2->getRunTimeType()) {
				codeGenerator->error(node->getLineNumber(), "The type of the two operands are not same.");
			}

			node->setRunTimeType(child1->getRunTimeType());
		}
		else if (node->getChildren()[0] != NULL) {
			codeGenerator->writeCodeLine("push 0");
			codeGenerator->generateCode(node->getChildren()[0]);
			codeGenerator->writeCodeLine("push eax");

			node->setRunTimeType(node->getChildren()[0]->getRunTimeType());

		}
		else {
			codeGenerator->error(node->getLineNumber(), "Operator with unsupported number of operand.");
		}

		OperationKind Operationkind = (OperationKind)node->getAttribute()._int;
		if (node->getRunTimeType() != ExpressionType(2)) {
			codeGenerator->writeCodeLine("pop ebx");
			codeGenerator->writeCodeLine("pop eax");
			string endLabel = LabelManager::createLabel();
			string shiftLabel2 = LabelManager::createLabel();
			string shiftLabel = LabelManager::createLabel();
			switch (Operationkind) {
			case PLUS:
				codeGenerator->writeCodeLine("add eax, ebx");
				break;
			case MINUS:
				codeGenerator->writeCodeLine("sub eax, ebx");
				break;
			case MUL:
				codeGenerator->writeCodeLine("xor edx, edx");
				codeGenerator->writeCodeLine("cmp ebx, 2");
				codeGenerator->writeCodeLine("je " + shiftLabel);
				codeGenerator->writeCodeLine("cmp eax, 2");
				codeGenerator->writeCodeLine("je" + shiftLabel2);
				codeGenerator->writeCodeLine("imul ebx");
				codeGenerator->writeCodeLine("jmp " + endLabel);
				codeGenerator->writeCodeLine(shiftLabel + ":");
				codeGenerator->writeCodeLine("sal eax, 1");
				codeGenerator->writeCodeLine("jmp " + endLabel);
				codeGenerator->writeCodeLine(shiftLabel2 + ":");
				codeGenerator->writeCodeLine("sal ebx, 1");
				codeGenerator->writeCodeLine(endLabel + ":");
				break;
			case DIV:
				codeGenerator->writeCodeLine("xor edx, edx");
				codeGenerator->writeCodeLine("cmp ebx, 2");
				codeGenerator->writeCodeLine("je " + shiftLabel);
				codeGenerator->writeCodeLine("idiv ebx");
				codeGenerator->writeCodeLine("jmp " + endLabel);
				codeGenerator->writeCodeLine(shiftLabel + ":");
				codeGenerator->writeCodeLine("sar eax, 1");
				codeGenerator->writeCodeLine(endLabel + ":");
				break;
			case MOD:
				codeGenerator->writeCodeLine("xor edx, edx");
				codeGenerator->writeCodeLine("idiv ebx");
				codeGenerator->writeCodeLine("mov eax,edx");
				break;
			case LT:
				codeGenerator->writeCodeLine("cmp eax, ebx");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("setl al");
				break;
			case LE:
				codeGenerator->writeCodeLine("cmp eax, ebx");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("setng al");
				break;
			case GT:
				codeGenerator->writeCodeLine("cmp eax, ebx");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("setg al");
				break;
			case GE:
				codeGenerator->writeCodeLine("cmp eax, ebx");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("setnl eax");
				break;
			case EQUAL:
				codeGenerator->writeCodeLine("cmp eax, ebx");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("sete al");
				break;
			case UNEQUAL:
				codeGenerator->writeCodeLine("cmp eax, ebx");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("setne al");
				break;
			}
		}
		else {
			if (Operationkind == OperationKind::PLUS || Operationkind == OperationKind::MINUS || Operationkind == OperationKind::MUL || Operationkind == OperationKind::DIV) {
				codeGenerator->writeCodeLine("fld dword ptr [esp+4]");
				codeGenerator->writeCodeLine("fld dword ptr [esp]");
			}
			else {
				codeGenerator->writeCodeLine("fld dword ptr [esp]");
				codeGenerator->writeCodeLine("fld dword ptr [esp+4]");
			}
			codeGenerator->writeCodeLine("pop eax");
			codeGenerator->writeCodeLine("pop eax");
			switch (Operationkind){
			case PLUS:
				codeGenerator->writeCodeLine("fadd");
				break;
			case MINUS:
				codeGenerator->writeCodeLine("fsub");
				break;
			case MUL:
				codeGenerator->writeCodeLine("fmul");
				break;
			case DIV:
				codeGenerator->writeCodeLine("fdiv");
				break;
			case LT:
				codeGenerator->writeCodeLine("fcomi st(0), st(1)");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("setb al");
				break;
			case LE:
				codeGenerator->writeCodeLine("fcomi st(0), st(1)");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("setna al");
				break;
			case GT:
				codeGenerator->writeCodeLine("fcomi st(0), st(1)");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("seta al");
				break;
			case GE:
				codeGenerator->writeCodeLine("fcomi st(0), st(1)");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("setnb eax");
				break;
			case EQUAL:
				codeGenerator->writeCodeLine("fcomi st(0), st(1)");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("sete al");
				break;
			case UNEQUAL:
				codeGenerator->writeCodeLine("fcomi st(0), st(1)");
				codeGenerator->writeCodeLine("mov eax, 0");
				codeGenerator->writeCodeLine("setne al");
				break;
			}
			if (Operationkind == OperationKind::PLUS || Operationkind == OperationKind::MINUS || Operationkind == OperationKind::MUL || Operationkind == OperationKind::DIV) {
				codeGenerator->writeCodeLine("sub esp,4");
				codeGenerator->writeCodeLine("fstp dword ptr [esp]");
				codeGenerator->writeCodeLine("pop eax");
			}
		}
	}
};

class FuncDeclGenerator : public Generator{
public:
	FuncDeclGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	FuncDeclGenerator(){}

	void generateCode(TreeNode node){
		TreeNode child1 = node->getChildren()[0];
		TreeNode child2 = node->getChildren()[1];
		SymbolTable::addProcOrFunc(child1);

		child2->setAttribute(child1->getAttribute()._double);
		child2->setAttribute(child1->getAttribute()._string);
		child2->setAttribute(child1->getAttribute()._int);

		codeGenerator->generateCode(child2);

		int sizeParam = SymbolTable::leaveScope();
		stringstream ss;
		string str;
		ss << sizeParam;
		ss >> str;
		codeGenerator->writeCodeLine("add esp, " + str);
		codeGenerator->writeCodeLine("ret");
	}
};

class ProcDeclGenerator : public Generator{
public:
	ProcDeclGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	ProcDeclGenerator(){}

	void generateCode(TreeNode node){
		TreeNode child1 = node->getChildren()[0];
		TreeNode child2 = node->getChildren()[1];
		SymbolTable::addProcOrFunc(child1);

		child2->setAttribute(child1->getAttribute()._double);
		child2->setAttribute(child1->getAttribute()._string);
		child2->setAttribute(child1->getAttribute()._int);

		codeGenerator->generateCode(child2);

		int sizeParam = SymbolTable::leaveScope();
		stringstream ss;
		string str;
		ss << sizeParam;
		ss >> str;
		codeGenerator->writeCodeLine("add esp, " + str);
		codeGenerator->writeCodeLine("ret");
	}
};

class RoutineHeadGenerator : public Generator{
public:

	RoutineHeadGenerator(CodeGenerator *codeGenerator) : Generator(codeGenerator){

	}

	RoutineHeadGenerator(){

	}


	void generateCode(TreeNode node) {
		int sizeParam = SymbolTable::enterNewScope(node);

		if (node->getChildren()[3] != NULL)
			codeGenerator->generateCode(node->getChildren()[3]);

		if (node->getAttribute()._string.compare("main") != 0){
			codeGenerator->writeCodeLine(node->getAttribute()._string + ":");
		}
		else {
			codeGenerator->writeCodeLine("main PROC");
			codeGenerator->writeCodeLine("mov ecx, esp");
		}
		stringstream ss;
		string str;
		ss << sizeParam;
		ss >> str;
		codeGenerator->writeCodeLine("sub esp, " + str);
	}
};

class StmtAssignGenerator : public Generator{
public:
	StmtAssignGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtAssignGenerator(){}

	void generateCode(TreeNode node) {
		codeGenerator->generateCode(node->getChildren()[1]);
		codeGenerator->writeCodeLine("push eax");

		stringstream ss;
		string str;
		ss << node->getChildren()[0]->getAttribute()._string;
		ss >> str;

		VariableDefinition varInfo = SymbolTable::lookupVar(node->getChildren()[0]->getAttribute()._string);
		if (varInfo.name == "null") {
			codeGenerator->error(node->getLineNumber(), "Undefined variable: " + node->getChildren()[0]->getAttribute()._string);
		}
		if (varInfo.isConst){
			codeGenerator->error(node->getLineNumber(), "Attempt to assign a const variable.");
		}
		codeGenerator->generateCode(node->getChildren()[0]);
		codeGenerator->writeCodeLine("pop eax");
		codeGenerator->writeCodeLine("mov [esi-0], eax");
		node->getChildren()[0]->setRunTimeType(node->getChildren()[1]->getRunTimeType());
	}
};

class StmtCaseGenerator : public Generator{
public:
	StmtCaseGenerator(CodeGenerator *codeGenerator) : Generator(codeGenerator){}

	StmtCaseGenerator(){}

	void generateCode(TreeNode node) {
		codeGenerator->generateCode(node->getChildren()[0]);
		codeGenerator->writeCodeLine("push eax");
		codeGenerator->generateCode(node->getChildren()[1]);
	}
};

class StmtForGenerator : public Generator{
public:
	StmtForGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtForGenerator(){}

	void generateCode(TreeNode node) {
		OperationKind Operationkind = (OperationKind)node->getAttribute()._int;

		if (OptimizationUtils::compareForCond(node->getChildren()[1], node->getChildren()[2], node))
			return;

		string startLabel = LabelManager::createLabel();
		string endLabel = LabelManager::createLabel();

		codeGenerator->generateCode(node->getChildren()[1]);  // 计算初值
		codeGenerator->writeCodeLine("push eax");
		codeGenerator->generateCode(node->getChildren()[0]);  // 计算循环变量
		codeGenerator->writeCodeLine("pop eax");
		codeGenerator->writeCodeLine("mov [esi-0], eax");        // 给循环变量赋初值
		codeGenerator->generateCode(node->getChildren()[2]);  // 计算终值
		codeGenerator->writeCodeLine("push eax");

		codeGenerator->writeCodeLine(startLabel + ":");
		codeGenerator->generateCode(node->getChildren()[0]);  // 获取循环变量
		codeGenerator->writeCodeLine("pop ebx");
		codeGenerator->writeCodeLine("cmp eax, ebx");
		if (Operationkind == OperationKind::TO) {
			codeGenerator->writeCodeLine("ja " + endLabel);
		}
		else if (Operationkind == OperationKind::DOWNTO) {
			codeGenerator->writeCodeLine("jb " + endLabel);
		}
		else {
			codeGenerator->error(node->getLineNumber(), "This is not a valid for statement: OperationKind");
		}

		codeGenerator->generateCode(node->getChildren()[3]);  // 循环体

		// 循环变量+1或-1
		codeGenerator->generateCode(node->getChildren()[0]);
		if (Operationkind == OperationKind::TO) {
			codeGenerator->writeCodeLine("inc eax");
		}
		else {
			codeGenerator->writeCodeLine("dec eax");
		}
		codeGenerator->writeCodeLine("mov [esi-0], eax");        // 将+1/-1之后的值赋值回给循环变量
		codeGenerator->writeCodeLine("jmp " + startLabel);
		codeGenerator->writeCodeLine(endLabel + ":");
	}
};

class StmtGotoGenerator : public Generator{
public:
	StmtGotoGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtGotoGenerator(){}

	void generateCode(TreeNode node){
		int value = node->getAttribute()._int;
		string label = LabelManager::buildCodeLabel(value);
		codeGenerator->writeCodeLine("jmp " + label);
	}
};

class StmtIfGenerator : public Generator{
public:
	StmtIfGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtIfGenerator(){}

	void generateCode(TreeNode node) {
		TreeNode cond = node->getChildren()[0];
		int alwaysTrue = OptimizationUtils::alwaysTrue(cond);

		string elseLabel = LabelManager::createLabel();
		string exitLabel = "";
		if (node->getChildren()[2] != NULL)
			exitLabel = LabelManager::createLabel();

		if (alwaysTrue == OptimizationUtils::CANNOT_DETERMINE) {
			codeGenerator->generateCode(cond);
			codeGenerator->writeCodeLine("cmp eax, 0");
			codeGenerator->writeCodeLine("je " + elseLabel);
		}
		else if (alwaysTrue == OptimizationUtils::ALWAYS_TRUE) {
			//恒为真则直接继续执行
		}
		else if (alwaysTrue == OptimizationUtils::ALWAYS_FALSE) {
			//恒为假则直接跳转到else段
			if (node->getChildren()[2] != NULL)
				codeGenerator->writeCodeLine("jmp " + elseLabel);
		}
		codeGenerator->generateCode(node->getChildren()[1]);
		if (node->getChildren()[2] != NULL) {
			codeGenerator->writeCodeLine("jmp " + exitLabel);
			codeGenerator->writeCodeLine(elseLabel + ":");
			codeGenerator->generateCode(node->getChildren()[2]);
			codeGenerator->writeCodeLine(exitLabel + ":");
		}
	}
};

class StmtInputGenerator : public Generator{
public:
	StmtInputGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtInputGenerator(){}

	void generateCode(TreeNode node) {
		TreeNode child = node->getChildren()[0];
		while (child != NULL) {
			codeGenerator->generateCode(child, false);

			codeGenerator->writeCodeLine("pusha");
			if (child->getRunTimeType() == ExpressionType::INT) {
				codeGenerator->writeCodeLine("invoke crt_scanf, addr lb_read_int, addr lb_tmp");
			}
			else if (child->getRunTimeType() == ExpressionType::REAL) {
				codeGenerator->writeCodeLine("invoke crt_scanf, addr lb_read_real, addr lb_tmp");
			}
			codeGenerator->writeCodeLine("popa");

			codeGenerator->writeCodeLine("mov eax, dword ptr lb_tmp");
			codeGenerator->writeCodeLine("mov [esi], eax");
			child = child->getSibling();
		}
	}
};

class StmtLabelGenerator : public Generator{
public:
	StmtLabelGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtLabelGenerator(){}

	void generateCode(TreeNode node) {
		int value = node->getAttribute()._int;
		string label = LabelManager::buildCodeLabel(value);
		codeGenerator->writeCodeLine(label + ":");
		codeGenerator->generateCode(node->getChildren()[0]);
	}
};

class StmtOutputGenerator : public Generator{
public:
	StmtOutputGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtOutputGenerator(){}

	void generateCode(TreeNode node) {
		TreeNode child = node->getChildren()[0];
		while (child != NULL) {
			codeGenerator->generateCode(child, false);
			codeGenerator->writeCodeLine("pusha");
			//不同类型使用定义好的格式调用C函数输出
			if (child->getRunTimeType() == ExpressionType::REAL) {
				codeGenerator->writeCodeLine("push eax");
				codeGenerator->writeCodeLine("fld dword ptr [esp]");
				codeGenerator->writeCodeLine("sub esp, 4");
				codeGenerator->writeCodeLine("fstp qword ptr [esp]");
				if (node->getAttribute()._int == OperationKind::WRITELN) {
					codeGenerator->writeCodeLine("push offset lb_writeln_real");
				}
				else {
					codeGenerator->writeCodeLine("push offset lb_write_real");
				}
				codeGenerator->writeCodeLine("call printf");
				codeGenerator->writeCodeLine("add esp, 8");
				codeGenerator->writeCodeLine("pop eax");
			}
			else if (child->getRunTimeType() == ExpressionType::INT) {
				if (node->getAttribute()._int == OperationKind::WRITELN) {
					codeGenerator->writeCodeLine("invoke printf,offset lb_writeln_int, eax");
				}
				else {
					codeGenerator->writeCodeLine("invoke printf,offset lb_write_int, eax");
				}
			}
			else {
				stringstream ss;
				string str;
				ss << child->getRunTimeType();
				ss >> str;
				codeGenerator->error(node->getLineNumber(), "Unknown type: " + str);
			}

			codeGenerator->writeCodeLine("popa");
			child = child->getSibling();
		}
	}
};

class StmtProcIdGenerator : public StmtFuncAndProcGenerator{
public:
	StmtProcIdGenerator(CodeGenerator* codeGenerator) : StmtFuncAndProcGenerator(codeGenerator){}

	StmtProcIdGenerator(){}

	void generateCode(TreeNode node) {
		stringstream ss;
		string str;
		ss << node->getAttribute()._int;
		ss >> str;
		ProcedureDefinition PosalVar = SymbolTable::lookupProc(node->getAttribute()._string);

		//参数列表
		codeGeneratorPushParam(node->getChildren()[0]);
		//访问链
		codeGenerator->writeCodeLine("push ecx");
		codeGenerator->writeCodeLine("mov ecx, esp");
		//调用过程
		codeGenerator->writeCodeLine("call " + str);
		codeGenerator->writeCodeLine("pop ecx");
		if (PosalVar.name != "null")
			codeGeneratorPopParam(node->getChildren()[0], PosalVar.paraList);
	}
};

class StmtProcSysGenerator : public StmtFuncAndProcGenerator{
private:
	static StmtInputGenerator *inputGenerator;
	static StmtOutputGenerator *outputGenerator;

public:

	StmtProcSysGenerator(CodeGenerator *codeGenerator) : StmtFuncAndProcGenerator(codeGenerator){
		if (inputGenerator == NULL) {
			inputGenerator = new StmtInputGenerator(instance);
		}
		if (outputGenerator == NULL) {
			outputGenerator = new StmtOutputGenerator(instance);
		}
	}

	void generateCode(TreeNode node) {
		if (node->getAttribute()._int == OperationKind::READ) {
			inputGenerator->generateCode(node);
		}
		else {
			outputGenerator->generateCode(node);
		}
	}

};

StmtInputGenerator* StmtProcSysGenerator::inputGenerator = NULL;
StmtOutputGenerator* StmtProcSysGenerator::outputGenerator = NULL;


class StmtRepeatGenerator : public Generator{
public:
	StmtRepeatGenerator(CodeGenerator *codeGenerator) : Generator(codeGenerator){}

	StmtRepeatGenerator(){}

	void generateCode(TreeNode node) {
		TreeNode cond = node->getChildren()[1];
		int alwaysTrue = OptimizationUtils::alwaysTrue(cond);

		if (alwaysTrue != OptimizationUtils::ALWAYS_TRUE) {
			string startLabel = LabelManager::createLabel();
			codeGenerator->writeCodeLine(startLabel + ":");
			codeGenerator->generateCode(node->getChildren()[0]);

			if (alwaysTrue == OptimizationUtils::CANNOT_DETERMINE) {
				codeGenerator->generateCode(cond);
				codeGenerator->writeCodeLine("cmp eax, 0");
				codeGenerator->writeCodeLine("je " + startLabel);
			}
			else {
				//若until条件恒为假,则无需判断直接跳转
				codeGenerator->writeCodeLine("jmp" + startLabel);
			}
		}
		else {
			//若until中条件恒为真,则相当于只执行repeat-until过程体一次
			codeGenerator->generateCode(node->getChildren()[0]);
		}
	}
};

class StmtWhileGenerator : public Generator{
public:
	StmtWhileGenerator(CodeGenerator *codeGenerator) : Generator(codeGenerator){}

	StmtWhileGenerator(){}

	void generateCode(TreeNode node) {
		TreeNode cond = node->getChildren()[0];
		int alwaysTrue = OptimizationUtils::alwaysTrue(cond);

		//条件恒为假无需输出该语句
		if (alwaysTrue == OptimizationUtils::ALWAYS_FALSE)
			return;

		string startLabel = LabelManager::createLabel();
		string endLabel = LabelManager::createLabel();

		codeGenerator->writeCodeLine(startLabel + ":");

		if (alwaysTrue == OptimizationUtils::CANNOT_DETERMINE) {
			codeGenerator->generateCode(cond);
			codeGenerator->writeCodeLine("cmp eax, 0");
			codeGenerator->writeCodeLine("je " + endLabel);
		}
		else {
			//while条件恒为真则开始不需要判断跳出
		}

		codeGenerator->generateCode(node->getChildren()[1]);
		codeGenerator->writeCodeLine("jmp " + startLabel);
		codeGenerator->writeCodeLine(endLabel + ":");
	}
};

extern StmtAssignGenerator* stmtAssignGenerator;
extern StmtIfGenerator* stmtIfGenerator;
extern StmtForGenerator* stmtForGenerator;
extern StmtWhileGenerator* stmtWhileGenerator;
extern StmtRepeatGenerator* stmtRepeatGenerator;
extern StmtCaseGenerator* stmtCaseGenerator;
extern StmtGotoGenerator* stmtGotoGenerator;
extern StmtLabelGenerator* stmtLabelGenerator;
extern StmtProcIdGenerator* stmtProcIdGenerator;
extern StmtProcSysGenerator* stmtProcSysGenerator;
extern StmtFuncAndProcGenerator* stmtFuncAndProcGenerator;
extern ExpIdGenerator* expIdGenerator;
extern ExpOpGenerator* expOpGenerator;
extern ExpConstGenerator* expConstGenerator;
extern ExpCaseGenerator* expCaseGenerator;
extern ExpFuncIdGenerator* expFuncIdGenerator;
extern FuncDeclGenerator* funcDeclGenerator;
extern ProcDeclGenerator* procDeclGenerator;
extern RoutineHeadGenerator* routineHeadGenerator;

void CodeGenerator::generateCode(TreeNode node, bool travelSibling){
	int codeGen = node->getNodeType();
	switch (codeGen){
	case StatementKind::ASSIGN:{
		stmtAssignGenerator->generateCode(node);
		break;
	}
	case StatementKind::IF:{
		stmtIfGenerator->generateCode(node);
		break;
	}
	case StatementKind::FOR:{
		stmtForGenerator->generateCode(node);
		break;
	}
	case StatementKind::WHILE:{
		stmtWhileGenerator->generateCode(node);
		break;
	}
	case StatementKind::REPEAT:{
		stmtRepeatGenerator->generateCode(node);
		break;
	}
	case StatementKind::SK_CASE:{
		stmtCaseGenerator->generateCode(node);
		break;
	}
	case StatementKind::GOTO:{
		stmtGotoGenerator->generateCode(node);
		break;
	}
	case StatementKind::LABEL:{
		stmtLabelGenerator->generateCode(node);
		break;
	}
	case StatementKind::PROC_ID:{
		stmtProcIdGenerator->generateCode(node);
		break;
	}
	case StatementKind::PROC_SYS:{
		stmtProcSysGenerator->generateCode(node);
		break;
	}
	case ExpressionKind::EK_ID:{
		expIdGenerator->generateCode(node);
		break;
	}
	case ExpressionKind::OP:{
		expOpGenerator->generateCode(node);
		break;
	}
	case ExpressionKind::EK_CONST:{
		expConstGenerator->generateCode(node);
		break;
	}
	case ExpressionKind::EK_CASE:{
		expCaseGenerator->generateCode(node);
		break;
	}
	case ExpressionKind::FUNC_ID:{
		expFuncIdGenerator->generateCode(node);
		break;
	}
	case DeclarationKind::ROUTINEHEAD:{
		routineHeadGenerator->generateCode(node);
		break;
	}
	case DeclarationKind::FUNCTION:{
		funcDeclGenerator->generateCode(node);
		break;
	}
	case DeclarationKind::PROCEDURE:{
		procDeclGenerator->generateCode(node);
		break;
	}
	};

	if (travelSibling){
		if (node->getSibling() != NULL){
			generateCode(node->getSibling(), true);
		}
	}
}

#endif
