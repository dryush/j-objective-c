#ifndef TREE_STRUCTS_H
#define TREE_STRUCTS_H

#include <stdlib.h>

enum OperationType 
{
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_MOD,
	OP_ASSIGN,
	OP_ASSIGN_ARRAY,
	OP_LESS,
	OP_LESS_OR_EQUAL,
	OP_GREATER,
	OP_GREATER_OR_EQUAL,
	OP_EQUAL,
	OP_NOT_EQUAL,
	OP_LOGICAL_NOT,
	OP_AND,
	OP_OR,
	OP_UPLUS,
	OP_UMINUS,
	OP_VALUE
};

enum ExprType {
	EXPR_OPERATION,
	EXPR_METHOD_CALL,
	EXPR_FUNC_CALL,
	EXPR_ARRAY_ELEM_CALL
};

enum VarType
{
	TYPE_VOID,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_CHAR,
	TYPE_STRING,
	TYPE_BOOL,
	TYPE_CUSTOM,
	TYPE_POINTER
};

struct Type_st;
struct Expression_st;
struct Expr_list_st;
struct Statement_st;
struct Statements_List_st;
struct Enum_declaration_st;
struct Enumerator_list_st;
struct Enumerator_st;
struct Class_method_param_declaration_st;
struct Class_method_param_declaration_list_st;
struct Class_method_declaration_st;
struct Class_methods_declaration_list_st;
struct Class_methods_declaration_block_st;
struct Class_methods_declaration_block_list_st;
struct Class_method_impl_st;
struct Class_invariant_declaration_st;
struct Class_invariants_declaration_list_st;
struct Class_invariants_declaration_block_st;
struct Class_invariants_declaration_block_list_st;
struct Class_declaration_st;
struct Class_declaration_st;
struct Class_impl_st;
struct Method_call_arg_st;
struct Method_call_arg_list_st;
struct Func_arg_st;
struct Func_arg_list_st;
struct Func_declaration_st;
struct Func_impl_st;
struct Func_call_arg_list_st;
struct Extern_code_st;
struct Program_st;

struct Expression_st *CreateExpression(enum OperationType operationType, struct Expression_st *left, struct Expression_st *right);
struct Expression_st *CreateIDExpression(char *identifier);
struct Expression_st *CreateIntValueExpression(int int_value);
struct Expression_st *CreateFloatValueExpression(double float_value);
struct Expression_st *CreateBoolValueExpression(char bool_value);
struct Expression_st *CreateStringValueExpression(char *string_value);
struct Statements_List_st *AppendStatementToList(struct Statements_List_st *list, struct Statement_st *stmt);
struct Statements_List_st *CreateStatementList(struct Statement_st *stmt);
struct Statement_st* CreateCompoundStatement(struct Statements_List_st* stmt_list);
struct Statement_st* CreateReturnStatement(struct Expression_st* expr);
struct Statement_st *CreateExpressionStatement(struct Expression_st *expr);
struct Statement_st *CreateWhileStatement(struct Expression_st *condition, struct Statement_st *stmt);
struct Statement_st *CreateIfStatement(struct Expression_st *condition, struct Statement_st *truth_stmt,
								 	   struct Statement_st *wrong_stmt);
struct Statement_st* CreateVarDeclWithInit(struct Type_st *var_type, char *identifier, struct Expression_st *expr);
struct Expression_st *CreateArrayInitStatement(struct Expression_st* left, struct Expr_list_st* elems);
struct Type_st* createType( enum VarType vartype, char * name, struct Type_st* child);								   
struct Enum_declaration_st *CreateEnumDeclaration(char *identifier, struct Enumerator_list_st *enumerator_list);
struct Enumerator_list_st *AppendEnumeratorToList(struct Enumerator_list_st *list, struct Enumerator_st *enumerator);
struct Enumerator_list_st *CreateEnumeratorList(struct Enumerator_st *enumerator);
struct Enumerator_st *CreateEnumenator(char *identifier, int value);
struct Class_method_param_declaration_st* createClassMethodParamDeclaration( char* outerName, struct Type_st* valtype, char* innerName);
struct Class_method_param_declaration_list_st* createClassMethodParamDeclarationList( 
  struct Class_method_param_declaration_st* param );
struct Class_method_param_declaration_list_st* addToClassMethodParamDeclarationList(
  struct Class_method_param_declaration_list_st* root, struct Class_method_param_declaration_st* param ); 
struct Class_method_param_declaration_list_st* addToClassMethodParamDeclarationList(
  struct Class_method_param_declaration_list_st* root, struct Class_method_param_declaration_st* param );
struct Class_method_param_declaration_list_st* addToFrontClassMethodParamDeclarationList(
  struct Class_method_param_declaration_list_st* root, struct Class_method_param_declaration_st* param );
