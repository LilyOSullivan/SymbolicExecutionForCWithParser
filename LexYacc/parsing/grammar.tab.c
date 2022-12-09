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
#line 1 "grammar.y"

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** GRAMMAR.Y SPECIFICATION FILE
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
/*
This is the grammar specification file for the ANSI C programming
language. The original file has been sourced at the following
reference:
	J. Lee. ANSI C Lex and YACC Grammar Files, April 1985.
	FTP: ftp.uu.net, FILE: usenet/net.sources/ansi.c.grammar.Z.

This file is used as the input grammar file of the parser generator 
used in the WCET Analysis Tool.
*/

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** GRAMMAR FILE DEFINITONS SECTION
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
extern int yylex();
extern void yyerror(const char*);
extern int yychar;
////////////////////////////////////////////////////////////////
// *** INCLUDE USER-DEFINED HEADER FILES
////////////////////////////////////////////////////////////////
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


#line 118 "grammar.tab.c"

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
  YYSYMBOL_CONSTANT = 4,                   /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_SIZEOF = 6,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 7,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 8,                     /* INC_OP  */
  YYSYMBOL_DEC_OP = 9,                     /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 10,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 11,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 12,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 13,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 14,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 15,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 16,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 17,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 18,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 19,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 20,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 21,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 22,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 23,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 24,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 25,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 26,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 27,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPE_NAME = 28,                 /* TYPE_NAME  */
  YYSYMBOL_TYPEDEF = 29,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 30,                    /* EXTERN  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_REGISTER = 32,                  /* REGISTER  */
  YYSYMBOL_AUTO = 33,                      /* AUTO  */
  YYSYMBOL_CHAR = 34,                      /* CHAR  */
  YYSYMBOL_SHORT = 35,                     /* SHORT  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_LONG = 37,                      /* LONG  */
  YYSYMBOL_SIGNED = 38,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 39,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 40,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 41,                    /* DOUBLE  */
  YYSYMBOL_CONST = 42,                     /* CONST  */
  YYSYMBOL_VOLATILE = 43,                  /* VOLATILE  */
  YYSYMBOL_VOID = 44,                      /* VOID  */
  YYSYMBOL_STRUCT = 45,                    /* STRUCT  */
  YYSYMBOL_UNION = 46,                     /* UNION  */
  YYSYMBOL_ENUM = 47,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 48,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_IF = 51,                        /* IF  */
  YYSYMBOL_ELSE = 52,                      /* ELSE  */
  YYSYMBOL_SWITCH = 53,                    /* SWITCH  */
  YYSYMBOL_WHILE = 54,                     /* WHILE  */
  YYSYMBOL_DO = 55,                        /* DO  */
  YYSYMBOL_FOR = 56,                       /* FOR  */
  YYSYMBOL_GOTO = 57,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 58,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 59,                     /* BREAK  */
  YYSYMBOL_RETURN = 60,                    /* RETURN  */
  YYSYMBOL_61_ = 61,                       /* '('  */
  YYSYMBOL_62_ = 62,                       /* ')'  */
  YYSYMBOL_63_ = 63,                       /* '['  */
  YYSYMBOL_64_ = 64,                       /* ']'  */
  YYSYMBOL_65_ = 65,                       /* '.'  */
  YYSYMBOL_66_ = 66,                       /* ','  */
  YYSYMBOL_67_ = 67,                       /* '&'  */
  YYSYMBOL_68_ = 68,                       /* '*'  */
  YYSYMBOL_69_ = 69,                       /* '+'  */
  YYSYMBOL_70_ = 70,                       /* '-'  */
  YYSYMBOL_71_ = 71,                       /* '~'  */
  YYSYMBOL_72_ = 72,                       /* '!'  */
  YYSYMBOL_73_ = 73,                       /* '/'  */
  YYSYMBOL_74_ = 74,                       /* '%'  */
  YYSYMBOL_75_ = 75,                       /* '<'  */
  YYSYMBOL_76_ = 76,                       /* '>'  */
  YYSYMBOL_77_ = 77,                       /* '^'  */
  YYSYMBOL_78_ = 78,                       /* '|'  */
  YYSYMBOL_79_ = 79,                       /* '?'  */
  YYSYMBOL_80_ = 80,                       /* ':'  */
  YYSYMBOL_81_ = 81,                       /* '='  */
  YYSYMBOL_82_ = 82,                       /* ';'  */
  YYSYMBOL_83_ = 83,                       /* '{'  */
  YYSYMBOL_84_ = 84,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 85,                  /* $accept  */
  YYSYMBOL_primary_expression = 86,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 87,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 88,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 89,          /* unary_expression  */
  YYSYMBOL_unary_operator = 90,            /* unary_operator  */
  YYSYMBOL_cast_expression = 91,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 92, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 93,       /* additive_expression  */
  YYSYMBOL_shift_expression = 94,          /* shift_expression  */
  YYSYMBOL_relational_expression = 95,     /* relational_expression  */
  YYSYMBOL_equality_expression = 96,       /* equality_expression  */
  YYSYMBOL_and_expression = 97,            /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 98,   /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 99,   /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 100,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 101,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 102,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 103,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 104,      /* assignment_operator  */
  YYSYMBOL_expression = 105,               /* expression  */
  YYSYMBOL_constant_expression = 106,      /* constant_expression  */
  YYSYMBOL_declaration = 107,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 108,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 109,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 110,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 111,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 112,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 113, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 114,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 115,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 116,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 117, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 118,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 119,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 120,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 121,          /* enumerator_list  */
  YYSYMBOL_enumerator = 122,               /* enumerator  */
  YYSYMBOL_type_qualifier = 123,           /* type_qualifier  */
  YYSYMBOL_declarator = 124,               /* declarator  */
  YYSYMBOL_direct_declarator = 125,        /* direct_declarator  */
  YYSYMBOL_pointer = 126,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 127,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 128,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 129,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 130,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 131,          /* identifier_list  */
  YYSYMBOL_type_name = 132,                /* type_name  */
  YYSYMBOL_abstract_declarator = 133,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 134, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 135,              /* initializer  */
  YYSYMBOL_initializer_list = 136,         /* initializer_list  */
  YYSYMBOL_statement = 137,                /* statement  */
  YYSYMBOL_labeled_statement = 138,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 139,       /* compound_statement  */
  YYSYMBOL_declaration_list = 140,         /* declaration_list  */
  YYSYMBOL_statement_list = 141,           /* statement_list  */
  YYSYMBOL_expression_statement = 142,     /* expression_statement  */
  YYSYMBOL_selection_statement = 143,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 144,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 145,           /* jump_statement  */
  YYSYMBOL_translation_unit = 146,         /* translation_unit  */
  YYSYMBOL_external_declaration = 147,     /* external_declaration  */
  YYSYMBOL_function_definition = 148       /* function_definition  */
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
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1301

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  350

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   140,   140,   144,   149,   153,   162,   166,   178,   192,
     206,   213,   221,   237,   251,   253,   261,   263,   271,   279,
     286,   301,   316,   317,   318,   319,   320,   321,   328,   342,
     355,   357,   366,   370,   385,   386,   388,   396,   397,   398,
     405,   406,   408,   410,   412,   420,   421,   423,   431,   433,
     441,   442,   450,   451,   459,   460,   469,   470,   480,   481,
     497,   498,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   526,   527,   537,   544,   548,   566,   568,
     570,   572,   590,   592,   600,   602,   610,   614,   624,   629,
     630,   631,   632,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   661,   681,   687,   710,   711,
     718,   720,   728,   751,   752,   753,   754,   761,   765,   775,
     776,   777,   783,   794,   816,   829,   833,   843,   860,   887,
     888,   895,   899,   909,   911,   915,   919,   921,   936,   940,
     950,   952,   954,   956,   964,   965,   972,   979,   986,   990,
    1001,  1012,  1016,  1026,  1027,  1034,  1035,  1042,  1043,  1044,
    1051,  1052,  1053,  1054,  1055,  1056,  1057,  1060,  1063,  1072,
    1076,  1082,  1094,  1095,  1103,  1104,  1105,  1106,  1107,  1108,
    1115,  1119,  1123,  1133,  1138,  1144,  1153,  1165,  1166,  1173,
    1174,  1181,  1182,  1189,  1193,  1196,  1206,  1209,  1212,  1215,
    1224,  1225,  1226,  1227,  1228,  1235,  1236,  1244,  1249,  1264,
    1268,  1275,  1279
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
  "CONSTANT", "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP",
  "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP",
  "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN",
  "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN",
  "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "REGISTER",
  "AUTO", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT",
  "DOUBLE", "CONST", "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM",
  "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'",
  "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'",
  "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-223)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     969,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,     5,    42,     4,  -223,    31,  1254,  1254,  -223,    11,
    -223,  1254,  1101,    88,    26,   879,  -223,  -223,   -60,    51,
      14,  -223,  -223,     4,  -223,    38,  -223,  1081,  -223,  -223,
     -10,  1055,  -223,   278,  -223,    31,  -223,  1101,   408,   666,
      88,  -223,  -223,    51,    69,   -23,  -223,  -223,  -223,  -223,
      42,  -223,   542,  -223,  1101,  1055,  1055,  1004,  -223,    72,
    1055,   -12,  -223,  -223,   785,   806,   806,   830,    17,   123,
     129,   132,   524,   141,   109,   127,   134,   559,   645,  -223,
    -223,  -223,  -223,  -223,  -223,  -223,  -223,  -223,   192,   274,
     830,  -223,   121,    36,   224,   116,   229,   151,   150,   158,
     236,    -2,  -223,  -223,    43,  -223,  -223,  -223,   348,   418,
    -223,  -223,  -223,  -223,   164,  -223,  -223,  -223,  -223,    18,
     198,   188,  -223,    16,  -223,  -223,  -223,  -223,   197,   -15,
     830,    51,  -223,  -223,   542,  -223,  -223,  -223,  1024,  -223,
    -223,  -223,   830,    76,  -223,   184,  -223,   524,   645,  -223,
     830,  -223,  -223,   190,   524,   830,   830,   830,   217,   596,
     191,  -223,  -223,  -223,   114,    49,    85,   212,   273,  -223,
    -223,   690,   830,   275,  -223,  -223,  -223,  -223,  -223,  -223,
    -223,  -223,  -223,  -223,  -223,   830,  -223,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,  -223,  -223,   454,
    -223,  -223,   924,   715,  -223,    22,  -223,   165,  -223,  1233,
    -223,   282,  -223,  -223,  -223,  -223,  -223,    35,  -223,  -223,
      72,  -223,   830,  -223,   215,   524,  -223,    81,   120,   145,
     227,   596,  -223,  -223,  -223,  1157,   170,  -223,   830,  -223,
    -223,   146,  -223,     1,  -223,  -223,  -223,  -223,  -223,   121,
     121,    36,    36,   224,   224,   224,   224,   116,   116,   229,
     151,   150,   158,   236,   -50,  -223,  -223,  -223,   228,   240,
    -223,   225,   165,  1198,   736,  -223,  -223,  -223,   488,  -223,
    -223,  -223,  -223,  -223,   524,   524,   524,   830,   760,  -223,
    -223,   830,  -223,   830,  -223,  -223,  -223,  -223,   242,  -223,
     241,  -223,  -223,   239,  -223,  -223,   148,   524,   155,  -223,
    -223,  -223,  -223,   524,   244,  -223,   524,  -223,  -223,  -223
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,   104,    88,    89,    90,    92,    91,    94,    95,
      96,    97,   100,   101,    98,    99,   129,   130,    93,   108,
     109,     0,     0,   140,   208,     0,    78,    80,   102,     0,
     103,    82,     0,   132,     0,     0,   205,   207,   124,     0,
       0,   144,   142,   141,    76,     0,    84,    86,    79,    81,
     107,     0,    83,     0,   187,     0,   212,     0,     0,     0,
     131,     1,   206,     0,   127,     0,   125,   134,   145,   143,
       0,    77,     0,   210,     0,     0,   114,     0,   110,     0,
     116,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,    25,    26,    27,   191,   183,     6,    16,    28,
       0,    30,    34,    37,    40,    45,    48,    50,    52,    54,
      56,    58,    60,    73,     0,   189,   174,   175,     0,     0,
     176,   177,   178,   179,    86,   188,   211,   153,   139,   152,
       0,   146,   148,     0,     2,   136,    28,    75,     0,     0,
       0,     0,   122,    85,     0,   169,    87,   209,     0,   113,
     106,   111,     0,     0,   117,   119,   115,     0,     0,    20,
       0,    17,    18,     0,     0,     0,     0,     0,     0,     0,
       0,   201,   202,   203,     0,     0,   155,     0,     0,    12,
      13,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    62,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   185,     0,
     184,   190,     0,     0,   150,   157,   151,   158,   137,     0,
     138,     0,   135,   123,   128,   126,   172,     0,   105,   120,
       0,   112,     0,   180,     0,     0,   182,     0,     0,     0,
       0,     0,   200,   204,     5,     0,   157,   156,     0,    11,
       8,     0,    14,     0,    10,    61,    31,    32,    33,    35,
      36,    38,    39,    43,    44,    41,    42,    46,    47,    49,
      51,    53,    55,    57,     0,    74,   186,   165,     0,     0,
     161,     0,   159,     0,     0,   147,   149,   154,     0,   170,
     118,   121,    21,   181,     0,     0,     0,     0,     0,    29,
       9,     0,     7,     0,   166,   160,   162,   167,     0,   163,
       0,   171,   173,   193,   195,   196,     0,     0,     0,    15,
      59,   168,   164,     0,     0,   198,     0,   194,   197,   199
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,  -223,  -223,   -48,  -223,   -91,    37,    46,     8,
      48,   110,   119,   122,   118,   135,  -223,   -55,   -70,  -223,
     -38,   -54,     6,     0,  -223,   272,  -223,   -27,  -223,  -223,
     268,   -67,   -24,  -223,   108,  -223,   300,   213,    47,   -13,
     -29,    -3,  -223,   -57,  -223,   126,  -223,   199,  -122,  -222,
    -151,  -223,   -74,  -223,   156,   -25,   238,  -172,  -223,  -223,
    -223,  -223,   333,  -223
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   107,   108,   271,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   205,
     124,   148,    54,    55,    45,    46,    26,    27,    28,    29,
      77,    78,    79,   163,   164,    30,    65,    66,    31,    32,
      33,    34,    43,   298,   141,   142,   143,   187,   299,   237,
     156,   247,   125,   126,   127,    57,   129,   130,   131,   132,
     133,    35,    36,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,   140,   155,   246,   147,    60,    24,   261,    38,    40,
     161,   146,    47,   302,    50,   224,   226,   236,   178,   206,
      42,     1,    74,    63,    76,     1,    48,    49,   128,     1,
     323,    52,   147,   173,     1,    25,   169,   171,   172,   146,
      69,    24,   134,   151,   302,     1,    16,    17,    76,    76,
      76,   151,   159,    76,    64,   231,   166,   134,   139,   184,
     185,   152,   146,   135,   267,   322,   165,   226,   167,   243,
      41,    76,    23,    75,   186,     1,    67,   225,   240,   232,
     135,   233,   241,   232,   155,   233,    23,    22,    39,   318,
      68,   161,    22,   253,    51,   147,   244,   174,    80,    23,
     256,   308,   146,    22,    70,   210,   211,   147,   249,   226,
      23,   264,   180,    44,   146,   226,   276,   277,   278,   309,
      71,   272,    80,    80,    80,   227,   234,    80,   214,   215,
     185,    76,   185,    22,   135,   275,   235,   257,   258,   259,
      23,    76,   250,   314,   186,    80,   265,   226,   233,    58,
     150,    59,   162,    23,   273,   231,   295,   332,   251,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   319,   147,   301,
     226,   313,   315,   266,   175,   146,   226,   294,    56,   207,
     176,   216,   217,   177,   208,   209,   263,   147,   311,   188,
     189,   190,   179,    73,   146,    80,    60,   316,   320,   181,
     344,   226,   321,   136,   226,    80,   182,   346,   220,    40,
     146,   226,   283,   284,   285,   286,   303,   221,   304,   235,
     157,   265,   139,   233,   212,   213,   222,   165,   155,   139,
     333,   334,   335,   218,   219,    72,   328,   279,   280,   147,
     330,   339,   223,   191,   239,   192,   146,   193,   281,   282,
     238,   242,   266,   345,   252,   139,   287,   288,   340,   347,
     255,   260,   349,   262,   268,   146,   269,   312,   274,   336,
     338,    81,    82,    83,    84,   307,    85,    86,   317,   326,
     324,   343,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   325,   139,   341,   342,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   348,    87,    88,    89,
     289,    90,    91,    92,    93,    94,    95,    96,    97,    98,
     290,   292,   153,   158,   291,    99,   100,   101,   102,   103,
     104,    81,    82,    83,    84,   204,    85,    86,   310,   293,
     105,    53,   106,   149,   245,   306,   229,   254,    62,     0,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    87,    88,    89,
       0,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,   137,     0,     0,     0,    99,   100,   101,   102,   103,
     104,    81,    82,    83,    84,     0,    85,    86,     0,     0,
     105,    53,   228,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    81,    82,    83,
      84,     0,    85,    86,     0,     0,     0,    87,    88,    89,
     138,    90,    91,    92,    93,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   144,    82,    83,    84,     0,    85,    86,     0,     0,
     105,    53,   230,    87,    88,    89,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,    81,    82,    83,
      84,     0,    85,    86,     0,     0,   105,    53,   296,     0,
       0,     0,     0,     0,     0,   144,    82,    83,    84,    98,
      85,    86,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   144,    82,    83,    84,     0,    85,    86,     0,
       0,   154,   331,    87,    88,    89,     0,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,     0,   144,
      82,    83,    84,    98,    85,    86,   105,    53,     0,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,   154,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,     0,     0,     0,     0,     0,     0,   144,    82,
      83,    84,     0,    85,    86,     0,     0,    98,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   144,
      82,    83,    84,     2,    85,    86,     0,     0,   105,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   144,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   144,    82,
      83,    84,     0,    85,    86,     0,     0,    98,     0,     0,
     145,     0,     0,    99,   100,   101,   102,   103,   104,   144,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,    98,   270,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   144,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,    98,     0,     0,   300,
       0,     0,    99,   100,   101,   102,   103,   104,   144,    82,
      83,    84,     0,    85,    86,     0,     0,    98,     0,     0,
     329,     0,     0,    99,   100,   101,   102,   103,   104,   144,
      82,    83,    84,     0,    85,    86,     0,     0,     0,     0,
       0,    98,   337,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,   144,    82,    83,    84,     0,    85,    86,
       0,     0,     0,     0,     0,     0,   168,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   170,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,    61,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   232,   297,   233,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,     0,     2,     0,     0,     0,     0,    23,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     2,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,   160,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,     0,     0,   248,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    72,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   265,   297,
     233,     0,     0,     0,     0,    23,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     327,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   305,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    58,    72,   154,    59,    34,     0,   179,     3,    22,
      77,    59,    25,   235,     3,    17,    66,   139,    92,   110,
      23,     3,    47,    83,    51,     3,    26,    27,    53,     3,
      80,    31,    87,    87,     3,    35,    84,    85,    86,    87,
      43,    35,    55,    66,   266,     3,    42,    43,    75,    76,
      77,    66,    76,    80,     3,   129,    80,    70,    58,    97,
      98,    84,   110,    57,   186,    64,    79,    66,    80,    84,
      23,    98,    68,    83,    98,     3,    62,    79,    62,    61,
      74,    63,    66,    61,   154,    63,    68,    61,    83,   261,
      43,   158,    61,   167,    83,   150,   150,    80,    51,    68,
     174,    66,   150,    61,    66,    69,    70,   162,   162,    66,
      68,    62,     3,    82,   162,    66,   207,   208,   209,    84,
      82,   191,    75,    76,    77,    82,   139,    80,    12,    13,
     168,   158,   170,    61,   128,   205,   139,   175,   176,   177,
      68,   168,    66,    62,   168,    98,    61,    66,    63,    61,
      81,    63,    80,    68,   192,   229,   226,   308,    82,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   268,   233,   233,
      66,   255,    62,   186,    61,   233,    66,   225,    32,    68,
      61,    75,    76,    61,    73,    74,    82,   252,   252,     7,
       8,     9,    61,    47,   252,   158,   235,    62,    62,    82,
      62,    66,    66,    57,    66,   168,    82,    62,    67,   232,
     268,    66,   214,   215,   216,   217,    61,    77,    63,   232,
      74,    61,   232,    63,    10,    11,    78,   250,   308,   239,
     314,   315,   316,    14,    15,    81,   303,   210,   211,   304,
     304,   321,    16,    61,    66,    63,   304,    65,   212,   213,
      62,    64,   265,   337,    80,   265,   218,   219,   323,   343,
      80,    54,   346,    82,    62,   323,     3,    62,     3,   317,
     318,     3,     4,     5,     6,     3,     8,     9,    61,    64,
      62,    52,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    62,   303,    62,    64,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    82,    49,    50,    51,
     220,    53,    54,    55,    56,    57,    58,    59,    60,    61,
     221,   223,    70,    75,   222,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    81,     8,     9,   250,   224,
      82,    83,    84,    63,   151,   239,   128,   168,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    49,    50,    51,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,     3,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      82,    83,    84,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    49,    50,    51,
      62,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      82,    83,    84,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    61,
       8,     9,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    83,    84,    49,    50,    51,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    71,    72,    -1,    -1,     3,
       4,     5,     6,    61,     8,     9,    82,    83,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    83,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    28,     8,     9,    -1,    -1,    82,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    64,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    61,    -1,    -1,
      64,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,     0,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    28,    -1,    -1,    -1,    -1,    68,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    84,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    -1,    -1,    84,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    61,    68,   107,   108,   111,   112,   113,   114,
     120,   123,   124,   125,   126,   146,   147,   148,     3,    83,
     124,   123,   126,   127,    82,   109,   110,   124,   108,   108,
       3,    83,   108,    83,   107,   108,   139,   140,    61,    63,
     125,     0,   147,    83,     3,   121,   122,    62,   123,   126,
      66,    82,    81,   139,   140,    83,   112,   115,   116,   117,
     123,     3,     4,     5,     6,     8,     9,    49,    50,    51,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    67,
      68,    69,    70,    71,    72,    82,    84,    86,    87,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   105,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   124,   107,   139,     3,    62,   108,
     128,   129,   130,   131,     3,    64,    89,   102,   106,   121,
      81,    66,    84,   110,    83,   103,   135,   139,   115,   117,
      84,   116,    80,   118,   119,   124,   117,    80,    61,    89,
      61,    89,    89,   106,    80,    61,    61,    61,   137,    61,
       3,    82,    82,    82,   105,   105,   117,   132,     7,     8,
       9,    61,    63,    65,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    81,   104,    91,    68,    73,    74,
      69,    70,    10,    11,    12,    13,    75,    76,    14,    15,
      67,    77,    78,    16,    17,    79,    66,    82,    84,   141,
      84,   137,    61,    63,   124,   126,   133,   134,    62,    66,
      62,    66,    64,    84,   106,   122,   135,   136,    84,   106,
      66,    82,    80,   137,   132,    80,   137,   105,   105,   105,
      54,   142,    82,    82,    62,    61,   126,   133,    62,     3,
      62,    88,   103,   105,     3,   103,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      97,    98,    99,   100,   105,   103,    84,    62,   128,   133,
      64,   106,   134,    61,    63,    48,   130,     3,    66,    84,
     119,   106,    62,   137,    62,    62,    62,    61,   142,    91,
      62,    66,    64,    80,    62,    62,    64,    62,   128,    64,
     106,    84,   135,   137,   137,   137,   105,    62,   105,   103,
     102,    62,    64,    52,    62,   137,    62,   137,    82,   137
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   110,   111,   111,
     111,   111,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   113,   113,   113,   114,   114,
     115,   115,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   122,   122,   123,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   135,
     135,   135,   136,   136,   137,   137,   137,   137,   137,   137,
     138,   138,   138,   139,   139,   139,   139,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   144,   144,   144,   144,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   148,   148
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     4,     2,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     4,     5,     2,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     3,     4,     3,     4,     4,     3,
       1,     2,     2,     3,     1,     2,     1,     3,     1,     3,
       2,     2,     1,     1,     3,     1,     2,     1,     1,     2,
       3,     2,     3,     3,     4,     2,     3,     3,     4,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     3,     2
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
  case 2: /* primary_expression: IDENTIFIER  */
