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
#line 1 "minic.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaSimbolos.h"
#include "listaCodigo.h"

extern int yylineno;
extern char *yytext;
extern int yylex();
void yyerror();

void print_code(ListaC code);
void symtable_print();
void setup_program();
void symtable_push(const char *id);
void ds_push_word(char *id);
const char* ds_push_asciiz(const char *lstr);
void cl_program(const char *id, ListaC decls, ListaC statements);
ListaC cl_push_const_list(ListaC constl, const char *id, ListaC vl);
ListaC cl_push_lint(const char *lint);
ListaC cl_push_id(const char *id);
ListaC cl_push_ominus_expr(ListaC l);
ListaC cl_push_condop(ListaC cond, ListaC tl, ListaC fl);
ListaC cl_push_binop(const char *inst, ListaC ll, ListaC rl);
ListaC cl_push_assign(const char *id, ListaC l);
ListaC cl_push_if_else(ListaC cond, ListaC ifl, ListaC elsel);
ListaC cl_push_if(ListaC cond, ListaC ifl);
ListaC cl_push_while(ListaC cond, ListaC statementl);
ListaC cl_push_print_expr(ListaC exprl);
ListaC cl_push_print_str(const char *lstr);
ListaC cl_push_read(const char *id);

Lista symtable = NULL;
ListaC dataseg = NULL;
int regs[10] = { 0 };
const char reg_strs[][10] = {
    "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"
};

int string_counter = 0;
int label_counter = 0;

#define _DEBUG_

#ifdef _DEBUG_
#define insertaLC(l, p, op) { \
    if (op.arg2) \
        printf("==%d: pushing `%s %s, %s, %s'\n", \
            yylineno, op.op, op.res, op.arg1, op.arg2); \
    else \
        printf("==%d: pushing `%s %s, %s'\n", \
            yylineno, op.op, op.res, op.arg1); \
    insertaLC(l, p, op); \
}

#define insertaLS(l, p, s) { \
    printf("==%d: pushing symbol '%s'\n", yylineno, s.nombre); \
    insertaLS(l, p, s); \
}
#endif



#line 137 "minic.tab.c"

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

