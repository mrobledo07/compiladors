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

#line 82 "build/parser.tab.c"

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
  YYSYMBOL_COS = 10,                       /* COS  */
  YYSYMBOL_SIN = 11,                       /* SIN  */
  YYSYMBOL_TAN = 12,                       /* TAN  */
  YYSYMBOL_PLUS = 13,                      /* PLUS  */
  YYSYMBOL_MINUS = 14,                     /* MINUS  */
  YYSYMBOL_MULT = 15,                      /* MULT  */
  YYSYMBOL_DIV = 16,                       /* DIV  */
  YYSYMBOL_MOD = 17,                       /* MOD  */
  YYSYMBOL_POW = 18,                       /* POW  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_GE = 20,                        /* GE  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_LE = 22,                        /* LE  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_PI = 28,                        /* PI  */
  YYSYMBOL_E = 29,                         /* E  */
  YYSYMBOL_LEN = 30,                       /* LEN  */
  YYSYMBOL_SUBSTR = 31,                    /* SUBSTR  */
  YYSYMBOL_LPAREN = 32,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 33,                    /* RPAREN  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_COMMENT = 35,                   /* COMMENT  */
  YYSYMBOL_REPEAT = 36,                    /* REPEAT  */
  YYSYMBOL_DO = 37,                        /* DO  */
  YYSYMBOL_DONE = 38,                      /* DONE  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_statement_list = 41,            /* statement_list  */
  YYSYMBOL_statement = 42,                 /* statement  */
  YYSYMBOL_repeat_statement = 43,          /* repeat_statement  */
  YYSYMBOL_assignment = 44,                /* assignment  */
  YYSYMBOL_expression = 45,                /* expression  */
  YYSYMBOL_expr_arithmetic = 46,           /* expr_arithmetic  */
  YYSYMBOL_expr_unary = 47,                /* expr_unary  */
  YYSYMBOL_expr_term = 48,                 /* expr_term  */
  YYSYMBOL_expr_pow = 49,                  /* expr_pow  */
  YYSYMBOL_factor = 50,                    /* factor  */
  YYSYMBOL_expr_trig = 51,                 /* expr_trig  */
  YYSYMBOL_expr_len = 52,                  /* expr_len  */
  YYSYMBOL_expr_substr = 53                /* expr_substr  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    79,    80,    84,    85,    99,   100,   101,
     105,   117,   151,   155,   156,   201,   238,   252,   253,   269,
     291,   305,   306,   343,   379,   394,   408,   409,   432,   448,
     464,   480,   496,   513,   532,   541,   549,   554,   559,   564,
     569,   574,   578,   579,   580,   584,   598,   612,   628,   633,
     652,   663
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
  "INTEGER", "ID", "REAL", "STRING", "BOOLEAN", "COS", "SIN", "TAN",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "POW", "GT", "GE", "LT", "LE",
  "EQ", "NE", "NOT", "AND", "OR", "PI", "E", "LEN", "SUBSTR", "LPAREN",
  "RPAREN", "COMMA", "COMMENT", "REPEAT", "DO", "DONE", "$accept",
  "program", "statement_list", "statement", "repeat_statement",
  "assignment", "expression", "expr_arithmetic", "expr_unary", "expr_term",
  "expr_pow", "factor", "expr_trig", "expr_len", "expr_substr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-17)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,   -17,    17,   -17,   -17,   -17,    -8,    -4,     6,    40,
      40,    78,   -17,   -17,     7,    11,    40,    40,    21,   -17,
       0,   -17,   -17,   -17,     9,    29,    41,   101,   -17,   -17,
     -17,   -17,    40,    40,    40,    40,   -17,   -17,   -17,   -17,
      19,    58,    27,    30,   -17,     1,   -17,    40,    40,    40,
      78,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,   -17,    44,    45,    46,    47,    66,    39,    67,   -17,
       1,   -17,    29,    29,    29,    41,   101,   101,   101,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,    40,    40,    36,    68,    70,   -17,    40,    40,    79,
      80,   -17,   -17
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       9,    35,    34,    38,    36,    37,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,     0,     0,     0,     2,
       4,     8,     5,     6,    12,    13,    17,    21,    26,    42,
      43,    44,     0,     0,     0,     0,    34,    18,    19,    25,
       0,     0,     0,     0,     1,     9,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,    41,
       9,     3,    14,    15,    16,    20,    22,    23,    24,    27,
      28,    30,    29,    31,    32,    33,    46,    45,    47,    49,
      48,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,    51,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,   -17,   -11,   -17,   -17,   -17,   -16,   -17,    -7,    -6,
      10,    72,   -17,   -17,   -17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    43,    37,    38,    45,    39,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    61,    62,    63,    64,
      32,    44,    47,    48,    33,    65,    11,    66,    34,    12,
      13,    14,    15,    16,    71,    46,    49,    17,    35,    40,
      72,    73,    74,    41,    75,     1,    36,     3,     4,     5,
       6,     7,     8,     9,    10,    50,    51,    52,    53,    93,
      69,    76,    77,    78,    67,    11,    68,    70,    12,    13,
      14,    15,    16,    91,    96,    94,    95,    86,    87,    88,
      89,    99,   100,     1,    36,     3,     4,     5,     6,     7,
       8,     1,    36,     3,     4,     5,     6,     7,     8,    90,
       0,    92,    97,    11,    98,     0,    12,    13,    14,    15,
      16,     0,   101,   102,    12,    13,    14,    15,    16,    54,
      55,    56,    57,    58,    59,    60,    79,    80,    81,    82,
      83,    84,    85
};

static const yytype_int8 yycheck[] =
{
      16,    17,     9,    10,     4,    11,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    32,    33,    34,    35,
       3,     0,    13,    14,    32,     6,    25,     8,    32,    28,
      29,    30,    31,    32,    45,    35,    27,    36,    32,    32,
      47,    48,    49,    32,    50,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    26,    15,    16,    17,    70,
      33,    51,    52,    53,     6,    25,     8,    37,    28,    29,
      30,    31,    32,    34,    38,    91,    92,    33,    33,    33,
      33,    97,    98,     5,     6,     7,     8,     9,    10,    11,
      12,     5,     6,     7,     8,     9,    10,    11,    12,    33,
      -1,    34,    34,    25,    34,    -1,    28,    29,    30,    31,
      32,    -1,    33,    33,    28,    29,    30,    31,    32,    18,
      19,    20,    21,    22,    23,    24,    54,    55,    56,    57,
      58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    25,    28,    29,    30,    31,    32,    36,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,     3,    32,    32,    32,     6,    47,    47,    48,
      32,    32,    45,    45,     0,     4,    35,    13,    14,    27,
      26,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    45,    45,    45,    45,     6,     8,     6,     8,    33,
      37,    41,    47,    47,    47,    48,    49,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    33,    33,    33,    33,
      33,    34,    34,    41,    45,    45,    38,    34,    34,    45,
      45,    33,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    42,    42,    42,
      43,    44,    45,    46,    46,    46,    46,    47,    47,    47,
      47,    48,    48,    48,    48,    48,    49,    49,    49,    49,
      49,    49,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    51,    52,    52,
      53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     1,     1,     1,     2,     1,     0,
       5,     3,     1,     1,     3,     3,     3,     1,     2,     2,
       3,     1,     3,     3,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     4,     4,     4,     4,     4,
       8,     8
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
#line 85 "parser.y"
                 {
        // Print the result of the expression
        fprintf(yyout, "PRODUCTION Expression %s\n", value_info_to_str((yyvsp[0].ident).id_val));
        printf("PARAM %s\n", (yyvsp[0].ident).lexema);
        if ((yyvsp[0].ident).id_val.val_type == INT_TYPE) {
            printf("CALL PUTI %s, 1\n", (yyvsp[0].ident).lexema);
        } else if ((yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
            printf("CALL PUTF %s, 1\n", (yyvsp[0].ident).lexema);
        } else if ((yyvsp[0].ident).id_val.val_type == STR_TYPE) {
            printf("CALL PUTC %s, %d\n", (yyvsp[0].ident).lexema, (yyvsp[0].ident).lenght);
        } else {
            yyerror("Unknown type in expression");
        }
    }
#line 1204 "build/parser.tab.c"
    break;

  case 10: /* repeat_statement: REPEAT expression DO statement_list DONE  */
