/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

	// https://www.quut.com/c/ANSI-C-grammar-y.html
	extern void yyerror(const char*);
	extern int yychar;

	#include "string.h"
	#include "definitions.h"
	#include "string_functions.h"
	#include "linkedlists.h"
	#include "parameters.h"
	#include "scopes.h"
	#include "ascii_functions.h"
	#include "switch_functions.h"
	#include "typedef_functions.h"
	#include "enum_functions.h"
	#include "output_functions.h"
	#include "array_functions.h"
	#include "decl_functions.h"
	#include "if_functions.h"
	#include "iteration_functions.h"
	#include "structures.h"
	#include "conversion_functions.h"

#line 95 "grammar.tab.c"

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

#include "grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_I_CONSTANT = 4,                 /* I_CONSTANT  */
  YYSYMBOL_F_CONSTANT = 5,                 /* F_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_FUNC_NAME = 7,                  /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 8,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 9,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 10,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 11,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 12,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 13,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 14,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 15,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 16,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 17,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 18,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 19,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 22,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 23,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 24,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 25,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 26,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 27,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 28,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 29,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF_NAME = 30,              /* TYPEDEF_NAME  */
  YYSYMBOL_ENUMERATION_CONSTANT = 31,      /* ENUMERATION_CONSTANT  */
  YYSYMBOL_TYPEDEF = 32,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 33,                    /* EXTERN  */
  YYSYMBOL_STATIC = 34,                    /* STATIC  */
  YYSYMBOL_AUTO = 35,                      /* AUTO  */
  YYSYMBOL_REGISTER = 36,                  /* REGISTER  */
  YYSYMBOL_INLINE = 37,                    /* INLINE  */
  YYSYMBOL_CONST = 38,                     /* CONST  */
  YYSYMBOL_RESTRICT = 39,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 40,                  /* VOLATILE  */
  YYSYMBOL_BOOL = 41,                      /* BOOL  */
  YYSYMBOL_CHAR = 42,                      /* CHAR  */
  YYSYMBOL_SHORT = 43,                     /* SHORT  */
  YYSYMBOL_INT = 44,                       /* INT  */
  YYSYMBOL_LONG = 45,                      /* LONG  */
  YYSYMBOL_SIGNED = 46,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 47,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 48,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 49,                    /* DOUBLE  */
  YYSYMBOL_VOID = 50,                      /* VOID  */
  YYSYMBOL_COMPLEX = 51,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 52,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 53,                    /* STRUCT  */
  YYSYMBOL_UNION = 54,                     /* UNION  */
  YYSYMBOL_ENUM = 55,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 56,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 57,                      /* CASE  */
  YYSYMBOL_DEFAULT = 58,                   /* DEFAULT  */
  YYSYMBOL_IF = 59,                        /* IF  */
  YYSYMBOL_ELSE = 60,                      /* ELSE  */
  YYSYMBOL_SWITCH = 61,                    /* SWITCH  */
  YYSYMBOL_WHILE = 62,                     /* WHILE  */
  YYSYMBOL_DO = 63,                        /* DO  */
  YYSYMBOL_FOR = 64,                       /* FOR  */
  YYSYMBOL_GOTO = 65,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 66,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 67,                     /* BREAK  */
  YYSYMBOL_RETURN = 68,                    /* RETURN  */
  YYSYMBOL_ALIGNAS = 69,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 70,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 71,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 72,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 73,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 74,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 75,              /* THREAD_LOCAL  */
  YYSYMBOL_76_ = 76,                       /* '('  */
  YYSYMBOL_77_ = 77,                       /* ')'  */
  YYSYMBOL_78_ = 78,                       /* ','  */
  YYSYMBOL_79_ = 79,                       /* ':'  */
  YYSYMBOL_80_ = 80,                       /* '['  */
  YYSYMBOL_81_ = 81,                       /* ']'  */
  YYSYMBOL_82_ = 82,                       /* '.'  */
  YYSYMBOL_83_ = 83,                       /* '{'  */
  YYSYMBOL_84_ = 84,                       /* '}'  */
  YYSYMBOL_85_ = 85,                       /* '&'  */
  YYSYMBOL_86_ = 86,                       /* '*'  */
  YYSYMBOL_87_ = 87,                       /* '+'  */
  YYSYMBOL_88_ = 88,                       /* '-'  */
  YYSYMBOL_89_ = 89,                       /* '~'  */
  YYSYMBOL_90_ = 90,                       /* '!'  */
  YYSYMBOL_91_ = 91,                       /* '/'  */
  YYSYMBOL_92_ = 92,                       /* '%'  */
  YYSYMBOL_93_ = 93,                       /* '<'  */
  YYSYMBOL_94_ = 94,                       /* '>'  */
  YYSYMBOL_95_ = 95,                       /* '^'  */
  YYSYMBOL_96_ = 96,                       /* '|'  */
  YYSYMBOL_97_ = 97,                       /* '?'  */
  YYSYMBOL_98_ = 98,                       /* '='  */
  YYSYMBOL_99_ = 99,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 100,                 /* $accept  */
  YYSYMBOL_primary_expression = 101,       /* primary_expression  */
  YYSYMBOL_constant = 102,                 /* constant  */
  YYSYMBOL_enumeration_constant = 103,     /* enumeration_constant  */
  YYSYMBOL_string = 104,                   /* string  */
  YYSYMBOL_generic_selection = 105,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 106,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 107,      /* generic_association  */
  YYSYMBOL_postfix_expression = 108,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 109, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 110,         /* unary_expression  */
  YYSYMBOL_unary_operator = 111,           /* unary_operator  */
  YYSYMBOL_cast_expression = 112,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 113, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 114,      /* additive_expression  */
  YYSYMBOL_shift_expression = 115,         /* shift_expression  */
  YYSYMBOL_relational_expression = 116,    /* relational_expression  */
  YYSYMBOL_equality_expression = 117,      /* equality_expression  */
  YYSYMBOL_and_expression = 118,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 119,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 120,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 121,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 122,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 123,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 124,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 125,      /* assignment_operator  */
  YYSYMBOL_expression = 126,               /* expression  */
  YYSYMBOL_constant_expression = 127,      /* constant_expression  */
  YYSYMBOL_declaration = 128,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 129,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 130,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 131,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 132,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 133,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 134, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 135,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 136,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 137,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 138, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 139,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 140,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 141,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 142,          /* enumerator_list  */
  YYSYMBOL_enumerator = 143,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 144,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 145,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 146,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 147,      /* alignment_specifier  */
  YYSYMBOL_declarator = 148,               /* declarator  */
  YYSYMBOL_direct_declarator = 149,        /* direct_declarator  */
  YYSYMBOL_pointer = 150,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 151,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 152,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 153,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 154,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 155,          /* identifier_list  */
  YYSYMBOL_type_name = 156,                /* type_name  */
  YYSYMBOL_abstract_declarator = 157,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 158, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 159,              /* initializer  */
  YYSYMBOL_initializer_list = 160,         /* initializer_list  */
  YYSYMBOL_designation = 161,              /* designation  */
  YYSYMBOL_designator_list = 162,          /* designator_list  */
  YYSYMBOL_designator = 163,               /* designator  */
  YYSYMBOL_static_assert_declaration = 164, /* static_assert_declaration  */
  YYSYMBOL_statement = 165,                /* statement  */
  YYSYMBOL_labeled_statement = 166,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 167,       /* compound_statement  */
  YYSYMBOL_block_item_list = 168,          /* block_item_list  */
  YYSYMBOL_block_item = 169,               /* block_item  */
  YYSYMBOL_expression_statement = 170,     /* expression_statement  */
  YYSYMBOL_selection_statement = 171,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 172,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 173,           /* jump_statement  */
  YYSYMBOL_translation_unit = 174,         /* translation_unit  */
  YYSYMBOL_external_declaration = 175,     /* external_declaration  */
  YYSYMBOL_function_definition = 176,      /* function_definition  */
  YYSYMBOL_declaration_list = 177          /* declaration_list  */
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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  100
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  275
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  480

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


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
       2,     2,     2,    90,     2,     2,     2,    92,    85,     2,
      76,    77,    86,    87,    78,    88,    82,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    99,
      93,    98,    94,    97,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    80,     2,    81,    95,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    96,    84,    89,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   124,   124,   130,   137,   143,   151,   155,   161,   167,
     178,   187,   193,   202,   206,   207,   211,   212,   216,   222,
     242,   266,   292,   302,   317,   346,   359,   360,   364,   370,
     382,   388,   401,   413,   423,   440,   452,   456,   462,   467,
     473,   478,   483,   491,   509,   526,   532,   547,   556,   575,
     581,   590,   602,   608,   617,   629,   635,   644,   653,   662,
     675,   681,   690,   702,   708,   720,   726,   738,   744,   756,
     762,   776,   782,   796,   802,   827,   833,   848,   853,   858,
     863,   868,   873,   878,   883,   888,   893,   898,   906,   912,
     924,   933,   939,   954,   958,   966,   972,   994,  1000,  1006,
    1012,  1013,  1014,  1015,  1019,  1025,  1037,  1043,  1053,  1059,
    1064,  1069,  1070,  1075,  1083,  1088,  1093,  1098,  1103,  1108,
    1113,  1118,  1123,  1128,  1133,  1138,  1143,  1144,  1150,  1156,
    1166,  1175,  1199,  1222,  1227,  1235,  1241,  1253,  1254,  1280,
    1284,  1290,  1296,  1304,  1313,  1320,  1333,  1340,  1349,  1358,
    1371,  1372,  1402,  1403,  1415,  1421,  1434,  1459,  1483,  1487,
    1492,  1497,  1502,  1510,  1511,  1515,  1516,  1520,  1528,  1537,
    1543,  1551,  1559,  1568,  1569,  1570,  1571,  1572,  1573,  1574,
    1575,  1599,  1607,  1620,  1628,  1635,  1642,  1650,  1656,  1668,
    1676,  1688,  1694,  1705,  1720,  1728,  1737,  1743,  1755,  1763,
    1772,  1780,  1786,  1795,  1803,  1809,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1830,  1839,  1840,  1841,  1842,  1843,  1844,
    1845,  1851,  1859,  1867,  1880,  1888,  1898,  1907,  1916,  1922,
    1923,  1927,  1937,  1943,  1954,  1962,  1973,  1977,  1983,  1989,
    1995,  2001,  2007,  2016,  2024,  2031,  2040,  2047,  2064,  2070,
    2086,  2093,  2102,  2107,  2118,  2126,  2133,  2143,  2150,  2157,
    2165,  2174,  2175,  2179,  2187,  2192,  2197,  2202,  2213,  2219,
    2230,  2237,  2255,  2267,  2281,  2287
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "I_CONSTANT", "F_CONSTANT", "STRING_LITERAL", "FUNC_NAME", "SIZEOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF_NAME",
  "ENUMERATION_CONSTANT", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE", "BOOL", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID",
  "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "'('", "')'", "','", "':'",
  "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'",
  "$accept", "primary_expression", "constant", "enumeration_constant",
  "string", "generic_selection", "generic_assoc_list",
  "generic_association", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    40,    41,    44,    58,
      91,    93,    46,   123,   125,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    61,    59
};
#endif

