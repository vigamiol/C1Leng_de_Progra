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
#line 3 "ac.y"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_INDIVIDUOS 100000
#define MAX_AUTOMATAS 10 // Máximo número de autómatas
 
static int total_movidos = 0;
static int total_cambios_estado = 0;
static int PROBABILIDAD_S=50;
static int PROBABILIDAD_E=50;
static int PROBABILIDAD_I=50;
static int PROBABILIDAD_R=50;
static int INDIVIDUOS_POR_CELDA = 100;
int should_exit = 0;

typedef enum {
  SUSCEPTIBLE, // Estado S
  EXPOSED,     // Estado E
  INFECTED,    // Estado I
  RECOVERED    // Estado R
} Estados;

typedef struct {
  Estados estado; // Estado del individuo
} Individuo;

typedef struct Cell {
  Individuo poblacion[MAX_INDIVIDUOS];
  int num_individuos;      // Contador de individuos en la célula
  struct Cell **neighbors; // Punteros a los vecinos de la célula
  int num_neighbors;       // Número de vecinos
  int row;                 // Fila de la celda
  int col;
} Cell;

typedef struct {
  int rows;    // Número de filas del AC
  int cols;    // Número de columnas del AC
  Cell **grid; // Puntero a la matriz bidimensional de células
} Automaton;

typedef struct {
  Automaton *automatons[MAX_AUTOMATAS]; // Arreglo de punteros a autómatas
  int count;                            // Número actual de autómatas
  int tiempo;
} Sistema;

Automaton *crear_automata(int rows, int cols);
void agregar_vecindad(Automaton *automaton);
void conectar_automatons(Sistema *sistema, int index1, int cell1_row,
                         int cell1_col, int index2, int cell2_row,
                         int cell2_col);
void liberar_automata(Automaton *automaton);
void imprimir_automata(Automaton *automaton);
void imprimir_vecinos(Automaton *automaton, int row, int col);
void mover_individuos(Cell *origen, Cell *destino);
void mover_individuos_en_sistema(Sistema *sistema);
void verificar_totales(Sistema *sistema);
void actualizar_estados(Sistema *sistema);
void imprimir_sistema(Sistema *sistema);
void liberar_sistema(Sistema *sistema);
void cambiar_estado_individuo(Sistema* sistema, int automaton_index, int cell_row, int cell_col, int individuo_index, Estados nuevo_estado);
void imprimir_estado(Sistema *sistema);
void avanzar_simulacion(Sistema *sistema, int pasos);
void avanzar_simulacion_confin(Sistema *sistema, int pasos);
void simular_libre(Sistema *sistema, int pasos);
void simular_confin(Sistema *sistema, int pasos);
void reiniciar_simulacion(Sistema *sistema);
void reiniciar_sistema(Sistema *sistema);
Sistema* inicializar_sistema(void);

Sistema* sistema = NULL;


int yylex();
void yyerror(const char*);



#line 152 "ac.tab.c"

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

