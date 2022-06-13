#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "symtype.hpp"
#include "symbol.hpp"

using namespace std;

extern string filename;
extern ofstream fout;

void CG_OutputAss();
void CG_initBegin();
void CG_initEnd();
void CG_progBeg();
void CG_progEnd();
void CG_VarDeclar(string id, Vartype var);
void CG_ExprVar(Vartype var);
void CG_ExprConst(Vartype cons);
void CG_ExprArith(char operType);
void CG_ExprBool(int operType);
void CG_StateAssign(string id, Vartype id_expr);
void CG_StatePrintBegin();
void CG_StatePrintEnd(bool prin, Vartype expr);
void CG_StateIfBegin();
void CG_StateElseBegin();
void CG_StateCondEnd(bool withElse);
void CG_StateLoopBegin();
void CG_StateLoopExpr();
void CG_StateLoopEnd();
void CG_StateLoop_ForEnd(string id, Vartype var);
void CG_ProceFuncBegin(Vartype proce);
void CG_ProceFuncEnd(int kind);
void CG_ProceFuncInvocation(Vartype proce);