%{
#include <iostream>
#include <string>
#include "symtype.hpp"
#include "symbol.hpp"
#include "codegeneration.hpp"
#include "lex.yy.cpp"


#define Trace(t) if (Opt_P) cout << "TRACE***\t" << t << "\t***"<< endl;
int Opt_P = 0; 
int scope = 0; //scope 1 mean global
int level = 0;

extern int linenum;
extern FILE *yyin;

string filename;
ofstream fout;

bool declaring = false;
int yyerror(string msg);
vector<SymbolTable>  symtable_list;
vector<vector<Vartype>> functions;
bool haveReturn = false;
bool cane = false;
%}

%union {
    int     int_val;
    string *stringVal;
    float   real_val;
    bool boolean_val;
    Vartype *var;
    int     dtype;
}

/* tokens */
%token COLON SEMICOLON LEFTBRACKETS RIGHTBRACKETS EQUAL ASSIGN LEFTPARENTHESES RIGHTPARENTHESES COMMA PERIOD IN NOT N_EQUAL REMAINDER
%token CONSTANT INTEGER BOOLEAN CHARACTER STRING FLOAT 
%token IF ELSE TRUE FALSE WHILE FOR LOOP DO THEN
%token PROGRAM PROCEDURE RETURN DECLARE BEG END PRINT PRINTLN READ

%token <real_val>num_real
%token <int_val>num_integer
%token <boolean_val> bool_val
%token <stringVal>string_val
%token <stringVal>identifier

%type <dtype>data_types
%type <var> constant_exp expression func_proce_invocation

%left OR
%left AND
%left NOT
%left LT LE EQUAL GE GT N_EQUAL
%left PLUS MINUS
%left MULT SLASH
%nonassoc UMINUS

%start program

%%
program:        {   
                    CG_OutputAss();
                    symtable_list.push_back(SymbolTable());
                    CG_initBegin();

                }
                PROGRAM identifier declarations BEG 
                {
                    CG_progBeg();
                    level = 0;
                }
                statements_list END semi END identifier 
                {
                    Trace("Program");
                    if(Opt_P) symtable_dump(symtable_list, 0);
                    if(symtable_list.size() > 1) symtable_list.pop_back(); 
                    CG_progEnd(); 
                    CG_initEnd();                        
                }
                ;

semi:           SEMICOLON;

declarationsTypes: constant_dec declarationsTypes 
                   |
                   var_dec declarationsTypes 
                   |
                   array_dec declarationsTypes 
                   |
                   function_dec declarationsTypes 
                   |
                   function_dec
                   |
                   constant_dec
                   |
                   var_dec
                   |
                   array_dec
                   ;

declarations:   DECLARE declarationsTypes
                |
                ;

constant_dec:   identifier COLON CONSTANT ASSIGN
                {
                    declaring = true;
                }
                expression semi 
                {
                    Trace("Constant Declaration (no type)");
                    if($6->var_kind != KIND_CONSTANT && $6->var_kind != KIND_VARIABLE) yyerror("expression's return value is no a constant.");
                    $6->var_kind = KIND_CONSTANT;
                    $6->declar = true;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*$1, *$6) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_Localinsert(*$1, *$6) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*$1, *$6) == -1) yyerror("id redefined (constant declaration)");
                    }
                    //if(symbolTable.symbol_insert(*$1) == -1) yyerror("id redefined (constant declaration)");
                    declaring = false;
                }
                |
                identifier COLON CONSTANT COLON data_types ASSIGN 
                {
                    declaring = true;
                }
                expression semi
                {
                    Trace("Constant Declaration (with) type)\n");
                    if($8->var_kind != KIND_CONSTANT && $8->var_kind != KIND_VARIABLE) yyerror("expression's return value is no a constant.");
                    $8->var_kind = KIND_CONSTANT;
                    $8->type = $5;
                    $8->declar = true;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*$1, *$8) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *$8) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*$1, *$8) == -1) yyerror("id redefined (constant declaration)");
                    }
                    declaring = false;
                };

