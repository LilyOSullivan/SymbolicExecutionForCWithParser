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
  YYSYMBOL_CASE = 61,                      /* CASE  */
  YYSYMBOL_DEFAULT = 62,                   /* DEFAULT  */
  YYSYMBOL_IF = 63,                        /* IF  */
  YYSYMBOL_ELSE = 64,                      /* ELSE  */
  YYSYMBOL_SWITCH = 65,                    /* SWITCH  */
  YYSYMBOL_WHILE = 66,                     /* WHILE  */
  YYSYMBOL_DO = 67,                        /* DO  */
  YYSYMBOL_FOR = 68,                       /* FOR  */
  YYSYMBOL_GOTO = 69,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 70,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 71,                     /* BREAK  */
  YYSYMBOL_RETURN = 72,                    /* RETURN  */
  YYSYMBOL_ALIGNAS = 73,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 74,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 75,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 76,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 77,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 78,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 79,              /* THREAD_LOCAL  */
  YYSYMBOL___CDECL = 80,                   /* __CDECL  */
  YYSYMBOL___CLRCALL = 81,                 /* __CLRCALL  */
  YYSYMBOL___STDCALL = 82,                 /* __STDCALL  */
  YYSYMBOL___FASTCALL = 83,                /* __FASTCALL  */
  YYSYMBOL___THISCALL = 84,                /* __THISCALL  */
  YYSYMBOL___VECTORCALL = 85,              /* __VECTORCALL  */
  YYSYMBOL_86_ = 86,                       /* '('  */
  YYSYMBOL_87_ = 87,                       /* ')'  */
  YYSYMBOL_88_ = 88,                       /* ','  */
  YYSYMBOL_89_ = 89,                       /* ':'  */
  YYSYMBOL_90_ = 90,                       /* '['  */
  YYSYMBOL_91_ = 91,                       /* ']'  */
  YYSYMBOL_92_ = 92,                       /* '.'  */
  YYSYMBOL_93_ = 93,                       /* '{'  */
  YYSYMBOL_94_ = 94,                       /* '}'  */
  YYSYMBOL_95_ = 95,                       /* '&'  */
  YYSYMBOL_96_ = 96,                       /* '*'  */
  YYSYMBOL_97_ = 97,                       /* '+'  */
  YYSYMBOL_98_ = 98,                       /* '-'  */
  YYSYMBOL_99_ = 99,                       /* '~'  */
  YYSYMBOL_100_ = 100,                     /* '!'  */
  YYSYMBOL_101_ = 101,                     /* '/'  */
  YYSYMBOL_102_ = 102,                     /* '%'  */
  YYSYMBOL_103_ = 103,                     /* '<'  */
  YYSYMBOL_104_ = 104,                     /* '>'  */
  YYSYMBOL_105_ = 105,                     /* '^'  */
  YYSYMBOL_106_ = 106,                     /* '|'  */
  YYSYMBOL_107_ = 107,                     /* '?'  */
  YYSYMBOL_108_ = 108,                     /* '='  */
  YYSYMBOL_109_ = 109,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 110,                 /* $accept  */
  YYSYMBOL_primary_expression = 111,       /* primary_expression  */
  YYSYMBOL_constant = 112,                 /* constant  */
  YYSYMBOL_enumeration_constant = 113,     /* enumeration_constant  */
  YYSYMBOL_string = 114,                   /* string  */
  YYSYMBOL_generic_selection = 115,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 116,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 117,      /* generic_association  */
  YYSYMBOL_postfix_expression = 118,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 119, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 120,         /* unary_expression  */
  YYSYMBOL_unary_operator = 121,           /* unary_operator  */
  YYSYMBOL_cast_expression = 122,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 123, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 124,      /* additive_expression  */
  YYSYMBOL_shift_expression = 125,         /* shift_expression  */
  YYSYMBOL_relational_expression = 126,    /* relational_expression  */
  YYSYMBOL_equality_expression = 127,      /* equality_expression  */
  YYSYMBOL_and_expression = 128,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 129,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 130,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 131,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 132,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 133,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 134,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 135,      /* assignment_operator  */
  YYSYMBOL_expression = 136,               /* expression  */
  YYSYMBOL_constant_expression = 137,      /* constant_expression  */
  YYSYMBOL_declaration = 138,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 139,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 140,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 141,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 142,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 143,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 144, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 145,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 146,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 147,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 148, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 149,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 150,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 151,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 152,          /* enumerator_list  */
  YYSYMBOL_enumerator = 153,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 154,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 155,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 156,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 157,      /* alignment_specifier  */
  YYSYMBOL_declarator = 158,               /* declarator  */
  YYSYMBOL_direct_declarator = 159,        /* direct_declarator  */
  YYSYMBOL_vc_specific_modifier = 160,     /* vc_specific_modifier  */
  YYSYMBOL_pointer = 161,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 162,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 163,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 164,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 165,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 166,          /* identifier_list  */
  YYSYMBOL_type_name = 167,                /* type_name  */
  YYSYMBOL_abstract_declarator = 168,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 169, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 170,              /* initializer  */
  YYSYMBOL_initializer_list = 171,         /* initializer_list  */
  YYSYMBOL_designation = 172,              /* designation  */
  YYSYMBOL_designator_list = 173,          /* designator_list  */
  YYSYMBOL_designator = 174,               /* designator  */
  YYSYMBOL_static_assert_declaration = 175, /* static_assert_declaration  */
  YYSYMBOL_statement = 176,                /* statement  */
  YYSYMBOL_labeled_statement = 177,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 178,       /* compound_statement  */
  YYSYMBOL_block_item_list = 179,          /* block_item_list  */
  YYSYMBOL_block_item = 180,               /* block_item  */
  YYSYMBOL_expression_statement = 181,     /* expression_statement  */
  YYSYMBOL_selection_statement = 182,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 183,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 184,           /* jump_statement  */
  YYSYMBOL_translation_unit = 185,         /* translation_unit  */
  YYSYMBOL_external_declaration = 186,     /* external_declaration  */
  YYSYMBOL_function_definition = 187,      /* function_definition  */
  YYSYMBOL_declaration_list = 188          /* declaration_list  */
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
#define YYFINAL  78
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2484

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  110
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  287
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  495

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   340


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
       2,     2,     2,   100,     2,     2,     2,   102,    95,     2,
      86,    87,    96,    97,    88,    98,    92,   101,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    89,   109,
     103,   108,   104,   107,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    90,     2,    91,   105,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    93,   106,    94,    99,     2,     2,     2,
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
      85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   134,   141,   147,   155,   159,   165,   171,
     182,   191,   197,   206,   210,   211,   215,   216,   220,   226,
     246,   270,   296,   306,   321,   350,   363,   364,   368,   374,
     386,   392,   405,   417,   427,   444,   456,   460,   466,   471,
     477,   482,   487,   495,   513,   530,   536,   551,   560,   579,
     585,   594,   606,   612,   621,   633,   639,   648,   657,   666,
     679,   685,   694,   706,   712,   724,   730,   742,   748,   760,
     766,   780,   786,   800,   806,   831,   837,   852,   857,   862,
     867,   872,   877,   882,   887,   892,   897,   902,   910,   916,
     928,   937,   948,   970,   974,   982,   988,  1010,  1016,  1022,
    1028,  1029,  1030,  1031,  1035,  1041,  1053,  1059,  1080,  1086,
    1091,  1096,  1097,  1102,  1110,  1115,  1120,  1125,  1130,  1135,
    1140,  1145,  1150,  1155,  1160,  1165,  1170,  1171,  1177,  1183,
    1191,  1196,  1201,  1206,  1214,  1223,  1247,  1270,  1275,  1283,
    1289,  1301,  1302,  1328,  1332,  1338,  1344,  1352,  1361,  1368,
    1381,  1388,  1397,  1406,  1419,  1420,  1450,  1451,  1463,  1469,
    1482,  1507,  1531,  1535,  1540,  1545,  1550,  1558,  1559,  1563,
    1564,  1568,  1576,  1585,  1591,  1599,  1607,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1647,  1655,  1665,  1673,  1684,
    1689,  1694,  1699,  1704,  1709,  1717,  1725,  1732,  1739,  1747,
    1753,  1765,  1773,  1785,  1791,  1802,  1817,  1825,  1834,  1840,
    1852,  1860,  1869,  1877,  1883,  1892,  1900,  1906,  1913,  1914,
    1915,  1916,  1917,  1918,  1919,  1927,  1936,  1937,  1938,  1939,
    1940,  1941,  1942,  1948,  1956,  1964,  1977,  1985,  1995,  2004,
    2013,  2019,  2020,  2024,  2034,  2040,  2051,  2059,  2070,  2074,
    2080,  2086,  2092,  2098,  2104,  2113,  2121,  2128,  2137,  2144,
    2161,  2167,  2183,  2190,  2199,  2204,  2215,  2223,  2230,  2240,
    2249,  2258,  2268,  2279,  2280,  2284,  2292,  2297,  2302,  2307,
    2318,  2324,  2335,  2342,  2360,  2372,  2388,  2394
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
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT",
  "THREAD_LOCAL", "__CDECL", "__CLRCALL", "__STDCALL", "__FASTCALL",
  "__THISCALL", "__VECTORCALL", "'('", "')'", "','", "':'", "'['", "']'",
  "'.'", "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept",
  "primary_expression", "constant", "enumeration_constant", "string",
  "generic_selection", "generic_assoc_list", "generic_association",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
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
     335,   336,   337,   338,   339,   340,    40,    41,    44,    58,
      91,    93,    46,   123,   125,    38,    42,    43,    45,   126,
      33,    47,    37,    60,    62,    94,   124,    63,    61,    59
};
#endif