#include "minic.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RVAR = 3,                       /* RVAR  */
  YYSYMBOL_RCONST = 4,                     /* RCONST  */
  YYSYMBOL_RINT = 5,                       /* RINT  */
  YYSYMBOL_RIF = 6,                        /* RIF  */
  YYSYMBOL_RELSE = 7,                      /* RELSE  */
  YYSYMBOL_RWHILE = 8,                     /* RWHILE  */
  YYSYMBOL_RPRINT = 9,                     /* RPRINT  */
  YYSYMBOL_RREAD = 10,                     /* RREAD  */
  YYSYMBOL_SEMICOLON = 11,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_OPLUS = 13,                     /* OPLUS  */
  YYSYMBOL_OMINUS = 14,                    /* OMINUS  */
  YYSYMBOL_OASTERISK = 15,                 /* OASTERISK  */
  YYSYMBOL_OSLASH = 16,                    /* OSLASH  */
  YYSYMBOL_OEQUALS = 17,                   /* OEQUALS  */
  YYSYMBOL_PARENL = 18,                    /* PARENL  */
  YYSYMBOL_PARENR = 19,                    /* PARENR  */
  YYSYMBOL_BRACKETL = 20,                  /* BRACKETL  */
  YYSYMBOL_BRACKETR = 21,                  /* BRACKETR  */
  YYSYMBOL_QUESTIONMARK = 22,              /* QUESTIONMARK  */
  YYSYMBOL_COLON = 23,                     /* COLON  */
  YYSYMBOL_ID = 24,                        /* ID  */
  YYSYMBOL_LSTR = 25,                      /* LSTR  */
  YYSYMBOL_LINT = 26,                      /* LINT  */
  YYSYMBOL_YYACCEPT = 27,                  /* $accept  */
  YYSYMBOL_program = 28,                   /* program  */
  YYSYMBOL_29_1 = 29,                      /* $@1  */
  YYSYMBOL_decls = 30,                     /* decls  */
  YYSYMBOL_type = 31,                      /* type  */
  YYSYMBOL_var_list = 32,                  /* var_list  */
  YYSYMBOL_const_list = 33,                /* const_list  */
  YYSYMBOL_statement_list = 34,            /* statement_list  */
  YYSYMBOL_statement = 35,                 /* statement  */
  YYSYMBOL_print_list = 36,                /* print_list  */
  YYSYMBOL_print_item = 37,                /* print_item  */
  YYSYMBOL_read_list = 38,                 /* read_list  */
  YYSYMBOL_expr = 39                       /* expr  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   121

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


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
      25,    26
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    89,    92,    93,    94,    97,   100,   101,
     104,   105,   108,   109,   112,   113,   114,   115,   116,   117,
     118,   121,   122,   125,   126,   129,   130,   133,   134,   135,
     136,   137,   138,   139,   140,   141
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
  "\"end of file\"", "error", "\"invalid token\"", "RVAR", "RCONST",
  "RINT", "RIF", "RELSE", "RWHILE", "RPRINT", "RREAD", "SEMICOLON",
  "COMMA", "OPLUS", "OMINUS", "OASTERISK", "OSLASH", "OEQUALS", "PARENL",
  "PARENR", "BRACKETL", "BRACKETR", "QUESTIONMARK", "COLON", "ID", "LSTR",
  "LINT", "$accept", "program", "$@1", "decls", "type", "var_list",
  "const_list", "statement_list", "statement", "print_list", "print_item",
  "read_list", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -60,     4,   -17,   -60,    -4,     1,     9,   -60,    55,    18,
      18,    28,   -60,    23,    26,    88,    89,    90,    91,   -60,
     -60,    59,   -60,   -60,    71,    84,    93,    -5,    -5,    -8,
      86,    45,    -5,   -60,    92,    -5,   -60,    94,    -5,    -5,
     -60,   -60,    58,    65,   -60,     3,   -60,    83,   -60,    56,
     -60,    79,   -60,    83,    95,    87,    48,    -5,    -5,    -5,
      -5,    36,    36,    -8,    78,    96,   100,   -60,    -5,   -60,
      -5,    24,    87,   -60,    98,   107,   -60,   -60,   -60,   -60,
     -60,    83,    12,    36,    -5,   -60,    72,   -60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     6,    13,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,    13,
       3,     0,    12,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     5,     0,     0,     0,
      34,    35,     0,     0,    24,     0,    21,    23,    25,     0,
      15,     0,     9,    10,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    33,
       0,    27,    28,    29,    30,    17,    18,    22,    19,    26,
      20,    11,     0,     0,     0,    16,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,   -60,   105,   -60,   -60,   102,   -59,   -60,
      54,   -60,   -27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     8,    13,    24,    26,    11,    22,    45,
      46,    49,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    43,    75,    76,     3,    51,    38,     4,    53,    38,
      39,    55,    56,    39,     5,    63,    40,    44,    41,    40,
       6,    41,    64,    12,    85,    57,    58,    59,    60,     7,
      71,    72,    73,    74,    15,    84,    16,    17,    18,    59,
      60,    81,    15,    82,    16,    17,    18,    23,    19,    20,
      25,    15,    21,    16,    17,    18,    19,    86,     9,    10,
      21,    57,    58,    59,    60,    19,    50,    69,    65,    21,
      70,    57,    58,    59,    60,    66,    32,    61,    57,    58,
      59,    60,    33,    34,    62,    57,    58,    59,    60,    78,
      67,    87,    57,    58,    59,    60,    57,    58,    59,    60,
      57,    35,    59,    60,    36,    37,    27,    28,    29,    30,
      48,    80,    68,    59,    83,    14,    52,    77,    54,     0,
      79,    31
};

static const yytype_int8 yycheck[] =
{
      27,    28,    61,    62,     0,    32,    14,    24,    35,    14,
      18,    38,    39,    18,    18,    12,    24,    25,    26,    24,
      19,    26,    19,     5,    83,    13,    14,    15,    16,    20,
      57,    58,    59,    60,     6,    23,     8,     9,    10,    15,
      16,    68,     6,    70,     8,     9,    10,    24,    20,    21,
      24,     6,    24,     8,     9,    10,    20,    84,     3,     4,
      24,    13,    14,    15,    16,    20,    21,    19,    12,    24,
      22,    13,    14,    15,    16,    19,    17,    19,    13,    14,
      15,    16,    11,    12,    19,    13,    14,    15,    16,    11,
      11,    19,    13,    14,    15,    16,    13,    14,    15,    16,
      13,    17,    15,    16,    11,    12,    18,    18,    18,    18,
      24,    11,    17,    15,     7,    10,    24,    63,    24,    -1,
      24,    19
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    29,     0,    24,    18,    19,    20,    30,     3,
       4,    34,     5,    31,    31,     6,     8,     9,    10,    20,
      21,    24,    35,    24,    32,    24,    33,    18,    18,    18,
      18,    34,    17,    11,    12,    17,    11,    12,    14,    18,
      24,    26,    39,    39,    25,    36,    37,    39,    24,    38,
      21,    39,    24,    39,    24,    39,    39,    13,    14,    15,
      16,    19,    19,    12,    19,    12,    19,    11,    17,    19,
      22,    39,    39,    39,    39,    35,    35,    37,    11,    24,
      11,    39,    39,     7,    23,    35,    39,    19
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    27,    29,    28,    30,    30,    30,    31,    32,    32,
      33,    33,    34,    34,    35,    35,    35,    35,    35,    35,
      35,    36,    36,    37,    37,    38,    38,    39,    39,    39,
      39,    39,    39,    39,    39,    39
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     5,     5,     0,     1,     1,     3,
       3,     5,     2,     0,     4,     3,     7,     5,     5,     5,
       5,     1,     3,     1,     1,     1,     3,     3,     3,     3,
       3,     7,     2,     3,     1,     1
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
  case 2: /* $@1: %empty  */
