#ifndef SIMPLE_TREE_STRUCTS
#define SIMPLE_TREE_STRUCTS

enum OperationType 
{
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_MOD,
	OP_ASSIGN,
	OP_ASSIGN_ARRAY,
	OP_ADD_ASSIGN,
	OP_SUB_ASSIGN,
	OP_MUL_ASSIGN,
	OP_DIV_ASSIGN,
	OP_MOD_ASSIGN,
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
	OP_PREINC,
	OP_POSTINC,
	OP_PREDEC,
	OP_POSTDEC,
	OP_VALUE
};

enum ExprType {
	OPERATION,
	METHOD_CALL,
	FUNC_CALL,
	ARRAY_ELEM_CALL
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
	TYPE_POINTER,
};



struct Expression_st
{
	enum ExprType exprType;
	enum OperationType operationType;
	struct Expression_st *left;
	struct Expression_st *right;
	struct Expr_list_st *arrayElems;
	char *identifier; /* имя / имя функции / имя вызываемого поля / имя вызываемого метода */
	int int_value;
	float float_value;
	char bool_value;
	char char_value;
	char *string_value;
	/* Вызов метода */
    struct Expression_st* object; /* объект у которого вызывается поле или метод */
	struct Method_call_arg_list_st* method_args;
	/* Вызов функции*/
    struct Func_call_arg_list_st* func_args;
	/* Вызов элемента массива*/
	struct Expression_st* array;
	struct Expression_st* index;
};

struct Expression_st *CreateExpression(OperationType operationType, struct Expression_st *left, struct Expression_st *right)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = OPERATION;
	cur->operationType = operationType;
	cur->left = left;
	cur->right = right;
	return cur;
}


struct Expression_st *CreateIDExpression(char *identifier)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = OPERATION;
	cur->operationType = OP_VALUE;
	cur->identifier = identifier;
	return cur;
}


struct Expression_st *CreatePreIncDecExpression(OperationType operationType, char *identifier)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = OPERATION;
	cur->operationType = operationType;
	struct Expression_st *right = CreateIDExpression( identifier);
	cur->right = right;
	return cur;
}

struct Expression_st *CreatePostIncDecExpression(OperationType operationType, char *identifier)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = OPERATION;
	cur->operationType = operationType;
	struct Expression_st *left = CreateIDExpression(identifier);
	cur->left = left;
	return cur;
}

struct Expression_st *CreateIntValueExpression(int int_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = OPERATION;
	cur->operationType = OP_VALUE;
	cur->int_value = int_value;
	return cur;
}

struct Expression_st *CreateFloatValueExpression(float float_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = OPERATION;
	cur->operationType = OP_VALUE;
	cur->float_value = float_value;
	return cur;
}

struct Expression_st *CreateBoolValueExpression(bool bool_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = OPERATION;
	cur->operationType = OP_VALUE;
	cur->bool_value = bool_value;
	return cur;
}

struct Expression_st *CreateCharValueExpression(char char_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = OPERATION;
	cur->operationType = OP_VALUE;
	cur->char_value = char_value;
	return cur;
}

struct Expression_st *CreateStringValueExpression(char *string_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->exprType = OPERATION;
	cur->operationType = OP_VALUE;
	cur->string_value = string_value;
	return cur;
}


struct Statements_List_st
{
	struct Statement_st *stmt;
	struct Statements_List_st *next;
};

struct Statements_List_st *AppendStatementToList(struct Statements_List_st *list, struct Statement_st *stmt)
{
	struct Statements_List_st *cur = (struct Statements_List_st *)malloc(sizeof(struct Statements_List_st));
	cur->next =0 ;
	list->next = cur;
	cur->stmt = stmt;
	return cur;
}

struct Statements_List_st *CreateStatementList(struct Statement_st *stmt)
{
	struct Statements_List_st *cur = (struct Statements_List_st *)malloc(sizeof(struct Statements_List_st));
	cur->next = 0;
	cur->stmt = stmt;
	return cur;
}


enum StatementType {
	STMT_WHILE,
	STMT_IF,
	STMT_EXPR,
	STMT_INIT,
	STMT_LIST,
	STMT_RETURN
	
};
struct Statement_st
{
	enum StatementType type;
	struct Expression_st *expr;
	struct While_statement_st *while_stmt;
	struct If_statement_st *if_stmt;
	struct Init_statement_st *init_stmt;
	struct Statements_List_st* stmt_list;
};

struct Statement_st* createReturnStatement(struct Expression_st* expr) {
	
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->type = STMT_RETURN;
	cur->expr = expr;
	return cur;

}

struct Statement_st *CreateExpressionStatement(struct Expression_st *expr)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->type = STMT_EXPR;
	cur->expr = expr;
	return cur;
}

struct Statement_st *CreateWhileStatement(struct While_statement_st *while_stmt)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->type = STMT_WHILE;
	cur->while_stmt = while_stmt;
	return cur;
}

