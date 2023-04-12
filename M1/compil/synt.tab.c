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
#line 1 "synt.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
	#include "TS.c"

	int yylex();
	int yyerror(char*);

	int is_int(char*);
	int is_float(char*);
	int is_bool_type(char*);
	int is_numeric_type(char*);

	char* type_of(char*);
	char* format_string(char*, ...);
	char* get_bigger_numeric_type(char*, char*);

	void Afficher_Erreur_Semantique(char*);

	extern FILE* yyin;
	extern int col, nb_ligne;

#line 96 "synt.tab.c"

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

#include "synt.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_idf = 3,                        /* idf  */
  YYSYMBOL_mc_int = 4,                     /* mc_int  */
  YYSYMBOL_mc_float = 5,                   /* mc_float  */
  YYSYMBOL_mc_char = 6,                    /* mc_char  */
  YYSYMBOL_mc_bool = 7,                    /* mc_bool  */
  YYSYMBOL_mc_addition = 8,                /* mc_addition  */
  YYSYMBOL_mc_moins = 9,                   /* mc_moins  */
  YYSYMBOL_mc_division = 10,               /* mc_division  */
  YYSYMBOL_mc_multiplication = 11,         /* mc_multiplication  */
  YYSYMBOL_mc_Sup = 12,                    /* mc_Sup  */
  YYSYMBOL_mc_Inf = 13,                    /* mc_Inf  */
  YYSYMBOL_mc_SupE = 14,                   /* mc_SupE  */
  YYSYMBOL_mc_InfE = 15,                   /* mc_InfE  */
  YYSYMBOL_mc_Egal = 16,                   /* mc_Egal  */
  YYSYMBOL_mc_Diff = 17,                   /* mc_Diff  */
  YYSYMBOL_mc_if = 18,                     /* mc_if  */
  YYSYMBOL_mc_else = 19,                   /* mc_else  */
  YYSYMBOL_mc_ligne = 20,                  /* mc_ligne  */
  YYSYMBOL_mc_import = 21,                 /* mc_import  */
  YYSYMBOL_mc_numpy = 22,                  /* mc_numpy  */
  YYSYMBOL_mc_as = 23,                     /* mc_as  */
  YYSYMBOL_mc_matplotlibpyplot = 24,       /* mc_matplotlibpyplot  */
  YYSYMBOL_mc_zeros = 25,                  /* mc_zeros  */
  YYSYMBOL_mc_ones = 26,                   /* mc_ones  */
  YYSYMBOL_mc_arange = 27,                 /* mc_arange  */
  YYSYMBOL_mc_linspace = 28,               /* mc_linspace  */
  YYSYMBOL_mc_randint = 29,                /* mc_randint  */
  YYSYMBOL_mc_randn = 30,                  /* mc_randn  */
  YYSYMBOL_mc_dtype = 31,                  /* mc_dtype  */
  YYSYMBOL_mc_uint8 = 32,                  /* mc_uint8  */
  YYSYMBOL_mc_while = 33,                  /* mc_while  */
  YYSYMBOL_mc_for = 34,                    /* mc_for  */
  YYSYMBOL_mc_in = 35,                     /* mc_in  */
  YYSYMBOL_mc_range = 36,                  /* mc_range  */
  YYSYMBOL_mc_DPoint = 37,                 /* mc_DPoint  */
  YYSYMBOL_mc_point = 38,                  /* mc_point  */
  YYSYMBOL_Val_int = 39,                   /* Val_int  */
  YYSYMBOL_Val_float = 40,                 /* Val_float  */
  YYSYMBOL_Val_char = 41,                  /* Val_char  */
  YYSYMBOL_Val_bool = 42,                  /* Val_bool  */
  YYSYMBOL_mc_not = 43,                    /* mc_not  */
  YYSYMBOL_mc_and = 44,                    /* mc_and  */
  YYSYMBOL_mc_or = 45,                     /* mc_or  */
  YYSYMBOL_mc_parenthese_open = 46,        /* mc_parenthese_open  */
  YYSYMBOL_mc_parenthese_close = 47,       /* mc_parenthese_close  */
  YYSYMBOL_mc_bracket_open = 48,           /* mc_bracket_open  */
  YYSYMBOL_mc_bracket_close = 49,          /* mc_bracket_close  */
  YYSYMBOL_mc_affectation = 50,            /* mc_affectation  */
  YYSYMBOL_mc_Vergule = 51,                /* mc_Vergule  */
  YYSYMBOL_DEDENT = 52,                    /* DEDENT  */
  YYSYMBOL_INDENT = 53,                    /* INDENT  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_Main_Program = 55,              /* Main_Program  */
  YYSYMBOL_Instruction_List = 56,          /* Instruction_List  */
  YYSYMBOL_Block = 57,                     /* Block  */
  YYSYMBOL_Block_Start = 58,               /* Block_Start  */
  YYSYMBOL_Block_End = 59,                 /* Block_End  */
  YYSYMBOL_Instruction = 60,               /* Instruction  */
  YYSYMBOL_Importation = 61,               /* Importation  */
  YYSYMBOL_Declaration_Type = 62,          /* Declaration_Type  */
  YYSYMBOL_Type = 63,                      /* Type  */
  YYSYMBOL_Declaration_Liste = 64,         /* Declaration_Liste  */
  YYSYMBOL_Variable_Declaration = 65,      /* Variable_Declaration  */
  YYSYMBOL_Liste_Variable_Declaration = 66, /* Liste_Variable_Declaration  */
  YYSYMBOL_Assignment = 67,                /* Assignment  */
  YYSYMBOL_Assign_Variable = 68,           /* Assign_Variable  */
  YYSYMBOL_IF_Statement = 69,              /* IF_Statement  */
  YYSYMBOL_WHILE_Statement = 70,           /* WHILE_Statement  */
  YYSYMBOL_Conditions = 71,                /* Conditions  */
  YYSYMBOL_FOR_Statement = 72,             /* FOR_Statement  */
  YYSYMBOL_For_Array = 73,                 /* For_Array  */
  YYSYMBOL_FOR_InRange_Form = 74,          /* FOR_InRange_Form  */
  YYSYMBOL_FOR_KeyWord = 75,               /* FOR_KeyWord  */
  YYSYMBOL_FOR_Block = 76,                 /* FOR_Block  */
  YYSYMBOL_FOR_idf = 77,                   /* FOR_idf  */
  YYSYMBOL_Array_Reference = 78,           /* Array_Reference  */
  YYSYMBOL_Range_State = 79,               /* Range_State  */
  YYSYMBOL_Expression = 80,                /* Expression  */
  YYSYMBOL_DTYPE = 81,                     /* DTYPE  */
  YYSYMBOL_Variable_Value = 82,            /* Variable_Value  */
  YYSYMBOL_Variable = 83                   /* Variable  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   193

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    65,    66,    70,    73,    76,    79,    80,
      81,    82,    83,    84,    85,    87,    92,   100,   112,   113,
     114,   115,   119,   124,   130,   140,   142,   146,   162,   170,
     189,   190,   195,   200,   208,   209,   214,   224,   231,   234,
     238,   246,   259,   265,   270,   281,   291,   301,   311,   321,
     330,   340,   350,   360,   370,   381,   392,   402,   412,   415,
     418,   419,   422,   425,   428,   430,   433,   436,   439,   444,
     455
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
  "\"end of file\"", "error", "\"invalid token\"", "idf", "mc_int",
  "mc_float", "mc_char", "mc_bool", "mc_addition", "mc_moins",
  "mc_division", "mc_multiplication", "mc_Sup", "mc_Inf", "mc_SupE",
  "mc_InfE", "mc_Egal", "mc_Diff", "mc_if", "mc_else", "mc_ligne",
  "mc_import", "mc_numpy", "mc_as", "mc_matplotlibpyplot", "mc_zeros",
  "mc_ones", "mc_arange", "mc_linspace", "mc_randint", "mc_randn",
  "mc_dtype", "mc_uint8", "mc_while", "mc_for", "mc_in", "mc_range",
  "mc_DPoint", "mc_point", "Val_int", "Val_float", "Val_char", "Val_bool",
  "mc_not", "mc_and", "mc_or", "mc_parenthese_open", "mc_parenthese_close",
  "mc_bracket_open", "mc_bracket_close", "mc_affectation", "mc_Vergule",
  "DEDENT", "INDENT", "$accept", "Main_Program", "Instruction_List",
  "Block", "Block_Start", "Block_End", "Instruction", "Importation",
  "Declaration_Type", "Type", "Declaration_Liste", "Variable_Declaration",
  "Liste_Variable_Declaration", "Assignment", "Assign_Variable",
  "IF_Statement", "WHILE_Statement", "Conditions", "FOR_Statement",
  "For_Array", "FOR_InRange_Form", "FOR_KeyWord", "FOR_Block", "FOR_idf",
  "Array_Reference", "Range_State", "Expression", "DTYPE",
  "Variable_Value", "Variable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-85)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -85,    24,     7,   -85,   -15,   -85,   -85,   -85,   -85,   -12,
      23,     0,   -85,   -85,   -85,   -85,   -85,   -85,   -85,    50,
     -85,     6,   -85,   -85,   -85,    20,    21,    56,    22,    48,
      53,    54,    48,    -3,    14,   -85,    32,    48,    31,    31,
     -85,    51,    43,   -16,   -85,   -85,   -85,   -85,    48,    39,
      46,    97,   -85,   -85,   126,   127,    86,   -85,   -85,   104,
      50,   -85,    97,   -85,   -85,   -85,    16,   -85,   119,   106,
     123,   107,    87,   109,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,   -85,   -85,   114,    99,
     -85,     2,   -85,   108,   -85,   -85,   112,   103,   110,   -85,
     100,   105,   105,   111,   111,   -85,   -85,   -85,   -85,   -85,
     -85,   123,   123,   100,   -85,   -85,   120,   113,   -85,   -85,
     141,   -85,   -30,   124,   125,   -85,   128,   115,   100,    -8,
     129,   -85,   -85,   130,   116,   117,   121,   -85,   139,   131,
     132,   -85,   168,   135,   142,   -85
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    28,    18,    19,    20,    21,     0,
       0,     0,    38,     6,    14,     4,     3,     8,     9,     0,
      13,     0,    10,    11,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    17,    26,     0,     0,     0,
      40,     0,     0,    69,    63,    64,    67,    66,     0,     0,
       0,    33,    58,    62,     0,     0,     0,     7,     5,     0,
       0,    22,    27,     4,    34,    35,     0,    29,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,     0,     0,
      25,     0,    41,     0,    36,    37,     0,     0,     0,    68,
       0,    47,    48,    46,    45,    56,    57,    52,    53,    54,
      55,    49,    50,     0,    24,    39,     0,     0,    70,    65,
      30,    32,     0,     0,     0,    42,     0,     0,     0,     0,
       0,    31,    43,     0,     0,     0,    61,    44,     0,     0,
       0,    59,     0,     0,     0,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,    12,   -84,   -85,   -85,   -85,   -85,   -85,   -85,
     133,   -85,   -85,   -85,   -85,   -85,   -85,   143,   -85,   -85,
     -85,   -85,   137,   -85,   -85,   -85,   -11,   -85,   -85,   -85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    14,    15,    58,    16,    17,    18,    19,
      35,    36,    61,    20,    21,    22,    23,    50,    24,    25,
      26,    27,    64,    41,    94,    95,    51,   139,    52,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       4,     5,     6,     7,     8,     4,     5,     6,     7,     8,
       4,     5,     6,     7,     8,     9,   120,   125,    10,    92,
       9,   126,    68,    10,     3,     9,    62,    33,    10,   121,
      11,    12,    69,    28,    29,    11,    12,    70,    72,   132,
      11,    12,    43,   133,   131,    30,    32,    31,    71,    57,
      13,    43,    93,    34,   115,    13,    37,    38,    39,    40,
      13,    42,    59,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    91,    54,    55,    44,    45,
      46,    47,    48,    60,    63,    49,    66,    44,    45,    46,
      47,    48,    67,    73,    49,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    76,    77,    78,    79,    80,
      81,    82,    83,    78,    79,    80,    81,    82,    83,    86,
      87,    84,    85,    88,    99,    78,    79,    80,    81,    82,
      83,    84,    85,    89,    96,    97,   100,    98,   114,    84,
      85,   113,   118,    13,   116,    84,    85,   119,   117,   122,
     124,   123,   128,   127,   137,   136,   130,   129,   134,   135,
     140,   143,   138,   144,   145,    56,    65,     0,   141,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90
};

static const yytype_int16 yycheck[] =
{
       3,     4,     5,     6,     7,     3,     4,     5,     6,     7,
       3,     4,     5,     6,     7,    18,   100,    47,    21,     3,
      18,    51,    38,    21,     0,    18,    37,    15,    21,   113,
      33,    34,    48,    48,    46,    33,    34,    48,    49,    47,
      33,    34,     3,    51,   128,    22,    46,    24,     9,    52,
      53,     3,    36,     3,    52,    53,    50,    37,    37,     3,
      53,    39,    48,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    63,    23,    23,    39,    40,
      41,    42,    43,    51,    53,    46,    35,    39,    40,    41,
      42,    43,    49,    47,    46,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    10,    11,    12,    13,    14,
      15,    16,    17,    12,    13,    14,    15,    16,    17,     3,
       3,    44,    45,    47,    47,    12,    13,    14,    15,    16,
      17,    44,    45,    39,    25,    39,    37,    40,    49,    44,
      45,    37,    49,    53,    46,    44,    45,    47,    46,    39,
      19,    48,    37,    39,    47,    49,    51,    39,    39,    39,
      31,     3,    51,    38,    32,    32,    39,    -1,    47,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    55,    56,     0,     3,     4,     5,     6,     7,    18,
      21,    33,    34,    53,    57,    58,    60,    61,    62,    63,
      67,    68,    69,    70,    72,    73,    74,    75,    48,    46,
      22,    24,    46,    56,     3,    64,    65,    50,    37,    37,
       3,    77,    39,     3,    39,    40,    41,    42,    43,    46,
      71,    80,    82,    83,    23,    23,    71,    52,    59,    48,
      51,    66,    80,    53,    76,    76,    35,    49,    38,    48,
      80,     9,    80,    47,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    44,    45,     3,     3,    47,    39,
      64,    56,     3,    36,    78,    79,    25,    39,    40,    47,
      37,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    37,    49,    52,    46,    46,    49,    47,
      57,    57,    39,    48,    19,    47,    51,    39,    37,    39,
      51,    57,    47,    51,    39,    39,    49,    47,    51,    81,
      31,    47,    50,     3,    38,    32
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    58,    59,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    62,    63,    63,
      63,    63,    64,    65,    65,    66,    66,    67,    68,    68,
      69,    69,    70,    71,    72,    72,    73,    74,    75,    76,
      77,    78,    79,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      81,    81,    82,    82,    82,    82,    82,    82,    82,    83,
      83
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     1,     1,
       1,     1,     2,     1,     4,     2,     0,     3,     1,     4,
       6,     9,     6,     1,     3,     3,     4,     4,     1,     3,
       1,     1,     4,     6,     8,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     1,    11,
       6,     0,     1,     1,     1,     4,     1,     1,     3,     1,
       4
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
  case 6: /* Block_Start: INDENT  */