#define YYPACT_NINF (-370)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2229,  -370,  -370,  -370,  -370,  -370,  -370,  -370,  -370,  -370,
    -370,  -370,  -370,  -370,  -370,  -370,  -370,  -370,  -370,  -370,
    -370,  -370,  -370,  -370,  -370,    26,   -43,   -35,  -370,    -8,
    -370,  -370,    28,  2319,  2319,  -370,    39,  -370,  -370,  2319,
    2319,  2319,  -370,  1816,  -370,  -370,   -56,    46,   901,  2428,
    1649,  -370,    45,   162,  -370,   -40,  -370,  1915,   -46,    79,
    -370,  -370,     2,  2357,  -370,  -370,  -370,  -370,  -370,    46,
    -370,   -45,    10,  -370,  -370,  -370,  -370,  -370,  -370,  1671,
    1693,  1693,  -370,    61,    71,   901,  -370,  -370,  -370,  -370,
    -370,  -370,  -370,  -370,  -370,  -370,   163,  -370,  1649,  -370,
     -67,   -30,   156,   125,   209,    92,    64,    65,   166,    20,
    -370,   121,  2428,   109,  2428,   128,   155,   160,   165,  -370,
    -370,  -370,   162,    45,  -370,   457,  1407,  -370,    28,  -370,
    2131,  1869,   989,   -46,  2357,  2031,  -370,    72,  -370,   104,
    1649,    29,  -370,   901,  -370,   901,  -370,  -370,  2428,  1649,
     450,  -370,  -370,   150,   169,   251,  -370,  -370,  1429,  1649,
     253,  -370,  1649,  1649,  1649,  1649,  1649,  1649,  1649,  1649,
    1649,  1649,  1649,  1649,  1649,  1649,  1649,  1649,  1649,  1649,
    1649,  -370,  -370,  1982,  1011,   -20,  -370,    74,  -370,  -370,
    -370,   259,  -370,  -370,  -370,  -370,   174,   195,  1649,   197,
     206,   220,   221,   721,   222,   282,   200,   202,   765,  -370,
    -370,    50,  -370,  -370,  -370,  -370,   578,  -370,  -370,  -370,
    -370,  -370,  1385,  -370,  -370,  -370,  -370,  -370,  -370,    76,
     227,   228,  -370,   157,  1253,  -370,   224,   226,  1033,  2078,
    -370,  -370,  1649,  -370,    66,  -370,   231,    32,  -370,  -370,
    -370,  -370,   234,   238,   242,   249,  -370,  -370,  -370,  -370,
    -370,  -370,  -370,  -370,  -370,  -370,  -370,  1649,  -370,  1649,
    1517,  -370,  -370,   159,  -370,   136,  -370,  -370,  -370,  -370,
     -67,   -67,   -30,   -30,   156,   156,   156,   156,   125,   125,
     209,    92,    64,    65,   166,   171,  -370,   256,   257,  1253,
    -370,   254,   258,  1121,    74,  2183,  1143,   260,   721,   261,
     721,  1649,  1649,  1649,   268,   668,   239,  -370,  -370,  -370,
      67,  -370,  -370,  -370,  1649,   340,  -370,   129,  1407,   101,
    -370,  1759,  -370,    77,  -370,  -370,  2275,  -370,   341,   264,
    1253,  -370,  -370,  1649,  -370,   265,   267,  -370,  -370,   117,
    -370,  1649,  -370,   266,   266,  -370,  2394,  -370,  -370,  1385,
    -370,  -370,  1649,  -370,  1649,  -370,  -370,   270,  1253,  -370,
    -370,  1649,  -370,   274,  -370,   279,  1253,  -370,   276,   277,
    1165,   262,  -370,   721,  -370,   175,   182,   184,   283,   811,
     811,  -370,  -370,   281,  -370,  1275,  -370,  -370,  -370,  -370,
    -370,  -370,  -370,  -370,   284,   285,  -370,  -370,  -370,  -370,
     289,   186,  -370,   290,   131,  -370,  -370,  -370,   291,   292,
    -370,  -370,   293,  1253,  -370,  -370,  1649,  -370,   295,  -370,
    -370,   721,   721,   721,  1649,  1539,  1561,  -370,  -370,  -370,
    1407,  -370,  -370,  1649,  -370,  2394,  1649,  1297,  -370,  -370,
    -370,  -370,   296,   297,  -370,   300,  -370,  -370,   190,   721,
     193,   721,   201,  -370,  -370,  -370,  -370,  -370,  -370,  -370,
     721,   271,  -370,   721,  -370,   721,  -370,  -370,  -370,  -370
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   129,   108,   109,   110,   112,   113,   163,   159,   160,
     161,   123,   115,   116,   117,   118,   121,   122,   119,   120,
     114,   124,   125,   133,   134,     0,     0,   162,   164,     0,
     111,   271,     0,    95,    97,   127,     0,   128,   126,    99,
     101,   103,    93,     0,   268,   270,   153,     0,     0,     0,
       0,   169,     0,   186,    91,     0,   104,   107,   168,     0,
      94,    96,   132,     0,    98,   100,   102,     1,   269,     0,
      10,   157,     0,   154,     2,     7,     8,    11,    12,     0,
       0,     0,     9,     0,     0,     0,    37,    38,    39,    40,
      41,    42,    18,     3,     4,     6,    30,    43,     0,    45,
      49,    52,    55,    60,    63,    65,    67,    69,    71,    73,
      90,     0,   141,   199,   143,     0,     0,     0,     0,   162,
     187,   185,   184,     0,    92,     0,     0,   274,     0,   273,
       0,     0,     0,   167,     0,     0,   135,     0,   139,     0,
       0,     0,   149,     0,    34,     0,    31,    32,     0,     0,
      43,    75,    88,     0,     0,     0,    24,    25,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   166,   140,     0,     0,   201,   198,   202,   142,   165,
     158,     0,   170,   188,   183,   105,   107,     2,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     252,     0,   250,   251,   237,   238,     0,   248,   239,   240,
     241,   242,     0,   226,   106,   275,   272,   196,   181,   195,
       0,   190,   191,     0,     0,   171,    38,     0,     0,     0,
     130,   136,     0,   137,     0,   144,   148,     0,   151,   156,
     150,   155,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    77,     0,     5,     0,
       0,    23,    20,     0,    28,     0,    22,    46,    47,    48,
      50,    51,    53,    54,    58,    59,    56,    57,    61,    62,
      64,    66,    68,    70,    72,     0,   220,     0,     0,     0,
     204,    38,     0,     0,   200,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   264,   265,   266,
       0,   253,   247,   249,     0,     0,   228,     0,     0,     0,
     232,     0,   193,   201,   194,   180,     0,   182,     0,     0,
       0,   172,   179,     0,   178,    38,     0,   131,   146,     0,
     138,     0,   152,    35,     0,    36,     0,    76,    89,     0,
      44,    21,     0,    19,     0,   221,   203,     0,     0,   205,
     211,     0,   210,     0,   222,     0,     0,   212,    38,     0,
       0,     0,   243,     0,   245,     0,     0,     0,     0,     0,
       0,   263,   267,     0,   235,     0,   224,   227,   231,   233,
     189,   192,   197,   174,     0,     0,   175,   177,   145,   147,
       0,     0,    14,     0,     0,    29,    74,   207,     0,     0,
     209,   223,     0,     0,   213,   219,     0,   218,     0,   236,
     244,     0,     0,     0,     0,     0,     0,   234,   225,   230,
       0,   173,   176,     0,    13,     0,     0,     0,    26,   206,
     208,   215,     0,     0,   216,   255,   256,   257,     0,     0,
       0,     0,     0,   229,    17,    15,    16,    27,   214,   217,
       0,     0,   261,     0,   259,     0,   254,   258,   262,   260
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -370,  -370,  -370,  -370,  -370,  -370,  -370,   -74,  -370,  -370,
     243,  -370,   -29,   122,   127,    52,   116,   188,   203,   205,
     207,   210,  -370,   -38,   -59,  -370,   -82,   -22,   -49,    11,
    -370,   263,  -370,   -42,  -370,  -370,   246,  -115,   -23,  -370,
      41,  -370,   322,  -124,  -370,   -48,  -370,  -370,   -18,   -50,
     -51,  -119,  -113,  -370,    56,  -370,    -2,   -91,  -169,  -122,
      34,  -369,  -370,    73,   -27,   -33,  -370,   -34,  -370,   178,
    -260,  -370,  -370,  -370,  -370,   352,  -370,  -370
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,    93,    71,    94,    95,   411,   412,    96,   273,
     150,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   151,   152,   267,   211,   111,    31,   128,
      55,    56,    33,    34,    35,    36,   135,   136,   113,   244,
     245,    37,    72,    73,    38,    39,    40,    41,   118,    58,
      59,   122,   297,   231,   232,   233,   413,   298,   187,   326,
     327,   328,   329,   330,    42,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    43,    44,    45,   130
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     114,   114,   121,   153,   224,   120,   112,   112,   127,   133,
     110,    32,   110,   238,    57,   114,   304,   251,   230,   162,
     241,   112,   186,   129,   163,   164,   440,    69,   117,    46,
     131,    51,    70,    48,   132,    70,   138,   114,   123,   179,
     137,    49,    62,   112,    60,    61,   115,   116,    51,    70,
      64,    65,    66,   140,    32,   390,   183,   165,   166,   124,
     184,   153,   185,   153,   114,   303,   114,   223,    50,   161,
     112,   194,   112,   237,   193,    51,   212,   275,   440,    51,
      51,   225,    51,   154,   120,   134,   114,   114,   141,   182,
     255,   188,   112,   112,   142,   114,   226,   114,   295,   274,
     114,   112,   110,   112,    52,   196,   112,   138,   138,    47,
     196,   137,   137,   250,    53,   340,   352,   180,   249,   246,
      51,    52,    63,   251,   241,   302,   320,    54,   269,   435,
     436,    53,   185,   277,   278,   279,   120,   148,   334,   169,
     170,   252,   229,   253,   349,   269,   254,   149,    52,   321,
     305,   242,   331,   331,   306,    52,   184,   184,    53,   176,
     110,   177,    53,   223,   304,   350,   392,   212,   167,   168,
     314,   243,   155,   156,   157,   339,   309,   175,   333,   346,
     368,   324,   247,   325,   178,   183,   120,   380,   248,   184,
     193,   114,   375,    52,   229,    53,   242,   112,   181,   398,
       8,     9,    10,    53,   110,   189,   397,   395,   357,   447,
     358,   332,   138,   396,   269,   448,   137,   363,   171,   172,
     348,   284,   285,   286,   287,   173,   174,   268,   269,   385,
     386,   387,   190,   119,   337,   338,   361,   362,   191,   158,
     367,   360,   192,   159,   373,   160,   270,   379,    53,   269,
     364,   120,   431,   269,   271,   193,   276,   423,   120,   432,
     269,   433,   269,   444,   445,   307,   389,   471,   269,   223,
     473,   269,   126,   439,   308,   382,   310,   384,   475,   269,
     333,   404,   311,   133,   405,   316,   110,   280,   281,   288,
     289,    97,   193,    97,   282,   283,   312,   313,   315,   317,
     223,   318,   393,   415,   335,   341,   336,   342,   114,   418,
     351,   353,   419,   110,   112,   354,   229,   422,   463,   355,
     193,   428,   144,   146,   147,   439,   416,   356,   120,   409,
     388,   246,   193,   365,   366,   369,   223,   381,   391,   370,
     383,    97,   229,   394,   402,   403,   406,   229,   407,   359,
     430,   417,   458,   460,   462,   420,   421,   424,   425,   434,
     470,   429,   437,   290,   452,   441,   442,   453,   443,   446,
     477,   465,   449,   450,   451,   193,   454,   468,   469,   291,
     239,   223,   292,    97,   464,   293,   195,   466,   223,   294,
     408,   139,   401,   414,   323,    68,     0,   114,   455,   456,
     457,     0,   399,   112,     0,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,     0,     0,     0,   472,     0,   474,     0,
       0,     0,     0,     0,     0,     0,     0,   476,     0,     0,
     478,    97,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,    75,    76,    77,    78,    79,     0,    80,    81,     0,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
       0,     0,     0,     0,     0,    97,     0,     1,    82,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    97,   198,   199,   200,     0,   201,   202,
     203,   204,   205,   206,   207,   208,    26,    83,    27,    84,
      28,    29,    30,    85,     0,     0,     0,     0,     0,     0,
     125,   209,    86,    87,    88,    89,    90,    91,   266,     0,
       0,     0,     0,     0,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,    75,    76,    77,    78,    79,     0,    80,    81,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     1,    82,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,   198,   199,   200,     0,   201,
     202,   203,   204,   205,   206,   207,   208,    26,    83,    27,
      84,    28,    29,    30,    85,     0,     0,     0,     0,     0,
       0,   125,   322,    86,    87,    88,    89,    90,    91,     0,
       0,    74,    75,    76,    77,    78,    79,   210,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    82,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   197,    75,    76,    77,    78,    79,
       0,    80,    81,     0,     0,     0,     0,    26,    83,    27,
      84,    28,    29,    30,    85,     0,     0,     0,     0,     0,
       0,     0,    82,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,     0,     0,     0,     0,   210,    74,    75,
      76,    77,    78,    79,     0,    80,    81,     0,   198,   199,
     200,     0,   201,   202,   203,   204,   205,   206,   207,   208,
       0,    83,     0,    84,     0,     0,    82,    85,     0,     0,
       0,     0,     0,     0,   125,     0,    86,    87,    88,    89,
      90,    91,     0,     0,    74,    75,    76,    77,    78,    79,
     210,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,    84,     0,     0,
       0,    85,    82,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,     0,   319,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,    84,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     0,     0,    74,    75,    76,    77,    78,    79,
     210,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,    82,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    27,    84,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      82,    80,    81,   234,     0,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    82,    80,    81,   299,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,    83,
     119,    84,     0,     0,    82,    85,     0,   343,     0,     0,
     235,     8,     9,    10,    86,   236,    88,    89,    90,    91,
       0,    83,   119,    84,     0,     0,     0,    85,     0,     0,
       0,     0,   300,     0,     0,     0,    86,   301,    88,    89,
      90,    91,     0,    83,   119,    84,     0,     0,     0,    85,
       0,     0,     0,     0,   344,     0,     0,     0,    86,   345,
      88,    89,    90,    91,    74,    75,    76,    77,    78,    79,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    82,    80,    81,   371,     0,     0,     0,     8,
       9,    10,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    82,    80,    81,   376,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,    83,   119,    84,     0,     0,    82,    85,     0,   426,
       0,     0,   372,     8,     9,    10,    86,    87,    88,    89,
      90,    91,     0,    83,   119,    84,     0,     0,     0,    85,
       0,     0,     0,     0,   377,     0,     0,     0,    86,   378,
      88,    89,    90,    91,     0,    83,   119,    84,     0,     0,
       0,    85,     0,     0,     0,     0,   427,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    74,    75,    76,    77,
      78,    79,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    82,    80,    81,     0,     0,     0,
       0,     8,     9,    10,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    82,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,   119,    84,     0,     0,    82,    85,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,     0,    83,     0,    84,     0,     0,
       0,    85,     0,     0,     0,   324,     0,   325,   222,   438,
      86,    87,    88,    89,    90,    91,     0,    83,     0,    84,
       0,     0,     0,    85,     0,     0,     0,   324,     0,   325,
     222,   467,    86,    87,    88,    89,    90,    91,    74,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    82,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    82,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    83,     0,    84,     0,     0,
      82,    85,     0,     0,     0,   324,     0,   325,   222,     0,
      86,    87,    88,    89,    90,    91,     0,    83,     0,    84,
       0,     0,     0,    85,     0,     0,     0,     0,     0,     0,
     222,     0,    86,    87,    88,    89,    90,    91,     0,    83,
       0,    84,     0,     0,     0,    85,   272,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      74,    75,    76,    77,    78,    79,     0,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    82,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      82,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,    84,
       0,     0,    82,    85,     0,     0,     0,     0,     0,     0,
     359,     0,    86,    87,    88,    89,    90,    91,     0,    83,
       0,    84,     0,     0,     0,    85,   459,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
       0,    83,     0,    84,     0,     0,     0,    85,   461,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      82,    80,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    82,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,    84,     0,     0,    82,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
       0,    83,     0,    84,     0,     0,     0,   143,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    51,    83,     0,    84,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,     0,     0,     0,     0,     0,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     0,    30,   331,   296,     0,     0,   184,
       0,     0,     0,     0,     0,    53,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,    27,     0,    28,
      29,    30,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,     0,    30,     1,   228,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   126,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,    28,     0,    30,   183,   296,
       0,     1,   184,     0,     0,     0,     0,     0,    53,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,    29,     0,     0,     1,     0,
       0,     0,     0,     0,     0,   240,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     1,   347,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,    27,     0,    28,    29,    30,     0,     0,     0,
       0,     0,     0,     1,   125,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    27,     0,    28,     0,    30,     1,
     374,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
      27,     0,    28,    29,    30,     1,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   400,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    27,     0,    28,     1,
      30,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,    26,     0,
      27,     0,    28,     0,    30,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,    27,     0,
       0,    29,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,   410,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,    27,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27
};

