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

struct Program_st
{
	struct Statements_List_st *stmt_list;
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
	OperationType type;
	struct Expression_st *left;
	struct Expression_st *right;
	char *identifier;
	int int_value;
	float float_value;
	bool bool_value;
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
	struct Type_st* type;
};


struct Class_method_param_declaration_st* createClassMethodParamDeclaration( char* outerName, struct Type_st* type, char* innerName)
{
	struct Class_method_param_declaration_st* st = ( struct Class_method_param_declaration_st*) malloc( sizeof( struct Class_method_param_declaration_st));
	st->innerName = innerName;
	st->outerName = outerName;
	st->type = type;
	return st;
};

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
	 return st;
 }

struct Class_method_param_declaration_list_st* addToClassMethodParamDeclarationList(
  struct Class_method_param_declaration_list_st* root, struct Class_method_param_declaration_st* param )
{
	struct Class_method_param_declaration_list_st* last = root;
	while ( last->next != NULL )
	 	last = last->next;
	last->next = createClassMethodParamDeclarationList(param); 
	return root;
}
struct Class_method_param_declaration_list_st* addToFrontClassMethodParamDeclarationList(
  struct Class_method_param_declaration_list_st* root, struct Class_method_param_declaration_st* param )
{

	struct Class_method_param_declaration_list_st* newRoot = createClassMethodParamDeclarationList(param);
	newRoot->next = root;
	return newRoot;
}

enum Method_type_en{
	NON_STATIC,
	STATIC
};

struct Class_method_declaration_st 
{
	char* name;
	Type_st* returnType;
	Method_type_en methodType;
	struct Class_method_param_declaration_list_st* params;
};

struct Class_method_declaration_st* createMethodDeclaration(Method_type_en methodType, struct Type_st* returnType, char* name, struct Class_method_param_declaration_list_st* params){
	struct Class_method_declaration_st* st = (struct Class_method_declaration_st*) malloc (sizeof(struct Class_method_declaration_st));
	st->methodType = methodType;
	st->returnType = returnType;
	st->name = name;
	st->params = params;
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
	return st;
}

struct Class_methods_declaration_list_st* addToMethodsDeclarationList( 
  struct Class_methods_declaration_list_st* root, struct Class_method_declaration_st* method )
{
	struct Class_methods_declaration_list_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createMethodsDeclarationList(method);
	return root;
}

struct Class_methods_declaration_block_st
{
	enum Field_access_en access;
	struct Class_methods_declaration_list_st* list;
};

struct Class_methods_declaration_block_st* createClassMethodsDeclarationBlock(
  Field_access_en access, struct Class_methods_declaration_list_st* list)
{
	struct Class_methods_declaration_block_st* st = (struct Class_methods_declaration_block_st*) malloc (sizeof(struct Class_methods_declaration_block_st));
	st->access = access;
	st->list = list;
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
}

struct Class_methods_declaration_block_list_st* addToClassMethodsDeclarationBlockList(
  struct Class_methods_declaration_block_list_st* root, struct Class_methods_declaration_block_st* list )
{
	struct Class_methods_declaration_block_list_st* last = root;
	while( last->next != NULL )
		last = last->next;
	last->next = createClassMethodsDeclarationBlockList(list);
}

struct Class_invariant_declaration_st
{
	char* name;
	struct Type_st* type;
};

struct Class_invariant_declaration_st* createClassInvariantDeclaration( struct Type_st* type, char * name)
{
	struct Class_invariant_declaration_st* st = (struct Class_invariant_declaration_st*) malloc( sizeof(struct Class_invariant_declaration_st));
	st->name = name;
	st->type = type;
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
}

struct Class_invariants_declaration_list_st* addToClassInvariantsDeclarationList(
  struct Class_invariants_declaration_list_st* root, struct Class_invariant_declaration_st* invariant)
{
	struct Class_invariants_declaration_list_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createClassInvariantsDeclarationList(invariant);
	return root;
}

struct Class_invariants_declaration_block_st
{
	Field_access_en access;
	struct Class_invariants_declaration_list_st* list;
};

struct Class_invariants_declaration_block_st* createClassInvariantsDeclarationBlock(
  Field_access_en access, struct Class_invariants_declaration_list_st* list )
{
	struct Class_invariants_declaration_block_st* st = (struct Class_invariants_declaration_block_st*) malloc(sizeof(struct Class_invariants_declaration_block_st));
	st->access = access;
	st->list = list;
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
}

struct Class_invariants_declaration_block_list_st* addToClassInvariantsDeclarationBlockList(
  struct Class_invariants_declaration_block_list_st* root, struct Class_invariants_declaration_block_st* list )
{
	struct Class_invariants_declaration_block_list_st* last = root;
	while( last->next != NULL )
		last = last->next;
	last->next = createClassInvariantsDeclarationBlockList(list);
}


struct Class_declaration_st
{
	char * name;
	char * parentName;
	struct Class_methods_declaration_block_list_st* methods_declaraion_list;
	struct Class_invariants_declaration_block_st* invariants_declaration_list;
};

struct Class_declaration_st* createClassDeclaration(
  char* name, char* parentName,
  struct Class_methods_declaration_block_list_st* methods_declaraion_list,
  struct Class_invariants_declaration_block_st* invariants_declaration_list )
{
	struct Class_declaration_st* st = (struct Class_declaration_st*)malloc(sizeof(struct Class_declaration_st));
	st->name = name;
	st->parentName = parentName;
	st->methods_declaraion_list = methods_declaraion_list;
	st->invariants_declaration_list = invariants_declaration_list;
	return st;
};

struct Class_method_impl_st {
	char* name;
	Type_st* returnType;
	Method_type_en methodType;
	Statement_st* body;
	struct Class_method_param_declaration_list_st* params;

};

struct Class_method_impl_st* createClassMethodImpl(
  struct Class_method_declaration_st* decl, Statement_st* stmt)
{
	struct Class_method_impl_st* st = (struct Class_method_impl_st*) malloc( sizeof(struct Class_method_impl_st));
	st->name = decl->name;
	st->methodType = decl->methodType;
	st->params = decl->params;
	st->returnType = decl->returnType;
	st->body = stmt;
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
}

struct Class_method_impl_list_st* addToClassMethodImplList( struct Class_method_impl_list_st* root, struct Class_method_impl_st* method)
{
	struct Class_method_impl_list_st* last = root;
	while( last->next != NULL)
		last = last->next;
	last->next = createClassMethodImplList(method);
	return root;
}

struct Class_impl_st
{
	char* name;
	struct Class_method_impl_list_st* methods;
}; 

struct Class_impl_st createClassImpl( char * name, struct Class_method_impl_list_st * methods)
{
	struct Class_impl_st* st = (struct Class_impl_st*) malloc( sizeof(struct Class_impl_st));
	st->name = name;
	st->methods = methods;
	return st;
}

#endif