#line 105 "parser.y"
                                             {
        if ((yyvsp[-3].ident).id_val.val_type != INT_TYPE) {
            yyerror("Repeat count must be an integer");
        } else {
            int repeat_count = (yyvsp[-3].ident).id_val.val_int;
            fprintf(yyout, "PRODUCTION Repeat %d times\n", repeat_count);
            printf("IF $t06 LTI $t05 GOTO 13\n");
        }
    }
#line 1218 "build/parser.tab.c"
    break;

  case 11: /* assignment: ID ASSIGN expression  */
#line 117 "parser.y"
                         {
        fprintf(yyout, "PRODUCTION Assignment %s := %s\n", (yyvsp[-2].ident).lexema, value_info_to_str((yyvsp[0].ident).id_val));
        // Assign only if the type is compatible or if it has not been initialized
        if ((yyvsp[-2].ident).id_val.val_type == UNKNOWN_TYPE || (yyvsp[-2].ident).id_val.val_type == (yyvsp[0].ident).id_val.val_type) {
            (yyvsp[-2].ident).id_val.val_type = (yyvsp[0].ident).id_val.val_type;
            if ((yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                (yyvsp[-2].ident).id_val.val_int = (yyvsp[0].ident).id_val.val_int;
            } else if ((yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                (yyvsp[-2].ident).id_val.val_float = (yyvsp[0].ident).id_val.val_float;
            } else if ((yyvsp[0].ident).id_val.val_type == STR_TYPE) {
                (yyvsp[-2].ident).id_val.val_str = (yyvsp[0].ident).id_val.val_str;
            } else if ((yyvsp[0].ident).id_val.val_type == BOOL_TYPE) {
                (yyvsp[-2].ident).id_val.val_bool = (yyvsp[0].ident).id_val.val_bool;
            }
            value_info value = {
                .val_type = (yyvsp[0].ident).id_val.val_type,
                .val_int = (yyvsp[0].ident).id_val.val_int,
                .val_float = (yyvsp[0].ident).id_val.val_float,
                .val_bool = (yyvsp[0].ident).id_val.val_bool,
                .val_str = (yyvsp[0].ident).id_val.val_str
            };
            int symtab_status = sym_enter((yyvsp[-2].ident).lexema, &value);
            if (symtab_status == SYMTAB_OK || symtab_status == SYMTAB_DUPLICATE) {
                printf("%s := %s\n", (yyvsp[-2].ident).lexema, value_info_to_str((yyvsp[-2].ident).id_val));
            } else {
                yyerror("Error: Variable could not be entered into the symbol table. Stack overflow.");
            }
        } else {
            yyerror("Incompatible types in assignment");
        }
    }
#line 1254 "build/parser.tab.c"
    break;

  case 14: /* expr_arithmetic: expr_arithmetic PLUS expr_unary  */
#line 156 "parser.y"
                                      {
        fprintf(yyout, "PRODUCTION expr_arithmetic %s + %s\n", value_info_to_str((yyvsp[-2].ident).id_val), value_info_to_str((yyvsp[0].ident).id_val));
        char *temp_var = NULL;
        // Verify that are numbers
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) &&
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                    (yyval.ident).id_val.val_int = ((yyvsp[-2].ident).id_val.val_int + (yyvsp[0].ident).id_val.val_int);
                    (yyval.ident).id_val.val_type = INT_TYPE;
                    temp_var = generate_temp_var();
                    printf("%s := %s ADDI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                } else {
                    if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                        (yyval.ident).id_val.val_float = (yyvsp[-2].ident).id_val.val_float + (yyvsp[0].ident).id_val.val_float;
                        temp_var = generate_temp_var();
                        printf("%s := %s ADDF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    } else if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_float + (yyvsp[0].ident).id_val.val_int;
                        *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, (yyvsp[0].ident).lexema);
                        printf("%s := %s ADDF %s\n", temp_var, (yyvsp[-2].ident).lexema, new_temp_var);
                    } else {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_int + (yyvsp[0].ident).id_val.val_float;
                        *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, (yyvsp[-2].ident).lexema);
                        printf("%s := %s ADDF %s\n", temp_var, new_temp_var, (yyvsp[0].ident).lexema);
                    }
                    (yyval.ident).id_val.val_type = FLOAT_TYPE;
                }
            } else if (((yyvsp[-2].ident).id_val.val_type != UNKNOWN_TYPE && (yyvsp[0].ident).id_val.val_type != UNKNOWN_TYPE) && 
                        ((yyvsp[-2].ident).id_val.val_type == STR_TYPE || (yyvsp[0].ident).id_val.val_type == STR_TYPE)) {
                // Concatenate strings
                (yyval.ident).id_val.val_str = concat(value_to_str((yyvsp[-2].ident)), value_to_str((yyvsp[0].ident)));    
                (yyval.ident).id_val.val_type = STR_TYPE;
                temp_var = generate_temp_var();
                printf("%s := %s CONCAT %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
            }
            else {
                yyerror("Type error: Unknown type in addition operation");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            }
            (yyval.ident).id_val.lexema = temp_var;
    }
