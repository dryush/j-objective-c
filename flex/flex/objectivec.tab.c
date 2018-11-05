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

	extern struct Program_st root;

/* Line 371 of yacc.c  */
#line 88 "objectivec.tab.c"

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
     DO = 265,
     IF = 266,
     ELSE = 267,
     END = 268,
     EXTERN = 269,
     IMPLEMENTATION = 270,
     INTERFACE = 271,
     PUBLIC = 272,
     PROTECTED = 273,
     PRIVATE = 274,
     RETURN = 275,
     ENUM = 276,
     INT = 277,
     FLOAT = 278,
     STRING = 279,
     CHAR = 280,
     BOOL = 281,
     VOID = 282,
     OR = 283,
     AND = 284,
     NOT_EQUAL = 285,
     EQUAL = 286,
     GREATER_OR_EQUAL = 287,
     LESS_OR_EQUAL = 288,
     POINTER = 289,
     UPLUS = 290,
     UMINUS = 291,
     ARROW = 292
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 21 "objectivec.y"

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

	struct Expr_list_st* expr_list_st;

	struct Func_arg_st* func_arg_st;
	struct Func_arg_list_st* func_arg_list_st;
	struct Func_declaration_st* func_declaration_st;
	struct Func_impl_st* func_impl_st;
	struct Func_call_st* func_call_st;

	struct Array_elem_call_st* array_elem_call_st;

	struct Extern_code_st* extern_code_st;
	struct Program_st* program_st;


