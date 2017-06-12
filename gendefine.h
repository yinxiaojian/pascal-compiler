/*************************************************************************
	> File Name: gendefine.h
	> Author: yinxiaojian
	> Mail: jianwen_yin@163.com
	> Created Time: Sun 11 Jun 2017 02:31:17 AM PDT
 ************************************************************************/

#ifndef _GENDEFINE_H
#define _GENDEFINE_H
#include "codegen.h"
class Generator{
public:
	CodeGenerator *codeGenerator;

	Generator(){}

	Generator(CodeGenerator *codeGenerator):codeGenerator(codeGenerator){}

	virtual void generateCode(TreeNode node){};
};

class LabelManager{
private:
	static int countLabel;
	static int countRealData;
	static const string labelHeader;
	static const string codeLabelHeader;
	static const string realDataLabelHeader;
	static unordered_map<double, string> realConstPool;

public:

	static string createLabel(){return labelHeader+to_string(countLabel++);}

	static string getLabel(int number){return labelHeader+to_string(number);}

	static string buildCodeLabel(int number){return buildCodeLabel(to_string(number));}
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
	static string createDataLabel(double realData, CodeGenerator *codeGenerator){
		string label = realDataLabelHeader + to_string(countRealData++);
		codeGenerator->writeDataLine(label + " dd " + to_string(realData));
		return label;
	}
};

int LabelManager::countLabel = 0;
int LabelManager::countRealData = 0;
const string LabelManager::labelHeader = "_LABEL_";
const string LabelManager::codeLabelHeader = "_CODE_LABEL_";
const string LabelManager::realDataLabelHeader = "_REAL_DATA_";
unordered_map<double, string> LabelManager::realConstPool;

class OptimizationUtils{
public:
	static const int ALWAYS_TRUE = 0;
	static const int ALWAYS_FALSE = 1;
	static const int CANNOT_DETERMINE = 2;
	static int alwaysTrue(TreeNode cond) {
		int ret = CANNOT_DETERMINE;
		if (!(cond->getExpType() == 0))
			return ret;
		if (cond->getExpType() == BOOL) {
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
		if ((cond1->getNodeType() < 11) || (cond1->getNodeType() > 16))
			return false;
		if ((cond2->getNodeType() < 11) || (cond2->getNodeType() > 16))
			return false;
		if (cond1->getNodeType() != EK_CONST || cond2->getNodeType() != EK_CONST)
			return false;
		if (cond1->getExpType() != INT && cond1->getExpType() != CHAR)
			return false;
		if (cond2->getExpType() != INT && cond2->getExpType() != CHAR)
			return false;
		int startVal, endVal;
		startVal = cond1->getAttribute()._int;
		endVal = cond2->getAttribute()._int;
		OperationKind Operationkind = (OperationKind)(op->getAttribute()._int);
		if (Operationkind == TO && startVal > endVal)
			return true;
		if (Operationkind == DOWNTO && startVal < endVal)
			return true;
		return false;
	}

};

class ExpCaseGenerator : public Generator{
public:
	ExpCaseGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	void generateCode(TreeNode node){
		string nextCaseLabel = LabelManager::createLabel();

		codeGenerator->generateCode(node->getChildren().at(0));
		codeGenerator->writeCodeLine("pop ebx");
		codeGenerator->writeCodeLine("cmp ebx, eax");
		codeGenerator->writeCodeLine("jne " + nextCaseLabel);
		codeGenerator->generateCode(node->getChildren().at(1));
		codeGenerator->writeCodeLine(nextCaseLabel + ":");
		if (node->getSibling() != NULL) {
			codeGenerator->writeCodeLine("push ebx");
		}
	}
};

class ExpConstGenerator : public Generator{
public:
	ExpConstGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	void generateCode(TreeNode node){
		if (node->getExpType() != REAL){
			int value;
			if (node->getExpType() == CHAR){
				value = (char)node->getNodeType();
			}
			else{
				value = node->getAttribute()._int;
			}

			codeGenerator->writeCodeLine("mov eax, " + to_string(value));
			node->setRunTimeType(INT);
		}
		else{
			double value = node->getAttribute()._double;
			string realDataLabel = LabelManager::getDataLabel(value, codeGenerator);
			codeGenerator->writeCodeLine("mov eax, " + realDataLabel);
			node->setRunTimeType(REAL);
		}
	}
};
//TODO
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

class ExpFuncIdGenerator : public StmtFuncAndProcGenerator{
public:
	ExpFuncIdGenerator(CodeGenerator* codeGenerator) : StmtFuncAndProcGenerator(codeGenerator){}

