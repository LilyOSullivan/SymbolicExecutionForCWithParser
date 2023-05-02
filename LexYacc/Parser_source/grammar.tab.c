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
  YYSYMBOL___INT8 = 51,                    /* __INT8  */
  YYSYMBOL___INT16 = 52,                   /* __INT16  */
  YYSYMBOL___INT32 = 53,                   /* __INT32  */
  YYSYMBOL___INT64 = 54,                   /* __INT64  */
  YYSYMBOL_COMPLEX = 55,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 56,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 57,                    /* STRUCT  */
  YYSYMBOL_UNION = 58,                     /* UNION  */
  YYSYMBOL_ENUM = 59,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 60,                  /* ELLIPSIS  */
  YYSYMBOL_DECLSPEC = 61,                  /* DECLSPEC  */
  YYSYMBOL_CASE = 62,                      /* CASE  */
  YYSYMBOL_DEFAULT = 63,                   /* DEFAULT  */
  YYSYMBOL_IF = 64,                        /* IF  */
  YYSYMBOL_ELSE = 65,                      /* ELSE  */
  YYSYMBOL_SWITCH = 66,                    /* SWITCH  */
  YYSYMBOL_WHILE = 67,                     /* WHILE  */
  YYSYMBOL_DO = 68,                        /* DO  */
  YYSYMBOL_FOR = 69,                       /* FOR  */
  YYSYMBOL_GOTO = 70,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 71,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 72,                     /* BREAK  */
  YYSYMBOL_RETURN = 73,                    /* RETURN  */
  YYSYMBOL_ALIGNAS = 74,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 75,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 76,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 77,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 78,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 79,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 80,              /* THREAD_LOCAL  */
  YYSYMBOL___CDECL = 81,                   /* __CDECL  */
  YYSYMBOL___CLRCALL = 82,                 /* __CLRCALL  */
  YYSYMBOL___STDCALL = 83,                 /* __STDCALL  */
  YYSYMBOL___FASTCALL = 84,                /* __FASTCALL  */
  YYSYMBOL___THISCALL = 85,                /* __THISCALL  */
  YYSYMBOL___VECTORCALL = 86,              /* __VECTORCALL  */
  YYSYMBOL_87_ = 87,                       /* '('  */
  YYSYMBOL_88_ = 88,                       /* ')'  */
  YYSYMBOL_89_ = 89,                       /* ','  */
  YYSYMBOL_90_ = 90,                       /* ':'  */
  YYSYMBOL_91_ = 91,                       /* '['  */
  YYSYMBOL_92_ = 92,                       /* ']'  */
  YYSYMBOL_93_ = 93,                       /* '.'  */
  YYSYMBOL_94_ = 94,                       /* '{'  */
  YYSYMBOL_95_ = 95,                       /* '}'  */
  YYSYMBOL_96_ = 96,                       /* '&'  */
  YYSYMBOL_97_ = 97,                       /* '*'  */
  YYSYMBOL_98_ = 98,                       /* '+'  */
  YYSYMBOL_99_ = 99,                       /* '-'  */
  YYSYMBOL_100_ = 100,                     /* '~'  */
  YYSYMBOL_101_ = 101,                     /* '!'  */
  YYSYMBOL_102_ = 102,                     /* '/'  */
  YYSYMBOL_103_ = 103,                     /* '%'  */
  YYSYMBOL_104_ = 104,                     /* '<'  */
  YYSYMBOL_105_ = 105,                     /* '>'  */
  YYSYMBOL_106_ = 106,                     /* '^'  */
  YYSYMBOL_107_ = 107,                     /* '|'  */
  YYSYMBOL_108_ = 108,                     /* '?'  */
  YYSYMBOL_109_ = 109,                     /* '='  */
  YYSYMBOL_110_ = 110,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 111,                 /* $accept  */
  YYSYMBOL_primary_expression = 112,       /* primary_expression  */
  YYSYMBOL_constant = 113,                 /* constant  */
  YYSYMBOL_enumeration_constant = 114,     /* enumeration_constant  */
  YYSYMBOL_string = 115,                   /* string  */
  YYSYMBOL_generic_selection = 116,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 117,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 118,      /* generic_association  */
  YYSYMBOL_postfix_expression = 119,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 120, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 121,         /* unary_expression  */
  YYSYMBOL_unary_operator = 122,           /* unary_operator  */
  YYSYMBOL_cast_expression = 123,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 124, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 125,      /* additive_expression  */
  YYSYMBOL_shift_expression = 126,         /* shift_expression  */
  YYSYMBOL_relational_expression = 127,    /* relational_expression  */
  YYSYMBOL_equality_expression = 128,      /* equality_expression  */
  YYSYMBOL_and_expression = 129,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 130,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 131,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 132,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 133,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 134,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 135,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 136,      /* assignment_operator  */
  YYSYMBOL_expression = 137,               /* expression  */
  YYSYMBOL_constant_expression = 138,      /* constant_expression  */
  YYSYMBOL_declaration = 139,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 140,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 141,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 142,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 143,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 144,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 145, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 146,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 147,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 148,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 149, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 150,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 151,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 152,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 153,          /* enumerator_list  */
  YYSYMBOL_enumerator = 154,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 155,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 156,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 157,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 158,      /* alignment_specifier  */
  YYSYMBOL_declarator = 159,               /* declarator  */
  YYSYMBOL_direct_declarator = 160,        /* direct_declarator  */
  YYSYMBOL_vc_specific_modifier = 161,     /* vc_specific_modifier  */
  YYSYMBOL_pointer = 162,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 163,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 164,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 165,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 166,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 167,          /* identifier_list  */
  YYSYMBOL_type_name = 168,                /* type_name  */
  YYSYMBOL_abstract_declarator = 169,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 170, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 171,              /* initializer  */
  YYSYMBOL_initializer_list = 172,         /* initializer_list  */
  YYSYMBOL_designation = 173,              /* designation  */
  YYSYMBOL_designator_list = 174,          /* designator_list  */
  YYSYMBOL_designator = 175,               /* designator  */
  YYSYMBOL_static_assert_declaration = 176, /* static_assert_declaration  */
  YYSYMBOL_statement = 177,                /* statement  */
  YYSYMBOL_labeled_statement = 178,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 179,       /* compound_statement  */
  YYSYMBOL_block_item_list = 180,          /* block_item_list  */
  YYSYMBOL_block_item = 181,               /* block_item  */
  YYSYMBOL_expression_statement = 182,     /* expression_statement  */
  YYSYMBOL_selection_statement = 183,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 184,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 185,           /* jump_statement  */
  YYSYMBOL_translation_unit = 186,         /* translation_unit  */
  YYSYMBOL_external_declaration = 187,     /* external_declaration  */
  YYSYMBOL_function_definition = 188,      /* function_definition  */
  YYSYMBOL_declaration_list = 189          /* declaration_list  */
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
#define YYFINAL  80
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2470

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  111
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  288
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  499

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   341


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
       2,     2,     2,   101,     2,     2,     2,   103,    96,     2,
      87,    88,    97,    98,    89,    99,    93,   102,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    90,   110,
     104,   109,   105,   108,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    91,     2,    92,   106,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    94,   107,    95,   100,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   130,   130,   138,   145,   151,   159,   163,   169,   175,
     186,   195,   201,   210,   214,   215,   219,   220,   224,   230,
     251,   272,   295,   305,   318,   345,   356,   357,   361,   367,
     379,   385,   396,   406,   416,   433,   445,   449,   455,   460,
     466,   471,   476,   484,   500,   517,   523,   536,   545,   561,
     567,   576,   588,   594,   603,   615,   621,   630,   639,   648,
     661,   667,   676,   688,   694,   706,   712,   724,   730,   742,
     748,   762,   768,   782,   788,   811,   817,   832,   837,   842,
     847,   852,   857,   862,   867,   872,   877,   882,   890,   896,
     908,   917,   928,   952,   956,   964,   970,   990,   996,  1002,
    1008,  1009,  1010,  1011,  1015,  1021,  1033,  1041,  1064,  1070,
    1075,  1080,  1081,  1086,  1094,  1099,  1104,  1109,  1114,  1119,
    1124,  1129,  1134,  1139,  1144,  1149,  1154,  1155,  1161,  1167,
    1175,  1180,  1185,  1190,  1198,  1207,  1232,  1253,  1258,  1266,
    1272,  1284,  1285,  1313,  1317,  1323,  1329,  1337,  1346,  1353,
    1366,  1373,  1382,  1391,  1404,  1405,  1432,  1433,  1446,  1452,
    1465,  1486,  1506,  1510,  1515,  1520,  1525,  1533,  1534,  1535,
    1539,  1540,  1544,  1552,  1561,  1567,  1575,  1583,  1592,  1593,
    1594,  1595,  1596,  1597,  1598,  1599,  1621,  1629,  1639,  1647,
    1658,  1663,  1668,  1673,  1678,  1683,  1691,  1699,  1706,  1713,
    1721,  1727,  1739,  1747,  1759,  1765,  1776,  1793,  1801,  1810,
    1816,  1828,  1836,  1845,  1853,  1859,  1868,  1876,  1882,  1889,
    1890,  1891,  1892,  1893,  1894,  1895,  1903,  1912,  1913,  1914,
    1915,  1916,  1917,  1918,  1924,  1932,  1940,  1953,  1963,  1974,
    1983,  1992,  1998,  1999,  2003,  2013,  2019,  2030,  2038,  2049,
    2053,  2059,  2065,  2071,  2077,  2083,  2092,  2100,  2109,  2120,
    2127,  2144,  2150,  2166,  2173,  2182,  2187,  2198,  2208,  2217,
    2229,  2238,  2247,  2257,  2268,  2269,  2273,  2281,  2286,  2291,
    2296,  2307,  2313,  2324,  2331,  2348,  2360,  2374,  2380
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
  "__INT8", "__INT16", "__INT32", "__INT64", "COMPLEX", "IMAGINARY",
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "DECLSPEC", "CASE", "DEFAULT",
  "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE",
  "BREAK", "RETURN", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC", "NORETURN",
  "STATIC_ASSERT", "THREAD_LOCAL", "__CDECL", "__CLRCALL", "__STDCALL",
  "__FASTCALL", "__THISCALL", "__VECTORCALL", "'('", "')'", "','", "':'",
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
  "alignment_specifier", "declarator", "direct_declarator",
  "vc_specific_modifier", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator",
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,    40,    41,    44,
      58,    91,    93,    46,   123,   125,    38,    42,    43,    45,
     126,    33,    47,    37,    60,    62,    94,   124,    63,    61,
      59
};
#endif