#line 73 "synt.y"
                    { create_new_scope(); }
#line 1278 "synt.tab.c"
    break;

  case 7: /* Block_End: DEDENT  */
#line 76 "synt.y"
                  { destroy_most_inner_scope(); }
#line 1284 "synt.tab.c"
    break;

  case 15: /* Importation: mc_import mc_numpy mc_as idf  */
#line 88 "synt.y"
                {
			if(!is_declared((yyvsp[0].str)))
			insert((yyvsp[0].str), "Bilbiotheque");
		}
#line 1293 "synt.tab.c"
    break;

  case 16: /* Importation: mc_import mc_matplotlibpyplot mc_as idf  */
#line 93 "synt.y"
                {
			if(!is_declared((yyvsp[0].str)))
			insert((yyvsp[0].str), "Bilbiotheque");
		}
#line 1302 "synt.tab.c"
    break;

  case 17: /* Declaration_Type: Type Declaration_Liste  */
#line 101 "synt.y"
                        {
				char *Variable = strtok((yyvsp[0].str), ",");

				while(Variable != NULL) {
					get(Variable)->type = (yyvsp[-1].str);
			
					Variable = strtok(NULL, ",");
				}
			}
#line 1316 "synt.tab.c"
    break;

  case 22: /* Declaration_Liste: Variable_Declaration Liste_Variable_Declaration  */
