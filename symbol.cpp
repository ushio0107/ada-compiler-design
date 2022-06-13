#include "symbol.hpp"

int localIndex = 0;

SymbolTable::SymbolTable()
{
}

int SymbolTable::sym_Globalinsert(string id, Vartype sym)
{
  if(haveDeclar(id)) return -1;
  else
  {
    symbols.push_back(id);
    table_map[id].global = true;
    table_map[id].arr_index = sym.arr_index;
    table_map[id].id = id;
    table_map[id].type = sym.type;
    table_map[id].var_kind = sym.var_kind;
    table_map[id].var_val = sym.var_val;
    table_map[id].declar = sym.declar;
    //cout << "done" << endl;
    return 1;
  }
}

int SymbolTable::sym_Localinsert(string id, Vartype sym)
{
  if(haveDeclar(id)) return -1;
  else
  {
    symbols.push_back(id);
    //localIndex++;
    table_map[id].global = false;
    table_map[id].arr_index = sym.arr_index;
    table_map[id].index = symbols.size() - 1;
    table_map[id].id = id;
    table_map[id].type = sym.type;
    table_map[id].var_kind = sym.var_kind;
    table_map[id].var_val = sym.var_val;
    table_map[id].declar = sym.declar;
    //cout << "done" << endl;
    return 1;
  }
}

Vartype SymbolTable::getSym(string id)
{
  Vartype sym = table_map[id];
  return sym;
}

bool SymbolTable::haveDeclar(string id)
{
  return table_map.find(id) != table_map.end();
}

void SymbolTable::changeKind(string id, int kind)
{
  table_map[id].var_kind = kind;
}

Vartype *SymbolTable::lookup(string id)
{
  if(haveDeclar(id)) return new Vartype(table_map[id]);
  else return NULL;
}

void SymbolTable::dump()
{
  cout << setw(20) << left <<"identifier" << setw(20)<< "Kind" << setw(20) <<  "DataType" << setw(20) << "Attribute" << endl;
  for(int i = 0; i < symbols.size(); ++i)
  {
    Vartype symtable = table_map[symbols[i]];
    cout <<  setw(20) << symtable.id ;
    switch(symtable.var_kind) 
    {
      case KIND_PROCEDURE:
        cout << setw(20) <<"Procedure";  
        break;
      case KIND_VARIABLE:
        cout << setw(20)  << "Variable";    
        break;
      case KIND_CONSTANT:
        cout << setw(20) << "Constant";    
        break;
      case KIND_FUNCTION:
        cout << setw(20) << "Function";
        break;
    }
    switch(symtable.type)
    {
      case TYPE_INT:
        cout << setw(20) << "Integer";
        break;
      case TYPE_REAL:
        cout << setw(20) << "Float";
        break;
      case TYPE_STRING:
        cout << setw(20) << "String";
        break;
      case TYPE_BOOLEAN: 
        cout << setw(20) << "Boolean";
        break;
      case TYPE_ARRAY:
        cout << setw(20) << "Array";
        break;
      case TYPE_VOID:
        cout << setw(20) << "Void";
        break;
    }
    //attribute
    if(symtable.declar) 
    {
      switch(symtable.type) 
      {
      case TYPE_INT: 
        cout << symtable.var_val.int_val;
        break;
      case TYPE_REAL: 
          cout << symtable.var_val.real_val;
        break;
      case TYPE_STRING: 
        cout << symtable.var_val.stringVal;
        break;      
      case TYPE_BOOLEAN: 
        cout << symtable.var_val.boolean_val;
        break;
      }
    }
    if(symtable.var_kind == KIND_FUNCTION || symtable.var_kind == KIND_PROCEDURE ) 
    {
      cout << "{";
      for(int i = 0; i < symtable.var_val.funcArg.size(); ++i) 
      {
        switch(symtable.var_val.funcArg[i].type) 
        {
          case TYPE_INT: 
            cout << "Integer";
            break;
          case TYPE_REAL: 
            cout << "Float";
            break;
          case TYPE_BOOLEAN:
            cout << "Boolean";
            break;
          case TYPE_STRING: 
            cout << "String";
            break;
          case TYPE_VOID:
            cout << "Void";
            break;
        }
        if(i != symtable.var_val.funcArg.size() -1) cout << ",";
      }
      cout << "}";
    }
    if(symtable.type == TYPE_ARRAY) 
    {
      switch(symtable.var_val.array_val[0].type) 
      {
        case TYPE_INT:
          cout << "Integer ";
          break;
        case TYPE_REAL:
          cout << "Float ";
          break;
        case TYPE_STRING: 
          cout << "String "; 
          break;        
        case TYPE_BOOLEAN:
          cout << "Boolean "; 
          break;
      }
      cout << "["<< symtable.var_val.array_val.size() << "]";
    }
    cout << endl;
  }
  cout << endl;
}