#include "ac.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMERO = 3,                     /* NUMERO  */
  YYSYMBOL_CREAR_AUTOMATA = 4,             /* CREAR_AUTOMATA  */
  YYSYMBOL_CONECTAR_AUTOMATA = 5,          /* CONECTAR_AUTOMATA  */
  YYSYMBOL_AJUSTAR_TASA = 6,               /* AJUSTAR_TASA  */
  YYSYMBOL_IMPRIMIR_SISTEMA = 7,           /* IMPRIMIR_SISTEMA  */
  YYSYMBOL_MOVER_INDIVIDUOS = 8,           /* MOVER_INDIVIDUOS  */
  YYSYMBOL_ACTUALIZAR_ESTADOS = 9,         /* ACTUALIZAR_ESTADOS  */
  YYSYMBOL_CAMBIAR_ESTADO_INDIVIDUO = 10,  /* CAMBIAR_ESTADO_INDIVIDUO  */
  YYSYMBOL_ESTADO = 11,                    /* ESTADO  */
  YYSYMBOL_EJECUTAR_SIMULACION_LIBRE = 12, /* EJECUTAR_SIMULACION_LIBRE  */
  YYSYMBOL_EJECUTAR_SIMULACION_CONFINAMIENTO = 13, /* EJECUTAR_SIMULACION_CONFINAMIENTO  */
  YYSYMBOL_REINICIAR_SIMULACION = 14,      /* REINICIAR_SIMULACION  */
  YYSYMBOL_REINICIAR_SISTEMA = 15,         /* REINICIAR_SISTEMA  */
  YYSYMBOL_HABITANTES_CELDA = 16,          /* HABITANTES_CELDA  */
  YYSYMBOL_ENDLINE = 17,                   /* ENDLINE  */
  YYSYMBOL_SALIR = 18,                     /* SALIR  */
  YYSYMBOL_YYACCEPT = 19,                  /* $accept  */
  YYSYMBOL_instrucciones = 20,             /* instrucciones  */
  YYSYMBOL_instruccion = 21,               /* instruccion  */
  YYSYMBOL_funcion = 22,                   /* funcion  */
  YYSYMBOL_endline = 23                    /* endline  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   65

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  5
/* YYNRULES -- Number of rules.  */
#define YYNRULES  20
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  42

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


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
      15,    16,    17,    18
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   115,   115,   116,   120,   121,   122,   125,   155,   159,
     162,   180,   183,   186,   189,   192,   195,   198,   201,   204,
     211
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMERO",
  "CREAR_AUTOMATA", "CONECTAR_AUTOMATA", "AJUSTAR_TASA",
  "IMPRIMIR_SISTEMA", "MOVER_INDIVIDUOS", "ACTUALIZAR_ESTADOS",
  "CAMBIAR_ESTADO_INDIVIDUO", "ESTADO", "EJECUTAR_SIMULACION_LIBRE",
  "EJECUTAR_SIMULACION_CONFINAMIENTO", "REINICIAR_SIMULACION",
  "REINICIAR_SISTEMA", "HABITANTES_CELDA", "ENDLINE", "SALIR", "$accept",
  "instrucciones", "instruccion", "funcion", "endline", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-16)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      18,   -15,     8,    26,    10,   -16,   -16,   -16,    34,    35,
      36,   -16,   -16,    37,   -16,   -16,     0,   -16,   -15,   -16,
     -16,    38,    39,    40,    41,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,    42,   -16,    43,    44,    45,    46,    47,    48,
     -16,   -16
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    11,    13,    14,     0,     0,
       0,    17,    18,     0,    20,    19,     0,     3,     0,     5,
       6,     0,     0,     0,     0,    15,    16,     8,     1,     2,
       4,     7,     0,    10,     0,     0,     0,     0,     0,     0,
      12,     9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -16,   -16,    49,   -16,     2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    16,    17,    18,    19
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,     1,    14,    20,     2,     3,     4,     5,     6,     7,
       8,    21,     9,    10,    11,    12,    13,    14,    15,     1,
      30,    23,     2,     3,     4,     5,     6,     7,     8,    22,
       9,    10,    11,    12,    13,    14,    15,    24,    25,    26,
      27,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    41,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,     0,     0,     0,    29
};

