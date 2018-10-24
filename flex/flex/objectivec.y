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

stmt_list: stmt_list stmt 
    | stmt 
    ;

stmt_list_or_empty: stmt_list
    | /* empty */
    ;

stmt: RETURN expr ';' 
	| RETURN ';'
	| init_stmt
	| expr ';' 
	| if_stmt 
	| while_stmt
	| compound_stmt
    ;

compound_stmt: '{' stmt_list_or_empty '}'
    ;

if_stmt: IF '(' expr ')' stmt 
    | IF '(' expr ')' stmt ELSE stmt 
    ;
	
while_stmt: WHILE '(' expr ')' stmt 
	;
	
init_stmt: ID assign_operator expr ';'
	| ID assign_operator array_constant ';'
	| array_elem_call assign_operator expr ';'
	| type ID '=' expr ';'
	| type ID '[' INT_CONST ']' '=' array_constant ';' 
	| type ID '[' INT_CONST ']' ';'
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

expr: expr '+' expr 
    | expr '-' expr 
    | expr '*' expr 
    | expr '/' expr 
	| expr '<' expr 
	| expr '=' expr
	| expr LESS_OR_EQUAL expr 
	| expr '>' expr 
	| expr GREATER_OR_EQUAL expr 
	| expr EQUAL expr 
	| expr NOT_EQUAL expr    
    | '!' expr
    | '+' expr %prec UPLUS
    | '-' expr %prec UMINUS
	| INC ID %prec PREINC
	| DEC ID %prec PREDEC
	| ID INC %prec POSTINC
	| ID DEC %prec POSTDEC
    | '(' expr ')' 
    | INT_CONST 
	| FLOAT_CONST 
	| CHAR_CONST
	| STRING_CONST 
	| ID 
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