#define YYPACT_NINF (-385)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2170,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,    20,
     -53,   -36,   -21,  -385,    -7,  -385,  -385,   720,  2270,  2270,
    -385,    24,  -385,  -385,  2270,  2270,  2270,  -385,  1739,  -385,
    -385,   -38,   100,   129,   878,  2394,  1495,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  1039,    -3,  -385,   -68,  -385,  1790,
      85,   137,   661,  -385,  -385,     1,  2313,  -385,  -385,  -385,
    -385,  -385,   100,  -385,   -77,   -20,  -385,    77,  -385,  -385,
    -385,  -385,  -385,  1525,  1600,  1600,  -385,    69,    84,   878,
    -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,  -385,
      29,  -385,  1495,  -385,    57,   -55,   168,    45,   170,    78,
      76,    81,   177,    -1,  -385,    96,  2394,    71,  2394,   109,
     116,   117,   120,   207,  -385,  -385,  -385,    -3,  1039,  -385,
     438,  1465,  -385,   720,  -385,  2050,  1606,   953,  -385,    85,
    2313,  1928,  -385,   314,  -385,    -4,  1495,    22,  -385,  -385,
     878,  -385,   878,  -385,  -385,  2394,  1495,   532,  -385,  -385,
     102,   126,   230,  -385,  -385,   938,  1495,   233,  -385,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  -385,  -385,
    1868,   993,    86,  -385,    92,  -385,  -385,  -385,   206,  -385,
     158,  -385,  -385,  -385,   150,   172,  1495,   181,   179,   186,
     192,   699,   194,   282,   185,   198,   748,  -385,  -385,   -43,
    -385,  -385,  -385,  -385,   539,  -385,  -385,  -385,  -385,  -385,
    1450,  -385,  -385,  -385,  -385,  -385,  -385,   729,   201,   202,
    -385,   166,  1298,  -385,   219,   223,  1068,  1986,  -385,  -385,
    1495,  -385,   -39,  -385,   228,    26,  -385,  -385,  -385,  -385,
     234,   235,   238,   240,  -385,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,  -385,  -385,  1495,  -385,  1495,  1480,  -385,
    -385,   169,  -385,   -31,  -385,  -385,  -385,  -385,    57,    57,
     -55,   -55,   168,   168,   168,   168,    45,    45,   170,    78,
      76,    81,   177,   171,  -385,   239,   242,  1298,  -385,   243,
     244,  1108,    92,  2113,  1183,   249,  -385,   699,   241,   699,
    1495,  1495,  1495,   271,   640,   229,  -385,  -385,  -385,    13,
    -385,  -385,  -385,  1495,   337,  -385,    48,  1465,    60,  -385,
    1673,  -385,   345,  -385,  -385,  2221,  -385,   340,   252,  1298,
    -385,  -385,  1495,  -385,   257,   258,  -385,  -385,   815,  -385,
    1495,  -385,   262,   262,  -385,  2355,  -385,  -385,  1450,  -385,
    -385,  1495,  -385,  1495,  -385,  -385,   259,  1298,  -385,  -385,
    1495,  -385,   260,  -385,   270,  1298,  -385,   273,   274,  1223,
     261,  -385,   699,  -385,   176,   180,   195,   280,   777,   777,
    -385,  -385,   276,  -385,  1336,  -385,  -385,  -385,  -385,  -385,
    -385,  -385,  -385,   277,   278,  -385,  -385,  -385,  -385,   284,
     205,  -385,   285,    68,  -385,  -385,  -385,   286,   288,  -385,
    -385,   289,  1298,  -385,  -385,  1495,  -385,   291,  -385,  -385,
     699,   699,   699,  1495,  1053,  1168,  -385,  -385,  -385,  1465,
    -385,  -385,  1495,  -385,  2355,  1495,  1351,  -385,  -385,  -385,
    -385,   292,   294,  -385,   307,  -385,  -385,   209,   699,   211,
     699,   215,  -385,  -385,  -385,  -385,  -385,  -385,  -385,   699,
     267,  -385,   699,  -385,   699,  -385,  -385,  -385,  -385
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   129,   108,   109,   110,   112,   113,   167,   163,   164,
     165,   123,   115,   116,   117,   118,   121,   122,   119,   120,
     114,   130,   131,   132,   133,   124,   125,   137,   138,     0,
       0,     0,   166,   168,     0,   111,   284,     0,    95,    97,
     127,     0,   128,   126,    99,   101,   103,    93,     0,   281,
     283,   157,     0,     0,     0,     0,     0,   174,   190,   191,
     192,   193,   194,   195,     0,   199,    91,     0,   104,   107,
     173,     0,     0,    94,    96,   136,     0,    98,   100,   102,
       1,   282,     0,    10,   161,     0,   158,     0,     2,     7,
       8,    11,    12,     0,     0,     0,     9,     0,     0,     0,
      37,    38,    39,    40,    41,    42,    18,     3,     4,     6,
      30,    43,     0,    45,    49,    52,    55,    60,    63,    65,
      67,    69,    71,    73,    90,     0,   145,   212,   147,     0,
       0,     0,     0,     0,   166,   200,   198,   197,     0,    92,
       0,     0,   287,     0,   286,     0,     0,     0,   188,   172,
       0,     0,   139,     0,   143,     0,     0,     0,   153,   169,
       0,    34,     0,    31,    32,     0,     0,    43,    75,    88,
       0,     0,     0,    24,    25,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   171,   144,
       0,     0,   214,   211,   215,   146,   170,   162,     0,   175,
     188,   201,   196,   105,   107,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,   265,     0,
     263,   264,   250,   251,     0,   261,   252,   253,   254,   255,
       0,   239,   106,   288,   285,   209,   186,   208,     0,   203,
     204,     0,     0,   176,    38,     0,     0,     0,   134,   140,
       0,   141,     0,   148,   152,     0,   155,   160,   154,   159,
       0,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    77,     0,     5,     0,     0,    23,
      20,     0,    28,     0,    22,    46,    47,    48,    50,    51,
      53,    54,    58,    59,    56,    57,    61,    62,    64,    66,
      68,    70,    72,     0,   233,     0,     0,     0,   217,    38,
       0,     0,   213,     0,     0,     0,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   277,   278,   279,     0,
     266,   260,   262,     0,     0,   241,     0,     0,     0,   245,
       0,   206,   214,   207,   185,     0,   187,     0,     0,     0,
     177,   184,     0,   183,    38,     0,   135,   150,     0,   142,
       0,   156,    35,     0,    36,     0,    76,    89,     0,    44,
      21,     0,    19,     0,   234,   216,     0,     0,   218,   224,
       0,   223,     0,   235,     0,     0,   225,    38,     0,     0,
       0,   256,     0,   258,     0,     0,     0,     0,     0,     0,
     276,   280,     0,   248,     0,   237,   240,   244,   246,   202,
     205,   210,   179,     0,     0,   180,   182,   149,   151,     0,
       0,    14,     0,     0,    29,    74,   220,     0,     0,   222,
     236,     0,     0,   226,   232,     0,   231,     0,   249,   257,
       0,     0,     0,     0,     0,     0,   247,   238,   243,     0,
     178,   181,     0,    13,     0,     0,     0,    26,   219,   221,
     228,     0,     0,   229,   268,   269,   270,     0,     0,     0,
       0,     0,   242,    17,    15,    16,    27,   227,   230,     0,
       0,   274,     0,   272,     0,   267,   271,   275,   273
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -385,  -385,  -385,  -385,  -385,  -385,  -385,   -75,  -385,  -385,
      36,  -385,   -35,   124,   125,    55,   123,   199,   200,   193,
     197,   212,  -385,   -23,    -5,  -385,   -92,   -15,   -59,     9,
    -385,   264,  -385,   -50,  -385,  -385,   253,  -131,   -63,  -385,
      37,  -385,   325,  -141,  -385,   -54,  -385,  -385,   -34,   -66,
     -62,   -48,  -139,  -134,  -385,    58,  -385,   112,  -112,  -188,
    -113,    34,  -384,  -385,    67,   -52,  -202,  -385,   -17,  -385,
     182,  -270,  -385,  -385,  -385,  -385,   369,  -385,  -385
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   106,   107,    84,   108,   109,   430,   431,   110,   291,
     167,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   168,   169,   285,   229,   125,    36,   143,
      67,    68,    38,    39,    40,    41,   151,   152,   127,   262,
     263,    42,    85,    86,    43,    44,    45,    46,   132,    70,
      71,    72,   137,   315,   249,   250,   251,   432,   316,   204,
     345,   346,   347,   348,   349,    47,   231,   232,   233,   234,
     235,   236,   237,   238,   239,    48,    49,    50,   145
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     128,   128,   133,    69,   126,   126,   149,   170,   256,    37,
     142,   135,   248,   153,   322,   203,   269,   136,   196,   333,
     259,   138,   128,    51,   154,    83,   126,    75,   242,    83,
     459,   124,   156,   124,    53,     8,     9,    10,   172,   173,
     174,   131,   139,   182,   183,   128,   287,    73,    74,   126,
     368,    54,   144,    77,    78,    79,    82,    37,   287,   186,
     187,   382,   321,   199,   409,   205,    55,   340,   170,   157,
     170,   369,   128,   134,   128,   158,   126,   178,   126,   202,
      56,   230,   459,   211,   293,   265,   243,   153,   153,   212,
     111,   266,   111,   135,    65,   150,   128,   128,   154,   154,
     126,   126,   287,    83,   214,   313,   128,   197,   128,   214,
     126,   128,   126,   359,    52,   126,   175,   268,    76,   264,
     176,   371,   177,   411,   269,   401,   259,   403,   244,   161,
     163,   164,    87,   124,   339,   353,   241,   414,   454,   455,
     148,   267,   255,   415,   295,   296,   297,   135,   111,   188,
     189,   343,   202,   344,   179,   247,   165,   466,   200,   180,
     181,   273,   201,   467,   322,   159,   129,   130,    65,   417,
     292,   166,   146,   200,   192,   230,   147,   201,   387,   323,
     184,   185,   193,   324,   198,   399,   190,   191,   194,   394,
     286,   287,   111,   124,   153,   195,   320,   206,   135,   352,
     449,   328,   211,   128,   207,   154,   208,   126,   209,   247,
     210,   171,   325,   351,   288,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   289,   416,   241,   294,   124,   404,   405,
     406,   302,   303,   304,   305,   367,   326,   358,   474,   475,
     476,   365,   111,   379,   356,   357,   442,   380,   381,   141,
     287,   383,   327,   135,   450,   287,   330,   211,   451,   287,
     135,   329,   270,   331,   271,   408,   491,   272,   493,   332,
     376,   334,   377,   452,   287,   335,   149,   495,   133,   354,
     497,   355,   498,   463,   464,   336,   111,   490,   287,   492,
     287,   458,   352,   494,   287,   211,   298,   299,   337,   300,
     301,   360,   386,   306,   307,   361,   392,    57,   370,   398,
     124,   128,   372,   373,   111,   126,   374,   384,   412,   375,
     385,   402,   247,   211,   264,   388,   389,   400,   407,   410,
     413,   135,   241,   421,   422,   211,   482,   124,    57,   425,
     426,   436,   439,   458,   423,   428,   378,   424,   440,   247,
     435,   477,   479,   481,   247,   443,   444,   453,   456,   460,
     461,   448,   489,   241,   462,   465,   434,   496,   468,   111,
     469,   470,   437,   473,   487,   438,   488,   310,   211,   484,
     441,   308,   311,   309,   447,    58,    59,    60,    61,    62,
      63,    64,   213,   257,   260,   427,   111,   155,   312,   241,
     128,    65,   433,   420,   126,   418,   342,    81,     0,   111,
       0,     0,     0,     0,   261,     0,    58,    59,    60,    61,
      62,    63,   350,     0,     0,     0,   201,   471,     0,     0,
     472,   215,    89,    90,    91,    92,    93,     0,    94,    95,
       0,     0,     0,     0,   241,     0,     0,   483,     0,     0,
     485,   241,     0,     0,     0,     0,     0,     0,     1,    96,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
     216,   217,   218,     0,   219,   220,   221,   222,   223,   224,
     225,   226,    31,    97,    32,    98,    33,    34,    35,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,   140,   227,   100,   101,   102,   103,   104,   105,
       0,     0,   215,    89,    90,    91,    92,    93,   228,    94,
      95,     0,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,     0,     0,     0,     0,     0,     0,     0,     1,
      96,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,   216,   217,   218,     0,   219,   220,   221,   222,   223,
     224,   225,   226,    31,    97,    32,    98,    33,    34,    35,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,   140,   341,   100,   101,   102,   103,   104,
     105,   284,     0,    88,    89,    90,    91,    92,    93,   228,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       1,    96,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,   215,    89,    90,    91,    92,    93,     0,    94,
      95,     0,     0,     0,    31,    97,    32,    98,    33,    34,
      35,     0,     0,    57,     0,     0,     0,    99,     0,     0,
      96,     0,    57,     0,     0,     0,   100,   101,   102,   103,
     104,   105,    58,    59,    60,    61,    62,    63,    64,     0,
     228,    88,    89,    90,    91,    92,    93,     0,    94,    95,
       0,   216,   217,   218,     0,   219,   220,   221,   222,   223,
     224,   225,   226,     0,    97,     0,    98,     0,     0,    96,
      88,    89,    90,    91,    92,    93,    99,    94,    95,     0,
       0,     0,     0,   140,     0,   100,   101,   102,   103,   104,
     105,    58,    59,    60,    61,    62,    63,    64,    96,   228,
      58,    59,    60,    61,    62,    63,   350,    65,    57,     0,
     201,     0,     0,    97,     0,    98,    65,     0,     0,     0,
      66,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     0,    97,     0,    98,     0,     0,     0,   338,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,     0,
       0,    88,    89,    90,    91,    92,    93,   228,    94,    95,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,     0,     0,   260,     0,     0,     1,    96,
       0,     0,    65,     0,     0,     0,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,     0,
       0,    88,    89,    90,    91,    92,    93,     0,    94,    95,
       0,     0,     0,    97,    32,    98,    88,    89,    90,    91,
      92,    93,     0,    94,    95,    99,     0,     0,     0,    96,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,    96,     0,     0,   252,     0,     0,
       0,     8,     9,    10,     0,     0,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,    98,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    99,   290,   317,    97,   134,
      98,     8,     9,    10,   100,   101,   102,   103,   104,   105,
      99,     0,    57,     0,     0,   253,     0,     0,     0,   100,
     254,   102,   103,   104,   105,     0,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,     0,     0,    97,   134,
      98,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      99,     0,     0,     0,    96,   318,     0,     0,     0,   100,
     319,   102,   103,   104,   105,     0,     0,     0,     0,    96,
       0,     0,   362,     0,     0,     0,     8,     9,    10,     0,
       0,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      58,    59,    60,    61,    62,    63,    64,     0,    97,     0,
      98,     0,     0,     0,     0,     0,    65,     0,     0,    96,
      99,   478,   390,    97,   134,    98,     8,     9,    10,   100,
     101,   102,   103,   104,   105,    99,     0,     0,     0,     0,
     363,     0,     0,     0,   100,   364,   102,   103,   104,   105,
       0,    88,    89,    90,    91,    92,    93,     0,    94,    95,
       0,     0,     0,    97,   134,    98,    88,    89,    90,    91,
      92,    93,     0,    94,    95,    99,     0,     0,     0,    96,
     391,     0,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,    96,     0,     0,   395,     0,     0,
       0,     8,     9,    10,     0,     0,    88,    89,    90,    91,
      92,    93,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,    98,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    99,   480,   445,    97,   134,
      98,     8,     9,    10,   100,   101,   102,   103,   104,   105,
      99,     0,     0,     0,     0,   396,     0,     0,     0,   100,
     397,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,   134,
      98,    88,    89,    90,    91,    92,    93,     0,    94,    95,
      99,     0,     0,     0,     0,   446,     0,     0,     0,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     8,     9,    10,    88,
      89,    90,    91,    92,    93,     0,    94,    95,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,    92,    93,
       0,    94,    95,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,    97,   134,    98,     0,     0,     0,     0,
       0,     0,    96,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,     0,    97,   343,    98,   344,
     240,   457,   100,   101,   102,   103,   104,   105,    99,     0,
       0,     0,   343,     0,   344,   240,   486,   100,   101,   102,
     103,   104,   105,    88,    89,    90,    91,    92,    93,     0,
      94,    95,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,     0,    94,    95,     0,     0,     0,
       0,    96,     0,    88,    89,    90,    91,    92,    93,     0,
      94,    95,     0,     0,     0,     0,    96,     0,    88,    89,
      90,    91,    92,    93,     0,    94,    95,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,    96,    98,    88,    89,
      90,    91,    92,    93,     0,    94,    95,    99,     0,     0,
      97,   343,    98,   344,   240,     0,   100,   101,   102,   103,
     104,   105,    99,     0,     0,    97,    96,    98,     0,   240,
       0,   100,   101,   102,   103,   104,   105,    99,     0,     0,
      97,     0,    98,     0,   378,     0,   100,   101,   102,   103,
     104,   105,    99,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,     0,     0,     0,
      97,     0,    98,    88,    89,    90,    91,    92,    93,   245,
      94,    95,   160,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,    96,     0,     0,     0,     0,     1,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,    30,     0,     0,
       0,     0,     0,     0,     0,    97,    57,    98,     0,     0,
      31,     0,    32,     0,    33,     0,    35,   162,     0,     0,
       0,     0,     0,     0,   246,     0,   100,   101,   102,   103,
     104,   105,     0,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,    31,     0,    32,
       0,    33,     0,    35,    58,    59,    60,    61,    62,    63,
     350,   314,     0,     0,   201,     0,     0,     0,     0,     1,
      65,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,    32,     0,    33,    34,    35,
       1,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    32,     0,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,   141,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    32,     0,    33,     0,    35,     0,
       0,     0,     0,     0,     0,   200,   314,     0,     1,   201,
       0,     0,     0,     0,     0,    65,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,   258,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,   366,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    32,     0,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,   140,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,    32,
       0,    33,     0,    35,     0,     0,     0,     0,     0,     0,
       1,   393,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    32,     0,    33,    34,
      35,     1,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,   419,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,    32,     0,    33,
       1,    35,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,    31,     0,    32,     0,    33,     0,
      35,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,    32,
       0,     0,    34,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,     0,     0,   429,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,    32,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32
};