#define YYPACT_NINF (-380)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2190,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,    31,
     -65,   -39,  -380,   -37,  -380,  -380,   342,  2288,  2288,  -380,
      42,  -380,  -380,  2288,  2288,  2288,  -380,  1823,  -380,  -380,
     -21,    26,   903,  2409,  1513,  -380,  -380,  -380,  -380,  -380,
    -380,  -380,   793,   258,  -380,   -63,  -380,  1873,     8,    66,
     148,  -380,  -380,   -19,  2330,  -380,  -380,  -380,  -380,  -380,
      26,  -380,   -22,    69,  -380,  -380,  -380,  -380,  -380,  -380,
    1611,  1626,  1626,  -380,     3,     5,   903,  -380,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,    56,  -380,  1513,
    -380,    53,   -57,   190,    28,   219,     6,    47,    12,   146,
      33,  -380,    79,  2409,    57,  2409,   102,   108,    92,   111,
     201,  -380,  -380,  -380,   258,   793,  -380,   572,  1482,  -380,
     342,  -380,  2072,  1763,   977,  -380,     8,  2330,  1620,  -380,
     291,  -380,    90,  1513,    25,  -380,   903,  -380,   903,  -380,
    -380,  2409,  1513,   665,  -380,  -380,   119,   140,   214,  -380,
    -380,   962,  1513,   238,  -380,  1513,  1513,  1513,  1513,  1513,
    1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,  1513,
    1513,  1513,  1513,  1513,  -380,  -380,  1950,  1016,    17,  -380,
      89,  -380,  -380,  -380,   261,  -380,   177,  -380,  -380,  -380,
     161,   187,  1513,   194,   188,   199,   203,   464,   207,   296,
     216,   217,   387,  -380,  -380,   -56,  -380,  -380,  -380,  -380,
     672,  -380,  -380,  -380,  -380,  -380,  1467,  -380,  -380,  -380,
    -380,  -380,  -380,   418,   215,   241,  -380,   175,  1316,  -380,
     243,   244,  1090,  2009,  -380,  -380,  1513,  -380,   -55,  -380,
     257,    27,  -380,  -380,  -380,  -380,   260,   262,   263,   267,
    -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,
    -380,  1513,  -380,  1513,  1497,  -380,  -380,   185,  -380,   -27,
    -380,  -380,  -380,  -380,    53,    53,   -57,   -57,   190,   190,
     190,   190,    28,    28,   219,     6,    47,    12,   146,   193,
    -380,   264,   270,  1316,  -380,   269,   274,  1129,    89,  2134,
    1203,   279,  -380,   464,   259,   464,  1513,  1513,  1513,   301,
     772,   273,  -380,  -380,  -380,   -50,  -380,  -380,  -380,  1513,
     365,  -380,    93,  1482,   -53,  -380,  1698,  -380,   130,  -380,
    -380,  2240,  -380,   367,   287,  1316,  -380,  -380,  1513,  -380,
     288,   292,  -380,  -380,    87,  -380,  1513,  -380,   295,   295,
    -380,  2371,  -380,  -380,  1467,  -380,  -380,  1513,  -380,  1513,
    -380,  -380,   293,  1316,  -380,  -380,  1513,  -380,   298,  -380,
     309,  1316,  -380,   308,   310,  1242,   294,  -380,   464,  -380,
     191,   200,   204,   316,   829,   829,  -380,  -380,   313,  -380,
    1354,  -380,  -380,  -380,  -380,  -380,  -380,  -380,  -380,   314,
     315,  -380,  -380,  -380,  -380,   320,   218,  -380,   321,   100,
    -380,  -380,  -380,   322,   324,  -380,  -380,   326,  1316,  -380,
    -380,  1513,  -380,   328,  -380,  -380,   464,   464,   464,  1513,
    1075,  1188,  -380,  -380,  -380,  1482,  -380,  -380,  1513,  -380,
    2371,  1513,  1369,  -380,  -380,  -380,  -380,   329,   338,  -380,
     347,  -380,  -380,   220,   464,   223,   464,   225,  -380,  -380,
    -380,  -380,  -380,  -380,  -380,   464,   323,  -380,   464,  -380,
     464,  -380,  -380,  -380,  -380
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   129,   108,   109,   110,   112,   113,   167,   163,   164,
     165,   123,   115,   116,   117,   118,   121,   122,   119,   120,
     114,   130,   131,   132,   133,   124,   125,   137,   138,     0,
       0,   166,   168,     0,   111,   283,     0,    95,    97,   127,
       0,   128,   126,    99,   101,   103,    93,     0,   280,   282,
     157,     0,     0,     0,     0,   173,   189,   190,   191,   192,
     193,   194,     0,   198,    91,     0,   104,   107,   172,     0,
       0,    94,    96,   136,     0,    98,   100,   102,     1,   281,
       0,    10,   161,     0,   158,     2,     7,     8,    11,    12,
       0,     0,     0,     9,     0,     0,     0,    37,    38,    39,
      40,    41,    42,    18,     3,     4,     6,    30,    43,     0,
      45,    49,    52,    55,    60,    63,    65,    67,    69,    71,
      73,    90,     0,   145,   211,   147,     0,     0,     0,     0,
       0,   166,   199,   197,   196,     0,    92,     0,     0,   286,
       0,   285,     0,     0,     0,   187,   171,     0,     0,   139,
       0,   143,     0,     0,     0,   153,     0,    34,     0,    31,
      32,     0,     0,    43,    75,    88,     0,     0,     0,    24,
      25,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   170,   144,     0,     0,   213,   210,
     214,   146,   169,   162,     0,   174,   187,   200,   195,   105,
     107,     2,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   264,     0,   262,   263,   249,   250,
       0,   260,   251,   252,   253,   254,     0,   238,   106,   287,
     284,   208,   185,   207,     0,   202,   203,     0,     0,   175,
      38,     0,     0,     0,   134,   140,     0,   141,     0,   148,
     152,     0,   155,   160,   154,   159,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      77,     0,     5,     0,     0,    23,    20,     0,    28,     0,
      22,    46,    47,    48,    50,    51,    53,    54,    58,    59,
      56,    57,    61,    62,    64,    66,    68,    70,    72,     0,
     232,     0,     0,     0,   216,    38,     0,     0,   212,     0,
       0,     0,   188,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   276,   277,   278,     0,   265,   259,   261,     0,
       0,   240,     0,     0,     0,   244,     0,   205,   213,   206,
     184,     0,   186,     0,     0,     0,   176,   183,     0,   182,
      38,     0,   135,   150,     0,   142,     0,   156,    35,     0,
      36,     0,    76,    89,     0,    44,    21,     0,    19,     0,
     233,   215,     0,     0,   217,   223,     0,   222,     0,   234,
       0,     0,   224,    38,     0,     0,     0,   255,     0,   257,
       0,     0,     0,     0,     0,     0,   275,   279,     0,   247,
       0,   236,   239,   243,   245,   201,   204,   209,   178,     0,
       0,   179,   181,   149,   151,     0,     0,    14,     0,     0,
      29,    74,   219,     0,     0,   221,   235,     0,     0,   225,
     231,     0,   230,     0,   248,   256,     0,     0,     0,     0,
       0,     0,   246,   237,   242,     0,   177,   180,     0,    13,
       0,     0,     0,    26,   218,   220,   227,     0,     0,   228,
     267,   268,   269,     0,     0,     0,     0,     0,   241,    17,
      15,    16,    27,   226,   229,     0,     0,   273,     0,   271,
       0,   266,   270,   274,   272
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -380,  -380,  -380,  -380,  -380,  -380,  -380,   -29,  -380,  -380,
      68,  -380,   -47,   139,   141,    40,   151,   242,   246,   247,
     245,   248,  -380,   -38,   133,  -380,   -88,   -30,   -40,    13,
    -380,   304,  -380,   -48,  -380,  -380,   286,  -128,   -11,  -380,
      77,  -380,   362,  -144,  -380,   -52,  -380,  -380,   -24,   -64,
     -60,   -46,  -121,  -134,  -380,    94,  -380,   -17,  -105,  -183,
    -135,    70,  -379,  -380,    99,   -67,  -132,  -380,   -49,  -380,
     222,  -243,  -380,  -380,  -380,  -380,   401,  -380,  -380
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   103,   104,    82,   105,   106,   426,   427,   107,   287,
     163,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   164,   165,   281,   225,   122,    35,   140,
      65,    66,    37,    38,    39,    40,   148,   149,   124,   258,
     259,    41,    83,    84,    42,    43,    44,    45,   129,    68,
      69,    70,   134,   311,   245,   246,   247,   428,   312,   200,
     341,   342,   343,   344,   345,    46,   227,   228,   229,   230,
     231,   232,   233,   234,   235,    47,    48,    49,   142
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     125,   125,   130,   238,   123,   123,   146,   151,   166,   244,
     265,   132,    67,    36,   121,   318,   121,   133,   141,   199,
     255,    52,   125,   252,   128,   135,   123,   139,    81,    81,
      81,   455,   283,   364,    50,   126,   127,   339,   283,   340,
     178,   179,   182,   183,   125,    73,   136,    53,   123,    54,
      71,    72,   192,   336,   365,   413,    75,    76,    77,   407,
      36,   283,   174,   150,   378,   168,   169,   170,   166,   145,
     166,   125,    80,   125,   147,   123,   317,   123,   198,   167,
     151,   151,   207,   455,   289,   329,   153,   405,   208,   161,
      55,   162,   132,   240,   143,   125,   125,   226,   144,   123,
     123,   188,   239,   196,   125,   309,   125,   197,   123,   125,
     123,   210,   195,   123,   201,   121,   210,   265,   190,   264,
     108,   367,   108,   263,    51,   255,   260,   355,   291,   292,
     293,   184,   185,    55,   335,    74,   150,   150,   349,   266,
     193,   267,   171,   196,   268,   132,   172,   197,   173,   175,
     198,    55,   189,    63,   176,   177,   243,   154,   157,   159,
     160,   450,   451,   155,   191,   318,   194,    56,    57,    58,
      59,    60,    61,    62,   121,   319,   256,   108,   261,   320,
     204,   410,   324,    63,   262,   390,   151,   411,   462,   202,
     226,   397,   383,   399,   463,   203,   132,   348,   205,   395,
     207,   125,   180,   181,   206,   123,   282,   283,   412,   243,
      56,    57,    58,    59,    60,    61,   346,   285,   121,   347,
     197,   108,   298,   299,   300,   301,   363,   284,    56,    57,
      58,    59,    60,    61,    62,   186,   187,   375,   400,   401,
     402,   290,   150,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   132,   352,   353,   322,   207,   445,   321,   132,   138,
     438,   237,   376,   377,   326,   454,   323,   251,   446,   283,
     108,   283,   379,   325,   146,   327,   130,   447,   283,   328,
     404,   448,   283,   330,    55,   269,     8,     9,    10,   331,
     348,   121,   350,   207,   288,   459,   460,   486,   283,   408,
     488,   283,   490,   283,   470,   471,   472,   294,   295,   125,
     478,   296,   297,   123,   108,   332,   333,   454,   121,   351,
     316,   207,   243,   131,   356,   357,   424,   302,   303,   132,
     260,   431,   487,   207,   489,    55,   366,   368,   398,   369,
     370,   380,   108,   491,    63,   371,   493,   381,   494,   243,
     384,   473,   475,   477,   243,   385,   396,   403,   409,   237,
     417,    56,    57,    58,    59,    60,    61,    62,   418,   421,
     256,   354,   406,   422,   432,   361,   207,    63,   374,   435,
      85,    86,    87,    88,    89,    90,   436,    91,    92,   439,
     257,   440,   449,   444,   452,   456,   457,   108,   125,   458,
     461,   485,   123,   464,   372,   465,   373,   466,    93,   469,
     483,    55,    56,    57,    58,    59,    60,    61,    62,   484,
     304,   480,   492,   253,   108,   305,   307,   306,    63,   209,
     308,   423,   152,   414,   429,   416,   382,   108,    79,     0,
     388,    64,   338,   394,     0,     0,     0,     0,     0,     0,
       0,    94,     0,    95,     0,     0,     0,   211,    86,    87,
      88,    89,    90,    96,    91,    92,   237,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,   419,     0,
       0,   420,     0,     0,     0,    93,   334,     0,    56,    57,
      58,    59,    60,    61,   346,     0,     0,   237,   197,     0,
     430,     0,     0,     0,    63,     0,   433,     0,     0,   434,
       0,     0,     0,     0,   437,   212,   213,   214,   443,   215,
     216,   217,   218,   219,   220,   221,   222,     0,    94,     0,
      95,     0,     0,   237,     0,     0,     0,     0,     0,     0,
      96,     0,     0,     0,     0,     0,     0,   137,     0,    97,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   467,     0,   224,   468,   211,    86,    87,    88,    89,
      90,     0,    91,    92,     0,     0,     0,     0,   237,     0,
       0,   479,     0,     0,   481,   237,     0,     0,     0,     0,
       0,     0,     1,    93,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,   212,   213,   214,     0,   215,   216,   217,
     218,   219,   220,   221,   222,    30,    94,    31,    95,    32,
      33,    34,     0,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,   137,   223,    97,    98,    99,
     100,   101,   102,     0,     0,   211,    86,    87,    88,    89,
      90,   224,    91,    92,     0,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,     0,     0,     0,     0,     0,
       0,     0,     1,    93,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,   212,   213,   214,     0,   215,   216,   217,
     218,   219,   220,   221,   222,    30,    94,    31,    95,    32,
      33,    34,     0,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,   137,   337,    97,    98,    99,
     100,   101,   102,   280,     0,    85,    86,    87,    88,    89,
      90,   224,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,     0,     0,     0,
       0,     0,     1,    93,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    85,    86,    87,    88,    89,    90,     0,    91,
      92,     0,     0,     0,     0,    30,    94,    31,    95,    32,
      33,    34,     0,     0,     0,     0,     0,     0,    96,     0,
      93,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,    56,    57,    58,    59,    60,    61,    62,
       0,   224,     0,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,    95,    85,    86,    87,    88,
      89,    90,     0,    91,    92,    96,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     1,    93,     0,     0,     0,   224,     0,
       0,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,     0,    85,    86,    87,    88,    89,
      90,     0,    91,    92,     0,     0,     0,    94,    31,    95,
      85,    86,    87,    88,    89,    90,     0,    91,    92,    96,
       0,     0,     0,    93,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,    93,     0,
       0,   248,     0,     0,     0,     8,     9,    10,     0,    85,
      86,    87,    88,    89,    90,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,    94,     0,    95,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    96,   286,
     313,    94,   131,    95,     8,     9,    10,    97,    98,    99,
     100,   101,   102,    96,     0,     0,     0,     0,   249,     0,
       0,     0,    97,   250,    99,   100,   101,   102,    85,    86,
      87,    88,    89,    90,     0,    91,    92,     0,     0,     0,
      94,   131,    95,    85,    86,    87,    88,    89,    90,     0,
      91,    92,    96,     0,     0,     0,    93,   314,     0,     0,
       0,    97,   315,    99,   100,   101,   102,     0,     0,     0,
       0,    93,     0,     0,   358,     0,     0,     0,     8,     9,
      10,     0,    85,    86,    87,    88,    89,    90,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,    94,
       0,    95,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    96,   474,   386,    94,   131,    95,     8,     9,    10,
      97,    98,    99,   100,   101,   102,    96,     0,     0,     0,
       0,   359,     0,     0,     0,    97,   360,    99,   100,   101,
     102,    85,    86,    87,    88,    89,    90,     0,    91,    92,
       0,     0,     0,    94,   131,    95,    85,    86,    87,    88,
      89,    90,     0,    91,    92,    96,     0,     0,     0,    93,
     387,     0,     0,     0,    97,    98,    99,   100,   101,   102,
       0,     0,     0,     0,    93,     0,     0,   391,     0,     0,
       0,     8,     9,    10,     0,    85,    86,    87,    88,    89,
      90,     0,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,    95,     0,     0,     0,     0,     0,
       0,     0,     0,    93,    96,   476,   441,    94,   131,    95,
       8,     9,    10,    97,    98,    99,   100,   101,   102,    96,
       0,     0,     0,     0,   392,     0,     0,     0,    97,   393,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,   131,    95,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    96,     0,
       0,     0,     0,   442,     0,     0,     0,    97,    98,    99,
     100,   101,   102,     0,     0,     0,     0,    93,     0,     0,
       0,     0,     0,     0,     8,     9,    10,    85,    86,    87,
      88,    89,    90,     0,    91,    92,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,     0,    91,
      92,     0,     0,     0,     0,    93,     0,     0,     0,     0,
      94,   131,    95,     0,     0,     0,     0,     0,     0,     0,
      93,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    94,   339,    95,   340,   236,   453,    97,
      98,    99,   100,   101,   102,    96,     0,     0,     0,   339,
       0,   340,   236,   482,    97,    98,    99,   100,   101,   102,
      85,    86,    87,    88,    89,    90,     0,    91,    92,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,     0,    91,    92,     0,     0,     0,     0,    93,     0,
      85,    86,    87,    88,    89,    90,     0,    91,    92,     0,
       0,     0,     0,    93,     0,     0,    85,    86,    87,    88,
      89,    90,     0,    91,    92,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,    95,    93,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,     0,    94,   339,    95,   340,
     236,     0,    97,    98,    99,   100,   101,   102,    96,     0,
       0,    94,     0,    95,     0,   236,     0,    97,    98,    99,
     100,   101,   102,    96,     0,     0,     0,    94,     0,    95,
     374,     0,    97,    98,    99,   100,   101,   102,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,    97,    98,
      99,   100,   101,   102,    85,    86,    87,    88,    89,    90,
       0,    91,    92,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,    89,    90,     0,    91,    92,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,     0,    93,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,     0,     0,     0,     0,    94,     0,    95,     0,     0,
       0,     0,     0,     0,     0,    31,     0,   156,    33,     0,
      94,    55,    95,     0,     0,     0,    97,    98,    99,   100,
     101,   102,   158,     0,   254,     0,     0,     0,     0,     0,
       0,    97,    98,    99,   100,   101,   102,     0,     1,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,     0,     0,   241,     0,     0,     0,
       0,    30,     0,    31,     0,    32,     0,    34,    56,    57,
      58,    59,    60,    61,   346,   310,     0,     0,   197,     0,
       0,     0,     0,     1,    63,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    31,     0,
      32,     0,    34,     0,     0,     0,     0,     0,     0,     0,
     242,     0,     0,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    31,     0,
      32,    33,    34,     1,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,    31,     0,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,   138,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    31,     0,    32,     0,    34,
       0,     0,     0,     0,     0,     0,   196,   310,     0,     1,
     197,     0,     0,     0,     0,     0,    63,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,   362,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,    31,     0,    32,
      33,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,   137,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,    31,
       0,    32,     0,    34,     0,     0,     0,     0,     0,     0,
       1,   389,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    31,     0,    32,    33,    34,
       1,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     415,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    30,     0,    31,     0,    32,     1,    34,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    30,     0,    31,     0,    32,     0,    34,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,    31,     0,     0,    33,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,     0,   425,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,    31,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
      52,    53,    62,   138,    52,    53,    70,    74,    96,   143,
     154,    63,    36,     0,    52,   198,    54,    63,    67,   124,
     148,    86,    74,   144,    54,    88,    74,    67,     3,     3,
       3,   410,    88,    88,     3,    52,    53,    90,    88,    92,
      97,    98,    14,    15,    96,     3,   109,    86,    96,    86,
      37,    38,    19,   109,   109,   108,    43,    44,    45,   109,
      47,    88,   109,    74,    91,     9,    10,    11,   156,     3,
     158,   123,    93,   125,    93,   123,   197,   125,   124,    96,
     147,   148,   134,   462,   172,   217,   108,   330,   134,    86,
       3,    86,   144,   142,    86,   147,   148,   137,    90,   147,
     148,    95,   142,    86,   156,   193,   158,    90,   156,   161,
     158,   135,   123,   161,   125,   153,   140,   261,   106,    94,
      52,    94,    54,   153,    93,   253,   150,   248,   175,   176,
     177,   103,   104,     3,   222,    93,   147,   148,   243,   156,
     107,   158,    86,    86,   161,   197,    90,    90,    92,    96,
     196,     3,   105,    96,   101,   102,   143,    88,    90,    91,
      92,   404,   405,    94,    18,   348,    87,    80,    81,    82,
      83,    84,    85,    86,   212,    86,    89,   109,    88,    90,
      88,    88,   212,    96,    94,   319,   253,    94,    88,    87,
     230,   323,   313,   325,    94,    87,   248,   243,    87,   320,
     252,   253,    12,    13,     3,   253,    87,    88,   343,   196,
      80,    81,    82,    83,    84,    85,    86,     3,   256,   243,
      90,   153,   182,   183,   184,   185,   256,    87,    80,    81,
      82,    83,    84,    85,    86,    16,    17,   284,   326,   327,
     328,     3,   253,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   313,    87,    88,    87,   317,   398,     6,   320,   108,
     391,   138,    87,    88,    86,   410,    89,   144,    87,    88,
     212,    88,    89,    89,   348,    86,   346,    87,    88,    86,
     330,    87,    88,    86,     3,   162,    38,    39,    40,     3,
     346,   339,    87,   355,   171,    87,    88,    87,    88,   339,
      87,    88,    87,    88,   446,   447,   448,   178,   179,   371,
     455,   180,   181,   371,   256,   109,   109,   462,   366,    88,
     197,   383,   319,    75,    91,    91,   366,   186,   187,   391,
     364,   379,   474,   395,   476,     3,    89,    87,    89,    87,
      87,    87,   284,   485,    96,    88,   488,    87,   490,   346,
      91,   449,   450,   451,   351,    91,    87,    66,     3,   236,
       3,    80,    81,    82,    83,    84,    85,    86,    91,    91,
      89,   248,   109,    91,    91,   252,   438,    96,    93,    91,
       3,     4,     5,     6,     7,     8,    87,    10,    11,    91,
     109,    91,    86,   109,    91,    91,    91,   339,   460,    89,
      89,    64,   460,    91,   281,    91,   283,    91,    31,    91,
      91,     3,    80,    81,    82,    83,    84,    85,    86,    91,
     188,   460,   109,   147,   366,   189,   191,   190,    96,   135,
     192,   364,    80,   344,   374,   351,   313,   379,    47,    -1,
     317,   109,   230,   320,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    76,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    86,    10,    11,   343,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,   355,    -1,
      -1,   358,    -1,    -1,    -1,    31,   109,    -1,    80,    81,
      82,    83,    84,    85,    86,    -1,    -1,   374,    90,    -1,
     377,    -1,    -1,    -1,    96,    -1,   383,    -1,    -1,   386,
      -1,    -1,    -1,    -1,   391,    61,    62,    63,   395,    65,
      66,    67,    68,    69,    70,    71,    72,    -1,    74,    -1,
      76,    -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,   438,    -1,   109,   441,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,   455,    -1,
      -1,   458,    -1,    -1,   461,   462,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,    -1,    -1,     3,     4,     5,     6,     7,
       8,   109,    10,    11,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    99,   100,   108,    -1,     3,     4,     5,     6,     7,
       8,   109,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    80,    81,    82,    83,    84,    85,    86,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    76,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,   109,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    74,    75,    76,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    86,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    86,    87,
      34,    74,    75,    76,    38,    39,    40,    95,    96,    97,
      98,    99,   100,    86,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    95,    96,    97,    98,    99,   100,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      74,    75,    76,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    86,    -1,    -1,    -1,    31,    91,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    34,    -1,    -1,    -1,    38,    39,
      40,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    86,    87,    34,    74,    75,    76,    38,    39,    40,
      95,    96,    97,    98,    99,   100,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    95,    96,    97,    98,    99,
     100,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    74,    75,    76,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    86,    -1,    -1,    -1,    31,
      91,    -1,    -1,    -1,    95,    96,    97,    98,    99,   100,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    86,    87,    34,    74,    75,    76,
      38,    39,    40,    95,    96,    97,    98,    99,   100,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    96,    97,
      98,    99,   100,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    74,    90,    76,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    86,    -1,    -1,    -1,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    31,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    31,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    76,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    74,    90,    76,    92,
      93,    -1,    95,    96,    97,    98,    99,   100,    86,    -1,
      -1,    74,    -1,    76,    -1,    93,    -1,    95,    96,    97,
      98,    99,   100,    86,    -1,    -1,    -1,    74,    -1,    76,
      93,    -1,    95,    96,    97,    98,    99,   100,    -1,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,
      97,    98,    99,   100,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    31,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    86,    78,    -1,
      74,     3,    76,    -1,    -1,    -1,    95,    96,    97,    98,
      99,   100,    86,    -1,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    98,    99,   100,    -1,    30,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    73,    -1,    75,    -1,    77,    -1,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    30,    96,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    -1,
      77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    -1,
      77,    78,    79,    30,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    -1,
      77,    78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,   108,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    75,    -1,    77,    -1,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    30,
      90,    -1,    -1,    -1,    -1,    -1,    96,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    94,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    75,    -1,    77,
      78,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    93,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,    75,
      -1,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    87,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    75,    -1,    77,    78,    79,
      30,    -1,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,    75,    -1,    77,    30,    79,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    73,    -1,    75,    -1,    77,    -1,    79,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    75,    -1,    -1,    78,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      73,    75,    77,    78,    79,   138,   139,   142,   143,   144,
     145,   151,   154,   155,   156,   157,   175,   185,   186,   187,
       3,    93,    86,    86,    86,     3,    80,    81,    82,    83,
      84,    85,    86,    96,   109,   140,   141,   158,   159,   160,
     161,   139,   139,     3,    93,   139,   139,   139,     0,   186,
      93,     3,   113,   152,   153,     3,     4,     5,     6,     7,
       8,    10,    11,    31,    74,    76,    86,    95,    96,    97,
      98,    99,   100,   111,   112,   114,   115,   118,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   137,   143,   148,   155,   167,   167,   137,   158,
     160,    75,   155,   161,   162,    88,   109,    93,   108,   138,
     139,   178,   188,    86,    90,     3,   159,    93,   146,   147,
     148,   175,   152,   108,    88,    94,    86,   120,    86,   120,
     120,    86,    86,   120,   133,   134,   136,   167,     9,    10,
      11,    86,    90,    92,   122,    96,   101,   102,    97,    98,
      12,    13,    14,    15,   103,   104,    16,    17,    95,   105,
     106,    18,    19,   107,    87,   148,    86,    90,   161,   168,
     169,   148,    87,    87,    88,    87,     3,   155,   161,   141,
     158,     3,    61,    62,    63,    65,    66,    67,    68,    69,
      70,    71,    72,    94,   109,   136,   138,   176,   177,   178,
     179,   180,   181,   182,   183,   184,    93,   134,   170,   138,
     178,     3,    87,   139,   163,   164,   165,   166,    34,    91,
      96,   134,   162,   146,    94,   147,    89,   109,   149,   150,
     158,    88,    94,   137,    94,   153,   167,   167,   167,   134,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     108,   135,    87,    88,    87,     3,    87,   119,   134,   136,
       3,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     125,   125,   126,   126,   127,   128,   129,   130,   131,   136,
      87,   163,   168,    34,    91,    96,   134,   162,   169,    86,
      90,     6,    87,    89,   137,    89,    86,    86,    86,   176,
      86,     3,   109,   109,   109,   136,   109,    94,   180,    90,
      92,   170,   171,   172,   173,   174,    86,   158,   161,   168,
      87,    88,    87,    88,   134,   162,    91,    91,    34,    91,
      96,   134,    94,   137,    88,   109,    89,    94,    87,    87,
      87,    88,   134,   134,    93,   122,    87,    88,    91,    89,
      87,    87,   134,   162,    91,    91,    34,    91,   134,    87,
     163,    34,    91,    96,   134,   162,    87,   176,    89,   176,
     136,   136,   136,    66,   138,   181,   109,   109,   137,     3,
      88,    94,   170,   108,   174,    60,   165,     3,    91,   134,
     134,    91,    91,   150,   137,    62,   116,   117,   167,   171,
     134,   133,    91,   134,   134,    91,    87,   134,   162,    91,
      91,    34,    91,   134,   109,   176,    87,    87,    87,    86,
     181,   181,    91,    94,   170,   172,    91,    91,    89,    87,
      88,    89,    88,    94,    91,    91,    91,   134,   134,    91,
     176,   176,   176,   136,    87,   136,    87,   136,   170,   134,
     117,   134,    94,    91,    91,    64,    87,   176,    87,   176,
      87,   176,   109,   176,   176
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   110,   111,   111,   111,   111,   111,   112,   112,   112,
     113,   114,   114,   115,   116,   116,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     124,   124,   125,   125,   125,   126,   126,   126,   126,   126,
     127,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   136,
     137,   138,   138,   138,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   140,   141,   141,   142,   142,
     142,   142,   142,   142,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   144,   144,   144,   145,   145,   146,
     146,   147,   147,   147,   148,   148,   148,   148,   149,   149,
     150,   150,   150,   151,   151,   151,   151,   151,   152,   152,
     153,   153,   154,   155,   155,   155,   155,   156,   156,   157,
     157,   158,   158,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   160,
     160,   160,   160,   160,   160,   161,   161,   161,   161,   162,
     162,   163,   163,   164,   164,   165,   165,   165,   166,   166,
     167,   167,   168,   168,   168,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   170,   170,   170,   171,
     171,   171,   171,   172,   173,   173,   174,   174,   175,   176,
     176,   176,   176,   176,   176,   177,   177,   177,   178,   178,
     179,   179,   180,   180,   181,   181,   182,   182,   182,   183,
     183,   183,   183,   183,   183,   184,   184,   184,   184,   184,
     185,   185,   186,   186,   187,   187,   188,   188
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
       4,     2,     1,     1,     3,     3,     4,     6,     5,     5,
       6,     5,     4,     4,     4,     3,     4,     2,     4,     1,
       1,     1,     1,     1,     1,     3,     2,     2,     1,     1,
       2,     3,     1,     1,     3,     2,     2,     1,     1,     3,
       2,     1,     2,     1,     1,     3,     2,     3,     5,     4,
       5,     4,     3,     3,     3,     4,     6,     5,     5,     6,
       4,     4,     2,     3,     3,     4,     3,     4,     1,     2,
       1,     4,     3,     2,     1,     2,     3,     2,     7,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     2,     3,
       1,     2,     1,     1,     1,     2,     7,     5,     5,     5,
       7,     6,     7,     6,     7,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     4,     3,     1,     2
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
#line 129 "grammar.y"
        {
        (yyval.id) = (char*) malloc(STRING_LIMIT);
        strcpy((yyval.id), identifier_function((yyvsp[0].id))); // DECL_FUNCTIONS.H
        free((yyvsp[0].id));
	}