#line 120 "synt.y"
                    { (yyval.str) = format_string("%s,%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1322 "synt.tab.c"
    break;

  case 23: /* Variable_Declaration: idf  */
#line 125 "synt.y"
                {
				 insert((yyvsp[0].str), NULL);

				 (yyval.str) = (yyvsp[0].str); // Variable_Declaration = idf ( "Ab" )
			    }
#line 1332 "synt.tab.c"
    break;

  case 24: /* Variable_Declaration: idf mc_bracket_open Val_int mc_bracket_close  */
#line 131 "synt.y"
                            {
				
				 insert_array((yyvsp[-3].str), NULL, (yyvsp[-1].entier));

				 (yyval.str) = (yyvsp[-3].str);
			    }
#line 1343 "synt.tab.c"
    break;

  case 25: /* Liste_Variable_Declaration: mc_Vergule Declaration_Liste  */
#line 141 "synt.y"
                            { (yyval.str) = (yyvsp[0].str); }
#line 1349 "synt.tab.c"
    break;

  case 26: /* Liste_Variable_Declaration: %empty  */
#line 142 "synt.y"
                                     { (yyval.str) = ""; }
#line 1355 "synt.tab.c"
    break;

  case 27: /* Assignment: Assign_Variable mc_affectation Expression  */
#line 147 "synt.y"
                        {
				Identifier *target_Variable = get((yyvsp[-2].str));
				char *Expression_type = (yyvsp[0].str);

				if (target_Variable->type == NULL)
					target_Variable->type = Expression_type;

				else if (strcmp(target_Variable->type, Expression_type) != 0)
					Afficher_Erreur_Semantique(
						format_string("Impossible assigner type '%s' pour la Variable '%s' of type %s \n", Expression_type, target_Variable->name, target_Variable->type)
					);
			}
#line 1372 "synt.tab.c"
    break;

  case 28: /* Assign_Variable: idf  */
#line 163 "synt.y"
                        {
				if(!is_declared((yyvsp[0].str)))
					insert((yyvsp[0].str), NULL);
				
				(yyval.str) = (yyvsp[0].str);
			}
#line 1383 "synt.tab.c"
    break;

  case 29: /* Assign_Variable: idf mc_bracket_open Val_int mc_bracket_close  */
#line 171 "synt.y"
                        {
				Identifier *id = get((yyvsp[-3].str));
				int indice = (yyvsp[-1].entier);

				if(id == NULL) 
					Afficher_Erreur_Semantique(format_string("Variable '%s' n'est pas declarer \n", (yyvsp[-3].str)));
				
				if (!id->is_array)
					Afficher_Erreur_Semantique(format_string("Variable '%s' n'est pas un vecteur (Tableau) \n", id->name));
				
				if (indice >= id->array_size)
					Afficher_Erreur_Semantique(format_string("indice %d out hors tableau '%s' borne \n", indice, id->name));
				
				(yyval.str) = (yyvsp[-3].str);
			}
#line 1403 "synt.tab.c"
    break;

  case 33: /* Conditions: Expression  */
#line 201 "synt.y"
                        {
				if (!is_bool_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(format_string("La condition doivent être de type booléen mais obtenues d'autre type : '%s' \n", (yyvsp[0].str)));
			}
#line 1412 "synt.tab.c"
    break;

  case 36: /* For_Array: FOR_KeyWord FOR_idf mc_in Array_Reference  */
#line 215 "synt.y"
                        {
				Identifier *array = get((yyvsp[0].str));
				Identifier *iterator = get((yyvsp[-2].str));

				iterator->type = array->type;
			}
#line 1423 "synt.tab.c"
    break;

  case 37: /* FOR_InRange_Form: FOR_KeyWord FOR_idf mc_in Range_State  */
#line 225 "synt.y"
                        {
				Identifier *iterator = get((yyvsp[-2].str));
				iterator->type = "int";
			}
#line 1432 "synt.tab.c"
    break;

  case 38: /* FOR_KeyWord: mc_for  */
#line 231 "synt.y"
                    { create_new_scope(); }
#line 1438 "synt.tab.c"
    break;

  case 39: /* FOR_Block: INDENT Instruction_List DEDENT  */
#line 234 "synt.y"
                                          { destroy_most_inner_scope(); }
#line 1444 "synt.tab.c"
    break;

  case 40: /* FOR_idf: idf  */
#line 239 "synt.y"
                        {
				insert((yyvsp[0].str), NULL);
				(yyval.str) = (yyvsp[0].str);
			}
#line 1453 "synt.tab.c"
    break;

  case 41: /* Array_Reference: idf  */
#line 246 "synt.y"
                     {		
				        Identifier *id = get((yyvsp[0].str));

				        if (id == NULL) Afficher_Erreur_Semantique(format_string("Variable '%s' n'est pas declarer  \n", (yyvsp[0].str)));

				        if (!id->is_array) Afficher_Erreur_Semantique(format_string("Variable '%s' n'existe pas dans tableau  \n", (yyvsp[0].str)));
				
				        (yyval.str) = (yyvsp[0].str);
                     }
#line 1467 "synt.tab.c"
    break;

  case 42: /* Range_State: mc_range mc_parenthese_open Val_int mc_parenthese_close  */
#line 260 "synt.y"
                        {
				if ((yyvsp[-1].entier) <= 0)
					Afficher_Erreur_Semantique(format_string("Borne sup '%d' doit etre superieur a zero '%d'  \n", (yyvsp[-1].entier)));
			}
#line 1476 "synt.tab.c"
    break;

  case 43: /* Range_State: mc_range mc_parenthese_open Val_int mc_Vergule Val_int mc_parenthese_close  */
#line 266 "synt.y"
                        {
				if ((yyvsp[-3].entier) >= (yyvsp[-1].entier))
					Afficher_Erreur_Semantique(format_string("Borne inf '%d' obliger etre moins que la borne sup '%d'  \n", (yyvsp[-3].entier), (yyvsp[-1].entier)));
			}
#line 1485 "synt.tab.c"
    break;

  case 44: /* Range_State: mc_range mc_parenthese_open Val_int mc_Vergule Val_int mc_Vergule Val_int mc_parenthese_close  */
#line 271 "synt.y"
                        {
				if ((yyvsp[-5].entier) >= (yyvsp[-3].entier))
					Afficher_Erreur_Semantique(format_string("Borne inf '%d' obliger etre moins que la borne sup '%d'  \n", (yyvsp[-5].entier), (yyvsp[-3].entier)));
				
				if ((yyvsp[-1].entier) <= 0)
					Afficher_Erreur_Semantique(format_string("Le pas '%d' doit etre superieur a zero  \n", (yyvsp[-1].entier)));
			}
#line 1497 "synt.tab.c"
    break;

  case 45: /* Expression: Expression mc_multiplication Expression  */
#line 282 "synt.y"
                        {
				if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateurr '*' attendre avoir operateur type numerique (int, float) mais resultat : '%s * %s' \n", (yyvsp[-2].str), (yyvsp[0].str))
					);
				
				(yyval.str) = get_bigger_numeric_type((yyvsp[-2].str), (yyvsp[0].str));
			}
#line 1510 "synt.tab.c"
    break;

  case 46: /* Expression: Expression mc_division Expression  */
#line 292 "synt.y"
                        {
				if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur '/' attendre avoir operateur type numerique (int, float) mais resultat : %s / %s \n", (yyvsp[-2].str), (yyvsp[0].str))
					);
				
				(yyval.str) = get_bigger_numeric_type((yyvsp[-2].str), (yyvsp[0].str));
			}
#line 1523 "synt.tab.c"
    break;

  case 47: /* Expression: Expression mc_addition Expression  */
#line 302 "synt.y"
                        {
				if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur '+' attendre avoir operateur type numerique (int, float) mais resultat : %s + %s \n", (yyvsp[-2].str), (yyvsp[0].str))
					);
				
				(yyval.str) = get_bigger_numeric_type((yyvsp[-2].str), (yyvsp[0].str));
			}