#line 141 "grammar.y"
        { 
		strcpy((yyval.id), identifier_function((yyvsp[0].id)));	// DECL_FUNCTIONS.H
	}
#line 1716 "grammar.tab.c"
    break;

  case 3: /* primary_expression: CONSTANT  */
#line 145 "grammar.y"
        { 	
		strcpy((yyval.id), ascii_function((yyvsp[0].id))); 	// ASCII_FUNCTIONS.H
		strcpy((yyval.id), check_number((yyvsp[0].id))); 		// CONVERSION_FUNCTIONS.H
	}
#line 1725 "grammar.tab.c"
    break;

  case 4: /* primary_expression: STRING_LITERAL  */
#line 150 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[0].id));
	}
#line 1733 "grammar.tab.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 154 "grammar.y"
        { 
		strcpy((yyval.id), "("); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ")"); 
	}
#line 1741 "grammar.tab.c"
    break;

  case 6: /* postfix_expression: primary_expression  */
#line 163 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[0].id)); 
	}
#line 1749 "grammar.tab.c"
    break;

  case 7: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 167 "grammar.y"
        { 
		if (strstr((yyvsp[-3].id), "[") != NULL) 
		{
			strcpy((yyval.id), process_arrays((yyvsp[-3].id), (yyvsp[-1].id))); // ARRAY_FUNCTIONS.H
		}
		else 
		{
			strcpy((yyval.id), (yyvsp[-3].id)); strcat((yyval.id), "["); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "]"); 
		}
	
	}