struct Class_method_declaration_st* createMethodDeclaration(enum Method_type_en methodType, struct Type_st* returnType, 
  char* name, struct Class_method_param_declaration_list_st* params);
struct Class_methods_declaration_list_st* createMethodsDeclarationList( struct Class_method_declaration_st* method );
struct Class_methods_declaration_list_st* addToMethodsDeclarationList( 
  struct Class_methods_declaration_list_st* root, struct Class_method_declaration_st* method );  
struct Class_methods_declaration_block_st* createClassMethodsDeclarationBlock(
  enum Field_access_en access, struct Class_methods_declaration_list_st* list);
struct Class_methods_declaration_block_list_st* createClassMethodsDeclarationBlockList(
  struct Class_methods_declaration_block_st* list );
struct Class_methods_declaration_block_list_st* addToClassMethodsDeclarationBlockList(
  struct Class_methods_declaration_block_list_st* root, struct Class_methods_declaration_block_st* list );
struct Class_invariant_declaration_st* createClassInvariantDeclaration( struct Type_st* valtype, char * name);
struct Class_invariants_declaration_list_st* createClassInvariantsDeclarationList(
  struct Class_invariant_declaration_st* invariant);
struct Class_invariants_declaration_list_st* addToClassInvariantsDeclarationList(
  struct Class_invariants_declaration_list_st* root, struct Class_invariant_declaration_st* invariant);
struct Class_invariants_declaration_block_st* createClassInvariantsDeclarationBlock(
  enum Field_access_en access, struct Class_invariants_declaration_list_st* list );
struct Class_invariants_declaration_block_list_st* createClassInvariantsDeclarationBlockList(
  struct Class_invariants_declaration_block_st* list );
struct Class_invariants_declaration_block_list_st* addToClassInvariantsDeclarationBlockList(
  struct Class_invariants_declaration_block_list_st* root, struct Class_invariants_declaration_block_st* list );
struct Class_declaration_st* createClassDeclaration(
  char* name, char* parentName,
  struct Class_invariants_declaration_block_list_st* invariants_declaration_list,
  struct Class_methods_declaration_block_list_st* methods_declaraion_list);
struct Class_method_impl_st* createClassMethodImpl(
  struct Class_method_declaration_st* decl, struct Statement_st* stmt);
struct Class_method_impl_list_st* createClassMethodImplList(struct Class_method_impl_st* method);
struct Class_method_impl_list_st* addToClassMethodImplList( struct Class_method_impl_list_st* root, struct Class_method_impl_st* method);
struct Class_impl_st* createClassImpl( char * name, struct Class_method_impl_list_st * methods);
struct Expression_st* createInvariantCall(
  struct Expression_st* object, char * name );
struct Method_call_arg_st* createMethodCallArg(
  char * outer_name, struct Expression_st* value);  
struct Method_call_arg_list_st* createMethodCallArgList(
  struct Method_call_arg_st* arg);
struct Method_call_arg_list_st* addToMethodCallArgList(
	struct Method_call_arg_list_st * root, struct Method_call_arg_st* arg );
struct Method_call_arg_list_st* addToFrontMethodCallArgList(
	struct Method_call_arg_list_st * root, struct Method_call_arg_st* arg );
struct Expression_st* createMethodCall( 
  struct Expression_st * object, char * name,
  struct Method_call_arg_list_st* args);
struct Func_arg_st* createFuncArg(struct Type_st* valtype, char * name);
struct Func_arg_list_st* createFuncArgList( struct Func_arg_st* arg );
struct Func_arg_list_st* addToFuncArgList( struct Func_arg_list_st* root, struct Func_arg_st* arg);
struct Func_declaration_st* createFuncDeclaration(
  struct Type_st* return_type, char*name, struct Func_arg_list_st * args );
struct Func_impl_st* createFuncImpl(struct Func_declaration_st* decl, struct Statement_st* body);
struct Func_call_arg_list_st* createFuncCallArgsList(struct Expression_st* arg);
struct Func_call_arg_list_st* addToFuncCallArgList( 
  struct Func_call_arg_list_st* root, struct Expression_st* arg );
struct Expression_st* createFuncCall( char* name, struct Func_call_arg_list_st* args);
struct Expr_list_st* createExprList( struct Expression_st* elem);
struct Expr_list_st* addToExprList( 
    struct Expr_list_st* root, struct Expression_st * elem);
struct Expression_st* createArrayElemCall(
  struct Expression_st* array_exp, struct Expression_st* index );
struct Extern_code_st* createExternCode(
	struct Func_declaration_st* func_decl, struct Func_impl_st* function_impl,
	struct Class_declaration_st* class_decl, struct Class_impl_st* class_impl,
	struct Enum_declaration_st* enum_decl );
