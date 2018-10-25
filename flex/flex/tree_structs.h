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



struct Statement_st
{
	struct Expression_st *expr;
	struct While_statement *while_stmt;
	struct If_statement_st *if_stmt;
	struct Init_statement_st *init_stmt;
	struct Statements_List_st* stmt_list;
};

struct Statement_st *CreateExpressionStatement(struct Expression_st *expr)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->expr = expr;
	return cur;
}

struct Statement_st *CreateWhileStatement(struct While_statement_st *while_stmt)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->while_stmt = while_stmt;
	return cur;
}

struct Statement_st *CreateIfStatement(struct If_statement_st *if_stmt)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->if_stmt = if_stmt;
	return cur;
}

struct Statement_st *CreateInitStatement(struct Init_statement_st *init_stmt)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->init_stmt = init_stmt;
	return cur;
}

struct Statement_st *CreateCompoundStatement(struct Statements_List_st *stmt_list)
{
	struct Statement_st *cur = (struct Statement_st *)malloc(sizeof(struct Statement_st));
	cur->stmt_list = stmt_list;
	return cur;
}



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

struct Expression_st *CreateExpression(OperationType type, struct Expression_st *left, struct Expression_st *right)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->type = type;
	cur->left = left;
	cur->right = right;
	return cur;
}

struct Expression_st *CreatePreIncDecExpression(OperationType type, char *identifier)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->type = type;
	struct Expression_st *right = CreateIDExpression(char *identifier);
	cur->right = right;
	return cur;
}

struct Expression_st *CreatePostIncDecExpression(OperationType type, char *identifier)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->type = type;
	struct Expression_st *left = CreateIDExpression(char *identifier);
	cur->left = left;
	return cur;
}

struct Expression_st *CreateIDExpression(char *identifier)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->type = VALUE;
	cur->identifier = identifier;
	return cur;
}

struct Expression_st *CreateIntValueExpression(int int_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->type = VALUE;
	cur->int_value = int_value;
	return cur;
}

struct Expression_st *CreateFloatValueExpression(float float_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->type = VALUE;
	cur->float_value = float_value;
	return cur;
}

struct Expression_st *CreateBoolValueExpression(bool bool_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->type = VALUE;
	cur->bool_value = bool_value;
	return cur;
}

struct Expression_st *CreateCharValueExpression(char char_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->type = VALUE;
	cur->char_value = char_value;
	return cur;
}

struct Expression_st *CreateStringValueExpression(char *string_value)
{
	struct Expression_st *cur = (struct Expression_st *)malloc(sizeof(struct Expression_st));
	cur->type = VALUE;
	cur->string_value = string_value;
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
	OperationType assign_type;
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
		cur->assign_type = ASSIGN;
		cur->expr = expr;
	}
	return cur;
}

struct Init_statement_st *CreateAssignID(char *identifier, OperationType assignType, struct Expression_st *expr)
{
	struct Init_statement_st *cur = (struct Init_statement_st *)malloc(sizeof(struct Init_statement_st));
	cur->identifier = identifier;
	cur->assignType = assignType;
	cur->expr = expr;
	return cur;
}



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