void SymbolTable::setProceType(int type)
{
  table_map[symbols[symbols.size() - 1]].type = type;
}

void SymbolTable::addProceArg(string id, Vartype symtable)
{
  table_map[symbols[symbols.size() - 1]].var_val.funcArg.push_back(symtable);
}

void symtable_dump(vector<SymbolTable> symtable, int scope)
{
  cout << "---------------------------------------------------------------------------" << endl;
  cout << "|                                                                         |" << endl;
  cout << "|                               SYMBOL TABLE                              |" << endl;
  cout << "|                                                                         |" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  if(symtable.size() > 0)
  {
    for(int i = symtable.size() - 1; i >= 0; --i) 
    {
      if(i == 0) cout << "Scope: \t 0(Global)" << endl; 
      else if(scope != 0)
      {
        cout << "Scope: \t " << scope << endl;
      }
      symtable[i].dump();
    }
  }
  cout << "---------------------------------------------------------------------------" << endl;
}

Vartype *symtableList_lookup(string id, vector<SymbolTable> symtable, int scope)
{
  if(scope > 1) 
  {
    for(int i = scope; i >= 0; i--)
    {
      if(symtable[i].haveDeclar(id)) return symtable[i].lookup(id);
    }
  }
  else
  {
    if(symtable[scope].haveDeclar(id)) return symtable[scope].lookup(id);
    else if(symtable[0].haveDeclar(id)) return symtable[0].lookup(id);
  }
  return NULL;
}

Vartype *new_constantInsert(int symtype, void *val)
{
  Vartype *newconstant = new Vartype();
  newconstant->var_kind = KIND_CONSTANT;
  newconstant->type = symtype;
  switch(symtype)
  {
    case TYPE_INT:
        newconstant->var_val.int_val = *(int*)val;
        //cout << newconstant->var_val.int_val << endl;
        break;
    case TYPE_REAL:
        newconstant->var_val.real_val = *(float*)val;
        break;
    case TYPE_STRING:
        newconstant->var_val.stringVal = *(string*)val;
        break;
    case TYPE_BOOLEAN:
        newconstant->var_val.boolean_val = *(bool*)val;
        break;
  }

  return newconstant;
}

Vartype *new_variable(int kind, int type)
{
  Vartype *new_var = new Vartype();
  new_var->var_kind = kind;
  new_var->type = type; 
  return new_var;
}

Vartype *exprArith(Vartype expr1, Vartype expr2, char opera, int kind, int type)
{
  Vartype* new_expr = new Vartype();
  float val1;
  float val2;
  float sum_real;
  int sum_int;
  switch(expr1.type)
  {
    case TYPE_INT:
      val1 = expr1.var_val.int_val;
      break;
    case TYPE_REAL:
      val1 = expr1.var_val.real_val;
      break;
  }
  switch(expr2.type)
  {
    case TYPE_INT:
      val2 = expr2.var_val.int_val;
      break;
    case TYPE_REAL:
      val2 = expr2.var_val.real_val;
      break;
  }

  switch(opera)
  {
    case '+': // +
    sum_real = val1 + val2;
    break;
    case '-': // -
    sum_real = val1 - val2;
    break;
    case '*': // *
    sum_real = val1 * val2;
    break;
    case '/': // /
    sum_real = val1 / val2;
    break;
  }
    if(expr1.type == TYPE_REAL || expr2.type == TYPE_REAL)
  {
    new_expr->var_val.real_val = sum_real;
  }
  else 
  {
    sum_int = sum_real;
    new_expr->var_val.int_val = sum_int;
  }
  //cout << new_expr->var_val.int_val << endl;
  new_expr->var_kind = kind;
  new_expr->type = type;
  new_expr->declar = true;

  return new_expr;
}