struct Program_st* createProgram(struct Extern_code_st* code);
struct Program_st* addToProgram( struct Program_st* root, struct Extern_code_st* code);	


struct Type_st
{
	enum VarType var_type;
	char* name; /* Если свой тип*/
	struct Type_st* childType; /*Массив чего или указатель на что*/
};
struct Expression_st
{
	enum ExprType exprType;
	enum OperationType operationType;
	enum VarType const_type;
	struct Expression_st *left;
	struct Expression_st *right;
	struct Expr_list_st *array_elems;
	char *identifier; /* имя / имя функции / имя вызываемого поля / имя вызываемого метода */
	int int_value;
	double float_value;
	char bool_value;
	char char_value;
	char *string_value;
	/* Вызов метода */
    struct Expression_st* object; /* объект у которого вызывается поле или метод */
	struct Method_call_arg_list_st* method_args;
	/* Вызов функции*/
    struct Func_call_arg_list_st* func_args;

};


struct Expr_list_st
{
    struct Expression_st * expr;
    struct Expr_list_st * next;
};

struct Expression_st *CreateExpression(enum OperationType operationType, struct Expression_st *left, struct Expression_st *right) {
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = EXPR_OPERATION;
	cur->operationType = operationType;
	cur->left = left;
	cur->right = right;
    printf("CreateExpression\n");
	return cur;
}


struct Expression_st *CreateIDExpression(char *identifier)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = EXPR_OPERATION;
	cur->operationType = OP_VALUE;
	cur->const_type = TYPE_CUSTOM;
	cur->identifier = identifier;
    printf("CreateIDExpression\n");
	return cur;
}

struct Expression_st *CreateIntValueExpression(int int_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = EXPR_OPERATION;
	cur->operationType = OP_VALUE;
	cur->const_type = TYPE_INT;
	cur->int_value = int_value;
    printf("CreateIntValueExpression\n");
	return cur;
}

struct Expression_st *CreateFloatValueExpression(double float_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = EXPR_OPERATION;
	cur->operationType = OP_VALUE;
	cur->const_type = TYPE_FLOAT;
	cur->float_value = float_value;
    printf("CreateFloatValueExpression\n");
	return cur;
}

struct Expression_st *CreateBoolValueExpression(char bool_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = EXPR_OPERATION;
	cur->operationType = OP_VALUE;
	cur->const_type = TYPE_BOOL;
	cur->bool_value = bool_value;
    printf("CreateBoolValueExpression\n");
	return cur;
}

struct Expression_st *CreateCharValueExpression(char char_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = EXPR_OPERATION;
	cur->operationType = OP_VALUE;
	cur->const_type = TYPE_CHAR;
	cur->char_value = char_value;
    printf("CreateCharValueExpression\n");
	return cur;
}

struct Expression_st *CreateStringValueExpression(char *string_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = EXPR_OPERATION;
	cur->operationType = OP_VALUE;
	cur->const_type = TYPE_STRING;
	cur->string_value = string_value;
    printf("CreateStringValueExpression\n");
	return cur;
}



enum StatementType 
{
	STMT_WHILE,
	STMT_IF,
	STMT_EXPR,
	STMT_VAR_DECL,
	STMT_RETURN,
	STMT_COMPOUND
};

struct Statement_st
{
	enum StatementType stmt_type;
	struct Expression_st *expr; /* в expr, return, var_decl */
	struct Expression_st *condition; /* while, if */
	struct Statement_st *truth_stmt; /* while, if */
	struct Statement_st *wrong_stmt; /* if */
	struct Statements_List_st *stmt_list; /* compound*/
	/* Для var_decl */
	struct Type_st *var_type; 
	char *identifier; 
	struct Array_constant *array_constant;
};

struct Statements_List_st
{
	struct Statement_st *stmt;
	struct Statements_List_st *next;
};

struct Statements_List_st *CreateStatementList(struct Statement_st *stmt)
{
	struct Statements_List_st *cur = (struct Statements_List_st *)malloc(sizeof(struct Statements_List_st));
	cur->next = 0;
	cur->stmt = stmt;
    printf("CreateStatementList\n");
	return cur;
}
struct Statements_List_st *AppendStatementToList(struct Statements_List_st *list, struct Statement_st *stmt)
{
	struct Statements_List_st* last = list;
	while ( last->next){
		last = last->next;
	}
	last->next = CreateStatementList(stmt);
    printf("AppendStatementToList\n");
	return list;
}


struct Statement_st* CreateCompoundStatement(struct Statements_List_st* stmt_list)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
    cur->stmt_type = STMT_COMPOUND;
	cur->stmt_list = stmt_list;
    printf("CreateCompoundStatement\n");
	return cur;
}