#line 1536 "synt.tab.c"
    break;

  case 48: /* Expression: Expression mc_moins Expression  */
#line 312 "synt.y"
                        {
				if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur '-' attendre avoir operateur type numerique (int, float) mais resultat : %s - %s \n", (yyvsp[-2].str), (yyvsp[0].str))
					);
				
				(yyval.str) = get_bigger_numeric_type((yyvsp[-2].str), (yyvsp[0].str));
			}
#line 1549 "synt.tab.c"
    break;

  case 49: /* Expression: Expression mc_and Expression  */
#line 322 "synt.y"
                        {
				if (!is_bool_type((yyvsp[-2].str)) || !is_bool_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur 'and' attendre avoir operateur type boolean (true, false) mais resultat : %s and %s \n", (yyvsp[-2].str), (yyvsp[0].str))
					);

				(yyval.str) = "bool";
			}
#line 1562 "synt.tab.c"
    break;

  case 50: /* Expression: Expression mc_or Expression  */
#line 331 "synt.y"
                        {
				if (!is_bool_type((yyvsp[-2].str)) || !is_bool_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur 'or' attendre avoir operateur type boolean (true, false) mais resultat : %s or %s \n", (yyvsp[-2].str), (yyvsp[0].str))
					);

				(yyval.str) = "bool";
			}