#line 1765 "grammar.tab.c"
    break;

  case 8: /* postfix_expression: postfix_expression '(' ')'  */
#line 179 "grammar.y"
        { 
		////////////////////////////////////////////////////////////////
		// Process function calls (without arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		////////////////////////////////////////////////////////////////
		char *func_name;
		func_name = (char *) malloc(STRING_LIMIT);
		strcpy(func_name, copystring((yyvsp[-2].id), 3, strlen((yyvsp[-2].id))));
		strcpy((yyval.id), "\nfunction_call(");
		strcat((yyval.id), func_name);
		strcat((yyval.id), ", [");  strcat((yyval.id), "]"); strcat((yyval.id), ")");
	}
#line 1783 "grammar.tab.c"
    break;

  case 9: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 193 "grammar.y"
        { 
		////////////////////////////////////////////////////////////////
		// Process function calls (with arguments)
		// Function calls are parsed with "LC_" or "UC_" in their name
		// Remove this and process as function call
		////////////////////////////////////////////////////////////////	
		char *func_name;
		func_name = (char *) malloc(STRING_LIMIT);
		strcpy(func_name, copystring((yyvsp[-3].id), 3, strlen((yyvsp[-3].id))-3));
		strcpy((yyval.id), "\nfunction_call(");
		strcat((yyval.id), func_name);
		strcat((yyval.id), ", ["); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "]"); strcat((yyval.id), ")");	
	}
#line 1801 "grammar.tab.c"
    break;

  case 10: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 207 "grammar.y"
        {	
		////////////////////////////////////////////////////////////////
		// Process records/structures
		////////////////////////////////////////////////////////////////		
		strcpy((yyval.id), process_records((yyvsp[-2].id), (yyvsp[0].id)));	// STRUCTURES.H
	}
#line 1812 "grammar.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 214 "grammar.y"
        { 		
		////////////////////////////////////////////////////////////////
		// Process linked list statements
		////////////////////////////////////////////////////////////////
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]); strcpy((yyval.id), "linkedlist("); 
		strcat((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ", "); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")");
	}
#line 1824 "grammar.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression INC_OP  */
#line 222 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process statements such as i++;
		////////////////////////////////////////////////////////////////		
		strcpy((yyval.id), "\npost_increment("); 
		if ( (strstr((yyvsp[-1].id), "dereference") != NULL) && ((yyvsp[-1].id)[0] != '(') )
		{
			strcat((yyval.id), "("); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), " , ");
			strcat((yyval.id), "(");  strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "+1)");
		}
		else
		{
			strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), " , "); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "+1)");
		}
	}
