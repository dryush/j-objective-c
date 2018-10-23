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
    char chat_const;
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
%token <string_const> STRING_CONST
%token <id> ID

%token WHILE
%token IF
%token ELSE
%token END
%token EXTERN
%token IMPLEMENTATION
%token INTERFACE
%token RETURN
%token INC
%token DEC
%token ENUM
%token INT
%token FLOAT
%token STRING
%token CHAR
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
%nonassoc ')' ']'
 
%%
// ТУТ ПРАВИЛА
extern_code
	: func_declaration 
	| func_implementation
    | class_declaration 
	| class_implementation
	| enum_declaration
	;
prog
	: extern_code 
    | prog extern_code 
    ;
stmt_list
	: stmt_list stmt 
    | stmt 
    ;
stmt_list_or_empty
	: stmt_list
    | /* empty */
    ;
stmt
	: RETURN expr ';' 
	| RETURN ';'
	| init_stmt
	| expr ';' 
	| if_stmt 
	| while_stmt
	| compound_stmt
    ;
compound_stmt
	: '{' stmt_list_or_empty '}'
    ;
if_stmt
	: IF '(' expr ')' stmt 
    | IF '(' expr ')' stmt ELSE stmt 
    ;
while_stmt
	: WHILE '(' expr ')' stmt 
	;
init_stmt
	: ID assign_operator expr ';'
	| ID assign_operator array_constant ';'
	| array_elem_call assign_operator expr ';'
	| type_name ID '=' expr ';'
	| type_name ID '[' INT_CONST ']' '=' array_constant ';' 
	| type_name ID '[' INT_CONST ']' ';'
	;
assign_operator
	: '='
	| ADD_ASSIGN
	| SUB_ASSIGN
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	;
type_name 
	: type
	| type '*' %prec POINTER
	;
type
	: ID
	| INT
	| FLOAT
	| STRING
	| CHAR
	;
expr
	: expr '+' expr 
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
    ;
enum_declaration
	: ENUM ID '{' enumerator_list '}'
enumerator_list
	: enumerator_list ',' enumerator
	| enumerator
	;
enumerator
	: ID 
	| ID '=' INT_CONST
	;
	
class_invariant_declaration
	: type_name ';'
	;
class_invariants_declaration_part
	: class_invariant_declaration 
    | class_invariants_declaration_part
	;
class_invariants_declaration
	: '{' '}'
    | '{' class_invariants_declaration_part '}'
	;
class_method_first_param
	: '(' type ')' ID
	;
	
/*Параметры, начиная со второго могут быть объявлены с именем*/
class_method_other_param
	: ID ':' '(' type ')' ID 
    | class_method_first_param
	;
class_method_other_params_part
	: class_method_other_param
    | class_method_other_param class_method_other_params_part
	;
class_method_all_params
	: class_method_first_param
    | class_method_first_param class_method_other_param
	;
	
/*Список параметров метода может быть пустым */
class_method_params
	: class_method_all_params
	;
	
/*Объявление метода без завершающей ';', чтоб переиспользовать в реализации метода */
class_method
	: '-' '(' type ')' ID ':' class_method_params
    | '+' '(' type ')' ID ':' class_method_params
    | '-' '(' type ')' ID 
    | '+' '(' type ')' ID 
    ;
class_method_declaration
	: class_method ';'
    ;
	
/*Список методов может быть пустым */
class_methods_declaration
	: class_method_declaration
    | class_methods_declaration class_method_declaration
    ;
class_methods_declaration_or_empty
	: class_methods_declaration
    | /* empty */
    ;
class_declaration
	: INTERFACE ID ':' ID class_invariants_declaration class_methods_declaration_or_empty END
    ;
class_method_implementation
	: class_method compound_stmt
    ;
	
/*Список методов может быть пустым */
class_methods_implementation
	: class_method_implementation
    | class_methods_implementation class_method_implementation
    ;
class_methods_implementation_or_empty
	: class_methods_implementation
    | /* empty */
    ;
class_implementation
	: IMPLEMENTATION ID class_methods_implementation_or_empty END
	;
	
/*ВЫЗОВ МЕТОДА*/
/*Аргументы могут быть именованными и нет, первый аргумент вегда без имени */
method_call_noname_arg
	: ':' expr
    ;                      
method_call_name_arg
	: ID ':' expr
    ;
method_call_noname_args
	: method_call_noname_arg
    | method_call_noname_args method_call_noname_arg
    ;
method_call_name_args
	: method_call_name_arg
    | method_call_name_args method_call_name_arg
    ;

/*Список аргументов может быть пустым */
method_call_args
	: method_call_noname_args method_call_name_arg
    | method_call_noname_args
    ;
method_call_args_or_empty
	: method_call_args
    | /*empty*/
    ;
method_name
	: ID
    ;
method_call
	: '['ID method_name method_call_args_or_empty']'
    ;

/*ОБРАЩЕНИЕ К ПОЛЮ*/
invariant_call
    : ID '.' ID
    ;
	
/*МАССИВЫ */
array_elems
	: expr 
    | array_elems ',' expr
    ;
array_elems_or_empty
	: array_elems 
    | /* empty */
    ;
array_constant
	: '{' array_elems_or_empty '}'
    ;
array_elem_call
	: ID'[' expr ']'
    ;

/*ФУНКЦИИ */
func_arg
	: type_name
    ;
func_args
	: type_name 
    | func_args func_arg
    ;
func_args_or_empty
	: func_args
    | /* empty */
    ;
func_header
	: type_name '(' func_args_or_empty ')'
    ;
func_declaration
	: func_header ';'
    ;
func_implementation
	: func_header compound_stmt
    ;
%%
