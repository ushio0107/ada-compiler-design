all: compiler

compiler: lex.yy.cpp y.tab.cpp symbol.cpp symbol.hpp symtype.hpp codegeneration.cpp codegeneration.hpp
	g++ y.tab.cpp symbol.cpp codegeneration.cpp -o compiler -ll -ly -std=c++11 -Wno-deprecated-register

lex.yy.cpp: lex.l
	lex -o lex.yy.cpp lex.l

y.tab.cpp: parser.y
	yacc -d parser.y -o y.tab.cpp

clean:
	rm compiler lex.yy.cpp y.tab.*