#line 1575 "synt.tab.c"
    break;

  case 51: /* Expression: mc_not Expression  */
#line 341 "synt.y"
                        {
				if (!is_bool_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur 'not' attendre avoir operateur type boolean (true, false) mais resultat : not %s \n", (yyvsp[0].str))
					);

				(yyval.str) = "bool";
			}
#line 1588 "synt.tab.c"
    break;

  case 52: /* Expression: Expression mc_SupE Expression  */
#line 351 "synt.y"
                        {
				if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur '>=' attendre avoir operateur type boolean (true, false) mais resultat : %s >= %s \n", (yyvsp[-2].str), (yyvsp[0].str))
					);

				(yyval.str) = "bool";
			}
#line 1601 "synt.tab.c"
    break;

  case 53: /* Expression: Expression mc_InfE Expression  */
#line 361 "synt.y"
                        {
				if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur '<=' attendre avoir operateur type boolean (true, false) mais resultat : %s <= %s \n", (yyvsp[-2].str), (yyvsp[0].str))
					);

				(yyval.str) = "bool";
			}
#line 1614 "synt.tab.c"
    break;

  case 54: /* Expression: Expression mc_Egal Expression  */
#line 371 "synt.y"
                        {
				if (strcmp((yyvsp[-2].str), (yyvsp[0].str)) != 0)
					if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
						Afficher_Erreur_Semantique(
							format_string("Operateur '==' attendre avoir operateur de meme type (exp: int == int) mais resultat : %s == %s \n", (yyvsp[-2].str), (yyvsp[0].str))
						);

				(yyval.str) = "bool";
			}