#line 1844 "grammar.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression DEC_OP  */
#line 238 "grammar.y"
        {	
		////////////////////////////////////////////////////////////////
		// Process statements such as i--;
		////////////////////////////////////////////////////////////////
		strcpy((yyval.id), "\npost_decrement("); strcat((yyval.id), (yyvsp[-1].id)); 
		strcat((yyval.id), " , "); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "-1)");
	}
#line 1856 "grammar.tab.c"
    break;

  case 14: /* argument_expression_list: assignment_expression  */
#line 252 "grammar.y"
        {strcpy((yyval.id), (yyvsp[0].id)); }
#line 1862 "grammar.tab.c"
    break;

  case 15: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 254 "grammar.y"
        {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ","); strcat((yyval.id), (yyvsp[0].id));  }
#line 1868 "grammar.tab.c"
    break;

  case 16: /* unary_expression: postfix_expression  */
#line 262 "grammar.y"
        {	strcpy((yyval.id), (yyvsp[0].id));  }
#line 1874 "grammar.tab.c"
    break;

  case 17: /* unary_expression: INC_OP unary_expression  */
#line 264 "grammar.y"
        {	
		////////////////////////////////////////////////////////////////
		// Process statements such as ++i;
		////////////////////////////////////////////////////////////////
		strcpy((yyval.id), "\npre_increment("); strcat((yyval.id), (yyvsp[0].id));  strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), "+1)");
	}
#line 1886 "grammar.tab.c"
    break;

  case 18: /* unary_expression: DEC_OP unary_expression  */
#line 272 "grammar.y"
        {	
		////////////////////////////////////////////////////////////////
		// Process statements such as --i;
		////////////////////////////////////////////////////////////////
		strcpy((yyval.id), "\npre_decrement("); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), " , ");
		strcat((yyval.id), (yyvsp[0].id));	strcat((yyval.id), "-1)");
	}
#line 1898 "grammar.tab.c"
    break;

  case 19: /* unary_expression: unary_operator cast_expression  */
#line 280 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process casting expressions
		////////////////////////////////////////////////////////////////
		strcpy((yyval.id), process_cast_unary_rule((yyvsp[-1].id), (yyvsp[0].id)));	// DECL_FUNCTIONS.H
	}
#line 1909 "grammar.tab.c"
    break;

  case 20: /* unary_expression: SIZEOF unary_expression  */
#line 287 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process sizeof statements
		////////////////////////////////////////////////////////////////	
		strcpy((yyval.id), "sizeof"); 
		if ((yyvsp[0].id)[0] != '(') 
		{
			strcat((yyval.id), "("); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")");
		}
		else
		{
			strcat((yyval.id), (yyvsp[0].id));
		}
	}
#line 1928 "grammar.tab.c"
    break;

  case 21: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 302 "grammar.y"
        {	
		////////////////////////////////////////////////////////////////
		// Process sizeof(type) statements
		////////////////////////////////////////////////////////////////	
		strcpy((yyval.id), "sizeof"); strcat((yyval.id), "("); 
		strcat((yyval.id), change_asterisk((yyvsp[-1].id))); 	// DECL_FUNCTIONS.H
		strcat((yyval.id), ")");
	}
#line 1941 "grammar.tab.c"
    break;

  case 22: /* unary_operator: '&'  */
#line 316 "grammar.y"
                { strcpy((yyval.id), "address_of"); 	}
#line 1947 "grammar.tab.c"
    break;

  case 23: /* unary_operator: '*'  */
#line 317 "grammar.y"
                { strcpy((yyval.id), "dereference"); 	}
#line 1953 "grammar.tab.c"
    break;

  case 24: /* unary_operator: '+'  */
#line 318 "grammar.y"
                { strcpy((yyval.id), "+"); 		}
#line 1959 "grammar.tab.c"
    break;

  case 25: /* unary_operator: '-'  */
#line 319 "grammar.y"
                { strcpy((yyval.id), "-"); 		}
#line 1965 "grammar.tab.c"
    break;

  case 26: /* unary_operator: '~'  */
#line 320 "grammar.y"
                { strcpy((yyval.id), "~"); 	   	}
#line 1971 "grammar.tab.c"
    break;

  case 27: /* unary_operator: '!'  */
#line 321 "grammar.y"
                { strcpy((yyval.id), "exclamation");	}
#line 1977 "grammar.tab.c"
    break;

  case 28: /* cast_expression: unary_expression  */
#line 329 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Surround negative numbers with ( and )
		////////////////////////////////////////////////////////////////	
		if ((yyvsp[0].id)[0] == '-')
		{
			strcpy((yyval.id), "("); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")");
		}
		else
		{
			strcpy((yyval.id), (yyvsp[0].id)); 
		}
	}
#line 1995 "grammar.tab.c"
    break;

  case 29: /* cast_expression: '(' type_name ')' cast_expression  */
#line 343 "grammar.y"
        {	
		////////////////////////////////////////////////////////////////
		// Process cast expressions
		////////////////////////////////////////////////////////////////	
		strcpy((yyval.id), "cast(("); strcat((yyval.id), change_asterisk((yyvsp[-2].id))); // DECL_FUNCTIONS.H
		strcat((yyval.id), "), "); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")"); 
	}
#line 2007 "grammar.tab.c"
    break;

  case 30: /* multiplicative_expression: cast_expression  */
#line 356 "grammar.y"
        {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2013 "grammar.tab.c"
    break;

  case 31: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 358 "grammar.y"
        {
		////////////////////////////////////////////////////////////////
		// Process * - change '*' to multiply to avoid confusion with 
		// the pointer dereference '*'		
		////////////////////////////////////////////////////////////////	
		strcpy((yyval.id), "multiply("); strcat((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ", "); 
		strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")");				
	}
#line 2026 "grammar.tab.c"
    break;

  case 32: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 367 "grammar.y"
        {
		strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "/"); strcat((yyval.id), (yyvsp[0].id)); 
	}
#line 2034 "grammar.tab.c"
    break;

  case 33: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 371 "grammar.y"
        {	
		////////////////////////////////////////////////////////////////
		// Process % - change '%' to modulo to avoid confusion with 
		// the Prolog comments operator '%'		
		////////////////////////////////////////////////////////////////	
		strcpy((yyval.id), "mod("); strcat((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), " , "); 
		strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")");
	}
#line 2047 "grammar.tab.c"
    break;

  case 34: /* additive_expression: multiplicative_expression  */
#line 385 "grammar.y"
                                        {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2053 "grammar.tab.c"
    break;

  case 35: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 387 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "+"); strcat((yyval.id), (yyvsp[0].id));   }
#line 2059 "grammar.tab.c"
    break;

  case 36: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 389 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "-");  strcat((yyval.id), (yyvsp[0].id));   }
#line 2065 "grammar.tab.c"
    break;

  case 37: /* shift_expression: additive_expression  */
#line 396 "grammar.y"
                                {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2071 "grammar.tab.c"
    break;

  case 38: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 397 "grammar.y"
                                                        {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "<<"); strcat((yyval.id), (yyvsp[0].id)); }
#line 2077 "grammar.tab.c"
    break;

  case 39: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 398 "grammar.y"
                                                        {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ">>"); strcat((yyval.id), (yyvsp[0].id)); }
#line 2083 "grammar.tab.c"
    break;

  case 40: /* relational_expression: shift_expression  */
#line 405 "grammar.y"
                                {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2089 "grammar.tab.c"
    break;

  case 41: /* relational_expression: relational_expression '<' shift_expression  */
#line 407 "grammar.y"
                {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "<");  strcat((yyval.id), (yyvsp[0].id)); }
#line 2095 "grammar.tab.c"
    break;

  case 42: /* relational_expression: relational_expression '>' shift_expression  */
#line 409 "grammar.y"
                {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ">");  strcat((yyval.id), (yyvsp[0].id)); }
#line 2101 "grammar.tab.c"
    break;

  case 43: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 411 "grammar.y"
                {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "<="); strcat((yyval.id), (yyvsp[0].id)); }
#line 2107 "grammar.tab.c"
    break;

  case 44: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 413 "grammar.y"
                {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ">="); strcat((yyval.id), (yyvsp[0].id)); }
#line 2113 "grammar.tab.c"
    break;

  case 45: /* equality_expression: relational_expression  */
#line 420 "grammar.y"
                                        {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2119 "grammar.tab.c"
    break;

  case 46: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 422 "grammar.y"
                {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "=="); strcat((yyval.id), (yyvsp[0].id)); }
#line 2125 "grammar.tab.c"
    break;

  case 47: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 424 "grammar.y"
                {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "<>"); strcat((yyval.id), (yyvsp[0].id)); }
#line 2131 "grammar.tab.c"
    break;

  case 48: /* and_expression: equality_expression  */
#line 432 "grammar.y"
        {	strcpy((yyval.id), (yyvsp[0].id)); }
#line 2137 "grammar.tab.c"
    break;

  case 49: /* and_expression: and_expression '&' equality_expression  */
#line 434 "grammar.y"
        {	strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "&"); strcat((yyval.id), (yyvsp[0].id)); }
#line 2143 "grammar.tab.c"
    break;

  case 50: /* exclusive_or_expression: and_expression  */
#line 441 "grammar.y"
                                {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2149 "grammar.tab.c"
    break;

  case 51: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 443 "grammar.y"
        {strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "^"); strcat((yyval.id), (yyvsp[0].id)); }
#line 2155 "grammar.tab.c"
    break;

  case 52: /* inclusive_or_expression: exclusive_or_expression  */
#line 450 "grammar.y"
                                        {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2161 "grammar.tab.c"
    break;

  case 53: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 452 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "|"); strcat((yyval.id), (yyvsp[0].id));}
#line 2167 "grammar.tab.c"
    break;

  case 54: /* logical_and_expression: inclusive_or_expression  */
