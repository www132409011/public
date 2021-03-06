/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_TIGGER_TAB_HPP_INCLUDED
# define YY_YY_TIGGER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ENTER = 258,
    LBRK = 259,
    RBRK = 260,
    MALLOC = 261,
    IF = 262,
    GOTO = 263,
    CALL = 264,
    RETURN = 265,
    STORE = 266,
    LOAD = 267,
    LOADADDR = 268,
    COL = 269,
    END = 270,
    ASSIGN = 271,
    VARIABLE = 272,
    ADD = 273,
    MINUS = 274,
    MUL = 275,
    DIV = 276,
    MOD = 277,
    NOT = 278,
    LESS = 279,
    MORE = 280,
    LEQ = 281,
    GEQ = 282,
    EQUAL = 283,
    AND = 284,
    OR = 285,
    NEQ = 286,
    REG = 287,
    LABEL = 288,
    FUNC = 289,
    CONST_INT = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TIGGER_TAB_HPP_INCLUDED  */