static const yytype_int16 yycheck[] =
{
      54,    55,    64,    37,    54,    55,    72,    99,   147,     0,
      69,    65,   146,    76,   202,   127,   157,    65,    19,   221,
     151,    89,    76,     3,    76,     3,    76,     3,   141,     3,
     414,    54,   109,    56,    87,    38,    39,    40,     9,    10,
      11,    56,   110,    98,    99,    99,    89,    38,    39,    99,
      89,    87,    69,    44,    45,    46,    94,    48,    89,    14,
      15,    92,   201,   126,   334,   128,    87,   110,   160,    89,
     162,   110,   126,    76,   128,    95,   126,   112,   128,   127,
      87,   140,   466,   137,   176,    89,   145,   150,   151,   137,
      54,    95,    56,   147,    97,    94,   150,   151,   150,   151,
     150,   151,    89,     3,   138,   197,   160,   108,   162,   143,
     160,   165,   162,   252,    94,   165,    87,    95,    94,   153,
      91,    95,    93,   110,   265,   327,   257,   329,   145,    93,
      94,    95,     3,   156,   226,   247,   141,    89,   408,   409,
       3,   156,   147,    95,   179,   180,   181,   201,   112,   104,
     105,    91,   200,    93,    97,   146,    87,    89,    87,   102,
     103,   166,    91,    95,   352,    88,    54,    55,    97,   109,
     175,    87,    87,    87,    96,   234,    91,    91,   317,    87,
      12,    13,   106,    91,    88,   324,    16,    17,   107,   323,
      88,    89,   156,   216,   257,    18,   201,    88,   252,   247,
     402,   216,   256,   257,    88,   257,    89,   257,    88,   200,
       3,    99,     6,   247,    88,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,     3,   347,   240,     3,   260,   330,   331,
     332,   186,   187,   188,   189,   260,    88,   252,   450,   451,
     452,   256,   216,   288,    88,    89,   395,    88,    89,   109,
      89,    90,    90,   317,    88,    89,    87,   321,    88,    89,
     324,    90,   160,    87,   162,   334,   478,   165,   480,    87,
     285,    87,   287,    88,    89,     3,   352,   489,   350,    88,
     492,    89,   494,    88,    89,   110,   260,    88,    89,    88,
      89,   414,   350,    88,    89,   359,   182,   183,   110,   184,
     185,    92,   317,   190,   191,    92,   321,     3,    90,   324,
     343,   375,    88,    88,   288,   375,    88,    88,   343,    89,
      88,    90,   323,   387,   368,    92,    92,    88,    67,   110,
       3,   395,   347,     3,    92,   399,   459,   370,     3,    92,
      92,    92,    92,   466,   359,   370,    94,   362,    88,   350,
     383,   453,   454,   455,   355,    92,    92,    87,    92,    92,
      92,   110,    65,   378,    90,    90,   381,   110,    92,   343,
      92,    92,   387,    92,    92,   390,    92,   194,   442,   464,
     395,   192,   195,   193,   399,    81,    82,    83,    84,    85,
      86,    87,   138,   150,    90,   368,   370,    82,   196,   414,
     464,    97,   378,   355,   464,   348,   234,    48,    -1,   383,
      -1,    -1,    -1,    -1,   110,    -1,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    -1,    91,   442,    -1,    -1,
     445,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,   459,    -1,    -1,   462,    -1,    -1,
     465,   466,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
      -1,    -1,     3,     4,     5,     6,     7,     8,   110,    10,
      11,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   109,    -1,     3,     4,     5,     6,     7,     8,   110,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    -1,    -1,     3,    -1,    -1,    -1,    87,    -1,    -1,
      31,    -1,     3,    -1,    -1,    -1,    96,    97,    98,    99,
     100,   101,    81,    82,    83,    84,    85,    86,    87,    -1,
     110,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    -1,    75,    -1,    77,    -1,    -1,    31,
       3,     4,     5,     6,     7,     8,    87,    10,    11,    -1,
      -1,    -1,    -1,    94,    -1,    96,    97,    98,    99,   100,
     101,    81,    82,    83,    84,    85,    86,    87,    31,   110,
      81,    82,    83,    84,    85,    86,    87,    97,     3,    -1,
      91,    -1,    -1,    75,    -1,    77,    97,    -1,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
      -1,    -1,    75,    -1,    77,    -1,    -1,    -1,   110,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,   100,   101,    -1,
      -1,     3,     4,     5,     6,     7,     8,   110,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    90,    -1,    -1,    30,    31,
      -1,    -1,    97,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    75,    76,    77,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    87,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    87,    88,    34,    75,    76,
      77,    38,    39,    40,    96,    97,    98,    99,   100,   101,
      87,    -1,     3,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    98,    99,   100,   101,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    75,    76,
      77,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      87,    -1,    -1,    -1,    31,    92,    -1,    -1,    -1,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      81,    82,    83,    84,    85,    86,    87,    -1,    75,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,    31,
      87,    88,    34,    75,    76,    77,    38,    39,    40,    96,
      97,    98,    99,   100,   101,    87,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    75,    76,    77,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    87,    -1,    -1,    -1,    31,
      92,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    87,    88,    34,    75,    76,
      77,    38,    39,    40,    96,    97,    98,    99,   100,   101,
      87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      77,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      87,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    75,    91,    77,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    87,    -1,
      -1,    -1,    91,    -1,    93,    94,    95,    96,    97,    98,
      99,   100,   101,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    31,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    31,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    31,    77,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    87,    -1,    -1,
      75,    91,    77,    93,    94,    -1,    96,    97,    98,    99,
     100,   101,    87,    -1,    -1,    75,    31,    77,    -1,    94,
      -1,    96,    97,    98,    99,   100,   101,    87,    -1,    -1,
      75,    -1,    77,    -1,    94,    -1,    96,    97,    98,    99,
     100,   101,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      75,    -1,    77,     3,     4,     5,     6,     7,     8,     3,
      10,    11,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,   100,   101,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    30,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,     3,    77,    -1,    -1,
      74,    -1,    76,    -1,    78,    -1,    80,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    96,    97,    98,    99,
     100,   101,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    -1,    -1,    -1,    -1,     0,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    76,
      -1,    78,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    30,
      97,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    76,    -1,    78,    79,    80,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,   109,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    76,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    30,    91,
      -1,    -1,    -1,    -1,    -1,    97,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    79,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    95,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    94,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    76,
      -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    88,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    78,    79,
      80,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    78,
      30,    80,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    74,    -1,    76,    -1,    78,    -1,
      80,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    76,
      -1,    -1,    79,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    -1,    -1,    63,    -1,
      -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      61,    74,    76,    78,    79,    80,   139,   140,   143,   144,
     145,   146,   152,   155,   156,   157,   158,   176,   186,   187,
     188,     3,    94,    87,    87,    87,    87,     3,    81,    82,
      83,    84,    85,    86,    87,    97,   110,   141,   142,   159,
     160,   161,   162,   140,   140,     3,    94,   140,   140,   140,
       0,   187,    94,     3,   114,   153,   154,     3,     3,     4,
       5,     6,     7,     8,    10,    11,    31,    75,    77,    87,
      96,    97,    98,    99,   100,   101,   112,   113,   115,   116,
     119,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   138,   144,   149,   156,   168,
     168,   138,   159,   161,    76,   156,   162,   163,    89,   110,
      94,   109,   139,   140,   179,   189,    87,    91,     3,   160,
      94,   147,   148,   149,   176,   153,   109,    89,    95,    88,
      87,   121,    87,   121,   121,    87,    87,   121,   134,   135,
     137,   168,     9,    10,    11,    87,    91,    93,   123,    97,
     102,   103,    98,    99,    12,    13,    14,    15,   104,   105,
      16,    17,    96,   106,   107,    18,    19,   108,    88,   149,
      87,    91,   162,   169,   170,   149,    88,    88,    89,    88,
       3,   156,   162,   142,   159,     3,    62,    63,    64,    66,
      67,    68,    69,    70,    71,    72,    73,    95,   110,   137,
     139,   177,   178,   179,   180,   181,   182,   183,   184,   185,
      94,   135,   171,   139,   179,     3,    88,   140,   164,   165,
     166,   167,    34,    92,    97,   135,   163,   147,    95,   148,
      90,   110,   150,   151,   159,    89,    95,   138,    95,   154,
     168,   168,   168,   135,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   109,   136,    88,    89,    88,     3,
      88,   120,   135,   137,     3,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   126,   126,   127,   127,   128,   129,
     130,   131,   132,   137,    88,   164,   169,    34,    92,    97,
     135,   163,   170,    87,    91,     6,    88,    90,   138,    90,
      87,    87,    87,   177,    87,     3,   110,   110,   110,   137,
     110,    95,   181,    91,    93,   171,   172,   173,   174,   175,
      87,   159,   162,   169,    88,    89,    88,    89,   135,   163,
      92,    92,    34,    92,    97,   135,    95,   138,    89,   110,
      90,    95,    88,    88,    88,    89,   135,   135,    94,   123,
      88,    89,    92,    90,    88,    88,   135,   163,    92,    92,
      34,    92,   135,    88,   164,    34,    92,    97,   135,   163,
      88,   177,    90,   177,   137,   137,   137,    67,   139,   182,
     110,   110,   138,     3,    89,    95,   171,   109,   175,    60,
     166,     3,    92,   135,   135,    92,    92,   151,   138,    63,
     117,   118,   168,   172,   135,   134,    92,   135,   135,    92,
      88,   135,   163,    92,    92,    34,    92,   135,   110,   177,
      88,    88,    88,    87,   182,   182,    92,    95,   171,   173,
      92,    92,    90,    88,    89,    90,    89,    95,    92,    92,
      92,   135,   135,    92,   177,   177,   177,   137,    88,   137,
      88,   137,   171,   135,   118,   135,    95,    92,    92,    65,
      88,   177,    88,   177,    88,   177,   110,   177,   177
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   111,   112,   112,   112,   112,   112,   113,   113,   113,
     114,   115,   115,   116,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     121,   121,   121,   121,   121,   121,   121,   122,   122,   122,
     122,   122,   122,   123,   123,   124,   124,   124,   124,   125,
     125,   125,   126,   126,   126,   127,   127,   127,   127,   127,
     128,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   137,   137,
     138,   139,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   142,   142,   143,   143,
     143,   143,   143,   143,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   145,   145,   145,   146,   146,   147,
     147,   148,   148,   148,   149,   149,   149,   149,   150,   150,
     151,   151,   151,   152,   152,   152,   152,   152,   153,   153,
     154,   154,   155,   156,   156,   156,   156,   157,   157,   157,
     158,   158,   159,   159,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   160,   160,   160,
     161,   161,   161,   161,   161,   161,   162,   162,   162,   162,
     163,   163,   164,   164,   165,   165,   166,   166,   166,   167,
     167,   168,   168,   169,   169,   169,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   171,   171,   171,
     172,   172,   172,   172,   173,   174,   174,   175,   175,   176,
     177,   177,   177,   177,   177,   177,   178,   178,   178,   179,
     179,   180,   180,   181,   181,   182,   182,   183,   183,   183,
     184,   184,   184,   184,   184,   184,   185,   185,   185,   185,
     185,   186,   186,   187,   187,   188,   188,   189,   189
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
       1,     1,     1,     1,     4,     5,     2,     1,     1,     1,
       2,     2,     3,     1,     2,     1,     2,     1,     1,     3,
       2,     3,     1,     4,     5,     5,     6,     2,     1,     3,
       3,     1,     4,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     2,     1,     1,     3,     3,     4,     6,     5,
       5,     6,     5,     4,     4,     4,     3,     4,     2,     4,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     1,
       1,     2,     3,     1,     1,     3,     2,     2,     1,     1,
       3,     2,     1,     2,     1,     1,     3,     2,     3,     5,
       4,     5,     4,     3,     3,     3,     4,     6,     5,     5,
       6,     4,     4,     2,     3,     3,     4,     3,     4,     1,
       2,     1,     4,     3,     2,     1,     2,     3,     2,     7,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     2,
       3,     1,     2,     1,     1,     1,     2,     7,     5,     5,
       5,     7,     6,     7,     6,     7,     3,     2,     2,     2,
       3,     1,     2,     1,     1,     4,     3,     1,     2
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
#line 131 "grammar.y"
        {
		char* identifier = identifier_function((yyvsp[0].id)); // DEFINITIONS.H
        (yyval.id) = (char*) malloc(strlen(identifier) + 1);
        strcpy((yyval.id), identifier);
		free(identifier);
        free((yyvsp[0].id));
	}
#line 2059 "grammar.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 139 "grammar.y"
        {
        (yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), ascii_function((yyvsp[0].id))); // ASCII_FUNCTIONS.H
		strcpy((yyval.id), check_number((yyvsp[0].id)));   // CONVERSION_FUNCTIONS.H
        free((yyvsp[0].id));
	}