#line 89 "minic.y"
          { setup_program(); }
#line 1216 "minic.tab.c"
    break;

  case 3: /* program: $@1 ID PARENL PARENR BRACKETL decls statement_list BRACKETR  */
#line 89 "minic.y"
                                                                                       { cl_program((yyvsp[-6].lex), (yyvsp[-2].code), (yyvsp[-1].code));  }
#line 1222 "minic.tab.c"
    break;

  case 4: /* decls: decls RVAR type var_list SEMICOLON  */
#line 92 "minic.y"
                                           { (yyval.code) = (yyvsp[-4].code); }
#line 1228 "minic.tab.c"
    break;

  case 5: /* decls: decls RCONST type const_list SEMICOLON  */
#line 93 "minic.y"
                                               { concatenaLC((yyvsp[-4].code), (yyvsp[-1].code)); (yyval.code) = (yyvsp[-4].code); }
#line 1234 "minic.tab.c"
    break;

  case 6: /* decls: %empty  */
#line 94 "minic.y"
        { (yyval.code) = creaLC(); }
#line 1240 "minic.tab.c"
    break;

  case 8: /* var_list: ID  */
#line 100 "minic.y"
              { symtable_push((yyvsp[0].lex)); ds_push_word((yyvsp[0].lex)); }
#line 1246 "minic.tab.c"
    break;

  case 9: /* var_list: var_list COMMA ID  */
#line 101 "minic.y"
                             { symtable_push((yyvsp[0].lex)); ds_push_word((yyvsp[0].lex)); }
#line 1252 "minic.tab.c"
    break;

  case 10: /* const_list: ID OEQUALS expr  */
#line 104 "minic.y"
                             { symtable_push((yyvsp[-2].lex)); ds_push_word((yyvsp[-2].lex)); (yyval.code) = cl_push_const_list(creaLC(), (yyvsp[-2].lex), (yyvsp[0].code)); }
#line 1258 "minic.tab.c"
    break;

  case 11: /* const_list: const_list COMMA ID OEQUALS expr  */
#line 105 "minic.y"
                                              { symtable_push((yyvsp[-2].lex)); ds_push_word((yyvsp[-2].lex)); (yyval.code) = cl_push_const_list((yyvsp[-4].code), (yyvsp[-2].lex), (yyvsp[0].code)); }
