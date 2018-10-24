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
	POSTDEC
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
#endif