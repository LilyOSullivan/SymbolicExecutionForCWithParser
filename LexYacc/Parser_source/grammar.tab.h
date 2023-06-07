/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    I_CONSTANT = 259,              /* I_CONSTANT  */
    F_CONSTANT = 260,              /* F_CONSTANT  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    FUNC_NAME = 262,               /* FUNC_NAME  */
    SIZEOF = 263,                  /* SIZEOF  */
    PTR_OP = 264,                  /* PTR_OP  */
    INC_OP = 265,                  /* INC_OP  */
    DEC_OP = 266,                  /* DEC_OP  */
    LEFT_OP = 267,                 /* LEFT_OP  */
    RIGHT_OP = 268,                /* RIGHT_OP  */
    LE_OP = 269,                   /* LE_OP  */
    GE_OP = 270,                   /* GE_OP  */
    EQ_OP = 271,                   /* EQ_OP  */
    NE_OP = 272,                   /* NE_OP  */
    AND_OP = 273,                  /* AND_OP  */
    OR_OP = 274,                   /* OR_OP  */
    MUL_ASSIGN = 275,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 276,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 277,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 278,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 279,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 280,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 281,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 282,              /* AND_ASSIGN  */
    XOR_ASSIGN = 283,              /* XOR_ASSIGN  */
    OR_ASSIGN = 284,               /* OR_ASSIGN  */
    TYPEDEF_NAME = 285,            /* TYPEDEF_NAME  */
    ENUMERATION_CONSTANT = 286,    /* ENUMERATION_CONSTANT  */
    ALIGN = 287,                   /* ALIGN  */
    TYPEDEF = 288,                 /* TYPEDEF  */
    EXTERN = 289,                  /* EXTERN  */
    STATIC = 290,                  /* STATIC  */
    AUTO = 291,                    /* AUTO  */
    REGISTER = 292,                /* REGISTER  */
    INLINE = 293,                  /* INLINE  */
    FORCEINLINE = 294,             /* FORCEINLINE  */
    CONST = 295,                   /* CONST  */
    RESTRICT = 296,                /* RESTRICT  */
    VOLATILE = 297,                /* VOLATILE  */
    BOOL = 298,                    /* BOOL  */
    CHAR = 299,                    /* CHAR  */
    SHORT = 300,                   /* SHORT  */
    INT = 301,                     /* INT  */
    LONG = 302,                    /* LONG  */
    SIGNED = 303,                  /* SIGNED  */
    UNSIGNED = 304,                /* UNSIGNED  */
    FLOAT = 305,                   /* FLOAT  */
    DOUBLE = 306,                  /* DOUBLE  */
    VOID = 307,                    /* VOID  */
    WCHAR_T = 308,                 /* WCHAR_T  */
    __INT8 = 309,                  /* __INT8  */
    __INT16 = 310,                 /* __INT16  */
    __INT32 = 311,                 /* __INT32  */
    __INT64 = 312,                 /* __INT64  */
    __PTR32 = 313,                 /* __PTR32  */
    __PTR64 = 314,                 /* __PTR64  */
    __UNALIGNED = 315,             /* __UNALIGNED  */
    COMPLEX = 316,                 /* COMPLEX  */
    IMAGINARY = 317,               /* IMAGINARY  */
    STRUCT = 318,                  /* STRUCT  */
    UNION = 319,                   /* UNION  */
    ENUM = 320,                    /* ENUM  */
    ELLIPSIS = 321,                /* ELLIPSIS  */
    DECLSPEC = 322,                /* DECLSPEC  */
    CASE = 323,                    /* CASE  */
    DEFAULT = 324,                 /* DEFAULT  */
    IF = 325,                      /* IF  */
    ELSE = 326,                    /* ELSE  */
    SWITCH = 327,                  /* SWITCH  */
    WHILE = 328,                   /* WHILE  */
    DO = 329,                      /* DO  */
    FOR = 330,                     /* FOR  */
    GOTO = 331,                    /* GOTO  */
    CONTINUE = 332,                /* CONTINUE  */
    BREAK = 333,                   /* BREAK  */
    RETURN = 334,                  /* RETURN  */
    ALIGNAS = 335,                 /* ALIGNAS  */
    ALIGNOF = 336,                 /* ALIGNOF  */
    ATOMIC = 337,                  /* ATOMIC  */
    GENERIC = 338,                 /* GENERIC  */
    NORETURN = 339,                /* NORETURN  */
    STATIC_ASSERT = 340,           /* STATIC_ASSERT  */
    THREAD_LOCAL = 341,            /* THREAD_LOCAL  */
    __CDECL = 342,                 /* __CDECL  */
    __CLRCALL = 343,               /* __CLRCALL  */
    __STDCALL = 344,               /* __STDCALL  */
    __FASTCALL = 345,              /* __FASTCALL  */
    __THISCALL = 346,              /* __THISCALL  */
    __VECTORCALL = 347             /* __VECTORCALL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "grammar.y"

	char *id;

#line 160 "grammar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