static const yytype_int8 yycheck[] =
{
       0,     1,    17,     1,     4,     5,     6,     7,     8,     9,
      10,     3,    12,    13,    14,    15,    16,    17,    18,     1,
      18,    11,     4,     5,     6,     7,     8,     9,    10,     3,
      12,    13,    14,    15,    16,    17,    18,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     4,     5,     6,     7,     8,     9,    10,    12,
      13,    14,    15,    16,    17,    18,    20,    21,    22,    23,
      23,     3,     3,    11,     3,     3,     3,     3,     0,    21,
      23,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      11,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    19,    20,    20,    21,    21,    21,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      23
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     3,     2,     7,
       3,     1,     6,     1,     1,     2,     2,     1,     1,     1,
       1
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
  case 6: /* instruccion: error endline  */
#line 122 "ac.y"
                   { yyerrok; }
#line 1185 "ac.tab.c"
    break;

  case 7: /* funcion: CREAR_AUTOMATA NUMERO NUMERO  */
#line 125 "ac.y"
                                     {
            // Verificar si el sistema está inicializado
            if (sistema == NULL) {
                sistema = inicializar_sistema();
                if (sistema == NULL) {
                    yyerror("Error al inicializar el sistema");
                    YYERROR;
                }
            }
            
            // Verificar límite de autómatas
            if (sistema->count >= MAX_AUTOMATAS) {
                yyerror("Número máximo de autómatas alcanzado");
                YYERROR;
            }
            
            // Crear el nuevo autómata
            Automaton* nuevo_automata = crear_automata((yyvsp[-1].ival), (yyvsp[0].ival));
            if (nuevo_automata == NULL) {
                yyerror("Error al crear el autómata");
                YYERROR;
            }
            
            sistema->automatons[sistema->count++] = nuevo_automata;
            
            // Agregar vecindad
            for (int i = 0; i < sistema->count; i++) {
                agregar_vecindad(sistema->automatons[i]);
            }
        }
#line 1220 "ac.tab.c"
    break;

  case 8: /* funcion: HABITANTES_CELDA NUMERO  */
#line 155 "ac.y"
                                 {
            INDIVIDUOS_POR_CELDA=(yyvsp[0].ival);
            printf("Ahora los individuos por celda serán %d\n",INDIVIDUOS_POR_CELDA);
        }
#line 1229 "ac.tab.c"
    break;

  case 9: /* funcion: CONECTAR_AUTOMATA NUMERO NUMERO NUMERO NUMERO NUMERO NUMERO  */
#line 159 "ac.y"
                                                                     {
            conectar_automatons(sistema,(yyvsp[-5].ival),(yyvsp[-4].ival),(yyvsp[-3].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival));
        }
#line 1237 "ac.tab.c"
    break;

  case 10: /* funcion: AJUSTAR_TASA ESTADO NUMERO  */
#line 162 "ac.y"
                                   {
            if((yyvsp[-1].ival)==EXPOSED){
                PROBABILIDAD_E=(yyvsp[0].ival);
                printf("la probabilidad de PROBABILIDAD_E cambiada a %d\n",PROBABILIDAD_E);
            }
            else if((yyvsp[-1].ival)==INFECTED){
                PROBABILIDAD_I=(yyvsp[0].ival);
                printf("la probabilidad de PROBABILIDAD_I cambiada a %d\n",PROBABILIDAD_I);
            
            }else if((yyvsp[-1].ival)==RECOVERED){
                PROBABILIDAD_R=(yyvsp[0].ival);
                printf("la probabilidad de PROBABILIDAD_R cambiada a %d\n",PROBABILIDAD_R);

            }else{
                PROBABILIDAD_S=(yyvsp[0].ival);
                printf("la probabilidad de PROBABILIDAD_S cambiada a %d\n",PROBABILIDAD_S);
            }
        }
#line 1260 "ac.tab.c"
    break;

  case 11: /* funcion: IMPRIMIR_SISTEMA  */
#line 180 "ac.y"
                         {
            imprimir_sistema(sistema);
        }
#line 1268 "ac.tab.c"
    break;

  case 12: /* funcion: CAMBIAR_ESTADO_INDIVIDUO NUMERO NUMERO NUMERO NUMERO ESTADO  */
#line 183 "ac.y"
                                                                    {
            cambiar_estado_individuo(sistema,(yyvsp[-4].ival),(yyvsp[-3].ival),(yyvsp[-2].ival),(yyvsp[-1].ival),(yyvsp[0].ival));
        }
#line 1276 "ac.tab.c"
    break;

  case 13: /* funcion: MOVER_INDIVIDUOS  */
#line 186 "ac.y"
                         {
            mover_individuos_en_sistema(sistema);
        }
#line 1284 "ac.tab.c"
    break;

  case 14: /* funcion: ACTUALIZAR_ESTADOS  */
#line 189 "ac.y"
                           {
            actualizar_estados(sistema);
        }
#line 1292 "ac.tab.c"
    break;

  case 15: /* funcion: EJECUTAR_SIMULACION_LIBRE NUMERO  */
#line 192 "ac.y"
                                         {
            simular_libre(sistema,(yyvsp[0].ival));
        }
#line 1300 "ac.tab.c"
    break;

  case 16: /* funcion: EJECUTAR_SIMULACION_CONFINAMIENTO NUMERO  */
#line 195 "ac.y"
                                                 {
            simular_confin(sistema,(yyvsp[0].ival));
        }
#line 1308 "ac.tab.c"
    break;

  case 17: /* funcion: REINICIAR_SIMULACION  */
#line 198 "ac.y"
                             {
            reiniciar_simulacion(sistema);
        }
#line 1316 "ac.tab.c"
    break;

  case 18: /* funcion: REINICIAR_SISTEMA  */
#line 201 "ac.y"
                          {
            reiniciar_sistema(sistema);
        }
#line 1324 "ac.tab.c"
    break;

  case 19: /* funcion: SALIR  */
#line 204 "ac.y"
                {
            printf("Saliendo del programa...\n");
            should_exit = 1;
            YYACCEPT;
        }
#line 1334 "ac.tab.c"
    break;


#line 1338 "ac.tab.c"

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

#line 214 "ac.y"


void yyerror(const char* msg){
    printf("error: %s\n", msg);
}

Sistema *crear_sistema() {
  Sistema *sistema = (Sistema *)malloc(sizeof(Sistema));
  sistema->count = 0;
  sistema->tiempo= 0;
  for (int i = 0; i < MAX_AUTOMATAS; ++i) {
        sistema->automatons[i] = NULL;
    }
  return sistema;
}

Automaton *crear_automata(int rows, int cols) {
  Automaton *automaton = (Automaton *)malloc(sizeof(Automaton));
  automaton->rows = rows;
  automaton->cols = cols;
  // Asignar memoria para la matriz de celdas
  automaton->grid = (Cell **)malloc(rows * sizeof(Cell *));
  for (int i = 0; i < rows; i++) {
    automaton->grid[i] = (Cell *)malloc(cols * sizeof(Cell));
  }

  // Inicializar celdas y asignar filas y columnas
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      Cell *cell = &automaton->grid[i][j];
      cell->row = i;           // Asigna la fila
      cell->col = j;           // Asigna la columna
      cell->neighbors = NULL;  // Inicializa neighbors
      cell->num_neighbors = 0; // Inicializa número de vecinos
      cell->num_individuos = 0;

      // Inicializa la población
      for (int k = 0; k < INDIVIDUOS_POR_CELDA; k++) {
        cell->poblacion[k].estado = SUSCEPTIBLE; // O inicializa de otra forma
        cell->num_individuos++;
      }
    }
  }
  printf("Automata creado\n");
  return automaton;
}

