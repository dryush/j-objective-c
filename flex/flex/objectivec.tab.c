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

   /* #define YYSTYPE */

    void yyerror( const char *s) {
        fprintf (stderr, "%s\n", s);
    }
	
	extern int yylex(void);
	struct Program_st* root;


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

    int int_const;
    double float_const;
    char char_const;
	char bool_const; 
    char* string_const;
    char* id;
    
	struct Statements_List_st *_stmt_list;
	struct Statement_st *_stmt;
	struct Expression_st *_expr;
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
#line 223 "objectivec.tab.c"
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
#line 251 "objectivec.tab.c"

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
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  237

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
       0,     0,     3,     5,     7,     9,    11,    13,    15,    18,
      21,    23,    25,    26,    30,    33,    36,    38,    40,    42,
      44,    48,    54,    62,    68,    74,    78,    85,    87,    90,
      92,    94,    96,    98,   100,   102,   104,   108,   112,   116,
     120,   124,   128,   134,   138,   142,   146,   150,   154,   158,
     162,   166,   169,   172,   175,   179,   181,   183,   185,   187,
     189,   191,   198,   203,   207,   212,   216,   222,   226,   228,
     230,   234,   236,   238,   240,   244,   246,   249,   252,   254,
     256,   259,   262,   266,   271,   278,   280,   283,   285,   288,
     291,   293,   295,   296,   304,   312,   318,   324,   327,   329,
     332,   334,   337,   339,   342,   344,   345,   353,   359,   362,
     364,   367,   369,   370,   371,   377,   380,   384,   386,   389,
     391,   394,   397,   399,   401,   402,   404,   408,   410,   411,
     414,   416,   419,   421,   422,   428,   431
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      59,     0,    -1,   109,    -1,   110,    -1,    91,    -1,    95,
      -1,    70,    -1,    58,    -1,    59,    58,    -1,    60,    62,
      -1,    62,    -1,    60,    -1,    -1,    20,    69,    52,    -1,
      20,    52,    -1,    69,    52,    -1,    65,    -1,    64,    -1,
      66,    -1,    63,    -1,    53,    61,    54,    -1,    11,    55,
      69,    50,    62,    -1,    11,    55,    69,    50,    62,    12,
      62,    -1,     9,    55,    69,    50,    62,    -1,    67,     8,
      29,    69,    52,    -1,    67,     8,    52,    -1,    67,     8,
      49,     3,    51,    52,    -1,    68,    -1,     8,    40,    -1,
       8,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1,    27,    -1,    69,    39,    69,    -1,    69,    38,
      69,    -1,    69,    40,    69,    -1,    69,    41,    69,    -1,
      69,    42,    69,    -1,    69,    29,    69,    -1,    69,    29,
      53,   104,    54,    -1,    69,    34,    69,    -1,    69,    37,
      69,    -1,    69,    35,    69,    -1,    69,    36,    69,    -1,
      69,    33,    69,    -1,    69,    32,    69,    -1,    69,    31,
      69,    -1,    69,    30,    69,    -1,    43,    69,    -1,    39,
      69,    -1,    38,    69,    -1,    55,    69,    50,    -1,     8,
      -1,     3,    -1,     4,    -1,     6,    -1,     5,    -1,     7,
      -1,    49,    69,     8,    56,   102,    51,    -1,    69,    49,
      69,    51,    -1,    69,    48,     8,    -1,     8,    55,   103,
      50,    -1,     8,    55,    50,    -1,    21,     8,    53,    71,
      54,    -1,    71,    28,    72,    -1,    72,    -1,     8,    -1,
       8,    29,     3,    -1,    17,    -1,    18,    -1,    19,    -1,
      67,     8,    52,    -1,    74,    -1,    75,    74,    -1,    73,
      75,    -1,    75,    -1,    76,    -1,    77,    76,    -1,    53,
      54,    -1,    53,    77,    54,    -1,    55,    67,    50,     8,
      -1,     8,    56,    55,    67,    50,     8,    -1,    80,    -1,
      81,    80,    -1,    79,    -1,    82,    79,    -1,    79,    81,
      -1,    82,    -1,    83,    -1,    -1,    38,    55,    67,    50,
       8,    56,    84,    -1,    39,    55,    67,    50,     8,    56,
      84,    -1,    38,    55,    67,    50,     8,    -1,    39,    55,
      67,    50,     8,    -1,    85,    52,    -1,    86,    -1,    87,
      86,    -1,    87,    -1,    73,    87,    -1,    88,    -1,    89,
      88,    -1,    89,    -1,    -1,    16,     8,    56,     8,    78,
      90,    13,    -1,    16,     8,    78,    90,    13,    -1,    85,
      63,    -1,    92,    -1,    93,    92,    -1,    93,    -1,    -1,
      -1,    15,     8,    94,    13,    96,    -1,    56,    69,    -1,
       8,    56,    69,    -1,    97,    -1,    99,    97,    -1,    98,
      -1,   100,    98,    -1,    97,   100,    -1,    99,    -1,   101,
      -1,    -1,    69,    -1,   103,    28,    69,    -1,   103,    -1,
      -1,    67,     8,    -1,   105,    -1,   106,   105,    -1,   106,
      -1,    -1,    67,     8,    55,   107,    50,    -1,   108,    52,
      -1,   108,    63,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   183,   183,   184,   185,   186,   187,   190,   191,   194,
     195,   198,   199,   202,   203,   204,   205,   206,   207,   208,
     211,   214,   215,   218,   221,   222,   223,   226,   227,   228,
     231,   232,   233,   234,   235,   236,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   265,   266,   267,   268,   269,   272,   275,   276,   279,
     280,   306,   307,   308,   311,   314,   315,   319,   320,   324,
     325,   328,   329,   332,   339,   342,   343,   346,   347,   351,
     352,   356,   357,   368,   369,   370,   371,   374,   379,   380,
     384,   385,   388,   389,   392,   393,   396,   397,   400,   404,
     405,   408,   409,   412,   412,   417,   420,   423,   424,   427,
     428,   432,   433,   436,   437,   441,   442,   447,   448,   453,
     456,   457,   460,   461,   464,   467,   470
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
  "';'", "'{'", "'}'", "'('", "':'", "$accept", "extern_code", "prog",
  "stmt_list", "stmt_list_or_empty", "stmt", "compound_stmt", "if_stmt",
  "while_stmt", "var_decl", "type", "default_type", "expr",
  "enum_declaration", "enumerator_list", "enumerator",
  "class_fields_access", "class_invariant_declaration",
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
      60,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    64,    64,    65,    66,    66,    66,    67,    67,    67,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    71,    71,    72,
      72,    73,    73,    73,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    79,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    93,
      93,    94,    94,    96,    95,    97,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     106,   106,   107,   107,   108,   109,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     0,     3,     2,     2,     1,     1,     1,     1,
       3,     5,     7,     5,     5,     3,     6,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     6,     4,     3,     4,     3,     5,     3,     1,     1,
       3,     1,     1,     1,     3,     1,     2,     2,     1,     1,
       2,     2,     3,     4,     6,     1,     2,     1,     2,     2,
       1,     1,     0,     7,     7,     5,     5,     2,     1,     2,
       1,     2,     1,     2,     1,     0,     7,     5,     2,     1,
       2,     1,     0,     0,     5,     2,     3,     1,     2,     1,
       2,     2,     1,     1,     0,     1,     3,     1,     0,     2,
       1,     2,     1,     0,     5,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    29,     0,     0,     0,    30,    31,    32,    33,    34,
      35,     7,     0,     0,    27,     6,     4,     5,     0,     2,
       3,    28,   112,     0,     0,     1,     8,     0,   135,    12,
     136,     0,     0,     0,   109,   111,     0,     0,     0,   105,
       0,   133,    56,    57,    59,    58,    60,    55,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,    10,    19,
      17,    16,    18,     0,     0,     0,     0,   108,   110,   113,
      71,    72,    73,    81,     0,     0,    75,    78,    79,     0,
       0,     0,     0,    98,   100,   102,   104,     0,    69,     0,
      68,     0,   130,   132,     0,     0,     0,     0,    55,    14,
       0,    53,    52,    51,     0,     0,     9,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,   114,     0,
      77,    76,    82,    80,   105,   101,    97,    99,   103,   107,
       0,     0,    66,   129,   131,   134,    65,   125,     0,     0,
       0,    13,     0,    54,     0,     0,    25,   128,    41,    50,
      49,    48,    47,    43,    45,    46,    44,    37,    36,    38,
      39,    40,    63,     0,     0,     0,    74,     0,    70,    67,
       0,    64,     0,     0,   124,     0,     0,   127,     0,    62,
      95,    96,   106,   126,    23,    21,     0,   117,   122,   123,
       0,    24,     0,    42,    92,    92,     0,   115,     0,   119,
     121,   118,    61,    26,     0,    87,    90,    91,    93,    94,
      22,     0,   120,     0,     0,    85,    89,    88,   116,     0,
       0,    86,    83,     0,     0,     0,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    56,    57,    58,    59,    60,    61,    62,
      63,    14,    64,    15,    89,    90,    81,    76,    77,    78,
      79,    39,   215,   225,   226,   216,   217,   218,    82,    83,
      84,    85,    86,    87,    16,    34,    35,    36,    17,   128,
     197,   209,   198,   210,   199,   200,   148,   188,    92,    93,
      94,    18,    19,    20
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
     474,   -29,     9,    20,    41,   -80,   -80,   -80,   -80,   -80,
     -80,   -80,   279,    52,   -80,   -80,   -80,   -80,   -44,   -80,
     -80,   -80,   -25,   -49,    16,   -80,   -80,     8,   -80,   114,
     -80,    13,    18,    21,   -80,   -25,    58,     7,    68,   126,
      70,    72,   -80,   -80,   -80,   -80,   -80,    -5,    31,    35,
      15,   193,   193,   193,   193,   193,   114,    46,   -80,   -80,
     -80,   -80,   -80,   107,   278,    72,    72,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   116,    72,   -80,    72,   -80,   232,
      73,   -25,    77,   -80,   -25,   -80,   126,   118,   103,   -18,
     -80,   125,   -80,    72,    85,   172,   193,   193,    87,   -80,
     302,     3,     3,     3,   235,   373,   -80,   -80,    10,   186,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   139,   193,   -80,    98,   100,   -80,   102,
      72,   -80,   -80,   -80,   126,   -25,   -80,   -80,   -80,   -80,
     152,    70,   -80,   -80,   -80,   -80,   -80,   439,   -12,   395,
     417,   -80,   104,   -80,   193,   153,   -80,   193,   439,   471,
     489,   505,   505,    43,    43,    43,    43,   204,   204,     3,
       3,     3,   -80,   350,   150,   151,   -80,   148,   -80,   -80,
     193,   -80,   114,   114,   106,   326,   115,   140,   117,   -80,
     127,   128,   -80,   439,   -80,   158,   193,   165,   106,   -80,
     123,   -80,   129,   -80,   130,   130,   114,   439,   131,   -80,
     165,   -80,   -80,   -80,    72,   174,   130,   -80,   -80,   -80,
     -80,   193,   -80,   136,   146,   -80,   174,   -80,   439,   187,
     149,   -80,   -80,    72,   155,   195,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   194,   -80,   -80,   -80,   -55,    39,   -80,   -80,   -80,
       0,   -80,    -8,   -80,   -80,    66,   -31,   -75,   133,   137,
     -80,   132,    -7,    -9,   -80,   -80,   -80,    14,     5,   -79,
     142,   134,   -80,    84,   -80,   191,   -80,   -80,   -80,   -80,
      30,    24,   -80,   -80,   -80,   -80,    80,   -80,   145,   -80,
     -80,   -80,   -80,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -30
