#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include "symtype.hpp"

using namespace std;

class SymbolTable
{
    private:
    vector<string> symbols;
    map<string, Vartype> table_map;

    public:
    SymbolTable();
    int sym_Globalinsert(string id, Vartype sym);
    int sym_Localinsert(string id, Vartype sym);
    Vartype getSym(string id);
    bool haveDeclar(string id);    
    void changeKind(string id, int kind);
    Vartype *lookup(string id);
    void dump();
    void setProceType(int type);
    void addProceArg(string id, Vartype info);
};

void symtable_dump(vector<SymbolTable> symtable, int scope);
Vartype *symtableList_lookup(string id, vector<SymbolTable> symtable, int scope);
Vartype *new_constantInsert(int symtype, void *val);
Vartype *new_variable(int kind, int type);
Vartype *exprArith(Vartype expr1, Vartype expr2, char opera, int kind, int type);

/*void initSymbolTable(struct SymbolTable *table);
void AddSymTable(struct SymbolTable* table);
void dumpSymbolTable(struct SymbolTable* table);

struct Attribute* CONSTANT_setvalue(TYPEOFVAR type, void* value);*/