#line 2070 "grammar.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 146 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2080 "grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 152 "grammar.y"
        {
        (yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
        strcat((yyval.id), (yyvsp[-1].id));
        strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 2092 "grammar.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 164 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2102 "grammar.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 170 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2112 "grammar.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 176 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2122 "grammar.tab.c"
    break;

  case 10: /* enumeration_constant: IDENTIFIER  */
#line 187 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2132 "grammar.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 196 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2142 "grammar.tab.c"
    break;

  case 12: /* string: FUNC_NAME  */
#line 202 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2152 "grammar.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 225 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2162 "grammar.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 231 "grammar.y"
        {
		if (strstr((yyvsp[-3].id), "[") != NULL)
		{
			char* array = process_arrays((yyvsp[-3].id), (yyvsp[-1].id)); // ARRAY_FUNCTIONS.H
			(yyval.id) = (char*) malloc(strlen(array) + 1);
			strcpy((yyval.id), array);
			free(array);
		}
		else
		{
			(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
			strcpy((yyval.id), (yyvsp[-3].id));
            strcat((yyval.id), "[");
            strcat((yyval.id), (yyvsp[-1].id));
            strcat((yyval.id), "]");
		}
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));

	}
#line 2187 "grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '(' ')'  */
#line 252 "grammar.y"
        {
		// Process function calls (without arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		char *func_name = (char *) malloc(STRING_LIMIT);
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
#line 2212 "grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 273 "grammar.y"
        {
		// Process function calls (with arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		char *func_name = (char*) malloc(STRING_LIMIT);
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
#line 2239 "grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 296 "grammar.y"
        {
		// Process records/structures
		char* record = process_records((yyvsp[-2].id), (yyvsp[0].id)); // STRUCTURES.H
        (yyval.id) = (char*) malloc(strlen(record) + 1);
		strcpy((yyval.id), record);
		free(record);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2253 "grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 306 "grammar.y"
        {
		// Process linked list statements
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
#line 2270 "grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression INC_OP  */
#line 319 "grammar.y"
                {
		// Process statements such as i++;
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
#line 2301 "grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression DEC_OP  */
#line 346 "grammar.y"
        {
		// Process statements such as i--;
        (yyval.id) = (char*) malloc(17+strlen((yyvsp[-1].id))+3+strlen((yyvsp[-1].id))+3+1);
		strcpy((yyval.id), "\npost_decrement(");
        strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), " , ");
        strcat((yyval.id), (yyvsp[-1].id));
        strcat((yyval.id), "-1)");
        free((yyvsp[-1].id));
	}
#line 2316 "grammar.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 362 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2326 "grammar.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 368 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[-2].id));
        strcat((yyval.id), ",");
        strcat((yyval.id), (yyvsp[0].id));
        free((yyvsp[-2].id));
        free((yyvsp[0].id));
    }
#line 2339 "grammar.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 380 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2349 "grammar.tab.c"
    break;

  case 31: /* unary_expression: INC_OP unary_expression  */
#line 386 "grammar.y"
        {
		// Process statements such as ++i;
        (yyval.id) = (char*) malloc(16 + strlen((yyvsp[0].id)) + 3 + strlen((yyvsp[0].id)) + 3 + 1);
		strcpy((yyval.id), "\npre_increment(");
        strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), "+1)");
        free((yyvsp[0].id));
	}
#line 2364 "grammar.tab.c"
    break;

  case 32: /* unary_expression: DEC_OP unary_expression  */
#line 397 "grammar.y"
        {
		// Process statements such as --i;
        (yyval.id) = (char*) malloc(16 + strlen((yyvsp[0].id)) + 3 + strlen((yyvsp[0].id)) + 3 + 1);
		strcpy((yyval.id), "\npre_decrement(");
        strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
        strcat((yyval.id), "-1)");
	}
#line 2378 "grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 407 "grammar.y"
        {
		char* unary_cast = process_cast_unary_rule((yyvsp[-1].id), (yyvsp[0].id));
		// Process casting expressions
        (yyval.id) = (char*) malloc(strlen(unary_cast) + 1);
		strcpy((yyval.id), unary_cast);	// DECL_FUNCTIONS.H
		free(unary_cast);
        free((yyvsp[-1].id));
        free((yyvsp[0].id));
	}
#line 2392 "grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 417 "grammar.y"
        {
		// Process sizeof statements
		(yyval.id) = (char*) malloc(6+1+strlen((yyvsp[0].id))+1+1);
		strcpy((yyval.id), "sizeof");
		if ((yyvsp[0].id)[0] != '(')
		{
			strcat((yyval.id), "(");
			strcat((yyval.id), (yyvsp[0].id));
			strcat((yyval.id), ")");
		}
		else
		{
			strcat((yyval.id), (yyvsp[0].id));
		}
		free((yyvsp[0].id));
	}
#line 2413 "grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 434 "grammar.y"
        {
		// Process sizeof(type) statements
		char* type_processed = change_asterisk((yyvsp[-1].id));
		(yyval.id) = (char*) malloc(6 + 1 + strlen(type_processed) + 1 + 1);
		strcpy((yyval.id), "sizeof");
		strcat((yyval.id), "(");
		strcat((yyval.id), type_processed); 	// DECL_FUNCTIONS.H
		strcat((yyval.id), ")");
		free(type_processed);
		free((yyvsp[-1].id));
	}
#line 2429 "grammar.tab.c"
    break;

  case 37: /* unary_operator: '&'  */
#line 450 "grammar.y"
        {
		(yyval.id) = (char*) malloc(10+1);
		strcpy((yyval.id), "address_of");

	}
#line 2439 "grammar.tab.c"
    break;

  case 38: /* unary_operator: '*'  */
#line 456 "grammar.y"
        {
		(yyval.id) = (char*) malloc(11+1);
		strcpy((yyval.id), "dereference");
	}
#line 2448 "grammar.tab.c"
    break;

  case 39: /* unary_operator: '+'  */
#line 461 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "+");

	}