#line 1628 "synt.tab.c"
    break;

  case 55: /* Expression: Expression mc_Diff Expression  */
#line 382 "synt.y"
                        {
				if (strcmp((yyvsp[-2].str), (yyvsp[0].str)) != 0)
					if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
						Afficher_Erreur_Semantique(
							format_string("Operateur '!=' attendre avoir operateur de meme type (exp: int != int) mais resultat : %s != %s \n", (yyvsp[-2].str), (yyvsp[0].str))
						);

				(yyval.str) = "bool";
			}
#line 1642 "synt.tab.c"
    break;

  case 56: /* Expression: Expression mc_Sup Expression  */
#line 393 "synt.y"
                        {
				if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur '>' attendre avoir operateur type numerique (int, float) mais resultat : %s > %s \n", (yyvsp[-2].str), (yyvsp[0].str))
					);

				(yyval.str) = "bool";
			}
#line 1655 "synt.tab.c"
    break;

  case 57: /* Expression: Expression mc_Inf Expression  */
#line 403 "synt.y"
                        {
				if (!is_numeric_type((yyvsp[-2].str)) || !is_numeric_type((yyvsp[0].str)))
					Afficher_Erreur_Semantique(
						format_string("Operateur '<' attendre avoir operateur type numerique (int, float) mais resultat : %s < %s \n", (yyvsp[-2].str), (yyvsp[0].str))
					);

				(yyval.str) = "bool";
			}
