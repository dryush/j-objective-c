#ifndef SIMPLE_TREE_STRUCTS
#define SIMPLE_TREE_STRUCTS

enum OperationType 
{
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	ASSIGN,
	ADD_ASSIGN,
	SUB_ASSIGN,
	MUL_ASSIGN,
	DIV_ASSIGN,
	MOD_ASSIGN,
	LESS,
	LESS_OR_EQUAL,
	GREATER,
	GREATER_OR_EQUAL,
	EQUAL,
	NOT_EQUAL,
	LOGICAL_NOT,
	UPLUS,
	UMINUS,
	PREINC,
	POSTINC,
	PREDEC,
	POSTDEC,
	VALUE
};

enum DefaultType
{
	VOID,
	INT,
	FLOAT,
	CHAR,
	STRING,
	BOOL
};


struct Statements_List_st
{
	struct Statement_st *stmt;
	struct Statements_List_st *next;
};

struct Statement_st
{
	struct Expression_st *expr;
	struct While_statement *while_stmt;
	struct If_statement_st *if_stmt;
	struct Init_statement_st *init_stmt;
	struct Statements_List_st* stmt_list;
};

struct Expression_st
{
	enum OperationType type;
	struct Expression_st *left;
	struct Expression_st *right;
	char *identifier;
	int int_value;
	float float_value;
	char bool_value;
	char char_value;
	char *string_value;
};

struct While_statement_st
{
	struct Expression_st *condition;
	struct Statements_List_st *stmt_list;
};

struct If_statement_st
{
	struct Expression_st *condition;
	struct Statements_List_st *truth_stmt_list, *wrong_stmt_list;
};

struct Init_statement_st
{
	struct Type_st *type;
	char *variable;
	OperationType type;
	struct Expression_st *expr;
	struct Array_constant *array_constant;
};

struct Type_st
{
	struct Return_type_st *return_type;
	struct Array_type_st *arrayt_type;
};

struct Return_type_st
{
	DefaultType default_type;
	char *type_name;
	bool isPointer;
};

struct Array_type_st
{
	DefaultType default_type;
	char *type_name, *array_name;
	int size;
};

struct Enum_declaration_st
{
	char *identifier;
	struct Enumerator_list_st *enumerator_list;
};

struct Enumerator_list_st
{
	struct Enumerator_st *enumerator_st;
	struct Enumerator_list_st *enumerator_list;
};

struct Enumerator_st
{
	char *identifier;
	int value;
};

#include "tree_structs_class.h"
#include "tree_structs_func.h"

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