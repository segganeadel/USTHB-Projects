/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNT_TAB_H_INCLUDED
# define YY_YY_SYNT_TAB_H_INCLUDED
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
    idf = 258,                     /* idf  */
    mc_int = 259,                  /* mc_int  */
    mc_float = 260,                /* mc_float  */
    mc_char = 261,                 /* mc_char  */
    mc_bool = 262,                 /* mc_bool  */
    mc_addition = 263,             /* mc_addition  */
    mc_moins = 264,                /* mc_moins  */
    mc_division = 265,             /* mc_division  */
    mc_multiplication = 266,       /* mc_multiplication  */
    mc_Sup = 267,                  /* mc_Sup  */
    mc_Inf = 268,                  /* mc_Inf  */
    mc_SupE = 269,                 /* mc_SupE  */
    mc_InfE = 270,                 /* mc_InfE  */
    mc_Egal = 271,                 /* mc_Egal  */
    mc_Diff = 272,                 /* mc_Diff  */
    mc_if = 273,                   /* mc_if  */
    mc_else = 274,                 /* mc_else  */
    mc_ligne = 275,                /* mc_ligne  */
    mc_import = 276,               /* mc_import  */
    mc_numpy = 277,                /* mc_numpy  */
    mc_as = 278,                   /* mc_as  */
    mc_matplotlibpyplot = 279,     /* mc_matplotlibpyplot  */
    mc_zeros = 280,                /* mc_zeros  */
    mc_ones = 281,                 /* mc_ones  */
    mc_arange = 282,               /* mc_arange  */
    mc_linspace = 283,             /* mc_linspace  */
    mc_randint = 284,              /* mc_randint  */
    mc_randn = 285,                /* mc_randn  */
    mc_dtype = 286,                /* mc_dtype  */
    mc_uint8 = 287,                /* mc_uint8  */
    mc_while = 288,                /* mc_while  */
    mc_for = 289,                  /* mc_for  */
    mc_in = 290,                   /* mc_in  */
    mc_range = 291,                /* mc_range  */
    mc_DPoint = 292,               /* mc_DPoint  */
    mc_point = 293,                /* mc_point  */
    Val_int = 294,                 /* Val_int  */
    Val_float = 295,               /* Val_float  */
    Val_char = 296,                /* Val_char  */
    Val_bool = 297,                /* Val_bool  */
    mc_not = 298,                  /* mc_not  */
    mc_and = 299,                  /* mc_and  */
    mc_or = 300,                   /* mc_or  */
    mc_parenthese_open = 301,      /* mc_parenthese_open  */
    mc_parenthese_close = 302,     /* mc_parenthese_close  */
    mc_bracket_open = 303,         /* mc_bracket_open  */
    mc_bracket_close = 304,        /* mc_bracket_close  */
    mc_affectation = 305,          /* mc_affectation  */
    mc_Vergule = 306,              /* mc_Vergule  */
    DEDENT = 307,                  /* DEDENT  */
    INDENT = 308                   /* INDENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "synt.y"

	int entier;
	char* str;
	float reel;


#line 124 "synt.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNT_TAB_H_INCLUDED  */