void agregar_vecindad(Automaton *automaton) {
  for (int i = 0; i < automaton->rows; i++) {
    for (int j = 0; j < automaton->cols; j++) {
      Cell *cell = &automaton->grid[i][j];
      cell->neighbors = (Cell **)malloc(8 * sizeof(Cell *)); // Máximo 8 vecinos
      cell->num_neighbors = 0;

      for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
          if (di == 0 && dj == 0)
            continue; // Ignorar la célula misma
          int ni = i + di;
          int nj = j + dj;
          if (ni >= 0 && ni < automaton->rows && nj >= 0 &&
              nj < automaton->cols) {
            cell->neighbors[cell->num_neighbors++] = &automaton->grid[ni][nj];
          }
        }
      }
    }
  }
}

void conectar_automatons(Sistema *sistema, int index1, int cell1_row,
                         int cell1_col, int index2, int cell2_row,
                         int cell2_col) {
  if (index1 >= sistema->count || index2 >= sistema->count) {
    printf("Índice de autómata fuera de rango\n");
    return;
  }

  Automaton *automaton1 = sistema->automatons[index1];
  Automaton *automaton2 = sistema->automatons[index2];

  Cell *cell1 = &automaton1->grid[cell1_row][cell1_col];
  Cell *cell2 = &automaton2->grid[cell2_row][cell2_col];

  // Conectar la celda exterior de automaton1 con la celda exterior de
  // automaton2
  cell1->neighbors = (Cell **)realloc(
      cell1->neighbors, (cell1->num_neighbors + 1) * sizeof(Cell *));
  cell1->neighbors[cell1->num_neighbors++] = cell2;

  cell2->neighbors = (Cell **)realloc(
      cell2->neighbors, (cell2->num_neighbors + 1) * sizeof(Cell *));
  cell2->neighbors[cell2->num_neighbors++] = cell1;
  printf("Automata %d conectado con Automata %d\n",index1,index2);
}

