%{
    /*
    ТУТ ПОДКЛЮЧЕНИЕ БИБЛИОТЕК, 
    ПРОТОТИПЫ ФУНКЦИЙ НА СИ
    ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ
    */
    #include <stdio.h>
	#include "tree_structs.h"
	#include "tree_structs_func.h"
    int yylex() { return getc(stdin); }
    void yyerror(char *s) {
        fprintf (stderr, "%s\n", s);
    }
%}

%union {
/*ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ*/
/*ОБЪЯВЛЕНИЕ СТРУКТУР*/
    int int_const;
    float float_const;
    char char_const;
	bool bool_const;
    char* string_const;
    char* id;
    void no_val;
	
	struct Statements_List_st_st *_stmt_list;
	struct Statement_st *_stmt;
	struct Expression_st *_expr;
	struct While_statement_st *_while_stmt;
	struct If_statement_st *_if_stmt;
	struct Init_statement_st *_init_stmt;
	struct Type_st *_type;
	struct Return_type_st *_return_type;
	struct Array_type_st *_array_type;
	struct Enum_declaration_st *_enum_decl;
	struct Enumerator_list_st *_enum_list;
	struct Enumerator_st *_enumerator;

	enum Field_access_en field_access_en;
	Class_method_param_declaration_st* class_method_param_declaration_st;
	Class_method_param_declaration_list_st* class_method_param_declaration_list_st;
	enum Method_type_en method_type_en;
	struct Class_method_declaration_st* class_method_declaration_st;
	struct Class_methods_declaration_list_st* class_methods_declaration_list_st;
	struct Class_methods_declaration_block_st* class_methods_declaration_block_st;
	struct Class_methods_declaration_block_list_st* class_methods_declaration_block_list_st;
	struct Class_invariant_declaration_st* class_invariant_declaration_st;
	struct Class_invariants_declaration_list_st* class_invariants_declaration_list_st;
	struct Class_invariants_declaration_block_st* class_invariants_declaration_block_st;
	struct Class_invariants_declaration_block_list_st* class_invariants_declaration_block_list_st;
	struct Class_declaration_st* class_declaration_st;
	struct Class_method_impl_st* class_method_impl_st;
	struct Class_method_impl_list_st* class_method_impl_list_st;
	struct Class_impl_st* class_impl_st;

	struct Func_arg_st* func_arg_st;
	struct Func_arg_list_st* func_arg_list_st;
	struct Func_declaration_st* func_declaration_st;
	struct Func_impl_st* func_impl_st;
	struct Func_call_arg_list_st* func_call_arg_list_st;
	struct Func_call_st* func_call_st;


}

%error-verbose

/*%type <Название структуры из union> название (работает это тип typedef и define) */


//%token Название токена, который возвращает FLEX

%token <int_const> INT_CONST
%token <float_const> FLOAT_CONST
%token <char_const> CHAR_CONST
%token <bool_const> BOOL_CONST
%token <string_const> STRING_CONST
%token <id> ID

%type <_stmt_list> stmt_list
%type <_stmt_list> stmt_list_or_empty
%type <_stmt> stmt
%type <_stmt> compound_stmt
%type <_expr> expr
%type <_while_stmt> while_stmt
%type <_if_stmt> if_stmt
%type <_init_stmt> init_stmt
%type <_type> type
%type <_return_type> RETURN
%type <_array_type> array_type
%type <_enum_decl> enum_declaration
%type <_enum_list> enumerator_list
%type <_enumerator> enumerator

