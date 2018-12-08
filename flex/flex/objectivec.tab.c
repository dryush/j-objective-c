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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   636

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNRULES -- Number of states.  */
#define YYNSTATES  314

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
      21,    23,    25,    26,    30,    33,    36,    38,    40,    42,
      44,    46,    50,    56,    64,    70,    76,    83,    87,    92,
      99,   107,   118,   130,   133,   135,   137,   139,   141,   143,
     145,   147,   149,   153,   157,   161,   165,   169,   173,   179,
     183,   187,   191,   195,   199,   203,   207,   211,   214,   217,
     220,   224,   226,   228,   230,   232,   234,   236,   242,   247,
     252,   256,   261,   265,   271,   275,   277,   279,   283,   285,
     287,   289,   293,   298,   300,   303,   306,   308,   310,   313,
     316,   320,   325,   331,   338,   346,   353,   361,   370,   380,
     382,   385,   387,   390,   393,   395,   397,   398,   406,   415,
     423,   432,   438,   445,   451,   458,   461,   463,   466,   469,
     471,   473,   476,   478,   479,   487,   493,   500,   505,   508,
     510,   513,   515,   516,   521,   524,   528,   530,   533,   535,
     538,   541,   543,   545,   549,   551,   552,   555,   559,   564,
     570,   572,   576,   578,   579,   585,   592
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,   109,    -1,    93,    -1,    97,    -1,    72,
      -1,    58,    -1,    59,    58,    -1,    59,    -1,    61,    63,
      -1,    63,    -1,    61,    -1,    -1,    20,    71,    52,    -1,
      20,    52,    -1,    71,    52,    -1,    66,    -1,    65,    -1,
      67,    -1,    64,    -1,    52,    -1,    53,    62,    54,    -1,
      11,    55,    71,    50,    63,    -1,    11,    55,    71,    50,
      63,    12,    63,    -1,     9,    55,    71,    50,    63,    -1,
      69,     8,    29,    71,    52,    -1,     8,    40,     8,    29,
      71,    52,    -1,    69,     8,    52,    -1,     8,    40,     8,
      52,    -1,    69,     8,    49,     3,    51,    52,    -1,     8,
      40,     8,    49,     3,    51,    52,    -1,    69,     8,    49,
       3,    51,    29,    53,   104,    54,    52,    -1,     8,    40,
       8,    49,     3,    51,    29,    53,   104,    54,    52,    -1,
      21,     8,    -1,    70,    -1,    68,    -1,    22,    -1,    23,
      -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,    71,
      39,    71,    -1,    71,    38,    71,    -1,    71,    40,    71,
      -1,    71,    41,    71,    -1,    71,    42,    71,    -1,    71,
      29,    71,    -1,    71,    29,    53,   104,    54,    -1,    71,
      34,    71,    -1,    71,    37,    71,    -1,    71,    35,    71,
      -1,    71,    36,    71,    -1,    71,    33,    71,    -1,    71,
      32,    71,    -1,    71,    31,    71,    -1,    71,    30,    71,
      -1,    43,    71,    -1,    39,    71,    -1,    38,    71,    -1,
      55,    71,    50,    -1,     8,    -1,     3,    -1,     4,    -1,
       6,    -1,     5,    -1,     7,    -1,    49,    71,     8,   102,
      51,    -1,    49,    71,     8,    51,    -1,    71,    49,    71,
      51,    -1,    71,    48,     8,    -1,     8,    55,   103,    50,
      -1,     8,    55,    50,    -1,    68,    53,    73,    54,    52,
      -1,    73,    28,    74,    -1,    74,    -1,     8,    -1,     8,
      29,     3,    -1,    17,    -1,    18,    -1,    19,    -1,    69,
       8,    52,    -1,     8,    40,     8,    52,    -1,    76,    -1,
      77,    76,    -1,    75,    77,    -1,    77,    -1,    78,    -1,
      79,    78,    -1,    53,    54,    -1,    53,    79,    54,    -1,
      55,    69,    50,     8,    -1,    55,     8,    40,    50,     8,
      -1,    55,    69,    49,    51,    50,     8,    -1,    55,     8,
      40,    49,    51,    50,     8,    -1,     8,    56,    55,    69,
      50,     8,    -1,     8,    56,    55,     8,    40,    50,     8,
      -1,     8,    56,    55,    69,    49,    51,    50,     8,    -1,
       8,    56,    55,     8,    40,    49,    51,    50,     8,    -1,
      82,    -1,    83,    82,    -1,    81,    -1,    84,    81,    -1,
      81,    83,    -1,    84,    -1,    85,    -1,    -1,    38,    55,
      69,    50,     8,    56,    86,    -1,    38,    55,     8,    40,
      50,     8,    56,    86,    -1,    39,    55,    69,    50,     8,
      56,    86,    -1,    39,    55,     8,    40,    50,     8,    56,
      86,    -1,    38,    55,    69,    50,     8,    -1,    38,    55,
       8,    40,    50,     8,    -1,    39,    55,    69,    50,     8,
      -1,    39,    55,     8,    40,    50,     8,    -1,    87,    52,
      -1,    88,    -1,    89,    88,    -1,    75,    89,    -1,    89,
      -1,    90,    -1,    91,    90,    -1,    91,    -1,    -1,    16,
       8,    56,     8,    80,    92,    13,    -1,    16,     8,    80,
      92,    13,    -1,    16,     8,    56,     8,    92,    13,    -1,
      16,     8,    92,    13,    -1,    87,    64,    -1,    94,    -1,
      95,    94,    -1,    95,    -1,    -1,    15,     8,    96,    13,
      -1,    56,    71,    -1,     8,    56,    71,    -1,    98,    -1,
     100,    98,    -1,    99,    -1,   101,    99,    -1,    98,   101,
      -1,   100,    -1,    71,    -1,   103,    28,    71,    -1,   103,
      -1,    -1,    69,     8,    -1,     8,    40,     8,    -1,    69,
       8,    49,    51,    -1,     8,    40,     8,    49,    51,    -1,
     105,    -1,   106,    28,   105,    -1,   106,    -1,    -1,    69,
       8,    55,   107,    50,    -1,     8,    40,     8,    55,   107,
      50,    -1,   108,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   183,   183,   184,   185,   186,   189,   190,   193,   195,
     196,   199,   200,   203,   204,   205,   206,   207,   208,   209,
     210,   213,   216,   217,   220,   223,   224,   225,   226,   227,
     228,   229,   230,   234,   237,   238,   241,   242,   243,   244,
     245,   246,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   282,   285,   286,   289,   290,   316,   317,
     318,   321,   322,   325,   326,   330,   334,   335,   336,   339,
     340,   343,   344,   345,   346,   353,   354,   355,   356,   359,
     360,   363,   364,   368,   369,   373,   374,   385,   386,   387,
     388,   389,   390,   391,   392,   395,   400,   401,   406,   410,
     411,   412,   415,   416,   419,   420,   421,   422,   426,   430,
     431,   434,   435,   438,   443,   446,   449,   450,   453,   454,
     458,   459,   464,   465,   470,   471,   476,   477,   478,   479,
     482,   483,   486,   487,   490,   491,   494
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
  "prog_full", "stmt_list", "stmt_list_or_empty", "stmt", "compound_stmt",
  "if_stmt", "while_stmt", "var_decl", "enum_type", "type", "default_type",
  "expr", "enum_declaration", "enumerator_list", "enumerator",
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
  "class_methods_implementation_or_empty", "class_implementation",
  "method_call_noname_arg", "method_call_name_arg",
  "method_call_noname_args", "method_call_name_args", "method_call_args",
  "expr_list", "array_elems_or_empty", "func_arg", "func_args",
  "func_args_or_empty", "func_header", "func_implementation", YY_NULL
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
       0,    57,    58,    58,    58,    58,    59,    59,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    65,    65,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    69,    69,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    73,    73,    74,    74,    75,    75,
      75,    76,    76,    77,    77,    78,    79,    79,    79,    80,
      80,    81,    81,    81,    81,    82,    82,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    89,    89,    90,    91,
      91,    91,    92,    92,    93,    93,    93,    93,    94,    95,
      95,    96,    96,    97,    98,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   105,   105,
     106,   106,   107,   107,   108,   108,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     2,     1,     2,
       1,     1,     0,     3,     2,     2,     1,     1,     1,     1,
       1,     3,     5,     7,     5,     5,     6,     3,     4,     6,
       7,    10,    11,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       3,     1,     1,     1,     1,     1,     1,     5,     4,     4,
       3,     4,     3,     5,     3,     1,     1,     3,     1,     1,
       1,     3,     4,     1,     2,     2,     1,     1,     2,     2,
       3,     4,     5,     6,     7,     6,     7,     8,     9,     1,
       2,     1,     2,     2,     1,     1,     0,     7,     8,     7,
       8,     5,     6,     5,     6,     2,     1,     2,     2,     1,
       1,     2,     1,     0,     7,     5,     6,     4,     2,     1,
       2,     1,     0,     4,     2,     3,     1,     2,     1,     2,
       2,     1,     1,     3,     1,     0,     2,     3,     4,     5,
       1,     3,     1,     0,     5,     6,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    36,    37,    38,    39,    40,
      41,     6,     8,     0,    35,     0,    34,     5,     3,     4,
       0,     2,     0,   132,   123,    33,     7,     1,     0,     0,
      12,   156,     0,     0,     0,     0,   129,   131,     0,    78,
      79,    80,     0,     0,     0,   123,     0,   116,   119,   120,
     122,     0,    76,     0,    75,   153,    62,    63,    65,    64,
      66,    61,     0,     0,     0,     0,     0,     0,     0,    20,
       0,    11,     0,    10,    19,    17,    16,    18,    35,     0,
       0,   153,     0,     0,   128,   130,   133,     0,    89,     0,
       0,    83,    86,    87,     0,   123,   118,     0,   115,   117,
     121,   127,     0,     0,     0,     0,     0,   150,   152,     0,
       0,     0,     0,     0,    61,    14,     0,    59,    58,    57,
       0,     0,     9,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,    85,
      84,    90,    88,   123,     0,   125,    77,    74,    73,     0,
     146,     0,   154,     0,    72,   142,     0,     0,     0,    13,
       0,    60,     0,     0,    27,   145,    47,    56,    55,    54,
      53,    49,    51,    52,    50,    43,    42,    44,    45,    46,
      70,     0,   155,     0,     0,     0,     0,     0,    81,     0,
     126,   147,     0,   151,     0,     0,    28,     0,    71,     0,
       0,    68,     0,   136,   141,     0,     0,     0,   144,     0,
      69,     0,   111,     0,   113,    82,   124,     0,   148,     0,
       0,   143,    24,    22,   134,     0,   138,   140,   137,    67,
      25,     0,    48,   112,   106,   114,   106,   149,    26,     0,
       0,     0,   139,     0,    29,   106,     0,   101,   104,   105,
     107,   106,   109,     0,    30,    23,   135,   145,   108,     0,
       0,     0,    99,   103,   102,   110,   145,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,    91,     0,
       0,    31,     0,    92,     0,     0,     0,    32,     0,    93,
       0,     0,     0,    94,     0,     0,     0,    95,     0,    96,
       0,     0,    97,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    16,    80,    17,    53,    54,    44,    91,
      92,    93,    94,    45,   257,   272,   273,   258,   259,   260,
      46,    47,    48,    49,    50,    51,    18,    36,    37,    38,
      19,   213,   236,   214,   237,   215,   218,   219,   107,   108,
     109,    20,    21
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -231
static const yytype_int16 yypact[] =
{
     258,     7,    45,    48,    54,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,   258,    99,    65,    86,  -231,  -231,  -231,  -231,
      68,  -231,   121,    41,    78,  -231,  -231,  -231,   124,    80,
     148,  -231,    83,    93,   103,    68,  -231,    41,   128,  -231,
    -231,  -231,     6,   152,    41,    87,   114,  -231,    41,  -231,
      90,   154,   150,   -18,  -231,   213,  -231,  -231,  -231,  -231,
    -231,   -21,   126,   127,    81,   221,   221,   221,   221,  -231,
     221,   148,   129,  -231,  -231,  -231,  -231,  -231,  -231,   180,
     282,   213,   502,   509,  -231,  -231,  -231,   153,  -231,   182,
     529,  -231,   529,  -231,    -2,    84,    41,   179,  -231,  -231,
    -231,  -231,   191,   124,   143,   156,   190,  -231,   171,   162,
     194,   203,   221,   221,   149,  -231,   306,    79,    79,    79,
     261,   401,  -231,  -231,   -11,   212,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   205,
     221,  -231,   172,   183,   181,   192,   193,   222,   195,   529,
    -231,  -231,  -231,    87,   220,  -231,  -231,  -231,  -231,   236,
     196,   213,  -231,    62,  -231,   467,   -15,   423,   445,  -231,
      42,  -231,   221,   245,  -231,   221,   467,   553,   571,   587,
     587,   500,   500,   500,   500,   136,   136,    79,    79,    79,
    -231,   378,  -231,   199,   246,   207,   254,   211,  -231,   255,
    -231,   223,   224,  -231,   221,   268,  -231,   221,  -231,   148,
     148,  -231,   221,   269,   230,   227,   330,   237,   259,   250,
    -231,   297,   251,   298,   252,  -231,  -231,   274,  -231,   354,
     275,   467,  -231,   315,   467,   272,  -231,   269,  -231,  -231,
    -231,    -8,  -231,   273,   277,   293,   277,  -231,  -231,    -7,
     148,   221,  -231,   280,  -231,   277,   536,   342,   277,  -231,
    -231,   277,  -231,   299,  -231,  -231,   467,   221,  -231,   311,
      94,   300,  -231,   342,  -231,  -231,   221,   303,    97,   302,
     365,   319,  -231,   321,   324,   326,   372,   331,  -231,   556,
     345,  -231,   348,  -231,   391,   360,   113,  -231,   393,  -231,
     115,   353,   397,  -231,   370,   414,   373,  -231,   374,  -231,
     417,   420,  -231,  -231
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,   432,  -231,  -231,  -231,  -231,   -70,    23,  -231,  -231,
    -231,   100,     0,  -231,   -62,  -231,  -231,   343,   -33,   -72,
     355,   375,  -231,   352,   208,   175,  -231,  -231,  -231,  -207,
       3,   -37,   424,   438,  -231,   -38,  -231,   430,  -231,  -231,
    -231,   256,   253,  -231,  -231,  -231,   380,  -230,   328,  -231,
     411,  -231,  -231
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      15,   122,   116,   117,   118,   119,   120,    97,   121,    90,
     103,    99,    15,   207,    87,    39,    40,    41,   172,   110,
     150,   253,   263,    39,    40,    41,    35,     4,     5,     6,
       7,     8,     9,    10,   111,   208,   104,   277,   173,   262,
      35,   174,    89,    31,   254,   264,   283,    22,   268,   165,
     167,   168,   151,    23,   275,   106,    24,   154,    84,    99,
      88,    90,    25,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   150,   191,    33,
      34,   106,   144,   146,    56,    57,    58,    59,    60,   114,
      89,   204,    89,   211,    29,    39,    40,    41,   212,    27,
      14,    39,    40,    41,    39,    40,    41,    39,    40,    41,
     216,   205,    14,   165,   206,   199,    33,    34,    28,    65,
      66,    30,    33,    34,    67,    33,    34,   139,   140,    32,
      68,    42,    52,   115,    43,    55,    70,    42,    81,   232,
     233,    86,   229,   279,   280,   231,   285,   286,    82,    89,
     234,    56,    57,    58,    59,    60,    61,    62,    83,    63,
      95,   106,   301,   302,   304,   305,    98,   101,    64,     4,
       5,     6,     7,     8,     9,    10,   136,   137,   138,   102,
     265,   112,   113,   123,   139,   140,    65,    66,   124,   266,
     148,    67,   155,   147,   156,   158,   159,    68,   160,   161,
      69,    30,   163,    70,   111,   165,    56,    57,    58,    59,
      60,   114,   162,   190,   165,    56,    57,    58,    59,    60,
     114,   105,   192,   193,    56,    57,    58,    59,    60,   114,
     197,   194,   195,   200,     4,     5,     6,     7,     8,     9,
      10,    65,    66,   196,   201,   202,    67,   198,   217,   221,
      65,    66,    68,   164,   222,    67,   270,   223,    70,    65,
      66,    68,   224,   225,    67,   175,     1,    70,   226,   170,
      68,   230,   227,     2,     3,   228,    70,   235,   239,     4,
       5,     6,     7,     8,     9,    10,   212,   207,   241,   296,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   242,   243,   245,   244,   246,   139,
     140,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   247,   249,   250,   251,   255,
     139,   140,   256,   267,   141,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   261,
     271,   278,   276,   287,   139,   140,   281,   284,   169,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   288,   289,   290,   291,   292,   139,   140,
     293,   294,   240,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   297,   298,   299,
     300,   303,   139,   140,   306,   307,   248,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   308,   309,   310,   311,   312,   139,   140,   313,   220,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    26,   149,   157,   153,   282,   139,
     140,   171,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   274,    85,    96,   152,
     238,   139,   140,   209,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   100,   203,
     252,   166,   142,   139,   140,   210,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     143,     0,     0,     0,     0,   139,   140,   145,     0,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
       4,     5,     6,     7,     8,     9,    10,    87,   134,   135,
     136,   137,   138,     0,   269,     0,     0,     0,   139,   140,
       4,     5,     6,     7,     8,     9,    10,     4,     5,     6,
       7,     8,     9,    10,   295,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,     0,     0,     0,     0,
       0,   139,   140,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,     0,     0,     0,     0,     0,   139,
     140,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,     0,     0,   139,   140
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    71,    64,    65,    66,    67,    68,    45,    70,    42,
      28,    48,    12,    28,     8,    17,    18,    19,    29,    40,
      92,    29,    29,    17,    18,    19,    23,    21,    22,    23,
      24,    25,    26,    27,    55,    50,    54,   267,    49,   246,
      37,    52,    42,    20,    52,    52,   276,    40,   255,   111,
     112,   113,    54,     8,   261,    55,     8,    95,    35,    96,
      54,    94,     8,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   149,   140,    38,
      39,    81,    82,    83,     3,     4,     5,     6,     7,     8,
      90,    29,    92,    51,     8,    17,    18,    19,    56,     0,
       0,    17,    18,    19,    17,    18,    19,    17,    18,    19,
     172,    49,    12,   175,    52,   153,    38,    39,    53,    38,
      39,    53,    38,    39,    43,    38,    39,    48,    49,     8,
      49,    53,     8,    52,    56,    55,    55,    53,    55,   209,
     210,    13,   204,    49,    50,   207,    49,    50,    55,   149,
     212,     3,     4,     5,     6,     7,     8,     9,    55,    11,
       8,   161,    49,    50,    49,    50,    52,    13,    20,    21,
      22,    23,    24,    25,    26,    27,    40,    41,    42,    29,
     250,    55,    55,    54,    48,    49,    38,    39,     8,   251,
       8,    43,    13,    40,     3,    52,    40,    49,     8,    28,
      52,    53,     8,    55,    55,   267,     3,     4,     5,     6,
       7,     8,    50,     8,   276,     3,     4,     5,     6,     7,
       8,     8,    50,    40,     3,     4,     5,     6,     7,     8,
       8,    50,    40,    13,    21,    22,    23,    24,    25,    26,
      27,    38,    39,    50,     8,    49,    43,    52,     3,    50,
      38,    39,    49,    50,     8,    43,   256,    50,    55,    38,
      39,    49,     8,    52,    43,    53,     8,    55,    13,     8,
      49,     3,    49,    15,    16,    51,    55,     8,    51,    21,
      22,    23,    24,    25,    26,    27,    56,    28,    51,   289,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    54,     8,     8,    56,    56,    48,
      49,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    51,    51,    12,    56,    56,
      48,    49,    55,    53,    52,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    56,
       8,    40,    53,    51,    48,    49,    56,    54,    52,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     8,    55,    54,    52,    51,    48,    49,
       8,    50,    52,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    52,    50,     8,
      40,     8,    48,    49,    51,     8,    52,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    51,     8,    50,    50,     8,    48,    49,     8,    51,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    12,    90,   103,    95,   273,    48,
      49,    50,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   258,    37,    44,    94,
     214,    48,    49,    50,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    50,   161,
     237,   111,    81,    48,    49,    50,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       8,    -1,    -1,    -1,    -1,    48,    49,     8,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      21,    22,    23,    24,    25,    26,    27,     8,    38,    39,
      40,    41,    42,    -1,     8,    -1,    -1,    -1,    48,    49,
      21,    22,    23,    24,    25,    26,    27,    21,    22,    23,
      24,    25,    26,    27,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    49,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    15,    16,    21,    22,    23,    24,    25,    26,
      27,    58,    59,    60,    68,    69,    70,    72,    93,    97,
     108,   109,    40,     8,     8,     8,    58,     0,    53,     8,
      53,    64,     8,    38,    39,    87,    94,    95,    96,    17,
      18,    19,    53,    56,    75,    80,    87,    88,    89,    90,
      91,    92,     8,    73,    74,    55,     3,     4,     5,     6,
       7,     8,     9,    11,    20,    38,    39,    43,    49,    52,
      55,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      71,    55,    55,    55,    64,    94,    13,     8,    54,    69,
      75,    76,    77,    78,    79,     8,    89,    92,    52,    88,
      90,    13,    29,    28,    54,     8,    69,   105,   106,   107,
      40,    55,    55,    55,     8,    52,    71,    71,    71,    71,
      71,    71,    63,    54,     8,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    48,
      49,    52,   107,     8,    69,     8,    69,    40,     8,    77,
      76,    54,    78,    80,    92,    13,     3,    74,    52,    40,
       8,    28,    50,     8,    50,    71,   103,    71,    71,    52,
       8,    50,    29,    49,    52,    53,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
       8,    71,    50,    40,    50,    40,    50,     8,    52,    92,
      13,     8,    49,   105,    29,    49,    52,    28,    50,    50,
      50,    51,    56,    98,   100,   102,    71,     3,   103,   104,
      51,    50,     8,    50,     8,    52,    13,    49,    51,    71,
       3,    71,    63,    63,    71,     8,    99,   101,    98,    51,
      52,    51,    54,     8,    56,     8,    56,    51,    52,    51,
      12,    56,    99,    29,    52,    56,    55,    81,    84,    85,
      86,    56,    86,    29,    52,    63,    71,    53,    86,     8,
      69,     8,    82,    83,    81,    86,    53,   104,    40,    49,
      50,    56,    82,   104,    54,    49,    50,    51,     8,    55,
      54,    52,    51,     8,    50,     8,    69,    52,    50,     8,
      40,    49,    50,     8,    49,    50,    51,     8,    51,     8,
      50,    50,     8,     8
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
    { (yyval.extern_code_st) = createExternCode(NULL, (yyvsp[(1) - (1)].func_impl_st), NULL, NULL, NULL);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 184 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, (yyvsp[(1) - (1)].class_declaration_st), NULL, NULL);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 185 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, (yyvsp[(1) - (1)].class_impl_st), NULL);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 186 "objectivec.y"
    { (yyval.extern_code_st) = createExternCode(NULL, NULL, NULL, NULL, (yyvsp[(1) - (1)]._enum_decl));}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 189 "objectivec.y"
    { (yyval.program_st) = createProgram((yyvsp[(1) - (1)].extern_code_st));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 190 "objectivec.y"
    { (yyval.program_st) = addToProgram((yyvsp[(1) - (2)].program_st), (yyvsp[(2) - (2)].extern_code_st));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 193 "objectivec.y"
    { root = (yyvsp[(1) - (1)].program_st); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 195 "objectivec.y"
    { (yyval._stmt_list) = AppendStatementToList((yyvsp[(1) - (2)]._stmt_list), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 196 "objectivec.y"
    { (yyval._stmt_list) = CreateStatementList((yyvsp[(1) - (1)]._stmt)); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 199 "objectivec.y"
    { (yyval._stmt_list) = (yyvsp[(1) - (1)]._stmt_list); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 200 "objectivec.y"
    { (yyval._stmt_list) = NULL; }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 203 "objectivec.y"
    { (yyval._stmt) = CreateReturnStatement((yyvsp[(2) - (3)]._expr));}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 204 "objectivec.y"
    { (yyval._stmt) = CreateReturnStatement(NULL);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 205 "objectivec.y"
    { (yyval._stmt) = CreateExpressionStatement((yyvsp[(1) - (2)]._expr)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 206 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 207 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 208 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 209 "objectivec.y"
    { (yyval._stmt) = (yyvsp[(1) - (1)]._stmt); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 210 "objectivec.y"
    { }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 213 "objectivec.y"
    { (yyval._stmt) = CreateCompoundStatement((yyvsp[(2) - (3)]._stmt_list)); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 216 "objectivec.y"
    { (yyval._stmt) = CreateIfStatement((yyvsp[(3) - (5)]._expr), (yyvsp[(5) - (5)]._stmt), NULL); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 217 "objectivec.y"
    { (yyval._stmt) = CreateIfStatement((yyvsp[(3) - (7)]._expr), (yyvsp[(5) - (7)]._stmt), (yyvsp[(7) - (7)]._stmt)); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 220 "objectivec.y"
    { (yyval._stmt) = CreateWhileStatement((yyvsp[(3) - (5)]._expr), (yyvsp[(5) - (5)]._stmt)); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 223 "objectivec.y"
    { (yyval._stmt) = CreateVarDeclWithInit((yyvsp[(1) - (5)]._type), (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)]._expr)); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 224 "objectivec.y"
    { (yyval._stmt) = CreateVarDeclWithInit(createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(1) - (6)].id), NULL)), (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)]._expr)); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 225 "objectivec.y"
    { (yyval._stmt) = CreateVarDeclWithInit((yyvsp[(1) - (3)]._type), (yyvsp[(2) - (3)].id), NULL); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 226 "objectivec.y"
    { (yyval._stmt) = CreateVarDeclWithInit(createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(1) - (4)].id), NULL)), (yyvsp[(3) - (4)].id), NULL); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 227 "objectivec.y"
    { (yyval._stmt) = CreateArrayDeclWithInit((yyvsp[(1) - (6)]._type), (yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].int_const), NULL);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 228 "objectivec.y"
    { (yyval._stmt) = CreateArrayDeclWithInit(createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(1) - (7)].id), NULL)), (yyvsp[(3) - (7)].id), (yyvsp[(5) - (7)].int_const), NULL);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 229 "objectivec.y"
    { (yyval._stmt) = CreateArrayDeclWithInit((yyvsp[(1) - (10)]._type), (yyvsp[(2) - (10)].id), (yyvsp[(4) - (10)].int_const), (yyvsp[(8) - (10)].expr_list_st));}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 230 "objectivec.y"
    { (yyval._stmt) = CreateArrayDeclWithInit(createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(1) - (11)].id), NULL)), (yyvsp[(3) - (11)].id), (yyvsp[(5) - (11)].int_const), (yyvsp[(9) - (11)].expr_list_st));}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 234 "objectivec.y"
    { (yyval._type) = createType(TYPE_CUSTOM, (yyvsp[(2) - (2)].id), NULL); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 237 "objectivec.y"
    { (yyval._type) = (yyvsp[(1) - (1)]._type); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 238 "objectivec.y"
    { (yyval._type) = (yyvsp[(1) - (1)]._type); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 241 "objectivec.y"
    { (yyval._type) = createType(TYPE_INT, NULL, NULL);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 242 "objectivec.y"
    { (yyval._type) = createType(TYPE_FLOAT, NULL, NULL);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 243 "objectivec.y"
    { (yyval._type) = createType(TYPE_STRING, NULL, NULL);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 244 "objectivec.y"
    { (yyval._type) = createType(TYPE_CHAR, NULL, NULL);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 245 "objectivec.y"
    { (yyval._type) = createType(TYPE_BOOL, NULL, NULL);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 246 "objectivec.y"
    { (yyval._type) = createType(TYPE_VOID, NULL, NULL);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 249 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_ADD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 250 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_SUB, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 251 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_MUL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 252 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_DIV, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 253 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_MOD, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 254 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_ASSIGN, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 255 "objectivec.y"
    { (yyval._expr) = CreateArrayInitExpr((yyvsp[(1) - (5)]._expr), (yyvsp[(4) - (5)].expr_list_st));}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 256 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LESS, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 257 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LESS_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 258 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_GREATER, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 259 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_GREATER_OR_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 260 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 261 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_NOT_EQUAL, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 262 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_AND, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 263 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_OR, (yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 264 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_LOGICAL_NOT, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 265 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_UPLUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 266 "objectivec.y"
    { (yyval._expr) = CreateExpression(OP_UMINUS, (yyvsp[(2) - (2)]._expr), NULL); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 267 "objectivec.y"
    { (yyval._expr) = (yyvsp[(2) - (3)]._expr); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 268 "objectivec.y"
    { (yyval._expr) = CreateIDExpression((yyvsp[(1) - (1)].id)); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 269 "objectivec.y"
    { (yyval._expr) = CreateIntValueExpression((yyvsp[(1) - (1)].int_const)); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 270 "objectivec.y"
    { (yyval._expr) = CreateFloatValueExpression((yyvsp[(1) - (1)].float_const)); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 271 "objectivec.y"
    { (yyval._expr) = CreateBoolValueExpression((yyvsp[(1) - (1)].bool_const)); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 272 "objectivec.y"
    { (yyval._expr) = CreateCharValueExpression((yyvsp[(1) - (1)].char_const)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 273 "objectivec.y"
    { (yyval._expr) = CreateStringValueExpression((yyvsp[(1) - (1)].string_const)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 274 "objectivec.y"
    { (yyval._expr) = createMethodCall((yyvsp[(2) - (5)]._expr), (yyvsp[(3) - (5)].id), (yyvsp[(4) - (5)].method_call_arg_list_st)); }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 275 "objectivec.y"
    { (yyval._expr) = createMethodCall((yyvsp[(2) - (4)]._expr), (yyvsp[(3) - (4)].id), NULL); }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 276 "objectivec.y"
    { (yyval._expr) = createArrayElemCall((yyvsp[(1) - (4)]._expr), (yyvsp[(3) - (4)]._expr)); }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 277 "objectivec.y"
    { (yyval._expr) = createInvariantCall((yyvsp[(1) - (3)]._expr), (yyvsp[(3) - (3)].id)); }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 278 "objectivec.y"
    { (yyval._expr) = createFuncCall((yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].expr_list_st)); }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 279 "objectivec.y"
    { (yyval._expr) = createFuncCall((yyvsp[(1) - (3)].id), NULL); }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 282 "objectivec.y"
    { (yyval._enum_decl) = CreateEnumDeclaration((yyvsp[(1) - (5)]._type)->name, (yyvsp[(3) - (5)]._enum_list)); }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 285 "objectivec.y"
    { (yyval._enum_list) = AppendEnumeratorToList((yyvsp[(1) - (3)]._enum_list), (yyvsp[(3) - (3)]._enumerator)); }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 286 "objectivec.y"
    { (yyval._enum_list) = CreateEnumeratorList((yyvsp[(1) - (1)]._enumerator)); }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 289 "objectivec.y"
    { (yyval._enumerator) = CreateEnumerator((yyvsp[(1) - (1)].id)); }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 290 "objectivec.y"
    { (yyval._enumerator) = CreateEnumeratorWithVal((yyvsp[(1) - (3)].id), (yyvsp[(3) - (3)].int_const)); }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 316 "objectivec.y"
    { (yyval.field_access_en) = A_PUBLIC; }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 317 "objectivec.y"
    { (yyval.field_access_en) = A_PROTECTED; }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 318 "objectivec.y"
    { (yyval.field_access_en) = A_PRIVATE; }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 321 "objectivec.y"
    { (yyval.class_invariant_declaration_st) = createClassInvariantDeclaration((yyvsp[(1) - (3)]._type), (yyvsp[(2) - (3)].id)); }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 322 "objectivec.y"
    { (yyval.class_invariant_declaration_st) = createClassInvariantDeclaration(createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(1) - (4)].id), NULL)), (yyvsp[(3) - (4)].id)); }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 325 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = createClassInvariantsDeclarationList((yyvsp[(1) - (1)].class_invariant_declaration_st)); }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 326 "objectivec.y"
    { (yyval.class_invariants_declaration_list_st) = addToClassInvariantsDeclarationList((yyvsp[(1) - (2)].class_invariants_declaration_list_st), (yyvsp[(2) - (2)].class_invariant_declaration_st)); }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 330 "objectivec.y"
    { (yyval.class_invariants_declaration_block_st) = createClassInvariantsDeclarationBlock((yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_invariants_declaration_list_st)); }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 334 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = createClassInvariantsDeclarationBlockList( createClassInvariantsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_invariants_declaration_list_st))); }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 335 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = createClassInvariantsDeclarationBlockList((yyvsp[(1) - (1)].class_invariants_declaration_block_st)); }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 336 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = addToClassInvariantsDeclarationBlockList((yyvsp[(1) - (2)].class_invariants_declaration_block_list_st), (yyvsp[(2) - (2)].class_invariants_declaration_block_st)); }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 339 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = NULL; }
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 340 "objectivec.y"
    { (yyval.class_invariants_declaration_block_list_st) = (yyvsp[(2) - (3)].class_invariants_declaration_block_list_st); }
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 343 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration( NULL, (yyvsp[(2) - (4)]._type), (yyvsp[(4) - (4)].id) ); }
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 344 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration( NULL, createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(2) - (5)].id), NULL)), (yyvsp[(5) - (5)].id) ); }
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 345 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration( NULL, createType(TYPE_ARRAY, NULL, (yyvsp[(2) - (6)]._type)), (yyvsp[(6) - (6)].id) ); }
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 346 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration( NULL, createType(TYPE_ARRAY, NULL, createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(2) - (7)].id), NULL))), (yyvsp[(7) - (7)].id) ); }
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 353 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration((yyvsp[(1) - (6)].id), (yyvsp[(4) - (6)]._type), (yyvsp[(6) - (6)].id)); }
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 354 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration((yyvsp[(1) - (7)].id), createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(4) - (7)].id), NULL)), (yyvsp[(7) - (7)].id)); }
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 355 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration((yyvsp[(1) - (8)].id), createType(TYPE_ARRAY, NULL, (yyvsp[(4) - (8)]._type)), (yyvsp[(8) - (8)].id)); }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 356 "objectivec.y"
    { (yyval.class_method_param_declaration_st) = createClassMethodParamDeclaration((yyvsp[(1) - (9)].id), createType(TYPE_ARRAY, NULL, createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(4) - (9)].id), NULL))), (yyvsp[(9) - (9)].id)); }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 359 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 360 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 363 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = createClassMethodParamDeclarationList((yyvsp[(1) - (1)].class_method_param_declaration_st)); }
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 364 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToClassMethodParamDeclarationList((yyvsp[(1) - (2)].class_method_param_declaration_list_st), (yyvsp[(2) - (2)].class_method_param_declaration_st)); }
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 368 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = addToFrontClassMethodParamDeclarationList((yyvsp[(2) - (2)].class_method_param_declaration_list_st), (yyvsp[(1) - (2)].class_method_param_declaration_st)); }
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 369 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 373 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = (yyvsp[(1) - (1)].class_method_param_declaration_list_st); }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 374 "objectivec.y"
    { (yyval.class_method_param_declaration_list_st) = NULL; }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 385 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st)); }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 386 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(3) - (8)].id), NULL)), (yyvsp[(6) - (8)].id), (yyvsp[(8) - (8)].class_method_param_declaration_list_st)); }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 387 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (7)]._type), (yyvsp[(5) - (7)].id), (yyvsp[(7) - (7)].class_method_param_declaration_list_st)); }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 388 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(3) - (8)].id), NULL)), (yyvsp[(6) - (8)].id), (yyvsp[(8) - (8)].class_method_param_declaration_list_st)); }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 389 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL); }
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 390 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(NON_STATIC, createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(3) - (6)].id), NULL)), (yyvsp[(6) - (6)].id), NULL); }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 391 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, (yyvsp[(3) - (5)]._type), (yyvsp[(5) - (5)].id), NULL); }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 392 "objectivec.y"
    { (yyval.class_method_declaration_st) = createMethodDeclaration(STATIC, createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(3) - (6)].id), NULL)), (yyvsp[(6) - (6)].id), NULL); }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 395 "objectivec.y"
    { (yyval.class_method_declaration_st) = (yyvsp[(1) - (2)].class_method_declaration_st); }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 400 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = createMethodsDeclarationList( (yyvsp[(1) - (1)].class_method_declaration_st)); }
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 401 "objectivec.y"
    { (yyval.class_methods_declaration_list_st) = addToMethodsDeclarationList( (yyvsp[(1) - (2)].class_methods_declaration_list_st), (yyvsp[(2) - (2)].class_method_declaration_st)); }
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 406 "objectivec.y"
    { (yyval.class_methods_declaration_block_st) = createClassMethodsDeclarationBlock( (yyvsp[(1) - (2)].field_access_en), (yyvsp[(2) - (2)].class_methods_declaration_list_st)); }
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 410 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = createClassMethodsDeclarationBlockList(createClassMethodsDeclarationBlock(A_NOT_SET, (yyvsp[(1) - (1)].class_methods_declaration_list_st))); }
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 411 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = createClassMethodsDeclarationBlockList( (yyvsp[(1) - (1)].class_methods_declaration_block_st)); }
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 412 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = addToClassMethodsDeclarationBlockList( (yyvsp[(1) - (2)].class_methods_declaration_block_list_st), (yyvsp[(2) - (2)].class_methods_declaration_block_st)); }
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 415 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = (yyvsp[(1) - (1)].class_methods_declaration_block_list_st); }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 416 "objectivec.y"
    { (yyval.class_methods_declaration_block_list_st) = NULL; }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 419 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (7)].id), (yyvsp[(4) - (7)].id), (yyvsp[(5) - (7)].class_invariants_declaration_block_list_st), (yyvsp[(6) - (7)].class_methods_declaration_block_list_st)); }
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 420 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (5)].id), NULL, (yyvsp[(3) - (5)].class_invariants_declaration_block_list_st), (yyvsp[(4) - (5)].class_methods_declaration_block_list_st)); }
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 421 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].id), NULL, (yyvsp[(5) - (6)].class_methods_declaration_block_list_st)); }
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 422 "objectivec.y"
    { (yyval.class_declaration_st) = createClassDeclaration((yyvsp[(2) - (4)].id), NULL, NULL, (yyvsp[(3) - (4)].class_methods_declaration_block_list_st)); }
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 426 "objectivec.y"
    { (yyval.class_method_impl_st) = createClassMethodImpl((yyvsp[(1) - (2)].class_method_declaration_st), (yyvsp[(2) - (2)]._stmt)); }
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 430 "objectivec.y"
    { (yyval.class_method_impl_list_st) = createClassMethodImplList((yyvsp[(1) - (1)].class_method_impl_st)); }
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 431 "objectivec.y"
    { (yyval.class_method_impl_list_st) = addToClassMethodImplList((yyvsp[(1) - (2)].class_method_impl_list_st), (yyvsp[(2) - (2)].class_method_impl_st)); }
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 434 "objectivec.y"
    { (yyval.class_method_impl_list_st) = (yyvsp[(1) - (1)].class_method_impl_list_st); }
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 435 "objectivec.y"
    {(yyval.class_method_impl_list_st) = NULL; }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 438 "objectivec.y"
    { (yyval.class_impl_st) = createClassImpl((yyvsp[(2) - (4)].id), (yyvsp[(3) - (4)].class_method_impl_list_st)); }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 443 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg(NULL, (yyvsp[(2) - (2)]._expr)); }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 446 "objectivec.y"
    { (yyval.method_call_arg_st) = createMethodCallArg((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)]._expr)); }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 449 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 450 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st)); }
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 453 "objectivec.y"
    { (yyval.method_call_arg_list_st) = createMethodCallArgList((yyvsp[(1) - (1)].method_call_arg_st)); }
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 454 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToMethodCallArgList((yyvsp[(1) - (2)].method_call_arg_list_st), (yyvsp[(2) - (2)].method_call_arg_st)); }
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 458 "objectivec.y"
    { (yyval.method_call_arg_list_st) = addToFrontMethodCallArgList((yyvsp[(2) - (2)].method_call_arg_list_st), (yyvsp[(1) - (2)].method_call_arg_st)); }
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 459 "objectivec.y"
    { (yyval.method_call_arg_list_st) = (yyvsp[(1) - (1)].method_call_arg_list_st); }
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 464 "objectivec.y"
    { (yyval.expr_list_st) = createExprList((yyvsp[(1) - (1)]._expr)); }
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 465 "objectivec.y"
    { (yyval.expr_list_st) = addToExprList((yyvsp[(1) - (3)].expr_list_st), (yyvsp[(3) - (3)]._expr)); }
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 470 "objectivec.y"
    { (yyval.expr_list_st) = (yyvsp[(1) - (1)].expr_list_st); }
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 471 "objectivec.y"
    { (yyval.expr_list_st) = NULL; }
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 476 "objectivec.y"
    { (yyval.func_arg_st) =  createFuncArg((yyvsp[(1) - (2)]._type), (yyvsp[(2) - (2)].id)); }
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 477 "objectivec.y"
    { (yyval.func_arg_st) =  createFuncArg(createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(1) - (3)].id), NULL)), (yyvsp[(3) - (3)].id)); }
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 478 "objectivec.y"
    { (yyval.func_arg_st) =  createFuncArg(createType(TYPE_ARRAY, NULL, (yyvsp[(1) - (4)]._type)), (yyvsp[(2) - (4)].id)); }
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 479 "objectivec.y"
    { (yyval.func_arg_st) =  createFuncArg(createType(TYPE_ARRAY, NULL, createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(1) - (5)].id), NULL))), (yyvsp[(3) - (5)].id)); }
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 482 "objectivec.y"
    { (yyval.func_arg_list_st) = createFuncArgList((yyvsp[(1) - (1)].func_arg_st)); }
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 483 "objectivec.y"
    { (yyval.func_arg_list_st) = addToFuncArgList((yyvsp[(1) - (3)].func_arg_list_st), (yyvsp[(3) - (3)].func_arg_st)); }
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 486 "objectivec.y"
    { (yyval.func_arg_list_st) = (yyvsp[(1) - (1)].func_arg_list_st); }
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 487 "objectivec.y"
    { (yyval.func_arg_list_st) = NULL; }
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 490 "objectivec.y"
    { (yyval.func_declaration_st) = createFuncDeclaration((yyvsp[(1) - (5)]._type), (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].func_arg_list_st)); }
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 491 "objectivec.y"
    { (yyval.func_declaration_st) = createFuncDeclaration(createType(TYPE_POINTER, 0, createType(TYPE_CUSTOM, (yyvsp[(1) - (6)].id), NULL)), (yyvsp[(3) - (6)].id), (yyvsp[(5) - (6)].func_arg_list_st)); }
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 494 "objectivec.y"
    { (yyval.func_impl_st) = createFuncImpl((yyvsp[(1) - (2)].func_declaration_st), (yyvsp[(2) - (2)]._stmt)); }
    break;


/* Line 1792 of yacc.c  */
#line 2739 "objectivec.tab.c"
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
#line 497 "objectivec.y"

