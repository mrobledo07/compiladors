/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    extern int yylex();
    extern int yylineno;
    void yyerror(char *s);
    extern FILE *yyout;

    #define MAX_STACK_SIZE 100

    char *repeat_stack[MAX_STACK_SIZE];
    int stack_top = -1;  

    void push_repeat_stack(char *temp_var) {
        if (stack_top < MAX_STACK_SIZE - 1) {
            repeat_stack[++stack_top] = temp_var;
        } else {
            printf("Error: Stack overflow.\n");
        }
    }

    char *pop_repeat_stack() {
        if (stack_top >= 0) {
            return repeat_stack[stack_top--];
        } else {
            printf("Error: Stack empty.\n");
            return NULL;
        }
    }

    int array_size = 1;
    char *array_elems = NULL;
    extern int n_instructions;

    char *temporal_var_switch = NULL;

#line 110 "build/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_ENDLINE = 4,                    /* ENDLINE  */
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_REAL = 7,                       /* REAL  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_BOOLEAN = 9,                    /* BOOLEAN  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_MULT = 12,                      /* MULT  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_MOD = 14,                       /* MOD  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_GE = 16,                        /* GE  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_PI = 24,                        /* PI  */
  YYSYMBOL_E = 25,                         /* E  */
  YYSYMBOL_LBRACKET = 26,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 27,                  /* RBRACKET  */
  YYSYMBOL_LPAREN = 28,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 29,                    /* RPAREN  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_DOT = 31,                       /* DOT  */
  YYSYMBOL_COLON = 32,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 33,                 /* SEMICOLON  */
  YYSYMBOL_COMMENT = 34,                   /* COMMENT  */
  YYSYMBOL_REPEAT = 35,                    /* REPEAT  */
  YYSYMBOL_DO = 36,                        /* DO  */
  YYSYMBOL_DONE = 37,                      /* DONE  */
  YYSYMBOL_IF = 38,                        /* IF  */
  YYSYMBOL_THEN = 39,                      /* THEN  */
  YYSYMBOL_ELSE = 40,                      /* ELSE  */
  YYSYMBOL_FI = 41,                        /* FI  */
  YYSYMBOL_SWITCH = 42,                    /* SWITCH  */
  YYSYMBOL_CASE = 43,                      /* CASE  */
  YYSYMBOL_DEFAULT = 44,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 45,                     /* BREAK  */
  YYSYMBOL_FSWITCH = 46,                   /* FSWITCH  */
  YYSYMBOL_WHILE = 47,                     /* WHILE  */
  YYSYMBOL_UNTIL = 48,                     /* UNTIL  */
  YYSYMBOL_FOR = 49,                       /* FOR  */
  YYSYMBOL_IN = 50,                        /* IN  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_program = 52,                   /* program  */
  YYSYMBOL_statement_list = 53,            /* statement_list  */
  YYSYMBOL_statement = 54,                 /* statement  */
  YYSYMBOL_if_statement = 55,              /* if_statement  */
  YYSYMBOL_if_else_statement = 56,         /* if_else_statement  */
  YYSYMBOL_else_part = 57,                 /* else_part  */
  YYSYMBOL_statement_then = 58,            /* statement_then  */
  YYSYMBOL_switch_statement = 59,          /* switch_statement  */
  YYSYMBOL_expression_switch = 60,         /* expression_switch  */
  YYSYMBOL_case_list = 61,                 /* case_list  */
  YYSYMBOL_case_block = 62,                /* case_block  */
  YYSYMBOL_default_clause = 63,            /* default_clause  */
  YYSYMBOL_expression_bool = 64,           /* expression_bool  */
  YYSYMBOL_expr_bool_and = 65,             /* expr_bool_and  */
  YYSYMBOL_marker = 66,                    /* marker  */
  YYSYMBOL_expr_bool_not = 67,             /* expr_bool_not  */
  YYSYMBOL_primary_bool = 68,              /* primary_bool  */
  YYSYMBOL_expr_bool = 69,                 /* expr_bool  */
  YYSYMBOL_repeat_statement = 70,          /* repeat_statement  */
  YYSYMBOL_repeat_expression = 71,         /* repeat_expression  */
  YYSYMBOL_assignment = 72,                /* assignment  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_expression_list = 74,           /* expression_list  */
  YYSYMBOL_expr_arithmetic = 75,           /* expr_arithmetic  */
  YYSYMBOL_expr_unary = 76,                /* expr_unary  */
  YYSYMBOL_expr_term = 77,                 /* expr_term  */
  YYSYMBOL_factor = 78,                    /* factor  */
  YYSYMBOL_array_access = 79               /* array_access  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   150

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   151,   152,   156,   157,   185,   186,   187,
     188,   189,   190,   194,   204,   220,   228,   236,   249,   262,
     266,   273,   284,   292,   293,   312,   313,   334,   340,   354,
     358,   366,   370,   403,   436,   469,   504,   537,   625,   644,
     670,   711,   746,   750,   801,   805,   806,   921,  1014,  1015,
    1052,  1094,  1095,  1185,  1274,  1309,  1310,  1324,  1333,  1340,
    1348,  1355,  1362,  1369
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN", "ENDLINE",
  "INTEGER", "ID", "REAL", "STRING", "BOOLEAN", "PLUS", "MINUS", "MULT",
  "DIV", "MOD", "GT", "GE", "LT", "LE", "EQ", "NE", "NOT", "AND", "OR",
  "PI", "E", "LBRACKET", "RBRACKET", "LPAREN", "RPAREN", "COMMA", "DOT",
  "COLON", "SEMICOLON", "COMMENT", "REPEAT", "DO", "DONE", "IF", "THEN",
  "ELSE", "FI", "SWITCH", "CASE", "DEFAULT", "BREAK", "FSWITCH", "WHILE",
  "UNTIL", "FOR", "IN", "$accept", "program", "statement_list",
  "statement", "if_statement", "if_else_statement", "else_part",
  "statement_then", "switch_statement", "expression_switch", "case_list",
  "case_block", "default_clause", "expression_bool", "expr_bool_and",
  "marker", "expr_bool_not", "primary_bool", "expr_bool",
  "repeat_statement", "repeat_expression", "assignment", "expression",
  "expression_list", "expr_arithmetic", "expr_unary", "expr_term",
  "factor", "array_access", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      84,   -51,    -2,   -51,   -51,   122,   122,   -51,   -51,   122,
     122,    92,   -26,    16,   -51,     6,   -51,   -51,   -51,   -51,
     -51,   -51,    -9,     1,   -51,    55,   -51,    34,   122,   122,
      17,   -51,   -51,   -51,     9,   -13,   -51,    92,    92,    -3,
      33,   -51,   -51,   -51,   119,   122,   -51,    84,   -51,   122,
     122,   122,    20,    20,    20,   122,   -51,     7,   -51,    84,
     -51,    12,    58,   -51,   -51,   -51,   122,   122,   122,   122,
     122,   122,    13,   -51,   -51,     1,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,    21,   -51,    92,    84,    92,   -51,   -51,
     -51,   -51,   -51,   -51,    76,   -51,    33,    41,    44,   -51,
     -51,   -51,   -51,    47,   -51,   -51,    84,   -51,   -14,   -51,
     -51,    91,    61,    97,   100,    73,   103,   -51,    64,   107,
     -51,   -51,   -51,    84,   -51,    84,    69,    70,    85,    98,
     -51,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      12,    57,    56,    59,    58,     0,     0,    60,    61,     0,
       0,     0,     0,     0,     2,     4,     9,    10,    11,     8,
       5,     6,    42,    44,    45,    48,    51,    55,     0,     0,
      56,    49,    55,    50,     0,     0,    39,     0,     0,     0,
      23,    25,    29,    31,     0,     0,     1,    12,     7,     0,
       0,     0,     0,     0,     0,     0,    40,     0,    62,    12,
      28,     0,     0,    27,    27,    27,     0,     0,     0,     0,
       0,     0,     0,    18,     3,    43,    46,    47,    52,    53,
      54,    41,    63,     0,    30,     0,    12,     0,    34,    35,
      36,    37,    32,    33,     0,    38,    24,    16,     0,    26,
      27,    27,    27,     0,    20,    13,    12,    27,     0,    15,
      14,     0,     0,     0,     0,     0,     0,    19,     0,     0,
      27,    27,    27,    12,    17,    12,     0,     0,     0,     0,
      22,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,   -40,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,    83,    39,   -50,   -31,   -51,   -51,   -51,
     -51,   -51,    -6,   -51,   -16,     3,   -51,    88,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    13,    14,    15,    16,    17,   103,    98,    18,    72,
     108,   113,   114,    39,    40,    85,    41,    42,    43,    19,
      35,    20,    21,    22,    23,    24,    25,    26,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    28,    45,    34,    36,    44,    60,    74,    31,    33,
      47,    50,    51,    57,    86,    87,    46,    50,    51,    83,
      63,    49,    56,    59,    29,     1,    30,     3,     4,   111,
     112,    44,    62,    75,    82,    63,    64,    55,    58,    73,
      48,    84,    94,    29,     7,     8,    97,    27,     9,    81,
     104,   105,   106,    76,    77,    65,    99,   110,    95,    27,
      88,    89,    90,    91,    92,    93,   109,    52,    53,    54,
     123,   124,   125,    66,    67,    68,    69,    70,    71,    44,
     100,    44,   101,   126,   102,   127,    27,    58,   107,     1,
       2,     3,     4,   116,     5,     6,   115,     1,    30,     3,
       4,   117,     5,     6,   118,   119,    27,   120,     7,     8,
     121,   122,     9,    37,   128,   129,     7,     8,   130,    10,
      38,    61,    11,    27,    96,    27,    12,     1,    30,     3,
       4,   131,     5,     6,    66,    67,    68,    69,    70,    71,
      78,    79,    80,     0,     0,     0,     7,     8,     0,     0,
       9
};

static const yytype_int8 yycheck[] =
{
       0,     3,    28,     9,    10,    11,    37,    47,     5,     6,
       4,    10,    11,    29,    64,    65,     0,    10,    11,    59,
      23,    30,    28,    36,    26,     5,     6,     7,     8,    43,
      44,    37,    38,    49,    27,    23,    39,     3,    29,    45,
      34,    29,    29,    26,    24,    25,    86,    47,    28,    55,
     100,   101,   102,    50,    51,    22,    87,   107,    37,    59,
      66,    67,    68,    69,    70,    71,   106,    12,    13,    14,
     120,   121,   122,    15,    16,    17,    18,    19,    20,    85,
       4,    87,    41,   123,    40,   125,    86,    29,    41,     5,
       6,     7,     8,    32,    10,    11,     5,     5,     6,     7,
       8,     4,    10,    11,     4,    32,   106,     4,    24,    25,
      46,     4,    28,    21,    45,    45,    24,    25,    33,    35,
      28,    38,    38,   123,    85,   125,    42,     5,     6,     7,
       8,    33,    10,    11,    15,    16,    17,    18,    19,    20,
      52,    53,    54,    -1,    -1,    -1,    24,    25,    -1,    -1,
      28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,    10,    11,    24,    25,    28,
      35,    38,    42,    52,    53,    54,    55,    56,    59,    70,
      72,    73,    74,    75,    76,    77,    78,    79,     3,    26,
       6,    76,    79,    76,    73,    71,    73,    21,    28,    64,
      65,    67,    68,    69,    73,    28,     0,     4,    34,    30,
      10,    11,    12,    13,    14,     3,    73,    75,    29,    36,
      67,    64,    73,    23,    39,    22,    15,    16,    17,    18,
      19,    20,    60,    73,    53,    75,    76,    76,    78,    78,
      78,    73,    27,    53,    29,    66,    66,    66,    73,    73,
      73,    73,    73,    73,    29,    37,    65,    53,    58,    67,
       4,    41,    40,    57,    66,    66,    66,    41,    61,    53,
      66,    43,    44,    62,    63,     5,    32,     4,     4,    32,
       4,    46,     4,    66,    66,    66,    53,    53,    45,    45,
      33,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    56,    57,    58,    59,    60,    61,
      61,    62,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    70,    71,
      72,    72,    73,    74,    74,    75,    75,    75,    76,    76,
      76,    77,    77,    77,    77,    78,    78,    78,    78,    78,
      78,    78,    78,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     0,     7,     8,     3,     1,    11,     1,     3,
       0,     8,     7,     1,     4,     1,     4,     0,     2,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     5,     1,
       3,     3,     1,     3,     1,     1,     3,     3,     1,     2,
       2,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* statement: expression  */
