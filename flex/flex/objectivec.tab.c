/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "objectivec.y"

    /*
    ТУТ ПОДКЛЮЧЕНИЕ БИБЛИОТЕК, 
    ПРОТОТИПЫ ФУНКЦИЙ НА СИ
    ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ
    */
    #include <stdio.h>
	#include "tree_structs.h"
	#include "tree_structs_func.h"
	#include "tree_structs_array.h"
	#include "tree_structs_class.h"
    int yylex() { return getc(stdin); }
    void yyerror(char *s) {
        fprintf (stderr, "%s\n", s);
    }

/* Line 371 of yacc.c  */
#line 85 "objectivec.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "objectivec.tab.h".  */
#ifndef YY_YY_OBJECTIVEC_TAB_H_INCLUDED
# define YY_YY_OBJECTIVEC_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_CONST = 258,
     FLOAT_CONST = 259,
     CHAR_CONST = 260,
     BOOL_CONST = 261,
     STRING_CONST = 262,
     ID = 263,
     WHILE = 264,
     IF = 265,
     ELSE = 266,
     END = 267,
     EXTERN = 268,
     IMPLEMENTATION = 269,
     INTERFACE = 270,
     PUBLIC = 271,
     PROTECTED = 272,
     PRIVATE = 273,
     RETURN = 274,
     INC = 275,
     DEC = 276,
     ENUM = 277,
     INT = 278,
     FLOAT = 279,
     STRING = 280,
     CHAR = 281,
     BOOL = 282,
     VOID = 283,
     MOD_ASSIGN = 284,
     DIV_ASSIGN = 285,
     MUL_ASSIGN = 286,
     SUB_ASSIGN = 287,
     ADD_ASSIGN = 288,
     OR = 289,
     AND = 290,
     NOT_EQUAL = 291,
     EQUAL = 292,
     GREATER_OR_EQUAL = 293,
     LESS_OR_EQUAL = 294,
     POINTER = 295,
     UPLUS = 296,
     UMINUS = 297,
     PREDEC = 298,
     PREINC = 299,
     ARROW = 300,
     POSTDEC = 301,
     POSTINC = 302
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 18 "objectivec.y"

/*ОБЪЯВЛЕНИЕ ПЕРЕМЕННЫХ*/
/*ОБЪЯВЛЕНИЕ СТРУКТУР*/
    int int_const;
    float float_const;
    char char_const;
	/*bool bool_const; */
	char bool_const; /*В Си нет bool*/
    char* string_const;
    char* id;
    /*void no_val; */ /*Сомнительно*/
	
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
	struct Class_method_param_declaration_st* class_method_param_declaration_st;
	struct Class_method_param_declaration_list_st* class_method_param_declaration_list_st;
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

	struct Invariant_call_st* invariant_call_st;

	struct Method_call_arg_st* method_call_arg_st;
	struct Method_call_arg_list_st* method_call_arg_list_st;
	struct Method_call_st* method_call_st;

	struct Func_arg_st* func_arg_st;
	struct Func_arg_list_st* func_arg_list_st;
	struct Func_declaration_st* func_declaration_st;
	struct Func_impl_st* func_impl_st;
	struct Func_call_arg_list_st* func_call_arg_list_st;
	struct Func_call_st* func_call_st;

	struct Array_const_elem_list_st* array_const_elem_list_st;
	struct Array_elem_call_st* array_elem_call_st;

	struct Extern_code_st* extern_code_st;
	struct Program_st* program_st;