#line 2458 "grammar.tab.c"
    break;

  case 40: /* unary_operator: '-'  */
#line 467 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "-");
	}
#line 2467 "grammar.tab.c"
    break;

  case 41: /* unary_operator: '~'  */
#line 472 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "~");
	}
#line 2476 "grammar.tab.c"
    break;

  case 42: /* unary_operator: '!'  */
#line 477 "grammar.y"
        {
		(yyval.id) = (char*) malloc(11+1);
		strcpy((yyval.id), "exclamation");
	}
#line 2485 "grammar.tab.c"
    break;

  case 43: /* cast_expression: unary_expression  */
#line 485 "grammar.y"
        {
		// Surround negative numbers with ( and )
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
#line 2505 "grammar.tab.c"
    break;

  case 44: /* cast_expression: '(' type_name ')' cast_expression  */
#line 501 "grammar.y"
        {
		// Process cast expressions
		char* typename = change_asterisk((yyvsp[-2].id)); // DECL_FUNCTIONS.H
		(yyval.id) = (char*) malloc(6 + strlen(typename) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "cast((");
		strcat((yyval.id), typename);
		strcat((yyval.id), "), ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free(typename);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2523 "grammar.tab.c"
    break;

  case 45: /* multiplicative_expression: cast_expression  */
#line 518 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2533 "grammar.tab.c"
    break;

  case 46: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 524 "grammar.y"
        {
		// Process * - change '*' to multiply to avoid confusion with
		// the pointer dereference '*'
		(yyval.id) = (char*) malloc(9 + strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "multiply(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2550 "grammar.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 537 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "/");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2563 "grammar.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 546 "grammar.y"
        {
		// Process % - change '%' to modulo to avoid confusion with
		// the Prolog comments operator '%'
		(yyval.id) = (char*) malloc(4 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "mod(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2580 "grammar.tab.c"
    break;

  case 49: /* additive_expression: multiplicative_expression  */
#line 562 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2590 "grammar.tab.c"
    break;

  case 50: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 568 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "+");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2603 "grammar.tab.c"
    break;

  case 51: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 577 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "-");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2616 "grammar.tab.c"
    break;

  case 52: /* shift_expression: additive_expression  */
#line 589 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2626 "grammar.tab.c"
    break;

  case 53: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 595 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<<");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2639 "grammar.tab.c"
    break;

  case 54: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 604 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">>");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2652 "grammar.tab.c"
    break;

  case 55: /* relational_expression: shift_expression  */
#line 616 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2662 "grammar.tab.c"
    break;

  case 56: /* relational_expression: relational_expression '<' shift_expression  */
#line 622 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2675 "grammar.tab.c"
    break;

  case 57: /* relational_expression: relational_expression '>' shift_expression  */
#line 631 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2688 "grammar.tab.c"
    break;

  case 58: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 640 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<=");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2701 "grammar.tab.c"
    break;

  case 59: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 649 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">=");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2714 "grammar.tab.c"
    break;

  case 60: /* equality_expression: relational_expression  */
#line 662 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2724 "grammar.tab.c"
    break;

  case 61: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 668 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "==");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2737 "grammar.tab.c"
    break;

  case 62: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 677 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<>");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2750 "grammar.tab.c"
    break;

  case 63: /* and_expression: equality_expression  */
#line 689 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2760 "grammar.tab.c"
    break;

  case 64: /* and_expression: and_expression '&' equality_expression  */
#line 695 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "&");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2773 "grammar.tab.c"
    break;

  case 65: /* exclusive_or_expression: and_expression  */
#line 707 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2783 "grammar.tab.c"
    break;

  case 66: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 713 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "^");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2796 "grammar.tab.c"
    break;

  case 67: /* inclusive_or_expression: exclusive_or_expression  */
#line 725 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2806 "grammar.tab.c"
    break;

  case 68: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 731 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "|");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2819 "grammar.tab.c"
    break;

  case 69: /* logical_and_expression: inclusive_or_expression  */
#line 743 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2829 "grammar.tab.c"
    break;

  case 70: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 749 "grammar.y"
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
#line 2844 "grammar.tab.c"
    break;

  case 71: /* logical_or_expression: logical_and_expression  */
#line 763 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2854 "grammar.tab.c"
    break;

  case 72: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 769 "grammar.y"
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
#line 2869 "grammar.tab.c"
    break;

  case 73: /* conditional_expression: logical_or_expression  */
#line 783 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2879 "grammar.tab.c"
    break;

  case 74: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 789 "grammar.y"
        {
		// Process ternary expressions from C to Prolog
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
#line 2903 "grammar.tab.c"
    break;

  case 75: /* assignment_expression: conditional_expression  */
#line 812 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2913 "grammar.tab.c"
    break;

  case 76: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 818 "grammar.y"
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
#line 2929 "grammar.tab.c"
    break;

  case 77: /* assignment_operator: '='  */
#line 833 "grammar.y"
        {
		(yyval.id) = (char*) malloc(13 + 1);
		strcpy((yyval.id), "\nassignment(");
	}
#line 2938 "grammar.tab.c"
    break;

  case 78: /* assignment_operator: MUL_ASSIGN  */
#line 838 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nmul_assignment(");
	}
#line 2947 "grammar.tab.c"
    break;

  case 79: /* assignment_operator: DIV_ASSIGN  */
#line 843 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\ndiv_assignment(");
	}
#line 2956 "grammar.tab.c"
    break;

  case 80: /* assignment_operator: MOD_ASSIGN  */
#line 848 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nmod_assignment(");
	}
#line 2965 "grammar.tab.c"
    break;

  case 81: /* assignment_operator: ADD_ASSIGN  */
#line 853 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nadd_assignment(");
	}
#line 2974 "grammar.tab.c"
    break;

  case 82: /* assignment_operator: SUB_ASSIGN  */
#line 858 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nsub_assignment(");
	}
#line 2983 "grammar.tab.c"
    break;

  case 83: /* assignment_operator: LEFT_ASSIGN  */
#line 863 "grammar.y"
        {
		(yyval.id) = (char*) malloc(18 + 1);
		strcpy((yyval.id), "\nleft_assignment(");
	}
#line 2992 "grammar.tab.c"
    break;

  case 84: /* assignment_operator: RIGHT_ASSIGN  */