#line 157 "parser.y"
                 {
        // Print the result of the expression
        fprintf(yyout, "PRODUCTION Expression %s\n", value_to_str((yyvsp[0].ident).id_val));
        if ((yyvsp[0].ident).array_name != NULL) {
            char *buffer = (char *)malloc(100);
            sprintf(buffer, "PARAM [%s]\n", (yyvsp[0].ident).lexema);
            emit(buffer);
        } else {
            char *buffer = (char *)malloc(100);
            sprintf(buffer, "PARAM %s\n", (yyvsp[0].ident).lexema);
            emit(buffer);
        }
        if ((yyvsp[0].ident).id_val.val_type == INT_TYPE) {
            char *buffer = (char *)malloc(100);
            sprintf(buffer, "CALL PUTI\n");
            emit(buffer);
        } else if ((yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
            char *buffer = (char *)malloc(100);
            sprintf(buffer, "CALL PUTF\n");
            emit(buffer);
        } else if ((yyvsp[0].ident).id_val.val_type == STR_TYPE) {
            char *buffer = (char *)malloc(100);
            sprintf(buffer, "CALL PUTC, %d\n", (yyvsp[0].ident).lenght);
            emit(buffer);
        } else {
            yyerror("Unknown type in expression");
        }
    }
#line 1297 "build/parser.tab.c"
    break;

  case 13: /* if_statement: IF expression_bool THEN marker statement_list FI marker  */
#line 194 "parser.y"
                                                            {
        fprintf(yyout, "PRODUCTION If %s = %s THEN\n", (yyvsp[-5].ident).lexema, value_to_str((yyvsp[-5].ident).id_val));
                
        // Backpatch the true_list of the condition to point to the start of the statement_list
        backpatch((yyvsp[-5].ident).true_list, (yyvsp[-3].marker).instr);
        backpatch((yyvsp[-5].ident).false_list, (yyvsp[0].marker).instr);
    }
#line 1309 "build/parser.tab.c"
    break;

  case 14: /* if_else_statement: IF expression_bool THEN marker statement_then else_part FI marker  */
#line 204 "parser.y"
                                                                      {
        fprintf(yyout, "PRODUCTION If %s = %s THEN\n", (yyvsp[-6].ident).lexema, value_to_str((yyvsp[-6].ident).id_val));
                
        // Backpatch the true_list of the condition to point to the start of the statement_list
        backpatch((yyvsp[-6].ident).true_list, (yyvsp[-4].marker).instr);

        // Backpatch the false_list of the condition to point to the start of the else_part
        backpatch((yyvsp[-6].ident).false_list, (yyvsp[-2].statement).instr);
        
        // Backpatch the goto_end_list of the if statement to point to the end of the statement_list
        backpatch((yyvsp[-3].statement).goto_end_list, (yyvsp[0].marker).instr);
    }
#line 1326 "build/parser.tab.c"
    break;

  case 15: /* else_part: ELSE marker statement_list  */
#line 220 "parser.y"
                               {
        fprintf(yyout, "PRODUCTION ELSE\n");
        // Backpatch the false_list of the condition to point to the start of the statement_list
        (yyval.statement).instr = (yyvsp[-1].marker).instr;
    }
#line 1336 "build/parser.tab.c"
    break;

  case 16: /* statement_then: statement_list  */
#line 228 "parser.y"
                   {
        fprintf(yyout, "PRODUCTION THEN\n");
        (yyval.statement).goto_end_list = makelist(n_instructions);
        emit("GOTO ____\n");
    }
#line 1346 "build/parser.tab.c"
    break;

  case 17: /* switch_statement: SWITCH LPAREN expression_switch RPAREN ENDLINE marker case_list default_clause ENDLINE FSWITCH marker  */
#line 236 "parser.y"
                                                                                                          {
        if ((yyvsp[-8].ident).id_val.val_type != INT_TYPE) {
            yyerror("Switch expression must be an integer");
        } else {
            fprintf(yyout, "PRODUCTION Switch %s\n", value_to_str((yyvsp[-8].ident).id_val));
            // Backpatch the goto_end_list of the switch statement to point to the end of the statement_list
            backpatch((yyvsp[-4].statement).goto_end_list, (yyvsp[0].marker).instr);
            backpatch((yyvsp[-3].statement).goto_end_list, (yyvsp[0].marker).instr);
        }
    }
#line 1361 "build/parser.tab.c"
    break;

  case 18: /* expression_switch: expression  */
#line 249 "parser.y"
               {
        if ((yyvsp[0].ident).is_literal) {
            char *new_var = generate_temp_var();
            char *buffer = (char *)malloc(100);
            sprintf(buffer, "%s := %s\n", new_var, (yyvsp[0].ident).lexema);
            emit(buffer);
            temporal_var_switch = new_var;
        }
        (yyval.ident) = (yyvsp[0].ident);
    }
#line 1376 "build/parser.tab.c"
    break;

  case 19: /* case_list: case_list case_block ENDLINE  */
#line 262 "parser.y"
                                 {
        fprintf(yyout, "PRODUCTION Case LIST\n");
        (yyval.statement).goto_end_list = merge((yyvsp[-2].statement).goto_end_list, (yyvsp[-1].statement).goto_end_list);
    }
#line 1385 "build/parser.tab.c"
    break;

  case 20: /* case_list: %empty  */
#line 266 "parser.y"
      { 
        (yyval.statement).instr = 0;
        (yyval.statement).goto_end_list = NULL;
    }
#line 1394 "build/parser.tab.c"
    break;

  case 21: /* case_block: CASE INTEGER COLON ENDLINE marker statement_list BREAK SEMICOLON  */
#line 273 "parser.y"
                                                                     {
        fprintf(yyout, "PRODUCTION Case block\n");   
        char *buffer = (char *)malloc(100);
        sprintf(buffer, "IF %s EQ %d GOTO %d\n", temporal_var_switch, (yyvsp[-6].integer), (yyvsp[-3].marker).instr);
        emit(buffer);
        (yyval.statement).goto_end_list = makelist(n_instructions);
        emit("GOTO ____\n");
    }
#line 1407 "build/parser.tab.c"
    break;

  case 22: /* default_clause: DEFAULT COLON ENDLINE marker statement_list BREAK SEMICOLON  */
#line 284 "parser.y"
                                                                {
        fprintf(yyout, "PRODUCTION Default\n");
        (yyval.statement).goto_end_list = makelist(n_instructions);
        emit("GOTO ____\n");
    }
#line 1417 "build/parser.tab.c"
    break;

  case 24: /* expression_bool: expression_bool OR marker expr_bool_and  */
#line 293 "parser.y"
                                              {
        fprintf(yyout, "PRODUCTION Expression %s OR %s\n", value_to_str((yyvsp[-3].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        if ((yyvsp[-3].ident).id_val.val_type == BOOL_TYPE && (yyvsp[0].ident).id_val.val_type == BOOL_TYPE) {
            (yyval.ident).id_val.val_bool = (yyvsp[-3].ident).id_val.val_bool || (yyvsp[0].ident).id_val.val_bool;
            (yyval.ident).id_val.val_type = BOOL_TYPE;
            // Backpatch false_list de la izquierda al inicio del lado derecho
            backpatch((yyvsp[-3].ident).false_list, (yyvsp[-1].marker).instr);
            // Combinar true_lists
            (yyval.ident).true_list = merge((yyvsp[-3].ident).true_list, (yyvsp[0].ident).true_list);
            // false_list es la del lado derecho
            (yyval.ident).false_list = (yyvsp[0].ident).false_list;
        } else {
            yyerror("Type error: Logical OR operation is only allowed between boolean values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1438 "build/parser.tab.c"
    break;

  case 26: /* expr_bool_and: expr_bool_and AND marker expr_bool_not  */
#line 313 "parser.y"
                                             {
        fprintf(yyout, "PRODUCTION Expression %s AND %s\n", value_to_str((yyvsp[-3].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        if ((yyvsp[-3].ident).id_val.val_type == BOOL_TYPE && (yyvsp[0].ident).id_val.val_type == BOOL_TYPE) {
            (yyval.ident).id_val.val_bool = (yyvsp[-3].ident).id_val.val_bool && (yyvsp[0].ident).id_val.val_bool;
            (yyval.ident).id_val.val_type = BOOL_TYPE;
            // Backpatch true_list del lado izquierdo al inicio del lado derecho
            backpatch((yyvsp[-3].ident).true_list, (yyvsp[-1].marker).instr);
        
            // La false_list es la combinación de ambas false_lists
            (yyval.ident).false_list = merge((yyvsp[-3].ident).false_list, (yyvsp[0].ident).false_list);
        
            // true_list es la del lado derecho
            (yyval.ident).true_list = (yyvsp[0].ident).true_list;
        } else {
            yyerror("Type error: Logical AND operation is only allowed between boolean values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1461 "build/parser.tab.c"
    break;

  case 27: /* marker: %empty  */
#line 334 "parser.y"
    {
        (yyval.marker).instr = n_instructions;
    }
#line 1469 "build/parser.tab.c"
    break;

  case 28: /* expr_bool_not: NOT expr_bool_not  */
#line 340 "parser.y"
                      {
        fprintf(yyout, "PRODUCTION NOT %s\n", value_to_str((yyvsp[0].ident).id_val));
        if ((yyvsp[0].ident).id_val.val_type == BOOL_TYPE) {
            (yyval.ident).id_val.val_bool = !(yyvsp[0].ident).id_val.val_bool;
            (yyval.ident).id_val.val_type = BOOL_TYPE;
            // Intercambiar las listas true y false
            (yyval.ident).true_list = (yyvsp[0].ident).false_list;
            (yyval.ident).false_list = (yyvsp[0].ident).true_list;
            (yyval.ident).lexema = concat_str("NOT ", (yyvsp[0].ident).lexema);
        } else {
            yyerror("Type error: Logical NOT operation is only allowed on boolean values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1488 "build/parser.tab.c"
    break;

  case 30: /* primary_bool: LPAREN expression_bool RPAREN  */
#line 358 "parser.y"
                                  {
        fprintf(yyout, "PRODUCTION ( %s )\n", value_to_str((yyvsp[-1].ident).id_val));
        (yyval.ident).id_val = (yyvsp[-1].ident).id_val;
        (yyval.ident).lexema = concat_str("(", (yyvsp[-1].ident).lexema);
        (yyval.ident).lexema = concat_str((yyval.ident).lexema, ")");
        (yyval.ident).true_list = (yyvsp[-1].ident).true_list;
        (yyval.ident).false_list = (yyvsp[-1].ident).false_list;
    }
#line 1501 "build/parser.tab.c"
    break;

  case 32: /* expr_bool: expression EQ expression  */
#line 370 "parser.y"
                             {
        fprintf(yyout, "PRODUCTION Expression %s EQ %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).id_val.val_int : (yyvsp[-2].ident).id_val.val_float) == 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).id_val.val_int : (yyvsp[0].ident).id_val.val_float);
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).id_val.val_int == (yyvsp[0].ident).id_val.val_int;
                }
                char *lexema = concat_str((yyvsp[-2].ident).lexema, " ");
                lexema = concat_str(lexema, "EQ");
                lexema = concat_str(lexema, " ");
                lexema = concat_str(lexema, (yyvsp[0].ident).lexema);
                (yyval.ident).lexema = lexema;

                // Crear las listas para backpatching
                (yyval.ident).true_list = makelist(n_instructions);
                (yyval.ident).false_list = makelist(n_instructions + 1);


                char *buffer = (char *)malloc(100);
                sprintf(buffer, "IF %s GOTO ____\n", (yyval.ident).lexema);
                emit(buffer);                           // Para true_list
                emit("GOTO ____\n");                   // Para false_list
                
                
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1539 "build/parser.tab.c"
    break;

  case 33: /* expr_bool: expression NE expression  */
#line 403 "parser.y"
                               {
        fprintf(yyout, "PRODUCTION Expression %s NE %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).id_val.val_int : (yyvsp[-2].ident).id_val.val_float) != 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).id_val.val_int : (yyvsp[0].ident).id_val.val_float);
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).id_val.val_int != (yyvsp[0].ident).id_val.val_int;
                }
                char *lexema = concat_str((yyvsp[-2].ident).lexema, " ");
                lexema = concat_str(lexema, "NE");
                lexema = concat_str(lexema, " ");
                lexema = concat_str(lexema, (yyvsp[0].ident).lexema);
                (yyval.ident).lexema = lexema;


                // Crear las listas para backpatching
                (yyval.ident).true_list = makelist(n_instructions);
                (yyval.ident).false_list = makelist(n_instructions + 1); 

                char *buffer = (char *)malloc(100);
                sprintf(buffer, "IF %s GOTO ____\n", (yyval.ident).lexema);
                emit(buffer);                           // Para true_list
                emit("GOTO ____\n");                   // Para false_list
                
                               
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1577 "build/parser.tab.c"
    break;

  case 34: /* expr_bool: expression GT expression  */
#line 436 "parser.y"
                               {
        fprintf(yyout, "PRODUCTION Expression %s GT %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                char *comparison = NULL;
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).id_val.val_int : (yyvsp[-2].ident).id_val.val_float) > 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).id_val.val_int : (yyvsp[0].ident).id_val.val_float);
                    comparison = "GTF";
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).id_val.val_int > (yyvsp[0].ident).id_val.val_int;
                    comparison = "GTI";
                }
                char *lexema = concat_str((yyvsp[-2].ident).lexema, " ");
                lexema = concat_str(lexema, comparison);
                lexema = concat_str(lexema, " ");
                lexema = concat_str(lexema, (yyvsp[0].ident).lexema);
                (yyval.ident).lexema = lexema;

                // Crear las listas para backpatching
                (yyval.ident).true_list = makelist(n_instructions);
                (yyval.ident).false_list = makelist(n_instructions + 1);

                char *buffer = (char *)malloc(100);
                sprintf(buffer, "IF %s GOTO ____\n", (yyval.ident).lexema);
                emit(buffer);                           // Para true_list
                emit("GOTO ____\n");                   // Para false_list                
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1615 "build/parser.tab.c"
    break;

  case 35: /* expr_bool: expression GE expression  */
#line 469 "parser.y"
                               {
        fprintf(yyout, "PRODUCTION Expression %s GE %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                char *comparison = NULL;
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).id_val.val_int : (yyvsp[-2].ident).id_val.val_float) >= 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).id_val.val_int : (yyvsp[0].ident).id_val.val_float);
                    comparison = "GEF";
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).id_val.val_int >= (yyvsp[0].ident).id_val.val_int;
                    comparison = "GEI";
                }
                char *lexema = concat_str((yyvsp[-2].ident).lexema, " ");
                lexema = concat_str(lexema, comparison);
                lexema = concat_str(lexema, " ");
                lexema = concat_str(lexema, (yyvsp[0].ident).lexema);
                (yyval.ident).lexema = lexema;

                // Crear las listas para backpatching
                (yyval.ident).true_list = makelist(n_instructions);
                (yyval.ident).false_list = makelist(n_instructions + 1);

                char *buffer = (char *)malloc(100);
                sprintf(buffer, "IF %s GOTO ____\n", (yyval.ident).lexema);
                emit(buffer);                           // Para true_list
                emit("GOTO ____\n");                   // Para false_list
                

        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1655 "build/parser.tab.c"
    break;

  case 36: /* expr_bool: expression LT expression  */
#line 504 "parser.y"
                               {
        fprintf(yyout, "PRODUCTION Expression %s LT %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                char *comparison = NULL;
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).id_val.val_int : (yyvsp[-2].ident).id_val.val_float) < 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).id_val.val_int : (yyvsp[0].ident).id_val.val_float);
                    comparison = "LTF";
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).id_val.val_int < (yyvsp[0].ident).id_val.val_int;
                    comparison = "LTI";
                }
                char *lexema = concat_str((yyvsp[-2].ident).lexema, " ");
                lexema = concat_str(lexema, comparison);
                lexema = concat_str(lexema, " ");
                lexema = concat_str(lexema, (yyvsp[0].ident).lexema);
                (yyval.ident).lexema = lexema;

                // Crear las listas para backpatching
                (yyval.ident).true_list = makelist(n_instructions);
                (yyval.ident).false_list = makelist(n_instructions + 1);

                char *buffer = (char *)malloc(100);
                sprintf(buffer, "IF %s GOTO ____\n", (yyval.ident).lexema);
                emit(buffer);                           // Para true_list
                emit("GOTO ____\n");                   // Para false_list                
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1693 "build/parser.tab.c"
    break;

  case 37: /* expr_bool: expression LE expression  */
#line 537 "parser.y"
                               {
        fprintf(yyout, "PRODUCTION Expression %s LE %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                char *comparison = NULL;
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).id_val.val_int : (yyvsp[-2].ident).id_val.val_float) <= 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).id_val.val_int : (yyvsp[0].ident).id_val.val_float);
                    comparison = "LEF";
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).id_val.val_int <= (yyvsp[0].ident).id_val.val_int;
                    comparison = "LEI";
                }
                char *lexema = concat_str((yyvsp[-2].ident).lexema, " ");
                lexema = concat_str(lexema, comparison);
                lexema = concat_str(lexema, " ");
                lexema = concat_str(lexema, (yyvsp[0].ident).lexema);
                (yyval.ident).lexema = lexema;
                
                // Crear las listas para backpatching
                (yyval.ident).true_list = makelist(n_instructions);
                (yyval.ident).false_list = makelist(n_instructions + 1);  

                char *buffer = (char *)malloc(100);
                sprintf(buffer, "IF %s GOTO ____\n", (yyval.ident).lexema);
                emit(buffer);                           // Para true_list
                emit("GOTO ____\n");                   // Para false_list             
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1731 "build/parser.tab.c"
    break;

  case 38: /* repeat_statement: REPEAT repeat_expression DO statement_list DONE  */