#line 1264 "minic.tab.c"
    break;

  case 12: /* statement_list: statement_list statement  */
#line 108 "minic.y"
                                          { concatenaLC((yyvsp[-1].code), (yyvsp[0].code)); (yyval.code) = (yyvsp[-1].code); }
#line 1270 "minic.tab.c"
    break;

  case 13: /* statement_list: %empty  */
#line 109 "minic.y"
                 {(yyval.code) = creaLC();}
#line 1276 "minic.tab.c"
    break;

  case 14: /* statement: ID OEQUALS expr SEMICOLON  */
#line 112 "minic.y"
                                      { (yyval.code) = cl_push_assign((yyvsp[-3].lex), (yyvsp[-1].code)); }
#line 1282 "minic.tab.c"
    break;

  case 15: /* statement: BRACKETL statement_list BRACKETR  */
#line 113 "minic.y"
                                             { (yyval.code) = (yyvsp[-1].code); }
#line 1288 "minic.tab.c"
    break;

  case 16: /* statement: RIF PARENL expr PARENR statement RELSE statement  */
#line 114 "minic.y"
                                                             { (yyval.code) = cl_push_if_else((yyvsp[-4].code), (yyvsp[-2].code), (yyvsp[0].code)); }
#line 1294 "minic.tab.c"
    break;

  case 17: /* statement: RIF PARENL expr PARENR statement  */
#line 115 "minic.y"
                                             { (yyval.code) = cl_push_if((yyvsp[-2].code), (yyvsp[0].code)); }
#line 1300 "minic.tab.c"
    break;

  case 18: /* statement: RWHILE PARENL expr PARENR statement  */
#line 116 "minic.y"
                                                { (yyval.code) = cl_push_while((yyvsp[-2].code), (yyvsp[0].code)); }
#line 1306 "minic.tab.c"
    break;

  case 19: /* statement: RPRINT PARENL print_list PARENR SEMICOLON  */
#line 117 "minic.y"
                                                      { (yyval.code) = (yyvsp[-2].code); }
#line 1312 "minic.tab.c"
    break;

  case 20: /* statement: RREAD PARENL read_list PARENR SEMICOLON  */
#line 118 "minic.y"
                                                    { (yyval.code) = (yyvsp[-2].code); }
#line 1318 "minic.tab.c"
    break;

  case 21: /* print_list: print_item  */
#line 121 "minic.y"
                        { (yyval.code) = (yyvsp[0].code); }
#line 1324 "minic.tab.c"
    break;

  case 22: /* print_list: print_list COMMA print_item  */
#line 122 "minic.y"
                                         { concatenaLC((yyvsp[-2].code), (yyvsp[0].code)); (yyval.code) = (yyvsp[-2].code); }
#line 1330 "minic.tab.c"
    break;

  case 23: /* print_item: expr  */
#line 125 "minic.y"
                  { (yyval.code) = cl_push_print_expr((yyvsp[0].code)); }
#line 1336 "minic.tab.c"
    break;

  case 24: /* print_item: LSTR  */
#line 126 "minic.y"
                  { (yyval.code) = cl_push_print_str((yyvsp[0].lex)); }
#line 1342 "minic.tab.c"
    break;

  case 25: /* read_list: ID  */
#line 129 "minic.y"
               { (yyval.code) = cl_push_read((yyvsp[0].lex)); }
#line 1348 "minic.tab.c"
    break;

  case 26: /* read_list: read_list COMMA ID  */
#line 130 "minic.y"
                               { concatenaLC((yyvsp[-2].code), cl_push_read((yyvsp[0].lex))); (yyval.code) = (yyvsp[-2].code); }
#line 1354 "minic.tab.c"
    break;

  case 27: /* expr: expr OPLUS expr  */
#line 133 "minic.y"
                       { (yyval.code) = cl_push_binop("add", (yyvsp[-2].code), (yyvsp[0].code)); }
#line 1360 "minic.tab.c"
    break;

  case 28: /* expr: expr OMINUS expr  */