#line 868 "grammar.y"
        {
		(yyval.id) = (char*) malloc(19 + 1);
		strcpy((yyval.id), "\nright_assignment(");
	}
#line 3001 "grammar.tab.c"
    break;

  case 85: /* assignment_operator: AND_ASSIGN  */
#line 873 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nand_assignment(");
	}
#line 3010 "grammar.tab.c"
    break;

  case 86: /* assignment_operator: XOR_ASSIGN  */
#line 878 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nxor_assignment(");
	}
#line 3019 "grammar.tab.c"
    break;

  case 87: /* assignment_operator: OR_ASSIGN  */
#line 883 "grammar.y"
        {
		(yyval.id) = (char*) malloc(16 + 1);
		strcpy((yyval.id), "\nor_assignment(");
	}
#line 3028 "grammar.tab.c"
    break;

  case 88: /* expression: assignment_expression  */
#line 891 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3038 "grammar.tab.c"
    break;

  case 89: /* expression: expression ',' assignment_expression  */
#line 897 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "comma(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
	}
#line 3051 "grammar.tab.c"
    break;

  case 90: /* constant_expression: conditional_expression  */
#line 909 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3061 "grammar.tab.c"
    break;

  case 91: /* declaration: declaration_specifiers ';'  */
#line 918 "grammar.y"
        {
		char* declaration = struct_declaration((yyvsp[-1].id));
		(yyval.id) = (char*) malloc(strlen(declaration) + 1);
		strcpy((yyval.id), declaration);	// STRUCTURES.H
		free(declaration);
		free((yyvsp[-1].id));
		if(typedef_flag == YES) {
			typedef_flag = NO;
		}
	}
#line 3076 "grammar.tab.c"
    break;

  case 92: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 929 "grammar.y"
        {
		if(typedef_flag == YES) {
			typedef_flag = NO;
			char* declaration = process_typedef((yyvsp[-2].id), (yyvsp[-1].id));
			(yyval.id) = (char*) malloc(strlen(declaration) + 1);
			strcpy((yyval.id), declaration);	// STRUCTURES.H
			free(declaration);
		}
		else
		{
			int lenSS;
			char* declaration_string = findvariabledetails((yyvsp[-2].id)); // DECL_FUNCTIONS.H
			(yyval.id) = (char*) malloc(strlen(declaration_string) + 1 + 1);
			strcpy((yyval.id), declaration_string);
			free(declaration_string);
			lenSS = strlen((yyval.id)) - 1;

			if ((yyval.id)[lenSS] != ',')
				strcat((yyval.id), ",");
		}
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
	}
#line 3104 "grammar.tab.c"
    break;

  case 94: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 957 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3116 "grammar.tab.c"
    break;

  case 95: /* declaration_specifiers: storage_class_specifier  */
#line 965 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3126 "grammar.tab.c"
    break;

  case 96: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 971 "grammar.y"
        {
		// Only append comma if not a type such as "unsigned int"
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
#line 3150 "grammar.tab.c"
    break;

  case 97: /* declaration_specifiers: type_specifier  */
#line 991 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3160 "grammar.tab.c"
    break;

  case 98: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 997 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
	}
#line 3170 "grammar.tab.c"
    break;

  case 99: /* declaration_specifiers: type_qualifier  */
#line 1003 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3180 "grammar.tab.c"
    break;

  case 104: /* init_declarator_list: init_declarator  */
#line 1016 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3190 "grammar.tab.c"
    break;

  case 105: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 1022 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3203 "grammar.tab.c"
    break;

  case 106: /* init_declarator: declarator '=' initializer  */
#line 1034 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		addvariabledetails((yyvsp[-2].id), (yyvsp[0].id)); // DECL_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3215 "grammar.tab.c"
    break;

  case 107: /* init_declarator: declarator  */
#line 1042 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		if(typedef_flag == YES)
		{
			char* declaration_cleaned = change_typedef((yyvsp[0].id)); // TYPEDEF_FUNCTIONS.H
			add_typedefs(declaration_cleaned); // TYPEDEF_FUNCTIONS.H
			free(declaration_cleaned);
		}
		else
		{
			// addvariables modifies the passed parameter. Reassigning to temp
			char* temp = (char*) malloc(STRING_LIMIT);
			strcpy(temp, (yyvsp[0].id));
			addvariables(temp, NO);	// DECL_FUNCTIONS.H
			free(temp);
		}
		free((yyvsp[0].id));
	}
#line 3239 "grammar.tab.c"
    break;

  case 108: /* storage_class_specifier: TYPEDEF  */
#line 1065 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "typedef");
		set_typedef_flag();	// TYPEDEF_FUNCTIONS.H
	}
#line 3249 "grammar.tab.c"
    break;

  case 109: /* storage_class_specifier: EXTERN  */
#line 1071 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "extern");
	}
#line 3258 "grammar.tab.c"
    break;

  case 110: /* storage_class_specifier: STATIC  */
#line 1076 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "Static_");
	}
#line 3267 "grammar.tab.c"
    break;

  case 112: /* storage_class_specifier: AUTO  */
#line 1082 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 3276 "grammar.tab.c"
    break;

  case 113: /* storage_class_specifier: REGISTER  */
#line 1087 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 3285 "grammar.tab.c"
    break;

  case 114: /* type_specifier: VOID  */
#line 1095 "grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + 1);
		strcpy((yyval.id), "void");
	}
#line 3294 "grammar.tab.c"
    break;

  case 115: /* type_specifier: CHAR  */
#line 1100 "grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + 1);
		strcpy((yyval.id), "char");
	}
#line 3303 "grammar.tab.c"
    break;

  case 116: /* type_specifier: SHORT  */
#line 1105 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5 + 1);
		strcpy((yyval.id), "short");
	}
#line 3312 "grammar.tab.c"
    break;

  case 117: /* type_specifier: INT  */
#line 1110 "grammar.y"
        {
		(yyval.id) = (char*) malloc(3 + 1);
		strcpy((yyval.id), "int");
	}
#line 3321 "grammar.tab.c"
    break;

  case 118: /* type_specifier: LONG  */
#line 1115 "grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + 1);
		strcpy((yyval.id), "long");
	}
#line 3330 "grammar.tab.c"
    break;

  case 119: /* type_specifier: FLOAT  */
#line 1120 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(5 + 1);
		 strcpy((yyval.id), "float");
	}
#line 3339 "grammar.tab.c"
    break;

  case 120: /* type_specifier: DOUBLE  */
#line 1125 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "double");
	}
#line 3348 "grammar.tab.c"
    break;

  case 121: /* type_specifier: SIGNED  */
#line 1130 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "signed");
	}
#line 3357 "grammar.tab.c"
    break;

  case 122: /* type_specifier: UNSIGNED  */
#line 1135 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(8 + 1);
		 strcpy((yyval.id), "unsigned");
	}
#line 3366 "grammar.tab.c"
    break;

  case 123: /* type_specifier: BOOL  */
#line 1140 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(4 + 1);
		 strcpy((yyval.id), "bool");
	}
#line 3375 "grammar.tab.c"
    break;

  case 124: /* type_specifier: COMPLEX  */
#line 1145 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(7 + 1);
		 strcpy((yyval.id), "complex");
	}
#line 3384 "grammar.tab.c"
    break;

  case 125: /* type_specifier: IMAGINARY  */
#line 1150 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(9 + 1);
		 strcpy((yyval.id), "imaginary");
	}
#line 3393 "grammar.tab.c"
    break;

  case 127: /* type_specifier: struct_or_union_specifier  */
#line 1156 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3403 "grammar.tab.c"
    break;

  case 128: /* type_specifier: enum_specifier  */
#line 1162 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3413 "grammar.tab.c"
    break;

  case 129: /* type_specifier: TYPEDEF_NAME  */
#line 1168 "grammar.y"
        {
		char* name = change_typedef((yyvsp[0].id));
		(yyval.id) = (char*) malloc(strlen(name) + 1);
		strcpy((yyval.id), name);	 // TYPEDEF_FUNCTIONS.H
		free(name);
		free((yyvsp[0].id));
	}
#line 3425 "grammar.tab.c"
    break;

  case 130: /* type_specifier: __INT8  */
#line 1176 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "__int8");
	}
#line 3434 "grammar.tab.c"
    break;

  case 131: /* type_specifier: __INT16  */
#line 1181 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "__int16");
	}
#line 3443 "grammar.tab.c"
    break;

  case 132: /* type_specifier: __INT32  */
#line 1186 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "__int32");
	}
#line 3452 "grammar.tab.c"
    break;

  case 133: /* type_specifier: __INT64  */
#line 1191 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "__int64");
	}
#line 3461 "grammar.tab.c"
    break;

  case 134: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 1199 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 3 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), ", [");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 3474 "grammar.tab.c"
    break;

  case 135: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 1208 "grammar.y"
        {
		// change the structure name.
		char * struct_name = (char *) malloc(3 + strlen((yyvsp[-3].id)) + 1);
		if (islower((yyvsp[-3].id)[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, (yyvsp[-3].id));

		(yyval.id) = (char*) malloc(strlen((yyvsp[-4].id)) + 2 + strlen(struct_name) + 2 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-4].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), struct_name);
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");

		free(struct_name);
		free((yyvsp[-4].id));
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 3503 "grammar.tab.c"
    break;

  case 136: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 1233 "grammar.y"
        {
		// change the structure name.
		char * struct_name = (char *) malloc(3 + strlen((yyvsp[0].id)) + 1);
		if (islower((yyvsp[0].id)[0]))
			strcpy(struct_name, "lc_");
		else
			strcpy(struct_name, "uc_");
		strcat(struct_name, (yyvsp[0].id));

		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 2 + strlen(struct_name) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), struct_name);
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
		free(struct_name);
	}
#line 3525 "grammar.tab.c"
    break;

  case 137: /* struct_or_union: STRUCT  */
#line 1254 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "struct ");
	}
#line 3534 "grammar.tab.c"
    break;

  case 138: /* struct_or_union: UNION  */
#line 1259 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "union ");
	}
#line 3543 "grammar.tab.c"
    break;

  case 139: /* struct_declaration_list: struct_declaration  */
#line 1267 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3553 "grammar.tab.c"
    break;

  case 140: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 1273 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3566 "grammar.tab.c"
    break;

  case 142: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 1286 "grammar.y"
        {
		// Many variables declared in $2, they must be separated.
		if (strstr((yyvsp[-1].id), ",") != NULL)
		{
			char* struct_definition_string = seperate_fields((yyvsp[-2].id), (yyvsp[-1].id)); // STRUCTURES.H
			(yyval.id) = (char*) malloc(strlen(struct_definition_string) + 1);
			strcpy((yyval.id), struct_definition_string);
			free(struct_definition_string);
		}
		else
		// Build the structure list, removing the 'struct' keyword if present
		{
			char* struct_definition_string = strip_struct((yyvsp[-2].id)); // STRUCTURES.H
			(yyval.id) = (char*) malloc(2 + strlen((yyvsp[-1].id)) + 3 + strlen(struct_definition_string) + 1 + 1);
			strcpy((yyval.id), "([");
			strcat((yyval.id), (yyvsp[-1].id));
			strcat((yyval.id), "], ");
			strcpy((yyvsp[-2].id), struct_definition_string);
			strcat((yyval.id), (yyvsp[-2].id));
			strcat((yyval.id), ")");

			free(struct_definition_string);
		}
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
	}