#line 625 "parser.y"
                                                    {
        if ((yyvsp[-3].ident).id_val.val_type != INT_TYPE) {
            yyerror("Repeat count must be an integer");
        } else {
            int repeat_count = (yyvsp[-3].ident).id_val.val_int;
            char *repeat_line_number = pop_repeat_stack();
            char *repeat_counter_name = pop_repeat_stack();
            char *repeat_expression_name = pop_repeat_stack();
            fprintf(yyout, "PRODUCTION Repeat %d times\n", repeat_count);
            char *buffer = (char *)malloc(100);
            sprintf(buffer, "%s := %s ADDI 1\n", repeat_counter_name, repeat_counter_name);
            emit(buffer);
            sprintf(buffer, "IF %s LTI %s GOTO %s\n", repeat_counter_name, repeat_expression_name, repeat_line_number);
            emit(buffer);
        }
    }
#line 1752 "build/parser.tab.c"
    break;

  case 39: /* repeat_expression: expression  */
#line 644 "parser.y"
               {
        if ((yyvsp[0].ident).is_literal) {
            char *new_var = generate_temp_var();
            char *buffer = (char *)malloc(100);
            sprintf(buffer, "%s := %s\n", new_var, (yyvsp[0].ident).lexema);
            emit(buffer);
        } 
        char *temp_var = generate_temp_var();
        char *buffer = (char *)malloc(100);
        sprintf(buffer, "%s := 0\n", temp_var);
        emit(buffer);
        char * repeat_counter_name = temp_var;
        // store the previous temp var in repeat_expression_name
        int previous_number = atoi(temp_var + 2) - 1;
        char *previous_temp_var = (char *)malloc(14);
        sprintf(previous_temp_var, "$t%02d", previous_number);
        char *repeat_expression_name = previous_temp_var;
        push_repeat_stack(repeat_expression_name);
        push_repeat_stack(repeat_counter_name);
        char *line_number = (char *)malloc(10); 
        sprintf(line_number, "%d", n_instructions);
        push_repeat_stack(line_number);
    }