var_dec:        identifier COLON data_types ASSIGN 
                {
                    declaring = true;
                    cane = true;
                }
                expression semi
                {
                    Trace("Variable declaration (with type and expr)");
                    if($6->var_kind != KIND_CONSTANT && $6->var_kind != KIND_VARIABLE) yyerror("expr is not a constant value");
                    if($3 != $6->type) yyerror("The variable declaration data type is not the data type of the expr");
                    $6->var_kind = KIND_VARIABLE;
                    $6->type = $3;
                    $6->declar = true;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*$1, *$6) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *$5) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*$1, *$6) == -1) yyerror("id redefined (constant declaration)");
                    }
                    Vartype *var = symtableList_lookup(*$1, symtable_list, level);
                    CG_VarDeclar(*$1, *var);
                    declaring = false;
                    cane = false;
                }
                |
                identifier ASSIGN 
                {
                    declaring = true;
                }
                expression semi
                {
                    Trace("Variable declaration (with expr)");
                    if($4->var_kind != KIND_CONSTANT && $4->var_kind != KIND_VARIABLE) yyerror("expr is not a constant value");
                    $4->var_kind = KIND_VARIABLE;
                    $4->declar = true;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*$1, *$4) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *$3) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*$1, *$4) == -1) yyerror("id redefined (constant declaration)");
                    }
                    Vartype *var = symtableList_lookup(*$1, symtable_list, level);
                    if(level == 0) CG_VarDeclar(*$1, *var);
                    declaring = false;               
                }       
                |
                identifier COLON data_types semi
                {
                    Trace("Variable declaration (with type)");
                    Vartype *new_var = new Vartype();
                    new_var->var_kind = KIND_VARIABLE;
                    new_var->type = $3;
                    //cout << "scope::" << scope << endl;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*$1, *new_var) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *new_var) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*$1, *new_var) == -1) yyerror("id redefined (constant declaration)");
                    }
                    Vartype *var = symtableList_lookup(*$1, symtable_list, level);
                    if(level == 0) CG_VarDeclar(*$1, *var);       
                }
                |
                identifier semi
                {
                    Trace("Variable declaration (no type and expr)");
                    Vartype *new_var = new Vartype();
                    new_var->var_kind = KIND_VARIABLE;
                    new_var->type = TYPE_INT;
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*$1, *new_var) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *new_var) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*$1, *new_var) == -1) yyerror("id redefined (constant declaration)");
                    }
                    Vartype *var = symtableList_lookup(*$1, symtable_list, level);
                    //cout << "var global" << var->global << endl;
                    if(level == 0) CG_VarDeclar(*$1, *var);     
                };

array_dec:      identifier COLON data_types LEFTBRACKETS expression RIGHTBRACKETS semi
                {
                    Trace("Array declaration");
                    if($5->var_kind != KIND_CONSTANT && $5->var_kind != KIND_VARIABLE) yyerror("the size of array is not a constant");
                    if($5->type != TYPE_INT) yyerror("the size of array is not a int");
                    if($5->var_val.int_val < 1) yyerror("the size of array can't be less than 1");
                    Vartype *new_sym = new Vartype();
                    new_sym->var_kind = KIND_VARIABLE;
                    new_sym->type = TYPE_ARRAY;
                    new_sym->var_val.array_val = vector<Vartype>($5->var_val.int_val);
                    for(int i = 0; i < $5->var_val.int_val; ++i)
                    {
                        new_sym->var_val.array_val[i].arr_index = -1;
                        new_sym->var_val.array_val[i].type = $3;
                        new_sym->var_val.array_val[i].var_kind = KIND_VARIABLE;
                    }
                    if(level == 0)
                    {
                        if(symtable_list[level].sym_Globalinsert(*$1, *$5) == -1) yyerror("id redefined (constant declaration)");
                    }
                    else 
                    {
                        //if(symtable_list[scope].sym_insert(*$1, *$5) == -1) yyerror("id redefined (constant declaration)");
                        if(symtable_list[level].sym_Localinsert(*$1, *$5) == -1) yyerror("id redefined (constant declaration)");
                    }
                    // no CG
                };