struct Statement_st *CreateIfStatement(struct If_statement_st *if_stmt)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->type = STMT_IF;
	cur->if_stmt = if_stmt;
	return cur;
}

struct Statement_st *CreateInitStatement(struct Init_statement_st* init_stmt)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->type = STMT_INIT;
	cur->init_stmt = init_stmt;
	return cur;
}

struct Expression_st *CreateArrayInitStatement(struct Expression_st* left, struct Expr_list_st* elems)
{
	struct Expression_st *expr = (struct Expression_st*)malloc(sizeof(struct Expression_st));
	expr->exprType = OPERATION;
	expr->operationType = OP_ASSIGN_ARRAY;
	expr->left = left;
	expr->arrayElems = elems;
	return expr;
}

struct Statement_st *CreateCompoundStatement(struct Statements_List_st *stmt_list)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->stmt_list = stmt_list;
	return cur;
}





struct While_statement_st
{
	struct Expression_st *condition;
	struct Statements_List_st *stmt_list;
};

struct While_statement_st *CreateWhile(struct Expression_st *condition, struct Statements_List_st *stmt_list)
{
	struct While_statement_st *cur = (struct While_statement_st *)malloc(sizeof(struct While_statement_st));
	cur->condition = condition;
	cur->stmt_list = stmt_list;
	return cur;
}



struct If_statement_st
{
	struct Expression_st *condition;
	struct Statements_List_st *truth_stmt_list, *wrong_stmt_list;
};

struct If_statement_st *CreateIf(struct Expression_st *condition, struct Statements_List_st *truth_stmt_list,
								 struct Statements_List_st *wrong_stmt_list)
{
	struct If_statement_st *cur = (struct If_statement_st *)malloc(sizeof(struct If_statement_st));
	cur->condition = condition;
	cur->truth_stmt_list = truth_stmt_list;
	cur->wrong_stmt_list = wrong_stmt_list;
	return cur;
}



struct Init_statement_st
{
	struct Type_st *type;
	char *identifier;
	enum OperationType assign_type;
	struct Expression_st *expr;
	struct Array_constant *array_constant;
};

struct Init_statement_st *CreateInitID(struct Type_st *type, char *identifier, struct Expression_st *expr)
{
	struct Init_statement_st *cur = (struct Init_statement_st *)malloc(sizeof(struct Init_statement_st));
	cur->type = type;
	cur->identifier = identifier;
	if (expr != NULL)
	{
		cur->assign_type = OP_ASSIGN;
		cur->expr = expr;
	}
	return cur;
}

struct Init_statement_st *CreateAssignID(char *identifier, OperationType assignType, struct Expression_st *expr)
{
	struct Init_statement_st *cur = (struct Init_statement_st *)malloc(sizeof(struct Init_statement_st));
	cur->identifier = identifier;
	cur->assign_type = assignType;
	cur->expr = expr;
	return cur;
}



/*
struct Type_st
{
	struct Return_type_st *return_type;
	struct Array_type_st *arrayt_type;
};
*/

struct Type_st
{
	enum VarType type;
	char* name; /* Если свой тип*/
	struct Type_st* childType; /*Массив чего или указатель на что*/
};

struct Type_st* createType( enum VarType type, char * name, struct Type_st* child) {
	struct Type_st* st = (struct Type_st*)malloc(sizeof(struct Type_st));
	st->type = type;
	st->name = name;
	st->childType = child;
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
	return cur;
}

struct Enumerator_list_st
{
	struct Enumerator_st *enumerator;
	struct Enumerator_list_st *next;
};

struct Enumerator_list_st *AppendEnumeratorToList(struct Enumerator_list_st *list, struct Enumerator_st *enumerator)
{
	struct Enumerator_list_st *cur = (struct Enumerator_list_st *)malloc(sizeof(struct Enumerator_list_st));
	cur->next = 0;
	list->next = cur;
	cur->enumerator = enumerator;
	return cur;
}

struct Enumerator_list_st *CreateEnumeratorList(struct Enumerator_st *enumerator)
{
	struct Enumerator_list_st *cur = (struct Enumerator_list_st *)malloc(sizeof(struct Enumerator_list_st));
	cur->next = 0;
	cur->enumerator = enumerator;
	return cur;
}



struct Enumerator_st
{
	char *identifier;
	int value;
};

struct Enumerator_st *CreateEnumenator(char *identifier, int value)
{
	struct Enumerator_st *cur = (struct Enumerator_st *)malloc(sizeof(struct Enumerator_st));
	cur->identifier = identifier;
	cur->value = value;
	return cur;
}


#include "tree_structs_class.h"
#include "tree_structs_func.h"
#include "tree_structs_array.h"

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
	st->next = NULL;
	return st;
}

struct Program_st* addToProgram( struct Program_st* root, struct Extern_code_st* code)
{
	struct Program_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createProgram(code);
	return last;
}
#endif