%type <field_access_en> class_fields_access
%type <class_invariant_declaration_st> class_invariant_declaration
%type <class_invariants_declaration_list_st> class_invariants_declarations
%type <class_invariants_declaration_block_st> class_invariant_declaration_with_access
%type <class_invariants_declaration_block_list_st> class_invariant_declaration_with_access_list 
%type <class_invariants_declaration_block_list_st> class_invariants_declaration
%type <class_method_param_declaration_st> class_method_first_param 
%type <class_method_param_declaration_st> class_method_other_param_named
%type <class_method_param_declaration_list_st> class_method_other_params_named
%type <class_method_param_declaration_list_st> class_method_params_nonamed
%type <class_method_param_declaration_list_st> class_method_all_params 
%type <class_method_param_declaration_list_st> class_method_params
%type <class_method_declaration_st> class_method_declaration
%type <class_method_declaration_st> class_method
%type <class_methods_declaration_list_st> class_methods_declaration
%type <class_methods_declaration_block_st> class_methods_declaration_with_access
%type <class_methods_declaration_block_list_st> class_methods_declaration_with_access_list
%type <class_methods_declaration_block_list_st> class_methods_declaration_or_empty
%type <class_declaration_st> class_declaration
%type <class_method_impl_st> class_method_implementation
%type <class_method_impl_list_st> class_methods_implementation
%type <class_method_impl_list_st> class_methods_implementation_or_empty
%type <class_impl_st> class_implementation

%type <func_arg_st> func_arg
%type <func_arg_list_st> func_args
%type <func_arg_list_st> func_args_or_empty
%type <func_declaration_st> func_header
%type <func_declaration_st> func_declaration
%type <func_impl_st> func_implementation
%type <func_call_arg_list_st> func_call_args
%type <func_call_st> func_call



%token WHILE
%token IF
%token ELSE
%token END
%token EXTERN
%token IMPLEMENTATION INTERFACE PUBLIC PROTECTED PRIVATE
%token RETURN
%token INC
%token DEC
%token ENUM
%token INT
%token FLOAT
%token STRING
%token CHAR
%token BOOL
%token VOID

// СПИСОК ПРИОРИТЕТОВ ОПЕРАЦИЙ
%left ','
%right '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left OR
%left AND
%left EQUAL NOT_EQUAL
%left '<' LESS_OR_EQUAL '>' GREATER_OR_EQUAL
%left '-' '+'
%left '*' '/' '%'
%right PREINC PREDEC UMINUS UPLUS '!' POINTER 
%left POSTINC POSTDEC '.' ARROW
%left '['
%nonassoc ')' ']'
 
%%
// ТУТ ПРАВИЛА
extern_code: func_declaration 
	| func_implementation
    | class_declaration 
	| class_implementation
	| enum_declaration
	;
	
prog: extern_code 
    | prog extern_code 
    ;

stmt_list: stmt_list stmt { $$ = AppendStatementToList($1, $2); }
    | stmt { $$ = CreateStList($1); }
    ;

stmt_list_or_empty: stmt_list { $$ = $1; }
    | /* empty */ { $$ = NULL; }
    ;

stmt: RETURN expr ';' 
	| RETURN ';'
	| expr ';' 			{ $$ = CreateStatement($1, NULL, NULL, NULL, NULL); }
	| while_stmt 		{ $$ = CreateStatement(NULL, $1, NULL, NULL, NULL); }
	| if_stmt 			{ $$ = CreateStatement(NULL, NULL, $1, NULL, NULL); }
	| init_stmt ';' 	{ $$ = CreateStatement(NULL, NULL, NULL, $1, NULL); }
	| compound_stmt		{ $$ = $1; }
    ;

compound_stmt: '{' stmt_list_or_empty '}' { $$ = CreateStatement(NULL, NULL, NULL, NULL, $2); }
    ;

if_stmt: IF '(' expr ')' stmt 
    | IF '(' expr ')' stmt ELSE stmt 
    ;
	
while_stmt: WHILE '(' expr ')' stmt 
	;
	
init_stmt: ID assign_operator expr 
	| ID assign_operator array_constant 
	| array_elem_call assign_operator expr 
	| type ID '=' expr 
	| array_type '=' array_constant  
	| array_type 
	;

assign_operator: '='
	| ADD_ASSIGN
	| SUB_ASSIGN
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	;
	
default_type:  INT
	| FLOAT
	| STRING
	| CHAR
	| BOOL
	;

custom_type: ID '*' %prec POINTER
	;

array_type: default_type '*' %prec POINTER
	| custom_type '*' %prec POINTER 
	;
	