data_types:     INTEGER
                {$$ = TYPE_INT;}
                |
                FLOAT
                {$$ = TYPE_REAL;}
                |
                BOOLEAN
                {$$ = TYPE_BOOLEAN;}
                |
                STRING
                {$$ = TYPE_STRING;}
                ;

constant_exp:   num_integer
                {
                    Trace("num_int");
                    $$ = new_constantInsert(TYPE_INT, &$1);
                }
                | 
                num_real
                {
                    Trace("num_real");
                    float val = $1;
                    $$ = new_constantInsert(TYPE_REAL, &val);
                }
                |  
                string_val
                {
                    Trace("string_val");
                    $$ = new_constantInsert(TYPE_STRING, $1);
                    free($1);
                }
                | 
                TRUE
                {
                    Trace("boolean_true");
                    bool val = true;
                    $$ = new_constantInsert(TYPE_BOOLEAN, &val);
                }
                | 
                FALSE
                {
                    Trace("boolean_false");
                    bool val = false;
                    $$ = new_constantInsert(TYPE_BOOLEAN, &val);
                }
                ;


optional_formalarg:    LEFTPARENTHESES formal_arg RIGHTPARENTHESES
                        |
                        ;

formal_arg: formal_arg semi arg
            |
            arg;       
        
arg:    identifier COLON data_types
        {
            Trace("ARG");
            Vartype *arg = new Vartype();
            arg->var_kind = KIND_VARIABLE;
            arg->type = $3;
            //cout << "scope: " << scope << endl;
            //cout << "sym_list size: " << symtable_list.size() << endl;
            //if(symtable_list[scope].sym_insert(*$1, *arg) == -1) yyerror("id redefined (arg)");
            if(symtable_list[1].sym_Localinsert(*$1, *arg) == -1) yyerror("id redefined (arg)");
            symtable_list[0].addProceArg(*$1, *arg);
        }
        ;

function_dec:  PROCEDURE identifier  
                {
                    Vartype *func = new Vartype();
                    //cout << "scope: " << scope << endl;
                    func->var_kind = KIND_FUNCTION;
                    if(symtable_list[0].sym_Globalinsert(*$2, *func) == -1 ) yyerror("id redefined (function declaration)");
                    symtable_list.push_back(SymbolTable());
                    ++scope;
                    ++level;
                    //cout << symtable_list.size() << endl;
                }
                optional_formalarg return_type
                {
                    Vartype *func = symtableList_lookup(*$2, symtable_list, level - 1);
                    CG_ProceFuncBegin(*func);
                }
                declarations BEG statements_list END semi END identifier semi
                {
                    if(!haveReturn) 
                    {
                        symtable_list[0].changeKind(*$2, KIND_PROCEDURE);
                        CG_ProceFuncEnd(KIND_PROCEDURE);
                        Trace("Procedure declar");
                    }
                    else 
                    {
                        CG_ProceFuncEnd(KIND_FUNCTION);
                        Trace("Function declar");
                    }

                    if(Opt_P) symtable_dump(symtable_list, scope);
                    if(symtable_list.size() > 1) symtable_list.pop_back(); 
                    haveReturn = false;
                    --level;
                    //--scope;
                }
                ;

return_type:    RETURN data_types
                {
                    symtable_list[0].setProceType($2);
                    haveReturn = true;
                }
                |
                {
                    symtable_list[0].setProceType(TYPE_VOID);
                    haveReturn = false;
                }
                ;

com_expr:   comma_separated_expressions
            |
            ;

comma_separated_expressions:    comma_separated_expressions COMMA function_exp
                                |
                                function_exp
                                ;

function_exp:   expression
                {
                    Trace("function_exp");
                    //cout << $1->id << " "<< $1->type << endl;
                    
                    functions[functions.size() - 1].push_back(*$1);
                };
            