#line 459 "grammar.y"
                                        {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2173 "grammar.tab.c"
    break;

  case 55: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 461 "grammar.y"
        {	strcpy((yyval.id), "andop(");	strcat((yyval.id), (yyvsp[-2].id)); 
		strcat((yyval.id), " , "); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")");
	}
#line 2181 "grammar.tab.c"
    break;

  case 56: /* logical_or_expression: logical_and_expression  */
#line 469 "grammar.y"
                                        {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2187 "grammar.tab.c"
    break;

  case 57: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 471 "grammar.y"
        {	strcpy((yyval.id), "orop("); strcat((yyval.id), (yyvsp[-2].id)); 
		strcat((yyval.id), " , "); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")"); 
	}
#line 2195 "grammar.tab.c"
    break;

  case 58: /* conditional_expression: logical_or_expression  */
#line 480 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[0].id)); }
#line 2201 "grammar.tab.c"
    break;

  case 59: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 482 "grammar.y"
        { 
		////////////////////////////////////////////////////////////////
		// Process ternary expressions from C to Prolog 		
		////////////////////////////////////////////////////////////////	
		strcpy((yyval.id), "ternary("); 
		strcat((yyval.id), "expression("); strcat((yyval.id), (yyvsp[-4].id)); strcat((yyval.id), "),");
		strcat((yyval.id), "["); strcat((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "]");
		strcat((yyval.id), ", "); strcat((yyval.id), "["); strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), "]"); strcat((yyval.id), ")");
	}
#line 2216 "grammar.tab.c"
    break;

  case 60: /* assignment_expression: conditional_expression  */
#line 497 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[0].id)); }
#line 2222 "grammar.tab.c"
    break;

  case 61: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 499 "grammar.y"
        { 		
		strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[-2].id)); 
		strcat((yyval.id), " , "); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")"); 
	}
#line 2231 "grammar.tab.c"
    break;

  case 62: /* assignment_operator: '='  */
#line 509 "grammar.y"
                        { strcpy((yyval.id), "\nassignment(");      }
#line 2237 "grammar.tab.c"
    break;

  case 63: /* assignment_operator: MUL_ASSIGN  */
#line 510 "grammar.y"
                        { strcpy((yyval.id), "\nmul_assignment(");  }
#line 2243 "grammar.tab.c"
    break;

  case 64: /* assignment_operator: DIV_ASSIGN  */
#line 511 "grammar.y"
                        { strcpy((yyval.id), "\ndiv_assignment(");  }
#line 2249 "grammar.tab.c"
    break;

  case 65: /* assignment_operator: MOD_ASSIGN  */
#line 512 "grammar.y"
                        { strcpy((yyval.id), "\nmod_assignment(");  }
#line 2255 "grammar.tab.c"
    break;

  case 66: /* assignment_operator: ADD_ASSIGN  */
#line 513 "grammar.y"
                        { strcpy((yyval.id), "\nadd_assignment(");  }
#line 2261 "grammar.tab.c"
    break;

  case 67: /* assignment_operator: SUB_ASSIGN  */
#line 514 "grammar.y"
                        { strcpy((yyval.id), "\nsub_assignment(");  }
#line 2267 "grammar.tab.c"
    break;

  case 68: /* assignment_operator: LEFT_ASSIGN  */
#line 515 "grammar.y"
                        { strcpy((yyval.id), "\nleft_assignment("); }
#line 2273 "grammar.tab.c"
    break;

  case 69: /* assignment_operator: RIGHT_ASSIGN  */
#line 516 "grammar.y"
                        { strcpy((yyval.id), "\nright_assignment(");}
#line 2279 "grammar.tab.c"
    break;

  case 70: /* assignment_operator: AND_ASSIGN  */
#line 517 "grammar.y"
                        { strcpy((yyval.id), "\nand_assignment(");  }
#line 2285 "grammar.tab.c"
    break;

  case 71: /* assignment_operator: XOR_ASSIGN  */
#line 518 "grammar.y"
                        { strcpy((yyval.id), "\nxor_assignment(");  }
#line 2291 "grammar.tab.c"
    break;

  case 72: /* assignment_operator: OR_ASSIGN  */
#line 519 "grammar.y"
                        { strcpy((yyval.id), "\nor_assignment(");   }
#line 2297 "grammar.tab.c"
    break;

  case 73: /* expression: assignment_expression  */
#line 526 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[0].id)); }
#line 2303 "grammar.tab.c"
    break;

  case 74: /* expression: expression ',' assignment_expression  */
#line 528 "grammar.y"
        { 	strcpy((yyval.id), "comma("); strcat((yyval.id), (yyvsp[-2].id));
		strcat((yyval.id), " , "); strcat((yyval.id), (yyvsp[0].id)); strcat((yyval.id), ")"); 
	}
#line 2311 "grammar.tab.c"
    break;

  case 75: /* constant_expression: conditional_expression  */
#line 537 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[0].id)); }
#line 2317 "grammar.tab.c"
    break;

  case 76: /* declaration: declaration_specifiers ';'  */
#line 545 "grammar.y"
        { 
		strcpy((yyval.id), struct_declaration((yyvsp[-1].id)));	// STRUCTURES.H
	}
#line 2325 "grammar.tab.c"
    break;

  case 77: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 549 "grammar.y"
        { 		
		////////////////////////////////////////////////////////////////
		// Process declarations		
		////////////////////////////////////////////////////////////////
		int lenSS;
		strcpy((yyval.id), findvariabledetails((yyvsp[-2].id)));	// DECL_FUNCTIONS.H
		lenSS = strlen((yyval.id)) - 1;
		
		if ((yyval.id)[lenSS] != ',')
			strcat((yyval.id), ",");
	}
#line 2341 "grammar.tab.c"
    break;

  case 78: /* declaration_specifiers: storage_class_specifier  */
#line 567 "grammar.y"
        { strcpy((yyval.id), (yyvsp[0].id));  }
#line 2347 "grammar.tab.c"
    break;

  case 79: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 569 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-1].id));  strcat((yyval.id), (yyvsp[0].id));}
#line 2353 "grammar.tab.c"
    break;

  case 80: /* declaration_specifiers: type_specifier  */
#line 571 "grammar.y"
        { strcpy((yyval.id), (yyvsp[0].id)); }
#line 2359 "grammar.tab.c"
    break;

  case 81: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 573 "grammar.y"
        {	
		////////////////////////////////////////////////////////////////
		// Only append comma if not a type such as "unsigned int"
		////////////////////////////////////////////////////////////////		
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
	}
#line 2381 "grammar.tab.c"
    break;

  case 82: /* declaration_specifiers: type_qualifier  */
#line 591 "grammar.y"
        {strcpy((yyval.id), (yyvsp[0].id)); }
#line 2387 "grammar.tab.c"
    break;

  case 83: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 593 "grammar.y"
        {strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); }
#line 2393 "grammar.tab.c"
    break;

  case 84: /* init_declarator_list: init_declarator  */
#line 601 "grammar.y"
        { strcpy((yyval.id), (yyvsp[0].id));   }
#line 2399 "grammar.tab.c"
    break;

  case 85: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 603 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ", "); strcat((yyval.id), (yyvsp[0].id)); }
#line 2405 "grammar.tab.c"
    break;

  case 86: /* init_declarator: declarator  */
#line 611 "grammar.y"
        { 		
		strcpy((yyval.id), (yyvsp[0].id)); addvariables((yyvsp[0].id), NO);	// DECL_FUNCTIONS.H
	}
#line 2413 "grammar.tab.c"
    break;

  case 87: /* init_declarator: declarator '=' initializer  */
#line 615 "grammar.y"
        { 					
		strcpy((yyval.id), (yyvsp[-2].id)); addvariabledetails((yyvsp[-2].id), (yyvsp[0].id));// DECL_FUNCTIONS.H
	}
#line 2421 "grammar.tab.c"
    break;

  case 88: /* storage_class_specifier: TYPEDEF  */
#line 625 "grammar.y"
        { 
		strcpy((yyval.id), "typedef"); 
		set_typedef_flag();	// TYPEDEF_FUNCTIONS.H
	}
#line 2430 "grammar.tab.c"
    break;

  case 89: /* storage_class_specifier: EXTERN  */
#line 629 "grammar.y"
                        { strcpy((yyval.id), ""); }
#line 2436 "grammar.tab.c"
    break;

  case 90: /* storage_class_specifier: STATIC  */
#line 630 "grammar.y"
                        { strcpy((yyval.id), ""); }
#line 2442 "grammar.tab.c"
    break;

  case 91: /* storage_class_specifier: AUTO  */
#line 631 "grammar.y"
                        { strcpy((yyval.id), ""); }
#line 2448 "grammar.tab.c"
    break;

  case 92: /* storage_class_specifier: REGISTER  */
#line 632 "grammar.y"
                        { strcpy((yyval.id), ""); }
#line 2454 "grammar.tab.c"
    break;

  case 93: /* type_specifier: VOID  */
#line 639 "grammar.y"
                                        { strcpy((yyval.id), "void"); 		}
#line 2460 "grammar.tab.c"
    break;

  case 94: /* type_specifier: CHAR  */
#line 640 "grammar.y"
                                        { strcpy((yyval.id), "char"); 		}
#line 2466 "grammar.tab.c"
    break;

  case 95: /* type_specifier: SHORT  */
#line 641 "grammar.y"
                                        { strcpy((yyval.id), "short"); 		}
#line 2472 "grammar.tab.c"
    break;

  case 96: /* type_specifier: INT  */
#line 642 "grammar.y"
                                        { strcpy((yyval.id), "int");  		}