static const yytype_int16 yycheck[] =
{
      48,    49,    53,    85,   126,    53,    48,    49,    57,    59,
      48,     0,    50,   132,    32,    63,   185,   141,   131,    86,
     135,    63,   113,    57,    91,    92,   395,    83,    50,     3,
      76,     3,     3,    76,    80,     3,    63,    85,    78,    19,
      63,    76,     3,    85,    33,    34,    48,    49,     3,     3,
      39,    40,    41,    98,    43,   315,    76,    87,    88,    99,
      80,   143,   113,   145,   112,   184,   114,   126,    76,    98,
     112,   122,   114,   132,   122,     3,   125,   159,   447,     3,
       3,   130,     3,    85,   132,    83,   134,   135,    78,   112,
     149,   114,   134,   135,    84,   143,   130,   145,   180,   158,
     148,   143,   140,   145,    76,   123,   148,   134,   135,    83,
     128,   134,   135,    84,    86,   234,    84,    97,   140,   137,
       3,    76,    83,   247,   239,   184,   208,    99,    78,   389,
     390,    86,   183,   162,   163,   164,   184,    76,   229,    14,
      15,   143,   131,   145,    78,    78,   148,    76,    76,    99,
      76,    79,    76,    76,    80,    76,    80,    80,    86,    95,
     198,    96,    86,   222,   333,    99,    99,   216,    12,    13,
     203,    99,     9,    10,    11,   234,   198,    85,   229,   238,
     299,    80,    78,    82,    18,    76,   234,   306,    84,    80,
     238,   239,   305,    76,   183,    86,    79,   239,    77,    98,
      38,    39,    40,    86,   242,    77,   328,    78,   267,    78,
     269,   229,   239,    84,    78,    84,   239,    81,    93,    94,
     242,   169,   170,   171,   172,    16,    17,    77,    78,   311,
     312,   313,    77,    71,    77,    78,    77,    78,    78,    76,
     299,   270,    77,    80,   303,    82,    77,   306,    86,    78,
      79,   299,    77,    78,     3,   303,     3,   376,   306,    77,
      78,    77,    78,    77,    78,     6,   315,    77,    78,   328,
      77,    78,    98,   395,    79,   308,    79,   310,    77,    78,
     331,   340,    76,   333,   343,     3,   324,   165,   166,   173,
     174,    48,   340,    50,   167,   168,    76,    76,    76,    99,
     359,    99,   324,   362,    77,    81,    78,    81,   356,   368,
      79,    77,   371,   351,   356,    77,   305,   376,   440,    77,
     368,   380,    79,    80,    81,   447,   364,    78,   376,   351,
      62,   349,   380,    77,    77,    81,   395,    77,    99,    81,
      79,    98,   331,     3,     3,    81,    81,   336,    81,    83,
     383,    81,   434,   435,   436,    81,    77,    81,    81,    76,
      60,    99,    81,   175,   423,    81,    81,   426,    79,    79,
      99,   445,    81,    81,    81,   423,    81,    81,    81,   176,
     134,   440,   177,   140,   443,   178,   123,   446,   447,   179,
     349,    69,   336,   359,   216,    43,    -1,   445,   431,   432,
     433,    -1,   329,   445,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,    -1,    -1,    -1,   459,    -1,   461,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,
     473,   198,   475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,   242,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,   270,    57,    58,    59,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   364,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    -1,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      -1,     3,     4,     5,     6,     7,     8,    99,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    85,    86,    87,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    57,    58,
      59,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    -1,    72,    -1,    -1,    31,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      89,    90,    -1,    -1,     3,     4,     5,     6,     7,     8,
      99,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    -1,     3,     4,     5,     6,     7,     8,
      99,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      31,    10,    11,    34,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    31,    76,    -1,    34,    -1,    -1,
      81,    38,    39,    40,    85,    86,    87,    88,    89,    90,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    34,    -1,    -1,    -1,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    31,    10,    11,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    31,    76,    -1,    34,
      -1,    -1,    81,    38,    39,    40,    85,    86,    87,    88,
      89,    90,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    31,    10,    11,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    31,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    -1,    31,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    70,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    31,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    31,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    72,    -1,    -1,
      31,    76,    -1,    -1,    -1,    80,    -1,    82,    83,    -1,
      85,    86,    87,    88,    89,    90,    -1,    70,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    85,    86,    87,    88,    89,    90,    -1,    70,
      -1,    72,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    31,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    72,
      -1,    -1,    31,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    85,    86,    87,    88,    89,    90,    -1,    70,
      -1,    72,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      31,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    31,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    72,    -1,    -1,    31,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      -1,    70,    -1,    72,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,     3,    70,    -1,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,     0,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    76,    77,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    86,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    -1,    75,    30,    77,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    98,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    71,    -1,    73,    -1,    75,    76,    77,
      -1,    30,    80,    -1,    -1,    -1,    -1,    -1,    86,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    74,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    84,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    71,    -1,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    83,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    -1,    73,    -1,    75,    30,
      77,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      71,    -1,    73,    74,    75,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    71,    -1,    73,    30,
      75,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    69,    -1,
      71,    -1,    73,    -1,    75,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    71,    -1,
      -1,    74,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    69,    71,    73,    74,
      75,   128,   129,   132,   133,   134,   135,   141,   144,   145,
     146,   147,   164,   174,   175,   176,     3,    83,    76,    76,
      76,     3,    76,    86,    99,   130,   131,   148,   149,   150,
     129,   129,     3,    83,   129,   129,   129,     0,   175,    83,
       3,   103,   142,   143,     3,     4,     5,     6,     7,     8,
      10,    11,    31,    70,    72,    76,    85,    86,    87,    88,
      89,    90,   101,   102,   104,   105,   108,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   127,   133,   138,   145,   156,   156,   127,   148,    71,
     145,   150,   151,    78,    99,    83,    98,   128,   129,   167,
     177,    76,    80,   149,    83,   136,   137,   138,   164,   142,
      98,    78,    84,    76,   110,    76,   110,   110,    76,    76,
     110,   123,   124,   126,   156,     9,    10,    11,    76,    80,
      82,   112,    86,    91,    92,    87,    88,    12,    13,    14,
      15,    93,    94,    16,    17,    85,    95,    96,    18,    19,
      97,    77,   138,    76,    80,   150,   157,   158,   138,    77,
      77,    78,    77,   145,   150,   131,   148,     3,    57,    58,
      59,    61,    62,    63,    64,    65,    66,    67,    68,    84,
      99,   126,   128,   165,   166,   167,   168,   169,   170,   171,
     172,   173,    83,   124,   159,   128,   167,     3,    77,   129,
     152,   153,   154,   155,    34,    81,    86,   124,   151,   136,
      84,   137,    79,    99,   139,   140,   148,    78,    84,   127,
      84,   143,   156,   156,   156,   124,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    98,   125,    77,    78,
      77,     3,    77,   109,   124,   126,     3,   112,   112,   112,
     113,   113,   114,   114,   115,   115,   115,   115,   116,   116,
     117,   118,   119,   120,   121,   126,    77,   152,   157,    34,
      81,    86,   124,   151,   158,    76,    80,     6,    79,   127,
      79,    76,    76,    76,   165,    76,     3,    99,    99,    99,
     126,    99,    84,   169,    80,    82,   159,   160,   161,   162,
     163,    76,   148,   150,   157,    77,    78,    77,    78,   124,
     151,    81,    81,    34,    81,    86,   124,    84,   127,    78,
      99,    79,    84,    77,    77,    77,    78,   124,   124,    83,
     112,    77,    78,    81,    79,    77,    77,   124,   151,    81,
      81,    34,    81,   124,    77,   152,    34,    81,    86,   124,
     151,    77,   165,    79,   165,   126,   126,   126,    62,   128,
     170,    99,    99,   127,     3,    78,    84,   159,    98,   163,
      56,   154,     3,    81,   124,   124,    81,    81,   140,   127,
      58,   106,   107,   156,   160,   124,   123,    81,   124,   124,
      81,    77,   124,   151,    81,    81,    34,    81,   124,    99,
     165,    77,    77,    77,    76,   170,   170,    81,    84,   159,
     161,    81,    81,    79,    77,    78,    79,    78,    84,    81,
      81,    81,   124,   124,    81,   165,   165,   165,   126,    77,
     126,    77,   126,   159,   124,   107,   124,    84,    81,    81,
      60,    77,   165,    77,   165,    77,   165,    99,   165,   165
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   100,   101,   101,   101,   101,   101,   102,   102,   102,
     103,   104,   104,   105,   106,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   113,   113,   114,
     114,   114,   115,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   128,   128,   128,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   137,
     138,   138,   138,   138,   139,   139,   140,   140,   140,   141,
     141,   141,   141,   141,   142,   142,   143,   143,   144,   145,
     145,   145,   145,   146,   146,   147,   147,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   150,   150,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   154,   154,   155,   155,   156,   156,
     157,   157,   157,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   159,   159,   159,   160,   160,   160,
     160,   161,   162,   162,   163,   163,   164,   165,   165,   165,
     165,   165,   165,   166,   166,   166,   167,   167,   168,   168,
     169,   169,   170,   170,   171,   171,   171,   172,   172,   172,
     172,   172,   172,   173,   173,   173,   173,   173,   174,   174,
     175,   175,   176,   176,   177,   177
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     6,     1,     3,     3,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     6,     7,     1,     3,
       1,     2,     2,     2,     2,     4,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     2,     1,     1,     1,     2,     2,     3,     1,
       2,     1,     2,     1,     1,     3,     2,     3,     1,     4,
       5,     5,     6,     2,     1,     3,     3,     1,     4,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     1,     1,
       3,     3,     4,     6,     5,     5,     6,     5,     4,     4,
       4,     3,     4,     3,     2,     2,     1,     1,     2,     3,
       1,     1,     3,     2,     2,     1,     1,     3,     2,     1,
       2,     1,     1,     3,     2,     3,     5,     4,     5,     4,
       3,     3,     3,     4,     6,     5,     5,     6,     4,     4,
       2,     3,     3,     4,     3,     4,     1,     2,     1,     4,
       3,     2,     1,     2,     3,     2,     7,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     3,     1,     2,
       1,     1,     1,     2,     7,     5,     5,     5,     7,     6,
       7,     6,     7,     3,     2,     2,     2,     3,     1,     2,
       1,     1,     4,     3,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* primary_expression: IDENTIFIER  */
#line 125 "grammar.y"
        {
        (yyval.id) = (char*) malloc(STRING_LIMIT);
        strcpy((yyval.id), identifier_function((yyvsp[0].id))); // DECL_FUNCTIONS.H
        free((yyvsp[0].id));
	}
#line 2034 "grammar.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 131 "grammar.y"
        {
        (yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), ascii_function((yyvsp[0].id))); // ASCII_FUNCTIONS.H
		strcpy((yyval.id), check_number((yyvsp[0].id)));   // CONVERSION_FUNCTIONS.H
        free((yyvsp[0].id));
	}