#line 2057 "grammar.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 135 "grammar.y"
        {
        (yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), ascii_function((yyvsp[0].id))); // ASCII_FUNCTIONS.H
		strcpy((yyval.id), check_number((yyvsp[0].id)));   // CONVERSION_FUNCTIONS.H
        free((yyvsp[0].id));
	}
#line 2068 "grammar.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 142 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)));
		strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2078 "grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 148 "grammar.y"
        {
        (yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
        strcat((yyval.id), (yyvsp[-1].id));
        strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 2090 "grammar.tab.c"
    break;

  case 7: /* constant: I_CONSTANT  */
#line 160 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2100 "grammar.tab.c"
    break;

  case 8: /* constant: F_CONSTANT  */
#line 166 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2110 "grammar.tab.c"
    break;

  case 9: /* constant: ENUMERATION_CONSTANT  */
#line 172 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2120 "grammar.tab.c"
    break;

  case 10: /* enumeration_constant: IDENTIFIER  */
#line 183 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2130 "grammar.tab.c"
    break;

  case 11: /* string: STRING_LITERAL  */
#line 192 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2140 "grammar.tab.c"
    break;

  case 12: /* string: FUNC_NAME  */
#line 198 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2150 "grammar.tab.c"
    break;

  case 18: /* postfix_expression: primary_expression  */
#line 221 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
	}
#line 2160 "grammar.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 227 "grammar.y"
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
#line 2184 "grammar.tab.c"
    break;

  case 20: /* postfix_expression: postfix_expression '(' ')'  */
#line 247 "grammar.y"
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
#line 2212 "grammar.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 271 "grammar.y"
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
#line 2242 "grammar.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 297 "grammar.y"
                {
		////////////////////////////////////////////////////////////////
		// Process records/structures
		////////////////////////////////////////////////////////////////
        (yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), process_records((yyvsp[-2].id), (yyvsp[0].id)));	// STRUCTURES.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2256 "grammar.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 307 "grammar.y"
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
#line 2275 "grammar.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression INC_OP  */
#line 322 "grammar.y"
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
#line 2308 "grammar.tab.c"
    break;

  case 25: /* postfix_expression: postfix_expression DEC_OP  */
#line 351 "grammar.y"
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
#line 2325 "grammar.tab.c"
    break;

  case 28: /* argument_expression_list: assignment_expression  */
#line 369 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2335 "grammar.tab.c"
    break;

  case 29: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 375 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[-2].id));
        strcat((yyval.id), ",");
        strcat((yyval.id), (yyvsp[0].id));
        free((yyvsp[-2].id));
        free((yyvsp[0].id));
    }