#line 2478 "grammar.tab.c"
    break;

  case 97: /* type_specifier: LONG  */
#line 643 "grammar.y"
                                        { strcpy((yyval.id), "long");  	}
#line 2484 "grammar.tab.c"
    break;

  case 98: /* type_specifier: FLOAT  */
#line 644 "grammar.y"
                                        { strcpy((yyval.id), "floats"); 	}
#line 2490 "grammar.tab.c"
    break;

  case 99: /* type_specifier: DOUBLE  */
#line 645 "grammar.y"
                                        { strcpy((yyval.id), "double");  	}
#line 2496 "grammar.tab.c"
    break;

  case 100: /* type_specifier: SIGNED  */
#line 646 "grammar.y"
                                        { strcpy((yyval.id), "signed"); 	}
#line 2502 "grammar.tab.c"
    break;

  case 101: /* type_specifier: UNSIGNED  */
#line 647 "grammar.y"
                                        { strcpy((yyval.id), "unsigned"); 	}
#line 2508 "grammar.tab.c"
    break;

  case 102: /* type_specifier: struct_or_union_specifier  */
#line 648 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[0].id));		}
#line 2514 "grammar.tab.c"
    break;

  case 103: /* type_specifier: enum_specifier  */
#line 649 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[0].id)); 		}
#line 2520 "grammar.tab.c"
    break;

  case 104: /* type_specifier: TYPE_NAME  */
#line 651 "grammar.y"
        { 					  
		add_typedefs(change_typedef((yyvsp[0].id)));// TYPEDEF_FUNCTIONS.H					
		strcpy((yyval.id), change_typedef((yyvsp[0].id)));	 // TYPEDEF_FUNCTIONS.H
	}
#line 2529 "grammar.tab.c"
    break;

  case 105: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 662 "grammar.y"
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
		printnames(struct_name, (yyvsp[-3].id));
		
		////////////////////////////////////////////////////
		strcpy((yyval.id), (yyvsp[-4].id)); strcat((yyval.id), ", "); 
		strcat((yyval.id), struct_name); strcat((yyval.id), ", ");  strcat((yyval.id), "["); 
		strcat((yyval.id), (yyvsp[-1].id)); 
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 2553 "grammar.tab.c"
    break;

  case 106: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 682 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[-3].id)); strcat((yyval.id), ", ["); strcat((yyval.id), (yyvsp[-1].id)); 
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");		
	}
#line 2563 "grammar.tab.c"
    break;

  case 107: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 688 "grammar.y"
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
		printnames(struct_name, (yyvsp[0].id));
		
		////////////////////////////////////////////////////		
		strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ", "); 
		strcat((yyval.id), struct_name); 	
	}
#line 2584 "grammar.tab.c"
    break;

  case 108: /* struct_or_union: STRUCT  */
#line 710 "grammar.y"
                        { strcpy((yyval.id), "struct "); }
#line 2590 "grammar.tab.c"
    break;

  case 109: /* struct_or_union: UNION  */
#line 711 "grammar.y"
                        { strcpy((yyval.id), "union ");  }
#line 2596 "grammar.tab.c"
    break;

  case 110: /* struct_declaration_list: struct_declaration  */
#line 719 "grammar.y"
        { strcpy((yyval.id), (yyvsp[0].id)); }
#line 2602 "grammar.tab.c"
    break;

  case 111: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 721 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ", "); strcat((yyval.id), (yyvsp[0].id)); }
#line 2608 "grammar.tab.c"
    break;

  case 112: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 729 "grammar.y"
        { 
		/////////////////////////////////////////////////////////////////
		// Many variables declared in $2, they must be separated.		
		if (strstr((yyvsp[-1].id), ",") != NULL) 
		{
			strcpy((yyval.id), seperate_fields((yyvsp[-2].id), (yyvsp[-1].id))); // STRUCTURES.H
		}
		else 
		/////////////////////////////////////////////////////////////////
		// Build the structure list, removing the 'struct' keyword if present		
		{	
			strcpy((yyval.id), "([");   strcat((yyval.id), (yyvsp[-1].id)); 
			strcat((yyval.id), "], ");  strcpy((yyvsp[-2].id), strip_struct((yyvsp[-2].id)));// STRUCTURES.H			
			strcat((yyval.id), (yyvsp[-2].id));     strcat((yyval.id), ")");
		}
	}
#line 2629 "grammar.tab.c"
    break;

  case 113: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 751 "grammar.y"
                                                        { strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); }
#line 2635 "grammar.tab.c"
    break;

  case 114: /* specifier_qualifier_list: type_specifier  */
#line 752 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id));  }
#line 2641 "grammar.tab.c"
    break;

  case 115: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 753 "grammar.y"
                                                        { strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); }
#line 2647 "grammar.tab.c"
    break;

  case 116: /* specifier_qualifier_list: type_qualifier  */
#line 754 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id));  }
#line 2653 "grammar.tab.c"
    break;

  case 117: /* struct_declarator_list: struct_declarator  */
#line 762 "grammar.y"
        { 
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]);  strcpy((yyval.id), (yyvsp[0].id));
	}
#line 2661 "grammar.tab.c"
    break;

  case 118: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 766 "grammar.y"
        { 	strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ","); 
		(yyvsp[0].id)[0] = convert_tolower((yyvsp[0].id)[0]); strcat((yyval.id), (yyvsp[0].id));
	}
#line 2669 "grammar.tab.c"
    break;

  case 119: /* struct_declarator: declarator  */
#line 775 "grammar.y"
                        {  strcpy((yyval.id), (yyvsp[0].id)); }
#line 2675 "grammar.tab.c"
    break;

  case 120: /* struct_declarator: ':' constant_expression  */
#line 776 "grammar.y"
                                        { strcpy((yyval.id), ":"); strcat((yyval.id), (yyvsp[0].id));}
#line 2681 "grammar.tab.c"
    break;

  case 121: /* struct_declarator: declarator ':' constant_expression  */
#line 777 "grammar.y"
                                               {  strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ":"); strcat((yyval.id), (yyvsp[0].id));}
#line 2687 "grammar.tab.c"
    break;

  case 122: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 784 "grammar.y"
        { 	////////////////////////////////////////////////////////////////
		// Build enumeration list.
		// Pop Scope when '}' is parsed and reset enumerations counter
		
		strcpy((yyval.id), "enum , "); strcat((yyval.id), "["); strcat((yyval.id), (yyvsp[-1].id)); 
		Pop(); 			// SCOPES.H
		strcat((yyval.id), "]"); 
		reset_enumcounter(); 	// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
#line 2702 "grammar.tab.c"
    break;

  case 123: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 795 "grammar.y"
        { 	////////////////////////////////////////////////////////////////
		// Build enumeration list.
		// Change their name to Prolog equivalent using change_enum()
		// Add the name to NAMES file using printnames()
		// Add the literal to Enum linked list using add_enums()
		// Pop Scope when '}' is parsed and reset enumerations counter
		
		char *enum_name;
		enum_name = (char *) malloc(STRING_LIMIT);
		
		strcpy(enum_name, change_enum((yyvsp[-3].id)));	// ENUM_FUNCTIONS.H
		printnames(enum_name, (yyvsp[-3].id));		// OUTPUT_FUNCTIONS.H
		
		strcpy((yyval.id), "enum , "); strcat((yyval.id), "["); strcat((yyval.id), enum_name);		
		strcat((yyval.id), "]");       strcat((yyval.id), ", ");strcat((yyval.id), "["); 
		strcat((yyval.id), (yyvsp[-1].id)); 
		Pop(); 					// SCOPES.H
		strcat((yyval.id), "]"); 
		reset_enumcounter(); 			// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
#line 2728 "grammar.tab.c"
    break;

  case 124: /* enum_specifier: ENUM IDENTIFIER  */
#line 817 "grammar.y"
        { 	////////////////////////////////////////////////////////////////
		// Change enum name to Prolog equivalent using change_enum()
		strcpy((yyval.id), "enum , "); 		
		strcat((yyval.id), change_enum((yyvsp[0].id)));	// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
#line 2739 "grammar.tab.c"
    break;

  case 125: /* enumerator_list: enumerator  */
#line 830 "grammar.y"
        {
			strcpy((yyval.id), (yyvsp[0].id)); 
	}
#line 2747 "grammar.tab.c"
    break;

  case 126: /* enumerator_list: enumerator_list ',' enumerator  */
#line 834 "grammar.y"
        {	
		strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ", "); strcat((yyval.id), (yyvsp[0].id)); 
	}
#line 2755 "grammar.tab.c"
    break;

  case 127: /* enumerator: IDENTIFIER  */
#line 844 "grammar.y"
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
		printnames(enum_name, (yyvsp[0].id));		// OUTPUT_FUNCTIONS.H	
		strcpy((yyval.id), enum_name);
		add_enums((yyvsp[0].id), -1);			// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
#line 2776 "grammar.tab.c"
    break;

  case 128: /* enumerator: IDENTIFIER '=' constant_expression  */
#line 861 "grammar.y"
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
		printnames(enum_name, (yyvsp[-2].id));		// OUTPUT_FUNCTIONS.H
		strcpy((yyval.id), enum_name);				
		i = atoi((yyvsp[0].id));				// change string to integer
		add_enums((yyvsp[-2].id), i); 			// ENUM_FUNCTIONS.H
		////////////////////////////////////////////////////////////////
	}
#line 2801 "grammar.tab.c"
    break;

  case 129: /* type_qualifier: CONST  */
#line 887 "grammar.y"
                        { strcpy((yyval.id), "const"); }
#line 2807 "grammar.tab.c"
    break;

  case 130: /* type_qualifier: VOLATILE  */
#line 888 "grammar.y"
                        { strcpy((yyval.id), "volatile"); }
#line 2813 "grammar.tab.c"
    break;

  case 131: /* declarator: pointer direct_declarator  */
#line 896 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); 
	}