void liberar_automata(Automaton *automaton) {
  for (int i = 0; i < automaton->rows; i++) {
    free(automaton->grid[i]->neighbors); // Liberar los punteros a vecinos
    free(automaton->grid[i]);
  }
  free(automaton->grid);
  free(automaton);
}
void imprimir_automata(Automaton *automaton) {
  printf("Autómata (%d filas, %d columnas):\n", automaton->rows,
         automaton->cols);
  for (int i = 0; i < automaton->rows; i++) {
    for (int j = 0; j < automaton->cols; j++) {
      Cell *cell = &automaton->grid[i][j];
      printf("Celda [%d][%d] (Individuos: %d): ", i, j,
             cell->num_individuos); // Muestra la cantidad de individuos
      for (int k = 0; k < cell->num_individuos; k++) {
        switch (cell->poblacion[k].estado) {
        case SUSCEPTIBLE:
          printf("S ");
          break;
        case EXPOSED:
          printf("E ");
          break;
        case INFECTED:
          printf("I ");
          break;
        case RECOVERED:
          printf("R ");
          break;
        }
      }
      printf("\n");
    }
    printf("\n");
  }
}

void imprimir_vecinos(Automaton *automaton, int row, int col) {
  if (row < 0 || row >= automaton->rows || col < 0 || col >= automaton->cols) {
    printf("Error: La celda [%d][%d] está fuera de rango.\n", row, col);
    return;
  }

  Cell *cell = &automaton->grid[row][col];

  printf("Vecinos de la celda [%d][%d]:\n", row, col);
  for (int i = 0; i < cell->num_neighbors; i++) {
    Cell *neighbor = cell->neighbors[i];
    printf("  Celda vecina: [%d][%d]\n", neighbor->row, neighbor->col);
  }
}

void mover_individuos(Cell *origen, Cell *destino) {

    if (origen->num_individuos <= 1)
        return; // Debe quedar al menos 1 individuo

    int max_a_mover = origen->num_individuos * 0.3; // 30% de la población actual
    int individuos_a_mover = rand() % (max_a_mover + 1); // Aleatorio entre 0 y max_a_mover

    if (individuos_a_mover >= origen->num_individuos) {
        individuos_a_mover = origen->num_individuos - 1; // Dejar al menos 1
    }

    // Mover individuos al destino
    for (int i = 0; i < individuos_a_mover; i++) {
        destino->poblacion[destino->num_individuos++] = origen->poblacion[origen->num_individuos - 1]; // Mover el último individuo
        origen->num_individuos--; // Reducir el número de individuos en la celda de origen
    }

    // Actualizar el total de movimientos
    total_movidos += individuos_a_mover;

    // Imprimir el total acumulado
}

void mover_individuos_en_sistema(Sistema *sistema) {
  for (int a = 0; a < sistema->count; a++) { // Iterar sobre cada autómata
    Automaton *automaton = sistema->automatons[a];
    for (int i = 0; i < automaton->rows; i++) {
      for (int j = 0; j < automaton->cols; j++) {
        Cell *cell = &automaton->grid[i][j];

        // Mover un número aleatorio de individuos a un vecino aleatorio
        if (cell->num_individuos > 1 &&
            cell->num_neighbors >
                0) { // Asegúrate de que hay al menos 2 individuos
          int vecino_index =
              rand() % cell->num_neighbors; // Selecciona un vecino aleatorio
          Cell *vecino = cell->neighbors[vecino_index];

          mover_individuos(cell, vecino); // Llama a mover_individuos
        }
      }
    }
  }
}

void verificar_totales(Sistema *sistema) {
  int total_individuos = 0;
  for (int a = 0; a < sistema->count; a++) {
    Automaton *automaton = sistema->automatons[a];
    for (int i = 0; i < automaton->rows; i++) {
      for (int j = 0; j < automaton->cols; j++) {
        total_individuos += automaton->grid[i][j].num_individuos;
      }
    }
  }
  printf("Total de individuos en el sistema: %d\n", total_individuos);
}