#line 2348 "grammar.tab.c"
    break;

  case 30: /* unary_expression: postfix_expression  */
#line 387 "grammar.y"
        {
        (yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
        strcpy((yyval.id), (yyvsp[0].id));
        free((yyvsp[0].id));
    }
#line 2358 "grammar.tab.c"
    break;

  case 31: /* unary_expression: INC_OP unary_expression  */
#line 393 "grammar.y"
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
#line 2375 "grammar.tab.c"
    break;

  case 32: /* unary_expression: DEC_OP unary_expression  */
#line 406 "grammar.y"
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
#line 2391 "grammar.tab.c"
    break;

  case 33: /* unary_expression: unary_operator cast_expression  */
#line 418 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process casting expressions
		////////////////////////////////////////////////////////////////
        (yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), process_cast_unary_rule((yyvsp[-1].id), (yyvsp[0].id)));	// DECL_FUNCTIONS.H
        free((yyvsp[-1].id));
        free((yyvsp[0].id));
	}
#line 2405 "grammar.tab.c"
    break;

  case 34: /* unary_expression: SIZEOF unary_expression  */
#line 428 "grammar.y"
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
#line 2426 "grammar.tab.c"
    break;

  case 35: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 445 "grammar.y"
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
#line 2442 "grammar.tab.c"
    break;

  case 37: /* unary_operator: '&'  */
