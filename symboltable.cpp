/*************************************************************************
	> File Name: symboltable.cpp
	> Author: yinxiaojian 
	> Mail: jianwe_yin@163.com
	> Created Time: Sat 10 Jun 2017 01:45:17 AM PDT
 ************************************************************************/
#include "symboltable.h"
using namespace std;

int SymbolTable::currentNestLevel = 0;//global scope
int SymbolTable::offset = 0;
int SymbolTable::totalOffset[MAXSIZE];

unordered_map<string, list<VariableDefinition>> SymbolTable::VariableDefinitionHashMap;
unordered_map<string, list<TypeDefinition>> SymbolTable::TypeDefinitionHashMap;
unordered_map<string, list<FunctionDefinition>> SymbolTable::FunctionDefinitionHashMap;
unordered_map<string, list<ProcedureDefinition>> SymbolTable::ProcedureDefinitionHashMap;

vector<SubBoundDefinition> SymbolTable::sdvector;
vector<ArrayDefinition> SymbolTable::advector;
vector<RecordDefinition> SymbolTable::rdvector;

int SymbolTable::addProcOrFunc(TreeNode headNode)
{
	//function_head : T_FUNCTION T_ID parameters  T_COLON simple_type_decl
	bool isFunc = (headNode->getNodeType() == FUNCTIONHEAD);
	string name = headNode->getAttribute()._string;
	int nestLevel = currentNestLevel;
	int paraNestLevel = nestLevel + 1;//paramenter belong to function 
	int offset = 4;

	list<SimpleType> paraList;
	TreeNode paraDecListNode = headNode->getChildren()[0];
	//function t([var] a,b:integer; [var]c,d:integer):integer
	while (paraDecListNode != NULL)
	{
		TreeNode nameListNode = paraDecListNode->getChildren()[0];
		TreeNode typeNode = paraDecListNode->getChildren()[1];
		bool isVar;
		if (paraDecListNode->getNodeType() == VAR_PARA)
			isVar = true;
		else
			isVar = false;

		while (nameListNode != NULL)
		{
			SimpleType para = SimpleType(nameListNode->getAttribute()._string, typeNode->getExpType(), isVar);
			paraList.push_back(para);
			Object n; n.flag = 0;//null
			insertVariable(VariableDefinition(para.name, para.type, false, paraNestLevel, n, offset), headNode->getLineNumber());
			offset += OFFSET_INC;
			nameListNode = nameListNode->getSibling();
		}
		paraDecListNode = paraDecListNode->getSibling();
	}

	if (isFunc)
	{
		ExpressionType retType = (headNode->getChildren()).at(1)->getExpType();
		struct Object n; n.flag = 0;
		//return value insert
		insertVariable(VariableDefinition(headNode->getAttribute()._string, retType, false, paraNestLevel, n, offset), headNode->getLineNumber());
		offset += OFFSET_INC;

		unordered_map<string,list<FunctionDefinition>>::iterator iter;
		iter = FunctionDefinitionHashMap.find(name);
		if (iter == FunctionDefinitionHashMap.end())
		{
			FunctionDefinitionHashMap.insert(make_pair(name, list<FunctionDefinition>()));
			iter = FunctionDefinitionHashMap.find(name);
		}
		iter->second.push_front(FunctionDefinition(name, paraList, retType, nestLevel));
	}
	else
	{
		unordered_map<string,list<ProcedureDefinition>>::iterator iter;
		iter = ProcedureDefinitionHashMap.find(name);
		if (iter == ProcedureDefinitionHashMap.end())
		{
			ProcedureDefinitionHashMap.insert(make_pair(name, list<ProcedureDefinition>()));
			iter = ProcedureDefinitionHashMap.find(name);
		}
		iter->second.push_front(ProcedureDefinition(name, paraList, nestLevel));
	}

	return offset;
}

void SymbolTable::insertVariable(VariableDefinition variableDefinition, int lineNumber)
{
	string name = variableDefinition.name;
	unordered_map<string,list<VariableDefinition>>::iterator iter;
	iter = VariableDefinitionHashMap.find(name);
	if (iter == VariableDefinitionHashMap.end())
	{
		VariableDefinitionHashMap.insert(make_pair(name, list<VariableDefinition>()));
		iter = VariableDefinitionHashMap.find(name);
	}
	
	int nestLevel = variableDefinition.nestLevel;
	//not define or big scope can insert 	
	if (iter->second.size() == 0 || nestLevel > iter->second.front().nestLevel)
		iter->second.push_front(variableDefinition);
	else
		cout << "Redefine variable: " << name << " in line " << lineNumber << endl;
}