struct Statement_st* CreateReturnStatement(struct Expression_st* expr) 
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
    cur->stmt_type = STMT_RETURN;
	cur->expr = expr;
    printf("CreateReturnStatement\n");
	return cur;
}

struct Statement_st *CreateExpressionStatement(struct Expression_st *expr)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
    cur->stmt_type = STMT_EXPR;
	cur->expr = expr;
    printf("CreateExpressionStatement\n");
	return cur;
}

struct Statement_st *CreateWhileStatement(struct Expression_st *condition, struct Statement_st *stmt)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->stmt_type = STMT_WHILE;
	cur->condition = condition;
	cur->truth_stmt = stmt;
    printf("CreateWhileStatement\n");
	return cur;
}

struct Statement_st *CreateIfStatement(struct Expression_st *condition, struct Statement_st *truth_stmt,
								 	   struct Statement_st *wrong_stmt)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->stmt_type = STMT_IF;
	cur->condition = condition;
	cur->truth_stmt = truth_stmt;
	cur->wrong_stmt = wrong_stmt;
    printf("CreateIfStatement\n");
	return cur;
}

struct Statement_st* CreateVarDeclWithInit(struct Type_st *var_type, char *identifier, struct Expression_st *expr)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
    cur->stmt_type =  STMT_VAR_DECL;
	cur->var_type = var_type;
	cur->identifier = identifier;
	cur->expr = expr;
    printf("CreateVarDeclWithInit\n");
	return cur;
}
/* Нужно разобраться с объявлением массива */
struct Expression_st *CreateArrayInitStatement(struct Expression_st* left, struct Expr_list_st* elems)
{
	struct Expression_st *expr = (struct Expression_st*)malloc(sizeof(struct Expression_st));
	expr->exprType = EXPR_OPERATION;
	expr->operationType = OP_ASSIGN_ARRAY;
    expr->left = left;
    expr->array_elems = elems;
    printf("CreateArrayInitStatement\n");
	return expr;
}


struct Type_st* createType( enum VarType vartype, char * name, struct Type_st* child) {
	struct Type_st* st = (struct Type_st*)malloc(sizeof(struct Type_st));
	st->var_type = vartype;
	st->name = name;
	st->childType = child;
    printf("createType\n");
	return st; 
}



struct Enum_declaration_st
{
	char *identifier;
	struct Enumerator_list_st *enumerator_list;
};

struct Enum_declaration_st *CreateEnumDeclaration(char *identifier, struct Enumerator_list_st *enumerator_list)
{
	struct Enum_declaration_st *cur = (struct Enum_declaration_st *)malloc(sizeof(struct Enum_declaration_st));
	cur->identifier = identifier;
	cur->enumerator_list = enumerator_list;
    printf("CreateEnumDeclaration\n");
	return cur;
}

struct Enumerator_list_st
{
	struct Enumerator_st *enumerator;
	struct Enumerator_list_st *next;
};

struct Enumerator_list_st *AppendEnumeratorToList(struct Enumerator_list_st *list, struct Enumerator_st *enumerator)
{
	struct Enumerator_list_st *last = list;
	while (last->next) {
		last = last->next;
	}
	last->next = CreateEnumeratorList(enumerator);
    printf("AppendEnumeratorToList\n");
	return list;
}

struct Enumerator_list_st *CreateEnumeratorList(struct Enumerator_st *enumerator)
{
	struct Enumerator_list_st *cur = (struct Enumerator_list_st *)malloc(sizeof(struct Enumerator_list_st));
	cur->next = 0;
	cur->enumerator = enumerator;
    printf("CreateEnumeratorList\n");
	return cur;
}

struct Enumerator_st
{
	char *identifier;
	int value;
};

struct Enumerator_st *CreateEnumerator(char *identifier, int value)
{
	struct Enumerator_st *cur = (struct Enumerator_st *)malloc(sizeof(struct Enumerator_st));
	cur->identifier = identifier;
	cur->value = value;
    printf("CreateEnumenator\n");
	return cur;
}


enum Method_type_en{
	NON_STATIC,
	STATIC
};

/* КЛАССЫ */
enum Field_access_en
{
	A_PUBLIC,
	A_PROTECTED,
	A_PRIVATE,
	A_NOT_SET
};

struct Class_method_param_declaration_st
{
	/* Имя, которое будут использоваться внутри метода*/
	char* innerName;
	/* Имя, которое используется для ппередачи метода в параметр */
	char* outerName;
	struct Type_st* val_type;
};