#line 2821 "grammar.tab.c"
    break;

  case 132: /* declarator: direct_declarator  */
#line 900 "grammar.y"
        {  
		strcpy((yyval.id), (yyvsp[0].id));
	}
#line 2829 "grammar.tab.c"
    break;

  case 133: /* direct_declarator: IDENTIFIER  */
#line 910 "grammar.y"
        {  strcpy((yyval.id), (yyvsp[0].id)); }
#line 2835 "grammar.tab.c"
    break;

  case 134: /* direct_declarator: '(' declarator ')'  */
#line 912 "grammar.y"
        { 	
		strcpy((yyval.id), "("); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ")");
	}
#line 2843 "grammar.tab.c"
    break;

  case 135: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 916 "grammar.y"
        { 	
		strcpy((yyval.id), (yyvsp[-3].id)); strcat((yyval.id), "["); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "]"); 
	}
#line 2851 "grammar.tab.c"
    break;

  case 136: /* direct_declarator: direct_declarator '[' ']'  */
#line 920 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "["); strcat((yyval.id), "]"); }
#line 2857 "grammar.tab.c"
    break;

  case 137: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 922 "grammar.y"
        { 
		////////////////////////////////////////////////////////////////		
		/* 	function prototypes and definitions come through this rule.
			in order to distinguish them later on from variables we 
			add the string "function_prototype" to $$
			if this is the function defintion this will have to be stripped later.
			if it is the function prototype it is left as it is.
		*/
		////////////////////////////////////////////////////////////////		
		(yyvsp[-3].id)[0] = convert_tolower((yyvsp[-3].id)[0]);		
		strcpy((yyval.id), "function_prototype(");
		strcat((yyval.id), (yyvsp[-3].id));	strcat((yyval.id), ", "); strcat((yyval.id), "[");		
		strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "]"); strcat((yyval.id), ", "); strcat((yyval.id), ").");		
	}
#line 2876 "grammar.tab.c"
    break;

  case 138: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 937 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[-3].id)); strcat((yyval.id), "("); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ")"); 
	}
#line 2884 "grammar.tab.c"
    break;

  case 139: /* direct_declarator: direct_declarator '(' ')'  */
#line 941 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "("); strcat((yyval.id), ")"); 
	}
#line 2892 "grammar.tab.c"
    break;

  case 140: /* pointer: '*'  */
#line 951 "grammar.y"
        { strcpy((yyval.id), "*"); 	}
#line 2898 "grammar.tab.c"
    break;

  case 141: /* pointer: '*' type_qualifier_list  */
#line 953 "grammar.y"
        { strcpy((yyval.id), "*"); strcat((yyval.id), (yyvsp[0].id));  }
#line 2904 "grammar.tab.c"
    break;

  case 142: /* pointer: '*' pointer  */
#line 955 "grammar.y"
        { strcpy((yyval.id), "*"); strcat((yyval.id), (yyvsp[0].id)); }
#line 2910 "grammar.tab.c"
    break;

  case 143: /* pointer: '*' type_qualifier_list pointer  */
#line 957 "grammar.y"
        { strcpy((yyval.id), "*"); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id));   }
#line 2916 "grammar.tab.c"
    break;

  case 144: /* type_qualifier_list: type_qualifier  */
#line 964 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id));  }
#line 2922 "grammar.tab.c"
    break;

  case 145: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 965 "grammar.y"
                                                { strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id));  }
#line 2928 "grammar.tab.c"
    break;

  case 146: /* parameter_type_list: parameter_list  */
#line 973 "grammar.y"
        { 
		int lenSS = strlen((yyvsp[0].id)) - 1;
		if ((yyvsp[0].id)[lenSS] == ',')	
			(yyvsp[0].id)[lenSS] = ' ';
		strcpy((yyval.id), (yyvsp[0].id)); 
	}
#line 2939 "grammar.tab.c"
    break;

  case 147: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 979 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ","); strcat((yyval.id), "..."); }
#line 2945 "grammar.tab.c"
    break;

  case 148: /* parameter_list: parameter_declaration  */
#line 987 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[0].id));  
	}
#line 2953 "grammar.tab.c"
    break;

  case 149: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 991 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[-2].id)); 
		strcat((yyval.id), (yyvsp[0].id));  
	}
#line 2962 "grammar.tab.c"
    break;

  case 150: /* parameter_declaration: declaration_specifiers declarator  */
#line 1002 "grammar.y"
        { 			
		if (PListFirstUse == NO)	// PARAMETERS.H
		{
			PListFirstUse = YES;	// PARAMETERS.H
			P = CreatePList();	// PARAMETERS.H
		}	
		PushPList((yyvsp[0].id), P);		// PARAMETERS.H
		addvariables((yyvsp[0].id), YES);			// DECL_FUNCTIONS.H
		strcpy((yyval.id), findvariabledetails((yyvsp[-1].id)));	// DECL_FUNCTIONS.H	
	}
#line 2977 "grammar.tab.c"
    break;

  case 151: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 1013 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); 
	}
#line 2985 "grammar.tab.c"
    break;

  case 152: /* parameter_declaration: declaration_specifiers  */
#line 1017 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[0].id));  
	}
#line 2993 "grammar.tab.c"
    break;

  case 153: /* identifier_list: IDENTIFIER  */
#line 1026 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id)); }
#line 2999 "grammar.tab.c"
    break;

  case 154: /* identifier_list: identifier_list ',' IDENTIFIER  */
#line 1027 "grammar.y"
                                                { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ","); strcat((yyval.id), (yyvsp[0].id)); }
#line 3005 "grammar.tab.c"
    break;

  case 155: /* type_name: specifier_qualifier_list  */
#line 1034 "grammar.y"
                                                { strcpy((yyval.id), (yyvsp[0].id));  }
#line 3011 "grammar.tab.c"
    break;

  case 156: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 1035 "grammar.y"
                                                        { strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); }
#line 3017 "grammar.tab.c"
    break;

  case 157: /* abstract_declarator: pointer  */
#line 1042 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id)); }
#line 3023 "grammar.tab.c"
    break;

  case 158: /* abstract_declarator: direct_abstract_declarator  */
#line 1043 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[0].id));  }
#line 3029 "grammar.tab.c"
    break;

  case 159: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 1044 "grammar.y"
                                                { strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); }
#line 3035 "grammar.tab.c"
    break;

  case 160: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 1051 "grammar.y"
                                        { strcpy((yyval.id), "("); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "("); }
#line 3041 "grammar.tab.c"
    break;

  case 161: /* direct_abstract_declarator: '[' ']'  */
#line 1052 "grammar.y"
                                        { strcpy((yyval.id), "["); strcat((yyval.id), "]"); }
#line 3047 "grammar.tab.c"
    break;

  case 162: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 1053 "grammar.y"
                                        { strcpy((yyval.id), "["); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "]"); }
#line 3053 "grammar.tab.c"
    break;

  case 163: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 1054 "grammar.y"
                                                { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "["); strcat((yyval.id), "]"); }
#line 3059 "grammar.tab.c"
    break;

  case 164: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 1055 "grammar.y"
                                                                        { strcpy((yyval.id), (yyvsp[-3].id)); strcat((yyval.id), "["); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), "]"); }
#line 3065 "grammar.tab.c"
    break;

  case 165: /* direct_abstract_declarator: '(' ')'  */
#line 1056 "grammar.y"
                                { strcpy((yyval.id), "("); strcat((yyval.id), ")"); }
#line 3071 "grammar.tab.c"
    break;

  case 166: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 1058 "grammar.y"
        { strcpy((yyval.id), "("); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ")"); 
	}
#line 3078 "grammar.tab.c"
    break;

  case 167: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 1061 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), "("); strcat((yyval.id), ")"); 
	}
#line 3085 "grammar.tab.c"
    break;

  case 168: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 1064 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-3].id)); strcat((yyval.id), "("); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ")"); 	
	}
#line 3092 "grammar.tab.c"
    break;

  case 169: /* initializer: assignment_expression  */
#line 1073 "grammar.y"
        { 
		strcpy((yyval.id), (yyvsp[0].id)); 
	}
#line 3100 "grammar.tab.c"
    break;

  case 170: /* initializer: '{' initializer_list '}'  */
#line 1077 "grammar.y"
        { 
		strcpy((yyval.id), "["); strcat((yyval.id), (yyvsp[-1].id)); 
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]"); 
	}
#line 3110 "grammar.tab.c"
    break;

  case 171: /* initializer: '{' initializer_list ',' '}'  */
#line 1083 "grammar.y"
        {
		strcpy((yyval.id), "{"); strcat((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ","); 
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "}"); 
	}
#line 3120 "grammar.tab.c"
    break;

  case 172: /* initializer_list: initializer  */
#line 1094 "grammar.y"
                        { strcpy((yyval.id), (yyvsp[0].id)); }
#line 3126 "grammar.tab.c"
    break;

  case 173: /* initializer_list: initializer_list ',' initializer  */
#line 1096 "grammar.y"
        { strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ","); strcat((yyval.id), (yyvsp[0].id)); 	}
#line 3132 "grammar.tab.c"
    break;

  case 174: /* statement: labeled_statement  */
#line 1103 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id)); }
#line 3138 "grammar.tab.c"
    break;

  case 175: /* statement: compound_statement  */
#line 1104 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id)); }
#line 3144 "grammar.tab.c"
    break;

  case 176: /* statement: expression_statement  */
#line 1105 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id)); }
#line 3150 "grammar.tab.c"
    break;

  case 177: /* statement: selection_statement  */