func_proce_invocation:  identifier
                        {
                            Trace("function invocation");
                            //cout << *$1 << endl;
                            functions.push_back(vector<Vartype>());
                        }
                        LEFTPARENTHESES com_expr RIGHTPARENTHESES
                        {
                            //cout << "OK : psss"<< endl;
                            Vartype *func = symtableList_lookup(*$1, symtable_list, level);
                            if(func == NULL) yyerror("haven't declare before invocate");
                            if(func->var_kind != KIND_FUNCTION && func->var_kind != KIND_PROCEDURE) yyerror("This is not a function or procedure");
                            vector<Vartype> p = func->var_val.funcArg;
                            if(p.size() != functions[functions.size() - 1].size()) yyerror("the size of the function parameter is different from the function declaration");
                            for(int i = 0; i < p.size(); ++i)
                            {
                                //cout << "type" << p[i].type<< endl;
                                //cout << "type2" << functions[functions.size() - 1].at(i).type <<endl;                                
                                if(p[i].type != functions[functions.size() - 1].at(i).type) yyerror("the type of the function parameter is different from the function declaration");
                            }
                            $$ = func;

                            CG_ProceFuncInvocation(*func);
                            functions.pop_back();
                        }
                        ;


block:  {
            Trace("Block");
            ++scope;
            ++level;
            //cout << "level" << level << endl;
            symtable_list.push_back(SymbolTable()); 
        }  
        declarations
        BEG statements_list END semi
        {
            --level;
            if(Opt_P) symtable_dump(symtable_list, scope);
            if(symtable_list.size() > 1) symtable_list.pop_back();
            //--scope;              
        }
        ;