struct Class_method_param_declaration_st* createClassMethodParamDeclaration( char* outerName, struct Type_st* valtype, char* innerName)
{
	struct Class_method_param_declaration_st* st = ( struct Class_method_param_declaration_st*) malloc( sizeof( struct Class_method_param_declaration_st));
	st->innerName = innerName;
	st->outerName = outerName;
    st->val_type = valtype;
    printf("createClassMethodParamDeclaration\n");
	return st;
}

struct Class_method_param_declaration_list_st 
{
	struct Class_method_param_declaration_st* param;
	struct Class_method_param_declaration_list_st* next;
};

struct Class_method_param_declaration_list_st* createClassMethodParamDeclarationList( 
  struct Class_method_param_declaration_st* param )
{
	struct  Class_method_param_declaration_list_st* st = (struct  Class_method_param_declaration_list_st*) malloc( sizeof(struct  Class_method_param_declaration_list_st));
	st->param = param;
	st->next = NULL;
    printf("createClassMethodParamDeclarationList\n");
	return st;
}

struct Class_method_param_declaration_list_st* addToClassMethodParamDeclarationList(
  struct Class_method_param_declaration_list_st* root, struct Class_method_param_declaration_st* param )
{
	struct Class_method_param_declaration_list_st* last = root;
	while ( last->next != NULL )
	 	last = last->next;
	last->next = createClassMethodParamDeclarationList(param);
    printf("addToClassMethodParamDeclarationList\n"); 
	return root;
}
struct Class_method_param_declaration_list_st* addToFrontClassMethodParamDeclarationList(
  struct Class_method_param_declaration_list_st* root, struct Class_method_param_declaration_st* param )
{

	struct Class_method_param_declaration_list_st* newRoot = createClassMethodParamDeclarationList(param);
	newRoot->next = root;
    printf("addToFrontClassMethodParamDeclarationList\n"); 
	return newRoot;
}

struct Class_method_declaration_st 
{
	char* name;
	struct Type_st* returnType;
	enum Method_type_en methodType;
	struct Class_method_param_declaration_list_st* params;
};

struct Class_method_declaration_st* createMethodDeclaration(enum Method_type_en methodType, struct Type_st* returnType, char* name, struct Class_method_param_declaration_list_st* params){
	struct Class_method_declaration_st* st = (struct Class_method_declaration_st*) malloc (sizeof(struct Class_method_declaration_st));
	st->methodType = methodType;
	st->returnType = returnType;
	st->name = name;
	st->params = params;
    printf("createMethodDeclaration\n"); 
	return st;
}


struct Class_methods_declaration_list_st
{
	struct Class_method_declaration_st* method;
	struct Class_methods_declaration_list_st* next;
};

struct Class_methods_declaration_list_st* createMethodsDeclarationList( struct Class_method_declaration_st* method )
{
	struct Class_methods_declaration_list_st* st = (struct Class_methods_declaration_list_st*) malloc(sizeof(struct Class_methods_declaration_list_st));
	st->method = method;
	st->next = NULL;
    printf("createMethodsDeclarationList\n");
	return st;
}

struct Class_methods_declaration_list_st* addToMethodsDeclarationList( 
  struct Class_methods_declaration_list_st* root, struct Class_method_declaration_st* method )
{
	struct Class_methods_declaration_list_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createMethodsDeclarationList(method);
    printf("addToMethodsDeclarationList\n");
	return root;
}

struct Class_methods_declaration_block_st
{
	enum Field_access_en access;
	struct Class_methods_declaration_list_st* list;
};

struct Class_methods_declaration_block_st* createClassMethodsDeclarationBlock(
  enum Field_access_en access, struct Class_methods_declaration_list_st* list)
{
	struct Class_methods_declaration_block_st* st = (struct Class_methods_declaration_block_st*) malloc (sizeof(struct Class_methods_declaration_block_st));
	st->access = access;
	st->list = list;
    printf("createClassMethodsDeclarationBlock\n");
	return st;
}

struct Class_methods_declaration_block_list_st
{
	struct Class_methods_declaration_block_st* list;
	struct Class_methods_declaration_block_list_st* next;
};

struct Class_methods_declaration_block_list_st* createClassMethodsDeclarationBlockList(
  struct Class_methods_declaration_block_st* list )
{
	struct Class_methods_declaration_block_list_st* st = (struct Class_methods_declaration_block_list_st*) malloc( sizeof(struct Class_methods_declaration_block_list_st));
	st->list = list;
	st->next = NULL;
    printf("createClassMethodsDeclarationBlockList\n");
	return st;
}