#line 1668 "synt.tab.c"
    break;

  case 58: /* Expression: Variable_Value  */
#line 413 "synt.y"
                        { (yyval.str) = type_of((yyvsp[0].str)); }
#line 1674 "synt.tab.c"
    break;

  case 59: /* Expression: idf mc_point mc_zeros mc_parenthese_open mc_bracket_open Val_int mc_Vergule Val_int mc_bracket_close DTYPE mc_parenthese_close  */
#line 416 "synt.y"
                        { (yyval.str) = "array"; }
#line 1680 "synt.tab.c"
    break;

  case 62: /* Variable_Value: Variable  */
#line 423 "synt.y"
                        { (yyval.str) = (yyvsp[0].str); }
#line 1686 "synt.tab.c"
    break;

  case 63: /* Variable_Value: Val_int  */
#line 426 "synt.y"
                        { (yyval.str) = format_string("%d", (yyvsp[0].entier)); }
#line 1692 "synt.tab.c"
    break;

  case 64: /* Variable_Value: Val_float  */
#line 429 "synt.y"
                        { (yyval.str) = format_string("%f", (yyvsp[0].reel)); }
#line 1698 "synt.tab.c"
    break;

  case 65: /* Variable_Value: mc_parenthese_open mc_moins Val_float mc_parenthese_close  */
