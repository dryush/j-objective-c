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

struct Program
{
	struct Statements_List *stmts;
};

struct Statements_List
{
	struct Statement *stmt;
	struct Statements_List *next;
};

struct Statement
{
	struct Expression *expr;
	struct While_statement *while_stmt;
	struct If_statement *if_stmt;
	struct Init_statement *init_stmt;
};

struct Expression
{
	OperationType type;
	struct Expression *left;
	struct Expression *right;
	char *identifier;
	int int_value;
	float float_value;
	bool bool_value;
	char char_value;
	char *string_value;
};

struct While_statement
{
	struct Expression *condition;
	struct Statements_List *stmt_list;
};

struct If_statement
{
	struct Expression *condition;
	struct Statements_List *truth_stmt_list, *wrong_stmt_list;
};

struct Init_statement
{
	struct Type *type;
	char *variable;
	OperationType type;
	struct Expression *expr;
	struct Array_constant *array_constant;
};

struct Type
{
	struct Return_type *return_type;
	struct Array_type *arrayt_type;
};

struct Return_type
{
	DefaultType default_type;
	char *type_name;
	bool isPointer;
};

struct Array_type
{
	DefaultType default_type;
	char *type_name, *array_name;
	int size;
};

struct Enum_declaration
{
	char *identifier;
	struct Enumerator_list *enumerator_list;
};

struct Enumerator_list
{
	struct Enumerator *enumerator;
	struct Enumerator_list *enumerator_list;
};

struct Enumerator
{
	char *identifier;
	int value;
};

/* КЛАССЫ */
enum Field_access_en{
	A_PUBLIC,
	A_PROTECTED,
	A_PRIVATE
};

struct Class_method_param_st
{
	char* name;
	struct Type* type;
};

struct Class_method_param_list_st {
	struct Class_method_param_st* param;
	struct Class_method_param_list_st* next;
};


struct Class_method_declaration_st 
{
	char* name;
	struct Class_method_param_list_st* params;
};

struct Class_methods_declaration_list_st
{
	struct Class_method_declaration_st* method;
	struct Class_methods_declaration_list_st* next;
};

struct Class_methods_declaration_block_st
{
	enum Field_access_en access;
	struct Class_methods_declaration_list_st* list;
};

struct Class_methods_declaration_block_list_st
{
	struct Class_methods_declaration_block_st* list;
	struct Class_methods_declaration_block_list_st* next;
};

struct Class_invariant_declaration_st
{
	char* name;
	struct Type* type;
};

struct Class_invariants_declaration_list_st
{
	struct Class_invariant_declaration_st* invariant;
	struct Class_invariants_declaration_list_st* next;
};

struct Class_invariants_declaration_block_st
{
	Field_access_en access;
	struct Class_invariants_declaration_list_st* list;
};

struct Class_declaration_st
{
	struct Class_methods_declaration_block_list_st* methods_declaraion_list;
	struct Class_invariants_declaration_block_st* invariants_declaration_list;
};
#endif