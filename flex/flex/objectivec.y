%{
    /*
    ТУТ ПОДКЛЮЧЕНИЕ БИБЛИОТЕК, 
    ПРОТОТИПЫ ФУНКЦИЙ НА СИ
    ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ
    */
    #include <stdio.h>
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
	
	struct Statements_List *_stmt_list;
	struct Statement *_stmt;
	struct Expression *_expr;
	struct While_statement *_while_stmt;
	struct If_statement *_if_stmt;
	struct Init_statement *_init_stmt;
	struct Type *_type;
	struct Return_type *_return_type;
	struct Array_type *_array_type;
	struct Enum_declaration *_enum_decl;
	struct Enumerator_list *_enum_list;
	struct Enumerator *_enumerator;
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
%type <_stmt> stmt
%type <_expr> expr
%type <_while_stmt> while_stmt
%type <_if_stmt> if_stmt
%type <_init_stmt> init_stmt
%type <_type> type
%type <_return_type> return
%type <_array_type> array_type
%type <_enum_decl> enum_declaration
%type <_enum_list> enumerator_list
%type <_enumerator> enumerator

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

stmt_list_or_empty: stmt_list
    | /* empty */
    ;

stmt: RETURN expr ';' 
	| RETURN ';'
	| expr ';' 			{ $$ = CreateStatement($1, NULL, NULL, NULL); }
	| while_stmt 		{ $$ = CreateStatement(NULL, $1, NULL, NULL); }
	| if_stmt 			{ $$ = CreateStatement(NULL, NULL, $1, NULL); }
	| init_stmt ';' 	{ $$ = CreateStatement(NULL, NULL, NULL, $1); }
	| compound_stmt
    ;

compound_stmt: '{' stmt_list_or_empty '}'
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

expr: expr '+' expr 				{ $$ = CreateExpression(ADD, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
    | expr '-' expr 				{ $$ = CreateExpression(SUB, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
    | expr '*' expr 				{ $$ = CreateExpression(MUL, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
    | expr '/' expr 				{ $$ = CreateExpression(DIV, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
	| expr '%' expr 				{ $$ = CreateExpression(MOD, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
	| expr '=' expr 				{ $$ = CreateExpression(ASSIGN, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
	| expr '<' expr 				{ $$ = CreateExpression(LESS, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
	| expr LESS_OR_EQUAL expr 		{ $$ = CreateExpression(LESS_OR_EQUAL, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
	| expr '>' expr 				{ $$ = CreateExpression(GREATER, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
	| expr GREATER_OR_EQUAL expr 	{ $$ = CreateExpression(GREATER_OR_EQUAL, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
	| expr EQUAL expr 				{ $$ = CreateExpression(EQUAL, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
	| expr NOT_EQUAL expr    		{ $$ = CreateExpression(NOT_EQUAL, $1, $3, NULL, NULL, NULL, NULL, NULL, NULL); }
    | '!' expr						{ $$ = CreateExpression(LOGICAL_NOT, $2, NULL, NULL, NULL, NULL, NULL, NULL, NULL); }
    | '+' expr %prec UPLUS			{ $$ = CreateExpression(UPLUS, $2, NULL, NULL, NULL, NULL, NULL, NULL, NULL); }
    | '-' expr %prec UMINUS			{ $$ = CreateExpression(UMINUS, $2, NULL, NULL, NULL, NULL, NULL, NULL, NULL); }
	| INC ID %prec PREINC			{ $$ = CreateExpression(PREINC, NULL, NULL, $2, NULL, NULL, NULL, NULL, NULL); }
	| DEC ID %prec PREDEC			{ $$ = CreateExpression(PREDEC, NULL, NULL, $2, NULL, NULL, NULL, NULL, NULL); }
	| ID INC %prec POSTINC			{ $$ = CreateExpression(POSTINC, NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL); }
	| ID DEC %prec POSTDEC			{ $$ = CreateExpression(POSTDEC, NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL); }
    | '(' expr ')' 					{ $$ = $2; }
	| ID 							{ $$ = CreateExpression(VALUE, NULL, NULL, $1, NULL, NULL, NULL, NULL, NULL); }
    | INT_CONST 					{ $$ = CreateExpression(VALUE, NULL, NULL, NULL, $1, NULL, NULL, NULL, NULL); }
	| FLOAT_CONST 					{ $$ = CreateExpression(VALUE, NULL, NULL, NULL, NULL, $1, NULL, NULL, NULL); }
	| BOOL_CONST					{ $$ = CreateExpression(VALUE, NULL, NULL, NULL, NULL, NULL, $1, NULL, NULL); }
	| CHAR_CONST					{ $$ = CreateExpression(VALUE, NULL, NULL, NULL, NULL, NULL, NULL, $1, NULL); }
	| STRING_CONST 					{ $$ = CreateExpression(VALUE, NULL, NULL, NULL, NULL, NULL, NULL, NULL, $1); }
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

class_fields_access: PUBLIC PROTECTED PRIVATE
	;

class_invariant_declaration: type ID ';'
	;

class_invariants_declarations: class_invariant_declaration 
    | class_invariants_declarations class_invariant_declaration
	;

class_invariant_declaration_with_access:
	  class_fields_access class_invariants_declarations 
	| class_invariants_declarations
	;

class_invariant_declaration_with_access_list: 
	  class_invariant_declaration_with_access
	| class_invariant_declaration_with_access_list class_invariant_declaration_with_access
	;

class_invariants_declaration: '{' '}'
    | '{' class_invariant_declaration_with_access_list '}'
	;

class_method_first_param: '(' type ')' ID
	;
	
/*Параметры, начиная со второго могут либо все объявляться с именем 
	Либо все без имени, подобно первому аргументу
*/

class_method_other_param_named: ID ':' '(' type ')' ID 
	;

class_method_other_params_named: class_method_other_params_named
	| class_method_other_params_named class_method_other_param_named
	;

class_method_params_nonamed: class_method_first_param
	| class_method_params_nonamed class_method_first_param
	;
	

class_method_all_params: class_method_first_param class_method_other_params_named
	| class_method_params_nonamed
	;
	
/*Список параметров метода может быть пустым */
class_method_params: class_method_all_params
	| /*Пусто*/
	;
	
/*Объявление метода без завершающей ';', чтоб переиспользовать в реализации метода */
/*
-|+ (<тип возвращаемого значения>) основнаяЧастьИмениМетода
[ : (<тип первого параметра>)имяПервогоФормальногоПараметра
[ [дополнительнаяЧастьИмениМетода] : (<тип второго параметра>)имяВторогоФормальногоПараметра]
… ]
*/

class_method: '-' '(' type ')' ID ':' class_method_params
    | '+' '(' type ')' ID ':' class_method_params
    | '-' '(' type ')' ID 
    | '+' '(' type ')' ID 
    ;

class_method_declaration: class_method ';'
    ;
	
/*Список методов может быть пустым */

class_methods_declaration: class_method_declaration
    | class_methods_declaration class_method_declaration
    ;


class_methods_declaration_with_access:  class_methods_declaration 
	| class_fields_access class_methods_declaration
	;

class_methods_declaration_with_access_list: class_methods_declaration_with_access
	| class_methods_declaration_with_access_list class_methods_declaration_with_access
	;


class_methods_declaration_or_empty: class_methods_declaration_with_access_list
    | /* empty */
    ;

class_declaration: INTERFACE ID ':' ID class_invariants_declaration class_methods_declaration_or_empty END
    ;

class_method_implementation: class_method compound_stmt
    ;
	
/*Список методов может быть пустым */
class_methods_implementation: class_method_implementation
    | class_methods_implementation class_method_implementation
    ;
	
class_methods_implementation_or_empty: class_methods_implementation
    | /* empty */
    ;

class_implementation: IMPLEMENTATION ID class_methods_implementation_or_empty END
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
func_arg: type ID
    ;

func_args: func_arg
    | func_args func_arg
    ;

func_args_or_empty: func_args
    | /* empty */
    ;

func_header: type ID '(' func_args_or_empty ')'
    ;

func_declaration: func_header ';'
    ;

func_implementation: func_header compound_stmt
    ;

func_call_args: expr
	| func_call_args ',' expr
	;

func_call: ID '(' func_call_args ')'
	| ID '(' ')'
	;

	
	
%%



struct Statements_List *AppendStatementToList(struct Statements_List *list, struct Statement *stmt)
{
	struct Statements_List *cur = (struct Statements_List *)malloc(sizeof(struct Statements_List));
	cur->next =0 ;
	list->next = cur;
	cur->stmt = stmt;
	return cur;
}

struct Statements_List *CreateStList(struct Statement *stmt)
{
	struct Statements_List *cur = (struct Statements_List *)malloc(sizeof(struct Statements_List));
	cur->next = 0;
	cur->stmt = stmt;
}

struct Statement *CreateStatement(struct Expression *expr, struct While_statement *while_stmt, 
								  struct If_statement *if_stmt, struct Init_statement *init_stmt)
{
	struct Statement *cur = (struct Statement *)malloc(sizeof(struct Statement));
	cur->expr = expr;
	cur->while_stmt = while_stmt;
	cur->if_stmt = if_stmt;
	cur->init_stmt = init_stmt;
	return cur;
}

struct Expression *CreateExpression(OperationType type, struct Expression *left, struct Expression *right,
									char *identifier, int int_value, float float_value,
									bool bool_value, char char_value, char *string_value)
{
	struct Expression *cur = (struct Expression *)malloc(sizeof(struct Expression));
	cur->type = type;
	cur->left = left;
	cur_>right = right;
	cur->identifier = identifier;
	cur->int_value = int_value;
	cur->float_value = float_value;
	cur->bool_value = bool_value;
	cur->char_value = char_value;
	cur->string_value = string_value;
	return cur;
}