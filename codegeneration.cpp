#include "codegeneration.hpp"

int label_count = 0;
vector<int> label_stack;

void CG_OutputAss()
{
  fout << "/*-------------------------------------------------*/" << endl;
  fout << "/*                Java Assembly Code               */" << endl;
  fout << "/*-------------------------------------------------*/" << endl;
}

void CG_initBegin()
{
  fout << "class " << filename << endl << "{" << endl;
}

void CG_initEnd()
{
  fout << "}" << endl;
}

void CG_progBeg()
{
  fout << "\tmethod public static void main(java.lang.String[])" << endl;
  fout << "\tmax_stack 15" << endl;
  fout << "\tmax_locals 15" << endl;
  fout << "\t{" << endl;
}

void CG_progEnd()
{
  fout << "\t\treturn" << endl;
  fout << "\t}" << endl;
}

void CG_VarDeclar(string id, Vartype var)
{
  if(var.global)   
  {
    fout << "\tfield static ";
    switch (var.type)
    {
      case TYPE_INT:
        fout << "int ";
        break;
      case TYPE_BOOLEAN:
        fout << "bool ";
        break;
      default:
        fout << "";
        break;
    }
    fout << id; //global == false as global
  }
  if(var.declar)
  {
    if(!var.global) fout << "\t\tsipush ";
    else fout << " = ";
    switch (var.type)
    {
      case TYPE_INT:
        fout << var.var_val.int_val;
        break;
      case TYPE_REAL:
        fout << (int)var.var_val.real_val;
        break;
      case TYPE_BOOLEAN:
        fout << var.var_val.boolean_val;
        break;
      default:
        fout << "";
        break;
    }
  }
  if(!var.global)
  {
    if(var.declar) fout << endl;
    fout << "\t\tistore "  << var.index;
  }
  fout << endl;
}

void CG_ExprVar(Vartype var)
{
  if(var.global) fout << "\t\tgetstatic int " << filename << "." << var.id << endl;
  else fout << "\t\tiload " << var.index << endl;
  // iload -> declar before use, 
  /*
  declar
    a: integer;
  begin
    a := ...;
  end

  as a expr
  */
}

void CG_ExprConst(Vartype cons)
{
  fout << "\t\t";
  switch(cons.type)
  {
      case TYPE_INT:
      fout << "sipush " << cons.var_val.int_val;
      break;
    case TYPE_BOOLEAN:
      fout << "iconst_" << cons.var_val.boolean_val;
      break;
    case TYPE_STRING:
      fout << "ldc \"" << cons.var_val.stringVal << "\"";
  }
  fout << endl;
}

void CG_ExprArith(char operType)
{
  fout << "\t\t";
  switch(operType)
  {
    case '+': // +
      fout << "iadd ";
      break;
    case '-': // -
      fout << "isub ";
      break;
    case '*': // *
      fout << "imul ";
      break;
    case '/': // /
      fout << "idiv ";
      break;
    case '%': // %
      fout << "irem ";
      break;
    case 'n': // -expr
      fout << "ineg ";
      break;
    case 'a': // and
      fout << "iand ";
      break;
    case 'o': // or
      fout << "ior ";
      break;
    case 'x': // xor
      fout << "ixor ";
      break;
  }
  fout << endl;
}

void CG_ExprBool(int operType)
{
  fout << "\t\tisub" << endl;
  fout << "\t\t";
  switch(operType)
  {
    case 0: // <
      fout << "iflt";
      break;
    case 1: // >
      fout << "ifgt";
      break;
    case 2: // =
      fout << "ifeq";
      break;
    case 3: // <=
      fout << "ifle";
      break;
    case 4: // >=
      fout << "ifge";
      break;
    case 5: // /=
      fout << "ifne";
      break;
  }

  int num_Ltrue = label_count;
  label_count++;
  int num_Lfalse = label_count;
  label_count++;
  fout << " L" << num_Ltrue <<  endl;
  fout << "\t\ticonst_0" << endl;
  fout << "\t\tgoto L" << num_Lfalse << endl;
  fout << "L" << num_Ltrue << ":" << endl << "\t\ticonst_1" << endl;
  fout << "L" << num_Lfalse << ":" << endl;
}

void CG_StateAssign(string id, Vartype id_expr)
{
  fout << "\t";
  if(id_expr.global)
  {
    fout << "\tputstatic ";
    switch(id_expr.type)
    {
      case TYPE_INT:
        fout << "int ";
        break;
      case TYPE_BOOLEAN:
        fout << "boolean ";
        break;
      case TYPE_STRING:
        fout << "string ";
        break;
    }
    fout << filename << "." << id;
  }
  else
  {
    fout << "\tistore " << id_expr.index;
  }
  fout << endl;
}

void CG_StatePrintBegin()
{
  fout << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl;
}