#line 1304 "build/parser.tab.c"
    break;

  case 15: /* expr_arithmetic: expr_arithmetic MINUS expr_unary  */
#line 201 "parser.y"
                                       {
        fprintf(yyout, "PRODUCTION expr_arithmetic %s - %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        char *temp_var = NULL;
        // Verify that are numbers
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) &&
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                    (yyval.ident).id_val.val_int = ((yyvsp[-2].ident).id_val.val_int - (yyvsp[0].ident).id_val.val_int);
                    (yyval.ident).id_val.val_type = INT_TYPE;
                    temp_var = generate_temp_var();
                    printf("%s := %s SUBI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                } else {
                    if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                        (yyval.ident).id_val.val_float = (yyvsp[-2].ident).id_val.val_float - (yyvsp[0].ident).id_val.val_float;
                        temp_var = generate_temp_var();
                        printf("%s := %s SUBF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    } else if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_float - (yyvsp[0].ident).id_val.val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, (yyvsp[0].ident).lexema);
                        printf("%s := %s SUBF %s\n", temp_var, (yyvsp[-2].ident).lexema, new_temp_var);
                    } else {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).id_val.val_int - (yyvsp[0].ident).id_val.val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, (yyvsp[-2].ident).lexema);
                        printf("%s := %s SUBF %s\n", temp_var, new_temp_var, (yyvsp[0].ident).lexema);
                    }
                    (yyval.ident).id_val.val_type = FLOAT_TYPE;
                }
            } else {
                yyerror("Type error: Subtraction operation is only allowed between numeric values");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            }
            (yyval.ident).lexema = temp_var;
    }