struct Class_methods_declaration_block_list_st* addToClassMethodsDeclarationBlockList(
  struct Class_methods_declaration_block_list_st* root, struct Class_methods_declaration_block_st* list )
{
	struct Class_methods_declaration_block_list_st* last = root;
	while( last->next != NULL )
		last = last->next;
	last->next = createClassMethodsDeclarationBlockList(list);
    printf("addToClassMethodsDeclarationBlockList\n");
	return root;
}

struct Class_invariant_declaration_st
{
	char* name;
	struct Type_st* val_type;
};

struct Class_invariant_declaration_st* createClassInvariantDeclaration( struct Type_st* valtype, char * name)
{
	struct Class_invariant_declaration_st* st = (struct Class_invariant_declaration_st*) malloc( sizeof(struct Class_invariant_declaration_st));
	st->name = name;
	st->val_type = valtype;
    printf("createClassInvariantDeclaration\n");
	return st;
}

struct Class_invariants_declaration_list_st
{
	struct Class_invariant_declaration_st* invariant;
	struct Class_invariants_declaration_list_st* next;
};

struct Class_invariants_declaration_list_st* createClassInvariantsDeclarationList(
  struct Class_invariant_declaration_st* invariant)
{
	struct Class_invariants_declaration_list_st* st = (struct Class_invariants_declaration_list_st*) malloc(sizeof(struct Class_invariants_declaration_list_st*));
	st->invariant = invariant;
	st->next = NULL;
    printf("createClassInvariantsDeclarationList\n");
	return st;
}

struct Class_invariants_declaration_list_st* addToClassInvariantsDeclarationList(
  struct Class_invariants_declaration_list_st* root, struct Class_invariant_declaration_st* invariant)
{
	struct Class_invariants_declaration_list_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createClassInvariantsDeclarationList(invariant);
    printf("addToClassInvariantsDeclarationList\n");
	return root;
}

struct Class_invariants_declaration_block_st
{
	enum Field_access_en access;
	struct Class_invariants_declaration_list_st* list;
};

struct Class_invariants_declaration_block_st* createClassInvariantsDeclarationBlock(
  enum Field_access_en access, struct Class_invariants_declaration_list_st* list )
{
	struct Class_invariants_declaration_block_st* st = (struct Class_invariants_declaration_block_st*) malloc(sizeof(struct Class_invariants_declaration_block_st));
	st->access = access;
	st->list = list;
    printf("createClassInvariantsDeclarationBlock\n");
	return st;
}

struct Class_invariants_declaration_block_list_st
{
	struct Class_invariants_declaration_block_st* list;
	struct Class_invariants_declaration_block_list_st* next;
};

struct Class_invariants_declaration_block_list_st* createClassInvariantsDeclarationBlockList(
  struct Class_invariants_declaration_block_st* list )
{
	struct Class_invariants_declaration_block_list_st* st = (struct Class_invariants_declaration_block_list_st*) malloc( sizeof(struct Class_methods_declaration_block_list_st));
	st->list = list;
	st->next = NULL;
    printf("createClassInvariantsDeclarationBlockList\n");
	return st;
}

struct Class_invariants_declaration_block_list_st* addToClassInvariantsDeclarationBlockList(
  struct Class_invariants_declaration_block_list_st* root, struct Class_invariants_declaration_block_st* list )
{
	struct Class_invariants_declaration_block_list_st* last = root;
	while( last->next != NULL )
		last = last->next;
	last->next = createClassInvariantsDeclarationBlockList(list);
    printf("addToClassInvariantsDeclarationBlockList\n");
	return root;
}


struct Class_declaration_st
{
	char * name;
	char * parentName;
	struct Class_methods_declaration_block_list_st* methods_declaraion_list;
	struct Class_invariants_declaration_block_list_st* invariants_declaration_list;
};

struct Class_declaration_st* createClassDeclaration(
  char* name, char* parentName,
  struct Class_invariants_declaration_block_list_st* invariants_declaration_list,
  struct Class_methods_declaration_block_list_st* methods_declaraion_list )
{
	struct Class_declaration_st* st = (struct Class_declaration_st*)malloc(sizeof(struct Class_declaration_st));
	st->name = name;
	st->parentName = parentName;
	st->methods_declaraion_list = methods_declaraion_list;
	st->invariants_declaration_list = invariants_declaration_list;
    printf("createClassDeclaration\n");
	return st;
};

struct Class_method_impl_st 
{
	char* name;
	struct Type_st* returnType;
	enum Method_type_en methodType;
	struct Statement_st* body;
	struct Class_method_param_declaration_list_st* params;

};

struct Class_method_impl_st* createClassMethodImpl(
  struct Class_method_declaration_st* decl, struct Statement_st* stmt)
{
	struct Class_method_impl_st* st = (struct Class_method_impl_st*) malloc( sizeof(struct Class_method_impl_st));
	st->name = decl->name;
	st->methodType = decl->methodType;
	st->params = decl->params;
	st->returnType = decl->returnType;
	st->body = stmt;
    printf("createClassMethodImpl\n");
	return st;
}

