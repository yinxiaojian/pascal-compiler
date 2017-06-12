/*************************************************************************
	> File Name: colorconsole.h
	> Author:yinxiaojian 
	> Mail: jianwen_yin@163.com
	> Created Time: Wed 07 Jun 2017 12:51:22 AM PDT
 ************************************************************************/

#ifndef _COLORCONSOLE_H
#define _COLORCONSOLE_H
#include <ostream>
namespace Color {
    enum Code {
         FG_RED = 31,
         FG_GREEN = 32,
         FG_BLUE = 34,
         FG_DEFAULT = 39,
         BG_RED = 41,
         BG_GREEN = 42,
         BG_BLUE = 44,
         BG_DEFAULT = 49
         
    };
    class Modifier {
        Code code;
        public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&operator<<(std::ostream& os, const Modifier& mod) {
             return os <<"\033[1;" <<mod.code <<"m";
        }
    };
};
#endif
