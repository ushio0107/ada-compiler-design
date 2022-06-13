#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

typedef enum{ KIND_PROCEDURE, KIND_VARIABLE, KIND_CONSTANT, KIND_FUNCTION } KIND;
typedef enum{ TYPE_INT, TYPE_REAL, TYPE_BOOLEAN, TYPE_STRING, TYPE_ARRAY, TYPE_VOID } TYPEOFVAR;

struct VarVal;
struct Vartype;

struct VarVal
{
    int int_val;
    float real_val;
    bool boolean_val;
    string stringVal = "";
    vector<Vartype> array_val;
    vector<Vartype> funcArg;
};

struct Vartype 
{ 
    bool global = true;
    int arr_index;
    int index;
    string id = "";
    int type;
    int var_kind;
    VarVal var_val;
    bool declar = false;
};