#line 3597 "grammar.tab.c"
    break;

  case 144: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 1318 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
	}
#line 3607 "grammar.tab.c"
    break;

  case 145: /* specifier_qualifier_list: type_specifier  */
#line 1324 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3617 "grammar.tab.c"
    break;

  case 146: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 1330 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3629 "grammar.tab.c"
    break;

  case 147: /* specifier_qualifier_list: type_qualifier  */
#line 1338 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3639 "grammar.tab.c"
    break;

  case 148: /* struct_declarator_list: struct_declarator  */
#line 1347 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3650 "grammar.tab.c"
    break;

  case 149: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1354 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3664 "grammar.tab.c"
    break;

  case 150: /* struct_declarator: ':' constant_expression  */
#line 1367 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3675 "grammar.tab.c"
    break;

  case 151: /* struct_declarator: declarator ':' constant_expression  */
#line 1374 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3688 "grammar.tab.c"
    break;

  case 152: /* struct_declarator: declarator  */
#line 1383 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3698 "grammar.tab.c"
    break;

  case 153: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 1392 "grammar.y"
                {
		// Build enumeration list.
		// Pop Scope when '}' is parsed and reset enumerations counter
		(yyval.id) = (char*) malloc(7 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 			// SCOPES.H
		strcat((yyval.id), "]");
		reset_enumcounter(); 	// ENUM_FUNCTIONS.H
		free((yyvsp[-1].id));
	}
#line 3715 "grammar.tab.c"
    break;

  case 155: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 1406 "grammar.y"
        {
		// Build enumeration list.
		// Change their name to Prolog equivalent using change_enum()
		// Add the name to NAMES file using printnames()
		// Add the literal to Enum linked list using add_enums()
		// Pop Scope when '}' is parsed and reset enumerations counter

		char* enum_name = change_enum((yyvsp[-3].id)); // ENUM_FUNCTIONS.H

		(yyval.id) = (char*) malloc(7 + 1 + strlen(enum_name) + 1 + 2 + 1 + strlen((yyvsp[-1].id)) + 1 + 1);

		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), "[");
		strcat((yyval.id), enum_name);
		strcat((yyval.id), "]");
		strcat((yyval.id), ", ");
		strcat((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
		reset_enumcounter(); // ENUM_FUNCTIONS.H

		free(enum_name);
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 3746 "grammar.tab.c"
    break;

  case 157: /* enum_specifier: ENUM IDENTIFIER  */
#line 1434 "grammar.y"
        {
		// Change enum name to Prolog equivalent using change_enum()
		char* enum_name = change_enum((yyvsp[0].id)); // ENUM_FUNCTIONS.H
		(yyval.id) = (char*) malloc(7 + strlen(enum_name) + 1);
		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), enum_name);
		free((yyvsp[0].id));
		free(enum_name);
	}
#line 3760 "grammar.tab.c"
    break;

  case 158: /* enumerator_list: enumerator  */
#line 1447 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3770 "grammar.tab.c"
    break;

  case 159: /* enumerator_list: enumerator_list ',' enumerator  */
#line 1453 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3783 "grammar.tab.c"
    break;

  case 160: /* enumerator: enumeration_constant '=' constant_expression  */
#line 1466 "grammar.y"
        {
		/*
			Process enumeration literals with initializations:
			e.g. enum daYs {mon, tues, wed = 20, thurs, fri = 7};
			Change the enum name to Prolog equivalent using change_enum()
			Add the name to NAMES file using printnames()
			Add the literal to Enum linked list using add_enums(), with its enum value.
		*/
		char *enum_name = change_enum((yyvsp[-2].id)); // ENUM_FUNCTIONS.H

		int i = atoi((yyvsp[0].id)); // change string to integer

		(yyval.id) = (char*) malloc(strlen(enum_name) + 1);
		strcpy((yyval.id), enum_name);
		add_enums((yyvsp[-2].id), i); 			// ENUM_FUNCTIONS.H

		free(enum_name);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3808 "grammar.tab.c"
    break;

  case 161: /* enumerator: enumeration_constant  */
#line 1487 "grammar.y"
        {
		/*
			Process enumeration literals.
			Change their name to Prolog equivalent using change_enum()
			Add the name to NAMES file using printnames()
			Add the literal to Enum linked list using add_enums()
		*/
		char *enum_name = change_enum((yyvsp[0].id)); // ENUM_FUNCTIONS.H

		(yyval.id) = (char*) malloc(strlen(enum_name) + 1);
		strcpy((yyval.id), enum_name);
		add_enums((yyvsp[0].id), -1);			// ENUM_FUNCTIONS.H

		free(enum_name);
		free((yyvsp[0].id));
	}
#line 3829 "grammar.tab.c"
    break;

  case 163: /* type_qualifier: CONST  */
#line 1511 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5 + 1);
		strcpy((yyval.id), "const");
	}
#line 3838 "grammar.tab.c"
    break;

  case 164: /* type_qualifier: RESTRICT  */
#line 1516 "grammar.y"
        {
		(yyval.id) = (char*) malloc(8 + 1);
		strcpy((yyval.id), "restrict");
	}
#line 3847 "grammar.tab.c"
    break;

  case 165: /* type_qualifier: VOLATILE  */
#line 1521 "grammar.y"
        {
		(yyval.id) = (char*) malloc(8 + 1);
		strcpy((yyval.id), "volatile");
	}
#line 3856 "grammar.tab.c"
    break;

  case 166: /* type_qualifier: ATOMIC  */
#line 1526 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "atomic");
	}
#line 3865 "grammar.tab.c"
    break;

  case 172: /* declarator: pointer direct_declarator  */
#line 1545 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3877 "grammar.tab.c"
    break;

  case 173: /* declarator: direct_declarator  */
#line 1553 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3887 "grammar.tab.c"
    break;

  case 174: /* direct_declarator: IDENTIFIER  */
#line 1562 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3897 "grammar.tab.c"
    break;

  case 175: /* direct_declarator: '(' declarator ')'  */
#line 1568 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 3909 "grammar.tab.c"
    break;

  case 176: /* direct_declarator: direct_declarator '[' ']'  */
#line 1576 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "]");
		free((yyvsp[-2].id));
	}
#line 3921 "grammar.tab.c"
    break;

  case 177: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 1584 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
		free((yyvsp[-3].id));
	}
#line 3934 "grammar.tab.c"
    break;

  case 185: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 1600 "grammar.y"
        {
		/* 	function prototypes and definitions come through this rule.
			in order to distinguish them later on from variables we
			add the string "function_prototype" to $$
			if this is the function defintion this will have to be stripped later.
			if it is the function prototype it is left as it is.
		*/
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
#line 3960 "grammar.tab.c"
    break;

  case 186: /* direct_declarator: direct_declarator '(' ')'  */
#line 1622 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
	}
#line 3972 "grammar.tab.c"
    break;

  case 187: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 1630 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 3986 "grammar.tab.c"
    break;

  case 188: /* direct_declarator: vc_specific_modifier IDENTIFIER  */
#line 1640 "grammar.y"
        {
		// Visual C extension
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3998 "grammar.tab.c"
    break;

  case 189: /* direct_declarator: '(' vc_specific_modifier IDENTIFIER ')'  */
#line 1648 "grammar.y"
        {
		// Visual C extension
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
	}
#line 4010 "grammar.tab.c"
    break;

  case 190: /* vc_specific_modifier: __CDECL  */
#line 1659 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4019 "grammar.tab.c"
    break;

  case 191: /* vc_specific_modifier: __CLRCALL  */
#line 1664 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4028 "grammar.tab.c"
    break;

  case 192: /* vc_specific_modifier: __STDCALL  */
#line 1669 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4037 "grammar.tab.c"
    break;

  case 193: /* vc_specific_modifier: __FASTCALL  */
#line 1674 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4046 "grammar.tab.c"
    break;

  case 194: /* vc_specific_modifier: __THISCALL  */
#line 1679 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4055 "grammar.tab.c"
    break;

  case 195: /* vc_specific_modifier: __VECTORCALL  */
#line 1684 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4064 "grammar.tab.c"
    break;

  case 196: /* pointer: '*' type_qualifier_list pointer  */
#line 1692 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
	}
#line 4076 "grammar.tab.c"
    break;

  case 197: /* pointer: '*' type_qualifier_list  */
#line 1700 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4087 "grammar.tab.c"
    break;

  case 198: /* pointer: '*' pointer  */
#line 1707 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4098 "grammar.tab.c"
    break;

  case 199: /* pointer: '*'  */
#line 1714 "grammar.y"
        {
		(yyval.id) = (char*) malloc(2);
		strcpy((yyval.id), "*");
	}
#line 4107 "grammar.tab.c"
    break;

  case 200: /* type_qualifier_list: type_qualifier  */
#line 1722 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4117 "grammar.tab.c"
    break;

  case 201: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1728 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4129 "grammar.tab.c"
    break;

  case 202: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1740 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 3 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), "...");
		free((yyvsp[-2].id));
	}
#line 4141 "grammar.tab.c"
    break;

  case 203: /* parameter_type_list: parameter_list  */
#line 1748 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		int lenSS = strlen((yyvsp[0].id)) - 1;
		if ((yyvsp[0].id)[lenSS] == ',')
			(yyvsp[0].id)[lenSS] = ' ';
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4154 "grammar.tab.c"
    break;

  case 204: /* parameter_list: parameter_declaration  */
#line 1760 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4164 "grammar.tab.c"
    break;

  case 205: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1766 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4176 "grammar.tab.c"
    break;

  case 206: /* parameter_declaration: declaration_specifiers declarator  */