expression:     identifier
                {
                    Trace("expr: id");
                    //cout << *$1 << endl;
                    //cout << "level"<<level <<endl;
                    Vartype *expr = symtableList_lookup(*$1, symtable_list, level);   
                    //cout << "level" << level <<endl;
                    //cout << *$1 << endl;                 
                    if(expr == NULL) yyerror("haven't declare before invocate");
                    $$ = expr;

                    if(!declaring) 
                    {
                        if(expr->var_kind == KIND_CONSTANT) CG_ExprConst(*expr);
                        else CG_ExprVar(*expr);
                    }
                    free($1);
                }
                |
                identifier LEFTBRACKETS expression RIGHTBRACKETS
                {  
                    Trace("expr: array type");
                    Vartype *arr = symtableList_lookup(*$1, symtable_list, level);
                    if(arr == NULL) yyerror("undeclared identifier");
                    if(arr->var_kind != KIND_VARIABLE) yyerror("not a variable");
                    if(arr->type != TYPE_ARRAY) yyerror("not array type");
                    if($3->type != TYPE_INT) yyerror("invalid index");
                    if($3->var_val.int_val >= arr->var_val.array_val.size() || $3->var_val.int_val < 0) yyerror("index out of range");
                    $$ = new Vartype(arr->var_val.array_val[$3->var_val.int_val]);
                }
                |
                constant_exp 
                {
                    Trace("constant_exp");
                    
                    if(declaring == true && cane == true && level != 0)
                    {
                    }
                    else if(!declaring) 
                    {
                        CG_ExprConst(*$1);
                    }
                    
                }
                |
                func_proce_invocation
                |
                LEFTPARENTHESES expression RIGHTPARENTHESES
                {
                    Trace("(expr)");
                    $$ = $2;
                }
                |
                MINUS expression %prec UMINUS
                {
                Trace("-expression");
                if($2->type != TYPE_INT && $2->type != TYPE_REAL) yyerror("The expr must be a int or real");
                if($2->var_kind == KIND_PROCEDURE) yyerror("a procedure can't be a factor");

                $$ = new_variable(KIND_VARIABLE, $2->type);
                CG_ExprArith('n');                
                }
                | 
                expression MULT expression
                {
                Trace("expression * expression");
                // this mean if expr1 = string/boolean, expr2 = string/boolean, their type must be the same, however, int or real is allowed to be expr1 or expr2 at the same time.
                if((($1->type != TYPE_INT && $1->type != TYPE_REAL) || ($3->type != TYPE_INT && $3->type != TYPE_REAL)) && ($1->type != $3->type)) yyerror("expr must be a int or real"); 
                if($1->type == TYPE_REAL || $3->type == TYPE_REAL) $$ = exprArith(*$1, *$3, '*', KIND_VARIABLE, TYPE_REAL);
                else $$ = exprArith(*$1, *$3, '*', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('*');
                }
                | 
                expression SLASH expression
                {
                Trace("expression / expression");
                if((($1->type != TYPE_INT && $1->type != TYPE_REAL) || ($3->type != TYPE_INT && $3->type != TYPE_REAL)) && ($1->type != $3->type)) yyerror("expr must be a int or real"); 
                if($1->type == TYPE_REAL || $3->type == TYPE_REAL) $$ = exprArith(*$1, *$3, '/', KIND_VARIABLE, TYPE_REAL);
                else $$ = exprArith(*$1, *$3, '/', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('/');
                }
                | 
                expression PLUS expression
                {
                Trace("expression + expression");
                if((($1->type != TYPE_INT && $1->type != TYPE_REAL) || ($1->type != TYPE_INT && $1->type != TYPE_REAL)) && ($1->type != $3->type)) yyerror("expr must be a int or real"); 
                if($1->type == TYPE_REAL || $3->type == TYPE_REAL) 
                {
                    $$ = exprArith(*$1, *$3, '+', KIND_VARIABLE, TYPE_REAL);
                }
                else $$ = exprArith(*$1, *$3, '+', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('+');
                }
                | 
                expression MINUS expression
                {
                Trace("expression - expression");

                if((($1->type != TYPE_INT && $1->type != TYPE_REAL) || ($3->type != TYPE_INT && $3->type != TYPE_REAL)) && ($1->type != $3->type)) yyerror("expr must be a int or real"); 
                if($1->type == TYPE_REAL || $3->type == TYPE_REAL) $$ = exprArith(*$1, *$3, '-', KIND_VARIABLE, TYPE_REAL);
                else $$ = exprArith(*$1, *$3, '-', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('-');
                }
                |
                expression REMAINDER expression
                {
                Trace("expression % expression");

                if((($1->type != TYPE_INT && $1->type != TYPE_REAL) || ($3->type != TYPE_INT && $3->type != TYPE_REAL)) && ($1->type != $3->type)) yyerror("expr must be a int or real"); 
                if($1->type == TYPE_REAL || $3->type == TYPE_REAL) $$ = exprArith(*$1, *$3, '%', KIND_VARIABLE, TYPE_REAL);
                else $$ = exprArith(*$1, *$3, '%', KIND_VARIABLE, TYPE_INT);

                if(!declaring) CG_ExprArith('%');
                }                
                | 
                expression LT expression
                {
                Trace("expression < expression");
                if(($1->type != TYPE_INT && $1->type != TYPE_REAL) || ($3->type != TYPE_INT && $3->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");
                // only int or real can compare
                $$ = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);

                //if(!declaring)
                CG_ExprBool(0);
                }
                | 
                expression LE expression
                {
                Trace("expression <= expression");
                if(($1->type != TYPE_INT && $1->type != TYPE_REAL) || ($3->type != TYPE_INT && $3->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");

                $$ = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(3);
                }
                | 
                expression EQUAL expression
                {
                Trace("expression = expression");
                //this mean expr1 = string/boolean and expr2 = string/boolean, and their type must be same
                if(($1->type != TYPE_INT && $1->type != TYPE_REAL) && ($3->type != TYPE_INT && $3->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");
                
                $$ = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(2);
                }
                | 
                expression GE expression
                {
                Trace("expression >= expression");

                if(($1->type != TYPE_INT && $1->type != TYPE_REAL) || ($3->type != TYPE_INT && $3->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");
                $$ = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(4);
                }
                | 
                expression GT expression
                {
                Trace("expression > expression");

                if(($1->type != TYPE_INT && $1->type != TYPE_REAL) || ($3->type != TYPE_INT && $3->type != TYPE_REAL)) yyerror("relational expr cannot be the type excepted int and real");
                $$ = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(1);
                }
                | 
                expression N_EQUAL expression
                {
                Trace("expression /= expression");
                if((($1->type != TYPE_INT && $1->type != TYPE_REAL) && ($3->type != TYPE_INT && $3->type != TYPE_REAL)) && $1->type != $3->type) yyerror("type of expr1 and type of expr2 are different"); 
                $$ = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprBool(5);
                }
                |
                NOT expression
                {
                Trace("NOT expression");

                if($2->type != TYPE_BOOLEAN) yyerror("expr must be a boolean");
                $$ = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprArith('x');
                }
                | 
                expression AND expression
                {
                Trace("expression AND expression");

                if($1->type != TYPE_BOOLEAN || $3->type != TYPE_BOOLEAN) yyerror("expr must be a boolean");

                $$ = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprArith('a');
                }
                | 
                expression OR expression
                {
                Trace("expression OR expression");

                if($1->type != TYPE_BOOLEAN || $3->type != TYPE_BOOLEAN) yyerror("expr must be a boolean"); 

                $$ = new_variable(KIND_VARIABLE, TYPE_BOOLEAN);
                //if(!declaring) 
                CG_ExprArith('o');
                }
                ;

statements:     simple_statements
                |
                conditional_statement
                |
                loop_statement
                |
                func_proce_invocation
                ;

statements_list:    statements_list statements
                    |
                    statements;

conditional_blockOrStatements:  {
                                    /*++scope;
                                    ++level;
                                    symtable_list.push_back(SymbolTable());  */
                                }
                                simple_statements_list
                                {
                                    //--level;
                                }
                                |
                                block;

simple_statements_list: simple_statements_list simple_statements
                        |
                        simple_statements;
                               
simple_statements:  identifier ASSIGN expression semi
                    {
                        Trace("simple statement: assign");
                        Vartype *temp = symtableList_lookup(*$1, symtable_list, level);
                        //cout << "OK" << endl;
                        if(temp == NULL) yyerror("haven't declared before invocate");
                        if(temp->var_kind != KIND_VARIABLE) yyerror("this is not a variable / this kind can't be assigned");
                        if(((temp->type != TYPE_INT && temp->type != TYPE_REAL) || ($3->type != TYPE_INT && $3->type != TYPE_REAL)) && temp->type != $3->type) yyerror("the type of the identifier is not the same type as expr");
                        CG_StateAssign(*$1, *temp);
                    }
                    |
                    identifier LEFTBRACKETS expression RIGHTBRACKETS ASSIGN expression semi
                    {
                        Trace("simple statement: array assign");
                        Trace("array type");
                        Vartype *arr = symtableList_lookup(*$1, symtable_list, level);     
                        if(arr == NULL) yyerror("haven't declared");
                        if(arr->var_kind != KIND_VARIABLE) yyerror("not a variable");
                        if(arr->type != TYPE_ARRAY) yyerror("not array type");
                        if($3->type != TYPE_INT) yyerror("index must be a int");
                        if($3->var_val.int_val >= arr->var_val.array_val.size() || $3->var_val.int_val < 0) yyerror("index out of range");
                        if(arr->var_val.array_val[0].type != $3->type) yyerror("the type of the array is not the same as the type assigned");
                    }
                    |
                    PRINTLN 
                    {
                        CG_StatePrintBegin();
                    }
                    expression semi
                    {
                        Trace("println expr");
                        CG_StatePrintEnd(false, *$3);
                    }
                    |
                    PRINT 
                    {
                        CG_StatePrintBegin();
                    }
                    expression semi
                    {
                        Trace("print expr");
                        CG_StatePrintEnd(true, *$3);
                    }
                    |
                    READ identifier semi
                    {
                        Trace("read id");
                    }
                    |
                    RETURN semi
                    {
                        Trace("return");
                        fout << "\t\treturn" << endl;
                    }
                    |
                    RETURN expression semi
                    {
                        Trace("return expr");
                        fout << "\t\tireturn" << endl;
                    }
                    |
                    expression semi
                    {
                        Trace("expression");
                    }
                    ;

ifBegin:    
            {
                CG_StateIfBegin();
            }


conditional_statement:  IF LEFTPARENTHESES expression RIGHTPARENTHESES THEN ifBegin conditional_blockOrStatements END IF semi
                        {
                            Trace("conditional statement: if");           
                            if($3->type != TYPE_BOOLEAN) yyerror("expr is not a boolean");

                            CG_StateCondEnd(false);

                            //--level;
                            //if(Opt_P) symtable_dump(symtable_list, scope);
                            //if(symtable_list.size() > 1) symtable_list.pop_back();
                            //--scope;
                            //cout <<"condition level"<<level<<endl;   
                        }
                        |
                        IF LEFTPARENTHESES expression RIGHTPARENTHESES THEN ifBegin conditional_blockOrStatements ELSE 
                        {
                            CG_StateElseBegin();
                            //--level;
                        }
                        conditional_blockOrStatements END IF semi
                        {
                            Trace("conditional statement: if and else");      
                            if($3->type != TYPE_BOOLEAN) yyerror("expr is not a boolean");

                            CG_StateCondEnd(true);
                            //--level;
                            
                            //if(Opt_P) symtable_dump(symtable_list, scope);
                            //if(symtable_list.size() > 1) symtable_list.pop_back();
                            //if(symtable_list.size() > 1) symtable_list.pop_back();
                            //cout <<"condition level"<<level<<endl;              
                            //--scope;        
                        }
                        ;

loop_statement:     while_statement
                    |
                    for_statements
                    ;


/*  while boolean expr loop
    a block or simple statement end loop ; */

while_statement:    WHILE 
                    {
                        CG_StateLoopBegin();
                    }
                    LEFTPARENTHESES expression RIGHTPARENTHESES LOOP 
                    {
                        Trace("while statement");
                        if($4->type != TYPE_BOOLEAN) yyerror("expr is not a boolean"); 

                        CG_StateLoopExpr();
                        //++level;
                    }
                    conditional_blockOrStatements END LOOP semi
                    {
                        CG_StateLoopEnd();

                        //--level;
                        //if(Opt_P) symtable_dump(symtable_list, scope);
                        //if(symtable_list.size() > 1) symtable_list.pop_back();
                        //Trace("OUT");
                        //--scope;  
                    }
                    ;

/*  for ( identifier in num . . num ) loop a block or simple statement
    end loop ; */

for_statements:     FOR LEFTPARENTHESES identifier IN expression
                    {
                        Vartype *temp = symtableList_lookup(*$3, symtable_list, level);
                        if(temp == NULL) yyerror("id hasn't been defined");
                        if(temp->var_kind != KIND_VARIABLE) yyerror("this isn't a variable");
                        if(temp->type != TYPE_INT) yyerror("this isn't a integer");
                        if($5->var_kind != KIND_CONSTANT) yyerror("expr is not a cont");
                        if($5->type != TYPE_INT) yyerror("expr is not a int");
                        temp->var_val.int_val = $5->var_val.int_val;
                        CG_StateAssign(*$3, *temp); 

                        CG_StateLoopBegin();
                        CG_ExprVar(*temp);
                    }
                    PERIOD PERIOD expression RIGHTPARENTHESES LOOP 
                    {
                        Trace("For statement");
                        //++scope;
                        //symtable_list.push_back(SymbolTable());  
                        if($9->var_kind != KIND_CONSTANT) yyerror("expr is not a cont");
                        if($9->type != TYPE_INT) yyerror("expr is not a int");
                        if($5->var_val.int_val > $9->var_val.int_val) yyerror("the begin value must be less than the end value");

                        CG_ExprBool(3);
                        CG_StateLoopExpr();
                    }
                    conditional_blockOrStatements END LOOP semi
                    {
                        Vartype *temp = symtableList_lookup(*$3, symtable_list, level);
                        CG_StateLoop_ForEnd(*$3, *temp); 
                        CG_StateLoopEnd();

                        //--level;
                        //if(Opt_P) symtable_dump(symtable_list, scope);
                        //if(symtable_list.size() > 1) symtable_list.pop_back();
                    };

%%

int yyerror(string msg)
{
    cerr << msg << endl;
    exit(1);
}

int main(int argc, char **argv)
{
    /* open the source program file */
    if (argc != 2) 
    {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    else
    {
        yyin = fopen(argv[1], "r");         /* open input file */
        if(!yyin)
        {
            cerr << "Error opening the order file" << endl;
            exit(1);
        }
    }
    
    string fin = string(argv[1]);
    filename = fin.substr(0, fin.find_last_of("."));
    fout.open(filename + ".jasm");

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
    
    return 0;
}
