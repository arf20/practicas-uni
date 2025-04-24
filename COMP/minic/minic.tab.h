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

#ifndef YY_YY_MINIC_TAB_H_INCLUDED
# define YY_YY_MINIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
    RVAR = 258,                    /* RVAR  */
    RCONST = 259,                  /* RCONST  */
    RINT = 260,                    /* RINT  */
    RIF = 261,                     /* RIF  */
    RELSE = 262,                   /* RELSE  */
    RWHILE = 263,                  /* RWHILE  */
    RDO = 264,                     /* RDO  */
    RFOR = 265,                    /* RFOR  */
    RPRINT = 266,                  /* RPRINT  */
    RREAD = 267,                   /* RREAD  */
    SEMICOLON = 268,               /* SEMICOLON  */
    COMMA = 269,                   /* COMMA  */
    OPLUS = 270,                   /* OPLUS  */
    OMINUS = 271,                  /* OMINUS  */
    OASTERISK = 272,               /* OASTERISK  */
    OSLASH = 273,                  /* OSLASH  */
    OASSIGN = 274,                 /* OASSIGN  */
    OLESS = 275,                   /* OLESS  */
    OGREATER = 276,                /* OGREATER  */
    OLESSEQUAL = 277,              /* OLESSEQUAL  */
    OGREATEREQUAL = 278,           /* OGREATEREQUAL  */
    OEQUALS = 279,                 /* OEQUALS  */
    ONOTEQUALS = 280,              /* ONOTEQUALS  */
    PARENL = 281,                  /* PARENL  */
    PARENR = 282,                  /* PARENR  */
    BRACKETL = 283,                /* BRACKETL  */
    BRACKETR = 284,                /* BRACKETR  */
    QUESTIONMARK = 285,            /* QUESTIONMARK  */
    COLON = 286,                   /* COLON  */
    ID = 287,                      /* ID  */
    LSTR = 288,                    /* LSTR  */
    LINT = 289,                    /* LINT  */
    OUMINUS = 290                  /* OUMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 95 "minic.y"

    char *lex;
    ListaC code;

#line 104 "minic.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MINIC_TAB_H_INCLUDED  */