static const yytype_int16 yytable[] =
{
      13,   106,   131,   -29,    37,   137,    75,    38,    28,    29,
     141,    21,    13,    31,    32,     1,   180,    22,    42,    43,
      44,    45,    46,    98,    70,    71,    72,    33,    23,     5,
       6,     7,     8,     9,    10,    21,   142,    74,   181,   154,
      33,    91,   100,   101,   102,   103,   104,   105,    75,    24,
      95,   123,   124,    51,    52,   131,   137,    30,    53,   155,
      27,    73,   156,    41,    54,   126,   127,    99,    65,    40,
      55,    69,    67,    66,    29,    74,    80,    74,    88,    74,
       1,   118,   119,   120,   121,   122,    96,   147,   149,   150,
      97,   123,   124,    91,     5,     6,     7,     8,     9,    10,
     107,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   108,   173,    42,    43,    44,
      45,    46,    47,    48,   129,    49,    37,   194,   195,   136,
      74,   139,   140,   143,    50,   145,     5,     6,     7,     8,
       9,    10,    95,    70,    71,    72,   185,   172,   174,   147,
     175,   220,    51,    52,   176,   178,   186,    53,   190,   191,
     184,   192,   196,    54,    31,    32,   202,    29,   180,    55,
     206,   203,   193,   208,   212,    42,    43,    44,    45,    46,
      98,   213,   224,   204,   205,   214,   229,   221,   207,    42,
      43,    44,    45,    46,    98,   232,    42,    43,    44,    45,
      46,    98,   230,   236,   233,   235,    26,   179,   130,   227,
      51,    52,   134,   228,   223,    53,   133,   231,   177,   219,
     138,    54,   146,   135,    51,    52,    68,    55,   211,    53,
       0,    51,    52,   234,   222,    54,    53,   187,   144,   157,
       1,    55,    54,   152,   120,   121,   122,     0,    55,    70,
      71,    72,   123,   124,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,    25,
       0,     0,     0,   123,   124,     0,   132,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       4,     5,     6,     7,     8,     9,    10,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,   123,   124,     0,     0,
     125,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
     123,   124,     0,     0,   151,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,   123,   124,     0,     0,   201,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,   123,   124,
       0,   189,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
       0,   123,   124,   153,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,   123,   124,   182,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,     0,   123,   124,   183,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     1,     0,     0,     0,     0,   123,   124,     2,
       3,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,     0,     0,     0,     0,   123,
     124,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,     0,   123,   124,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,   123,   124
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    56,    77,     8,    53,    84,    37,    56,    52,    53,
      28,    40,    12,    38,    39,     8,    28,     8,     3,     4,
       5,     6,     7,     8,    17,    18,    19,    22,     8,    22,
      23,    24,    25,    26,    27,    40,    54,    37,    50,    29,
      35,    41,    50,    51,    52,    53,    54,    55,    79,     8,
      55,    48,    49,    38,    39,   130,   135,    18,    43,    49,
       8,    54,    52,    55,    49,    65,    66,    52,    55,    53,
      55,    13,    33,    55,    53,    75,     8,    77,     8,    79,
       8,    38,    39,    40,    41,    42,    55,    95,    96,    97,
      55,    48,    49,    93,    22,    23,    24,    25,    26,    27,
      54,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     8,   124,     3,     4,     5,
       6,     7,     8,     9,     8,    11,    53,   182,   183,    52,
     130,    13,    29,     8,    20,    50,    22,    23,    24,    25,
      26,    27,    55,    17,    18,    19,   154,     8,    50,   157,
      50,   206,    38,    39,    52,     3,     3,    43,     8,     8,
      56,    13,    56,    49,    38,    39,    51,    53,    28,    55,
      12,    54,   180,     8,    51,     3,     4,     5,     6,     7,
       8,    52,     8,    56,    56,    55,    50,    56,   196,     3,
       4,     5,     6,     7,     8,     8,     3,     4,     5,     6,
       7,     8,    56,     8,    55,    50,    12,   141,    75,   216,
      38,    39,    80,   221,   214,    43,    79,   226,   134,   205,
      86,    49,    50,    81,    38,    39,    35,    55,   198,    43,
      -1,    38,    39,   233,   210,    49,    43,   157,    93,    53,
       8,    55,    49,     8,    40,    41,    42,    -1,    55,    17,
      18,    19,    48,    49,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,     0,
      -1,    -1,    -1,    48,    49,    -1,    54,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,
      52,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    -1,    52,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,
      -1,    51,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,     8,    -1,    -1,    -1,    -1,    48,    49,    15,
      16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    49,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    15,    16,    21,    22,    23,    24,    25,    26,
      27,    58,    59,    67,    68,    70,    91,    95,   108,   109,
     110,    40,     8,     8,     8,     0,    58,     8,    52,    53,
      63,    38,    39,    85,    92,    93,    94,    53,    56,    78,
      53,    55,     3,     4,     5,     6,     7,     8,     9,    11,
      20,    38,    39,    43,    49,    55,    60,    61,    62,    63,
      64,    65,    66,    67,    69,    55,    55,    63,    92,    13,
      17,    18,    19,    54,    67,    73,    74,    75,    76,    77,
       8,    73,    85,    86,    87,    88,    89,    90,     8,    71,
      72,    67,   105,   106,   107,    55,    55,    55,     8,    52,
      69,    69,    69,    69,    69,    69,    62,    54,     8,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    48,    49,    52,    67,    67,    96,     8,
      75,    74,    54,    76,    78,    87,    52,    86,    88,    13,
      29,    28,    54,     8,   105,    50,    50,    69,   103,    69,
      69,    52,     8,    50,    29,    49,    52,    53,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,     8,    69,    50,    50,    52,    90,     3,    72,
      28,    50,    50,    50,    56,    69,     3,   103,   104,    51,
       8,     8,    13,    69,    62,    62,    56,    97,    99,   101,
     102,    52,    51,    54,    56,    56,    12,    69,     8,    98,
     100,    97,    51,    52,    55,    79,    82,    83,    84,    84,
      62,    56,    98,    67,     8,    80,    81,    79,    69,    50,
      56,    80,     8,    55,    67,    50,     8
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
#line 183 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode((yyvsp[(1) - (1)].func_declaration_st), NULL, NULL, NULL, NULL);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 184 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, (yyvsp[(1) - (1)].func_impl_st), NULL, NULL, NULL);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 185 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, (yyvsp[(1) - (1)].class_declaration_st), NULL, NULL);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 186 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, (yyvsp[(1) - (1)].class_impl_st), NULL);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 187 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, NULL, (yyvsp[(1) - (1)]._enum_decl));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 190 "objectivec.y"
    { root = createProgram((yyvsp[(1) - (1)].extern_code_st)); printf("createProg");}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 191 "objectivec.y"
    { root = addToProgram((yyvsp[(1) - (2)].program_st), (yyvsp[(2) - (2)].extern_code_st));}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 194 "objectivec.y"
    { (yyval._stmt_list) = AppendStatementToList((yyvsp[(1) - (2)]._stmt_list), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 195 "objectivec.y"
    { (yyval._stmt_list) = CreateStatementList((yyvsp[(1) - (1)]._stmt)); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 198 "objectivec.y"
    { (yyval._stmt_list) = (yyvsp[(1) - (1)]._stmt_list); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 199 "objectivec.y"
    { (yyval._stmt_list) = NULL; }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 202 "objectivec.y"
    { (yyval._stmt) = CreateReturnStatement((yyvsp[(2) - (3)]._expr));}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 203 "objectivec.y"
    { (yyval._stmt) = CreateReturnStatement(NULL);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 204 "objectivec.y"
    { (yyval._stmt) = CreateExpressionStatement((yyvsp[(1) - (2)]._expr)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 205 "objectivec.y"
    { /* $$ = $1; */ }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 206 "objectivec.y"
    { /* $$ = $1; */ }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 207 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 208 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 211 "objectivec.y"
    { /* $$ = $2; */}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 214 "objectivec.y"
    { /* $$ = CreateIfStatement($3, $5, NULL); */ }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 215 "objectivec.y"
    { /* $$ = CreateIfStatement($3, $5, $7); */}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 218 "objectivec.y"
    { /* $$ = CreateWhileStatement($3, $5); */ }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 221 "objectivec.y"
    { (yyval._stmt) = CreateVarDeclWithInit((yyvsp[(1) - (5)]._type), (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)]._expr)); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 222 "objectivec.y"
    { (yyval._stmt) = CreateVarDeclWithInit((yyvsp[(1) - (3)]._type), (yyvsp[(2) - (3)].id), NULL); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 223 "objectivec.y"
    {;}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 226 "objectivec.y"
    { (yyval._type) = (yyvsp[(1) - (1)]._type); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 227 "objectivec.y"
    { createType(TYPE_POINTER, NULL, createType(TYPE_CUSTOM, (yyvsp[(1) - (2)].id), NULL)); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 228 "objectivec.y"
    { createType(TYPE_CUSTOM, (yyvsp[(1) - (1)].id), NULL); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 231 "objectivec.y"
    { (yyval._type) = createType(TYPE_INT, NULL, NULL);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 232 "objectivec.y"
    { (yyval._type) = createType(TYPE_FLOAT, NULL, NULL);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 233 "objectivec.y"
    { (yyval._type) = createType(TYPE_STRING, NULL, NULL);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 234 "objectivec.y"
    { (yyval._type) = createType(TYPE_CHAR, NULL, NULL);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 235 "objectivec.y"
    { (yyval._type) = createType(TYPE_BOOL, NULL, NULL);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 236 "objectivec.y"
    { (yyval._type) = createType(TYPE_VOID, NULL, NULL);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 239 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_ADD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 240 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_SUB, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 241 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_MUL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 242 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_DIV, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 243 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_MOD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 244 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_ASSIGN, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 245 "objectivec.y"
    { (yyval._expr) = CreateArrayInitStatement((yyvsp[(1) - (5)]._expr), (yyvsp[(4) - (5)].expr_list_st));}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 246 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LESS, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 247 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LESS_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 248 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_GREATER, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 249 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_GREATER_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 250 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 251 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_NOT_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 252 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_AND, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 253 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_OR, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 254 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LOGICAL_NOT, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 255 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_UPLUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 256 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_UMINUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 257 "objectivec.y"
    { (yyval._expr) = (yyvsp[(2) - (3)]._expr); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 258 "objectivec.y"
    { (yyval._expr) = CreateIDExpression((yyvsp[(1) - (1)].id)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 259 "objectivec.y"
    { (yyval._expr) = CreateIntValueExpression((yyvsp[(1) - (1)].int_const)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 260 "objectivec.y"
    { (yyval._expr) = CreateFloatValueExpression((yyvsp[(1) - (1)].float_const)); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 261 "objectivec.y"
    { (yyval._expr) = CreateBoolValueExpression((yyvsp[(1) - (1)].bool_const)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 262 "objectivec.y"
    { (yyval._expr) = CreateCharValueExpression((yyvsp[(1) - (1)].char_const)); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 263 "objectivec.y"
    { (yyval._expr) = CreateStringValueExpression((yyvsp[(1) - (1)].string_const)); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 265 "objectivec.y"
    { (yyval._expr) =createMethodCall((yyvsp[(2) - (6)]._expr), (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].method_call_arg_list_st));}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 266 "objectivec.y"
    { (yyval._expr) = createArrayElemCall((yyvsp[(1) - (4)]._expr), (yyvsp[(3) - (4)]._expr)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 267 "objectivec.y"
    { (yyval._expr) = createInvariantCall((yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)].id));}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 268 "objectivec.y"
    { /*$$ = createFuncCall($1, $3);*/ }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 269 "objectivec.y"
    { /*$$ = createFuncCall($1, NULL); */}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 272 "objectivec.y"
    { (yyval._enum_decl) = CreateEnumDeclaration((yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)]._enum_list)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 275 "objectivec.y"
    { (yyval._enum_list) = AppendEnumeratorToList((yyvsp[(1) - (3)]._enum_list), (yyvsp[(3) - (3)]._enumerator)); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 276 "objectivec.y"
    { (yyval._enum_list) = CreateEnumeratorList((yyvsp[(1) - (1)]._enumerator)); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 279 "objectivec.y"
    { /* $$ = CreateEnumerator($1, -1); */ }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 280 "objectivec.y"
    {  /* $$ = CreateEnumerator($1, $3); */ }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 306 "objectivec.y"
    { (yyval.field_access_en) = A_PUBLIC; }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 307 "objectivec.y"
    { (yyval.field_access_en) = A_PROTECTED; }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 308 "objectivec.y"
    { (yyval.field_access_en) = A_PRIVATE; }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 311 "objectivec.y"
    { (yyval.class_invariant_declaration_st) = createClassInvariantDeclaration((yyvsp[(1) - (3)]._type), (yyvsp[(2) - (3)].id)); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 314 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = createClassInvariantsDeclarationList((yyvsp[(1) - (1)].class_invariant_declaration_st)); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 315 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = addToClassInvariantsDeclarationList((yyvsp[(1) - (2)].class_invariants_declaration_list_st), (yyvsp[(2) - (2)].class_invariant_declaration_st)); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 319 "objectivec.y"
    { (yyval.class_invariants_declaration_block_st) = createClassInvariantsDeclarationBlock((yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_invariants_declaration_list_st)); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 320 "objectivec.y"
    { (yyval.class_invariants_declaration_block_st) = createClassInvariantsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_invariants_declaration_list_st)); }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 324 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = createClassInvariantsDeclarationBlockList((yyvsp[(1) - (1)].class_invariants_declaration_block_st)); }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 325 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = addToClassInvariantsDeclarationBlockList((yyvsp[(1) - (2)].class_invariants_declaration_block_list_st), (yyvsp[(2) - (2)].class_invariants_declaration_block_st)); }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 328 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = NULL; }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 329 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = (yyvsp[(2) - (3)].class_invariants_declaration_block_list_st); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 332 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration( NULL, (yyvsp[(2) - (4)]._type), (yyvsp[(4) - (4)].id) );}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 339 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration((yyvsp[(1) - (6)].id), (yyvsp[(4) - (6)]._type), (yyvsp[(6) - (6)].id)); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 342 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 343 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 346 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 347 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 351 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToFrontClassMethodParamDeclarationList((yyvsp[(2) - (2)].class_method_param_declaration_list_st), (yyvsp[(1) - (2)].class_method_param_declaration_st)); }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 352 "objectivec.y"
    {(yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 356 "objectivec.y"
    {(yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 357 "objectivec.y"
    {(yyval.class_method_param_declaration_list_st) = NULL; }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 368 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st));}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 369 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st));}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 370 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL);}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 371 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL);}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 374 "objectivec.y"
    { (yyval.class_method_declaration_st) = (yyvsp[(1) - (2)].class_method_declaration_st); }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 379 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = createMethodsDeclarationList( (yyvsp[(1) - (1)].class_method_declaration_st)); }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 380 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = addToMethodsDeclarationList( (yyvsp[(1) - (2)].class_methods_declaration_list_st), (yyvsp[(2) - (2)].class_method_declaration_st)); }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 384 "objectivec.y"
    { (yyval.class_methods_declaration_block_st) = createClassMethodsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_methods_declaration_list_st)); }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 385 "objectivec.y"
    { (yyval.class_methods_declaration_block_st) = createClassMethodsDeclarationBlock( (yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_methods_declaration_list_st)); }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 388 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = createClassMethodsDeclarationBlockList( (yyvsp[(1) - (1)].class_methods_declaration_block_st)); }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 389 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = addToClassMethodsDeclarationBlockList( (yyvsp[(1) - (2)].class_methods_declaration_block_list_st), (yyvsp[(2) - (2)].class_methods_declaration_block_st)); }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 392 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = (yyvsp[(1) - (1)].class_methods_declaration_block_list_st); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 393 "objectivec.y"
    {(yyval.class_methods_declaration_block_list_st) = NULL; }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 396 "objectivec.y"
    { /*$$ = createClassDeclaration($2, $4, $5, $6); */}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 397 "objectivec.y"
    { /*$$ = createClassDeclaration($2, NULL, $3, $4);*/ }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 400 "objectivec.y"
    { (yyval.class_method_impl_st) = createClassMethodImpl((yyvsp[(1) - (2)].class_method_declaration_st), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 404 "objectivec.y"
    { (yyval.class_method_impl_list_st) = createClassMethodImplList((yyvsp[(1) - (1)].class_method_impl_st)); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 405 "objectivec.y"
    { (yyval.class_method_impl_list_st) = addToClassMethodImplList((yyvsp[(1) - (2)].class_method_impl_list_st), (yyvsp[(2) - (2)].class_method_impl_st)); }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 408 "objectivec.y"
    {(yyval.class_method_impl_list_st) = (yyvsp[(1) - (1)].class_method_impl_list_st); }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 409 "objectivec.y"
    {(yyval.class_method_impl_list_st) = NULL; }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 412 "objectivec.y"
    {}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 412 "objectivec.y"
    { (yyval.class_impl_st) = createClassImpl((yyvsp[(2) - (5)].id), (yyvsp[(3) - (5)].class_method_impl_list_st)); }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 417 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg(NULL, (yyvsp[(2) - (2)]._expr));}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 420 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)]._expr));}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 423 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 424 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st));}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 427 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 428 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st));}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 432 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToFrontMethodCallArgList((yyvsp[(2) - (2)].method_call_arg_list_st), (yyvsp[(1) - (2)].method_call_arg_st));}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 433 "objectivec.y"
    { (yyval.method_call_arg_list_st) = (yyvsp[(1) - (1)].method_call_arg_list_st); }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 436 "objectivec.y"
    { (yyval.method_call_arg_list_st) = (yyvsp[(1) - (1)].method_call_arg_list_st);}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 437 "objectivec.y"
    { (yyval.method_call_arg_list_st) = NULL; }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 441 "objectivec.y"
    { (yyval.expr_list_st) = createExprList((yyvsp[(1) - (1)]._expr));}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 442 "objectivec.y"
    { (yyval.expr_list_st) = addToExprList((yyvsp[(1) - (3)].expr_list_st), (yyvsp[(3) - (3)]._expr));}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 447 "objectivec.y"
    { (yyval.expr_list_st) = (yyvsp[(1) - (1)].expr_list_st);}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 448 "objectivec.y"
    { (yyval.expr_list_st) = NULL;}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 453 "objectivec.y"
    { (yyval.func_arg_st) =  createFuncArg((yyvsp[(1) - (2)]._type), (yyvsp[(2) - (2)].id));}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 456 "objectivec.y"
    { (yyval.func_arg_list_st) = createFuncArgList((yyvsp[(1) - (1)].func_arg_st)); }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 457 "objectivec.y"
    { (yyval.func_arg_list_st) = addToFuncArgList((yyvsp[(1) - (2)].func_arg_list_st), (yyvsp[(2) - (2)].func_arg_st)); }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 460 "objectivec.y"
    { (yyval.func_arg_list_st) = (yyvsp[(1) - (1)].func_arg_list_st); }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 461 "objectivec.y"
    { (yyval.func_arg_list_st) = NULL; }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 464 "objectivec.y"
    { (yyval.func_declaration_st) = createFuncDeclaration((yyvsp[(1) - (5)]._type), (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].func_arg_list_st)); }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 467 "objectivec.y"
    { (yyval.func_declaration_st) = (yyvsp[(1) - (2)].func_declaration_st); }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 470 "objectivec.y"
    { (yyval.func_impl_st) = createFuncImpl((yyvsp[(1) - (2)].func_declaration_st), (yyvsp[(2) - (2)]._stmt));}
    break;


/* Line 1792 of yacc.c  */
#line 2556 "objectivec.tab.c"
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
#line 476 "objectivec.y"