struct Class_method_impl_list_st
{
	struct Class_method_impl_st* method;
	struct Class_method_impl_list_st* next;
};

struct Class_method_impl_list_st* createClassMethodImplList(struct Class_method_impl_st* method)
{
	struct Class_method_impl_list_st* st = (struct Class_method_impl_list_st*)malloc(sizeof(struct Class_method_impl_list_st));
	st->method = method;
	st->next = NULL;
    printf("createClassMethodImplList\n");
	return st;
}

struct Class_method_impl_list_st* addToClassMethodImplList( struct Class_method_impl_list_st* root, struct Class_method_impl_st* method)
{
	struct Class_method_impl_list_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createClassMethodImplList(method);
    printf("addToClassMethodImplList\n");
	return root;
}

struct Class_impl_st
{
	char* name;
	struct Class_method_impl_list_st* methods;
}; 

struct Class_impl_st* createClassImpl( char * name, struct Class_method_impl_list_st * methods)
{
	struct Class_impl_st* st = (struct Class_impl_st*) malloc( sizeof(struct Class_impl_st));
	st->name = name;
	st->methods = methods;
    printf("createClassImpl\n");
	return st;
}

struct Expression_st* createInvariantCall(
  struct Expression_st* object, char * name )
{
    struct Expression_st* st = (struct Expression_st*) malloc(sizeof(struct Expression_st));
    st->identifier = name;
    st->object = object;
    printf("createInvariantCall\n");
    return st;
}

struct Method_call_arg_st
{
	char* outer_name;
	struct Expression_st* value;
};

struct Method_call_arg_st* createMethodCallArg(
  char * outer_name, struct Expression_st* value)
{
	struct Method_call_arg_st* st = (struct Method_call_arg_st*)malloc(sizeof(struct Method_call_arg_st));
	st->outer_name = outer_name;
	st->value = value;
    printf("createMethodCallArgs\n");
	return st;
}

struct Method_call_arg_list_st
{
	struct Method_call_arg_st* arg;
	struct Method_call_arg_list_st* next;
};

struct Method_call_arg_list_st* createMethodCallArgList(
  struct Method_call_arg_st* arg)
{
	struct Method_call_arg_list_st * st = (struct Method_call_arg_list_st*) malloc(sizeof(struct Method_call_arg_list_st));
	st->arg = arg;
	st->next = NULL;
    printf("createMethodCallArgList\n");
	return st;
}

struct Method_call_arg_list_st* addToMethodCallArgList(
	struct Method_call_arg_list_st * root, struct Method_call_arg_st* arg )
{
	struct Method_call_arg_list_st* last = root;
	while ( last->next != NULL)
		last = last->next;
	last->next = createMethodCallArgList(arg);
    printf("addToMethodCallArgList\n");
	return root; 
}

struct Method_call_arg_list_st* addToFrontMethodCallArgList(
	struct Method_call_arg_list_st * root, struct Method_call_arg_st* arg )
{
	struct Method_call_arg_list_st* newRoot = createMethodCallArgList(arg);
	newRoot->next = root;
    printf("addToFrontMethodCallArgList\n");
	return newRoot;
}

struct Expression_st* createMethodCall( 
  struct Expression_st * object, char * name,
  struct Method_call_arg_list_st* args)
{
	struct Expression_st * st = (struct Expression_st*) malloc(sizeof(struct Expression_st));
	st->method_args = args;
	st->identifier = name;
	st->object = object;
    printf("createMethodCall\n");
	return st;
}
struct Func_arg_st 
{
    struct Type_st* val_type;
    char* name;
};

struct Func_arg_st* createFuncArg(struct Type_st* valtype, char * name)
{
    struct Func_arg_st* st = (struct Func_arg_st*) malloc(sizeof(struct Func_arg_st));
    st->val_type = valtype;
    st->name = name;
    printf("createFuncArg\n");
    return st; 
}

struct Func_arg_list_st
{
    struct Func_arg_st* arg;
    struct Func_arg_list_st* next;
};

struct Func_arg_list_st* createFuncArgList( struct Func_arg_st* arg )
{
    struct Func_arg_list_st* st = (struct Func_arg_list_st*) malloc(sizeof(struct Func_arg_list_st));
    st->arg  = arg;
    st->next = NULL;
    printf("createFuncArgList\n");
    return st;
}

struct Func_arg_list_st* addToFuncArgList( struct Func_arg_list_st* root, struct Func_arg_st* arg) 
{
    struct Func_arg_list_st* last = root;
    while ( last->next != NULL )
        last = last->next;
    last->next = createFuncArgList( arg);
    printf("addToFuncArgList\n");
    return root;
}