type: default_type
	| custom_type
	| array_type
	;

expr: expr '+' expr 				{ $$ = CreateExpression(ADD, $1, $3); }
    | expr '-' expr 				{ $$ = CreateExpression(SUB, $1, $3); }
    | expr '*' expr 				{ $$ = CreateExpression(MUL, $1, $3); }
    | expr '/' expr 				{ $$ = CreateExpression(DIV, $1, $3); }
	| expr '%' expr 				{ $$ = CreateExpression(MOD, $1, $3); }
	| expr '=' expr 				{ $$ = CreateExpression(ASSIGN, $1, $3); }
	| expr '<' expr 				{ $$ = CreateExpression(LESS, $1, $3); }
	| expr LESS_OR_EQUAL expr 		{ $$ = CreateExpression(LESS_OR_EQUAL, $1, $3); }
	| expr '>' expr 				{ $$ = CreateExpression(GREATER, $1, $3); }
	| expr GREATER_OR_EQUAL expr 	{ $$ = CreateExpression(GREATER_OR_EQUAL, $1, $3); }
	| expr EQUAL expr 				{ $$ = CreateExpression(EQUAL, $1, $3); }
	| expr NOT_EQUAL expr    		{ $$ = CreateExpression(NOT_EQUAL, $1, $3); }
    | '!' expr						{ $$ = CreateExpression(LOGICAL_NOT, $2, NULL); }
    | '+' expr %prec UPLUS			{ $$ = CreateExpression(UPLUS, $2, NULL); }
    | '-' expr %prec UMINUS			{ $$ = CreateExpression(UMINUS, $2, NULL); }
	| INC ID %prec PREINC			{ $$ = CreatePreIncDecExpression(PREINC, $2); }
	| DEC ID %prec PREDEC			{ $$ = CreatePreIncDecExpression(PREDEC, $2); }
	| ID INC %prec POSTINC			{ $$ = CreatePostIncDecExpression(POSTINC, $1); }
	| ID DEC %prec POSTDEC			{ $$ = CreatePostIncDecExpression(POSTDEC, $1); }
    | '(' expr ')' 					{ $$ = $2; }
	| ID 							{ $$ = CreateIDExpression($1); }
    | INT_CONST 					{ $$ = CreateIntValueExpression($1); }
	| FLOAT_CONST 					{ $$ = CreateFloatValueExpression($1); }
	| BOOL_CONST					{ $$ = CreateBoolValueExpression($1); }
	| CHAR_CONST					{ $$ = CreateCharValueExpression($1); }
	| STRING_CONST 					{ $$ = CreateStringValueExpression($1); }
    | method_call
    | array_elem_call
    | invariant_call
	| func_call
    ;

enum_declaration: ENUM ID '{' enumerator_list '}'
	;

enumerator_list: enumerator_list ',' enumerator
	| enumerator
	;

enumerator: ID 
	| ID '=' INT_CONST
	;
	
	
/* Пример объявления класса

@interface Complex : NSObject
	{
		double _re; //инвариант для действительной части
		double _im; //инвариант для мнимой части
		NSString *_format; //строка формата для метода description
	}
	- (id)initWithRe: (double)re andIm: (double)im; //специализированный конструктор
	+ (Complex *)complexWithRe: (double)re andIm: (double)im; //метод класса для одноэтапного создания объекта
	- (Complex *)add: (Complex *)other; //метод для сложения
	- (Complex *)sub: (Complex *)other; //метод для вычетания
	- (NSString *)format; //метод доступа к _format
	- (void)setFormat: (NSString *)format; //метод установки _format
	- (double)re; //остальные методы доступа к действительной и мнимой частям
	- (void)setRe: (double)re;
	- (double)im;
	- (void)setIm: (double)im;
@end

*/

class_fields_access: PUBLIC { $$ = A_PUBLIC; } 
	| PROTECTED { $$ = A_PROTECTED; }
	| PRIVATE	{ $$ = A_PRIVATE; }
	;

class_invariant_declaration: type ID ';' { $$ = createClassInvariantDeclaration($1, $2); }
	;