void actualizar_estados(Sistema *sistema) {
    for (int a = 0; a < sistema->count; a++) { // Iterar sobre cada autómata
        Automaton *automaton = sistema->automatons[a];
        for (int i = 0; i < automaton->rows; i++) {
            for (int j = 0; j < automaton->cols; j++) {
                Cell *cell = &automaton->grid[i][j];

                // Cambiar el estado de los individuos en la celda actual
                for (int k = 0; k < cell->num_individuos; k++) {
                    Individuo *individuo = &cell->poblacion[k];

                    // Transición de SUSCEPTIBLE a EXPOSED
                    if (individuo->estado == SUSCEPTIBLE) {
                        for (int l = 0; l < cell->num_individuos; l++) {
                            if (cell->poblacion[l].estado == EXPOSED || 
                                cell->poblacion[l].estado == INFECTED) {
                                if (rand() % 100 < PROBABILIDAD_E ) {
                                    individuo->estado = EXPOSED;
                                    total_cambios_estado++; // Incrementar el contador
                                }
                                break;
                            }
                        }
                    }
                    // Transición de EXPOSED a INFECTED
                    else if (individuo->estado == EXPOSED) {
                        if (rand() % 100 < PROBABILIDAD_I) { // 50% de probabilidad
                            individuo->estado = INFECTED;
                            total_cambios_estado++; // Incrementar el contador
                        }
                    }
                    // Transición de INFECTED a SUSCEPTIBLE
                    else if (individuo->estado == INFECTED) {
                        if (rand() % 100 < PROBABILIDAD_R) { // 50% de probabilidad
                            individuo->estado = RECOVERED;
                            total_cambios_estado++; // Incrementar el contador
                        }
                    }
                    else if (individuo->estado==RECOVERED) {
                        if(rand() % 100< PROBABILIDAD_S){ // 50% de probabilidad
                            individuo->estado=SUSCEPTIBLE;
                            total_cambios_estado++; //Incrementar el contador
                        }
                    }
                }
            }
        }
    }
}

void imprimir_sistema(Sistema *sistema) {
  printf("\nSistema de Autómatas:\n");
  for (int a = 0; a < sistema->count; a++) {
    printf("Autómata %d:\n", a + 1);
    imprimir_automata(sistema->automatons[a]);
    printf("\n"); // Espacio entre autómatas
  }
}

void liberar_sistema(Sistema *sistema) {
  for (int i = 0; i < sistema->count; i++) {
    liberar_automata(sistema->automatons[i]);
  }
  free(sistema);
}

void cambiar_estado_individuo(Sistema* sistema, int automaton_index, int cell_row, int cell_col, int individuo_index, Estados nuevo_estado) {
    if (automaton_index < 0 || automaton_index >= sistema->count) {
        printf("Índice de autómata fuera de rango.\n");
        return;
    }

    Automaton* automaton = sistema->automatons[automaton_index];
    if (cell_row < 0 || cell_row >= automaton->rows || cell_col < 0 || cell_col >= automaton->cols) {
        printf("Índice de celda fuera de rango.\n");
        return;
    }

    Cell* cell = &automaton->grid[cell_row][cell_col];
    if (individuo_index < 0 || individuo_index >= cell->num_individuos) {
        printf("Índice de individuo fuera de rango.\n");
        return;
    }

    // Cambiar el estado del individuo
    cell->poblacion[individuo_index].estado = nuevo_estado;
    printf("Estado del individuo en la celda [%d][%d] cambiado a %d.\n", cell_row, cell_col, nuevo_estado);
}