#line 1780 "build/parser.tab.c"
    break;

  case 40: /* assignment: ID ASSIGN expression  */
#line 670 "parser.y"
                         {
        fprintf(yyout, "PRODUCTION Assignment %s := %s\n", (yyvsp[-2].ident).lexema, value_to_str((yyvsp[0].ident).id_val));
        // Assign only if the type is compatible or if it has not been initialized
        if ((yyvsp[-2].ident).id_val.val_type == UNKNOWN_TYPE || (yyvsp[-2].ident).id_val.val_type == (yyvsp[0].ident).id_val.val_type) {
            (yyvsp[-2].ident).id_val.val_type = (yyvsp[0].ident).id_val.val_type;
            if ((yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                (yyvsp[-2].ident).id_val.val_int = (yyvsp[0].ident).id_val.val_int;
            } else if ((yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                (yyvsp[-2].ident).id_val.val_float = (yyvsp[0].ident).id_val.val_float;
            } else if ((yyvsp[0].ident).id_val.val_type == STR_TYPE) {
                (yyvsp[-2].ident).id_val.val_str = (yyvsp[0].ident).id_val.val_str;
            } else if ((yyvsp[0].ident).id_val.val_type == ARRAY_TYPE) {
                (yyvsp[-2].ident).id_val.val_array = (yyvsp[0].ident).id_val.val_array;
            }
            value_info value = {
                .val_type = (yyvsp[0].ident).id_val.val_type,
                .val_int = (yyvsp[0].ident).id_val.val_int,
                .val_float = (yyvsp[0].ident).id_val.val_float,
                .val_str = (yyvsp[0].ident).id_val.val_str,
                .val_array = (yyvsp[0].ident).id_val.val_array
            };
            int symtab_status = sym_enter((yyvsp[-2].ident).lexema, &value);
            if (symtab_status == SYMTAB_OK || symtab_status == SYMTAB_DUPLICATE) {
                if (array_size > 1 || (yyvsp[0].ident).array_name != NULL) {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := [%s]\n", (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    emit(buffer);
                    array_size = 1;
                    array_elems = NULL;
                } else { 
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := %s\n", (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    emit(buffer);
                }
            } else {
                yyerror("Error: Variable could not be entered into the symbol table. Stack overflow.");
            }
        } else {
            yyerror("Incompatible types in assignment");
        }
    }
#line 1826 "build/parser.tab.c"
    break;

  case 41: /* assignment: array_access ASSIGN expression  */
#line 711 "parser.y"
                                     {
        fprintf(yyout, "PRODUCTION Assignment %s[%d] := %s\n", (yyvsp[-2].ident).lexema, (yyvsp[0].ident).id_val.val_int, value_to_str((yyvsp[0].ident).id_val));

        value_info val1;
        if (sym_lookup((yyvsp[-2].ident).array_name, &val1) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
        } else if (val1.val_type != ARRAY_TYPE) {
            yyerror("Variable is not an array");
        } else if ((yyvsp[-2].ident).id_val.val_type != (yyvsp[0].ident).id_val.val_type) {
            yyerror("Type error: Incompatible types in assignment");
        } else {
            int index = (yyvsp[-2].ident).index; 
            if (index < 0 || index > val1.val_int) {
                yyerror("Array index out of bounds");
            } else {
                val1.val_array[index] = (value){
                    .val_type = (yyvsp[0].ident).id_val.val_type,
                    .val_int = (yyvsp[0].ident).id_val.val_int,
                    .val_float = (yyvsp[0].ident).id_val.val_float,
                    .val_str = (yyvsp[0].ident).id_val.val_str ? strdup((yyvsp[0].ident).id_val.val_str) : NULL
                };
                int symtab_status = sym_enter((yyvsp[-2].ident).lexema, &val1);
                if (symtab_status == SYMTAB_OK || symtab_status == SYMTAB_DUPLICATE) {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "[%s] := %s\n", (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    emit(buffer);
                } else {
                    yyerror("Error: Variable could not be entered into the symbol table. Stack overflow.");
                } 
            }
        }
    }
#line 1863 "build/parser.tab.c"
    break;

  case 43: /* expression_list: expression_list COMMA expr_arithmetic  */
#line 750 "parser.y"
                                          {
       if (array_size == 1) {
            char *new_elem1 = (yyvsp[-2].ident).lexema;
            char *new_elem2 = (yyvsp[0].ident).lexema;
            if ((yyvsp[-2].ident).id_val.val_type != (yyvsp[0].ident).id_val.val_type) {
                yyerror("Type error: Incompatible types in array");
            }
            (yyval.ident).id_val.val_array_type = (yyvsp[-2].ident).id_val.val_type;
            array_elems = concat_str(new_elem1, ", ");
            array_elems = concat_str(array_elems, new_elem2);
            (yyval.ident).id_val.val_array = (value *)malloc(sizeof(value) * 2);
            value new_value1 = {
                .val_type = (yyvsp[-2].ident).id_val.val_type,
                .val_int = (yyvsp[-2].ident).id_val.val_int,
                .val_float = (yyvsp[-2].ident).id_val.val_float,
                .val_str = (yyvsp[-2].ident).id_val.val_str
            };
            value new_value2 = {
                .val_type = (yyvsp[0].ident).id_val.val_type,
                .val_int = (yyvsp[0].ident).id_val.val_int,
                .val_float = (yyvsp[0].ident).id_val.val_float,
                .val_str = (yyvsp[0].ident).id_val.val_str
            };
            (yyval.ident).id_val.val_array[0] = new_value1;
            (yyval.ident).id_val.val_array[1] = new_value2;
       } else {
            char *new_elem = (yyvsp[0].ident).lexema;
            if ((yyvsp[0].ident).id_val.val_type != (yyval.ident).id_val.val_array_type) {
                yyerror("Type error: Incompatible types in array");
            }
            array_elems = concat_str(array_elems, ", ");
            array_elems = concat_str(array_elems, new_elem);    
       }
       array_size++;
       (yyval.ident).lexema = array_elems;
       (yyval.ident).id_val.val_type = ARRAY_TYPE;
       (yyval.ident).id_val.val_int = array_size;
        value new_value = {
           .val_type = (yyvsp[0].ident).id_val.val_type,
           .val_int = (yyvsp[0].ident).id_val.val_int,
           .val_float = (yyvsp[0].ident).id_val.val_float,
           .val_str = (yyvsp[0].ident).id_val.val_str
        };
        value *new_array = (value *)malloc(array_size * sizeof(value));
        for (int i = 0; i < array_size - 1; i++) {
            new_array[i] = (yyval.ident).id_val.val_array[i];
        }
        new_array[array_size - 1] = new_value;
        (yyval.ident).id_val.val_array = new_array;

    }
#line 1919 "build/parser.tab.c"
    break;

  case 46: /* expr_arithmetic: expr_arithmetic PLUS expr_unary  */
#line 806 "parser.y"
                                      {
        fprintf(yyout, "PRODUCTION expr_arithmetic %s + %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        char *temp_var = NULL;
        // Verify that are numbers
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) &&
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                    (yyval.ident).id_val.val_int = ((yyvsp[-2].ident).id_val.val_int + (yyvsp[0].ident).id_val.val_int);
                    (yyval.ident).id_val.val_type = INT_TYPE;
                    temp_var = generate_temp_var();
                    if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := [%s] ADDI [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else if ((yyvsp[-2].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := [%s] ADDI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else if ((yyvsp[0].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s ADDI [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s ADDI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    }
                } else {
                    if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                        (yyval.ident).id_val.val_float = (yyvsp[-2].ident).id_val.val_float + (yyvsp[0].ident).id_val.val_float;
                        temp_var = generate_temp_var();
                        if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] ADDF [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else if ((yyvsp[-2].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] ADDF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else if ((yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := %s ADDF [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := %s ADDF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        }
                    } else if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_float + (yyvsp[0].ident).id_val.val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        if ((yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F [%s]\n", new_temp_var, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F %s\n", new_temp_var, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        }
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s ADDF %s\n", temp_var,(yyvsp[-2].ident).lexema, new_temp_var);
                        emit(buffer);
                    } else {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_int + (yyvsp[0].ident).id_val.val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        if ((yyvsp[-2].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F [%s]\n", new_temp_var, (yyvsp[-2].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F %s\n", new_temp_var, (yyvsp[-2].ident).lexema);
                            emit(buffer);
                        }
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s ADDF %s\n", temp_var, new_temp_var, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    }
                    (yyval.ident).id_val.val_type = FLOAT_TYPE;
                }
            } else if (((yyvsp[-2].ident).id_val.val_type != UNKNOWN_TYPE && (yyvsp[0].ident).id_val.val_type != UNKNOWN_TYPE) && 
                        ((yyvsp[-2].ident).id_val.val_type == STR_TYPE || (yyvsp[0].ident).id_val.val_type == STR_TYPE)) {
                // Concatenate strings
                (yyval.ident).id_val.val_str = concat_str(value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));    
                (yyval.ident).id_val.val_type = STR_TYPE;
                temp_var = generate_temp_var();

                if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := [%s] CONCAT [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    emit(buffer);
                } else if ((yyvsp[-2].ident).array_name != NULL) {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := [%s] CONCAT %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    emit(buffer);
                } else if ((yyvsp[0].ident).array_name != NULL) {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := %s CONCAT [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    emit(buffer);
                } else {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := %s CONCAT %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    emit(buffer);
                }
            }
            else {
                yyerror("Type error: Unknown type in addition operation");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            }
            (yyval.ident).lexema = temp_var;
            (yyval.ident).is_literal = 0;
    }
#line 2039 "build/parser.tab.c"
    break;

  case 47: /* expr_arithmetic: expr_arithmetic MINUS expr_unary  */
#line 921 "parser.y"
                                       {
        fprintf(yyout, "PRODUCTION expr_arithmetic %s - %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        char *temp_var = NULL;
        // Verify that are numbers
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) &&
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                    (yyval.ident).id_val.val_int = ((yyvsp[-2].ident).id_val.val_int - (yyvsp[0].ident).id_val.val_int);
                    (yyval.ident).id_val.val_type = INT_TYPE;
                    temp_var = generate_temp_var();
                    if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := [%s] SUBI [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else if ((yyvsp[-2].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := [%s] SUBI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else if ((yyvsp[0].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s SUBI [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s SUBI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    }
                } else {
                    if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                        (yyval.ident).id_val.val_float = (yyvsp[-2].ident).id_val.val_float - (yyvsp[0].ident).id_val.val_float;
                        temp_var = generate_temp_var();
                        if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] SUBF [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else if ((yyvsp[-2].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] SUBF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else if ((yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := %s SUBF [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := %s SUBF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        }
                    } else if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_float - (yyvsp[0].ident).id_val.val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        if ((yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F [%s]\n", new_temp_var, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F %s\n", new_temp_var, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        }
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s SUBF %s\n", temp_var, (yyvsp[-2].ident).lexema, new_temp_var);
                        emit(buffer);
                    } else {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_int - (yyvsp[0].ident).id_val.val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        if ((yyvsp[-2].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F [%s]\n", new_temp_var, (yyvsp[-2].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F %s\n", new_temp_var, (yyvsp[-2].ident).lexema);
                            emit(buffer);
                        }
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s SUBF %s\n", temp_var, new_temp_var, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    }
                    (yyval.ident).id_val.val_type = FLOAT_TYPE;
                }
            } else {
                yyerror("Type error: Subtraction operation is only allowed between numeric values");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            }
            (yyval.ident).lexema = temp_var;
            (yyval.ident).is_literal = 0;
    }
#line 2134 "build/parser.tab.c"
    break;

  case 49: /* expr_unary: PLUS expr_unary  */
#line 1015 "parser.y"
                      {
        fprintf(yyout, "PRODUCTION expr_unary + %s\n", value_to_str((yyvsp[0].ident).id_val));
        char *temp_var = NULL;
        // Verify its a number
        if ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
            if ((yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                (yyval.ident).id_val.val_int = (yyvsp[0].ident).id_val.val_int;
                (yyval.ident).id_val.val_type = INT_TYPE;
                temp_var = generate_temp_var();
                if ((yyvsp[0].ident).array_name != NULL) {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := [%s]\n", temp_var, (yyvsp[0].ident).lexema);
                    emit(buffer);
                } else {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := %s\n", temp_var, (yyvsp[0].ident).lexema);
                    emit(buffer);
                }
            } else {
                (yyval.ident).id_val.val_float = (yyvsp[0].ident).id_val.val_float;
                (yyval.ident).id_val.val_type = FLOAT_TYPE;
                temp_var = generate_temp_var();
                if ((yyvsp[0].ident).array_name != NULL) {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := [%s]\n", temp_var, (yyvsp[0].ident).lexema);
                    emit(buffer);
                } else {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := %s\n", temp_var, (yyvsp[0].ident).lexema);
                    emit(buffer);
                }
            }
        } else {
            yyerror("Type error: Unary plus operation is only allowed on numeric values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 2176 "build/parser.tab.c"
    break;

  case 50: /* expr_unary: MINUS expr_unary  */
#line 1052 "parser.y"
                       {
        fprintf(yyout, "PRODUCTION expr_unary - %s\n", value_to_str((yyvsp[0].ident).id_val));
        char *temp_var = NULL;
        // Verify its a number
        if ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
            if ((yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                (yyval.ident).id_val.val_int = (yyvsp[0].ident).id_val.val_int * -1;
                (yyval.ident).id_val.val_type = INT_TYPE;
                temp_var = generate_temp_var();
                if ((yyvsp[0].ident).array_name != NULL) {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := CHSI [%s]\n", temp_var, (yyvsp[0].ident).lexema);
                    emit(buffer);
                } else {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := CHSI %s\n", temp_var, (yyvsp[0].ident).lexema);
                    emit(buffer);
                }
            } else {
                (yyval.ident).id_val.val_float = (yyvsp[0].ident).id_val.val_float * -1;
                (yyval.ident).id_val.val_type = FLOAT_TYPE;
                temp_var = generate_temp_var();
                if ((yyvsp[0].ident).array_name != NULL) {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := CHSF [%s]\n", temp_var, (yyvsp[0].ident).lexema);
                    emit(buffer);
                } else {
                    char *buffer = (char *)malloc(100);
                    sprintf(buffer, "%s := CHSF %s\n", temp_var, (yyvsp[0].ident).lexema);
                    emit(buffer);
                }
            }
        } else {
            yyerror("Type error: Unary minus operation is only allowed on numeric values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
        (yyval.ident).lexema = temp_var;
        (yyval.ident).is_literal = 0;
    }
#line 2220 "build/parser.tab.c"
    break;

  case 52: /* expr_term: expr_term MULT factor  */
#line 1095 "parser.y"
                            {
        fprintf(yyout, "PRODUCTION expr_term %s * %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        char *temp_var = NULL;
        // Verify that are numbers
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) &&
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                    (yyval.ident).id_val.val_int = ((yyvsp[-2].ident).id_val.val_int * (yyvsp[0].ident).id_val.val_int);
                    (yyval.ident).id_val.val_type = INT_TYPE;
                    temp_var = generate_temp_var();
                    if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := [%s] MULI [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else if ((yyvsp[-2].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := [%s] MULI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else if ((yyvsp[0].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s MULI [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s MULI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    }
                } else {
                    if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                        (yyval.ident).id_val.val_float = (yyvsp[-2].ident).id_val.val_float * (yyvsp[0].ident).id_val.val_float;
                        temp_var = generate_temp_var();
                        if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] MULF [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else if ((yyvsp[-2].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] MULF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else if ((yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := %s MULF [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := %s MULF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        }
                    } else if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_float * (yyvsp[0].ident).id_val.val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        if ((yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F [%s]\n", new_temp_var, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F %s\n", new_temp_var, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        }
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s MULF %s\n", temp_var, (yyvsp[-2].ident).lexema, new_temp_var);
                        emit(buffer);
                    } else {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_int * (yyvsp[0].ident).id_val.val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        if ((yyvsp[-2].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F [%s]\n", new_temp_var, (yyvsp[-2].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F %s\n", new_temp_var, (yyvsp[-2].ident).lexema);
                            emit(buffer);
                        }
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s MULF %s\n", temp_var, new_temp_var, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    }
                    (yyval.ident).id_val.val_type = FLOAT_TYPE;
                }
            } else {
                yyerror("Type error: Multiplication operation is only allowed between numeric values");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            }
            (yyval.ident).lexema = temp_var;
            (yyval.ident).is_literal = 0;
    }
#line 2315 "build/parser.tab.c"
    break;

  case 53: /* expr_term: expr_term DIV factor  */
#line 1185 "parser.y"
                           {
        fprintf(yyout, "PRODUCTION expr_term %s / %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        char *temp_var = NULL;
        // Verify that are numbers
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) &&
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = FLOAT_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                    (yyval.ident).id_val.val_float = (float) ((yyvsp[-2].ident).id_val.val_int / (yyvsp[0].ident).id_val.val_int);
                    temp_var = generate_temp_var();
                    if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := [%s] DIVI [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    } else if ((yyvsp[-2].ident).array_name != NULL) {
                        char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] DIVI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                    } else if ((yyvsp[0].ident).array_name != NULL) {
                         char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] DIVI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                    } else {
                         char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := %s DIVI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                    }
                } else {
                    if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                        (yyval.ident).id_val.val_float = (yyvsp[-2].ident).id_val.val_float / (yyvsp[0].ident).id_val.val_float;
                        temp_var = generate_temp_var();
                        if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := [%s] DIVF [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                        emit(buffer);
                        } else if ((yyvsp[-2].ident).array_name != NULL) {
                           char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] DIVF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else if ((yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := [%s] DIVF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := %s DIVF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        }
                    } else if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_float / (yyvsp[0].ident).id_val.val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        if ((yyvsp[0].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F [%s]\n", new_temp_var, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F %s\n", new_temp_var, (yyvsp[0].ident).lexema);
                            emit(buffer);
                        }
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s DIVF %s\n", temp_var, (yyvsp[-2].ident).lexema, new_temp_var);
                        emit(buffer);
                    } else {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_int / (yyvsp[0].ident).id_val.val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        if ((yyvsp[-2].ident).array_name != NULL) {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F [%s]\n", new_temp_var, (yyvsp[-2].ident).lexema);
                            emit(buffer);
                        } else {
                            char *buffer = (char *)malloc(100);
                            sprintf(buffer, "%s := I2F %s\n", new_temp_var, (yyvsp[-2].ident).lexema);
                            emit(buffer);
                        }
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s DIVF %s\n", temp_var, new_temp_var, (yyvsp[0].ident).lexema);
                        emit(buffer);
                    }
                }
            } else {
                yyerror("Type error: Division operation is only allowed between numeric values");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            }
            (yyval.ident).lexema = temp_var;
            (yyval.ident).is_literal = 0;
    }
#line 2409 "build/parser.tab.c"
    break;

  case 54: /* expr_term: expr_term MOD factor  */
#line 1274 "parser.y"
                           {
        fprintf(yyout, "PRODUCTION expr_term %s %% %s\n", value_to_str((yyvsp[-2].ident).id_val), value_to_str((yyvsp[0].ident).id_val));
        char *temp_var = NULL;
        // Verify that both operands are integers
        if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
            (yyval.ident).id_val.val_type = INT_TYPE;
            (yyval.ident).id_val.val_int = (yyvsp[-2].ident).id_val.val_int % (yyvsp[0].ident).id_val.val_int;
            temp_var = generate_temp_var();
            if ((yyvsp[-2].ident).array_name != NULL && (yyvsp[0].ident).array_name != NULL) {
                char *buffer = (char *)malloc(100);
                sprintf(buffer, "%s := [%s] MODI [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                emit(buffer);
            } else if ((yyvsp[-2].ident).array_name != NULL) {
                char *buffer = (char *)malloc(100);
                sprintf(buffer, "%s := [%s] MODI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                emit(buffer);
            } else if ((yyvsp[0].ident).array_name != NULL) {
                char *buffer = (char *)malloc(100);
                sprintf(buffer, "%s := %s MODI [%s]\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                emit(buffer);
            } else {
                char *buffer = (char *)malloc(100);
                sprintf(buffer, "%s := %s MODI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                emit(buffer);
            }
        } else {
            yyerror("Type error: Modulus operation is only allowed between integers");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
        (yyval.ident).lexema = temp_var;
        (yyval.ident).is_literal = 0;
    }
#line 2446 "build/parser.tab.c"
    break;

  case 56: /* factor: ID  */
#line 1310 "parser.y"
         {
        fprintf(yyout, "PRODUCTION ID Factor %s\n", (yyvsp[0].ident).lexema);
        value_info value;
        if (sym_lookup((yyvsp[0].ident).lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
        } else {
                (yyval.ident).id_val = value;
                (yyval.ident).lexema = (yyvsp[0].ident).lexema;
                if (value.val_type == STR_TYPE) {
                    (yyval.ident).lenght = strlen(value.val_str);
                }
                (yyval.ident).is_literal = 1;
            }
    }
#line 2465 "build/parser.tab.c"
    break;

  case 57: /* factor: INTEGER  */
#line 1324 "parser.y"
              {
        fprintf(yyout, "PRODUCTION INTEGER Factor %d\n", (yyvsp[0].integer));
        (yyval.ident).id_val.val_type = INT_TYPE;
        (yyval.ident).id_val.val_int = (yyvsp[0].integer);
        // store value as a string
        (yyval.ident).lexema = (char *)malloc(12);
        sprintf((yyval.ident).lexema, "%d", (yyvsp[0].integer));
        (yyval.ident).is_literal = 1;
    }
#line 2479 "build/parser.tab.c"
    break;

  case 58: /* factor: STRING  */
#line 1333 "parser.y"
             {
        fprintf(yyout, "PRODUCTION STRING Factor %s\n", (yyvsp[0].string));
        (yyval.ident).id_val.val_type = STR_TYPE;
        (yyval.ident).id_val.val_str = substr((yyvsp[0].string), 1, strlen((yyvsp[0].string)) - 2);
        (yyval.ident).lexema = (yyvsp[0].string);
        (yyval.ident).lenght = strlen((yyvsp[0].string)) - 2;
    }
#line 2491 "build/parser.tab.c"
    break;

  case 59: /* factor: REAL  */
#line 1340 "parser.y"
           {
        fprintf(yyout, "PRODUCTION REAL Factor %f\n", (yyvsp[0].real));
        (yyval.ident).id_val.val_type = FLOAT_TYPE;
        (yyval.ident).id_val.val_float = (yyvsp[0].real);
        // store value as a string
        (yyval.ident).lexema = (char *)malloc(12);
        sprintf((yyval.ident).lexema, "%f", (yyvsp[0].real));
    }
#line 2504 "build/parser.tab.c"
    break;

  case 60: /* factor: PI  */
#line 1348 "parser.y"
         {
        fprintf(yyout, "PRODUCTION PI Factor\n");
        (yyval.ident).id_val.val_type = FLOAT_TYPE;
        (yyval.ident).id_val.val_float = 3.141592653589793;
        // store value as a string
        (yyval.ident).lexema = "3.141592653589793";
    }
#line 2516 "build/parser.tab.c"
    break;

  case 61: /* factor: E  */
#line 1355 "parser.y"
        {
        fprintf(yyout, "PRODUCTION E Factor\n");
        (yyval.ident).id_val.val_type = FLOAT_TYPE;
        (yyval.ident).id_val.val_float = 2.718281828459045;
        // store value as a string
        (yyval.ident).lexema = "2.718281828459045";
    }
#line 2528 "build/parser.tab.c"
    break;

  case 62: /* factor: LPAREN expression RPAREN  */
#line 1362 "parser.y"
                               {
        fprintf(yyout, "PRODUCTION LPAREN expression RPAREN %s\n", value_to_str((yyvsp[-1].ident).id_val));
        (yyval.ident) = (yyvsp[-1].ident);
    }
#line 2537 "build/parser.tab.c"
    break;

  case 63: /* array_access: ID LBRACKET expr_arithmetic RBRACKET  */
#line 1369 "parser.y"
                                         {
    value_info val1;
        if (sym_lookup((yyvsp[-3].ident).lexema, &val1) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
        } else {
            if (val1.val_type != ARRAY_TYPE) {
                yyerror("Variable is not an array");
            } else {
                if ((yyvsp[-1].ident).id_val.val_type != INT_TYPE) {
                    yyerror("Array index must be an integer");
                } else {
                    if ((yyvsp[-1].ident).id_val.val_int <= 0 || (yyvsp[-1].ident).id_val.val_int > val1.val_int) {
                        yyerror("Array index out of bounds");
                    } else {
                        value val2 = val1.val_array[(yyvsp[-1].ident).id_val.val_int - 1];
                        char *temp_var = generate_temp_var();
                        if ((yyvsp[-1].ident).id_val.val_type != INT_TYPE) {
                            yyerror("Error. Array index access must be integer.");
                        }
                        int index = (yyvsp[-1].ident).id_val.val_int;
                        char *buffer = (char *)malloc(100);
                        sprintf(buffer, "%s := %s MULI 4\n", temp_var, (yyvsp[-1].ident).lexema);
                        emit(buffer);
                        char *temp_var2 = generate_temp_var();
                        sprintf(buffer, "%s := &%s ADDI %s\n", temp_var2, (yyvsp[-3].ident).lexema, temp_var);
                        emit(buffer);
                        (yyval.ident).lexema = temp_var2;
                        (yyval.ident).array_name = (yyvsp[-3].ident).lexema;
                        (yyval.ident).index = index;
                        (yyval.ident).id_val = (value_info){
                            .val_type = val2.val_type,
                            .val_int = val2.val_int,
                            .val_float = val2.val_float,
                            .val_str = val2.val_str,
                            .val_array = NULL
                        };
                        if (val2.val_type == STR_TYPE) {
                            (yyval.ident).lenght = strlen(val2.val_str);
                        }
                    }
                }
            }
        }
    }
#line 2586 "build/parser.tab.c"
    break;


#line 2590 "build/parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1414 "parser.y"