void SymbolTable::insertType(TypeDefinition typeDefinition, int lineNumber)
{
	string name = typeDefinition.name;
	unordered_map<string,list<TypeDefinition>>::iterator iter;
	iter = TypeDefinitionHashMap.find(name);
	if (iter == TypeDefinitionHashMap.end())
	{
		TypeDefinitionHashMap.insert(make_pair(name, list<TypeDefinition>()));
		iter = TypeDefinitionHashMap.find(name);
	}
	
	int nestLevel = typeDefinition.nestLevel;
	//not define or big scope can insert 	
	if (iter->second.size() == 0 || nestLevel > iter->second.front().nestLevel)
		iter->second.push_front(typeDefinition);
	else
		cout << "Redefine type: " << name << " in line " << lineNumber << endl;
}

VariableDefinition SymbolTable::lookupVar(string name)
{
	unordered_map<string,list<VariableDefinition>>::iterator iter;
	iter = VariableDefinitionHashMap.find(name);
	if (iter == VariableDefinitionHashMap.end())
		return VariableDefinition();
	else
	{
		VariableDefinition ret = iter->second.front();
		ret.memPos.basePos = currentNestLevel - ret.nestLevel;
		return ret;
	}
}

TypeDefinition SymbolTable::lookupType(string name)
{
	unordered_map<string,list<TypeDefinition>>::iterator iter;
	iter = TypeDefinitionHashMap.find(name);
	if (iter == TypeDefinitionHashMap.end())
		return TypeDefinition();
	else
		return iter->second.front();
}

ProcedureDefinition SymbolTable::lookupProc(string name)
{
	unordered_map<string,list<ProcedureDefinition>>::iterator iter;
	iter = ProcedureDefinitionHashMap.find(name);
	if (iter == ProcedureDefinitionHashMap.end())
		return ProcedureDefinition();
	else
		return iter->second.front();
}

FunctionDefinition SymbolTable::lookupFunc(string name)
{
	unordered_map<string,list<FunctionDefinition>>::iterator iter;
	iter = FunctionDefinitionHashMap.find(name);
	if (iter == FunctionDefinitionHashMap.end())
		return FunctionDefinition();
	else
		return iter->second.front();
}

LookupReturn SymbolTable::lookupRecord(string rec, string a)
{
	VariableDefinition l = lookupVar(rec);
	list<TypeDefinition> members;
	LookupReturn ret = LookupReturn(ERROR_RETURN, ERROR_RETURN, VOID);

	//NULL 
	if (l.type != ET_RECORD || l.pAttr.flag == 0)
		return ret;

	members = (l.pAttr.rd)->ptr;
	int size = -1;
	list<TypeDefinition>::iterator it;
	for (it = members.begin(); it != members.end(); it++)
	{
		size++;
		if (it->name == a)
			break;
	}
	if (size >= 0)
	{
		ret.totalOff = size * OFFSET_INC + l.memPos.offset;
		ret.jumpLevel = currentNestLevel - l.nestLevel;
		ret.type = it->type;
	}
	return ret;
}

void SymbolTable::initScope()
{
	currentNestLevel = -1;
	VariableDefinitionHashMap.clear();
	TypeDefinitionHashMap.clear();
	FunctionDefinitionHashMap.clear();
	ProcedureDefinitionHashMap.clear();
}

int SymbolTable::enterNewScope(TreeNode t)
{
	currentNestLevel += 1;
	totalOffset[currentNestLevel] = updateSymbolTable(t);
	return totalOffset[currentNestLevel];
}

int SymbolTable::leaveScope()
{
	int retValue = totalOffset[currentNestLevel];
	currentNestLevel--;
	for(unordered_map<string,list<VariableDefinition>>::iterator iter = VariableDefinitionHashMap.begin(); 
     iter != VariableDefinitionHashMap.end();)
	{
        while(iter->second.size()!=0 && iter->second.front().nestLevel > currentNestLevel )
			iter->second.pop_front();
        if(iter->second.size() == 0)
			VariableDefinitionHashMap.erase(iter++);
		else
			iter++;
    }
	for(unordered_map<string,list<TypeDefinition>>::iterator iter = TypeDefinitionHashMap.begin(); 
     iter != TypeDefinitionHashMap.end();)
	{
        while(iter->second.size()!=0 && iter->second.front().nestLevel > currentNestLevel )
			iter->second.pop_front();
        if(iter->second.size() == 0)
			TypeDefinitionHashMap.erase(iter++);
		else
			iter++;
    }
	return retValue;
}

int SymbolTable::updateSymbolTable(TreeNode syntaxTree)
{
	offset = -4;
	if (syntaxTree != NULL && syntaxTree->getChildren().size() >= 4)
	{
		for (int i = 0; i < 4; i++)
		{
			insertNode(syntaxTree->getChildren().at(i));
		}
	}
	return -offset;
}

