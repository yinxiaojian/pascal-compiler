/*************************************************************************
	> File Name: absyn.cpp
	> Author: yinxiaojian
	> Mail: jianwen_yin@163.com
	> Created Time: Fri 09 Jun 2017 07:59:35 PM PDT
 ************************************************************************/

#include <iostream>
#include "absyn.h"
using namespace std;

vector<TreeNode> TreeDefine::getChildren() {return childNode;}
void TreeDefine::addChild(TreeNode node) {childNode.push_back(node);}

TreeNode TreeDefine::getSibling() {return siblingNode;}
void TreeDefine::setSibling(TreeNode siblingNode) {this->siblingNode = siblingNode;}

int TreeDefine::getLineNumber() {return lineNumber;}
void TreeDefine::setLineNumber(int lineNumber) { this->lineNumber = lineNumber;}

int TreeDefine::getNodeType() {return nodeType;}
void TreeDefine::setNodeType(int nodeType) {this->nodeType = nodeType;}

Object TreeDefine::getAttribute() {return attribute;}
void TreeDefine::setAttribute(Object attribute) {this->attribute = attribute;}
void TreeDefine::setAttribute(int attribute,int flag = 1) {this->attribute._int = attribute; this->attribute.flag = flag;}
void TreeDefine::setAttribute(double attribute) {this->attribute._double = attribute; this->attribute.flag = 2;}
void TreeDefine::setAttribute(string attribute) {this->attribute._string = attribute; this->attribute.flag = 3;}

ExpressionType TreeDefine::getExpType() {return expressionType;}
void TreeDefine::setExpType(ExpressionType expressionType) {this->expressionType = expressionType;}

ExpressionType TreeDefine::getRunTimeType() {return runtimeType;}
void TreeDefine::setRunTimeType(ExpressionType runtimeType) {this->runtimeType = runtimeType;}

void TreeDefine::printTree(TreeNode root, int level)
{
    if(level == 0)
        if(root == NULL) return;
    for(int i = 0; i < level; ++i){
        if(bitSet[i] == false)
            cout<<"|";
        else
            cout<<" ";
        cout<<"    ";
    }
    cout<<"|-";
    cout<<" "<<mapping[root->getNodeType()];
    cout<<" "<<mapping[root->getExpType()];
    switch(root->getAttribute().flag)
    {
        case 1: cout << " " << root->getAttribute()._int; break;
        case 2: cout << " " << root->getAttribute()._double; break;
        case 3: cout << " " << root->getAttribute()._string; break;
		case 4: cout << " " << mapping[root->getAttribute()._int]; break;
        defualt: cout << " "<< mapping[0]; break;
    }
    cout<<endl;

    if(root->getSibling() == NULL)
        bitSet.set(level);
    else
        bitSet.reset(level);
        
    int cnt = 0;
    for(int i=0;i<root->getChildren().size();i++)
        if(root->getChildren().at(i) != NULL) cnt++;
    int cnt2 = 0;
    for(int i=0;i<root->getChildren().size();i++){
        if(root->getChildren().at(i) != NULL){
            cnt2++;
            for(int j = 0; j < level + 1; ++j){
                if(bitSet[j] == false)
                    cout<<"|";
                else
                    cout<<" ";
                cout<<"    ";
            }
            if(cnt2 == cnt)
                bitSet.set(level + 1);
            else
                bitSet.reset(level + 1);
            cout<<"|-"<<mapping[root->getChildren().at(i)->getNodeType()]<<endl;
            printTree(root->getChildren().at(i), level + 2);
        }
    }
    TreeNode t = root->getSibling();
    if(t != NULL)
    {
        if(t->getSibling() == NULL)
            bitSet.set(level);
        else
            bitSet.reset(level);
        printTree(t, level);
    }
}