struct Func_declaration_st
{
    struct Type_st * return_type;
    char* name;
    struct Func_arg_list_st* args;
};

struct Func_declaration_st* createFuncDeclaration(
  struct Type_st* return_type, char*name, struct Func_arg_list_st * args )
{
    struct Func_declaration_st * st = (struct Func_declaration_st*) malloc(sizeof(struct Func_declaration_st));
    st->return_type = return_type;
    st->name = name;
    st->args = args;
    printf("createFuncDeclaration\n");
    return st;
}

struct Func_impl_st
{
    struct Type_st * return_type;
    char* name;
    struct Func_arg_list_st* args;
    struct Statement_st* body;
};

struct Func_impl_st* createFuncImpl(struct Func_declaration_st* decl, struct Statement_st* body)
{
    struct Func_impl_st* st = (struct Func_impl_st*)malloc(sizeof(struct Func_impl_st));
    st->return_type = decl->return_type;
    st->name = decl->name;
    st->args = decl->args;
    st->body = body;
    printf("createFuncImpl\n");
    return st;
}

struct Func_call_arg_list_st
{
    struct Expression_st* arg;
    struct Func_call_arg_list_st* next;
};

struct Func_call_arg_list_st* createFuncCallArgsList(struct Expression_st* arg)
{
    struct Func_call_arg_list_st* st = (struct Func_call_arg_list_st*) malloc(sizeof(struct Func_call_arg_list_st));
    st->arg = arg;
    st->next = NULL;
    printf("createFuncCallArgsList\n");
    return st;
}

struct Func_call_arg_list_st* addToFuncCallArgList( 
  struct Func_call_arg_list_st* root, struct Expression_st* arg )
{
    struct Func_call_arg_list_st* last = root;
    while (last->next != NULL)
        last = last->next;
    last->next = createFuncCallArgsList(arg);
    printf("addToFuncCallArgList\n");
    return root;
}


struct Expression_st* createFuncCall( char* name, struct Func_call_arg_list_st* args)
{
    struct Expression_st* st = (struct Expression_st*) malloc ( sizeof(struct Expression_st));
    st->exprType = EXPR_FUNC_CALL;
    st->identifier = name;
    st->func_args = args;
    printf("createFuncCall\n");
    return st;
}

struct Expr_list_st* createExprList( struct Expression_st* elem)
{
    struct Expr_list_st* st = (struct Expr_list_st*) malloc(sizeof(struct Expr_list_st));
    st->expr = elem;
    st->next = NULL;
    printf("createExprList\n");
    return st;
}

struct Expr_list_st* addToExprList( 
    struct Expr_list_st* root, struct Expression_st * elem)
{
    struct Expr_list_st* last = root;
    while ( last->next != NULL)
        last = last->next;
    last->next = createExprList( elem);
    printf("addToExprList\n");
    return root;
}

struct Expression_st* createArrayElemCall(
  struct Expression_st* array_exp, struct Expression_st* index )
{
    struct Expression_st* st = (struct Expression_st*)malloc(sizeof(struct Expression_st));
    st->left = array_exp;
    st->right = index;
    printf("createArrayElemCall\n");
    return st;
}

struct Extern_code_st
{
	struct Func_declaration_st* func_decl;
	struct Func_impl_st* func_impl;
	struct Class_declaration_st* class_decl;
	struct Class_impl_st* class_impl;
	struct Enum_declaration_st* enum_decl;
};

struct Extern_code_st* createExternCode(
	struct Func_declaration_st* func_decl, struct Func_impl_st* function_impl,
	struct Class_declaration_st* class_decl, struct Class_impl_st* class_impl,
	struct Enum_declaration_st* enum_decl )
{
	struct Extern_code_st* st = (struct Extern_code_st*)malloc(sizeof(struct Extern_code_st));
	st->class_decl = class_decl;
	st->class_impl = class_impl;
	st->func_decl = func_decl;
	st->func_impl = function_impl;
	st->enum_decl = enum_decl;
    printf("createExternCode\n");
	return st;
}

struct Program_st
{
	struct Extern_code_st* code;
	struct Program_st* next;
};

struct Program_st* createProgram(struct Extern_code_st* code)
{
	struct Program_st* st = (struct Program_st*) malloc (sizeof(struct Program_st));
	st->code = code;
	st->next = 0;
    printf("createProgram\n");
	return st;
}

struct Program_st* addToProgram( struct Program_st* root, struct Extern_code_st* code)
{
	struct Program_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createProgram(code);
    printf("addToProgram\n");
	return root;
}
#endif TREE_STRUCTS_H