#line 2045 "grammar.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 138 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)));
		strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2055 "grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 144 "grammar.y"
        {
        (yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
        strcat((yyval.id), (yyvsp[-1].id));
        strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 2067 "grammar.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 156 "grammar.y"
                {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2077 "grammar.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 162 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2087 "grammar.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 168 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2097 "grammar.tab.c"
    break;

  case 10: /* enumeration_constant: IDENTIFIER  */
#line 179 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2107 "grammar.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 188 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2117 "grammar.tab.c"
    break;

  case 12: /* string: FUNC_NAME  */
#line 194 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2127 "grammar.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 217 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2137 "grammar.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 223 "grammar.y"
        {
        (yyval.id) = (char*) malloc(STRING_LIMIT);
		if (strstr((yyvsp[-3].id), "[") != NULL)
		{
			strcpy((yyval.id), process_arrays((yyvsp[-3].id), (yyvsp[-1].id))); // ARRAY_FUNCTIONS.H
            free((yyvsp[-3].id));
            free((yyvsp[-1].id));
		}
		else
		{
			strcpy((yyval.id), (yyvsp[-3].id));
            strcat((yyval.id), "[");
            strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), "]");
            free((yyvsp[-3].id));
            free((yyvsp[-1].id));
		}

	}
#line 2161 "grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '(' ')'  */
#line 243 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process function calls (without arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		////////////////////////////////////////////////////////////////
		char *func_name;
		func_name = (char *) malloc(STRING_LIMIT);
		strcpy(func_name, copystring((yyvsp[-2].id), 3, strlen((yyvsp[-2].id))));
        (yyval.id) = (char*) malloc(16 + 3 + STRING_LIMIT + 3 + 1 + 1 + 1);
		strcpy((yyval.id), "\nfunction_call(");

		if (isupper(func_name[0]))
			strcat((yyval.id), "UC_");
		else
			strcat((yyval.id), "LC_");

		strcat((yyval.id), func_name);
		strcat((yyval.id), ", [");
		strcat((yyval.id), "]");
		strcat((yyval.id), ")");
        free((yyvsp[-2].id));
	}
#line 2189 "grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 267 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process function calls (with arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		////////////////////////////////////////////////////////////////
		char *func_name;
		func_name = (char *) malloc(STRING_LIMIT);
		strcpy(func_name, copystring((yyvsp[-3].id), 3, strlen((yyvsp[-3].id))-3));
        (yyval.id) = (char*) malloc(16+ 3 + STRING_LIMIT + 3 + strlen((yyvsp[-1].id)) + 1 + 1 + 1);
		strcpy((yyval.id), "\nfunction_call(");

		if (isupper(func_name[0]))
			strcat((yyval.id), "UC_");
		else
			strcat((yyval.id), "LC_");

		strcat((yyval.id), func_name);
		strcat((yyval.id), ", [");
        strcat((yyval.id), (yyvsp[-1].id));
        strcat((yyval.id), "]");
        strcat((yyval.id), ")");
        free((yyvsp[-3].id));
        free((yyvsp[-1].id));
	}