#line 1777 "grammar.y"
        {
		if (PListFirstUse == NO)	// PARAMETERS.H
		{
			PListFirstUse = YES;	// PARAMETERS.H
			P = CreatePList();	// PARAMETERS.H
		}
		PushPList((yyvsp[0].id), P);		// PARAMETERS.H
		Push(yylineno);	// SCOPES.H
		addvariables((yyvsp[0].id), YES);			// DECL_FUNCTIONS.H
		char* declaration_string = findvariabledetails((yyvsp[-1].id)); // DECL_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(declaration_string) + 1);
		strcpy((yyval.id), declaration_string);
		free(declaration_string);
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4197 "grammar.tab.c"
    break;

  case 207: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1794 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4209 "grammar.tab.c"
    break;

  case 208: /* parameter_declaration: declaration_specifiers  */
#line 1802 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4219 "grammar.tab.c"
    break;

  case 209: /* identifier_list: IDENTIFIER  */
#line 1811 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4229 "grammar.tab.c"
    break;

  case 210: /* identifier_list: identifier_list ',' IDENTIFIER  */
#line 1817 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4242 "grammar.tab.c"
    break;

  case 211: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 1829 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4254 "grammar.tab.c"
    break;

  case 212: /* type_name: specifier_qualifier_list  */
#line 1837 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4264 "grammar.tab.c"
    break;

  case 213: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 1846 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4276 "grammar.tab.c"
    break;

  case 214: /* abstract_declarator: pointer  */
#line 1854 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4286 "grammar.tab.c"
    break;

  case 215: /* abstract_declarator: direct_abstract_declarator  */
#line 1860 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4296 "grammar.tab.c"
    break;

  case 216: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 1869 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4308 "grammar.tab.c"
    break;

  case 217: /* direct_abstract_declarator: '[' ']'  */
#line 1877 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), "]");
	}
#line 4318 "grammar.tab.c"
    break;

  case 218: /* direct_abstract_declarator: '[' '*' ']'  */
#line 1883 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
	}
#line 4329 "grammar.tab.c"
    break;

  case 225: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 1896 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "]");
		free((yyvsp[-2].id));
	}
#line 4341 "grammar.tab.c"
    break;

  case 226: /* direct_abstract_declarator: direct_abstract_declarator '[' '*' ']'  */
#line 1904 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
		free((yyvsp[-3].id));
	}
#line 4354 "grammar.tab.c"
    break;

  case 233: /* direct_abstract_declarator: '(' ')'  */
#line 1919 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), ")");
	}
#line 4364 "grammar.tab.c"
    break;

  case 234: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 1925 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4376 "grammar.tab.c"
    break;

  case 235: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 1933 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
	}
#line 4388 "grammar.tab.c"
    break;

  case 236: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 1941 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4402 "grammar.tab.c"
    break;

  case 237: /* initializer: '{' initializer_list '}'  */
#line 1954 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");

		free((yyvsp[-1].id));
	}
#line 4416 "grammar.tab.c"
    break;

  case 238: /* initializer: '{' initializer_list ',' '}'  */
#line 1964 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), "{");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "}");

		free((yyvsp[-2].id));
	}
#line 4431 "grammar.tab.c"
    break;

  case 239: /* initializer: assignment_expression  */
#line 1975 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4441 "grammar.tab.c"
    break;

  case 240: /* initializer_list: designation initializer  */
#line 1984 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4454 "grammar.tab.c"
    break;

  case 241: /* initializer_list: initializer  */
#line 1993 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4464 "grammar.tab.c"
    break;

  case 244: /* designation: designator_list '='  */
#line 2004 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "=");
		free((yyvsp[-1].id));
	}
#line 4475 "grammar.tab.c"
    break;

  case 245: /* designator_list: designator  */
#line 2014 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4485 "grammar.tab.c"
    break;

  case 246: /* designator_list: designator_list designator  */
#line 2020 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4497 "grammar.tab.c"
    break;

  case 247: /* designator: '[' constant_expression ']'  */
#line 2031 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "]");
		free((yyvsp[-1].id));
	}
#line 4509 "grammar.tab.c"
    break;

  case 248: /* designator: '.' IDENTIFIER  */
#line 2039 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "access(");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[0].id));
	}
#line 4521 "grammar.tab.c"
    break;

  case 250: /* statement: labeled_statement  */
#line 2054 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4531 "grammar.tab.c"
    break;

  case 251: /* statement: compound_statement  */
#line 2060 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4541 "grammar.tab.c"
    break;

  case 252: /* statement: expression_statement  */
#line 2066 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4551 "grammar.tab.c"
    break;

  case 253: /* statement: selection_statement  */
#line 2072 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4561 "grammar.tab.c"
    break;

  case 254: /* statement: iteration_statement  */
#line 2078 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4571 "grammar.tab.c"
    break;

  case 255: /* statement: jump_statement  */
#line 2084 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4581 "grammar.tab.c"
    break;

  case 256: /* labeled_statement: IDENTIFIER ':' statement  */
#line 2093 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
	}
#line 4593 "grammar.tab.c"
    break;

  case 257: /* labeled_statement: CASE constant_expression ':' statement  */
#line 2101 "grammar.y"
        {
		char* case_string = case_statement((yyvsp[-2].id), (yyvsp[0].id)); // SWITCH_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(case_string) + 1);
		strcpy((yyval.id), case_string);
		free(case_string);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4606 "grammar.tab.c"
    break;

  case 258: /* labeled_statement: DEFAULT ':' statement  */
#line 2110 "grammar.y"
        {
		char* default_string = default_statement((yyvsp[0].id)); // SWITCH_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(default_string) + 1);
		strcpy((yyval.id), default_string);
		free(default_string);
		free((yyvsp[0].id));
	}
#line 4618 "grammar.tab.c"
    break;

  case 259: /* compound_statement: '{' '}'  */
#line 2121 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "[");
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 4629 "grammar.tab.c"
    break;

  case 260: /* compound_statement: '{' block_item_list '}'  */
#line 2128 "grammar.y"
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
#line 4647 "grammar.tab.c"
    break;

  case 261: /* block_item_list: block_item  */
#line 2145 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4657 "grammar.tab.c"
    break;

  case 262: /* block_item_list: block_item_list block_item  */
#line 2151 "grammar.y"
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
#line 4674 "grammar.tab.c"
    break;

  case 263: /* block_item: declaration  */
#line 2167 "grammar.y"
        {

		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4685 "grammar.tab.c"
    break;

  case 264: /* block_item: statement  */
#line 2174 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4695 "grammar.tab.c"
    break;

  case 265: /* expression_statement: ';'  */
#line 2183 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "null");
	}
#line 4704 "grammar.tab.c"
    break;

  case 266: /* expression_statement: expression ';'  */
#line 2188 "grammar.y"
        {
		(yyval.id) = (char*) malloc(21 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "expression_statement(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4716 "grammar.tab.c"
    break;

  case 267: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 2199 "grammar.y"
        {
		char* if_else_statement_definition = ifelse_statement((yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id)); // IF_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(if_else_statement_definition) + 1);
		strcpy((yyval.id), if_else_statement_definition);
		free(if_else_statement_definition);
		free((yyvsp[-4].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4730 "grammar.tab.c"
    break;

  case 268: /* selection_statement: IF '(' expression ')' statement  */
#line 2209 "grammar.y"
        {
		char* if_statement_definition = if_statement((yyvsp[-2].id), (yyvsp[0].id)); // IF_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(if_statement_definition) + 1);
		strcpy((yyval.id), if_statement_definition);
		free(if_statement_definition);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4743 "grammar.tab.c"
    break;

  case 269: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 2218 "grammar.y"
        {
		char* switch_statement_definition = switch_statement((yyvsp[-2].id), (yyvsp[0].id)); // SWITCH_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(switch_statement_definition) + 1);
		strcpy((yyval.id), switch_statement_definition);
		free(switch_statement_definition);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4756 "grammar.tab.c"
    break;

  case 270: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 2230 "grammar.y"
        {
		char* while_statement_definition = while_statement((yyvsp[-2].id), (yyvsp[0].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(while_statement_definition) + 1);
		strcpy((yyval.id), while_statement_definition);
		free(while_statement_definition);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4769 "grammar.tab.c"
    break;

  case 271: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 2239 "grammar.y"
        {
		char* do_statement_definition = do_statement((yyvsp[-5].id), (yyvsp[-2].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(do_statement_definition) + 1);
		strcpy((yyval.id), do_statement_definition);
		free(do_statement_definition);
		free((yyvsp[-5].id));
		free((yyvsp[-2].id));
	}
#line 4782 "grammar.tab.c"
    break;

  case 272: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 2248 "grammar.y"
        {
		char* for_statement_definition = for2_statement((yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[0].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(for_statement_definition) + 1);
		strcpy((yyval.id), for_statement_definition);
		free(for_statement_definition);
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4796 "grammar.tab.c"
    break;

  case 273: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 2258 "grammar.y"
        {
		char* for_statement_definition = for_statement((yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[0].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(for_statement_definition) + 1);
		strcpy((yyval.id), for_statement_definition);
		free(for_statement_definition);
		free((yyvsp[-4].id));
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4811 "grammar.tab.c"
    break;

  case 276: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 2274 "grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "goto");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ";");
		free((yyvsp[-1].id));
	}
#line 4823 "grammar.tab.c"
    break;

  case 277: /* jump_statement: CONTINUE ';'  */
#line 2282 "grammar.y"
        {
		(yyval.id) = (char*) malloc(8 + 1);
		strcpy((yyval.id), "continue");
	}
#line 4832 "grammar.tab.c"
    break;

  case 278: /* jump_statement: BREAK ';'  */
#line 2287 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5 + 1);
		strcpy((yyval.id), "break");
	}
#line 4841 "grammar.tab.c"
    break;

  case 279: /* jump_statement: RETURN ';'  */
#line 2292 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "return");
	}
#line 4850 "grammar.tab.c"
    break;

  case 280: /* jump_statement: RETURN expression ';'  */
#line 2297 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "return(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4862 "grammar.tab.c"
    break;

  case 281: /* translation_unit: external_declaration  */
#line 2308 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4872 "grammar.tab.c"
    break;

  case 282: /* translation_unit: translation_unit external_declaration  */
#line 2314 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4884 "grammar.tab.c"
    break;

  case 283: /* external_declaration: function_definition  */
#line 2325 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		printfunction((yyval.id)); 	// OUTPUT_FUNCTIONS.H
		free((yyvsp[0].id));
	}
#line 4895 "grammar.tab.c"
    break;

  case 284: /* external_declaration: declaration  */
#line 2332 "grammar.y"
        {
		// Global Variable declarations
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
#line 4913 "grammar.tab.c"
    break;

  case 285: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 2349 "grammar.y"
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
#line 4929 "grammar.tab.c"
    break;

  case 286: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 2361 "grammar.y"
        {
		// Function Defintions
		char* function = process_functions((yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].id));
		(yyval.id) = (char*) malloc(strlen(function) + 1);
		strcpy((yyval.id), function);	// DECL_FUNCTIONS.H
		free(function);
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4944 "grammar.tab.c"
    break;

  case 287: /* declaration_list: declaration  */
#line 2375 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4954 "grammar.tab.c"
    break;

  case 288: /* declaration_list: declaration_list declaration  */
#line 2381 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4966 "grammar.tab.c"
    break;


#line 4970 "grammar.tab.c"

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

#line 2390 "grammar.y"

#include <stdio.h>
#include "lex.yy.c"
