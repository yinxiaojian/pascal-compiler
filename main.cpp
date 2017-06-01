/*************************************************************************
	> File Name: main.cpp
	> Author:yinxiaojian 
	> Mail: jianwen_yin@163.com
	> Created Time: Wed 31 May 2017 03:38:38 AM PDT
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
extern int yyparse(void);
extern FILE* yyin;
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
    return 0;
}