#line 2219 "grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 293 "grammar.y"
                {
		////////////////////////////////////////////////////////////////
		// Process records/structures
		////////////////////////////////////////////////////////////////
        (yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), process_records((yyvsp[-2].id), (yyvsp[0].id)));	// STRUCTURES.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2233 "grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 303 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process linked list statements
		////////////////////////////////////////////////////////////////
        (yyval.id) = (char*) malloc(11 + strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1 + 1);
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
        strcpy((yyval.id), "linkedlist(");
		strcat((yyval.id), (yyvsp[-2].id));
        strcat((yyval.id), ", ");
        strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), ")");
        free((yyvsp[-2].id));
        free((yyvsp[0].id));
	}
#line 2252 "grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression INC_OP  */
#line 318 "grammar.y"
                {
		////////////////////////////////////////////////////////////////
		// Process statements such as i++;
		////////////////////////////////////////////////////////////////
        (yyval.id) = (char*) malloc(25+(2*strlen((yyvsp[-1].id)))+1);
        // 17 + 1 + 3 + 1 + strlen($1)+3 = 25 + strlen($1)
        // 17 + strlen($1) + 3 + strlen($1) + 3 = 23 + 2*strlen($1)

		strcpy((yyval.id), "\npost_increment(");
		if ( (strstr((yyvsp[-1].id), "dereference") != NULL) && ((yyvsp[-1].id)[0] != '(') )
		{
			strcat((yyval.id), "(");
            strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), " , ");
			strcat((yyval.id), "(");
            strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), "+1)");
            free((yyvsp[-1].id));
		}
		else
		{
			strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), " , ");
            strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), "+1)");
            free((yyvsp[-1].id));
		}
	}
#line 2285 "grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression DEC_OP  */
#line 347 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process statements such as i--;
		////////////////////////////////////////////////////////////////
        (yyval.id) = (char*) malloc(17+strlen((yyvsp[-1].id))+3+strlen((yyvsp[-1].id))+3+1);
		strcpy((yyval.id), "\npost_decrement(");
        strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), " , ");
        strcat((yyval.id), (yyvsp[-1].id));
        strcat((yyval.id), "-1)");
        free((yyvsp[-1].id));
	}
#line 2302 "grammar.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 365 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2312 "grammar.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 371 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[-2].id));
        strcat((yyval.id), ",");
        strcat((yyval.id), (yyvsp[0].id));
        free((yyvsp[-2].id));
        free((yyvsp[0].id));
    }
#line 2325 "grammar.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 383 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2335 "grammar.tab.c"
    break;

  case 31: /* unary_expression: INC_OP unary_expression  */
#line 389 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process statements such as ++i;
		////////////////////////////////////////////////////////////////
        (yyval.id) = (char*) malloc(16 + strlen((yyvsp[0].id)) + 3 + strlen((yyvsp[0].id)) + 3 + 1);
		strcpy((yyval.id), "\npre_increment(");
        strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), "+1)");
        free((yyvsp[0].id));
	}
#line 2352 "grammar.tab.c"
    break;

  case 32: /* unary_expression: DEC_OP unary_expression  */
#line 402 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process statements such as --i;
		////////////////////////////////////////////////////////////////
        (yyval.id) = (char*) malloc(16 + strlen((yyvsp[0].id)) + 3 + strlen((yyvsp[0].id)) + 3 + 1);
		strcpy((yyval.id), "\npre_decrement(");
        strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), "-1)");
	}
#line 2368 "grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 414 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process casting expressions
		////////////////////////////////////////////////////////////////
        (yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), process_cast_unary_rule((yyvsp[-1].id), (yyvsp[0].id)));	// DECL_FUNCTIONS.H
        free((yyvsp[-1].id));
        free((yyvsp[0].id));
	}
#line 2382 "grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 424 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process sizeof statements
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(6+1+strlen((yyvsp[0].id))+1+1);
		strcpy((yyval.id), "sizeof");
		if ((yyvsp[0].id)[0] != '(')
		{
			strcat((yyval.id), "("); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")");
		}
		else
		{
			strcat((yyval.id), (yyvsp[0].id));
		}
		free((yyvsp[0].id));
	}
#line 2403 "grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 441 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process sizeof(type) statements
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(6 + 1 + STRING_LIMIT + 1 + 1);
		strcpy((yyval.id), "sizeof");
		strcat((yyval.id), "(");
		strcat((yyval.id), change_asterisk((yyvsp[-1].id))); 	// DECL_FUNCTIONS.H
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 2419 "grammar.tab.c"
    break;

  case 37: /* unary_operator: '&'  */
#line 457 "grammar.y"
        {
		(yyval.id) = (char*) malloc(10+1);
		strcpy((yyval.id), "address_of");

	}
#line 2429 "grammar.tab.c"
    break;

  case 38: /* unary_operator: '*'  */
#line 463 "grammar.y"
        {
		(yyval.id) = (char*) malloc(11+1);
		strcpy((yyval.id), "dereference");
	}
#line 2438 "grammar.tab.c"
    break;

  case 39: /* unary_operator: '+'  */
#line 468 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "+");

	}
#line 2448 "grammar.tab.c"
    break;

  case 40: /* unary_operator: '-'  */
#line 474 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "-");
	}
#line 2457 "grammar.tab.c"
    break;

  case 41: /* unary_operator: '~'  */
#line 479 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "~");
	}
#line 2466 "grammar.tab.c"
    break;

  case 42: /* unary_operator: '!'  */
#line 484 "grammar.y"
        {
		(yyval.id) = (char*) malloc(11+1);
		strcpy((yyval.id), "exclamation");
	}
#line 2475 "grammar.tab.c"
    break;

  case 43: /* cast_expression: unary_expression  */
#line 492 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Surround negative numbers with ( and )
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1 + 1);
		if ((yyvsp[0].id)[0] == '-')
		{
			strcpy((yyval.id), "(");
			strcat((yyval.id), (yyvsp[0].id));
			strcat((yyval.id), ")");
		}
		else
		{
			strcpy((yyval.id), (yyvsp[0].id));
		}
		free((yyvsp[0].id));
	}
#line 2497 "grammar.tab.c"
    break;

  case 44: /* cast_expression: '(' type_name ')' cast_expression  */
#line 510 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process cast expressions
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), "cast((");
		strcat((yyval.id), change_asterisk((yyvsp[-2].id))); // DECL_FUNCTIONS.H
		strcat((yyval.id), "), ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2515 "grammar.tab.c"
    break;

  case 45: /* multiplicative_expression: cast_expression  */
#line 527 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2525 "grammar.tab.c"
    break;

  case 46: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 533 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process * - change '*' to multiply to avoid confusion with
		// the pointer dereference '*'
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(9 + strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "multiply(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2544 "grammar.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 548 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "/");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2557 "grammar.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 557 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process % - change '%' to modulo to avoid confusion with
		// the Prolog comments operator '%'
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(4 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "mod(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2576 "grammar.tab.c"
    break;

  case 49: /* additive_expression: multiplicative_expression  */
#line 576 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2586 "grammar.tab.c"
    break;

  case 50: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 582 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "+");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2599 "grammar.tab.c"
    break;

  case 51: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 591 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "-");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2612 "grammar.tab.c"
    break;

  case 52: /* shift_expression: additive_expression  */
#line 603 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2622 "grammar.tab.c"
    break;

  case 53: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 609 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<<");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2635 "grammar.tab.c"
    break;

  case 54: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 618 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">>");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2648 "grammar.tab.c"
    break;

  case 55: /* relational_expression: shift_expression  */
#line 630 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2658 "grammar.tab.c"
    break;

  case 56: /* relational_expression: relational_expression '<' shift_expression  */
#line 636 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2671 "grammar.tab.c"
    break;

  case 57: /* relational_expression: relational_expression '>' shift_expression  */
#line 645 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2684 "grammar.tab.c"
    break;

  case 58: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 654 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<=");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2697 "grammar.tab.c"
    break;

  case 59: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 663 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">=");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2710 "grammar.tab.c"
    break;

  case 60: /* equality_expression: relational_expression  */
#line 676 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2720 "grammar.tab.c"
    break;

  case 61: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 682 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "==");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2733 "grammar.tab.c"
    break;

  case 62: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 691 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<>");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2746 "grammar.tab.c"
    break;

  case 63: /* and_expression: equality_expression  */
#line 703 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2756 "grammar.tab.c"
    break;

  case 64: /* and_expression: and_expression '&' equality_expression  */
#line 709 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "&");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2769 "grammar.tab.c"
    break;

  case 65: /* exclusive_or_expression: and_expression  */
#line 721 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2779 "grammar.tab.c"
    break;

  case 66: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 727 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "^");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2792 "grammar.tab.c"
    break;

  case 67: /* inclusive_or_expression: exclusive_or_expression  */
#line 739 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2802 "grammar.tab.c"
    break;

  case 68: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 745 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "|");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2815 "grammar.tab.c"
    break;

  case 69: /* logical_and_expression: inclusive_or_expression  */
#line 757 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2825 "grammar.tab.c"
    break;

  case 70: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 763 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "andop(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2840 "grammar.tab.c"
    break;

  case 71: /* logical_or_expression: logical_and_expression  */
#line 777 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2850 "grammar.tab.c"
    break;

  case 72: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 783 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "orop(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2865 "grammar.tab.c"
    break;

  case 73: /* conditional_expression: logical_or_expression  */
#line 797 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2875 "grammar.tab.c"
    break;

  case 74: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 803 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process ternary expressions from C to Prolog
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(8 + 11 + strlen((yyvsp[-4].id)) + 2 + 1 + strlen((yyvsp[-2].id)) + 1 + 2 + 1 + strlen((yyvsp[0].id)) + 1 + 1 + 1);
		strcpy((yyval.id), "ternary(");
		strcat((yyval.id), "expression(");
		strcat((yyval.id), (yyvsp[-4].id));
		strcat((yyval.id), "),");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "]");
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), "]");
		strcat((yyval.id), ")");
		free((yyvsp[-4].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2901 "grammar.tab.c"
    break;

  case 75: /* assignment_expression: conditional_expression  */
#line 828 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2911 "grammar.tab.c"
    break;

  case 76: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 834 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id))+ strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 2927 "grammar.tab.c"
    break;

  case 77: /* assignment_operator: '='  */