/* Line 387 of yacc.c  */
#line 238 "objectivec.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_OBJECTIVEC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 266 "objectivec.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   481

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNRULES -- Number of states.  */
#define YYNSTATES  255

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,     2,     2,    48,     2,     2,
      65,    60,    46,    45,    29,    44,    55,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    66,    62,
      40,    30,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,    64,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    42,    43,    50,    51,    52,    53,    54,
      56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    16,    18,
      20,    21,    25,    28,    31,    33,    35,    38,    40,    44,
      50,    58,    64,    68,    72,    77,    80,    82,    84,    86,
      88,    90,    92,    94,    96,    98,   100,   103,   106,   109,
     111,   113,   115,   116,   120,   124,   128,   132,   136,   140,
     144,   148,   152,   156,   160,   164,   167,   170,   173,   176,
     179,   182,   185,   189,   191,   193,   195,   197,   199,   201,
     203,   205,   207,   209,   211,   217,   221,   223,   225,   229,
     231,   233,   235,   239,   241,   244,   247,   249,   251,   254,
     257,   261,   266,   273,   275,   278,   280,   283,   286,   288,
     290,   291,   299,   307,   313,   319,   322,   324,   327,   329,
     332,   334,   337,   339,   340,   348,   354,   357,   359,   362,
     364,   365,   366,   372,   375,   379,   381,   384,   386,   389,
     392,   394,   396,   397,   404,   408,   410,   414,   416,   417,
     421,   426,   429,   431,   434,   436,   437,   443,   446,   449,
     451,   455,   460
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      68,     0,    -1,   125,    -1,   126,    -1,   103,    -1,   107,
      -1,    82,    -1,    69,    71,    -1,    71,    -1,    69,    -1,
      -1,    19,    81,    62,    -1,    19,    62,    -1,    81,    62,
      -1,    74,    -1,    73,    -1,    75,    62,    -1,    72,    -1,
      63,    70,    64,    -1,    10,    65,    81,    60,    71,    -1,
      10,    65,    81,    60,    71,    11,    71,    -1,     9,    65,
      81,    60,    71,    -1,     8,    76,    81,    -1,   120,    76,
      81,    -1,    80,     8,    30,    81,    -1,    80,     8,    -1,
      35,    -1,    34,    -1,    33,    -1,    32,    -1,    31,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,
       8,    46,    -1,    77,    46,    -1,    78,    46,    -1,    77,
      -1,    78,    -1,    79,    -1,    -1,    81,    45,    81,    -1,
      81,    44,    81,    -1,    81,    46,    81,    -1,    81,    47,
      81,    -1,    81,    48,    81,    -1,    81,    30,    81,    -1,
      81,    40,    81,    -1,    81,    43,    81,    -1,    81,    41,
      81,    -1,    81,    42,    81,    -1,    81,    39,    81,    -1,
      81,    38,    81,    -1,    49,    81,    -1,    45,    81,    -1,
      44,    81,    -1,    20,     8,    -1,    21,     8,    -1,     8,
      20,    -1,     8,    21,    -1,    65,    81,    60,    -1,     8,
      -1,     3,    -1,     4,    -1,     6,    -1,     5,    -1,     7,
      -1,   115,    -1,   120,    -1,   116,    -1,   128,    -1,   119,
      -1,    22,     8,    63,    83,    64,    -1,    83,    29,    84,
      -1,    84,    -1,     8,    -1,     8,    30,     3,    -1,    16,
      -1,    17,    -1,    18,    -1,    80,     8,    62,    -1,    86,
      -1,    87,    86,    -1,    85,    87,    -1,    87,    -1,    88,
      -1,    89,    88,    -1,    63,    64,    -1,    63,    89,    64,
      -1,    65,    80,    60,     8,    -1,     8,    66,    65,    80,
      60,     8,    -1,    92,    -1,    93,    92,    -1,    91,    -1,
      94,    91,    -1,    91,    93,    -1,    94,    -1,    95,    -1,
      -1,    44,    65,    80,    60,     8,    66,    96,    -1,    45,
      65,    80,    60,     8,    66,    96,    -1,    44,    65,    80,
      60,     8,    -1,    45,    65,    80,    60,     8,    -1,    97,
      62,    -1,    98,    -1,    99,    98,    -1,    99,    -1,    85,
      99,    -1,   100,    -1,   101,   100,    -1,   101,    -1,    -1,
      15,     8,    66,     8,    90,   102,    12,    -1,    15,     8,
      90,   102,    12,    -1,    97,    72,    -1,   104,    -1,   105,
     104,    -1,   105,    -1,    -1,    -1,    14,     8,   106,    12,
     108,    -1,    66,    81,    -1,     8,    66,    81,    -1,   109,
      -1,   111,   109,    -1,   110,    -1,   112,   110,    -1,   109,
     112,    -1,   111,    -1,   113,    -1,    -1,    59,    81,     8,
      66,   114,    61,    -1,    81,    56,     8,    -1,    81,    -1,
     117,    29,    81,    -1,   117,    -1,    -1,    63,   118,    64,
      -1,    81,    59,    81,    61,    -1,    80,     8,    -1,   121,
      -1,   122,   121,    -1,   122,    -1,    -1,    80,     8,    65,
     123,    60,    -1,   124,    62,    -1,   124,    72,    -1,    81,
      -1,   127,    29,    81,    -1,     8,    65,   127,    60,    -1,
       8,    65,    60,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   194,   194,   195,   196,   197,   198,   205,   206,   209,
     210,   213,   214,   215,   216,   217,   218,   219,   222,   225,
     226,   229,   232,   233,   234,   235,   238,   239,   240,   241,
     242,   245,   246,   247,   248,   249,   252,   255,   256,   259,
     260,   261,   262,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   298,   301,   302,   305,   306,   332,
     333,   334,   337,   340,   341,   345,   346,   350,   351,   354,
     355,   358,   365,   368,   369,   372,   373,   377,   378,   382,
     383,   394,   395,   396,   397,   400,   405,   406,   410,   411,
     414,   415,   418,   419,   422,   423,   426,   430,   431,   434,
     435,   438,   438,   443,   446,   449,   450,   453,   454,   458,
     459,   462,   463,   468,   472,   476,   477,   480,   481,   484,
     487,   491,   494,   495,   498,   499,   502,   505,   508,   511,
     512,   515,   516
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_CONST", "FLOAT_CONST", "CHAR_CONST",
  "BOOL_CONST", "STRING_CONST", "ID", "WHILE", "IF", "ELSE", "END",
  "EXTERN", "IMPLEMENTATION", "INTERFACE", "PUBLIC", "PROTECTED",
  "PRIVATE", "RETURN", "INC", "DEC", "ENUM", "INT", "FLOAT", "STRING",
  "CHAR", "BOOL", "VOID", "','", "'='", "MOD_ASSIGN", "DIV_ASSIGN",
  "MUL_ASSIGN", "SUB_ASSIGN", "ADD_ASSIGN", "OR", "AND", "NOT_EQUAL",
  "EQUAL", "'<'", "'>'", "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "'-'", "'+'",
  "'*'", "'/'", "'%'", "'!'", "POINTER", "UPLUS", "UMINUS", "PREDEC",
  "PREINC", "'.'", "ARROW", "POSTDEC", "POSTINC", "'['", "')'", "']'",
  "';'", "'{'", "'}'", "'('", "':'", "$accept", "extern_code", "stmt_list",
  "stmt_list_or_empty", "stmt", "compound_stmt", "if_stmt", "while_stmt",
  "init_stmt", "assign_operator", "default_type", "custom_type",
  "array_type", "type", "expr", "enum_declaration", "enumerator_list",
  "enumerator", "class_fields_access", "class_invariant_declaration",
  "class_invariants_declarations",
  "class_invariant_declaration_with_access",
  "class_invariant_declaration_with_access_list",
  "class_invariants_declaration", "class_method_first_param",
  "class_method_other_param_named", "class_method_other_params_named",
  "class_method_params_nonamed", "class_method_all_params",
  "class_method_params", "class_method", "class_method_declaration",
  "class_methods_declaration", "class_methods_declaration_with_access",
  "class_methods_declaration_with_access_list",
  "class_methods_declaration_or_empty", "class_declaration",
  "class_method_implementation", "class_methods_implementation",
  "class_methods_implementation_or_empty", "class_implementation", "$@1",
  "method_call_noname_arg", "method_call_name_arg",
  "method_call_noname_args", "method_call_name_args", "method_call_args",
  "method_call_args_or_empty", "method_call", "invariant_call",
  "array_elems", "array_elems_or_empty", "array_constant",
  "array_elem_call", "func_arg", "func_args", "func_args_or_empty",
  "func_header", "func_declaration", "func_implementation",
  "func_call_args", "func_call", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    44,
      61,   284,   285,   286,   287,   288,   289,   290,   291,   292,
      60,    62,   293,   294,    45,    43,    42,    47,    37,    33,
     295,   296,   297,   298,   299,    46,   300,   301,   302,    91,
      41,    93,    59,   123,   125,    40,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    72,    73,
      73,    74,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    77,    77,    77,    77,    77,    78,    79,    79,    80,
      80,    80,    80,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    82,    83,    83,    84,    84,    85,
      85,    85,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   105,   105,   106,
     106,   108,   107,   109,   110,   111,   111,   112,   112,   113,
     113,   114,   114,   115,   116,   117,   117,   118,   118,   119,
     120,   121,   122,   122,   123,   123,   124,   125,   126,   127,
     127,   128,   128
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       0,     3,     2,     2,     1,     1,     2,     1,     3,     5,
       7,     5,     3,     3,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     1,     1,     3,     1,
       1,     1,     3,     1,     2,     2,     1,     1,     2,     2,
       3,     4,     6,     1,     2,     1,     2,     2,     1,     1,
       0,     7,     7,     5,     5,     2,     1,     2,     1,     2,
       1,     2,     1,     0,     7,     5,     2,     1,     2,     1,
       0,     0,     5,     2,     3,     1,     2,     1,     2,     2,
       1,     1,     0,     6,     3,     1,     3,     1,     0,     3,
       4,     2,     1,     2,     1,     0,     5,     2,     2,     1,
       3,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
       0,    39,    40,    41,     0,     6,     4,     5,     0,     2,
       3,    36,   120,     0,     0,     1,    37,    38,     0,   147,
      10,   148,     0,     0,     0,   117,   119,     0,     0,     0,
     113,     0,   145,    64,    65,    67,    66,    68,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
       9,     0,     8,    17,    15,    14,     0,     0,     0,    69,
      71,    73,    70,    72,    42,    42,   116,   118,   121,    79,
      80,    81,    89,     0,     0,    83,    86,    87,     0,     0,
       0,     0,   106,   108,   110,   112,     0,    77,     0,    76,
       0,   142,   144,     0,    60,    61,    30,    29,    28,    27,
      26,     0,     0,     0,     0,    63,    12,   138,     0,    70,
      58,    59,    57,    56,    55,     0,   135,   137,     0,     0,
       7,    18,    16,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,   122,     0,    85,    84,    90,    88,   113,   109,
     105,   107,   111,   115,     0,     0,    74,   141,   143,   146,
     152,   149,     0,    22,     0,     0,   135,    11,     0,     0,
     139,    62,     0,    48,    54,    53,    49,    51,    52,    50,
      44,    43,    45,    46,    47,   134,     0,    23,     0,     0,
      82,     0,    78,    75,     0,   151,     0,     0,   132,   136,
      24,   140,   103,   104,   114,   150,    21,    19,     0,   125,
     130,   131,     0,   100,   100,     0,   123,     0,   127,   129,
     126,   133,    42,    95,    98,    99,   101,   102,    20,     0,
     128,     0,     0,    93,    97,    96,   124,     0,     0,    94,
      91,    42,     0,     0,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    60,    61,    62,    63,    64,    65,    66,   112,
      11,    12,    13,    67,    68,    15,    98,    99,    90,    85,
      86,    87,    88,    40,   233,   243,   244,   234,   235,   236,
      91,    92,    93,    94,    95,    96,    16,    35,    36,    37,
      17,   152,   219,   228,   220,   229,   221,   222,    69,    70,
     127,   128,    71,   119,   101,   102,   103,    18,    19,    20,
     172,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
     454,   -23,    29,    33,    43,   -88,   -88,   -88,   -88,   -88,
      57,    20,    30,   -88,    56,   -88,   -88,   -88,    -7,   -88,
     -88,   -88,    38,   -13,    17,   -88,   -88,   -88,    24,   -88,
     106,   -88,    41,    42,    45,   -88,    38,    73,     1,    79,
       4,   109,    96,   -88,   -88,   -88,   -88,   -88,    12,    53,
      59,   138,   120,   126,   215,   215,   215,   215,   106,   215,
     106,    72,   -88,   -88,   -88,   -88,    75,   131,   169,   -88,
     -88,   -88,    28,   -88,    96,    96,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   132,    96,   -88,    96,   -88,   245,    84,
      38,    90,   -88,    38,   -88,     4,   141,   127,   -24,   -88,
     148,   -88,    96,   101,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   185,   215,   215,   215,    14,   -88,   215,   273,   -88,
     -88,   -88,    22,    22,    22,   246,   169,   137,   104,   322,
     -88,   -88,   -88,   140,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   165,   215,   -88,   215,
     119,   121,   -88,   114,    96,   -88,   -88,   -88,     4,    38,
     -88,   -88,   -88,   -88,   177,   109,   -88,   -88,   -88,   -88,
     -88,   391,   -21,   391,   345,   368,   391,   -88,   118,   215,
     -88,   -88,   215,   391,   411,   411,   193,   193,   193,   193,
     116,   116,    22,    22,    22,   -88,   298,   391,   178,   186,
     -88,   173,   -88,   -88,   215,   -88,   106,   106,   136,   391,
     391,   -88,   158,   160,   -88,   391,   -88,   187,   215,   196,
     136,   -88,   166,   168,   168,   106,   391,   176,   -88,   196,
     -88,   -88,    96,   235,   168,   -88,   -88,   -88,   -88,   215,
     -88,   195,   180,   -88,   235,   -88,   391,   239,   191,   -88,
     -88,    96,   197,   250,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   -58,    18,   -88,   -88,   -88,   194,
     -88,   -88,   -88,     0,   -44,   -88,   -88,   100,   -34,   -83,
     183,   189,   -88,   184,    47,    31,   -88,   -88,   -88,    55,
      -6,   -87,   192,   188,   -88,   139,   -88,   259,   -88,   -88,
     -88,   -88,    76,    69,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -29,   198,   -88,   -88,   -88,   -88,   -88,
     -88,   -88
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      14,    72,   130,   155,    84,   165,   161,   118,   204,     1,
     122,   123,   124,   125,   126,   129,    34,    79,    80,    81,
      79,    80,    81,    21,     5,     6,     7,     8,     9,    72,
      34,    72,   104,   105,   104,   105,    31,    22,    83,   205,
     166,    23,   100,   106,   107,   108,   109,   110,    32,    33,
      38,    24,    76,    39,    84,    29,    30,    25,    21,   106,
     107,   108,   109,   110,    28,    82,    26,   171,   173,   174,
     175,   155,   161,   176,   150,   151,    27,   111,   146,   111,
      41,   147,    32,    33,    83,    78,    83,    89,    83,    42,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   100,   196,     1,   197,    74,    75,    30,    43,
      44,    45,    46,    47,    48,    49,    50,    97,   113,     5,
       6,     7,     8,     9,   114,    51,    52,    53,   120,     5,
       6,     7,     8,     9,   121,   209,   131,   132,   210,   133,
     153,    43,    44,    45,    46,    47,   115,    38,   216,   217,
      54,    55,   160,   163,    83,    56,   167,   164,    52,    53,
     215,   169,   143,   144,   145,    57,   179,   238,   180,    58,
     182,    59,   146,   195,   226,   147,   200,    72,    72,   198,
     202,   199,    54,    55,   208,   214,   212,    56,    43,    44,
      45,    46,    47,   115,   213,   246,    72,    57,   225,   134,
     116,   117,   218,    59,   227,    52,    53,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,    43,    44,
      45,    46,    47,   115,   223,   146,   224,   231,   147,    54,
      55,   148,   241,   232,    56,    52,    53,   141,   142,   143,
     144,   145,   239,   242,    57,   170,   248,   250,   117,   146,
      59,   252,   147,     1,   178,   247,   251,   253,   254,    54,
      55,    79,    80,    81,    56,   203,   149,   154,     5,     6,
       7,     8,     9,   158,    57,   249,   134,   157,   117,   237,
      59,   245,   159,   162,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,    77,   230,   201,   240,     0,
     168,     0,   146,   134,     0,   147,     0,     0,     0,   156,
       0,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,     0,     0,     0,     0,     0,     0,   134,   146,
       0,     0,   147,     0,     0,   177,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,     0,
       0,     0,   134,     0,   146,     0,     0,   147,     0,   211,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,     0,     0,     0,     0,   134,     0,     0,   146,     0,
       0,   147,   181,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,     0,     0,     0,     0,   134,     0,
       0,   146,     0,     0,   147,   206,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,     0,     0,
       0,   134,     0,     0,   146,     0,     0,   147,   207,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,     0,     0,     0,     0,     0,   146,     0,     0,
     147,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,     0,     1,     0,     0,     0,     0,   146,     2,     3,
     147,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     9
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-88)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    30,    60,    86,    38,    29,    93,    51,    29,     8,
      54,    55,    56,    57,    58,    59,    22,    16,    17,    18,
      16,    17,    18,    46,    23,    24,    25,    26,    27,    58,
      36,    60,    20,    21,    20,    21,    18,     8,    38,    60,
      64,     8,    42,    31,    32,    33,    34,    35,    44,    45,
      63,     8,    34,    66,    88,    62,    63,     0,    46,    31,
      32,    33,    34,    35,     8,    64,    46,   111,   112,   113,
     114,   154,   159,   117,    74,    75,    46,    65,    56,    65,
      63,    59,    44,    45,    84,    12,    86,     8,    88,    65,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   102,   147,     8,   149,    65,    65,    63,     3,
       4,     5,     6,     7,     8,     9,    10,     8,    65,    23,
      24,    25,    26,    27,    65,    19,    20,    21,     8,    23,
      24,    25,    26,    27,     8,   179,    64,    62,   182,     8,
       8,     3,     4,     5,     6,     7,     8,    63,   206,   207,
      44,    45,    62,    12,   154,    49,     8,    30,    20,    21,
     204,    60,    46,    47,    48,    59,    29,   225,    64,    63,
      30,    65,    56,     8,   218,    59,    62,   206,   207,    60,
       3,    60,    44,    45,    66,    12,     8,    49,     3,     4,
       5,     6,     7,     8,     8,   239,   225,    59,    11,    30,
      62,    63,    66,    65,     8,    20,    21,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     3,     4,
       5,     6,     7,     8,    66,    56,    66,    61,    59,    44,
      45,    62,   232,    65,    49,    20,    21,    44,    45,    46,
      47,    48,    66,     8,    59,    60,    66,     8,    63,    56,
      65,   251,    59,     8,     8,    60,    65,    60,     8,    44,
      45,    16,    17,    18,    49,   165,    72,    84,    23,    24,
      25,    26,    27,    89,    59,   244,    30,    88,    63,   224,
      65,   234,    90,    95,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    36,   220,   158,   229,    -1,
     102,    -1,    56,    30,    -1,    59,    -1,    -1,    -1,    64,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    30,    56,
      -1,    -1,    59,    -1,    -1,    62,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    56,    -1,    -1,    59,    -1,    61,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    30,    -1,    -1,    56,    -1,
      -1,    59,    60,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    56,    -1,    -1,    59,    60,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    56,    -1,    -1,    59,    60,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    -1,     8,    -1,    -1,    -1,    -1,    56,    14,    15,
      59,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    14,    15,    22,    23,    24,    25,    26,    27,
      68,    77,    78,    79,    80,    82,   103,   107,   124,   125,
     126,    46,     8,     8,     8,     0,    46,    46,     8,    62,
      63,    72,    44,    45,    97,   104,   105,   106,    63,    66,
      90,    63,    65,     3,     4,     5,     6,     7,     8,     9,
      10,    19,    20,    21,    44,    45,    49,    59,    63,    65,
      69,    70,    71,    72,    73,    74,    75,    80,    81,   115,
     116,   119,   120,   128,    65,    65,    72,   104,    12,    16,
      17,    18,    64,    80,    85,    86,    87,    88,    89,     8,
      85,    97,    98,    99,   100,   101,   102,     8,    83,    84,
      80,   121,   122,   123,    20,    21,    31,    32,    33,    34,
      35,    65,    76,    65,    65,     8,    62,    63,    81,   120,
       8,     8,    81,    81,    81,    81,    81,   117,   118,    81,
      71,    64,    62,     8,    30,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    56,    59,    62,    76,
      80,    80,   108,     8,    87,    86,    64,    88,    90,    99,
      62,    98,   100,    12,    30,    29,    64,     8,   121,    60,
      60,    81,   127,    81,    81,    81,    81,    62,     8,    29,
      64,    60,    30,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,     8,    81,    81,    60,    60,
      62,   102,     3,    84,    29,    60,    60,    60,    66,    81,
      81,    61,     8,     8,    12,    81,    71,    71,    66,   109,
     111,   113,   114,    66,    66,    11,    81,     8,   110,   112,
     109,    61,    65,    91,    94,    95,    96,    96,    71,    66,
     110,    80,     8,    92,    93,    91,    81,    60,    66,    92,
       8,    65,    80,    60,     8
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 194 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode((yyvsp[(1) - (1)].func_declaration_st), NULL, NULL, NULL, NULL);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 195 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, (yyvsp[(1) - (1)].func_impl_st), NULL, NULL, NULL);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 196 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, (yyvsp[(1) - (1)].class_declaration_st), NULL, NULL);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 197 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, (yyvsp[(1) - (1)].class_impl_st), NULL);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 198 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, NULL, (yyvsp[(1) - (1)]._enum_decl));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 205 "objectivec.y"
    { (yyval._stmt_list) = AppendStatementToList((yyvsp[(1) - (2)]._stmt_list), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 206 "objectivec.y"
    { (yyval._stmt_list) = CreateStatementList((yyvsp[(1) - (1)]._stmt)); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 209 "objectivec.y"
    { (yyval._stmt_list) = (yyvsp[(1) - (1)]._stmt_list); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 210 "objectivec.y"
    { (yyval._stmt_list) = NULL; }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 215 "objectivec.y"
    { (yyval._stmt) = CreateExpressionStatement((yyvsp[(1) - (2)]._expr)); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 216 "objectivec.y"
    { (yyval._stmt) = CreateWhileStatement((yyvsp[(1) - (1)]._while_stmt)); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 217 "objectivec.y"
    { (yyval._stmt) = CreateIfStatement((yyvsp[(1) - (1)]._if_stmt)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 218 "objectivec.y"
    { (yyval._stmt) = CreateInitStatement((yyvsp[(1) - (2)]._init_stmt)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 219 "objectivec.y"
    { (yyval._stmt) = CreateCompoundStatement((yyvsp[(1) - (1)]._stmt)); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 222 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(2) - (3)]._stmt_list); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 225 "objectivec.y"
    { (yyval._if_stmt) = CreateIf((yyvsp[(3) - (5)]._expr),(yyvsp[(5) - (5)]._stmt),NULL); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 226 "objectivec.y"
    { (yyval._if_stmt) = CreateIf((yyvsp[(3) - (7)]._expr),(yyvsp[(5) - (7)]._stmt),(yyvsp[(7) - (7)]._stmt)); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 229 "objectivec.y"
    { (yyval._while_stmt) = CreateWhile((yyvsp[(3) - (5)]._expr),(yyvsp[(5) - (5)]._stmt)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 234 "objectivec.y"
    { (yyval._init_stmt) = CreateInitID((yyvsp[(1) - (4)]._type), (yyvsp[(2) - (4)].id), (yyvsp[(4) - (4)]._expr)); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 235 "objectivec.y"
    { (yyval._init_stmt) = CreateInitID((yyvsp[(1) - (2)]._type), (yyvsp[(2) - (2)].id), NULL); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 265 "objectivec.y"
    { (yyval._expr) = CreateExpression(ADD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 266 "objectivec.y"
    { (yyval._expr) = CreateExpression(SUB, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 267 "objectivec.y"
    { (yyval._expr) = CreateExpression(MUL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 268 "objectivec.y"
    { (yyval._expr) = CreateExpression(DIV, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 269 "objectivec.y"
    { (yyval._expr) = CreateExpression(MOD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 270 "objectivec.y"
    { (yyval._expr) = CreateExpression(ASSIGN, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 271 "objectivec.y"
    { (yyval._expr) = CreateExpression(LESS, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 272 "objectivec.y"
    { (yyval._expr) = CreateExpression(LESS_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 273 "objectivec.y"
    { (yyval._expr) = CreateExpression(GREATER, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 274 "objectivec.y"
    { (yyval._expr) = CreateExpression(GREATER_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 275 "objectivec.y"
    { (yyval._expr) = CreateExpression(EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 276 "objectivec.y"
    { (yyval._expr) = CreateExpression(NOT_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 277 "objectivec.y"
    { (yyval._expr) = CreateExpression(LOGICAL_NOT, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 278 "objectivec.y"
    { (yyval._expr) = CreateExpression(UPLUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 279 "objectivec.y"
    { (yyval._expr) = CreateExpression(UMINUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 280 "objectivec.y"
    { (yyval._expr) = CreatePreIncDecExpression(PREINC, (yyvsp[(2) - (2)].id)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 281 "objectivec.y"
    { (yyval._expr) = CreatePreIncDecExpression(PREDEC, (yyvsp[(2) - (2)].id)); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 282 "objectivec.y"
    { (yyval._expr) = CreatePostIncDecExpression(POSTINC, (yyvsp[(1) - (2)].id)); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 283 "objectivec.y"
    { (yyval._expr) = CreatePostIncDecExpression(POSTDEC, (yyvsp[(1) - (2)].id)); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 284 "objectivec.y"
    { (yyval._expr) = (yyvsp[(2) - (3)]._expr); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 285 "objectivec.y"
    { (yyval._expr) = CreateIDExpression((yyvsp[(1) - (1)].id)); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 286 "objectivec.y"
    { (yyval._expr) = CreateIntValueExpression((yyvsp[(1) - (1)].int_const)); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 287 "objectivec.y"
    { (yyval._expr) = CreateFloatValueExpression((yyvsp[(1) - (1)].float_const)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 288 "objectivec.y"
    { (yyval._expr) = CreateBoolValueExpression((yyvsp[(1) - (1)].bool_const)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 289 "objectivec.y"
    { (yyval._expr) = CreateCharValueExpression((yyvsp[(1) - (1)].char_const)); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 290 "objectivec.y"
    { (yyval._expr) = CreateStringValueExpression((yyvsp[(1) - (1)].string_const)); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 298 "objectivec.y"
    { (yyval._enum_decl) = CreateEnumDeclaration((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)]._enum_list)); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 301 "objectivec.y"
    { (yyval._enum_list) = AppendEnumeratorToList((yyvsp[(1) - (3)]._enum_list), (yyvsp[(3) - (3)]._enumerator)); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 302 "objectivec.y"
    { (yyval._enum_list) = CreateEnumeratorList((yyvsp[(1) - (1)]._enumerator)); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 306 "objectivec.y"
    {(yyval._enumerator) = CreateEnumerator((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].int_const)); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 332 "objectivec.y"
    { (yyval.field_access_en) = A_PUBLIC; }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 333 "objectivec.y"
    { (yyval.field_access_en) = A_PROTECTED; }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 334 "objectivec.y"
    { (yyval.field_access_en) = A_PRIVATE; }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 337 "objectivec.y"
    { (yyval.class_invariant_declaration_st) = createClassInvariantDeclaration((yyvsp[(1) - (3)]._type), (yyvsp[(2) - (3)].id)); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 340 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = createClassInvariantsDeclarationList((yyvsp[(1) - (1)].class_invariant_declaration_st)); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 341 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = addToClassInvariantsDeclarationList((yyvsp[(1) - (2)].class_invariants_declaration_list_st), (yyvsp[(2) - (2)].class_invariant_declaration_st)); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 345 "objectivec.y"
    { (yyval.class_invariants_declaration_block_st) = createClassInvariantsDeclarationBlock((yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_invariants_declaration_list_st)); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 346 "objectivec.y"
    { (yyval.class_invariants_declaration_block_st) = createClassInvariantsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_invariants_declaration_list_st)); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 350 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = createClassInvariantsDeclarationBlockList((yyvsp[(1) - (1)].class_invariants_declaration_block_st)); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 351 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = addToClassInvariantsDeclarationBlockList((yyvsp[(1) - (2)].class_invariants_declaration_block_list_st), (yyvsp[(2) - (2)].class_invariants_declaration_block_st)); }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 354 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = NULL; }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 355 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = (yyvsp[(2) - (3)].class_invariants_declaration_block_list_st); }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 358 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration( NULL, (yyvsp[(2) - (4)]._type), (yyvsp[(4) - (4)].id) );}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 365 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration((yyvsp[(1) - (6)].id), (yyvsp[(4) - (6)]._type), (yyvsp[(6) - (6)].id)); }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 368 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 369 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 372 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 373 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 377 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToFrontClassMethodParamDeclarationList((yyvsp[(2) - (2)].class_method_param_declaration_list_st), (yyvsp[(1) - (2)].class_method_param_declaration_st)); }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 378 "objectivec.y"
    {(yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 382 "objectivec.y"
    {(yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 383 "objectivec.y"
    {(yyval.class_method_param_declaration_list_st) = NULL; }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 394 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st));}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 395 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st));}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 396 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL);}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 397 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL);}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 400 "objectivec.y"
    { (yyval.class_method_declaration_st) = (yyvsp[(1) - (2)].class_method_declaration_st); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 405 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = createMethodsDeclarationList( (yyvsp[(1) - (1)].class_method_declaration_st)); }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 406 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = addToMethodsDeclarationList( (yyvsp[(1) - (2)].class_methods_declaration_list_st), (yyvsp[(2) - (2)].class_method_declaration_st)); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 410 "objectivec.y"
    { (yyval.class_methods_declaration_block_st) = createClassMethodsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_methods_declaration_list_st)); }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 411 "objectivec.y"
    { (yyval.class_methods_declaration_block_st) = createClassMethodsDeclarationBlock( (yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_methods_declaration_list_st)); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 414 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = createClassMethodsDeclarationBlockList( (yyvsp[(1) - (1)].class_methods_declaration_block_st)); }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 415 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = addToClassMethodsDeclarationBlockList( (yyvsp[(1) - (2)].class_methods_declaration_block_list_st), (yyvsp[(2) - (2)].class_methods_declaration_block_st)); }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 418 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = (yyvsp[(1) - (1)].class_methods_declaration_block_list_st); }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 419 "objectivec.y"
    {(yyval.class_methods_declaration_block_list_st) = NULL; }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 422 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (7)].id), (yyvsp[(4) - (7)].id), (yyvsp[(5) - (7)].class_invariants_declaration_block_list_st), (yyvsp[(6) - (7)].class_methods_declaration_block_list_st)); }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 423 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (5)].id), NULL, (yyvsp[(3) - (5)].class_invariants_declaration_block_list_st), (yyvsp[(4) - (5)].class_methods_declaration_block_list_st)); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 426 "objectivec.y"
    { (yyval.class_method_impl_st) = createClassMethodImpl((yyvsp[(1) - (2)].class_method_declaration_st), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 430 "objectivec.y"
    { (yyval.class_method_impl_list_st) = createClassMethodImplList((yyvsp[(1) - (1)].class_method_impl_st)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 431 "objectivec.y"
    { (yyval.class_method_impl_list_st) = addToClassMethodImplList((yyvsp[(1) - (2)].class_method_impl_list_st), (yyvsp[(2) - (2)].class_method_impl_st)); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 434 "objectivec.y"
    {(yyval.class_method_impl_list_st) = (yyvsp[(1) - (1)].class_method_impl_list_st); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 435 "objectivec.y"
    {(yyval.class_method_impl_list_st) = NULL; }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 438 "objectivec.y"
    {}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 438 "objectivec.y"
    { (yyval.class_impl_st) = createClassImpl((yyvsp[(2) - (5)].id), (yyvsp[(3) - (5)].class_method_impl_list_st)); }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 443 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg(NULL, (yyvsp[(2) - (2)]._expr));}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 446 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)]._expr));}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 449 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 450 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToCreateMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st));}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 453 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 454 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToCreateMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st));}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 458 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToFrontMethodCallArgList((yyvsp[(2) - (2)].method_call_arg_list_st), (yyvsp[(1) - (2)].method_call_arg_st));}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 459 "objectivec.y"
    { (yyval.method_call_arg_list_st) = (yyvsp[(1) - (1)].method_call_arg_list_st); }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 462 "objectivec.y"
    { (yyval.method_call_arg_list_st) = (yyvsp[(1) - (1)].method_call_arg_list_st);}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 463 "objectivec.y"
    { (yyval.method_call_arg_list_st) = NULL; }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 468 "objectivec.y"
    { (yyval.method_call_st) =createMethodCall((yyvsp[(2) - (6)]._expr), (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].method_call_arg_list_st));}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 472 "objectivec.y"
    { (yyval.invariant_call_st) = createInvariantCall((yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)].id));}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 476 "objectivec.y"
    { (yyval.array_const_elem_list_st) = createArrayConstElemList((yyvsp[(1) - (1)]._expr));}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 477 "objectivec.y"
    { (yyval.array_const_elem_list_st) = addToArrayConstElemList((yyvsp[(1) - (3)].array_const_elem_list_st), (yyvsp[(3) - (3)]._expr));}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 480 "objectivec.y"
    { (yyval.array_const_elem_list_st) = (yyvsp[(1) - (1)].array_const_elem_list_st);}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 481 "objectivec.y"
    { (yyval.array_const_elem_list_st) = NULL;}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 484 "objectivec.y"
    { (yyval.array_const_elem_list_st) = (yyvsp[(2) - (3)].array_const_elem_list_st);}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 487 "objectivec.y"
    { (yyval.array_elem_call_st) = createArrayElemCall((yyvsp[(1) - (4)]._expr), (yyvsp[(3) - (4)]._expr)); }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 491 "objectivec.y"
    { (yyval.func_arg_st) =  createFuncArg((yyvsp[(1) - (2)]._type), (yyvsp[(2) - (2)].id));}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 494 "objectivec.y"
    { (yyval.func_arg_list_st) = createFuncArgList((yyvsp[(1) - (1)].func_arg_st)); }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 495 "objectivec.y"
    { (yyval.func_arg_list_st) = addToFuncArgList((yyvsp[(1) - (2)].func_arg_list_st), (yyvsp[(2) - (2)].func_arg_st)); }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 498 "objectivec.y"
    { (yyval.func_arg_list_st) = (yyvsp[(1) - (1)].func_arg_list_st); }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 499 "objectivec.y"
    { (yyval.func_arg_list_st) = NULL; }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 502 "objectivec.y"
    { (yyval.func_declaration_st) = createFuncDeclaration((yyvsp[(1) - (5)]._type), (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].func_arg_list_st)); }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 505 "objectivec.y"
    { (yyval.func_declaration_st) = (yyvsp[(1) - (2)].func_declaration_st); }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 508 "objectivec.y"
    { (yyval.func_impl_st) = createFuncImpl((yyvsp[(1) - (2)].func_declaration_st), (yyvsp[(2) - (2)]._stmt));}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 511 "objectivec.y"
    { (yyval.func_call_arg_list_st) = createFuncCallArgsList((yyvsp[(1) - (1)]._expr));}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 512 "objectivec.y"
    { (yyval.func_call_arg_list_st) = addToFuncCallArgList((yyvsp[(1) - (3)].func_call_arg_list_st), (yyvsp[(3) - (3)]._expr));}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 515 "objectivec.y"
    { (yyval.func_call_st) = createFuncCall((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].func_call_arg_list_st)); }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 516 "objectivec.y"
    { (yyval.func_call_st) = createFuncCall((yyvsp[(1) - (3)].id), NULL); }
    break;


/* Line 1792 of yacc.c  */
#line 2516 "objectivec.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 521 "objectivec.y"
