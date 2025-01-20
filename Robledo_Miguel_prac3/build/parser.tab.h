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

#ifndef YY_YY_BUILD_PARSER_TAB_H_INCLUDED
# define YY_YY_BUILD_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 38 "parser.y"

    #include "../include/data.h"
    #include "../include/functions.h"
    #include "../include/symtab.h"

#line 55 "build/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASSIGN = 258,                  /* ASSIGN  */
    ENDLINE = 259,                 /* ENDLINE  */
    INTEGER = 260,                 /* INTEGER  */
    ID = 261,                      /* ID  */
    REAL = 262,                    /* REAL  */
    STRING = 263,                  /* STRING  */
    BOOLEAN = 264,                 /* BOOLEAN  */
    PLUS = 265,                    /* PLUS  */
    MINUS = 266,                   /* MINUS  */
    MULT = 267,                    /* MULT  */
    DIV = 268,                     /* DIV  */
    MOD = 269,                     /* MOD  */
    GT = 270,                      /* GT  */
    GE = 271,                      /* GE  */
    LT = 272,                      /* LT  */
    LE = 273,                      /* LE  */
    EQ = 274,                      /* EQ  */
    NE = 275,                      /* NE  */
    NOT = 276,                     /* NOT  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    PI = 279,                      /* PI  */
    E = 280,                       /* E  */
    LBRACKET = 281,                /* LBRACKET  */
    RBRACKET = 282,                /* RBRACKET  */
    LPAREN = 283,                  /* LPAREN  */
    RPAREN = 284,                  /* RPAREN  */
    COMMA = 285,                   /* COMMA  */
    DOT = 286,                     /* DOT  */
    COMMENT = 287,                 /* COMMENT  */
    REPEAT = 288,                  /* REPEAT  */
    DO = 289,                      /* DO  */
    DONE = 290,                    /* DONE  */
    IF = 291,                      /* IF  */
    THEN = 292,                    /* THEN  */
    ELSE = 293,                    /* ELSE  */
    FI = 294,                      /* FI  */
    SWITCH = 295,                  /* SWITCH  */
    CASE = 296,                    /* CASE  */
    DEFAULT = 297,                 /* DEFAULT  */
    BREAK = 298,                   /* BREAK  */
    FSWITCH = 299,                 /* FSWITCH  */
    WHILE = 300,                   /* WHILE  */
    UNTIL = 301,                   /* UNTIL  */
    FOR = 302,                     /* FOR  */
    IN = 303                       /* IN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "parser.y"

    struct {
        char *lexema;
        int lenght;
        int line;
        value_info id_val;
        int is_literal;
        char *array_name;
        int index;
        instruction_list *true_list;
        instruction_list *false_list;
    } ident;
    int integer;
    float real;
    char *string;
    int boolean;
    void *no_value;
    struct {
        int instr;
    }   marker;
    struct {
        int instr;
        instruction_list *goto_end_list;
    } statement;

#line 146 "build/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_TAB_H_INCLUDED  */
