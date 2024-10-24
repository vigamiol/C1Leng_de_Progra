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

#ifndef YY_YY_AC_TAB_H_INCLUDED
# define YY_YY_AC_TAB_H_INCLUDED
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
    NUMERO = 258,                  /* NUMERO  */
    CREAR_AUTOMATA = 259,          /* CREAR_AUTOMATA  */
    CONECTAR_AUTOMATA = 260,       /* CONECTAR_AUTOMATA  */
    AJUSTAR_TASA = 261,            /* AJUSTAR_TASA  */
    IMPRIMIR_SISTEMA = 262,        /* IMPRIMIR_SISTEMA  */
    MOVER_INDIVIDUOS = 263,        /* MOVER_INDIVIDUOS  */
    ACTUALIZAR_ESTADOS = 264,      /* ACTUALIZAR_ESTADOS  */
    CAMBIAR_ESTADO_INDIVIDUO = 265, /* CAMBIAR_ESTADO_INDIVIDUO  */
    ESTADO = 266,                  /* ESTADO  */
    EJECUTAR_SIMULACION_LIBRE = 267, /* EJECUTAR_SIMULACION_LIBRE  */
    EJECUTAR_SIMULACION_CONFINAMIENTO = 268, /* EJECUTAR_SIMULACION_CONFINAMIENTO  */
    REINICIAR_SIMULACION = 269,    /* REINICIAR_SIMULACION  */
    REINICIAR_SISTEMA = 270,       /* REINICIAR_SISTEMA  */
    HABITANTES_CELDA = 271,        /* HABITANTES_CELDA  */
    ENDLINE = 272,                 /* ENDLINE  */
    SALIR = 273                    /* SALIR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 84 "ac.y"

  int ival;
  char strval[50];

#line 87 "ac.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_AC_TAB_H_INCLUDED  */