#line 134 "minic.y"
                        { (yyval.code) = cl_push_binop("sub", (yyvsp[-2].code), (yyvsp[0].code)); }
#line 1366 "minic.tab.c"
    break;

  case 29: /* expr: expr OASTERISK expr  */
#line 135 "minic.y"
                           { (yyval.code) = cl_push_binop("mul", (yyvsp[-2].code), (yyvsp[0].code)); }
#line 1372 "minic.tab.c"
    break;

  case 30: /* expr: expr OSLASH expr  */
#line 136 "minic.y"
                        { (yyval.code) = cl_push_binop("div", (yyvsp[-2].code), (yyvsp[0].code)); }
#line 1378 "minic.tab.c"
    break;

  case 31: /* expr: PARENL expr QUESTIONMARK expr COLON expr PARENR  */
#line 137 "minic.y"
                                                       { (yyval.code) = cl_push_condop((yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code)); }
#line 1384 "minic.tab.c"
    break;

  case 32: /* expr: OMINUS expr  */
#line 138 "minic.y"
                   { (yyval.code) = cl_push_ominus_expr((yyvsp[0].code)); }
#line 1390 "minic.tab.c"
    break;

  case 33: /* expr: PARENL expr PARENR  */
#line 139 "minic.y"
                          { (yyval.code) = (yyvsp[-1].code); }
#line 1396 "minic.tab.c"
    break;

  case 34: /* expr: ID  */
#line 140 "minic.y"
          { (yyval.code) = cl_push_id((yyvsp[0].lex)); }
#line 1402 "minic.tab.c"
    break;

  case 35: /* expr: LINT  */
#line 141 "minic.y"
            { (yyval.code) = cl_push_lint((yyvsp[0].lex)); }
#line 1408 "minic.tab.c"
    break;


#line 1412 "minic.tab.c"

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

#line 146 "minic.y"



/* =================================== util ================================= */

void
yyerror()
{
    fprintf(stderr, "%d: syntax error at `%s'\n", yylineno, yytext);
}

void
print_code(ListaC code)
{
    printf("listing:\n========\n");
    PosicionListaC end = finalLC(code);
    for (PosicionListaC it = inicioLC(code); it != end; it = siguienteLC(code, it)) {
        Operacion op = recuperaLC(code, it);
        if (op.op[0] == '.' || op.op[strlen(op.op)-1] != ':')
            printf("\t");
        printf("%s", op.op);
        if (op.res)
            printf(" %s", op.res);
        if (op.arg1)
            printf(", %s", op.arg1);
        if (op.arg2)
            printf(", %s", op.arg2);
        printf("\n");
    }
    printf("\n");
} 

void
symtable_print() {
    PosicionLista end = finalLS(symtable);
    printf("symbol table:\nsymbol\n======\n");
    for (PosicionLista t = inicioLS(symtable); t != end; t = siguienteLS(symtable, t)) {
        Simbolo s = recuperaLS(symtable, t);
        printf("%s\n", s.nombre);
    }
    printf("\n");
}

const char*
alloc_reg()
{
    for (int i = 0; i < 10; i++) {
        if (regs[i] == 0) {
            regs[i] = 1;
            return reg_strs[i];
        }
    }

    printf("error: ran out of registers\n");
    return "";
}

void
free_reg(const char *reg)
{
    if (!reg)
        return;
    int i = (reg - (const char*)reg_strs) / sizeof(char*);
    regs[i] = 0;
}

char*
next_label()
{
    static char buff[32];
    snprintf(buff, 32, "$l%d", label_counter++);
    return strdup(buff);
}

char*
next_string_label()
{
    static char buff[32];
    snprintf(buff, 32, "$str%d", string_counter++);
    return strdup(buff);
}


char*
label_colon(const char *label)
{
    int len = strlen(label);
    char *labelc = malloc(len + 2);
    strcpy(labelc, label);
    labelc[len] = ':';
    labelc[len + 1] = '\0';
    return labelc;
}

/* =================================== main ================================= */

