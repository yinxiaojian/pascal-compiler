# pascal-compiler
this is a pascal compiler which can translate pascal code to x86 assembly language. easy to use, try it!

# compile and run 
this project can only run in Linux, make sure you have flex and bison. if you don't have, please install:
```
sudo apt-get install flex
sudo apt-get install bison
```
after install, you can run it
```
make
./main x.spl y.asm
# such as: ./main test/test2.spl test/test2.asm
# you can input 'make clean' to delele .o file
```
# file decription
```
├── absyn.cpp           for abstract tree 
├── absyn.h             for abstract tree
├── absyn.o
├── codegen.cpp         for code generate 
├── codegen.h           for code generate
├── codegen.o
├── colorconsole.h      add console color
├── gendefine.h         code generate class define
├── lex.l               lexical analysis
├── lex.yy.c
├── lex.yy.o
├── main                main
├── main.cpp            main function
├── main.o
├── Makefile            makefile
├── symboldefine.h      symbol table define
├── symboltable.cpp     for symbol table
├── symboltable.h       for symbol table
├── symboltable.o
├── testspl             test
│   ├── test2.asm
│   ├── test2.spl
│   ├── test4.asm
│   ├── test4.spl
│   ├── test6.asm
│   └── test6.spl
├── typemap.h           enum-string map
├── yacc.tab.c
├── yacc.tab.h
├── yacc.tab.o
└── yacc.y              syntax analysis
```

# work finished
```
Scanning. Using Lex √
Parsing. Using Yacc √
Semantic Analysis √
Error detection √(simple)
Error recovery √(simple)
Symbol table, type checking √
Code generation Target: MASM √
Runtime environment √
Optimization √(simple)

middle code generate ×
```

# support
### Type:
* Integer
* Real
* Char
* Bool
* Record (imperfectly)
* Array (imperfectly)

### statement
* if statement
* for statement
* repeat statement
* while statement
* case statement
* goto statement 

### system function
* write
* writeln
* read

### other
* variable
* type
* function
* procedure

# finally
please forgive a little bug ^_+