/* Line 387 of yacc.c  */
#line 230 "objectivec.tab.c"
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
#line 258 "objectivec.tab.c"

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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   512

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  235

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,     2,     2,    42,     2,     2,
      55,    50,    40,    39,    28,    38,    47,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    52,
      34,    29,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      25,    26,    27,    30,    31,    32,    33,    36,    37,    44,
      45,    46,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    16,    18,
      20,    21,    25,    28,    31,    33,    35,    37,    39,    43,
      49,    57,    63,    69,    73,    80,    82,    84,    86,    88,
      90,    92,    94,    97,    99,   103,   107,   111,   115,   119,
     123,   129,   133,   137,   141,   145,   149,   153,   157,   161,
     164,   167,   170,   174,   176,   178,   180,   182,   184,   186,
     193,   198,   202,   207,   211,   217,   221,   223,   225,   229,
     231,   233,   235,   239,   241,   244,   247,   249,   251,   254,
     257,   261,   266,   273,   275,   278,   280,   283,   286,   288,
     290,   291,   299,   307,   313,   319,   322,   324,   327,   329,
     332,   334,   337,   339,   340,   348,   354,   357,   359,   362,
     364,   365,   366,   372,   375,   379,   381,   384,   386,   389,
     392,   394,   396,   397,   399,   403,   405,   406,   409,   411,
     414,   416,   417,   423,   426
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,   108,    -1,   109,    -1,    90,    -1,    94,
      -1,    69,    -1,    59,    61,    -1,    61,    -1,    59,    -1,
      -1,    20,    68,    52,    -1,    20,    52,    -1,    68,    52,
      -1,    64,    -1,    63,    -1,    65,    -1,    62,    -1,    53,
      60,    54,    -1,    11,    55,    68,    50,    61,    -1,    11,
      55,    68,    50,    61,    12,    61,    -1,     9,    55,    68,
      50,    61,    -1,    67,     8,    29,    68,    52,    -1,    67,
       8,    52,    -1,    67,     8,    49,     3,    51,    52,    -1,
      22,    -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,
      27,    -1,    66,    -1,     8,    40,    -1,     8,    -1,    68,
      39,    68,    -1,    68,    38,    68,    -1,    68,    40,    68,
      -1,    68,    41,    68,    -1,    68,    42,    68,    -1,    68,
      29,    68,    -1,    68,    29,    53,   103,    54,    -1,    68,
      34,    68,    -1,    68,    37,    68,    -1,    68,    35,    68,
      -1,    68,    36,    68,    -1,    68,    33,    68,    -1,    68,
      32,    68,    -1,    68,    31,    68,    -1,    68,    30,    68,
      -1,    43,    68,    -1,    39,    68,    -1,    38,    68,    -1,
      55,    68,    50,    -1,     8,    -1,     3,    -1,     4,    -1,
       6,    -1,     5,    -1,     7,    -1,    49,    68,     8,    56,
     101,    51,    -1,    68,    49,    68,    51,    -1,    68,    48,
       8,    -1,     8,    55,   102,    50,    -1,     8,    55,    50,
      -1,    21,     8,    53,    70,    54,    -1,    70,    28,    71,
      -1,    71,    -1,     8,    -1,     8,    29,     3,    -1,    17,
      -1,    18,    -1,    19,    -1,    67,     8,    52,    -1,    73,
      -1,    74,    73,    -1,    72,    74,    -1,    74,    -1,    75,
      -1,    76,    75,    -1,    53,    54,    -1,    53,    76,    54,
      -1,    55,    67,    50,     8,    -1,     8,    56,    55,    67,
      50,     8,    -1,    79,    -1,    80,    79,    -1,    78,    -1,
      81,    78,    -1,    78,    80,    -1,    81,    -1,    82,    -1,
      -1,    38,    55,    67,    50,     8,    56,    83,    -1,    39,
      55,    67,    50,     8,    56,    83,    -1,    38,    55,    67,
      50,     8,    -1,    39,    55,    67,    50,     8,    -1,    84,
      52,    -1,    85,    -1,    86,    85,    -1,    86,    -1,    72,
      86,    -1,    87,    -1,    88,    87,    -1,    88,    -1,    -1,
      16,     8,    56,     8,    77,    89,    13,    -1,    16,     8,
      77,    89,    13,    -1,    84,    62,    -1,    91,    -1,    92,
      91,    -1,    92,    -1,    -1,    -1,    15,     8,    93,    13,
      95,    -1,    56,    68,    -1,     8,    56,    68,    -1,    96,
      -1,    98,    96,    -1,    97,    -1,    99,    97,    -1,    96,
      99,    -1,    98,    -1,   100,    -1,    -1,    68,    -1,   102,
      28,    68,    -1,   102,    -1,    -1,    67,     8,    -1,   104,
      -1,   105,   104,    -1,   105,    -1,    -1,    67,     8,    55,
     106,    50,    -1,   107,    52,    -1,   107,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   190,   190,   191,   192,   193,   194,   201,   202,   205,
     206,   209,   210,   211,   212,   213,   214,   215,   218,   221,
     222,   225,   228,   229,   230,   234,   235,   236,   237,   238,
     239,   242,   243,   244,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   273,
     274,   275,   276,   277,   280,   283,   284,   287,   288,   314,
     315,   316,   319,   322,   323,   327,   328,   332,   333,   336,
     337,   340,   347,   350,   351,   354,   355,   359,   360,   364,
     365,   376,   377,   378,   379,   382,   387,   388,   392,   393,
     396,   397,   400,   401,   404,   405,   408,   412,   413,   416,
     417,   420,   420,   425,   428,   431,   432,   435,   436,   440,
     441,   444,   445,   449,   450,   455,   456,   461,   464,   465,
     468,   469,   472,   475,   478
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_CONST", "FLOAT_CONST", "CHAR_CONST",
  "BOOL_CONST", "STRING_CONST", "ID", "WHILE", "DO", "IF", "ELSE", "END",
  "EXTERN", "IMPLEMENTATION", "INTERFACE", "PUBLIC", "PROTECTED",
  "PRIVATE", "RETURN", "ENUM", "INT", "FLOAT", "STRING", "CHAR", "BOOL",
  "VOID", "','", "'='", "OR", "AND", "NOT_EQUAL", "EQUAL", "'<'", "'>'",
  "GREATER_OR_EQUAL", "LESS_OR_EQUAL", "'-'", "'+'", "'*'", "'/'", "'%'",
  "'!'", "POINTER", "UPLUS", "UMINUS", "'.'", "ARROW", "'['", "')'", "']'",
  "';'", "'{'", "'}'", "'('", "':'", "$accept", "extern_code", "stmt_list",
  "stmt_list_or_empty", "stmt", "compound_stmt", "if_stmt", "while_stmt",
  "var_decl", "default_type", "type", "expr", "enum_declaration",
  "enumerator_list", "enumerator", "class_fields_access",
  "class_invariant_declaration", "class_invariants_declarations",
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
  "method_call_args_or_empty", "expr_list", "array_elems_or_empty",
  "func_arg", "func_args", "func_args_or_empty", "func_header",
  "func_declaration", "func_implementation", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    44,    61,
     283,   284,   285,   286,    60,    62,   287,   288,    45,    43,
      42,    47,    37,    33,   289,   290,   291,    46,   292,    91,
      41,    93,    59,   123,   125,    40,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    62,    63,
      63,    64,    65,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    70,    70,    71,    71,    72,
      72,    72,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    84,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    92,    92,    93,
      93,    95,    94,    96,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   105,   105,
     106,   106,   107,   108,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       0,     3,     2,     2,     1,     1,     1,     1,     3,     5,
       7,     5,     5,     3,     6,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     3,     3,     3,     3,     3,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     6,
       4,     3,     4,     3,     5,     3,     1,     1,     3,     1,
       1,     1,     3,     1,     2,     2,     1,     1,     2,     2,
       3,     4,     6,     1,     2,     1,     2,     2,     1,     1,
       0,     7,     7,     5,     5,     2,     1,     2,     1,     2,
       1,     2,     1,     0,     7,     5,     2,     1,     2,     1,
       0,     0,     5,     2,     3,     1,     2,     1,     2,     2,
       1,     1,     0,     1,     3,     1,     0,     2,     1,     2,
       1,     0,     5,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    33,     0,     0,     0,    25,    26,    27,    28,    29,
      30,     0,    31,     0,     6,     4,     5,     0,     2,     3,
      32,   110,     0,     0,     1,     0,   133,    10,   134,     0,
       0,     0,   107,   109,     0,     0,     0,   103,     0,   131,
      54,    55,    57,    56,    58,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     9,     0,     8,    17,    15,    14,
      16,     0,     0,     0,     0,   106,   108,   111,    69,    70,
      71,    79,     0,     0,    73,    76,    77,     0,     0,     0,
       0,    96,    98,   100,   102,     0,    67,     0,    66,     0,
     128,   130,     0,     0,     0,     0,    53,    12,     0,    51,
      50,    49,     0,     0,     7,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,   112,     0,    75,    74,
      80,    78,   103,    99,    95,    97,   101,   105,     0,     0,
      64,   127,   129,   132,    63,   123,     0,     0,     0,    11,
       0,    52,     0,     0,    23,   126,    39,    48,    47,    46,
      45,    41,    43,    44,    42,    35,    34,    36,    37,    38,
      61,     0,     0,     0,    72,     0,    68,    65,     0,    62,
       0,     0,   122,     0,     0,   125,     0,    60,    93,    94,
     104,   124,    21,    19,     0,   115,   120,   121,     0,    22,
       0,    40,    90,    90,     0,   113,     0,   117,   119,   116,
      59,    24,     0,    85,    88,    89,    91,    92,    20,     0,
     118,     0,     0,    83,    87,    86,   114,     0,     0,    84,
      81,     0,     0,     0,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    54,    55,    56,    57,    58,    59,    60,    12,
      61,    62,    14,    87,    88,    79,    74,    75,    76,    77,
      37,   213,   223,   224,   214,   215,   216,    80,    81,    82,
      83,    84,    85,    15,    32,    33,    34,    16,   126,   195,
     207,   196,   208,   197,   198,   146,   186,    90,    91,    92,
      17,    18,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
     423,   -11,    42,    44,    50,   -77,   -77,   -77,   -77,   -77,
     -77,    61,   -77,    63,   -77,   -77,   -77,   -44,   -77,   -77,
     -77,    31,   -19,    21,   -77,    23,   -77,   112,   -77,    27,
      28,    39,   -77,    31,   109,    71,    68,    -7,    76,   432,
     -77,   -77,   -77,   -77,   -77,    -4,    58,    69,    10,   177,
     177,   177,   177,   177,   112,    72,   -77,   -77,   -77,   -77,
     -77,   119,   227,   432,   432,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   123,   432,   -77,   432,   -77,   179,    80,    31,
      91,   -77,    31,   -77,    -7,   132,   117,   -26,   -77,   144,
     -77,   432,   104,    17,   177,   177,   101,   -77,   251,    32,
      32,    32,   206,   322,   -77,   -77,   -22,   170,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   149,   177,   -77,   108,   110,   -77,   107,   432,   -77,
     -77,   -77,    -7,    31,   -77,   -77,   -77,   -77,   159,    76,
     -77,   -77,   -77,   -77,   -77,   388,    18,   344,   366,   -77,
     113,   -77,   177,   160,   -77,   177,   388,   429,   447,   463,
     463,   151,   151,   151,   151,   100,   100,    32,    32,    32,
     -77,   299,   156,   158,   -77,   155,   -77,   -77,   177,   -77,
     112,   112,   115,   275,   121,   166,   125,   -77,   139,   154,
     -77,   388,   -77,   176,   177,   199,   115,   -77,   167,   -77,
     165,   -77,   169,   169,   112,   388,   171,   -77,   199,   -77,
     -77,   -77,   432,   213,   169,   -77,   -77,   -77,   -77,   177,
     -77,   172,   173,   -77,   213,   -77,   388,   220,   175,   -77,
     -77,   432,   184,   241,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   -77,   -51,     2,   -77,   -77,   -77,   -77,
       0,    -8,   -77,   -77,   111,   -30,   -74,   178,   193,   -77,
     174,    57,    29,   -77,   -77,   -77,    70,     5,   -76,   195,
     188,   -77,   145,   -77,   245,   -77,   -77,   -77,   -77,    98,
      87,   -77,   -77,   -77,   -77,   141,   -77,   207,   -77,   -77,
     -77,   -77,   -77
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -34
static const yytype_int16 yytable[] =
{
      13,   129,   139,   104,   -33,    73,   135,   152,    26,    27,
      68,    69,    70,    40,    41,    42,    43,    44,    96,    28,
      40,    41,    42,    43,    44,    96,    31,   153,   140,    20,
     154,    29,    30,    65,    35,    72,    20,    36,    31,    89,
      98,    99,   100,   101,   102,   103,   178,    73,    49,    50,
      21,    93,    22,    51,   129,    49,    50,   135,    23,    52,
      51,    24,    97,   124,   125,    53,    52,   144,   179,    29,
      30,    25,    53,    72,    38,    72,    78,    72,    39,     1,
     121,   122,    63,    64,    86,   145,   147,   148,    68,    69,
      70,    89,    27,     5,     6,     7,     8,     9,    10,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,    94,   171,    40,    41,    42,    43,    44,
      45,    46,    67,    47,    95,    71,   105,   106,    72,   192,
     193,   127,    48,    35,     5,     6,     7,     8,     9,    10,
     118,   119,   120,   134,   183,   137,   138,   145,   121,   122,
      49,    50,   141,   218,   143,    51,    93,   170,   172,   174,
     173,    52,   176,   184,   188,    27,   189,    53,   190,   182,
     191,   194,   200,    40,    41,    42,    43,    44,    96,   201,
      40,    41,    42,    43,    44,    96,   205,     1,   204,   116,
     117,   118,   119,   120,   178,   202,    68,    69,    70,   121,
     122,     5,     6,     7,     8,     9,    10,   206,    49,    50,
     203,   226,   221,    51,   150,    49,    50,   211,   210,    52,
      51,   222,   227,   155,   212,    53,    52,   219,   230,   228,
     231,   232,    53,   130,   233,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   234,
     177,   128,   132,   229,   121,   122,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     131,   225,   136,   217,   133,   121,   122,   175,    66,   123,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   209,   220,   185,     0,   142,   121,
     122,     0,     0,   149,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,     0,     0,
       0,     0,     0,   121,   122,     0,     0,   199,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,     0,   121,   122,     0,
     187,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
     121,   122,   151,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,     0,
       0,     0,   121,   122,   180,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,     0,
       0,     0,     0,     0,   121,   122,   181,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     1,     0,     0,     0,     0,   121,   122,     2,     3,
       1,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,     5,     6,     7,     8,     9,    10,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,     0,   121,   122,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,   121,   122,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,   121,   122
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-77)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    75,    28,    54,     8,    35,    82,    29,    52,    53,
      17,    18,    19,     3,     4,     5,     6,     7,     8,    17,
       3,     4,     5,     6,     7,     8,    21,    49,    54,    40,
      52,    38,    39,    31,    53,    35,    40,    56,    33,    39,
      48,    49,    50,    51,    52,    53,    28,    77,    38,    39,
       8,    55,     8,    43,   128,    38,    39,   133,     8,    49,
      43,     0,    52,    63,    64,    55,    49,    50,    50,    38,
      39,     8,    55,    73,    53,    75,     8,    77,    55,     8,
      48,    49,    55,    55,     8,    93,    94,    95,    17,    18,
      19,    91,    53,    22,    23,    24,    25,    26,    27,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    55,   122,     3,     4,     5,     6,     7,
       8,     9,    13,    11,    55,    54,    54,     8,   128,   180,
     181,     8,    20,    53,    22,    23,    24,    25,    26,    27,
      40,    41,    42,    52,   152,    13,    29,   155,    48,    49,
      38,    39,     8,   204,    50,    43,    55,     8,    50,    52,
      50,    49,     3,     3,     8,    53,     8,    55,    13,    56,
     178,    56,    51,     3,     4,     5,     6,     7,     8,    54,
       3,     4,     5,     6,     7,     8,   194,     8,    12,    38,
      39,    40,    41,    42,    28,    56,    17,    18,    19,    48,
      49,    22,    23,    24,    25,    26,    27,     8,    38,    39,
      56,   219,   212,    43,     8,    38,    39,    52,    51,    49,
      43,     8,    50,    53,    55,    55,    49,    56,     8,    56,
      55,   231,    55,    54,    50,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     8,
     139,    73,    78,   224,    48,    49,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      77,   214,    84,   203,    79,    48,    49,   132,    33,    52,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   196,   208,   155,    -1,    91,    48,
      49,    -1,    -1,    52,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    52,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      51,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    50,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     8,    -1,    -1,    -1,    -1,    48,    49,    15,    16,
       8,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    22,    23,    24,    25,    26,    27,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    15,    16,    21,    22,    23,    24,    25,    26,
      27,    58,    66,    67,    69,    90,    94,   107,   108,   109,
      40,     8,     8,     8,     0,     8,    52,    53,    62,    38,
      39,    84,    91,    92,    93,    53,    56,    77,    53,    55,
       3,     4,     5,     6,     7,     8,     9,    11,    20,    38,
      39,    43,    49,    55,    59,    60,    61,    62,    63,    64,
      65,    67,    68,    55,    55,    62,    91,    13,    17,    18,
      19,    54,    67,    72,    73,    74,    75,    76,     8,    72,
      84,    85,    86,    87,    88,    89,     8,    70,    71,    67,
     104,   105,   106,    55,    55,    55,     8,    52,    68,    68,
      68,    68,    68,    68,    61,    54,     8,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    48,    49,    52,    67,    67,    95,     8,    74,    73,
      54,    75,    77,    86,    52,    85,    87,    13,    29,    28,
      54,     8,   104,    50,    50,    68,   102,    68,    68,    52,
       8,    50,    29,    49,    52,    53,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
       8,    68,    50,    50,    52,    89,     3,    71,    28,    50,
      50,    50,    56,    68,     3,   102,   103,    51,     8,     8,
      13,    68,    61,    61,    56,    96,    98,   100,   101,    52,
      51,    54,    56,    56,    12,    68,     8,    97,    99,    96,
      51,    52,    55,    78,    81,    82,    83,    83,    61,    56,
      97,    67,     8,    79,    80,    78,    68,    50,    56,    79,
       8,    55,    67,    50,     8
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
#line 190 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode((yyvsp[(1) - (1)].func_declaration_st), NULL, NULL, NULL, NULL);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 191 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, (yyvsp[(1) - (1)].func_impl_st), NULL, NULL, NULL);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 192 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, (yyvsp[(1) - (1)].class_declaration_st), NULL, NULL);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 193 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, (yyvsp[(1) - (1)].class_impl_st), NULL);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 194 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, NULL, (yyvsp[(1) - (1)]._enum_decl));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 201 "objectivec.y"
    { (yyval._stmt_list) = AppendStatementToList((yyvsp[(1) - (2)]._stmt_list), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 202 "objectivec.y"
    { (yyval._stmt_list) = CreateStatementList((yyvsp[(1) - (1)]._stmt)); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 205 "objectivec.y"
    { (yyval._stmt_list) = (yyvsp[(1) - (1)]._stmt_list); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 206 "objectivec.y"
    { (yyval._stmt_list) = NULL; }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 209 "objectivec.y"
    { (yyval._stmt) = createReturnStatement((yyvsp[(2) - (3)]._expr));}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 210 "objectivec.y"
    { (yyval._stmt) = createReturnStatement(NULL;}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 211 "objectivec.y"
    { (yyval._stmt) = CreateExpressionStatement((yyvsp[(1) - (2)]._expr)); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 212 "objectivec.y"
    { (yyval._stmt) = CreateWhileStatement((yyvsp[(1) - (1)]._while_stmt)); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 213 "objectivec.y"
    { (yyval._stmt) = CreateIfStatement((yyvsp[(1) - (1)]._if_stmt)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 214 "objectivec.y"
    { (yyval._stmt) = CreateInitStatement((yyvsp[(1) - (1)]._stmt)); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 215 "objectivec.y"
    { (yyval._stmt) = CreateCompoundStatement((yyvsp[(1) - (1)]._stmt)); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 218 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(2) - (3)]._stmt_list); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 221 "objectivec.y"
    { (yyval._if_stmt) = CreateIf((yyvsp[(3) - (5)]._expr),(yyvsp[(5) - (5)]._stmt),NULL); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 222 "objectivec.y"
    { (yyval._if_stmt) = CreateIf((yyvsp[(3) - (7)]._expr),(yyvsp[(5) - (7)]._stmt),(yyvsp[(7) - (7)]._stmt)); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 225 "objectivec.y"
    { (yyval._while_stmt) = CreateWhile((yyvsp[(3) - (5)]._expr),(yyvsp[(5) - (5)]._stmt)); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 228 "objectivec.y"
    { (yyval._stmt) = CreateInitID((yyvsp[(1) - (5)]._type), (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)]._expr)); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 229 "objectivec.y"
    { (yyval._stmt) = CreateInitID((yyvsp[(1) - (3)]._type), (yyvsp[(2) - (3)].id), NULL); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 230 "objectivec.y"
    {;}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 234 "objectivec.y"
    { (yyval._type) = createType(TYPE_INT, NULL, NULL);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 235 "objectivec.y"
    { (yyval._type) = createType(TYPE_FLOAT, NULL, NULL);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 236 "objectivec.y"
    { (yyval._type) = createType(TYPE_STRING, NULL, NULL);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 237 "objectivec.y"
    { (yyval._type) = createType(TYPE_CHAR, NULL, NULL);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 238 "objectivec.y"
    { (yyval._type) = createType(TYPE_BOOL, NULL, NULL);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 239 "objectivec.y"
    { (yyval._type) = { (yyval._type) = createType(TYPE_VOID, NULL, NULL);}}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 242 "objectivec.y"
    { (yyval._type) = (yyvsp[(1) - (1)]._type); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 243 "objectivec.y"
    { createType(TYPE_POINTER, NULL, createType(TYPE_CUSTOM, (yyvsp[(1) - (2)].id), NULL); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 244 "objectivec.y"
    { createType(TYPE_CUSTOM, (yyvsp[(1) - (1)].id), NULL); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 247 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_ADD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 248 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_SUB, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 249 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_MUL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 250 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_DIV, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 251 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_MOD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 252 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_ASSIGN, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 253 "objectivec.y"
    { (yyval._expr) = CreateArrayInitStatement((yyvsp[(1) - (5)]._expr), (yyvsp[(4) - (5)].expr_list_st));}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 254 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LESS, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 255 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LESS_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 256 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_GREATER, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 257 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_GREATER_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 258 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 259 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_NOT_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 260 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_AND, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 261 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_OR, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 262 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LOGICAL_NOT, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 263 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_UPLUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 264 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_UMINUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 265 "objectivec.y"
    { (yyval._expr) = (yyvsp[(2) - (3)]._expr); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 266 "objectivec.y"
    { (yyval._expr) = CreateIDExpression((yyvsp[(1) - (1)].id)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 267 "objectivec.y"
    { (yyval._expr) = CreateIntValueExpression((yyvsp[(1) - (1)].int_const)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 268 "objectivec.y"
    { (yyval._expr) = CreateFloatValueExpression((yyvsp[(1) - (1)].float_const)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 269 "objectivec.y"
    { (yyval._expr) = CreateBoolValueExpression((yyvsp[(1) - (1)].bool_const)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 270 "objectivec.y"
    { (yyval._expr) = CreateCharValueExpression((yyvsp[(1) - (1)].char_const)); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 271 "objectivec.y"
    { (yyval._expr) = CreateStringValueExpression((yyvsp[(1) - (1)].string_const)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 273 "objectivec.y"
    { (yyval._expr) =createMethodCall((yyvsp[(2) - (6)]._expr), (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].method_call_arg_list_st));}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 274 "objectivec.y"
    { (yyval._expr) = createArrayElemCall((yyvsp[(1) - (4)]._expr), (yyvsp[(3) - (4)]._expr)); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 275 "objectivec.y"
    { (yyval._expr) = createInvariantCall((yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)].id));}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 276 "objectivec.y"
    { (yyval._expr) = createFuncCall((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].expr_list_st)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 277 "objectivec.y"
    { (yyval._expr) = createFuncCall((yyvsp[(1) - (3)].id), NULL); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 280 "objectivec.y"
    { (yyval._enum_decl) = CreateEnumDeclaration((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)]._enum_list)); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 283 "objectivec.y"
    { (yyval._enum_list) = AppendEnumeratorToList((yyvsp[(1) - (3)]._enum_list), (yyvsp[(3) - (3)]._enumerator)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 284 "objectivec.y"
    { (yyval._enum_list) = CreateEnumeratorList((yyvsp[(1) - (1)]._enumerator)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 287 "objectivec.y"
    {(yyval._enumerator) = CreateEnumerator((yyvsp[(1) - (1)].id), -1); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 288 "objectivec.y"
    {(yyval._enumerator) = CreateEnumerator((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].int_const)); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 314 "objectivec.y"
    { (yyval.field_access_en) = A_PUBLIC; }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 315 "objectivec.y"
    { (yyval.field_access_en) = A_PROTECTED; }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 316 "objectivec.y"
    { (yyval.field_access_en) = A_PRIVATE; }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 319 "objectivec.y"
    { (yyval.class_invariant_declaration_st) = createClassInvariantDeclaration((yyvsp[(1) - (3)]._type), (yyvsp[(2) - (3)].id)); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 322 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = createClassInvariantsDeclarationList((yyvsp[(1) - (1)].class_invariant_declaration_st)); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 323 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = addToClassInvariantsDeclarationList((yyvsp[(1) - (2)].class_invariants_declaration_list_st), (yyvsp[(2) - (2)].class_invariant_declaration_st)); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 327 "objectivec.y"
    { (yyval.class_invariants_declaration_block_st) = createClassInvariantsDeclarationBlock((yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_invariants_declaration_list_st)); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 328 "objectivec.y"
    { (yyval.class_invariants_declaration_block_st) = createClassInvariantsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_invariants_declaration_list_st)); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 332 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = createClassInvariantsDeclarationBlockList((yyvsp[(1) - (1)].class_invariants_declaration_block_st)); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 333 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = addToClassInvariantsDeclarationBlockList((yyvsp[(1) - (2)].class_invariants_declaration_block_list_st), (yyvsp[(2) - (2)].class_invariants_declaration_block_st)); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 336 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = NULL; }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 337 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = (yyvsp[(2) - (3)].class_invariants_declaration_block_list_st); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 340 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration( NULL, (yyvsp[(2) - (4)]._type), (yyvsp[(4) - (4)].id) );}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 347 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration((yyvsp[(1) - (6)].id), (yyvsp[(4) - (6)]._type), (yyvsp[(6) - (6)].id)); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 350 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 351 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 354 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 355 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 359 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToFrontClassMethodParamDeclarationList((yyvsp[(2) - (2)].class_method_param_declaration_list_st), (yyvsp[(1) - (2)].class_method_param_declaration_st)); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 360 "objectivec.y"
    {(yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 364 "objectivec.y"
    {(yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 365 "objectivec.y"
    {(yyval.class_method_param_declaration_list_st) = NULL; }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 376 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st));}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 377 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st));}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 378 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL);}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 379 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL);}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 382 "objectivec.y"
    { (yyval.class_method_declaration_st) = (yyvsp[(1) - (2)].class_method_declaration_st); }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 387 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = createMethodsDeclarationList( (yyvsp[(1) - (1)].class_method_declaration_st)); }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 388 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = addToMethodsDeclarationList( (yyvsp[(1) - (2)].class_methods_declaration_list_st), (yyvsp[(2) - (2)].class_method_declaration_st)); }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 392 "objectivec.y"
    { (yyval.class_methods_declaration_block_st) = createClassMethodsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_methods_declaration_list_st)); }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 393 "objectivec.y"
    { (yyval.class_methods_declaration_block_st) = createClassMethodsDeclarationBlock( (yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_methods_declaration_list_st)); }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 396 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = createClassMethodsDeclarationBlockList( (yyvsp[(1) - (1)].class_methods_declaration_block_st)); }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 397 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = addToClassMethodsDeclarationBlockList( (yyvsp[(1) - (2)].class_methods_declaration_block_list_st), (yyvsp[(2) - (2)].class_methods_declaration_block_st)); }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 400 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = (yyvsp[(1) - (1)].class_methods_declaration_block_list_st); }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 401 "objectivec.y"
    {(yyval.class_methods_declaration_block_list_st) = NULL; }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 404 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (7)].id), (yyvsp[(4) - (7)].id), (yyvsp[(5) - (7)].class_invariants_declaration_block_list_st), (yyvsp[(6) - (7)].class_methods_declaration_block_list_st)); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 405 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (5)].id), NULL, (yyvsp[(3) - (5)].class_invariants_declaration_block_list_st), (yyvsp[(4) - (5)].class_methods_declaration_block_list_st)); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 408 "objectivec.y"
    { (yyval.class_method_impl_st) = createClassMethodImpl((yyvsp[(1) - (2)].class_method_declaration_st), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 412 "objectivec.y"
    { (yyval.class_method_impl_list_st) = createClassMethodImplList((yyvsp[(1) - (1)].class_method_impl_st)); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 413 "objectivec.y"
    { (yyval.class_method_impl_list_st) = addToClassMethodImplList((yyvsp[(1) - (2)].class_method_impl_list_st), (yyvsp[(2) - (2)].class_method_impl_st)); }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 416 "objectivec.y"
    {(yyval.class_method_impl_list_st) = (yyvsp[(1) - (1)].class_method_impl_list_st); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 417 "objectivec.y"
    {(yyval.class_method_impl_list_st) = NULL; }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 420 "objectivec.y"
    {}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 420 "objectivec.y"
    { (yyval.class_impl_st) = createClassImpl((yyvsp[(2) - (5)].id), (yyvsp[(3) - (5)].class_method_impl_list_st)); }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 425 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg(NULL, (yyvsp[(2) - (2)]._expr));}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 428 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)]._expr));}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 431 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 432 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToCreateMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st));}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 435 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 436 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToCreateMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st));}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 440 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToFrontMethodCallArgList((yyvsp[(2) - (2)].method_call_arg_list_st), (yyvsp[(1) - (2)].method_call_arg_st));}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 441 "objectivec.y"
    { (yyval.method_call_arg_list_st) = (yyvsp[(1) - (1)].method_call_arg_list_st); }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 444 "objectivec.y"
    { (yyval.method_call_arg_list_st) = (yyvsp[(1) - (1)].method_call_arg_list_st);}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 445 "objectivec.y"
    { (yyval.method_call_arg_list_st) = NULL; }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 449 "objectivec.y"
    { (yyval.expr_list_st) = createExprList((yyvsp[(1) - (1)]._expr));}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 450 "objectivec.y"
    { (yyval.expr_list_st) = addToExprList((yyvsp[(1) - (3)].expr_list_st), (yyvsp[(3) - (3)]._expr));}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 455 "objectivec.y"
    { (yyval.expr_list_st) = (yyvsp[(1) - (1)].expr_list_st);}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 456 "objectivec.y"
    { (yyval.expr_list_st) = NULL;}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 461 "objectivec.y"
    { (yyval.func_arg_st) =  createFuncArg((yyvsp[(1) - (2)]._type), (yyvsp[(2) - (2)].id));}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 464 "objectivec.y"
    { (yyval.func_arg_list_st) = createFuncArgList((yyvsp[(1) - (1)].func_arg_st)); }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 465 "objectivec.y"
    { (yyval.func_arg_list_st) = addToFuncArgList((yyvsp[(1) - (2)].func_arg_list_st), (yyvsp[(2) - (2)].func_arg_st)); }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 468 "objectivec.y"
    { (yyval.func_arg_list_st) = (yyvsp[(1) - (1)].func_arg_list_st); }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 469 "objectivec.y"
    { (yyval.func_arg_list_st) = NULL; }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 472 "objectivec.y"
    { (yyval.func_declaration_st) = createFuncDeclaration((yyvsp[(1) - (5)]._type), (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].func_arg_list_st)); }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 475 "objectivec.y"
    { (yyval.func_declaration_st) = (yyvsp[(1) - (2)].func_declaration_st); }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 478 "objectivec.y"
    { (yyval.func_impl_st) = createFuncImpl((yyvsp[(1) - (2)].func_declaration_st), (yyvsp[(2) - (2)]._stmt));}
    break;


/* Line 1792 of yacc.c  */
#line 2541 "objectivec.tab.c"
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
#line 484 "objectivec.y"