void
symtable_push(const char *id)
{
    if (buscaLS(symtable, id) == finalLS(symtable)) {
        insertaLS(symtable, finalLS(symtable), ((Simbolo){strdup(id), VARIABLE, 0}));
    }
    else
        fprintf(stderr, "%d: error: symbol `%s' redefined\n", yylineno, id);
}


void
setup_program()
{
    symtable = creaLS();
    dataseg = creaLC();
    
    Operacion op = { ".data" };
    insertaLC(dataseg, finalLC(dataseg), op);
}


void
ds_push_word(char *id)
{
    Operacion op = { label_colon(id) };
    insertaLC(dataseg, finalLC(dataseg), op);

    op = (Operacion){ ".word 0" };
    insertaLC(dataseg, finalLC(dataseg), op);
}

const char*
ds_push_asciiz(const char *lstr)
{
    const char *label = next_string_label();
    Operacion op = { label_colon(label) };
    insertaLC(dataseg, finalLC(dataseg), op);

    op = (Operacion){ ".asciiz", lstr };
    insertaLC(dataseg, finalLC(dataseg), op);

    return label;
}

void
cl_program(const char *id, ListaC decls, ListaC statements)
{
    symtable_print();
    liberaLS(symtable);

    ListaC textseg = creaLC();
    Operacion op = { ".text" };
    insertaLC(textseg, finalLC(textseg), op);
    concatenaLC(textseg, decls);
    concatenaLC(textseg, statements);

    ListaC program = creaLC();
    concatenaLC(program, dataseg);
    concatenaLC(program, textseg);

    print_code(program);
}

ListaC
cl_push_const_list(ListaC constl, const char *id, ListaC vl)
{
    concatenaLC(constl, vl);
    Operacion op = { "sw", recuperaResLC(vl), strdup(id) };
    insertaLC(constl, finalLC(constl), op);
    free_reg(recuperaResLC(vl));
    return constl;
}


ListaC
cl_push_read(const char *id)
{
    if (buscaLS(symtable, id) == finalLS(symtable))
        fprintf(stderr, "%d: error: undeclared symbol `%s'\n", yylineno, id);
    
    ListaC rl = creaLC();
    Operacion op = { "li", "$v0", "5" };
    insertaLC(rl, finalLC(rl), op);
    op = (Operacion){ "syscall" };
    insertaLC(rl, finalLC(rl), op);
    op = (Operacion){ "sw", "$v0", id };
    insertaLC(rl, finalLC(rl), op);

    return rl;
}

ListaC
cl_push_print_expr(ListaC exprl)
{
    Operacion op = { "li", "$v0", "1" };
    insertaLC(exprl, finalLC(exprl), op);
    op = (Operacion){ "move", "$a0", recuperaResLC(exprl) };
    insertaLC(exprl, finalLC(exprl), op);
    op = (Operacion){ "syscall" };
    insertaLC(exprl, finalLC(exprl), op);

    return exprl;
}

ListaC
cl_push_print_str(const char *lstr)
{
    const char *strlbl = ds_push_asciiz(lstr);
   
    ListaC pl = creaLC();   
    Operacion op = { "li", "$v0", "4" };
    insertaLC(pl, finalLC(pl), op);
    op = (Operacion){ "la", "$a0", strlbl };
    insertaLC(pl, finalLC(pl), op);
    op = (Operacion){ "syscall" };
    insertaLC(pl, finalLC(pl), op);

    return pl;
}

ListaC
cl_push_while(ListaC cond, ListaC statementl)
{
    const char *looplbl = next_label();
    const char *loopendlbl = next_label();

    ListaC ll = creaLC();
    // loop start label
    Operacion op = { label_colon(looplbl) };
    insertaLC(ll, finalLC(ll), op);
    // condition
    concatenaLC(ll, statementl);
    op = (Operacion){ "beqz", recuperaResLC(cond), loopendlbl };
    insertaLC(ll, finalLC(ll), op);
    // body
    concatenaLC(ll, statementl);
    // loop over
    op = (Operacion){ "j", looplbl };
    insertaLC(ll, finalLC(ll), op);
    // loop end label
    op = (Operacion){ label_colon(loopendlbl) };
    insertaLC(ll, finalLC(ll), op);

    return ll;
}