#line 849 "grammar.y"
        {
		(yyval.id) = (char*) malloc(13 + 1);
		strcpy((yyval.id), "\nassignment(");
	}
#line 2936 "grammar.tab.c"
    break;

  case 78: /* assignment_operator: MUL_ASSIGN  */
#line 854 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nmul_assignment(");
	}
#line 2945 "grammar.tab.c"
    break;

  case 79: /* assignment_operator: DIV_ASSIGN  */
#line 859 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\ndiv_assignment(");
	}
#line 2954 "grammar.tab.c"
    break;

  case 80: /* assignment_operator: MOD_ASSIGN  */
#line 864 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nmod_assignment(");
	}
#line 2963 "grammar.tab.c"
    break;

  case 81: /* assignment_operator: ADD_ASSIGN  */
#line 869 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nadd_assignment(");
	}
#line 2972 "grammar.tab.c"
    break;

  case 82: /* assignment_operator: SUB_ASSIGN  */
#line 874 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nsub_assignment(");
	}
#line 2981 "grammar.tab.c"
    break;

  case 83: /* assignment_operator: LEFT_ASSIGN  */
#line 879 "grammar.y"
        {
		(yyval.id) = (char*) malloc(18 + 1);
		strcpy((yyval.id), "\nleft_assignment(");
	}
#line 2990 "grammar.tab.c"
    break;

  case 84: /* assignment_operator: RIGHT_ASSIGN  */
#line 884 "grammar.y"
        {
		(yyval.id) = (char*) malloc(19 + 1);
		strcpy((yyval.id), "\nright_assignment(");
	}
#line 2999 "grammar.tab.c"
    break;

  case 85: /* assignment_operator: AND_ASSIGN  */
#line 889 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nand_assignment(");
	}
#line 3008 "grammar.tab.c"
    break;

  case 86: /* assignment_operator: XOR_ASSIGN  */
#line 894 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nxor_assignment(");
	}
#line 3017 "grammar.tab.c"
    break;

  case 87: /* assignment_operator: OR_ASSIGN  */
#line 899 "grammar.y"
        {
		(yyval.id) = (char*) malloc(16 + 1);
		strcpy((yyval.id), "\nor_assignment(");
	}
#line 3026 "grammar.tab.c"
    break;

  case 88: /* expression: assignment_expression  */
#line 907 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3036 "grammar.tab.c"
    break;

  case 89: /* expression: expression ',' assignment_expression  */
#line 913 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "comma(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
	}
#line 3049 "grammar.tab.c"
    break;

  case 90: /* constant_expression: conditional_expression  */
#line 925 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3059 "grammar.tab.c"
    break;

  case 91: /* declaration: declaration_specifiers ';'  */
#line 934 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), struct_declaration((yyvsp[-1].id)));	// STRUCTURES.H
		free((yyvsp[-1].id));
	}
#line 3069 "grammar.tab.c"
    break;

  case 92: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 940 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process declarations
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		int lenSS;
		strcpy((yyval.id), findvariabledetails((yyvsp[-2].id)));	// DECL_FUNCTIONS.H
		lenSS = strlen((yyval.id)) - 1;

		if ((yyval.id)[lenSS] != ',')
			strcat((yyval.id), ",");
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
	}
#line 3088 "grammar.tab.c"
    break;

  case 94: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 959 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3100 "grammar.tab.c"
    break;

  case 95: /* declaration_specifiers: storage_class_specifier  */
#line 967 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3110 "grammar.tab.c"
    break;

  case 96: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 973 "grammar.y"
{
		////////////////////////////////////////////////////////////////
		// Only append comma if not a type such as "unsigned int"
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 2 + strlen((yyvsp[0].id)) + 1);

		strcpy((yyval.id), (yyvsp[-1].id));
		if ( (strcmp((yyvsp[-1].id), "signed") == 0) || (strcmp((yyvsp[-1].id), "unsigned") == 0) )
		{
		}
		else if ((strcmp((yyvsp[-1].id), "short") == 0) && (strcmp((yyvsp[0].id), "int") == 0))
		{
		}
		else
		{
			strcat((yyval.id), ", ");
		}
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3136 "grammar.tab.c"
    break;

  case 97: /* declaration_specifiers: type_specifier  */
#line 995 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3146 "grammar.tab.c"
    break;

  case 98: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 1001 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
	}
#line 3156 "grammar.tab.c"
    break;

  case 99: /* declaration_specifiers: type_qualifier  */
#line 1007 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3166 "grammar.tab.c"
    break;

  case 104: /* init_declarator_list: init_declarator  */
#line 1020 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3176 "grammar.tab.c"
    break;

  case 105: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 1026 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3189 "grammar.tab.c"
    break;

  case 106: /* init_declarator: declarator '=' initializer  */
#line 1038 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		addvariabledetails((yyvsp[-2].id), (yyvsp[0].id));// DECL_FUNCTIONS.H
	}
#line 3199 "grammar.tab.c"
    break;

  case 107: /* init_declarator: declarator  */
#line 1044 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		addvariables((yyvsp[0].id), NO);	// DECL_FUNCTIONS.H
		free((yyvsp[0].id));
	}
#line 3210 "grammar.tab.c"
    break;

  case 108: /* storage_class_specifier: TYPEDEF  */
#line 1054 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "typedef");
		set_typedef_flag();	// TYPEDEF_FUNCTIONS.H
	}
#line 3220 "grammar.tab.c"
    break;

  case 109: /* storage_class_specifier: EXTERN  */
#line 1060 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 3229 "grammar.tab.c"
    break;

  case 110: /* storage_class_specifier: STATIC  */
#line 1065 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "Static_");
	}
#line 3238 "grammar.tab.c"
    break;

  case 112: /* storage_class_specifier: AUTO  */
#line 1071 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 3247 "grammar.tab.c"
    break;

  case 113: /* storage_class_specifier: REGISTER  */
#line 1076 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 3256 "grammar.tab.c"
    break;

  case 114: /* type_specifier: VOID  */
#line 1084 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "void");
	}
#line 3265 "grammar.tab.c"
    break;

  case 115: /* type_specifier: CHAR  */
#line 1089 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "char");
	}
#line 3274 "grammar.tab.c"
    break;

  case 116: /* type_specifier: SHORT  */
#line 1094 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6);
		strcpy((yyval.id), "short");
	}
#line 3283 "grammar.tab.c"
    break;

  case 117: /* type_specifier: INT  */
#line 1099 "grammar.y"
        {
		(yyval.id) = (char*) malloc(4);
		strcpy((yyval.id), "int");
	}
#line 3292 "grammar.tab.c"
    break;

  case 118: /* type_specifier: LONG  */
#line 1104 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "long");
	}
#line 3301 "grammar.tab.c"
    break;

  case 119: /* type_specifier: FLOAT  */
#line 1109 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(6);
		 strcpy((yyval.id), "float");
	}
#line 3310 "grammar.tab.c"
    break;

  case 120: /* type_specifier: DOUBLE  */
#line 1114 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7);
		strcpy((yyval.id), "double");
	}
#line 3319 "grammar.tab.c"
    break;

  case 121: /* type_specifier: SIGNED  */
#line 1119 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7);
		strcpy((yyval.id), "signed");
	}
#line 3328 "grammar.tab.c"
    break;

  case 122: /* type_specifier: UNSIGNED  */
#line 1124 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(9);
		 strcpy((yyval.id), "unsigned");
	}
#line 3337 "grammar.tab.c"
    break;

  case 123: /* type_specifier: BOOL  */
#line 1129 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(9);
		 strcpy((yyval.id), "bool");
	}
#line 3346 "grammar.tab.c"
    break;

  case 124: /* type_specifier: COMPLEX  */
#line 1134 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(9);
		 strcpy((yyval.id), "complex");
	}
#line 3355 "grammar.tab.c"
    break;

  case 125: /* type_specifier: IMAGINARY  */
#line 1139 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(9);
		 strcpy((yyval.id), "imaginary");
	}
#line 3364 "grammar.tab.c"
    break;

  case 127: /* type_specifier: struct_or_union_specifier  */
#line 1145 "grammar.y"
                {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3374 "grammar.tab.c"
    break;

  case 128: /* type_specifier: enum_specifier  */
#line 1151 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3384 "grammar.tab.c"
    break;

  case 129: /* type_specifier: TYPEDEF_NAME  */
#line 1157 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		add_typedefs(change_typedef((yyvsp[0].id)));// TYPEDEF_FUNCTIONS.H
		strcpy((yyval.id), change_typedef((yyvsp[0].id)));	 // TYPEDEF_FUNCTIONS.H
		free((yyvsp[0].id));
	}
