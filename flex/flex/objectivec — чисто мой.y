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
    double double_const;
    char chat_const;
    char* string_const;
    char* id;
    void no_val;
}

%error-verbose

/*%type <Название структуры из union> название (работает это тип typedef и define) */


//%token Название токена, который возвращает FLEX

%token <int_const> INT
%token <float_const> FLOAT
%token <double_const> DOUBLE
%token <char_const> CHAR
%token <string_const> STRING
%token <id> ID

%token WHILE
%token IF
%token ELSE
%token END
%token EXTERN
%token IMPLEMENTATION
%token INTERFACE
%token RETURN


// СПИСОК ПРИОРИТЕТОВ ОПЕРАЦИЙ
%left ','
%right '=' PLUSEQUAL MINUSEQUAL MULEQUAL DIVEQUAL 
%right '?' ':'
%left OR
%left AND
%left '|'
%left '^'
%left '&'
%left EQUAL NOTEQUAL
%left '<' LESSEQUAL '>' MOREEQUAL
%left '-' '+'
%left '*' '/' '%'
// TYPE - приведение типа, POINTER - указатель '*', LINK - ссылка '&'
%right PREINC PREDEC UMINUS UPLUS '!' '~' TYPE POINTER LINK SIZEOF
// ARROW - Обращение к члену структуры через указатель
%left POSTINC POSTDEC '.' ARROW
%nonassoc ')' ']'
// ‘+’ - метод статический, ‘-’ - метод экземплярный 
%%
// ТУТ ПРАВИЛА

type: ID
    | ID '*'
    ;
type_name: type ID
        ;


extern_code: func_declaration | func_implementation
    | class_declaration | class_implementation;
prog: extern_code 
    | prog extern_code 
    ;

stmt: RETURN expr ';'
    | ID expr ';'
    | EXTERN ID expr';'
    | expr ';' 
    | if_stmt 
    | while_loop
    ;

stmt_list: 
    stmt_list stmt 
    | stmt 
    ;
stmt_list_or_empty: stmt_list
    | /* empty */
    ;
compound_stmt: '{' stmt_list_or_empty '}'
    ;

expr: expr '+' expr 
    | expr '-' expr 
    | expr '*' expr 
    | expr '/' expr 
    | expr '<' expr 
    | expr LESSEQUAL expr 
    | expr '>' expr 
    | expr MOREEQUAL expr 
    | expr EQUAL expr 
    | expr NOTEQUAL expr 
    | expr '=' expr 
    | expr PLUSEQUAL expr 
    | expr MINUSEQUAL expr
    | expr MULEQUAL expr 
    | expr DIVEQUAL expr 
    | '(' expr ')' 
    | INT 
    | FLOAT 
    | CHAR 
    | STRING 
    | ID
    | array_elem_call
    | method_call 
    ;

if_stmt: IF '(' expr ')' stmt 
    | IF '(' expr ')' stmt ELSE stmt
    ;
while_loop: WHILE '(' expr ')' stmt 
    ;

class_invariant_declaration: type_name ';'
;
class_invariants_declaration_part: class_invariant_declaration 
    | class_invariants_declaration_part
;
class_invariants_declaration: '{' '}'
    | '{' class_invariants_declaration_part '}'
;
class_method_first_param: '(' type ')' ID
;
/*Параметры, начиная со второго могут быть объявлены с именем*/
class_method_other_param: ID ':' '(' type ')' ID 
    | class_method_first_param
;
class_method_other_params_part: class_method_other_param
    | class_method_other_param class_method_other_params_part
;
class_method_all_params: class_method_first_param
    | class_method_first_param class_method_other_param
;
/*Список параметров метода может быть пустым */
class_method_params: class_method_all_params
;
/*Объявление метода без завершающей ';', чтоб переиспользовать в реализации метода */
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
class_methods_declaration_or_empty: class_methods_declaration
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
method_call_args: method_call_noname_args method_call_name_arg
    | method_call_noname_args
    ;
method_call_args_or_empty: method_call_args
    | /*empty*/
    ;
method_name: ID
    ;
method_call: '['ID method_name method_call_args_or_empty']'
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
array_elem_call: ID'[' expr ']'
    ;

/*ФУНКЦИИ */
func_arg: type_name
    ;
func_args: type_name 
    | func_args func_arg
    ;
func_args_or_empty: func_args
    | /* empty */
    ;
func_header: type_name '(' func_args_or_empty ')'
    ;
func_declaration: func_header ';'
    ;
func_implementation: func_header compound_stmt
    ;
%%