	ExpFuncIdGenerator(){}

	void generateCode(TreeNode node){
		FunctionDefinition PosalVar = SymbolTable::lookupFunc(node->getAttribute()._string);

		codeGenerator->writeCodeLine("push eax");
		codeGeneratorPushParam(node->getChildren().at(0));
		codeGenerator->writeCodeLine("push ecx");
		codeGenerator->writeCodeLine("mov ecx, esp");
		codeGenerator->writeCodeLine("call " + node->getAttribute()._string);
		codeGenerator->writeCodeLine("pop ecx");
		codeGeneratorPopParam(node->getChildren().at(0), PosalVar.paraList);
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

		if (varInfo.name == "undefined"){
			codeGenerator->error(node->getLineNumber(), "Undefined variable: " + node->getAttribute()._string);
		}

		type = varInfo.type;

		if (type == ET_ARRAY){
			if (varInfo.pAttr.flag == 0){
				codeGenerator->error(node->getLineNumber(), "Variable: " + node->getAttribute()._string + " is not an array.");
			}
			ArrayDefinition* temp = varInfo.pAttr.ad;
			lower = (temp->subBound).LowerBound._int;
			level = varInfo.memPos.basePos;
			offset = varInfo.memPos.offset;
		}
		else if (type == ET_RECORD) {
			recordInfo = SymbolTable::lookupRecord(node->getAttribute()._string, node->getChildren().at(0)->getAttribute()._string);
			level = recordInfo.jumpLevel;
			offset = recordInfo.totalOff;
		}
		else {
			level = varInfo.memPos.basePos;
			offset = varInfo.memPos.offset;
		}

		if (type == ET_ARRAY) {
			codeGenerator->generateCode(node->getChildren()[0], false); 	// 计算数组下标的值
			codeGenerator->writeCodeLine("mov ebx, " + to_string(lower));
			codeGenerator->writeCodeLine("sub eax, ebx");
			codeGenerator->writeCodeLine("mov ebx, 4");
			codeGenerator->writeCodeLine("imul eax,ebx");
			codeGenerator->writeCodeLine("mov edi, " + to_string(offset));
			codeGenerator->writeCodeLine("add edi, eax");
		}
		else {
			codeGenerator->writeCodeLine("mov edi, " + to_string(offset));
		}

		if (type == ET_ARRAY) {
			ArrayDefinition* temp = varInfo.pAttr.ad;
			type = temp->arrayType;
		}
		else if (type == ET_RECORD) {
			type = recordInfo.type;
		}

		codeGenerator->writeCodeLine("mov esi, ecx");
		while (level > 0){
			codeGenerator->writeCodeLine("mov eax, [esi]");
			codeGenerator->writeCodeLine("mov esi, eax");
			level--;
		}
		codeGenerator->writeCodeLine("add esi, edi");

		if (type == INT || type == CHAR || type == BOOL){
			codeGenerator->writeCodeLine("mov eax, [esi]; calculate ExpId ");
			node->setRunTimeType(INT);
		}
		else if (REAL){
			codeGenerator->writeCodeLine("mov eax, dword ptr [esi]; calculate ExpId(type: real)");
			node->setRunTimeType(REAL);
		}
		else {
			codeGenerator->error(node->getLineNumber(), "Unknown running type: " + to_string(node->getChildren()[0]->getRunTimeType()));
		}

	}
};

class ExpOpGenerator : public Generator{
public:
	ExpOpGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	ExpOpGenerator(){}

