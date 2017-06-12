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
#include "colorconsole.h"
using namespace std;
extern int yyparse(void);
extern FILE* yyin;
TreeNode savedTree;
vector<string> errMsg;

Color::Modifier red(Color::FG_RED);
Color::Modifier def(Color::FG_DEFAULT);

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        cout<<"please input like : ./main x.spl y.asm"<<endl;
        exit(1);
    }
    char* input = argv[1];
    string output = argv[2];
    FILE *fp = fopen(input, "r");
    if(fp == NULL)
    {
        cout<<"can not open file "<<input<<endl;
        exit(1);
    }
    yyin = fp;
    cout<<"compile begin"<<endl;
    yyparse();
    fclose(fp);
    cout<<"compile end"<<endl;
	if(errMsg.size()==0)
	{
        cout<<"===========a=b=s=t=r=c=t===t=r=e=e============="<<endl;
		savedTree->printTree(savedTree,0);
		CodeGenerator *instance = CodeGenerator::getinstance();
		CodeGenerator::init(instance);
		instance->generate(savedTree,output);
        cout<<"==============================================="<<endl;
        cout<<"generate code finish"<<endl;
	}
	else
		for(int i = 0; i < errMsg.size(); i++)
            cout<<red<<"Error: "<<def<<errMsg.at(i)<<endl;
    return 0;
}