#line 1106 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id)); }
#line 3156 "grammar.tab.c"
    break;

  case 178: /* statement: iteration_statement  */
#line 1107 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id)); }
#line 3162 "grammar.tab.c"
    break;

  case 179: /* statement: jump_statement  */
#line 1108 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[0].id)); }
#line 3168 "grammar.tab.c"
    break;

  case 180: /* labeled_statement: IDENTIFIER ':' statement  */
#line 1116 "grammar.y"
        {  
		strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), ":"); strcat((yyval.id), (yyvsp[0].id));  
	}
#line 3176 "grammar.tab.c"
    break;

  case 181: /* labeled_statement: CASE constant_expression ':' statement  */
#line 1120 "grammar.y"
        {
		strcpy((yyval.id), case_statement((yyvsp[-2].id), (yyvsp[0].id)));	// SWITCH_FUNCTIONS.H
	}
#line 3184 "grammar.tab.c"
    break;

  case 182: /* labeled_statement: DEFAULT ':' statement  */
#line 1124 "grammar.y"
        { 
		strcpy((yyval.id), default_statement((yyvsp[0].id)));  	// SWITCH_FUNCTIONS.H
	}
#line 3192 "grammar.tab.c"
    break;

  case 183: /* compound_statement: '{' '}'  */
#line 1134 "grammar.y"
        {	strcpy((yyval.id), "["); 
		Pop(); 	// SCOPES.H
		strcat((yyval.id), "]");
	}
#line 3201 "grammar.tab.c"
    break;

  case 184: /* compound_statement: '{' statement_list '}'  */
#line 1139 "grammar.y"
        {	
		strcpy((yyval.id), "["); strcat((yyval.id), (yyvsp[-1].id)); 		
		Pop();  	// SCOPES.H
		strcat((yyval.id), "]"); 
	}
#line 3211 "grammar.tab.c"
    break;

  case 185: /* compound_statement: '{' declaration_list '}'  */
#line 1145 "grammar.y"
        {
		int lenS2 = strlen((yyvsp[-1].id)) - 1;
		if ((yyvsp[-1].id)[lenS2] == ',')
			(yyvsp[-1].id)[lenS2] = ' ';		
		strcpy((yyval.id), "["); strcat((yyval.id), (yyvsp[-1].id)); 		
		Pop(); 	 // SCOPES.H
		strcat((yyval.id), "\n]"); 
	}
#line 3224 "grammar.tab.c"
    break;

  case 186: /* compound_statement: '{' declaration_list statement_list '}'  */
#line 1154 "grammar.y"
        {
		strcpy((yyval.id), "["); strcat((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), (yyvsp[-1].id)); 
		Pop(); 	 // SCOPES.H
		strcat((yyval.id), "\n]");  
	}
#line 3234 "grammar.tab.c"
    break;

  case 187: /* declaration_list: declaration  */
#line 1165 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[0].id)); 		  }
#line 3240 "grammar.tab.c"
    break;

  case 188: /* declaration_list: declaration_list declaration  */
#line 1166 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); }
#line 3246 "grammar.tab.c"
    break;

  case 189: /* statement_list: statement  */
#line 1173 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[0].id)); }
#line 3252 "grammar.tab.c"
    break;

  case 190: /* statement_list: statement_list statement  */
#line 1174 "grammar.y"
                                        { strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ", "); strcat((yyval.id), (yyvsp[0].id));  }
#line 3258 "grammar.tab.c"
    break;

  case 191: /* expression_statement: ';'  */
#line 1181 "grammar.y"
                                        { strcpy((yyval.id), "null");   }
#line 3264 "grammar.tab.c"
    break;

  case 192: /* expression_statement: expression ';'  */
#line 1182 "grammar.y"
                                { strcpy((yyval.id), (yyvsp[-1].id));   	}
#line 3270 "grammar.tab.c"
    break;

  case 193: /* selection_statement: IF '(' expression ')' statement  */
#line 1190 "grammar.y"
        {	
		strcpy((yyval.id), if_statement((yyvsp[-2].id), (yyvsp[0].id))); 	  // IF_FUNCTIONS.H
	}
#line 3278 "grammar.tab.c"
    break;

  case 194: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 1194 "grammar.y"
        { 	strcpy((yyval.id), ifelse_statement((yyvsp[-4].id), (yyvsp[-2].id), (yyvsp[0].id))); // IF_FUNCTIONS.H
	}
#line 3285 "grammar.tab.c"
    break;

  case 195: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 1197 "grammar.y"
        {
		strcpy((yyval.id), switch_statement((yyvsp[-2].id), (yyvsp[0].id)));	  // SWITCH_FUNCTIONS.H 
	}
#line 3293 "grammar.tab.c"
    break;

  case 196: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 1207 "grammar.y"
        { 	strcpy((yyval.id), while_statement((yyvsp[-2].id), (yyvsp[0].id)));	 // ITERATION_FUNCTIONS.H 
	}
#line 3300 "grammar.tab.c"
    break;

  case 197: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 1210 "grammar.y"
        { 	strcpy((yyval.id), do_statement((yyvsp[-5].id), (yyvsp[-2].id)));	 // ITERATION_FUNCTIONS.H 
	}
#line 3307 "grammar.tab.c"
    break;

  case 198: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 1213 "grammar.y"
        {	strcpy((yyval.id), for2_statement((yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[0].id)));	 // ITERATION_FUNCTIONS.H  
	}
#line 3314 "grammar.tab.c"
    break;

  case 199: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 1216 "grammar.y"
        {	strcpy((yyval.id), for_statement((yyvsp[-4].id), (yyvsp[-3].id), (yyvsp[-2].id), (yyvsp[0].id)));// ITERATION_FUNCTIONS.H 
	}
#line 3321 "grammar.tab.c"
    break;

  case 200: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 1224 "grammar.y"
                                {strcpy((yyval.id), "goto"); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ";"); }
#line 3327 "grammar.tab.c"
    break;

  case 201: /* jump_statement: CONTINUE ';'  */
#line 1225 "grammar.y"
                                {strcpy((yyval.id), "continue");  }
#line 3333 "grammar.tab.c"
    break;

  case 202: /* jump_statement: BREAK ';'  */
#line 1226 "grammar.y"
                                {strcpy((yyval.id), "break");    }
#line 3339 "grammar.tab.c"
    break;

  case 203: /* jump_statement: RETURN ';'  */
#line 1227 "grammar.y"
                                {strcpy((yyval.id), "return");  }
#line 3345 "grammar.tab.c"
    break;

  case 204: /* jump_statement: RETURN expression ';'  */
#line 1228 "grammar.y"
                                {strcpy((yyval.id), "return("); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), ")");}
#line 3351 "grammar.tab.c"
    break;

  case 205: /* translation_unit: external_declaration  */
#line 1235 "grammar.y"
                                {strcpy((yyval.id), (yyvsp[0].id));  }
#line 3357 "grammar.tab.c"
    break;

  case 206: /* translation_unit: translation_unit external_declaration  */
#line 1237 "grammar.y"
        {strcpy((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id));  }
#line 3363 "grammar.tab.c"
    break;

  case 207: /* external_declaration: function_definition  */
#line 1245 "grammar.y"
        {	
		strcpy((yyval.id), (yyvsp[0].id)); 
		printfunction((yyval.id)); 	// OUTPUT_FUNCTIONS.H
	}
#line 3372 "grammar.tab.c"
    break;

  case 208: /* external_declaration: declaration  */
#line 1250 "grammar.y"
        {	////////////////////////////////////////////////////////////////
		// Global Variable declarations
		////////////////////////////////////////////////////////////////
		int lenS1 = strlen((yyvsp[0].id)) - 1;
		strcpy((yyval.id), "\nglobal_variables([");
		if((yyvsp[0].id)[lenS1] == ',')
			(yyvsp[0].id)[lenS1] = ' ';	   
		strcat((yyval.id), (yyvsp[0].id));
		strcat((yyval.id), "], void).\n");	   
		printfunction((yyval.id));	// OUTPUT_FUNCTIONS.H
	}
#line 3388 "grammar.tab.c"
    break;

  case 209: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 1265 "grammar.y"
        {	
		strcpy((yyval.id), (yyvsp[-3].id)); strcat((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); 
	}
#line 3396 "grammar.tab.c"
    break;

  case 210: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 1269 "grammar.y"
        {	
		////////////////////////////////////////////////////////////////
		// Function Defintions
		////////////////////////////////////////////////////////////////
		strcpy((yyval.id), process_functions((yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].id)));	// DECL_FUNCTIONS.H
	}
#line 3407 "grammar.tab.c"
    break;

  case 211: /* function_definition: declarator declaration_list compound_statement  */
#line 1276 "grammar.y"
        {
		strcpy((yyval.id), (yyvsp[-2].id)); strcat((yyval.id), (yyvsp[-1].id)); strcat((yyval.id), (yyvsp[0].id)); 
	}
#line 3415 "grammar.tab.c"
    break;

  case 212: /* function_definition: declarator compound_statement  */
#line 1280 "grammar.y"
        {  			
		////////////////////////////////////////////////////////////////
		// Function Prototypes
		////////////////////////////////////////////////////////////////		
		strcpy((yyval.id), process_prototypes((yyvsp[-1].id), (yyvsp[0].id)));	// DECL_FUNCTIONS.H
	}
#line 3426 "grammar.tab.c"
    break;


#line 3430 "grammar.tab.c"

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

#line 1293 "grammar.y"

#include "lex.yy.c"		// include the lexical analyser file

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// *** END GRAMMAR.Y SPECIFICATION FILE
////////////////////////////////////////////////////////////////