void CG_StatePrintEnd(bool prin, Vartype expr)
{
  if(prin) fout << "\t\tinvokevirtual void java.io.PrintStream.print(";
  else fout << "\t\tinvokevirtual void java.io.PrintStream.println(";
  switch(expr.type)
  {
    case TYPE_INT:
      fout << "int)";
      break;
    case TYPE_BOOLEAN:
      fout << "boolean)";
      break;
    case TYPE_STRING:
      fout << "java.lang.String)";
      break;  
  }
  fout << endl;
}

void CG_StateIfBegin()
{
  label_stack.push_back(label_count);
  label_count += 2;
  fout << "\t\tifeq L" << label_stack[label_stack.size() - 1] << endl;
}

void CG_StateElseBegin()
{
  fout << "\t\tgoto L" << label_stack[label_stack.size() - 1] + 1 << endl;
  fout << "L" << label_stack[label_stack.size() - 1] << ":"<< endl;
}

void CG_StateCondEnd(bool withElse)
{
  if(withElse) fout << "L" << label_stack[label_stack.size() - 1] + 1 << ":" << endl;
  else fout << "L" << label_stack[label_stack.size() - 1] << ":" << endl;
  label_stack.pop_back();
}

void CG_StateLoopBegin()
{
  label_stack.push_back(label_count);
  label_count++;
  fout << "L" << label_stack[label_stack.size() - 1] << ":" << endl;
}

void CG_StateLoopExpr()
{
  label_stack[label_stack.size() - 1] ++;
  label_count++;
  fout << "\t\tifeq L" << label_stack[label_stack.size() - 1] + 2 << endl;
}

void CG_StateLoopEnd()
{
  fout << "\t\tgoto L" << label_stack[label_stack.size() - 1] - 1 << endl;
  fout << "L" << label_stack[label_stack.size() - 1] + 2 << ":" << endl;
  label_stack.pop_back();
}

void CG_StateLoop_ForEnd(string id, Vartype var)
{
  //CG_ExprVar
  if(var.global) fout << "\t\tgetstatic int " << filename << "." << var.id << endl;
  else fout << "\t\tiload " << var.index << endl;

  fout << "\t\tsipush 1" << endl;
  fout << "\t\tiadd" << endl;

  //CG_StateAssign
  fout << "\t\t";
  if(var.global)
  {
    fout << "putstatic ";
    switch(var.type)
    {
      case TYPE_INT:
        fout << "int ";
        break;
      case TYPE_BOOLEAN:
        fout << "boolean ";
        break;
      case TYPE_STRING:
        fout << "string ";
        break;
    }
    fout << filename << "." << id;
  }
  else
  {
    fout << "istore " << var.index;
  }
  fout << endl;
}

void CG_ProceFuncBegin(Vartype proce)
{
  fout << "\tmethod public static ";
  switch(proce.type)
  {
    case TYPE_INT:
      fout << "int ";
      break;
    case TYPE_BOOLEAN:
      fout << "boolean ";
      break;
    case TYPE_STRING:
      fout << "string ";
      break;
    case TYPE_VOID:
      fout << "void ";
      break;
  }
  fout << proce.id << "(";
  for(int i = 0; i < proce.var_val.funcArg.size(); i++)
  {
    switch(proce.var_val.funcArg[i].type)
    {
      case TYPE_INT:
        fout << "int";
        break;
      case TYPE_BOOLEAN:
        fout << "boolean";
        break;
      case TYPE_STRING:
        fout << "string";
        break;
    }
    if(i != proce.var_val.funcArg.size() - 1) fout << " ,";
  }
  fout << ")" << endl;
  fout << "\tmax_stack 15" << endl;
  fout << "\tmax_locals 15" << endl;
  fout << "\t{" << endl;
}

void CG_ProceFuncEnd(int kind)
{
  if(kind == 0) fout << "\t\treturn" << endl; //procedure
  else if (kind == 3) fout << "\t\tireturn" << endl; //function
  fout << "\t}" << endl;
}

void CG_ProceFuncInvocation(Vartype proce)
{
  fout << "\t\tinvokestatic ";
  switch (proce.type)
  {
    case TYPE_INT:
      fout << "int";
      break;
    case TYPE_BOOLEAN:
      fout << "boolean";
      break;
    case TYPE_VOID:
      fout << "void";
      break;
  }
  fout << " " << filename << "." << proce.id << "(";
  for(int i = 0; i < proce.var_val.funcArg.size(); i++)
  {
    switch(proce.var_val.funcArg[i].type)
    {
      case TYPE_INT:
        fout << "int";
        break;
      case TYPE_BOOLEAN:
        fout << "boolean";
        break;
      case TYPE_STRING:
        fout << "string";
        break;
      case TYPE_VOID:
        fout << "void";
        break;
    }
    if(i != proce.var_val.funcArg.size() - 1) fout << " ,";
  }
  fout << ")" << endl;
}