#line 431 "synt.y"
                        { (yyval.str) = format_string("%s%f", (yyvsp[-2].str), (yyvsp[-1].reel)); }
#line 1704 "synt.tab.c"
    break;

  case 66: /* Variable_Value: Val_bool  */
#line 434 "synt.y"
                        { (yyval.str) = (yyvsp[0].str); }
#line 1710 "synt.tab.c"
    break;

  case 67: /* Variable_Value: Val_char  */
#line 437 "synt.y"
                        { (yyval.str) = format_string("'%c'", (yyvsp[0].str)); }
#line 1716 "synt.tab.c"
    break;

  case 68: /* Variable_Value: mc_parenthese_open Expression mc_parenthese_close  */
#line 440 "synt.y"
                        { (yyval.str) = (yyvsp[-1].str); }
#line 1722 "synt.tab.c"
    break;

  case 69: /* Variable: idf  */
#line 445 "synt.y"
                        {
				Identifier *id = get((yyvsp[0].str));
				
				if (id == NULL) Afficher_Erreur_Semantique(format_string("Variable '%s' est non declarer ! \n", (yyvsp[0].str)));
				
				if (id->is_array) Afficher_Erreur_Semantique(format_string("Variable '%s' c'est un tableau, tu peut seulement utilise la referance ! (nom de variable) \n", (yyvsp[0].str)));

				(yyval.str) = (yyvsp[0].str);
			}
#line 1736 "synt.tab.c"
    break;

  case 70: /* Variable: idf mc_bracket_open Val_int mc_bracket_close  */
#line 456 "synt.y"
                        {
				Identifier *id = get((yyvsp[-3].str));
				int indice = (yyvsp[-1].entier);

				if (id == NULL) 
					Afficher_Erreur_Semantique(format_string("Tableau %s non declarer ! \n", (yyvsp[-3].str)));
				
				if (!id->is_array)
					Afficher_Erreur_Semantique(format_string("Variable '%s' c'est pas un tableau \n", (yyvsp[-3].str)));
				
				if (indice >= id->array_size)
					Afficher_Erreur_Semantique(format_string("indice %d hors tableau %s borne ! \n", indice, id->name));
				
				(yyval.str) = (yyvsp[-3].str);
			}
#line 1756 "synt.tab.c"
    break;


#line 1760 "synt.tab.c"

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

#line 472 "synt.y"


int yyerror(char* msg) 
{
	printf("Erruer Syntaxique: %s, Ligne : %d , colonne : %d, entite lexicale (%s) \n", msg, nb_ligne, col, yylval.str);

	return 1;
}

void Afficher_Erreur_Semantique(char* message)
{
	printf("Erruer Semantique: %s\nLigne => %d\ncolumn => %d \n", message, nb_ligne, col);

	exit(1);
}


char *format_string(char* format, ...) 
{
	va_list args;
	va_start(args, format);

	char* str = (char*) malloc(100);
	vsprintf(str, format, args);

	va_end(args);

	return str;
}

char *type_of(char* str)
{
	if (strcmp(str, "true") == 0 || strcmp(str, "false") == 0)
		return "bool";

	if (str[0] == '\'' && str[2] == '\'')
		return "char";

	if (str[0] == '-' && is_int(str) || is_int(str))
		return "int";

	if (str[0] == '-' && is_float(str) || is_float(str))
		return "float";

	return get(str)->type;
}

int is_numeric_type(char* str)
{
	return strcmp(str, "int") == 0 || strcmp(str, "float") == 0;
}

int is_bool_type(char* str)
{
	return strcmp(str, "bool") == 0;
}

int is_float(char *str) 
{
    char *endptr;

    strtod(str, &endptr);

    if (endptr == str || *endptr != '\0')
        return 0;
    
    return 1;
}

int is_int(char *str)
{
	char *endptr;

    strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
        return 0;
    
    return 1;
}

char *get_bigger_numeric_type(char* type1, char* type2)
{
	if (strcmp(type1, "float") == 0 || strcmp(type2, "float") == 0)
		return "float";

	return "int";
}

int main (int argc, char** argv) 
{ 	
	yyin = fopen("in.minipy", "r");

	create_new_scope();
    display();
	yyparse();

	display();
	fclose (yyin);

	return 0;
}