#line 3395 "grammar.tab.c"
    break;

  case 130: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 1167 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 3 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), ", [");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 3408 "grammar.tab.c"
    break;

  case 131: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 1176 "grammar.y"
        {
		////////////////////////////////////////////////////
		// change the structure name.
		char * struct_name;
		struct_name = (char *) malloc(STRING_LIMIT);
		if (islower((yyvsp[-3].id)[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, (yyvsp[-3].id));

		////////////////////////////////////////////////////

		(yyval.id) = (char*) malloc(strlen((yyvsp[-4].id)) + 2 + strlen(struct_name) + 2 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-4].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), struct_name);
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 3436 "grammar.tab.c"
    break;

  case 132: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 1200 "grammar.y"
        {
		////////////////////////////////////////////////////
		// change the structure name.
		char * struct_name;
		struct_name = (char *) malloc(STRING_LIMIT);
		if (islower((yyvsp[0].id)[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, (yyvsp[0].id));

		////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 2 + strlen(struct_name) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), struct_name);
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3460 "grammar.tab.c"
    break;

  case 133: /* struct_or_union: STRUCT  */
#line 1223 "grammar.y"
        {
		(yyval.id) = (char*) malloc(8);
		strcpy((yyval.id), "struct ");
	}
#line 3469 "grammar.tab.c"
    break;

  case 134: /* struct_or_union: UNION  */
#line 1228 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7);
		strcpy((yyval.id), "union ");
	}
#line 3478 "grammar.tab.c"
    break;

  case 135: /* struct_declaration_list: struct_declaration  */
#line 1236 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3488 "grammar.tab.c"
    break;

  case 136: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 1242 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3501 "grammar.tab.c"
    break;

  case 138: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 1255 "grammar.y"
                {

		/////////////////////////////////////////////////////////////////
		// Many variables declared in $2, they must be separated.
		if (strstr((yyvsp[-1].id), ",") != NULL)
		{
			(yyval.id) = (char*) malloc(STRING_LIMIT + 1);
			strcpy((yyval.id), seperate_fields((yyvsp[-2].id), (yyvsp[-1].id))); // STRUCTURES.H
		}
		else
		/////////////////////////////////////////////////////////////////
		// Build the structure list, removing the 'struct' keyword if present
		{
			(yyval.id) = (char*) malloc(2 + strlen((yyvsp[-1].id)) + 3 + STRING_LIMIT + 1 + 1);
			strcpy((yyval.id), "([");
			strcat((yyval.id), (yyvsp[-1].id));
			strcat((yyval.id), "], ");
			strcpy((yyvsp[-2].id), strip_struct((yyvsp[-2].id)));// STRUCTURES.H
			strcat((yyval.id), (yyvsp[-2].id));
			strcat((yyval.id), ")");
		}
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
	}
#line 3530 "grammar.tab.c"
    break;

  case 140: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 1285 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
	}
#line 3540 "grammar.tab.c"
    break;

  case 141: /* specifier_qualifier_list: type_specifier  */
#line 1291 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3550 "grammar.tab.c"
    break;

  case 142: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 1297 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3562 "grammar.tab.c"
    break;

  case 143: /* specifier_qualifier_list: type_qualifier  */
#line 1305 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3572 "grammar.tab.c"
    break;

  case 144: /* struct_declarator_list: struct_declarator  */
#line 1314 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3583 "grammar.tab.c"
    break;

  case 145: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1321 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3597 "grammar.tab.c"
    break;

  case 146: /* struct_declarator: ':' constant_expression  */
#line 1334 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3608 "grammar.tab.c"
    break;

  case 147: /* struct_declarator: declarator ':' constant_expression  */
#line 1341 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3621 "grammar.tab.c"
    break;

  case 148: /* struct_declarator: declarator  */
#line 1350 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3631 "grammar.tab.c"
    break;

  case 149: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 1359 "grammar.y"
                { 	////////////////////////////////////////////////////////////////
		// Build enumeration list.
		// Pop Scope when '}' is parsed and reset enumerations counter
		(yyval.id) = (char*) malloc(7 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 			// SCOPES.H
		strcat((yyval.id), "]");
		reset_enumcounter(); 	// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
#line 3648 "grammar.tab.c"
    break;

  case 151: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 1373 "grammar.y"
        { 	////////////////////////////////////////////////////////////////
		// Build enumeration list.
		// Change their name to Prolog equivalent using change_enum()
		// Add the name to NAMES file using printnames()
		// Add the literal to Enum linked list using add_enums()
		// Pop Scope when '}' is parsed and reset enumerations counter

		char *enum_name;
		enum_name = (char *) malloc(STRING_LIMIT);
		strcpy(enum_name, change_enum((yyvsp[-3].id)));	// ENUM_FUNCTIONS.H

		(yyval.id) = (char*) malloc(7 + 1 + strlen(enum_name) + 1 + 2 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);

		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), "[");
		strcat((yyval.id), enum_name);
		strcat((yyval.id), "]");
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 					// SCOPES.H
		strcat((yyval.id), "]");
		reset_enumcounter(); 			// ENUM_FUNCTIONS.H

		free(enum_name);
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
		////////////////////////////////////////////////////////////////
	}
#line 3682 "grammar.tab.c"
    break;

  case 153: /* enum_specifier: ENUM IDENTIFIER  */
#line 1404 "grammar.y"
        { 	////////////////////////////////////////////////////////////////
		// Change enum name to Prolog equivalent using change_enum()
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), change_enum((yyvsp[0].id)));	// ENUM_FUNCTIONS.H
		free((yyvsp[0].id));
		////////////////////////////////////////////////////////////////
	}
#line 3695 "grammar.tab.c"
    break;

  case 154: /* enumerator_list: enumerator  */
#line 1416 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3705 "grammar.tab.c"
    break;

  case 155: /* enumerator_list: enumerator_list ',' enumerator  */
#line 1422 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3718 "grammar.tab.c"
    break;

  case 156: /* enumerator: enumeration_constant '=' constant_expression  */
#line 1435 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		/*
	 	Process enumeration literals with initializations:
		e.g. enum daYs {mon, tues, wed = 20, thurs, fri = 7};
		Change the enum name to Prolog equivalent using change_enum()
		Add the name to NAMES file using printnames()
		Add the literal to Enum linked list using add_enums(), with its enum value.
		*/
		////////////////////////////////////////////////////////////////
		char *enum_name;
		int i;
		enum_name = (char *) malloc(STRING_LIMIT);
		strcpy(enum_name, change_enum((yyvsp[-2].id)));	// ENUM_FUNCTIONS.H
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), enum_name);
		i = atoi((yyvsp[0].id));				// change string to integer
		add_enums((yyvsp[-2].id), i); 			// ENUM_FUNCTIONS.H

		free(enum_name);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
		////////////////////////////////////////////////////////////////
	}
#line 3747 "grammar.tab.c"
    break;

  case 157: /* enumerator: enumeration_constant  */
#line 1460 "grammar.y"
        { 	////////////////////////////////////////////////////////////////
		/*
		Process enumeration literals.
		Change their name to Prolog equivalent using change_enum()
		Add the name to NAMES file using printnames()
		Add the literal to Enum linked list using add_enums()
		*/
		////////////////////////////////////////////////////////////////
		char *enum_name;
		enum_name = (char *) malloc(STRING_LIMIT);
		strcpy(enum_name, change_enum((yyvsp[0].id)));	// ENUM_FUNCTIONS.H

		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), enum_name);
		add_enums((yyvsp[0].id), -1);			// ENUM_FUNCTIONS.H

		free(enum_name);
		free((yyvsp[0].id));
		////////////////////////////////////////////////////////////////
	}
#line 3772 "grammar.tab.c"
    break;

  case 159: /* type_qualifier: CONST  */
#line 1488 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6);
		strcpy((yyval.id), "const");
	}
#line 3781 "grammar.tab.c"
    break;

  case 160: /* type_qualifier: RESTRICT  */
#line 1493 "grammar.y"
        {
		(yyval.id) = (char*) malloc(9);
		strcpy((yyval.id), "restrict");
	}
#line 3790 "grammar.tab.c"
    break;

  case 161: /* type_qualifier: VOLATILE  */
#line 1498 "grammar.y"
        {
		(yyval.id) = (char*) malloc(9);
		strcpy((yyval.id), "volatile");
	}
#line 3799 "grammar.tab.c"
    break;

  case 162: /* type_qualifier: ATOMIC  */
#line 1503 "grammar.y"
        {
		(yyval.id) = (char*) malloc(9);
		strcpy((yyval.id), "atomic");
	}
#line 3808 "grammar.tab.c"
    break;

  case 167: /* declarator: pointer direct_declarator  */
#line 1521 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3820 "grammar.tab.c"
    break;

  case 168: /* declarator: direct_declarator  */
#line 1529 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3830 "grammar.tab.c"
    break;

  case 169: /* direct_declarator: IDENTIFIER  */
#line 1538 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3840 "grammar.tab.c"
    break;

  case 170: /* direct_declarator: '(' declarator ')'  */
#line 1544 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 3852 "grammar.tab.c"
    break;

  case 171: /* direct_declarator: direct_declarator '[' ']'  */
#line 1552 "grammar.y"
                {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "]");
		free((yyvsp[-2].id));
	}
#line 3864 "grammar.tab.c"
    break;

  case 172: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 1560 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
		free((yyvsp[-3].id));
	}
#line 3877 "grammar.tab.c"
    break;

  case 180: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 1576 "grammar.y"
                {
		////////////////////////////////////////////////////////////////
		/* 	function prototypes and definitions come through this rule.
			in order to distinguish them later on from variables we
			add the string "function_prototype" to $$
			if this is the function defintion this will have to be stripped later.
			if it is the function prototype it is left as it is.
		*/
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(19 + strlen((yyvsp[-3].id)) + 2 + 1 + strlen((yyvsp[-1].id)) + 1 + 2 + 2 + 1);

		(yyvsp[-3].id)[0] = convert_tolower((yyvsp[-3].id)[0]);
		strcpy((yyval.id), "function_prototype(");
		strcat((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "]");
		strcat((yyval.id), ", ");
		strcat((yyval.id), ").");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 3905 "grammar.tab.c"
    break;

  case 181: /* direct_declarator: direct_declarator '(' ')'  */
#line 1600 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
	}
#line 3917 "grammar.tab.c"
    break;

  case 182: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 1608 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 3931 "grammar.tab.c"
    break;

  case 183: /* pointer: '*' type_qualifier_list pointer  */
#line 1621 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
	}
#line 3943 "grammar.tab.c"
    break;

  case 184: /* pointer: '*' type_qualifier_list  */
#line 1629 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3954 "grammar.tab.c"
    break;

  case 185: /* pointer: '*' pointer  */
#line 1636 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3965 "grammar.tab.c"
    break;

  case 186: /* pointer: '*'  */
#line 1643 "grammar.y"
                {
		(yyval.id) = (char*) malloc(2);
		strcpy((yyval.id), "*");
	}
#line 3974 "grammar.tab.c"
    break;

  case 187: /* type_qualifier_list: type_qualifier  */
#line 1651 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3984 "grammar.tab.c"
    break;

  case 188: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1657 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3996 "grammar.tab.c"
    break;

  case 189: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1669 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 3 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), "...");
		free((yyvsp[-2].id));
	}
#line 4008 "grammar.tab.c"
    break;

  case 190: /* parameter_type_list: parameter_list  */
#line 1677 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		int lenSS = strlen((yyvsp[0].id)) - 1;
		if ((yyvsp[0].id)[lenSS] == ',')
			(yyvsp[0].id)[lenSS] = ' ';
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4021 "grammar.tab.c"
    break;

  case 191: /* parameter_list: parameter_declaration  */
#line 1689 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4031 "grammar.tab.c"
    break;

  case 192: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1695 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4043 "grammar.tab.c"
    break;

  case 193: /* parameter_declaration: declaration_specifiers declarator  */
#line 1706 "grammar.y"
        {
		if (PListFirstUse == NO)	// PARAMETERS.H
		{
			PListFirstUse = YES;	// PARAMETERS.H
			P = CreatePList();	// PARAMETERS.H
		}
		PushPList((yyvsp[0].id), P);		// PARAMETERS.H
		Push(yylineno);	// SCOPES.H
		addvariables((yyvsp[0].id), YES);			// DECL_FUNCTIONS.H
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), findvariabledetails((yyvsp[-1].id)));	// DECL_FUNCTIONS.H
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4062 "grammar.tab.c"
    break;

  case 194: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1721 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4074 "grammar.tab.c"
    break;

  case 195: /* parameter_declaration: declaration_specifiers  */