ListaC
cl_push_if(ListaC cond, ListaC ifl)
{
    ListaC res = creaLC();
    concatenaLC(res, cond);

    char *endiflabel = next_label();
    
    // continue to if or go to else
    Operacion op = { "beqz", recuperaResLC(cond), endiflabel };
    insertaLC(res, finalLC(res), op);
    // if block
    concatenaLC(res, ifl);
    // end label
    op = (Operacion){ label_colon(endiflabel) };
    insertaLC(res, finalLC(res), op);

    return res;
}

ListaC
cl_push_if_else(ListaC cond, ListaC ifl, ListaC elsel)
{
    ListaC res = creaLC();
    concatenaLC(res, cond);

    char *elselabel = next_label();
    char *endiflabel = next_label();
    
    // continue to if or go to else
    Operacion op = { "beqz", recuperaResLC(cond), endiflabel };
    insertaLC(res, finalLC(res), op);
    // if block
    concatenaLC(res, ifl);
    // prevent fall through
    op = (Operacion){ "j", endiflabel };
    insertaLC(res, finalLC(res), op);
    // else label
    op = (Operacion){ label_colon(elselabel) };
    insertaLC(res, finalLC(res), op);
    // else block
    concatenaLC(res, elsel);
    // end label
    op = (Operacion){ label_colon(endiflabel) };
    insertaLC(res, finalLC(res), op);

    return res;
}

ListaC
cl_push_assign(const char *id, ListaC l)
{
    Operacion op = { "sw", recuperaResLC(l), strdup(id) };
    insertaLC(l, finalLC(l), op);
    free_reg(recuperaResLC(l));
    return l; 
}

ListaC
cl_push_binop(const char *inst, ListaC ll, ListaC rl)
{
    ListaC res = creaLC();
    concatenaLC(res, ll);
    concatenaLC(res, rl);

    const char *reg = alloc_reg();

    Operacion op = { inst, reg, recuperaResLC(ll), recuperaResLC(rl) };
    insertaLC(res, finalLC(res), op);
    
    guardaResLC(res, reg);
    free_reg(recuperaResLC(ll));
    free_reg(recuperaResLC(rl));

    return res;
}

ListaC
cl_push_condop(ListaC cond, ListaC tl, ListaC fl)
{
    ListaC res = creaLC();
    concatenaLC(res, tl);
    concatenaLC(res, fl);
    concatenaLC(res, cond);

    const char *reg = alloc_reg();
    const char *falselabel = next_label();
    const char *endlabel = next_label();
    Operacion op = { "beqz", recuperaResLC(cond), falselabel };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ "move", reg, recuperaResLC(tl) };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ "j", endlabel };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ falselabel };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ "move", reg, recuperaResLC(fl) };
    insertaLC(res, finalLC(res), op);
    op = (Operacion){ endlabel };
    insertaLC(res, finalLC(res), op);

    guardaResLC(res, reg);

    free_reg(recuperaResLC(cond));
    free_reg(recuperaResLC(tl));
    free_reg(recuperaResLC(fl));

    return res;
}

ListaC
cl_push_ominus_expr(ListaC l)
{
    const char *reg = recuperaResLC(l);
    Operacion op = { "neg", reg, reg };
    insertaLC(l, finalLC(l), op);
    return l;
}

ListaC
cl_push_id(const char *id)
{
    ListaC l = creaLC();
    if (buscaLS(symtable, id) == finalLS(symtable))
        fprintf(stderr, "%d: error: undeclared symbol `%s'\n", yylineno, id);
    const char *reg = alloc_reg();
    Operacion op = { "lw", reg, strdup(id) };
    insertaLC(l, finalLC(l), op);
    guardaResLC(l, reg);
    return l;
}

ListaC
cl_push_lint(const char *lint)
{
    ListaC l = creaLC();
    const char *reg = alloc_reg();
    Operacion op = { "li", reg, strdup(lint) };
    insertaLC(l, finalLC(l), op);
    guardaResLC(l, reg);
    return l;
}