#line 461 "grammar.y"
        {
		(yyval.id) = (char*) malloc(10+1);
		strcpy((yyval.id), "address_of");

	}
#line 2452 "grammar.tab.c"
    break;

  case 38: /* unary_operator: '*'  */
#line 467 "grammar.y"
        {
		(yyval.id) = (char*) malloc(11+1);
		strcpy((yyval.id), "dereference");
	}
#line 2461 "grammar.tab.c"
    break;

  case 39: /* unary_operator: '+'  */
#line 472 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "+");

	}
#line 2471 "grammar.tab.c"
    break;

  case 40: /* unary_operator: '-'  */
#line 478 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "-");
	}
#line 2480 "grammar.tab.c"
    break;

  case 41: /* unary_operator: '~'  */
#line 483 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1+1);
		strcpy((yyval.id), "~");
	}
#line 2489 "grammar.tab.c"
    break;

  case 42: /* unary_operator: '!'  */
#line 488 "grammar.y"
        {
		(yyval.id) = (char*) malloc(11+1);
		strcpy((yyval.id), "exclamation");
	}
#line 2498 "grammar.tab.c"
    break;

  case 43: /* cast_expression: unary_expression  */
#line 496 "grammar.y"
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
#line 2520 "grammar.tab.c"
    break;

  case 44: /* cast_expression: '(' type_name ')' cast_expression  */
#line 514 "grammar.y"
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
#line 2538 "grammar.tab.c"
    break;

  case 45: /* multiplicative_expression: cast_expression  */
#line 531 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2548 "grammar.tab.c"
    break;

  case 46: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 537 "grammar.y"
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
#line 2567 "grammar.tab.c"
    break;

  case 47: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 552 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "/");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2580 "grammar.tab.c"
    break;

  case 48: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 561 "grammar.y"
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
#line 2599 "grammar.tab.c"
    break;

  case 49: /* additive_expression: multiplicative_expression  */
#line 580 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2609 "grammar.tab.c"
    break;

  case 50: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 586 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "+");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2622 "grammar.tab.c"
    break;

  case 51: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 595 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "-");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2635 "grammar.tab.c"
    break;

  case 52: /* shift_expression: additive_expression  */
#line 607 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2645 "grammar.tab.c"
    break;

  case 53: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 613 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<<");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2658 "grammar.tab.c"
    break;

  case 54: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 622 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">>");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2671 "grammar.tab.c"
    break;

  case 55: /* relational_expression: shift_expression  */
#line 634 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2681 "grammar.tab.c"
    break;

  case 56: /* relational_expression: relational_expression '<' shift_expression  */
#line 640 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2694 "grammar.tab.c"
    break;

  case 57: /* relational_expression: relational_expression '>' shift_expression  */
#line 649 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2707 "grammar.tab.c"
    break;

  case 58: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 658 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<=");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2720 "grammar.tab.c"
    break;

  case 59: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 667 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ">=");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2733 "grammar.tab.c"
    break;

  case 60: /* equality_expression: relational_expression  */
#line 680 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2743 "grammar.tab.c"
    break;

  case 61: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 686 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "==");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2756 "grammar.tab.c"
    break;

  case 62: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 695 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "<>");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2769 "grammar.tab.c"
    break;

  case 63: /* and_expression: equality_expression  */
#line 707 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2779 "grammar.tab.c"
    break;

  case 64: /* and_expression: and_expression '&' equality_expression  */
#line 713 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "&");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2792 "grammar.tab.c"
    break;

  case 65: /* exclusive_or_expression: and_expression  */
#line 725 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2802 "grammar.tab.c"
    break;

  case 66: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 731 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "^");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2815 "grammar.tab.c"
    break;

  case 67: /* inclusive_or_expression: exclusive_or_expression  */
#line 743 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2825 "grammar.tab.c"
    break;

  case 68: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 749 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "|");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 2838 "grammar.tab.c"
    break;

  case 69: /* logical_and_expression: inclusive_or_expression  */
#line 761 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2848 "grammar.tab.c"
    break;

  case 70: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 767 "grammar.y"
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
#line 2863 "grammar.tab.c"
    break;

  case 71: /* logical_or_expression: logical_and_expression  */
#line 781 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2873 "grammar.tab.c"
    break;

  case 72: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 787 "grammar.y"
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
#line 2888 "grammar.tab.c"
    break;

  case 73: /* conditional_expression: logical_or_expression  */
#line 801 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2898 "grammar.tab.c"
    break;

  case 74: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 807 "grammar.y"
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
#line 2924 "grammar.tab.c"
    break;

  case 75: /* assignment_expression: conditional_expression  */