	void generateCode(TreeNode node){
		if (node->getChildren().at(0) != NULL && node->getChildren().at(1) != NULL){
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
		if (node->getRunTimeType() != REAL) {
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
			if (Operationkind == PLUS || Operationkind == MINUS || Operationkind == MUL || Operationkind == DIV) {
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
			if (Operationkind == PLUS || Operationkind == MINUS || Operationkind == MUL || Operationkind == DIV) {
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
		TreeNode child1 = node->getChildren().at(0);
		TreeNode child2 = node->getChildren().at(1);
		SymbolTable::addProcOrFunc(child1);

		child2->setAttribute(child1->getAttribute());
		codeGenerator->generateCode(child2);

		int sizeParam = SymbolTable::leaveScope();
		codeGenerator->writeCodeLine("add esp, " + to_string(sizeParam));
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

		child2->setAttribute(child1->getAttribute());
		codeGenerator->generateCode(child2);

		int sizeParam = SymbolTable::leaveScope();
		codeGenerator->writeCodeLine("add esp, " + to_string(sizeParam));
		codeGenerator->writeCodeLine("ret");
	}
};

class RoutineHeadGenerator : public Generator{
public:

	RoutineHeadGenerator(CodeGenerator *codeGenerator) : Generator(codeGenerator){}

	RoutineHeadGenerator(){}

	void generateCode(TreeNode node) {
		int sizeParam = SymbolTable::enterNewScope(node);

		if (node->getChildren().at(3) != NULL)
			codeGenerator->generateCode(node->getChildren().at(3));

		if (node->getAttribute()._string.compare("main") != 0){
			codeGenerator->writeCodeLine(node->getAttribute()._string + ":");
		}
		else {
			codeGenerator->writeCodeLine("main PROC");
			codeGenerator->writeCodeLine("mov ecx, esp");
		}

		codeGenerator->writeCodeLine("sub esp, " + to_string(sizeParam));
	}
};

class StmtAssignGenerator : public Generator{
public:
	StmtAssignGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtAssignGenerator(){}

	void generateCode(TreeNode node) {
		codeGenerator->generateCode(node->getChildren().at(1));
		codeGenerator->writeCodeLine("push eax");

		VariableDefinition varInfo = SymbolTable::lookupVar(node->getChildren().at(0)->getAttribute()._string);
		if (varInfo.name == "undefined") {
			codeGenerator->error(node->getLineNumber(), "Undefined variable: " + node->getChildren().at(0)->getAttribute()._string);
		}
		if (varInfo.isConst){
			codeGenerator->error(node->getLineNumber(), "Attempt to assign a const variable.");
		}
		codeGenerator->generateCode(node->getChildren().at(0));
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
		codeGenerator->generateCode(node->getChildren().at(0));
		codeGenerator->writeCodeLine("push eax");
		codeGenerator->generateCode(node->getChildren().at(1));
	}
};

class StmtForGenerator : public Generator{
public:
	StmtForGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtForGenerator(){}

	void generateCode(TreeNode node) {
		OperationKind Operationkind = (OperationKind)node->getAttribute()._int;

		if (OptimizationUtils::compareForCond(node->getChildren().at(1), node->getChildren().at(2), node))
			return;

		string startLabel = LabelManager::createLabel();
		string endLabel = LabelManager::createLabel();

		codeGenerator->generateCode(node->getChildren().at(1)); 
		codeGenerator->writeCodeLine("push eax");
		codeGenerator->generateCode(node->getChildren().at(0));
		codeGenerator->writeCodeLine("pop eax");
		codeGenerator->writeCodeLine("mov [esi-0], eax");        // 给循环变量赋初值
		codeGenerator->generateCode(node->getChildren().at(2));  // 计算终值
		codeGenerator->writeCodeLine("push eax");

		codeGenerator->writeCodeLine(startLabel + ":");
		codeGenerator->generateCode(node->getChildren().at(0));  // 获取循环变量
		codeGenerator->writeCodeLine("pop ebx");
		codeGenerator->writeCodeLine("cmp eax, ebx");
		if (Operationkind == TO) {
			codeGenerator->writeCodeLine("ja " + endLabel);
		}
		else if (Operationkind == DOWNTO) {
			codeGenerator->writeCodeLine("jb " + endLabel);
		}
		else {
			codeGenerator->error(node->getLineNumber(), "This is not a valid for statement: OperationKind");
		}

		codeGenerator->generateCode(node->getChildren()[3]);
		codeGenerator->generateCode(node->getChildren()[0]);
		if (Operationkind == OperationKind::TO) {
			codeGenerator->writeCodeLine("inc eax");
		}
		else {
			codeGenerator->writeCodeLine("dec eax");
		}
		codeGenerator->writeCodeLine("mov [esi-0], eax");
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
		TreeNode cond = node->getChildren().at(0);
		int alwaysTrue = OptimizationUtils::alwaysTrue(cond);

		string elseLabel = LabelManager::createLabel();
		string exitLabel = "";
		if (node->getChildren().at(2) != NULL)
			exitLabel = LabelManager::createLabel();

		if (alwaysTrue == OptimizationUtils::CANNOT_DETERMINE) {
			codeGenerator->generateCode(cond);
			codeGenerator->writeCodeLine("cmp eax, 0");
			codeGenerator->writeCodeLine("je " + elseLabel);
		}
		else if (alwaysTrue == OptimizationUtils::ALWAYS_TRUE) {
			//do nothing 
		}
		else if (alwaysTrue == OptimizationUtils::ALWAYS_FALSE) {
			if (node->getChildren().at(2) != NULL)
				codeGenerator->writeCodeLine("jmp " + elseLabel);
		}
		codeGenerator->generateCode(node->getChildren().at(1));
		if (node->getChildren().at(2) != NULL) {
			codeGenerator->writeCodeLine("jmp " + exitLabel);
			codeGenerator->writeCodeLine(elseLabel + ":");
			codeGenerator->generateCode(node->getChildren().at(2));
			codeGenerator->writeCodeLine(exitLabel + ":");
		}
	}
};

class StmtInputGenerator : public Generator{
public:
	StmtInputGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtInputGenerator(){}

	void generateCode(TreeNode node) {
		TreeNode child = node->getChildren().at(0);
		while (child != NULL) {
			codeGenerator->generateCode(child, false);

			codeGenerator->writeCodeLine("pusha");
			if (child->getRunTimeType() == INT) {
				codeGenerator->writeCodeLine("invoke crt_scanf, addr lb_read_int, addr lb_tmp");
			}
			else if (child->getRunTimeType() == REAL) {
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
		codeGenerator->generateCode(node->getChildren().at(0));
	}
};

class StmtOutputGenerator : public Generator{
public:
	StmtOutputGenerator(CodeGenerator* codeGenerator) : Generator(codeGenerator){}

	StmtOutputGenerator(){}

	void generateCode(TreeNode node) {
		TreeNode child = node->getChildren().at(0);
		while (child != NULL) {
			codeGenerator->generateCode(child, false);
			codeGenerator->writeCodeLine("pusha");
			
			if (child->getRunTimeType() == REAL) {
				codeGenerator->writeCodeLine("push eax");
				codeGenerator->writeCodeLine("fld dword ptr [esp]");
				codeGenerator->writeCodeLine("sub esp, 4");
				codeGenerator->writeCodeLine("fstp qword ptr [esp]");
				if (node->getAttribute()._int == WRITELN) {
					codeGenerator->writeCodeLine("push offset lb_writeln_real");
				}
				else {
					codeGenerator->writeCodeLine("push offset lb_write_real");
				}
				codeGenerator->writeCodeLine("call printf");
				codeGenerator->writeCodeLine("add esp, 8");
				codeGenerator->writeCodeLine("pop eax");
			}
			else if (child->getRunTimeType() == INT) {
				if (node->getAttribute()._int == WRITELN) {
					codeGenerator->writeCodeLine("invoke printf,offset lb_writeln_int, eax");
				}
				else {
					codeGenerator->writeCodeLine("invoke printf,offset lb_write_int, eax");
				}
			}
			else {
				codeGenerator->error(node->getLineNumber(), "Unknown type: " + to_string(child->getRunTimeType()));
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
		ProcedureDefinition PosalVar = SymbolTable::lookupProc(node->getAttribute()._string);

		codeGeneratorPushParam(node->getChildren().at(0));
		codeGenerator->writeCodeLine("push ecx");
		codeGenerator->writeCodeLine("mov ecx, esp");

		codeGenerator->writeCodeLine("call " + to_string(node->getAttribute()._int));
		codeGenerator->writeCodeLine("pop ecx");
		if (PosalVar.name != "undefined")
			codeGeneratorPopParam(node->getChildren().at(0), PosalVar.paraList);
	}
};

class StmtProcSysGenerator : public Generator{
private:
	static StmtInputGenerator *inputGenerator;
	static StmtOutputGenerator *outputGenerator;

public:

	StmtProcSysGenerator(CodeGenerator *codeGenerator) : Generator(codeGenerator){
		if (inputGenerator == NULL) {
			inputGenerator = new StmtInputGenerator(codeGenerator);
		}
		if (outputGenerator == NULL) {
			outputGenerator = new StmtOutputGenerator(codeGenerator);
		}
	}

	void generateCode(TreeNode node) {
		if(node->getAttribute()._int<27 && node->getAttribute()._int>56)
			codeGenerator->error(node->getLineNumber(), "This is not a valid System call statement");
		if (node->getAttribute()._int == READ) {
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
		TreeNode cond = node->getChildren().at(1);
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
				codeGenerator->writeCodeLine("jmp" + startLabel);
			}
		}
		else {
			codeGenerator->generateCode(node->getChildren().at(0));
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
			//break
		}

		codeGenerator->generateCode(node->getChildren().at(1));
		codeGenerator->writeCodeLine("jmp " + startLabel);
		codeGenerator->writeCodeLine(endLabel + ":");
	}
};
#endif