void imprimir_estado(Sistema *sistema) {
    for (int a = 0; a < sistema->count; a++) {
        Automaton *automaton = sistema->automatons[a];
        printf("Autómata %d:\n", a + 1);
        for (int i = 0; i < automaton->rows; i++) {
            for (int j = 0; j < automaton->cols; j++) {
                Cell *cell = &automaton->grid[i][j];
                printf("Celda [%d][%d]: ", i, j);

                for (int k = 0; k < cell->num_individuos; k++) {
                    Individuo *individuo = &cell->poblacion[k];
                    switch (individuo->estado) {
                        case SUSCEPTIBLE: printf("S "); break;
                        case EXPOSED:    printf("E "); break;
                        case INFECTED:   printf("I "); break;
                        case RECOVERED:  printf("R "); break;
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
    }
}

void avanzar_simulacion(Sistema *sistema, int pasos) {
    for (int p = 0; p < pasos; p++) {
        // Actualizar estados y mover individuos
        actualizar_estados(sistema);
        mover_individuos_en_sistema(sistema);
        sistema->tiempo++; // Incrementar el tiempo
        printf("Tiempo: %d\n", sistema->tiempo);
        printf("Total de individuos movidos en este paso: %d\n", total_movidos);
        printf("Total de cambios de estado: %d\n", total_cambios_estado);
        total_movidos=0;
        total_cambios_estado=0;
    }
}
void avanzar_simulacion_confin(Sistema *sistema, int pasos) {
    for (int p = 0; p < pasos; p++) {
        // Actualizar estados y mover individuos
        actualizar_estados(sistema);
        sistema->tiempo++; // Incrementar el tiempo
        printf("Tiempo: %d\n", sistema->tiempo);
        printf("Total de cambios de estado: %d\n", total_cambios_estado);
        total_cambios_estado=0;
    }
}

void simular_libre(Sistema *sistema, int pasos) {
    avanzar_simulacion(sistema, pasos);
    imprimir_sistema(sistema);
}
void simular_confin(Sistema *sistema, int pasos) {
    avanzar_simulacion_confin(sistema, pasos);
    imprimir_sistema(sistema);
}


void reiniciar_simulacion(Sistema *sistema) {
    sistema->tiempo=0;
    for (int a = 0; a < sistema->count; a++) { // Iterar sobre cada autómata
        Automaton *automaton = sistema->automatons[a];
        for (int i = 0; i < automaton->rows; i++) {
            for (int j = 0; j < automaton->cols; j++) {
                Cell *cell = &automaton->grid[i][j];

                // Reiniciar el estado de todos los individuos existentes a SUSCEPTIBLE
                for (int k = 0; k < cell->num_individuos; k++) {
                    cell->poblacion[k].estado = SUSCEPTIBLE;
                }

                // Ajustar el número de individuos a INDIVIDUOS_POR_CELDA por celda
                if (cell->num_individuos < INDIVIDUOS_POR_CELDA) {
                    // Si hay menos de 100, agregar individuos
                    int individuos_a_agregar = INDIVIDUOS_POR_CELDA - cell->num_individuos;
                    for (int k = 0; k < individuos_a_agregar; k++) {
                        Individuo nuevo_individuo = {SUSCEPTIBLE}; // Crear nuevo individuo en estado SUSCEPTIBLE
                        cell->poblacion[cell->num_individuos++] = nuevo_individuo;
                    }
                } else if (cell->num_individuos > INDIVIDUOS_POR_CELDA) {
                    // Si hay más de 100, eliminar el exceso
                    cell->num_individuos = INDIVIDUOS_POR_CELDA;
                }
            }
        }
    }
    printf("Simulacion reiniciado: Todos los individuos están en estado SUSCEPTIBLE y hay %d individuos por celda.\n",INDIVIDUOS_POR_CELDA);
}
void reiniciar_sistema(Sistema *sistema) {
    sistema->tiempo=0;
    // Liberar cada autómata en el sistema
    for (int a = 0; a < sistema->count; a++) {
        Automaton *automaton = sistema->automatons[a];

        // Liberar la memoria de cada celda en la cuadrícula
        for (int i = 0; i < automaton->rows; i++) {
            free(automaton->grid[i]); // Liberar cada fila de celdas
        }

        // Liberar la memoria de la cuadrícula de celdas
        free(automaton->grid);

        // Liberar la estructura del autómata
        free(automaton);
    }

    // Reiniciar el contador de autómatas en el sistema a 0
    sistema->count = 0;

    printf("Sistema reiniciado: Todos los autómatas y celdas han sido eliminados.\n");
}
Sistema* inicializar_sistema(void) {
    Sistema* nuevo_sistema = (Sistema*)malloc(sizeof(Sistema));
    if (nuevo_sistema == NULL) {
        return NULL;
    }
    
    nuevo_sistema->count = 0;
    nuevo_sistema->tiempo = 0;
    
    // Inicializar todos los punteros a NULL
    for (int i = 0; i < MAX_AUTOMATAS; i++) {
        nuevo_sistema->automatons[i] = NULL;
    }
    
    return nuevo_sistema;
}


int main(int argc, char **argv) {
    srand(time(NULL));
    printf("Comienza el programa. Escriba 'salir' para terminar.\n");
    
    while (!should_exit) {
        printf("> "); // Prompt
        fflush(stdout);
        
        int result = yyparse();
        if (result != 0 && !should_exit) {
            // Solo mostrar error si no es por salir
            printf("Continúe escribiendo comandos o escriba 'salir' para terminar.\n");
        }
    }
    
    if (sistema != NULL) {
        liberar_sistema(sistema);
    }
    return 0;
}