#line 832 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 2934 "grammar.tab.c"
    break;

  case 76: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 838 "grammar.y"
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
#line 2950 "grammar.tab.c"
    break;

  case 77: /* assignment_operator: '='  */
#line 853 "grammar.y"
        {
		(yyval.id) = (char*) malloc(13 + 1);
		strcpy((yyval.id), "\nassignment(");
	}
#line 2959 "grammar.tab.c"
    break;

  case 78: /* assignment_operator: MUL_ASSIGN  */
#line 858 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nmul_assignment(");
	}
#line 2968 "grammar.tab.c"
    break;

  case 79: /* assignment_operator: DIV_ASSIGN  */
#line 863 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\ndiv_assignment(");
	}
#line 2977 "grammar.tab.c"
    break;

  case 80: /* assignment_operator: MOD_ASSIGN  */
#line 868 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nmod_assignment(");
	}
#line 2986 "grammar.tab.c"
    break;

  case 81: /* assignment_operator: ADD_ASSIGN  */
#line 873 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nadd_assignment(");
	}
#line 2995 "grammar.tab.c"
    break;

  case 82: /* assignment_operator: SUB_ASSIGN  */
#line 878 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nsub_assignment(");
	}
#line 3004 "grammar.tab.c"
    break;

  case 83: /* assignment_operator: LEFT_ASSIGN  */
#line 883 "grammar.y"
        {
		(yyval.id) = (char*) malloc(18 + 1);
		strcpy((yyval.id), "\nleft_assignment(");
	}
#line 3013 "grammar.tab.c"
    break;

  case 84: /* assignment_operator: RIGHT_ASSIGN  */
#line 888 "grammar.y"
        {
		(yyval.id) = (char*) malloc(19 + 1);
		strcpy((yyval.id), "\nright_assignment(");
	}
#line 3022 "grammar.tab.c"
    break;

  case 85: /* assignment_operator: AND_ASSIGN  */
#line 893 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nand_assignment(");
	}
#line 3031 "grammar.tab.c"
    break;

  case 86: /* assignment_operator: XOR_ASSIGN  */
#line 898 "grammar.y"
        {
		(yyval.id) = (char*) malloc(17 + 1);
		strcpy((yyval.id), "\nxor_assignment(");
	}
#line 3040 "grammar.tab.c"
    break;

  case 87: /* assignment_operator: OR_ASSIGN  */
#line 903 "grammar.y"
        {
		(yyval.id) = (char*) malloc(16 + 1);
		strcpy((yyval.id), "\nor_assignment(");
	}
#line 3049 "grammar.tab.c"
    break;

  case 88: /* expression: assignment_expression  */
#line 911 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3059 "grammar.tab.c"
    break;

  case 89: /* expression: expression ',' assignment_expression  */
#line 917 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + strlen((yyvsp[-2].id)) + 3 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "comma(");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
	}
#line 3072 "grammar.tab.c"
    break;

  case 90: /* constant_expression: conditional_expression  */
#line 929 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3082 "grammar.tab.c"
    break;

  case 91: /* declaration: declaration_specifiers ';'  */
#line 938 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		char* declaration = struct_declaration((yyvsp[-1].id));
		strcpy((yyval.id), declaration);	// STRUCTURES.H
		free(declaration);
		free((yyvsp[-1].id));
		if(typedef_flag == YES) {
			typedef_flag = NO;
		}
	}
#line 3097 "grammar.tab.c"
    break;

  case 92: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 949 "grammar.y"
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
			(yyval.id) = (char*) malloc(STRING_LIMIT);
			int lenSS;
			strcpy((yyval.id), findvariabledetails((yyvsp[-2].id)));	// DECL_FUNCTIONS.H
			lenSS = strlen((yyval.id)) - 1;

			if ((yyval.id)[lenSS] != ',')
				strcat((yyval.id), ",");
		}
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
	}
#line 3123 "grammar.tab.c"
    break;

  case 94: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 975 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3135 "grammar.tab.c"
    break;

  case 95: /* declaration_specifiers: storage_class_specifier  */
#line 983 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3145 "grammar.tab.c"
    break;

  case 96: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 989 "grammar.y"
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
#line 3171 "grammar.tab.c"
    break;

  case 97: /* declaration_specifiers: type_specifier  */
#line 1011 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3181 "grammar.tab.c"
    break;

  case 98: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 1017 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
	}
#line 3191 "grammar.tab.c"
    break;

  case 99: /* declaration_specifiers: type_qualifier  */
#line 1023 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3201 "grammar.tab.c"
    break;

  case 104: /* init_declarator_list: init_declarator  */
#line 1036 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3211 "grammar.tab.c"
    break;

  case 105: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 1042 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3224 "grammar.tab.c"
    break;

  case 106: /* init_declarator: declarator '=' initializer  */
#line 1054 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		addvariabledetails((yyvsp[-2].id), (yyvsp[0].id));// DECL_FUNCTIONS.H
	}
#line 3234 "grammar.tab.c"
    break;

  case 107: /* init_declarator: declarator  */
#line 1060 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		if(typedef_flag == YES)
		{
			add_typedefs(change_typedef((yyvsp[0].id))); // TYPEDEF_FUNCTIONS.H
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
#line 3256 "grammar.tab.c"
    break;

  case 108: /* storage_class_specifier: TYPEDEF  */
#line 1081 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "typedef");
		set_typedef_flag();	// TYPEDEF_FUNCTIONS.H
	}
#line 3266 "grammar.tab.c"
    break;

  case 109: /* storage_class_specifier: EXTERN  */
#line 1087 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "extern");
	}
#line 3275 "grammar.tab.c"
    break;

  case 110: /* storage_class_specifier: STATIC  */
#line 1092 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "Static_");
	}
#line 3284 "grammar.tab.c"
    break;

  case 112: /* storage_class_specifier: AUTO  */
#line 1098 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 3293 "grammar.tab.c"
    break;

  case 113: /* storage_class_specifier: REGISTER  */
#line 1103 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 3302 "grammar.tab.c"
    break;

  case 114: /* type_specifier: VOID  */
#line 1111 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "void");
	}
#line 3311 "grammar.tab.c"
    break;

  case 115: /* type_specifier: CHAR  */
#line 1116 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "char");
	}
#line 3320 "grammar.tab.c"
    break;

  case 116: /* type_specifier: SHORT  */
#line 1121 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6);
		strcpy((yyval.id), "short");
	}
#line 3329 "grammar.tab.c"
    break;

  case 117: /* type_specifier: INT  */
#line 1126 "grammar.y"
        {
		(yyval.id) = (char*) malloc(4);
		strcpy((yyval.id), "int");
	}
#line 3338 "grammar.tab.c"
    break;

  case 118: /* type_specifier: LONG  */
#line 1131 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "long");
	}
#line 3347 "grammar.tab.c"
    break;

  case 119: /* type_specifier: FLOAT  */
#line 1136 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(6);
		 strcpy((yyval.id), "float");
	}
#line 3356 "grammar.tab.c"
    break;

  case 120: /* type_specifier: DOUBLE  */
#line 1141 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7);
		strcpy((yyval.id), "double");
	}
#line 3365 "grammar.tab.c"
    break;

  case 121: /* type_specifier: SIGNED  */
#line 1146 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7);
		strcpy((yyval.id), "signed");
	}
#line 3374 "grammar.tab.c"
    break;

  case 122: /* type_specifier: UNSIGNED  */
#line 1151 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(9);
		 strcpy((yyval.id), "unsigned");
	}
#line 3383 "grammar.tab.c"
    break;

  case 123: /* type_specifier: BOOL  */
#line 1156 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(9);
		 strcpy((yyval.id), "bool");
	}
#line 3392 "grammar.tab.c"
    break;

  case 124: /* type_specifier: COMPLEX  */
#line 1161 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(9);
		 strcpy((yyval.id), "complex");
	}
#line 3401 "grammar.tab.c"
    break;

  case 125: /* type_specifier: IMAGINARY  */
#line 1166 "grammar.y"
        {
		 (yyval.id) = (char*) malloc(9);
		 strcpy((yyval.id), "imaginary");
	}
#line 3410 "grammar.tab.c"
    break;

  case 127: /* type_specifier: struct_or_union_specifier  */
#line 1172 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3420 "grammar.tab.c"
    break;

  case 128: /* type_specifier: enum_specifier  */
#line 1178 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3430 "grammar.tab.c"
    break;

  case 129: /* type_specifier: TYPEDEF_NAME  */
#line 1184 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		char* name = change_typedef((yyvsp[0].id));
		strcpy((yyval.id), name);	 // TYPEDEF_FUNCTIONS.H
		free(name);
		free((yyvsp[0].id));
	}
#line 3442 "grammar.tab.c"
    break;

  case 130: /* type_specifier: __INT8  */
#line 1192 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6 + 1);
		strcpy((yyval.id), "__int8");
	}
#line 3451 "grammar.tab.c"
    break;

  case 131: /* type_specifier: __INT16  */
#line 1197 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "__int16");
	}
#line 3460 "grammar.tab.c"
    break;

  case 132: /* type_specifier: __INT32  */
#line 1202 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "__int32");
	}
#line 3469 "grammar.tab.c"
    break;

  case 133: /* type_specifier: __INT64  */
#line 1207 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + 1);
		strcpy((yyval.id), "__int64");
	}
#line 3478 "grammar.tab.c"
    break;

  case 134: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 1215 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 3 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), ", [");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 3491 "grammar.tab.c"
    break;

  case 135: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 1224 "grammar.y"
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
#line 3519 "grammar.tab.c"
    break;

  case 136: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 1248 "grammar.y"
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
#line 3543 "grammar.tab.c"
    break;

  case 137: /* struct_or_union: STRUCT  */
#line 1271 "grammar.y"
        {
		(yyval.id) = (char*) malloc(8);
		strcpy((yyval.id), "struct ");
	}