#line 1346 "build/parser.tab.c"
    break;

  case 16: /* expr_arithmetic: expr_arithmetic OR expr_unary  */
#line 238 "parser.y"
                                    {
        fprintf(yyout, "PRODUCTION expr_arithmetic %s OR %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        // Verify that are booleans
        if ((yyvsp[-2].ident).id_val.val_type == BOOL_TYPE && (yyvsp[0].ident).id_val.val_type == BOOL_TYPE) {
            (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).id_val.val_bool || (yyvsp[0].ident).id_val.val_bool;
            (yyval.ident).id_val.val_type = BOOL_TYPE;
        } else {
            yyerror("Type error: Logical OR operation is only allowed between boolean values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1362 "build/parser.tab.c"
    break;

  case 18: /* expr_unary: PLUS expr_unary  */
#line 253 "parser.y"
                      {
        fprintf(yyout, "PRODUCTION expr_unary + %s\n", value_info_to_str((yyvsp[0].ident)));
        // Verify its a number
        if ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
            if ((yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                (yyval.ident).id_val.val_int = (yyvsp[0].ident).id_val.val_int;
                (yyval.ident).id_val.val_type = INT_TYPE;
            } else {
                (yyval.ident).id_val.val_float = (yyvsp[0].ident).val_float;
                (yyval.ident).id_val.val_type = FLOAT_TYPE;
            }
        } else {
            yyerror("Type error: Unary plus operation is only allowed on numeric values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1383 "build/parser.tab.c"
    break;

  case 19: /* expr_unary: MINUS expr_unary  */
#line 269 "parser.y"
                       {
        fprintf(yyout, "PRODUCTION expr_unary - %s\n", value_info_to_str((yyvsp[0].ident)));
        char *temp_var = NULL;
        // Verify its a number
        if ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
            if ((yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                (yyval.ident).id_val.val_int = (yyvsp[0].ident).id_val.val_int * -1;
                (yyval.ident).id_val.val_type = INT_TYPE;
                temp_var = generate_temp_var();
                printf("%s := CHSI %s\n", temp_var, (yyvsp[0].ident).lexema);
            } else {
                (yyval.ident).id_val.val_float = (yyvsp[0].ident).id_val.val_float * -1;
                (yyval.ident).id_val.val_type = FLOAT_TYPE;
                temp_var = generate_temp_var();
                printf("%s := CHSF %s\n", temp_var, (yyvsp[0].ident).lexema);
            }
        } else {
            yyerror("Type error: Unary minus operation is only allowed on numeric values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
        (yyval.ident).lexema = temp_var;
    }
#line 1410 "build/parser.tab.c"
    break;

  case 20: /* expr_unary: expr_unary AND expr_term  */
#line 291 "parser.y"
                               {
        fprintf(yyout, "PRODUCTION expr_unary %s AND %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        // Verify that are booleans
        if ((yyvsp[-2].ident).id_val.val_type == BOOL_TYPE && (yyvsp[0].ident).id_val.val_type == BOOL_TYPE) {
            (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).id_val.val_bool && (yyvsp[0].ident).id_val.val_bool;
            (yyval.ident).id_val.val_type = BOOL_TYPE;
        } else {
            yyerror("Type error: Logical AND operation is only allowed between boolean values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1426 "build/parser.tab.c"
    break;

  case 22: /* expr_term: expr_term MULT expr_pow  */
#line 306 "parser.y"
                              {
        fprintf(yyout, "PRODUCTION expr_term %s * %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        char *temp_var = NULL;
        // Verify that are numbers
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) &&
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                    (yyval.ident).id_val.val_int = ((yyvsp[-2].ident).val_int * (yyvsp[0].ident).val_int);
                    (yyval.ident).id_val.val_type = INT_TYPE;
                    temp_var = generate_temp_var();
                    printf("%s := %s MULI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                } else {
                    if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                        (yyval.ident).id_val.val_float = (yyvsp[-2].ident).val_float * (yyvsp[0].ident).val_float;
                        temp_var = generate_temp_var();
                        printf("%s := %s MULF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    } else if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).val_float * (yyvsp[0].ident).val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, (yyvsp[0].ident).lexema);
                        printf("%s := %s MULF %s\n", temp_var, (yyvsp[-2].ident).lexema, new_temp_var);
                    } else {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).val_int * (yyvsp[0].ident).val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, (yyvsp[-2].ident).lexema);
                        printf("%s := %s MULF %s\n", temp_var, new_temp_var, (yyvsp[0].ident).lexema);
                    }
                    (yyval.ident).id_val.val_type = FLOAT_TYPE;
                }
            } else {
                yyerror("Type error: Multiplication operation is only allowed between numeric values");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            }
            (yyval.ident).lexema = temp_var;
    }
#line 1468 "build/parser.tab.c"
    break;

  case 23: /* expr_term: expr_term DIV expr_pow  */
#line 343 "parser.y"
                             {
        fprintf(yyout, "PRODUCTION expr_term %s / %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        char *temp_var = NULL;
        // Verify that are numbers
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) &&
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = FLOAT_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                    (yyval.ident).id_val.val_float = (float) ((yyvsp[-2].ident).val_int / (yyvsp[0].ident).val_int);
                    temp_var = generate_temp_var();
                    printf("%s := %s DIVI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                } else {
                    if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                        (yyval.ident).id_val.val_float = (yyvsp[-2].ident).val_float / (yyvsp[0].ident).val_float;
                        temp_var = generate_temp_var();
                        printf("%s := %s DIVF %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
                    } else if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).val_float / (yyvsp[0].ident).val_int;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, (yyvsp[0].ident).lexema);
                        printf("%s := %s DIVF %s\n", temp_var, (yyvsp[-2].ident).lexema, new_temp_var);
                    } else {
                        (yyval.ident).id_val.val_float = (float) (yyvsp[-2].ident).val_int / (yyvsp[0].ident).val_float;
                        char *new_temp_var = generate_temp_var();
                        temp_var = generate_temp_var();
                        printf("%s := I2F %s\n", new_temp_var, (yyvsp[-2].ident).lexema);
                        printf("%s := %s DIVF %s\n", temp_var, new_temp_var, (yyvsp[0].ident).lexema);
                    }
                }
            } else {
                yyerror("Type error: Division operation is only allowed between numeric values");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            }
            (yyval.ident).lexema = temp_var;
    }
#line 1509 "build/parser.tab.c"
    break;

  case 24: /* expr_term: expr_term MOD expr_pow  */
#line 379 "parser.y"
                             {
        fprintf(yyout, "PRODUCTION expr_term %s %% %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        char *temp_var = NULL;
        // Verify that both operands are integers
        if ((yyvsp[-2].ident).id_val.val_type == INT_TYPE && (yyvsp[0].ident).id_val.val_type == INT_TYPE) {
            (yyval.ident).id_val.val_type = INT_TYPE;
            (yyval.ident).id_val.val_int = (yyvsp[-2].ident).val_int % (yyvsp[0].ident).val_int;
            temp_var = generate_temp_var();
            printf("%s := %s MODI %s\n", temp_var, (yyvsp[-2].ident).lexema, (yyvsp[0].ident).lexema);
        } else {
            yyerror("Type error: Modulus operation is only allowed between integers");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
        (yyval.ident).lexema = temp_var;
    }
#line 1529 "build/parser.tab.c"
    break;

  case 25: /* expr_term: NOT expr_term  */
#line 394 "parser.y"
                    {
        fprintf(yyout, "PRODUCTION NOT %s\n", value_info_to_str((yyvsp[0].ident)));
        // Verify that the operand is a boolean
        if ((yyvsp[0].ident).id_val.val_type == BOOL_TYPE) {
            (yyval.ident).id_val.val_type = BOOL_TYPE;
            (yyval.ident).id_val.val_bool = !(yyvsp[0].ident).id_val.val_bool;
        } else {
            yyerror("Type error: Logical NOT operation is only allowed on boolean values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1545 "build/parser.tab.c"
    break;

  case 27: /* expr_pow: expr_pow POW factor  */
#line 409 "parser.y"
                          {
        fprintf(yyout, "PRODUCTION expr_pow %s ** %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        // Verify that both operands are numeric (int or float)
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) &&
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
            // Perform the power operation based on the operand types
            if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                // Convert to float if either operand is float
                (yyval.ident).id_val.val_type = FLOAT_TYPE;
                (yyval.ident).id_val.val_float = pow(
                    ((yyvsp[-2].ident).id_val.val_type == INT_TYPE) ? (float)(yyvsp[-2].ident).val_int : (yyvsp[-2].ident).val_float,
                    ((yyvsp[0].ident).id_val.val_type == INT_TYPE) ? (float)(yyvsp[0].ident).val_int : (yyvsp[0].ident).val_float
                );
            } else {
                // If both are integers, keep the integer type
                (yyval.ident).id_val.val_type = INT_TYPE;
                (yyval.ident).id_val.val_int = (int)pow((yyvsp[-2].ident).val_int, (yyvsp[0].ident).val_int);
            }
        } else {
            yyerror("Type error: Power operation is only allowed between numeric values");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1573 "build/parser.tab.c"
    break;

  case 28: /* expr_pow: expr_pow GT factor  */
#line 432 "parser.y"
                         {
        fprintf(yyout, "PRODUCTION expr_pow %s > %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).val_int : (yyvsp[-2].ident).val_float) > 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).val_int : (yyvsp[0].ident).val_float);
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).val_int > (yyvsp[0].ident).val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1594 "build/parser.tab.c"
    break;

  case 29: /* expr_pow: expr_pow LT factor  */
#line 448 "parser.y"
                         {
        fprintf(yyout, "PRODUCTION expr_pow %s < %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).val_int : (yyvsp[-2].ident).val_float) < 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).val_int : (yyvsp[0].ident).val_float);
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).val_int < (yyvsp[0].ident).val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1615 "build/parser.tab.c"
    break;

  case 30: /* expr_pow: expr_pow GE factor  */
#line 464 "parser.y"
                         {
        fprintf(yyout, "PRODUCTION expr_pow %s >= %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).val_int : (yyvsp[-2].ident).val_float) >= 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).val_int : (yyvsp[0].ident).val_float);
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).val_int >= (yyvsp[0].ident).val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1636 "build/parser.tab.c"
    break;

  case 31: /* expr_pow: expr_pow LE factor  */
#line 480 "parser.y"
                         {
        fprintf(yyout, "PRODUCTION expr_pow %s <= %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).val_int : (yyvsp[-2].ident).val_float) <= 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).val_int : (yyvsp[0].ident).val_float);
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).val_int <= (yyvsp[0].ident).val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1657 "build/parser.tab.c"
    break;

  case 32: /* expr_pow: expr_pow EQ factor  */
#line 496 "parser.y"
                         {
        fprintf(yyout, "PRODUCTION expr_pow %s == %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
        if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).val_int : (yyvsp[-2].ident).val_float) == 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).val_int : (yyvsp[0].ident).val_float);
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).val_int == (yyvsp[0].ident).val_int;
                }
        } else {
            yyerror("Type error: Comparison requires numeric types");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }

    }
#line 1679 "build/parser.tab.c"
    break;

  case 33: /* expr_pow: expr_pow NE factor  */
#line 513 "parser.y"
                         {
        fprintf(yyout, "PRODUCTION expr_pow %s != %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
         if (((yyvsp[-2].ident).id_val.val_type == INT_TYPE || (yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE) && 
            ((yyvsp[0].ident).id_val.val_type == INT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE)) {
                (yyval.ident).id_val.val_type = BOOL_TYPE;
                if ((yyvsp[-2].ident).id_val.val_type == FLOAT_TYPE || (yyvsp[0].ident).id_val.val_type == FLOAT_TYPE) {
                    (yyval.ident).id_val.val_bool = ((yyvsp[-2].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[-2].ident).val_int : (yyvsp[-2].ident).val_float) != 
                        ((yyvsp[0].ident).id_val.val_type == INT_TYPE ? (float)(yyvsp[0].ident).val_int : (yyvsp[0].ident).val_float);
                } else {
                    (yyval.ident).id_val.val_bool = (yyvsp[-2].ident).val_int != (yyvsp[0].ident).val_int;
                }
        } else {
            fprintf(yyout, "PRODUCTION ERROR expr_pow %s != %s\n", value_info_to_str((yyvsp[-2].ident)), value_info_to_str((yyvsp[0].ident)));
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1700 "build/parser.tab.c"
    break;

  case 34: /* factor: ID  */
#line 532 "parser.y"
       {
        fprintf(yyout, "PRODUCTION ID Factor %s\n", (yyvsp[0].ident).lexema);
        value_info value;
        if (sym_lookup((yyvsp[0].ident).lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
        } else {
                (yyval.ident) = value;
            }
    }
#line 1714 "build/parser.tab.c"
    break;

  case 35: /* factor: INTEGER  */
#line 541 "parser.y"
              {
        fprintf(yyout, "PRODUCTION INTEGER Factor %d\n", (yyvsp[0].ident));
        (yyval.ident).id_val.val_type = INT_TYPE;
        (yyval.ident).id_val.val_int = (yyvsp[0].ident);
        // store value as char in lexema
        (yyval.ident).id_val.lexema = (char *)malloc(10);
        sprintf((yyval.ident).id_val.lexema, "%d", (yyvsp[0].ident));
    }
#line 1727 "build/parser.tab.c"
    break;

  case 36: /* factor: STRING  */
#line 549 "parser.y"
             {
        fprintf(yyout, "PRODUCTION STRING Factor %s\n", (yyvsp[0].string));
        (yyval.ident).id_val.val_type = STR_TYPE;
        (yyval.ident).id_val.val_str = substr((yyvsp[0].string), 1, strlen((yyvsp[0].string)) - 2);
    }
#line 1737 "build/parser.tab.c"
    break;

  case 37: /* factor: BOOLEAN  */
#line 554 "parser.y"
              {
        fprintf(yyout, "PRODUCTION BOOLEAN Factor %d\n", (yyvsp[0].boolean));
        (yyval.ident).id_val.val_type = BOOL_TYPE;
        (yyval.ident).id_val.val_bool = (yyvsp[0].boolean);
    }
#line 1747 "build/parser.tab.c"
    break;

  case 38: /* factor: REAL  */
#line 559 "parser.y"
           {
        fprintf(yyout, "PRODUCTION REAL Factor %f\n", (yyvsp[0].real));
        (yyval.ident).id_val.val_type = FLOAT_TYPE;
        (yyval.ident).id_val.val_float = (yyvsp[0].real);
    }
#line 1757 "build/parser.tab.c"
    break;

  case 39: /* factor: PI  */
#line 564 "parser.y"
         {
        fprintf(yyout, "PRODUCTION PI Factor\n");
        (yyval.ident).id_val.val_type = FLOAT_TYPE;
        (yyval.ident).id_val.val_float = 3.141592653589793;
    }
#line 1767 "build/parser.tab.c"
    break;

  case 40: /* factor: E  */
#line 569 "parser.y"
        {
        fprintf(yyout, "PRODUCTION E Factor\n");
        (yyval.ident).id_val.val_type = FLOAT_TYPE;
        (yyval.ident).id_val.val_float = 2.718281828459045;
    }
#line 1777 "build/parser.tab.c"
    break;

  case 41: /* factor: LPAREN expression RPAREN  */
#line 574 "parser.y"
                               {
        fprintf(yyout, "PRODUCTION LPAREN expression RPAREN %s\n", value_info_to_str((yyvsp[-1].ident)));
        (yyval.ident) = (yyvsp[-1].ident);
    }
#line 1786 "build/parser.tab.c"
    break;

  case 45: /* expr_trig: SIN LPAREN expression RPAREN  */
#line 584 "parser.y"
                                 {
        // Verify if the parameter is a number
        fprintf(yyout, "PRODUCTION SIN %s\n", value_info_to_str((yyvsp[-1].ident)));
        if ((yyvsp[-1].ident).id_val.val_type == INT_TYPE) {
            (yyval.ident).id_val.val_float = sin((yyvsp[-1].ident).val_int);
            (yyval.ident).id_val.val_type = FLOAT_TYPE;
        } else if ((yyvsp[-1].ident).id_val.val_type == FLOAT_TYPE) {
            (yyval.ident).id_val.val_float = sin((yyvsp[-1].ident).val_float);
            (yyval.ident).id_val.val_type = FLOAT_TYPE;
        } else {
            yyerror("The sine function only applies to numbers.");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1805 "build/parser.tab.c"
    break;

  case 46: /* expr_trig: COS LPAREN expression RPAREN  */
#line 598 "parser.y"
                                   {
        fprintf(yyout, "PRODUCTION COS %s\n", value_info_to_str((yyvsp[-1].ident)));
        if ((yyvsp[-1].ident).id_val.val_type == INT_TYPE) {
            (yyval.ident).id_val.val_float = cos((yyvsp[-1].ident).val_int);
            (yyval.ident).id_val.val_type = FLOAT_TYPE;
        } else if ((yyvsp[-1].ident).id_val.val_type == FLOAT_TYPE) {
            (yyval.ident).id_val.val_float = cos((yyvsp[-1].ident).val_float);
            (yyval.ident).id_val.val_type = FLOAT_TYPE;
        } else {
            yyerror("The cosine function only applies to numbers.");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
        
    }
#line 1824 "build/parser.tab.c"
    break;

  case 47: /* expr_trig: TAN LPAREN expression RPAREN  */
#line 612 "parser.y"
                                   {
        fprintf(yyout, "PRODUCTION TAN %s\n", value_info_to_str((yyvsp[-1].ident)));
        if ((yyvsp[-1].ident).id_val.val_type == INT_TYPE) {
            (yyval.ident).id_val.val_float = tan((yyvsp[-1].ident).val_int);
            (yyval.ident).id_val.val_type = FLOAT_TYPE;
        } else if ((yyvsp[-1].ident).id_val.val_type == FLOAT_TYPE) {
            (yyval.ident).id_val.val_float = tan((yyvsp[-1].ident).val_float);
            (yyval.ident).id_val.val_type = FLOAT_TYPE;
        } else {
            yyerror("The tangent function only applies to numbers.");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1842 "build/parser.tab.c"
    break;

  case 48: /* expr_len: LEN LPAREN STRING RPAREN  */
#line 628 "parser.y"
                             {
        fprintf(yyout, "PRODUCTION STRING LEN %s\n", (yyvsp[-1].string));
        (yyval.ident).id_val.val_int = strlen((yyvsp[-1].string));
        (yyval.ident).id_val.val_type = INT_TYPE;
    }
#line 1852 "build/parser.tab.c"
    break;

  case 49: /* expr_len: LEN LPAREN ID RPAREN  */
#line 633 "parser.y"
                           {
        fprintf(yyout, "PRODUCTION ID LEN %s\n", (yyvsp[-1].ident).lexema);
        value_info value;
        if (sym_lookup((yyvsp[-1].ident).lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        } else {
            if (value.val_type != STR_TYPE) {
                yyerror("The len function only applies to strings.");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            } else {
                (yyval.ident).id_val.val_int = strlen(value.val_str);
                (yyval.ident).id_val.val_type = INT_TYPE;
            }
        }
    }
#line 1873 "build/parser.tab.c"
    break;

  case 50: /* expr_substr: SUBSTR LPAREN STRING COMMA expression COMMA expression RPAREN  */
#line 652 "parser.y"
                                                                  {
        fprintf(yyout, "PRODUCTION STRING SUBSTR %s\n", (yyvsp[-5].string));
        // Verify if the indexes are integers
        if ((yyvsp[-3].ident).val_type == INT_TYPE && (yyvsp[-1].ident).val_type == INT_TYPE) {
            (yyval.ident).id_val.val_str = substr((yyvsp[-5].string), (yyvsp[-3].ident).val_int, (yyvsp[-1].ident).val_int);
            (yyval.ident).id_val.val_type = STR_TYPE;
        } else {
            yyerror("Substrings indexes must be integers.");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        }
    }
#line 1889 "build/parser.tab.c"
    break;

  case 51: /* expr_substr: SUBSTR LPAREN ID COMMA expression COMMA expression RPAREN  */
#line 663 "parser.y"
                                                                {
        fprintf(yyout, "PRODUCTION ID SUBSTR %s\n", (yyvsp[-5].ident).lexema);
        value_info value;
        if (sym_lookup((yyvsp[-5].ident).lexema, &value) == SYMTAB_NOT_FOUND) {
            yyerror("Variable not found");
            (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
        } else {
            if (value.val_type != STR_TYPE) {
                yyerror("The substr function only applies to strings.");
                (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
            } else {
                if ((yyvsp[-3].ident).val_type == INT_TYPE && (yyvsp[-1].ident).val_type == INT_TYPE) {
                    (yyval.ident).id_val.val_str = substr(value.val_str, (yyvsp[-3].ident).val_int, (yyvsp[-1].ident).val_int);
                    (yyval.ident).id_val.val_type = STR_TYPE;
                } else {
                    yyerror("Substrings indexes must be integers.");
                    (yyval.ident).id_val.val_type = UNKNOWN_TYPE;
                }
            }
        }
    }
#line 1915 "build/parser.tab.c"
    break;


#line 1919 "build/parser.tab.c"

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

#line 686 "parser.y"