class_invariants_declarations: class_invariant_declaration 		{ $$ = createClassInvariantsDeclarationList($1); }
    | class_invariants_declarations class_invariant_declaration	{ $$ = addToClassInvariantsDeclarationList($1, $2); }
	;

class_invariant_declaration_with_access:
	  class_fields_access class_invariants_declarations { $$ = createClassInvariantsDeclarationBlock($1, $2); }
	| class_invariants_declarations { $$ = createClassInvariantsDeclarationBlock(A_NOT_SET, $1); }
	;

class_invariant_declaration_with_access_list: 
	  class_invariant_declaration_with_access { $$ = createClassInvariantsDeclarationBlockList($1); }
	| class_invariant_declaration_with_access_list class_invariant_declaration_with_access { $$ = addToClassInvariantsDeclarationBlockList($1, $2); }
	;

class_invariants_declaration: '{' '}' 	{ $$ = NULL; }
    | '{' class_invariant_declaration_with_access_list '}' { $$ = $2; }
	;

class_method_first_param: '(' type ')' ID { $$ = createClassMethodParamDeclaration( NULL, $2, $4 );}
	;
	
/*Параметры, начиная со второго могут либо все объявляться с именем 
	Либо все без имени, подобно первому аргументу
*/

class_method_other_param_named: ID ':' '(' type ')' ID { $$ = createClassMethodParamDeclaration($1, $4, $6); }
	;

class_method_other_params_named: class_method_other_param_named  { $$ = createClassMethodParamDeclarationList($1); }
	| class_method_other_params_named class_method_other_param_named { $$ = addToClassMethodParamDeclarationList($1, $2); }
	;

class_method_params_nonamed: class_method_first_param { $$ = createClassMethodParamDeclarationList($1); }
	| class_method_params_nonamed class_method_first_param { $$ = addToClassMethodParamDeclarationList($1, $2); }
	;
	

class_method_all_params: class_method_first_param class_method_other_params_named { $$ = addToFrontClassMethodParamDeclarationList($2, $1); }
	| class_method_params_nonamed {$$ = $1; }
	;
	
/*Список параметров метода может быть пустым */
class_method_params: class_method_all_params {$$ = $1; }
	| /*Пусто*/	{$$ = NULL; }
	;
	
/*Объявление метода без завершающей ';', чтоб переиспользовать в реализации метода */
/*
-|+ (<тип возвращаемого значения>) основнаяЧастьИмениМетода
[ : (<тип первого параметра>)имяПервогоФормальногоПараметра
[ [дополнительнаяЧастьИмениМетода] : (<тип второго параметра>)имяВторогоФормальногоПараметра]
… ]
*/

class_method: '-' '(' type ')' ID ':' class_method_params { $$ = createMethodDeclaration(NON_STATIC, $3, $5, $7);}
    | '+' '(' type ')' ID ':' class_method_params { $$ = createMethodDeclaration(STATIC, $3, $5, $7);}
    | '-' '(' type ')' ID { $$ = createMethodDeclaration(NON_STATIC, $3, $5, NULL);}
    | '+' '(' type ')' ID { $$ = createMethodDeclaration(STATIC, $3, $5, NULL);}
    ;

class_method_declaration: class_method ';' { $$ = $1; }
    ;
	
/*Список методов может быть пустым */

class_methods_declaration: class_method_declaration 		{ $$ = createMethodsDeclarationList( $1); }
    | class_methods_declaration class_method_declaration	{ $$ = addToMethodsDeclarationList( $1, $2); }
    ;


class_methods_declaration_with_access:  class_methods_declaration { $$ = createClassMethodsDeclarationBlock(A_NOT_SET, $1); }
	| class_fields_access class_methods_declaration { $$ = createClassMethodsDeclarationBlock( $1, $2); }
	;

class_methods_declaration_with_access_list: class_methods_declaration_with_access { $$ = createClassMethodsDeclarationBlockList( $1); }
	| class_methods_declaration_with_access_list class_methods_declaration_with_access { $$ = addToClassMethodsDeclarationBlockList( $1, $2); }
	;