#line 3552 "grammar.tab.c"
    break;

  case 138: /* struct_or_union: UNION  */
#line 1276 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7);
		strcpy((yyval.id), "union ");
	}
#line 3561 "grammar.tab.c"
    break;

  case 139: /* struct_declaration_list: struct_declaration  */
#line 1284 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3571 "grammar.tab.c"
    break;

  case 140: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 1290 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3584 "grammar.tab.c"
    break;

  case 142: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 1303 "grammar.y"
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
#line 3613 "grammar.tab.c"
    break;

  case 144: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 1333 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
	}
#line 3623 "grammar.tab.c"
    break;

  case 145: /* specifier_qualifier_list: type_specifier  */
#line 1339 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3633 "grammar.tab.c"
    break;

  case 146: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 1345 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3645 "grammar.tab.c"
    break;

  case 147: /* specifier_qualifier_list: type_qualifier  */
#line 1353 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3655 "grammar.tab.c"
    break;

  case 148: /* struct_declarator_list: struct_declarator  */
#line 1362 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3666 "grammar.tab.c"
    break;

  case 149: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1369 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3680 "grammar.tab.c"
    break;

  case 150: /* struct_declarator: ':' constant_expression  */
#line 1382 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3691 "grammar.tab.c"
    break;

  case 151: /* struct_declarator: declarator ':' constant_expression  */
#line 1389 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3704 "grammar.tab.c"
    break;

  case 152: /* struct_declarator: declarator  */
#line 1398 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3714 "grammar.tab.c"
    break;

  case 153: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 1407 "grammar.y"
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
#line 3731 "grammar.tab.c"
    break;

  case 155: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 1421 "grammar.y"
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
#line 3765 "grammar.tab.c"
    break;

  case 157: /* enum_specifier: ENUM IDENTIFIER  */
#line 1452 "grammar.y"
        { 	////////////////////////////////////////////////////////////////
		// Change enum name to Prolog equivalent using change_enum()
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), "enum , ");
		strcat((yyval.id), change_enum((yyvsp[0].id)));	// ENUM_FUNCTIONS.H
		free((yyvsp[0].id));
		////////////////////////////////////////////////////////////////
	}
#line 3778 "grammar.tab.c"
    break;

  case 158: /* enumerator_list: enumerator  */
#line 1464 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3788 "grammar.tab.c"
    break;

  case 159: /* enumerator_list: enumerator_list ',' enumerator  */
#line 1470 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 2 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ", ");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 3801 "grammar.tab.c"
    break;

  case 160: /* enumerator: enumeration_constant '=' constant_expression  */
#line 1483 "grammar.y"
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
#line 3830 "grammar.tab.c"
    break;

  case 161: /* enumerator: enumeration_constant  */
#line 1508 "grammar.y"
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
#line 3855 "grammar.tab.c"
    break;

  case 163: /* type_qualifier: CONST  */
#line 1536 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6);
		strcpy((yyval.id), "const");
	}
#line 3864 "grammar.tab.c"
    break;

  case 164: /* type_qualifier: RESTRICT  */
#line 1541 "grammar.y"
        {
		(yyval.id) = (char*) malloc(9);
		strcpy((yyval.id), "restrict");
	}
#line 3873 "grammar.tab.c"
    break;

  case 165: /* type_qualifier: VOLATILE  */
#line 1546 "grammar.y"
        {
		(yyval.id) = (char*) malloc(9);
		strcpy((yyval.id), "volatile");
	}
#line 3882 "grammar.tab.c"
    break;

  case 166: /* type_qualifier: ATOMIC  */
#line 1551 "grammar.y"
        {
		(yyval.id) = (char*) malloc(9);
		strcpy((yyval.id), "atomic");
	}
#line 3891 "grammar.tab.c"
    break;

  case 171: /* declarator: pointer direct_declarator  */
#line 1569 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 3903 "grammar.tab.c"
    break;

  case 172: /* declarator: direct_declarator  */
#line 1577 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3913 "grammar.tab.c"
    break;

  case 173: /* direct_declarator: IDENTIFIER  */
#line 1586 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 3923 "grammar.tab.c"
    break;

  case 174: /* direct_declarator: '(' declarator ')'  */
#line 1592 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 3935 "grammar.tab.c"
    break;

  case 175: /* direct_declarator: direct_declarator '[' ']'  */
#line 1600 "grammar.y"
                {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "]");
		free((yyvsp[-2].id));
	}
#line 3947 "grammar.tab.c"
    break;

  case 176: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 1608 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
		free((yyvsp[-3].id));
	}
#line 3960 "grammar.tab.c"
    break;

  case 184: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 1624 "grammar.y"
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
#line 3988 "grammar.tab.c"
    break;

  case 185: /* direct_declarator: direct_declarator '(' ')'  */
#line 1648 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
	}
#line 4000 "grammar.tab.c"
    break;

  case 186: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 1656 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4014 "grammar.tab.c"
    break;

  case 187: /* direct_declarator: vc_specific_modifier IDENTIFIER  */
#line 1666 "grammar.y"
        {
		// Visual C extension
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4026 "grammar.tab.c"
    break;

  case 188: /* direct_declarator: '(' vc_specific_modifier IDENTIFIER ')'  */
#line 1674 "grammar.y"
        {
		// Visual C extension
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		free((yyvsp[-1].id));
		free((yyvsp[-2].id));
	}
#line 4038 "grammar.tab.c"
    break;

  case 189: /* vc_specific_modifier: __CDECL  */
#line 1685 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4047 "grammar.tab.c"
    break;

  case 190: /* vc_specific_modifier: __CLRCALL  */
#line 1690 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4056 "grammar.tab.c"
    break;

  case 191: /* vc_specific_modifier: __STDCALL  */
#line 1695 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4065 "grammar.tab.c"
    break;

  case 192: /* vc_specific_modifier: __FASTCALL  */
#line 1700 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4074 "grammar.tab.c"
    break;

  case 193: /* vc_specific_modifier: __THISCALL  */
#line 1705 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4083 "grammar.tab.c"
    break;

  case 194: /* vc_specific_modifier: __VECTORCALL  */
#line 1710 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1);
		strcpy((yyval.id), "");
	}
#line 4092 "grammar.tab.c"
    break;

  case 195: /* pointer: '*' type_qualifier_list pointer  */
#line 1718 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
	}
#line 4104 "grammar.tab.c"
    break;

  case 196: /* pointer: '*' type_qualifier_list  */
#line 1726 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4115 "grammar.tab.c"
    break;

  case 197: /* pointer: '*' pointer  */
#line 1733 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), "*");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4126 "grammar.tab.c"
    break;

  case 198: /* pointer: '*'  */
#line 1740 "grammar.y"
        {
		(yyval.id) = (char*) malloc(2);
		strcpy((yyval.id), "*");
	}
#line 4135 "grammar.tab.c"
    break;

  case 199: /* type_qualifier_list: type_qualifier  */
#line 1748 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4145 "grammar.tab.c"
    break;

  case 200: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1754 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4157 "grammar.tab.c"
    break;

  case 201: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1766 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 3 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), "...");
		free((yyvsp[-2].id));
	}
#line 4169 "grammar.tab.c"
    break;

  case 202: /* parameter_type_list: parameter_list  */
#line 1774 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		int lenSS = strlen((yyvsp[0].id)) - 1;
		if ((yyvsp[0].id)[lenSS] == ',')
			(yyvsp[0].id)[lenSS] = ' ';
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4182 "grammar.tab.c"
    break;

  case 203: /* parameter_list: parameter_declaration  */
#line 1786 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4192 "grammar.tab.c"
    break;

  case 204: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1792 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4204 "grammar.tab.c"
    break;

  case 205: /* parameter_declaration: declaration_specifiers declarator  */
#line 1803 "grammar.y"
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
#line 4223 "grammar.tab.c"
    break;

  case 206: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1818 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4235 "grammar.tab.c"
    break;

  case 207: /* parameter_declaration: declaration_specifiers  */
#line 1826 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4245 "grammar.tab.c"
    break;

  case 208: /* identifier_list: IDENTIFIER  */
#line 1835 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4255 "grammar.tab.c"
    break;

  case 209: /* identifier_list: identifier_list ',' IDENTIFIER  */
#line 1841 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4268 "grammar.tab.c"
    break;

  case 210: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 1853 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4280 "grammar.tab.c"
    break;

  case 211: /* type_name: specifier_qualifier_list  */
#line 1861 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4290 "grammar.tab.c"
    break;

  case 212: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 1870 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4302 "grammar.tab.c"
    break;

  case 213: /* abstract_declarator: pointer  */
#line 1878 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4312 "grammar.tab.c"
    break;

  case 214: /* abstract_declarator: direct_abstract_declarator  */
#line 1884 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4322 "grammar.tab.c"
    break;

  case 215: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 1893 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4334 "grammar.tab.c"
    break;

  case 216: /* direct_abstract_declarator: '[' ']'  */
#line 1901 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), "]");
	}
#line 4344 "grammar.tab.c"
    break;

  case 217: /* direct_abstract_declarator: '[' '*' ']'  */
#line 1907 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
	}
#line 4355 "grammar.tab.c"
    break;

  case 224: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 1920 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "]");
		free((yyvsp[-2].id));
	}
#line 4367 "grammar.tab.c"
    break;

  case 225: /* direct_abstract_declarator: direct_abstract_declarator '[' '*' ']'  */
#line 1928 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "[");
		strcat((yyval.id), "*");
		strcat((yyval.id), "]");
		free((yyvsp[-3].id));
	}
#line 4380 "grammar.tab.c"
    break;

  case 232: /* direct_abstract_declarator: '(' ')'  */
#line 1943 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), ")");
	}
#line 4390 "grammar.tab.c"
    break;

  case 233: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 1949 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4402 "grammar.tab.c"
    break;

  case 234: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 1957 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), ")");
		free((yyvsp[-2].id));
	}