void SymbolTable::insertNode(TreeNode t) {
    if (t == NULL)
        return;
    if (!(t->getNodeType() >= ROUTINEHEAD && t->getNodeType() <= VAL_PARA))
    {
        return;
    }
    int lineNumber = t->getLineNumber();
    switch (t->getNodeType()) 
    {
        case DK_CONST: 
        {
            while (t != NULL) 
            {
                offset -= OFFSET_INC;
				struct Object null; null.flag = 0;
                insertVariable(VariableDefinition(t->getAttribute()._string, t->getExpType(), true, currentNestLevel, null, offset), lineNumber);
                t = t->getSibling();
            }
            break;
        }
        case VAR: {
            while (t != NULL) {
                TreeNode pname = t->getChildren().at(0);
                TreeNode ptype = t->getChildren().at(1);
                while (pname != NULL)
                {
                    switch (ptype->getNodeType()) {
                        case SIMPLE_ID: {
                            TypeDefinition l = lookupType(ptype->getAttribute()._string);
                            switch (l.type) {
                                case TK_ARRAY:
                                case TK_RECORD: {
                                    offset -= l.size;
                                    break;
                                }
                                default: {
                                    offset -= OFFSET_INC;
                                    break;
                                }
                            }
                            insertVariable(VariableDefinition(pname->getAttribute()._string, l.type, false, currentNestLevel, l.pAttr, offset), lineNumber);
                            break;
                            }
                            case TK_SIMPLE_ENUM: {
                                list<Object>eptr;
                                while (ptype != NULL) {
                                    eptr.push_back(ptype->getAttribute());
                                    ptype = ptype->getSibling();
                                }
                                offset -= OFFSET_INC;
                                Object t;
                                t.flag = 6;
                                t.lo = eptr;
                                insertVariable( VariableDefinition(pname->getAttribute()._string,ET_SIMPLE_ENUM, false, currentNestLevel, t, offset), lineNumber);

                                break;
                            }
                            case TK_SIMPLE_LIMIT: {
                                SubBoundDefinition sub = SubBoundDefinition(ptype->getChildren().at(0)->getExpType(), ptype->getChildren().at(0)->getAttribute(), ptype->getChildren().at(1)->getAttribute());
                                offset -= OFFSET_INC;
                                Object temp;
                                temp.flag = 7;
                                sdvector.push_back(sub);
                                temp.sd = &(sdvector.back());
                                insertVariable(VariableDefinition(pname->getAttribute()._string, ET_SIMPLE_LIMIT, false, currentNestLevel, temp, offset), lineNumber);
                                break;
                            }
                            case SIMPLE_SYS: {
                                offset -= OFFSET_INC;
                                Object t;
                                t.flag = 0;
                                insertVariable( VariableDefinition(pname->getAttribute()._string, ptype->getExpType(), false, currentNestLevel, t, offset), lineNumber);
                                break;
                            }
                            case TK_ARRAY: {
                                int arraySize = 0;
                                if (ptype->getChildren().at(0)->getExpType() == ET_SIMPLE_LIMIT) { 
                                    arraySize = ptype->getChildren().at(0)->getChildren().at(1)->getAttribute()._int - ptype->getChildren().at(0)->getChildren().at(0)->getAttribute()._int + 1;
                                    ArrayDefinition pAttr = ArrayDefinition(ptype->getChildren().at(1)->getExpType(), ptype->getChildren().at(0)->getChildren().at(0)->getExpType(), ptype->getChildren().at(0)->getChildren().at(0)->getAttribute(), ptype->getChildren().at(0)->getChildren().at(1)->getAttribute());
                                    offset -= (OFFSET_INC * arraySize);
                                    Object temp; temp.flag = 8;
                                    advector.push_back(pAttr);
                                    temp.ad = &(advector.back());
                                    insertVariable( VariableDefinition(pname->getAttribute()._string, ptype->getExpType(), false, currentNestLevel, temp, offset), lineNumber);
                                }
                                break;
                            }
                            case TK_RECORD: {
                                list<TypeDefinition> TypeDefinitionList;
                                while (ptype != NULL) {
                                    TreeNode nameNode = ptype->getChildren().at(0);
                                    TreeNode typeNode = ptype->getChildren().at(1);
                                    while (nameNode != NULL) {
                                        offset -= OFFSET_INC;
                                        Object null;
                                        null.flag=0;
                                        TypeDefinitionList.push_back(TypeDefinition(nameNode->getAttribute()._string, typeNode->getExpType(), currentNestLevel, null, OFFSET_INC));
                                        nameNode = nameNode->getSibling();
                                    }
                                }
                                RecordDefinition r = RecordDefinition(ANONYMOUS, TypeDefinitionList);
                                Object temp;
                                temp.flag = 5;
                                rdvector.push_back(r);
                                temp.rd = &(rdvector.back());
                                insertVariable(VariableDefinition(pname->getAttribute()._string, ET_RECORD, false, currentNestLevel, temp, offset), lineNumber);
                                break;
                            }
                            default:
                                break;
                        }
                        pname = pname->getSibling();
                    }
                    t = t->getSibling();
                }
                break;
            }
            case TYPE: {
                while (t != NULL) {
                    switch (t->getChildren().at(1)->getNodeType()) {
                        case SIMPLE_ID: {
                            string definedTypeName = t->getChildren().at(1)->getAttribute()._string;
                            TypeDefinition definedType = lookupType(definedTypeName);
                            if (definedType.name ==  "undefined") {
                                cout<<"No such type: "<<definedTypeName<<" in line "<<lineNumber<<endl;
                                exit(1);
                            }
                            insertType(TypeDefinition(t->getChildren().at(0)->getAttribute()._string, definedType.type, currentNestLevel, definedType.pAttr, OFFSET_INC), lineNumber);
                            break;
                        }
                        case TK_SIMPLE_ENUM: {
                            TreeNode eList = t->getChildren().at(1)->getChildren().at(0);
                            list<Object> eptr;
                            while (eList != NULL) {
                                eptr.push_back(eList->getAttribute());
                                eList = eList->getSibling();
                            }
                            offset -= OFFSET_INC;
                            Object temp; temp.flag = 6; temp.lo = eptr;
                            insertType(TypeDefinition(t->getChildren().at(0)->getAttribute()._string, ET_SIMPLE_ENUM, currentNestLevel, temp, OFFSET_INC), lineNumber);
                            break;
                        }
                        case TK_SIMPLE_LIMIT: {
                            SubBoundDefinition sub = SubBoundDefinition(t->getChildren().at(1)->getChildren().at(0)->getExpType(), t->getChildren().at(1)->getChildren().at(0)->getAttribute(), t->getChildren().at(1)->getChildren().at(1)->getAttribute());
                            sdvector.push_back(sub);
                            Object temp; temp.flag = 7; temp.sd = &(sdvector.back());
                            insertType(TypeDefinition(t->getChildren().at(0)->getAttribute()._string, ET_SIMPLE_LIMIT, currentNestLevel, temp, OFFSET_INC), lineNumber);
                            break;
                        }
                        case SIMPLE_SYS: {
                            Object null; null.flag = 0;
                            insertType(TypeDefinition(t->getChildren().at(0)->getAttribute()._string, t->getChildren().at(1)->getExpType(), currentNestLevel, null, OFFSET_INC), lineNumber);
                            break;
                        }
                        case TK_ARRAY: {
                            TreeNode atype = t->getChildren().at(1);
                            if (atype->getChildren().at(0)->getExpType() == ET_SIMPLE_LIMIT) {
                                ArrayDefinition pAttr = ArrayDefinition(atype->getChildren().at(1)->getExpType(), atype->getChildren().at(0)->getChildren().at(0)->getExpType(), atype->getChildren().at(0)->getChildren().at(0)->getAttribute(), atype->getChildren().at(0)->getChildren().at(1)->getAttribute());
                                int size = (atype->getChildren().at(0)->getChildren().at(1)->getAttribute()._int - atype->getChildren().at(0)->getChildren().at(0)->getAttribute()._int + 1) * OFFSET_INC;
                                advector.push_back(pAttr);
                                Object temp; temp.flag = 8; temp.ad = &(advector.back());
                                insertType(TypeDefinition(t->getChildren().at(0)->getAttribute()._string, t->getChildren().at(1)->getExpType(), currentNestLevel, temp, size), lineNumber);
                            }
                            break;
                        }
                        case TK_RECORD: {
                            TreeNode pname = t->getChildren().at(0);
                            TreeNode ptype = t->getChildren().at(1);
                            list<TypeDefinition> TypeDefinitionList;
                            int size = 0;
                            while (ptype != NULL) {
                                TreeNode nameNode = ptype->getChildren().at(0);
                                TreeNode typeNode = ptype->getChildren().at(1);
                                Object null; null.flag = 0;
                                while (nameNode != NULL) {
                                    size++;
                                    TypeDefinitionList.push_back(TypeDefinition(nameNode->getAttribute()._string, typeNode->getExpType(), currentNestLevel, null, OFFSET_INC));
                                    nameNode = nameNode->getSibling();
                                }
                                ptype = ptype->getSibling();
                            }
                            RecordDefinition r = RecordDefinition(DEFINED, TypeDefinitionList);
                            rdvector.push_back(r);
                            Object temp; temp.rd = &(rdvector.back());
                            temp.flag = 5;
                            insertType(TypeDefinition(pname->getAttribute()._string, ET_RECORD, currentNestLevel, temp, size * OFFSET_INC), lineNumber);
                            break;
                        }
                        default:
                            break;
                    }
                    t = t->getSibling();
                }
                break;
            }
            default:
                break;
        }
    }