class_methods_declaration_or_empty: class_methods_declaration_with_access_list { $$ = $1; }
    | /* empty */	{$$ = NULL; }
    ;

class_declaration: INTERFACE ID ':' ID class_invariants_declaration class_methods_declaration_or_empty END { $$ = createClassDeclaration($2, $4, $5, $6); }
	|  INTERFACE ID class_invariants_declaration class_methods_declaration_or_empty END { $$ = createClassDeclaration($2, NULL, $3, $4); }
    ;

class_method_implementation: class_method compound_stmt { $$ = createClassMethodImpl($1, $2); }
    ;
	
/*Список методов может быть пустым */
class_methods_implementation: class_method_implementation { $$ = createClassMethodImplList($1); }
    | class_methods_implementation class_method_implementation { $$ = addToClassMethodImplList($1, $2); }
    ;
	
class_methods_implementation_or_empty: class_methods_implementation {$$ = $1; }
    | /* empty */	{$$ = NULL; }
    ;

class_implementation: IMPLEMENTATION ID class_methods_implementation_or_empty END {} { $$ = createClassImpl($2, $3); }
	;
	
/*ВЫЗОВ МЕТОДА*/
/*Аргументы могут быть именованными и нет, первый аргумент вегда без имени */
method_call_noname_arg: ':' expr
    ;  

method_call_name_arg: ID ':' expr
    ;

method_call_noname_args: method_call_noname_arg
    | method_call_noname_args method_call_noname_arg
    ;

method_call_name_args: method_call_name_arg
    | method_call_name_args method_call_name_arg
    ;

/*Список аргументов может быть пустым */
method_call_args: method_call_noname_arg method_call_name_args
    | method_call_noname_args
    ;

method_call_args_or_empty: method_call_args
    | /*empty*/
    ;


/* [receiver methodWithFirstArgument: 10 andSecondArgument: 20]; */
method_call: '['ID ID method_call_args_or_empty']'
    ;

/*ОБРАЩЕНИЕ К ПОЛЮ*/
invariant_call: expr ARROW ID
    ;
	
/*МАССИВЫ */
array_elems: expr 
    | array_elems ',' expr
    ;

array_elems_or_empty: array_elems 
    | /* empty */
    ;

array_constant: '{' array_elems_or_empty '}'
    ;

array_elem_call: expr '[' expr ']'
    ;

/*ФУНКЦИИ */
func_arg: type ID { $$ =  createFuncArg($1, $2);}
    ;

func_args: func_arg 		{ $$ = createFuncArgList($1); }
    | func_args func_arg	{ $$ = addToFuncArgList($1, $2); }
    ;

func_args_or_empty: func_args	{ $$ = $1; }
    | /* empty */				{ $$ = NULL; }
    ;

func_header: type ID '(' func_args_or_empty ')' { $$ = createFuncDeclaration($1, $2, $4); }
    ;

func_declaration: func_header ';' { $$ = $1; }
    ;

func_implementation: func_header compound_stmt { $$ = createFuncImpl($1, $2);}
    ;

func_call_args: expr		{ $$ = createFuncCallArgsList($1);}
	| func_call_args ',' expr { $$ = addToFuncCallArgList($1, $3);}
	;

func_call: ID '(' func_call_args ')' { $$ = createFuncCall($1, $3); }
	| ID '(' ')'	{ $$ = createFuncCall($1, NULL); }
	;

	
	
%%



struct Statements_List_st *AppendStatementToList(struct Statements_List_st *list, struct Statement_st *stmt)
{
	struct Statements_List_st *cur = (struct Statements_List_st *)malloc(sizeof(struct Statements_List_st));
	cur->next =0 ;
	list->next = cur;
	cur->stmt = stmt;
	return cur;
}

struct Statements_List_st *CreateStList(struct Statement_st *stmt)
{
	struct Statements_List_st *cur = (struct Statements_List_st *)malloc(sizeof(struct Statements_List_st));
	cur->next = 0;
	cur->stmt = stmt;
}

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