#line 4414 "grammar.tab.c"
    break;

  case 235: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 1965 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-3].id)) + 1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-3].id));
		strcat((yyval.id), "(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-3].id));
		free((yyvsp[-1].id));
	}
#line 4428 "grammar.tab.c"
    break;

  case 236: /* initializer: '{' initializer_list '}'  */
#line 1978 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 4440 "grammar.tab.c"
    break;

  case 237: /* initializer: '{' initializer_list ',' '}'  */
#line 1986 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-2].id)) + 1 + 1 + 1);
		strcpy((yyval.id), "{");
		strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ",");
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "}");
		free((yyvsp[-2].id));
	}
#line 4454 "grammar.tab.c"
    break;

  case 238: /* initializer: assignment_expression  */
#line 1996 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4464 "grammar.tab.c"
    break;

  case 239: /* initializer_list: designation initializer  */
#line 2005 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ",");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4477 "grammar.tab.c"
    break;

  case 240: /* initializer_list: initializer  */
#line 2014 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4487 "grammar.tab.c"
    break;

  case 243: /* designation: designator_list '='  */
#line 2025 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "=");
		free((yyvsp[-1].id));
	}
#line 4498 "grammar.tab.c"
    break;

  case 244: /* designator_list: designator  */
#line 2035 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4508 "grammar.tab.c"
    break;

  case 245: /* designator_list: designator_list designator  */
#line 2041 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4520 "grammar.tab.c"
    break;

  case 246: /* designator: '[' constant_expression ']'  */
#line 2052 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "[");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), "]");
		free((yyvsp[-1].id));
	}
#line 4532 "grammar.tab.c"
    break;

  case 247: /* designator: '.' IDENTIFIER  */
#line 2060 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + strlen((yyvsp[0].id)) + 1 + 1);
		strcpy((yyval.id), "access(");
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), ")");
		free((yyvsp[0].id));
	}
#line 4544 "grammar.tab.c"
    break;

  case 249: /* statement: labeled_statement  */
#line 2075 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4554 "grammar.tab.c"
    break;

  case 250: /* statement: compound_statement  */
#line 2081 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4564 "grammar.tab.c"
    break;

  case 251: /* statement: expression_statement  */
#line 2087 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4574 "grammar.tab.c"
    break;

  case 252: /* statement: selection_statement  */
#line 2093 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4584 "grammar.tab.c"
    break;

  case 253: /* statement: iteration_statement  */
#line 2099 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4594 "grammar.tab.c"
    break;

  case 254: /* statement: jump_statement  */
#line 2105 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4604 "grammar.tab.c"
    break;

  case 255: /* labeled_statement: IDENTIFIER ':' statement  */
#line 2114 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-2].id)) + 1 + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), ":");
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-2].id));
	}
#line 4616 "grammar.tab.c"
    break;

  case 256: /* labeled_statement: CASE constant_expression ':' statement  */
#line 2122 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), case_statement((yyvsp[-2].id), (yyvsp[0].id)));	// SWITCH_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4627 "grammar.tab.c"
    break;

  case 257: /* labeled_statement: DEFAULT ':' statement  */
#line 2129 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), default_statement((yyvsp[0].id)));  	// SWITCH_FUNCTIONS.H
		free((yyvsp[0].id));
	}
#line 4637 "grammar.tab.c"
    break;

  case 258: /* compound_statement: '{' '}'  */
#line 2138 "grammar.y"
        {
		(yyval.id) = (char*) malloc(1 + 1 + 1);
		strcpy((yyval.id), "[");
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 4648 "grammar.tab.c"
    break;

  case 259: /* compound_statement: '{' block_item_list '}'  */
#line 2145 "grammar.y"
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
#line 4666 "grammar.tab.c"
    break;

  case 260: /* block_item_list: block_item  */
#line 2162 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4676 "grammar.tab.c"
    break;

  case 261: /* block_item_list: block_item_list block_item  */
#line 2168 "grammar.y"
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
#line 4693 "grammar.tab.c"
    break;

  case 262: /* block_item: declaration  */
#line 2184 "grammar.y"
        {

		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4704 "grammar.tab.c"
    break;

  case 263: /* block_item: statement  */
#line 2191 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4714 "grammar.tab.c"
    break;

  case 264: /* expression_statement: ';'  */
#line 2200 "grammar.y"
        {
		(yyval.id) = (char*) malloc(5);
		strcpy((yyval.id), "null");
	}
#line 4723 "grammar.tab.c"
    break;

  case 265: /* expression_statement: expression ';'  */
#line 2205 "grammar.y"
        {
		(yyval.id) = (char*) malloc(21 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "expression_statement(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4735 "grammar.tab.c"
    break;

  case 266: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 2216 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), ifelse_statement((yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id))); // IF_FUNCTIONS.H
		free((yyvsp[-4].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4747 "grammar.tab.c"
    break;

  case 267: /* selection_statement: IF '(' expression ')' statement  */
#line 2224 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), if_statement((yyvsp[-2].id), (yyvsp[0].id))); 	  // IF_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4758 "grammar.tab.c"
    break;

  case 268: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 2231 "grammar.y"
        {
		(yyval.id) = (char*) malloc(STRING_LIMIT);
		strcpy((yyval.id), switch_statement((yyvsp[-2].id), (yyvsp[0].id)));	  // SWITCH_FUNCTIONS.H
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4769 "grammar.tab.c"
    break;

  case 269: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 2241 "grammar.y"
        {
		char* while_statement_definition = while_statement((yyvsp[-2].id), (yyvsp[0].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(while_statement_definition) + 1);
		strcpy((yyval.id), while_statement_definition);
		free(while_statement_definition);
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4782 "grammar.tab.c"
    break;

  case 270: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 2250 "grammar.y"
        {
		char* do_statement_definition = do_statement((yyvsp[-5].id), (yyvsp[-2].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(do_statement_definition) + 1);
		strcpy((yyval.id), do_statement_definition);
		free(do_statement_definition);
		free((yyvsp[-5].id));
		free((yyvsp[-2].id));
	}
#line 4795 "grammar.tab.c"
    break;

  case 271: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 2259 "grammar.y"
        {
		char* for_statement_definition = for2_statement((yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[0].id)); // ITERATION_FUNCTIONS.H
		(yyval.id) = (char*) malloc(strlen(for_statement_definition) + 1);
		strcpy((yyval.id), for_statement_definition);
		free(for_statement_definition);
		free((yyvsp[-3].id));
		free((yyvsp[-2].id));
		free((yyvsp[0].id));
	}
#line 4809 "grammar.tab.c"
    break;

  case 272: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 2269 "grammar.y"
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
#line 4824 "grammar.tab.c"
    break;

  case 275: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 2285 "grammar.y"
        {
		(yyval.id) = (char*) malloc(4 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "goto");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ";");
		free((yyvsp[-1].id));
	}
#line 4836 "grammar.tab.c"
    break;

  case 276: /* jump_statement: CONTINUE ';'  */
#line 2293 "grammar.y"
        {
		(yyval.id) = (char*) malloc(9);
		strcpy((yyval.id), "continue");
	}
#line 4845 "grammar.tab.c"
    break;

  case 277: /* jump_statement: BREAK ';'  */
#line 2298 "grammar.y"
        {
		(yyval.id) = (char*) malloc(6);
		strcpy((yyval.id), "break");
	}
#line 4854 "grammar.tab.c"
    break;

  case 278: /* jump_statement: RETURN ';'  */
#line 2303 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7);
		strcpy((yyval.id), "return");
	}
#line 4863 "grammar.tab.c"
    break;

  case 279: /* jump_statement: RETURN expression ';'  */
#line 2308 "grammar.y"
        {
		(yyval.id) = (char*) malloc(7 + strlen((yyvsp[-1].id)) + 1 + 1);
		strcpy((yyval.id), "return(");
		strcat((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), ")");
		free((yyvsp[-1].id));
	}
#line 4875 "grammar.tab.c"
    break;

  case 280: /* translation_unit: external_declaration  */
#line 2319 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4885 "grammar.tab.c"
    break;

  case 281: /* translation_unit: translation_unit external_declaration  */
#line 2325 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4897 "grammar.tab.c"
    break;

  case 282: /* external_declaration: function_definition  */
#line 2336 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		printfunction((yyval.id)); 	// OUTPUT_FUNCTIONS.H
		free((yyvsp[0].id));
	}
#line 4908 "grammar.tab.c"
    break;

  case 283: /* external_declaration: declaration  */
#line 2343 "grammar.y"
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
#line 4927 "grammar.tab.c"
    break;

  case 284: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 2361 "grammar.y"
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
#line 4943 "grammar.tab.c"
    break;

  case 285: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 2373 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Function Defintions
		////////////////////////////////////////////////////////////////
		char* function = process_functions((yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].id));
		(yyval.id) = (char*) malloc(strlen(function) + 1);
		strcpy((yyval.id), function);	// DECL_FUNCTIONS.H
		free(function);
		free((yyvsp[-2].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4960 "grammar.tab.c"
    break;

  case 286: /* declaration_list: declaration  */
#line 2389 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[0].id));
		free((yyvsp[0].id));
	}
#line 4970 "grammar.tab.c"
    break;

  case 287: /* declaration_list: declaration_list declaration  */
#line 2395 "grammar.y"
        {
		(yyval.id) = (char*) malloc(strlen((yyvsp[-1].id)) + strlen((yyvsp[0].id)) + 1);
		strcpy((yyval.id), (yyvsp[-1].id));
		strcat((yyval.id), (yyvsp[0].id));
		free((yyvsp[-1].id));
		free((yyvsp[0].id));
	}
#line 4982 "grammar.tab.c"
    break;


#line 4986 "grammar.tab.c"

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

#line 2404 "grammar.y"

#include <stdio.h>
#include "lex.yy.c"