#line 1729 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4084 "grammar.tab.c"
    break;

  case 196: /* identifier_list: IDENTIFIER  */
#line 1738 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4094 "grammar.tab.c"
    break;

  case 197: /* identifier_list: identifier_list ',' IDENTIFIER  */
#line 1744 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4107 "grammar.tab.c"
    break;

  case 198: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 1756 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4119 "grammar.tab.c"
    break;

  case 199: /* type_name: specifier_qualifier_list  */
#line 1764 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4129 "grammar.tab.c"
    break;

  case 200: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 1773 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4141 "grammar.tab.c"
    break;

  case 201: /* abstract_declarator: pointer  */
#line 1781 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4151 "grammar.tab.c"
    break;

  case 202: /* abstract_declarator: direct_abstract_declarator  */
#line 1787 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4161 "grammar.tab.c"
    break;

  case 203: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 1796 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4173 "grammar.tab.c"
    break;

  case 204: /* direct_abstract_declarator: '[' ']'  */
#line 1804 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), "]");
	}
#line 4183 "grammar.tab.c"
    break;

  case 205: /* direct_abstract_declarator: '[' '*' ']'  */
#line 1810 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
	}
#line 4194 "grammar.tab.c"
    break;

  case 212: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 1823 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "]");
		free((yyvsp[-2].id));
	}
#line 4206 "grammar.tab.c"
    break;

  case 213: /* direct_abstract_declarator: direct_abstract_declarator '[' '*' ']'  */
#line 1831 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
		free((yyvsp[-3].id));
	}
#line 4219 "grammar.tab.c"
    break;

  case 220: /* direct_abstract_declarator: '(' ')'  */
#line 1846 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), ")");
	}
#line 4229 "grammar.tab.c"
    break;

  case 221: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 1852 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4241 "grammar.tab.c"
    break;

  case 222: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 1860 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
	}
#line 4253 "grammar.tab.c"
    break;

  case 223: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 1868 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4267 "grammar.tab.c"
    break;

  case 224: /* initializer: '{' initializer_list '}'  */
#line 1881 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 4279 "grammar.tab.c"
    break;

  case 225: /* initializer: '{' initializer_list ',' '}'  */
#line 1889 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), "{");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "}");
		free((yyvsp[-2].id));
	}
#line 4293 "grammar.tab.c"
    break;

  case 226: /* initializer: assignment_expression  */
#line 1899 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4303 "grammar.tab.c"
    break;

  case 227: /* initializer_list: designation initializer  */
#line 1908 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4316 "grammar.tab.c"
    break;

  case 228: /* initializer_list: initializer  */
#line 1917 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4326 "grammar.tab.c"
    break;

  case 231: /* designation: designator_list '='  */
#line 1928 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "=");
		free((yyvsp[-1].id));
	}
#line 4337 "grammar.tab.c"
    break;

  case 232: /* designator_list: designator  */
#line 1938 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4347 "grammar.tab.c"
    break;

  case 233: /* designator_list: designator_list designator  */
#line 1944 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4359 "grammar.tab.c"
    break;

  case 234: /* designator: '[' constant_expression ']'  */
#line 1955 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "]");
		free((yyvsp[-1].id));
	}
#line 4371 "grammar.tab.c"
    break;

  case 235: /* designator: '.' IDENTIFIER  */
#line 1963 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "access(");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[0].id));
	}
#line 4383 "grammar.tab.c"
    break;

  case 237: /* statement: labeled_statement  */
#line 1978 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4393 "grammar.tab.c"
    break;

  case 238: /* statement: compound_statement  */
#line 1984 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4403 "grammar.tab.c"
    break;

  case 239: /* statement: expression_statement  */
#line 1990 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4413 "grammar.tab.c"
    break;

  case 240: /* statement: selection_statement  */
#line 1996 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4423 "grammar.tab.c"
    break;

  case 241: /* statement: iteration_statement  */
#line 2002 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4433 "grammar.tab.c"
    break;

  case 242: /* statement: jump_statement  */
#line 2008 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4443 "grammar.tab.c"
    break;

  case 243: /* labeled_statement: IDENTIFIER ':' statement  */
#line 2017 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
	}
#line 4455 "grammar.tab.c"
    break;

  case 244: /* labeled_statement: CASE constant_expression ':' statement  */
#line 2025 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), case_statement((yyvsp[-2].id), (yyvsp[0].id)));	// SWITCH_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4466 "grammar.tab.c"
    break;

  case 245: /* labeled_statement: DEFAULT ':' statement  */
#line 2032 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), default_statement((yyvsp[0].id)));  	// SWITCH_FUNCTIONS.H
		free((yyvsp[0].id));
	}
#line 4476 "grammar.tab.c"
    break;

  case 246: /* compound_statement: '{' '}'  */
#line 2041 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "[");
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 4487 "grammar.tab.c"
    break;

  case 247: /* compound_statement: '{' block_item_list '}'  */
#line 2048 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop();  	// SCOPES.H

		int lenSS = strlen((yyval.id)) - 1;
		if ((yyval.id)[lenSS] == ',')
			(yyval.id)[lenSS] = ']';
		else
			strcat((yyval.id), "]");
		free((yyvsp[-1].id));
	}
#line 4505 "grammar.tab.c"
    break;

  case 248: /* block_item_list: block_item  */
#line 2065 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4515 "grammar.tab.c"
    break;

  case 249: /* block_item_list: block_item_list block_item  */
#line 2071 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));

		int lenSS = strlen((yyval.id)) - 1;
		if ((yyval.id)[lenSS] != ',')
			strcat((yyval.id), ",");

		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4532 "grammar.tab.c"
    break;

  case 250: /* block_item: declaration  */
#line 2087 "grammar.y"
        {

		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4543 "grammar.tab.c"
    break;

  case 251: /* block_item: statement  */
#line 2094 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4553 "grammar.tab.c"
    break;

  case 252: /* expression_statement: ';'  */
#line 2103 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "null");
	}
#line 4562 "grammar.tab.c"
    break;

  case 253: /* expression_statement: expression ';'  */
#line 2108 "grammar.y"
        {
		(yyval.id) = (char*) malloc(21 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "expression_statement(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4574 "grammar.tab.c"
    break;

  case 254: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 2119 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), ifelse_statement((yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id))); // IF_FUNCTIONS.H
		free((yyvsp[-4].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4586 "grammar.tab.c"
    break;

  case 255: /* selection_statement: IF '(' expression ')' statement  */
#line 2127 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), if_statement((yyvsp[-2].id), (yyvsp[0].id))); 	  // IF_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4597 "grammar.tab.c"
    break;

  case 256: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 2134 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), switch_statement((yyvsp[-2].id), (yyvsp[0].id)));	  // SWITCH_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4608 "grammar.tab.c"
    break;

  case 257: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 2144 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), while_statement((yyvsp[-2].id), (yyvsp[0].id)));	 // ITERATION_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4619 "grammar.tab.c"
    break;

  case 258: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 2151 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), do_statement((yyvsp[-5].id), (yyvsp[-2].id)));	 // ITERATION_FUNCTIONS.H
		free((yyvsp[-5].id));
		free((yyvsp[-2].id));
	}
#line 4630 "grammar.tab.c"
    break;

  case 259: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 2158 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), for2_statement((yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[0].id)));	 // ITERATION_FUNCTIONS.H
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4642 "grammar.tab.c"
    break;

  case 260: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 2166 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), for_statement((yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[0].id)));// ITERATION_FUNCTIONS.H
		free((yyvsp[-4].id));
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4655 "grammar.tab.c"
    break;

  case 263: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 2180 "grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "goto");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ";");
		free((yyvsp[-1].id));
	}
#line 4667 "grammar.tab.c"
    break;

  case 264: /* jump_statement: CONTINUE ';'  */
#line 2188 "grammar.y"
        {
		(yyval.id) = (char*) malloc(9);
		strcpy((yyval.id), "continue");
	}
#line 4676 "grammar.tab.c"
    break;

  case 265: /* jump_statement: BREAK ';'  */
#line 2193 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6);
		strcpy((yyval.id), "break");
	}
#line 4685 "grammar.tab.c"
    break;

  case 266: /* jump_statement: RETURN ';'  */
#line 2198 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7);
		strcpy((yyval.id), "return");
	}
#line 4694 "grammar.tab.c"
    break;

  case 267: /* jump_statement: RETURN expression ';'  */
#line 2203 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "return(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4706 "grammar.tab.c"
    break;

  case 268: /* translation_unit: external_declaration  */
#line 2214 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4716 "grammar.tab.c"
    break;

  case 269: /* translation_unit: translation_unit external_declaration  */
#line 2220 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4728 "grammar.tab.c"
    break;

  case 270: /* external_declaration: function_definition  */
#line 2231 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		printfunction((yyval.id)); 	// OUTPUT_FUNCTIONS.H
		free((yyvsp[0].id));
	}
#line 4739 "grammar.tab.c"
    break;

  case 271: /* external_declaration: declaration  */
#line 2238 "grammar.y"
        {	////////////////////////////////////////////////////////////////
		// Global Variable declarations
		////////////////////////////////////////////////////////////////
		int lenS1 = strlen((yyvsp[0].id)) - 1;
		(yyval.id) = (char*) malloc(20 + strlen((yyvsp[0].id)) + 11 + 1);
		strcpy((yyval.id), "\nglobal_variables([");
		if((yyvsp[0].id)[lenS1] == ',')
			(yyvsp[0].id)[lenS1] = ' ';

		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), "], void),\n");
		printfunction((yyval.id));	// OUTPUT_FUNCTIONS.H
		free((yyvsp[0].id));
	}
#line 4758 "grammar.tab.c"
    break;

  case 272: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 2256 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + strlen((yyvsp[-2].id)) + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4774 "grammar.tab.c"
    break;

  case 273: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 2268 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Function Defintions
		////////////////////////////////////////////////////////////////
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), process_functions((yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].id)));	// DECL_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4789 "grammar.tab.c"
    break;

  case 274: /* declaration_list: declaration  */
#line 2282 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4799 "grammar.tab.c"
    break;

  case 275: /* declaration_list: declaration_list declaration  */
#line 2288 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4811 "grammar.tab.c"
    break;


#line 4815 "grammar.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 2297 "grammar.y"

#include <stdio.h>
#include "lex.yy.c"
