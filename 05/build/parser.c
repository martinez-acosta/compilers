/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:339  */

#include <stdio.h>
#define INT_ 0x01
#define DOUBLE_ 0x02
#define STRING_ 0x03
#define NUMBER_ 0x04
#define UNDEF_ 0x05
#define ARR_ 0x06

int yylex(void);
void yyerror (char *);
char * restarCadena(char*, char*);
char * sumarCadena(char*, char*);
char * powCadena(char*,int);
char * divCadena(char*,char*);
char * invertirCadena(char*);
char isBinA(char*,char*);
void appendChar(char*,char);
void copiarCadena(char *, char *, int);
char compararCadena(char *, char *);
int longitudCadena(char*);

typedef struct Valor {
        int entero;
        double decimal;
        char* palabra;
        double* arr;
        int tamArr;
}Valor;

typedef struct Simbolo {
    char    *nombre;
    int tipo;
    struct Valor valor;
    struct Simbolo *next;
} Simbolo;

typedef struct TablaSimbolos {
    Simbolo *first;
}TablaSimbolos;


//Funciones tabla de símbolos
void imprimirTabla();
void imprimirSimbolo(Simbolo*);
void agregarSimbolo(char*,int,Valor*);
Simbolo* obtenerSimbolo(char*);
char existeSimbolo(char*);
void agregarInt(char*name,int val);
void agregarDouble(char*name,double val);
void agregarString(char*name,char* val);


#line 120 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_HOME_LALO_DROPBOX_ESCOM_COMPILADORES_PRACTICAS_05_BUILD_PARSER_H_INCLUDED
# define YY_YY_HOME_LALO_DROPBOX_ESCOM_COMPILADORES_PRACTICAS_05_BUILD_PARSER_H_INCLUDED
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
    POW = 258,
    DIV = 259,
    INT = 260,
    DOUBLE = 261,
    STRING = 262,
    IF = 263,
    ENTERO = 264,
    DECIMAL = 265,
    ID = 266,
    UNARYMINUS = 267
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 56 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:355  */

    int entero;
    double decimal;
    char* palabra;
    struct Dato {
            char tipo;
            double numero;
            char* palabra;
    }dato;

#line 184 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_LALO_DROPBOX_ESCOM_COMPILADORES_PRACTICAS_05_BUILD_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   485

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  246

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   267

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    28,     2,     2,    16,     2,     2,
      24,    26,    14,    12,    27,    13,     2,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
       2,    17,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    20,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    91,    93,    94,    95,    96,    97,    98,
      99,   103,   104,   112,   120,   128,   140,   157,   174,   191,
     226,   257,   258,   259,   260,   267,   272,   277,   282,   306,
     321,   336,   352,   366,   380,   396,   410,   424,   443,   457,
     471,   488,   502,   515,   529,   544,   559,   569,   579,   592,
     605,   620,   630,   640,   653,   672,   691,   712,   733,   763,
     784,   809,   810,   811,   812,   813,   818,   819,   820,   821,
     822,   823,   824,   825,   826,   827,   828,   833,   834,   835,
     839,   840,   841,   842,   843,   857,   858,   859,   860,   861,
     862,   867,   868
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "POW", "DIV", "INT", "DOUBLE", "STRING",
  "IF", "ENTERO", "DECIMAL", "ID", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'='", "UNARYMINUS", "'\\n'", "'p'", "';'", "'['", "']'", "'('", "'>'",
  "')'", "','", "'\"'", "$accept", "input", "line", "decl", "expr",
  "exp_decimal", "exp_string", "exp_entera", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,    43,    45,    42,    47,    37,    61,   267,    10,
     112,    59,    91,    93,    40,    62,    41,    44,    34
};
# endif

#define YYPACT_NINF -24

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-24)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,     6,   -24,   -24,   -23,   -22,    16,    57,    62,   -19,
     -24,   -24,   293,   346,   -24,   -24,    20,   -24,    -3,   436,
      11,   446,    67,     0,    15,    56,   294,    56,    55,    56,
      56,    56,    87,    74,   -24,   -24,    71,    94,   346,   346,
     346,   346,   346,   -24,     0,     0,   -24,   346,   346,   346,
     346,   346,   -24,    23,    51,    73,   107,    70,    56,   108,
     110,   243,   454,   459,   464,   469,    56,   132,   454,    56,
     454,    78,   454,   117,   346,   -24,   -24,    26,    37,    26,
      37,   147,   149,   147,   149,   147,   149,   -24,   -24,    26,
      37,    26,    37,   147,   149,   147,   149,   147,   149,   346,
     111,   111,     0,     0,   454,    56,    56,    56,    56,    56,
      56,    56,   157,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,   454,   165,   454,    56,   169,   131,   248,
     161,   111,   287,   292,    49,   103,   137,   160,   168,   185,
     194,    95,    95,   174,   174,   174,   173,    95,    95,   174,
     174,   174,    95,   140,   163,    95,   140,   163,   174,   189,
     210,   174,   189,   210,   174,   189,   210,    95,   188,    95,
     188,   174,   174,   174,    95,   140,   163,    95,   140,   163,
     174,   189,   210,   174,   189,   210,   174,   189,   210,   -24,
     307,    56,   -24,   -24,   111,   -24,   111,   111,   111,   111,
     111,   -24,   -24,   -24,    56,    56,    56,    56,    56,    56,
     -24,   -24,   454,   220,   229,   229,   211,   211,   211,   312,
     327,   332,   356,   371,   376,   391,   396,   411,   416,   431,
     -24,   -24,   -24,   -24,   -24,   -24
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    10,     0,     0,     0,     0,     0,     0,
      85,    61,    11,     0,     4,     5,     0,     3,     0,     0,
       0,     0,     0,     0,    12,     0,    13,     0,    14,     0,
       0,     0,     0,     0,    79,    92,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     9,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    21,    26,    27,    25,     0,     0,    22,     0,
      23,     0,    20,     0,     0,    80,     6,    62,    73,    63,
      74,    64,    75,    67,    78,    66,    77,    81,    82,    68,
      86,    69,    87,    70,    88,    72,    91,    71,    89,     0,
       0,     0,     0,     0,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    57,    59,    58,    60,     0,    48,    49,    51,
      50,    52,    35,    26,    25,    36,    26,    25,    38,    26,
      25,    37,    26,    25,    39,    26,    25,    41,    27,    42,
      27,    44,    43,    45,    29,    26,    25,    30,    26,    25,
      32,    26,    25,    31,    26,    25,    33,    26,    25,    15,
       0,     0,    65,    76,     0,    92,     0,     0,     0,     0,
       0,    84,    90,    83,     0,     0,     0,     0,     0,     0,
      28,    24,    19,     0,    86,    87,    88,    91,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    40,    47,    34,    53,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -24,   -24,   -24,   -24,   162,   120,    -1,     7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    17,    18,    62,    63,    64,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    22,    23,    56,     5,    30,     2,     3,    21,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    37,    13,
      35,    54,    57,    44,    45,    14,    15,    24,    16,    55,
      46,    36,    58,    25,    16,    38,    39,    40,    41,    42,
      40,    41,    42,    87,    88,    78,    80,    82,    84,    86,
      99,    49,    50,    51,    90,    92,    94,    96,    98,    59,
      60,    44,    45,    44,    45,    10,    11,    61,    26,    13,
       4,     5,    69,    28,    27,   213,    10,    11,   100,    29,
      13,    55,    44,    45,    16,    47,    48,    49,    50,    51,
     113,   114,   115,   116,   117,    16,    73,   103,    74,    75,
     101,    54,   144,   136,   147,   150,   139,   142,   143,   115,
     116,   117,   148,    76,   140,   113,   114,   115,   116,   117,
      10,    19,   178,   180,   141,   164,   167,   170,   173,   176,
     214,   102,   105,    34,   106,   186,   189,   192,   195,   198,
     137,   134,    53,    38,    39,    40,    41,    42,   205,   118,
     119,   120,   121,   122,   120,   121,   122,   202,    77,    79,
      81,    83,    85,    42,   215,    51,   156,    89,    91,    93,
      95,    97,   123,   124,   125,   126,   127,   130,   131,   132,
     128,   129,   130,   131,   132,   204,   201,   216,   199,    68,
     117,    70,    71,    72,    53,   217,   220,   113,   114,   115,
     116,   117,   125,   126,   127,   122,   123,   124,   125,   126,
     127,   223,   218,   224,   225,   226,   227,   228,   239,   138,
     104,   219,   232,   234,   236,   146,   132,   210,   133,     0,
       0,   135,   206,   207,   208,   209,   210,     0,   163,   166,
     169,   172,   175,   208,   209,   210,     0,   101,   185,   188,
     191,   194,   197,     0,     0,   107,   108,   109,   110,   111,
      47,    48,    49,    50,    51,   112,     0,   145,   149,   151,
     152,   153,   154,   155,   203,   157,   158,   159,   160,   161,
     162,   165,   168,   171,   174,   177,   179,   181,   182,   183,
     184,   187,   190,   193,   196,     0,     0,     0,   200,   206,
     207,   208,   209,   210,   206,   207,   208,   209,   210,     0,
      31,    66,     0,   211,     0,    32,    67,     0,   212,   113,
     114,   115,   116,   117,   113,   114,   115,   116,   117,     0,
       0,     0,     0,   221,     0,   231,     0,     0,   240,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    33,
       0,     0,     0,   241,     0,    10,    11,     0,   202,    13,
       0,     0,     0,   222,     0,     0,     0,     0,   128,   129,
     130,   131,   132,     0,     0,     0,   229,   230,   233,   235,
     237,   238,   203,   113,   114,   115,   116,   117,   128,   129,
     130,   131,   132,     0,     0,     0,     0,   242,     0,     0,
       0,     0,   211,   113,   114,   115,   116,   117,   128,   129,
     130,   131,   132,     0,     0,     0,     0,   243,     0,     0,
       0,     0,   212,   113,   114,   115,   116,   117,   113,   114,
     115,   116,   117,     0,     0,     0,     0,   244,     0,     0,
       0,     0,   245,   123,   124,   125,   126,   127,    38,    39,
      40,    41,    42,     0,     0,    43,     0,   213,    47,    48,
      49,    50,    51,     0,     0,    52,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132
};

static const yytype_int16 yycheck[] =
{
       1,    24,    24,     3,     4,    24,     0,     1,     1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    21,    13,
      13,    22,    23,    12,    13,    19,    20,    11,    28,    22,
      19,    11,    17,    17,    28,    12,    13,    14,    15,    16,
      14,    15,    16,    44,    45,    38,    39,    40,    41,    42,
      27,    14,    15,    16,    47,    48,    49,    50,    51,     3,
       4,    12,    13,    12,    13,     9,    10,    11,    11,    13,
       3,     4,    17,    11,    17,    26,     9,    10,    27,    17,
      13,    74,    12,    13,    28,    12,    13,    14,    15,    16,
      12,    13,    14,    15,    16,    28,     9,    27,    24,    28,
      27,   102,   103,    25,   105,   106,    99,   100,   101,    14,
      15,    16,   105,    19,     3,    12,    13,    14,    15,    16,
       9,     1,   123,   124,    13,   118,   119,   120,   121,   122,
      27,    24,    24,    13,    24,   128,   129,   130,   131,   132,
      23,     9,    22,    12,    13,    14,    15,    16,   141,    12,
      13,    14,    15,    16,    14,    15,    16,    26,    38,    39,
      40,    41,    42,    16,    27,    16,     9,    47,    48,    49,
      50,    51,    12,    13,    14,    15,    16,    14,    15,    16,
      12,    13,    14,    15,    16,    24,    17,    27,    23,    27,
      16,    29,    30,    31,    74,    27,    23,    12,    13,    14,
      15,    16,    14,    15,    16,    16,    12,    13,    14,    15,
      16,   204,    27,   206,   207,   208,   209,   210,   219,    99,
      58,    27,   215,   216,   217,   105,    16,    16,    66,    -1,
      -1,    69,    12,    13,    14,    15,    16,    -1,   118,   119,
     120,   121,   122,    14,    15,    16,    -1,    27,   128,   129,
     130,   131,   132,    -1,    -1,    12,    13,    14,    15,    16,
      12,    13,    14,    15,    16,    22,    -1,   105,   106,   107,
     108,   109,   110,   111,    26,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,    -1,    -1,    -1,   136,    12,
      13,    14,    15,    16,    12,    13,    14,    15,    16,    -1,
      17,    17,    -1,    26,    -1,    22,    22,    -1,    26,    12,
      13,    14,    15,    16,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    26,    -1,   215,    -1,    -1,    26,    12,
      13,    14,    15,    16,    12,    13,    14,    15,    16,     3,
      -1,    -1,    -1,    26,    -1,     9,    10,    -1,    26,    13,
      -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    -1,    -1,    -1,   214,   215,   216,   217,
     218,   219,    26,    12,    13,    14,    15,    16,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    26,    12,    13,    14,    15,    16,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    26,    12,    13,    14,    15,    16,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    26,    12,    13,    14,    15,    16,    12,    13,
      14,    15,    16,    -1,    -1,    19,    -1,    26,    12,    13,
      14,    15,    16,    -1,    -1,    19,    12,    13,    14,    15,
      16,    12,    13,    14,    15,    16,    12,    13,    14,    15,
      16,    12,    13,    14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    13,    19,    20,    28,    31,    32,    34,
      35,    36,    24,    24,    11,    17,    11,    17,    11,    17,
      24,    17,    22,     3,    34,    36,    11,    21,    12,    13,
      14,    15,    16,    19,    12,    13,    19,    12,    13,    14,
      15,    16,    19,    34,    35,    36,     3,    35,    17,     3,
       4,    11,    33,    34,    35,    36,    17,    22,    33,    17,
      33,    33,    33,     9,    24,    28,    19,    34,    36,    34,
      36,    34,    36,    34,    36,    34,    36,    35,    35,    34,
      36,    34,    36,    34,    36,    34,    36,    34,    36,    27,
      27,    27,    24,    27,    33,    24,    24,    12,    13,    14,
      15,    16,    22,    12,    13,    14,    15,    16,    12,    13,
      14,    15,    16,    12,    13,    14,    15,    16,    12,    13,
      14,    15,    16,    33,     9,    33,    25,    23,    34,    36,
       3,    13,    36,    36,    35,    33,    34,    35,    36,    33,
      35,    33,    33,    33,    33,    33,     9,    33,    33,    33,
      33,    33,    33,    34,    36,    33,    34,    36,    33,    34,
      36,    33,    34,    36,    33,    34,    36,    33,    35,    33,
      35,    33,    33,    33,    33,    34,    36,    33,    34,    36,
      33,    34,    36,    33,    34,    36,    33,    34,    36,    23,
      33,    17,    26,    26,    24,    36,    12,    13,    14,    15,
      16,    26,    26,    26,    27,    27,    27,    27,    27,    27,
      23,    26,    33,    36,    36,    36,    36,    36,    36,    33,
      33,    34,    36,    33,    36,    33,    36,    33,    33,    35,
      26,    26,    26,    26,    26,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    30,    31,    31,    31,    31,    31,    31,
      31,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      35,    35,    35,    35,    35,    36,    36,    36,    36,    36,
      36,    36,    36
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     3,     2,     2,     2,
       1,     1,     2,     2,     2,     5,     4,     4,     4,     6,
       3,     3,     3,     3,     6,     1,     1,     1,     4,     3,
       3,     3,     3,     3,     6,     3,     3,     3,     3,     3,
       6,     3,     3,     3,     3,     3,     6,     6,     3,     3,
       3,     3,     3,     6,     6,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     6,     3,     3,     2,
       3,     3,     3,     6,     6,     1,     3,     3,     3,     3,
       6,     3,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 5:
#line 94 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {imprimirTabla();}
#line 1467 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {printf("\n");}
#line 1473 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 96 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {printf("res entero-%d-\n",(yyvsp[-1].entero));}
#line 1479 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 97 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {printf("res decimal -%f-\n",(yyvsp[-1].decimal));}
#line 1485 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 98 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {printf("res string-%s-\n",(yyvsp[-1].palabra));}
#line 1491 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if(existeSimbolo((yyvsp[0].palabra)))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        agregarSimbolo((yyvsp[0].palabra),INT_,tmp);
    }
}
#line 1504 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 112 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if(existeSimbolo((yyvsp[0].palabra)))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        agregarSimbolo((yyvsp[0].palabra),DOUBLE_,tmp);
    }
}
#line 1517 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 120 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if(existeSimbolo((yyvsp[0].palabra)))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        agregarSimbolo((yyvsp[0].palabra),STRING_,tmp);
    }
}
#line 1530 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 128 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    printf("Expresión inválida.\n");
    if(existeSimbolo((yyvsp[-3].palabra)))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        tmp->arr = malloc(sizeof((yyvsp[-1].entero)));
        tmp->tamArr = (yyvsp[-1].entero);
        agregarSimbolo((yyvsp[-3].palabra),ARR_,tmp);
    }
}
#line 1546 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( existeSimbolo((yyvsp[-2].palabra)) )
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        switch ((yyvsp[0].dato).tipo) {
        case NUMBER_:
            tmp->entero = (yyvsp[0].dato).numero;
            agregarSimbolo((yyvsp[-2].palabra),INT_,tmp);
            break;
        case STRING_:
        case UNDEF_:
            printf("expr inválida");
            break;
        }
    }
}
#line 1568 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 157 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if(existeSimbolo((yyvsp[-2].palabra)))
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        switch ((yyvsp[0].dato).tipo) {
        case NUMBER_:
            tmp->decimal = (yyvsp[0].dato).numero;
            agregarSimbolo((yyvsp[-2].palabra),DOUBLE_,tmp);
            break;
        case STRING_:
        case UNDEF_:
            printf("expr inválida");
            break;
        }
    }
}
#line 1590 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 174 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( existeSimbolo((yyvsp[-2].palabra)) )
        printf("El símbolo ya existe\n");
    else {
        Valor *tmp = malloc(sizeof(Valor));
        switch ((yyvsp[0].dato).tipo) {
        case STRING_:
            tmp->palabra = (yyvsp[0].dato).palabra;
            agregarSimbolo((yyvsp[-2].palabra),STRING_,tmp);
            break;
        case NUMBER_:
        case UNDEF_:
            printf("expr inválida");
            break;
        }
    }
}
#line 1612 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 191 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    printf("llegamos\n");

    if (!existeSimbolo((yyvsp[-5].palabra))) {
        printf("no existe el símbolo, expr inválida\n");
        //$$.tipo = UNDEF_;
    } else {
        printf("llegamos\n");

        Simbolo *sim = obtenerSimbolo((yyvsp[-5].palabra));
        if (sim->tipo == INT_ || sim->tipo == DOUBLE_ || sim->tipo == STRING_) {
            //$$.tipo = UNDEF_;
            printf("expr inválida, no es un array el símbolo que intenta accesar.\n");
        } else if (sim->tipo == ARR_) {
            if ((yyvsp[-3].entero) > sim->valor.tamArr) {
              printf("está fuera del rango del array, use un num más pequeño\n");
            }
            switch ((yyvsp[0].dato).tipo) {
            case NUMBER_:
                *(sim->valor.arr + (yyvsp[-3].entero)) = (yyvsp[0].dato).numero;//asignamos en el array
                //$$.numero = $6.numero;//asignamos en la expr recursiva
                //$$.tipo = NUMBER_;
                break;

            default:
                //algo salió mal
                printf("Deje de asginar cosas que no v:\n");
                //$$.tipo = UNDEF_;
                break;
            }

        }
    }
    printf("ID [%d] \t",(yyvsp[-3].entero));
}
#line 1652 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 226 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( !existeSimbolo((yyvsp[-2].palabra)) )
        printf("El símbolo no existe\n");
    else if ((yyvsp[0].dato).tipo == UNDEF_)
        printf("expr inválida\n");
    else {
        printf("Símbolo encontrado\n");
        Simbolo *sim = obtenerSimbolo((yyvsp[-2].palabra));
        switch (sim->tipo) {
        case INT_:
            if ( (yyvsp[0].dato).tipo == NUMBER_)
                sim->valor.entero = (yyvsp[0].dato).numero;
            else if ((yyvsp[0].dato).tipo == STRING_)
                printf("No intente asignar un string a un entero. Tipo de datos incompatibles.\n");
            break;
        case DOUBLE_:
            if ( (yyvsp[0].dato).tipo == NUMBER_)
                sim->valor.decimal = (yyvsp[0].dato).numero;
            else if ((yyvsp[0].dato).tipo == STRING_)
                printf("No intente asignar un string a un double. Tipo de datos incompatibles.\n");
            break;
        case STRING_:
            if ( (yyvsp[0].dato).tipo == NUMBER_)
                printf("No intente asignar un entero/double a un string. Tipo de datos incompatibles.\n");
            else if ((yyvsp[0].dato).tipo == STRING_)
                sim->valor.palabra = (yyvsp[0].dato).palabra;
            break;
        }
    }
    printf("id: %s\n",(yyvsp[-2].palabra));
}
#line 1688 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 257 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { printf("Nombre de variable inválido, debe empezar por alguna letra\n"); }
#line 1694 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 258 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { printf("Nombre de variable inválido, debe empezar por alguna letra\n"); }
#line 1700 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 259 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { printf("Nombre de variable inválido, debe empezar por alguna letra\n"); }
#line 1706 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 260 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ((yyvsp[-3].dato).numero>(yyvsp[-1].dato).numero)
        printf("Expresión 1 es mayor a expresión 2, VERDADERO\n");
    else
        printf("FALSO\n");
}
#line 1717 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 267 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    (yyval.dato).tipo = NUMBER_;
    (yyval.dato).numero = (yyvsp[0].entero);
    printf("expr: expr_entera\n");
                 }
#line 1727 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 272 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    (yyval.dato).tipo = NUMBER_;
    (yyval.dato).numero = (yyvsp[0].decimal);
    printf("expr: expr_decimal\n");
              }
#line 1737 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 277 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    (yyval.dato).tipo = STRING_;
    (yyval.dato).palabra = (yyvsp[0].palabra);
    printf("expr: expr_string\n");
             }
#line 1747 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 282 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    printf("llegamos1\n");

    if (!existeSimbolo((yyvsp[-3].palabra))) {
        printf("no existe el símbolo, expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else {
        printf("llegamos1\n");

        Simbolo *sim = obtenerSimbolo((yyvsp[-3].palabra));
        if (sim->tipo == INT_ || sim->tipo == DOUBLE_ || sim->tipo == STRING_) {
            (yyval.dato).tipo = UNDEF_;
            printf("expr inválida, no es un array el símbolo que intenta accesar.\n");
        } else if (sim->tipo == ARR_) {
            if ((yyvsp[-1].entero) > sim->valor.tamArr) {
              printf("está fuera del rango del array, use un num más pequeño\n");
            }
                (yyval.dato).numero = *(sim->valor.arr + (yyvsp[-1].entero));//asignamos en la expr recursiva
                (yyval.dato).tipo = NUMBER_;
                printf("Valor es: %f\n",*(sim->valor.arr + (yyvsp[-1].entero)));
        }
    }
    printf("ID [%d] \t",(yyvsp[-1].entero));
}
#line 1776 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 306 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
        (yyval.dato).numero = (yyvsp[-2].entero)+(yyvsp[0].dato).numero;
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        (yyval.dato).numero = 0;
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede sumar un número con un string\n");
        break;
    }
    printf("expr: expr_entera + expr\n");
}
#line 1796 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 321 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
        (yyval.dato).numero = (yyvsp[-2].entero)-(yyvsp[0].dato).numero;
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        (yyval.dato).tipo = UNDEF_;
        (yyval.dato).numero = 0;
        printf("Operación inválida, no puede restar un número con un string\n");
        break;
    }
    printf("expr: expr_entera - expr\n");
}
#line 1816 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 336 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
        if ((yyvsp[0].dato).numero == 0.0)
            printf("No se puede dividir entre cero.\n");
        (yyval.dato).numero = (yyvsp[-2].entero)/(yyvsp[0].dato).numero;
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede dividir un número con un string\n");
        break;
    }
    printf("expr: expr_entera / expr\n");
}
#line 1837 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 352 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
        (yyval.dato).numero = (yyvsp[-2].entero)*(yyvsp[0].dato).numero;
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede multiplicar un número con un string\n");
        break;
    }
    printf("expr: expr_entera * expr\n");
}
#line 1856 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 366 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
        (yyval.dato).numero = (yyvsp[-2].entero)%(int)(yyvsp[0].dato).numero;
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede multiplicar un número con un string\n");
        break;
    }
    printf("expr: expr_entera % expr\n");
}
#line 1875 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 380 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[-1].dato).tipo) {
    case NUMBER_:
        for (int i =1; i<(int)(yyvsp[-1].dato).numero;i++)
            (yyvsp[-3].entero) *= (yyvsp[-3].entero);
        (yyval.dato).numero = (yyvsp[-3].entero);
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede hacer DIV de un número con un string\n");
        (yyval.dato).tipo = UNDEF_;
        break;
    }
    printf("expr: DIV(expr_entera, expr)\n");
}
#line 1896 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 396 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
        (yyval.dato).numero = (yyvsp[-2].decimal)+(yyvsp[0].dato).numero;
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede sumar un número con un string\n");
        (yyval.dato).tipo = UNDEF_;
        break;
    }
    printf("expr: expr_decimal + expr\n");
}
#line 1915 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 410 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
        (yyval.dato).numero = (yyvsp[-2].decimal)-(yyvsp[0].dato).numero;
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede restar un número con un string\n");
        break;
    }
    printf("expr: expr_decimal - expr\n");
}
#line 1934 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 424 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
        if((yyvsp[0].dato).numero == 0.0) {
            printf("No se puede dividir entre cero\n");
            (yyval.dato).numero = 0;
        }else
            (yyval.dato).numero = (yyvsp[-2].decimal)/(yyvsp[0].dato).numero;
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede dividir un número con un string\n");
        (yyval.dato).tipo = UNDEF_;
        break;
    }

    printf("expr: expr_decimal / expr\n");
}
#line 1958 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 443 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
            (yyval.dato).numero = (yyvsp[-2].decimal)*(yyvsp[0].dato).numero;
            (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede multiplicar un número con un string\n");
        (yyval.dato).tipo = UNDEF_;
        break;
    }
    printf("expr: expr_decimal * expr\n");
}
#line 1977 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 457 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case NUMBER_:
            (yyval.dato).numero = (int)(yyvsp[-2].decimal)%(int)(yyvsp[0].dato).numero;
            (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede multiplicar un número con un string\n");
        (yyval.dato).tipo = UNDEF_;
        break;
    }
    printf("expr: expr_decimal % expr\n");
}
#line 1996 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 471 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[-1].dato).tipo) {
    case NUMBER_:
        (yyvsp[-3].decimal) = (int)(yyvsp[-3].decimal);
        for (int i =1; i<(int)(yyvsp[-1].dato).numero;i++)
            (yyvsp[-3].decimal) *= (yyvsp[-3].decimal);
        (yyval.dato).numero = (int)(yyvsp[-3].decimal);
        (yyval.dato).tipo = NUMBER_;
        break;
    case STRING_:
    case UNDEF_:
        printf("Operación inválida, no puede hacer DIV de un número con un string\n");
        (yyval.dato).tipo = UNDEF_;
        break;
    }
    printf("expr: DIV(expr_decimal, expr)\n");
}
#line 2018 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 488 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case STRING_:
        (yyval.dato).palabra = sumarCadena((yyvsp[-2].palabra),(yyvsp[0].dato).palabra);
        (yyval.dato).tipo = STRING_;
        break;
    case NUMBER_:
    case UNDEF_:
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede sumar un string con un número\n");
        break;
    }
    printf("expr: expr_string + expr\n");
}
#line 2037 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 502 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case STRING_:
        (yyval.dato).palabra = restarCadena((yyvsp[-2].palabra),(yyvsp[0].dato).palabra);
        (yyval.dato).tipo = STRING_;
        break;
    case NUMBER_:
    case UNDEF_:
        printf("Operación inválida, no puede restar un string con un número\n");
        break;
    }
    printf("expr: expr_string - expr\n");
}
#line 2055 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 515 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case STRING_:
        printf("Operación inválida, no puede dividir un string con otro string de esta manera, use DIV para ello\n");
        (yyval.dato).tipo = UNDEF_;
        break;
    case NUMBER_:
    case UNDEF_:
        printf("Operación inválida, no puede dividir un string con un número\n");
        (yyval.dato).tipo = UNDEF_;
        break;
    }
    printf("expr: expr_string / expr\n");
}
#line 2074 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 529 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case STRING_:
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede multiplicar un string con otro string de esta manera, use POW para ello\n");
        (yyval.dato).palabra = (yyvsp[-2].palabra);
        break;
    case NUMBER_:
    case UNDEF_:
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede multiplicar un string con un número\n");
        break;
    }
    printf("expr: expr_string * expr\n");
}
#line 2094 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 544 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    switch ((yyvsp[0].dato).tipo) {
    case STRING_:
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede % un string con otro string de esta manera, use POW para ello\n");
        (yyval.dato).palabra = (yyvsp[-2].palabra);
        break;
    case NUMBER_:
    case UNDEF_:
        (yyval.dato).tipo = UNDEF_;
        printf("Operación inválida, no puede % un string con un número\n");
        break;
    }
    printf("expr: expr_string * expr\n");
}
#line 2114 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 559 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( (yyvsp[-1].dato).tipo == UNDEF_) {
        printf("expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else {
        (yyval.dato).tipo = STRING_;
        (yyval.dato).palabra = divCadena((yyvsp[-3].palabra),(yyvsp[-1].dato).palabra);
    }
    printf("DIV(expr,expr)\t");
}
#line 2129 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 569 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( (yyvsp[-1].dato).tipo == UNDEF_ || (yyvsp[-1].dato).tipo == STRING_ ) {
        printf("expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else if ( (yyvsp[-1].dato).tipo == NUMBER_ ) {
        (yyval.dato).tipo = STRING_;
        (yyval.dato).palabra = powCadena(invertirCadena((yyvsp[-3].palabra)),(int)(yyvsp[-1].dato).numero);
    }
    printf("DIV(expr,expr)\t");
}
#line 2144 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 579 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( (yyvsp[-2].dato).tipo == NUMBER_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
        (yyval.dato).tipo = NUMBER_;
        (yyval.dato).numero = (yyvsp[-2].dato).numero + (yyvsp[0].dato).numero;
    } else if ((yyvsp[-2].dato).tipo == STRING_ && (yyvsp[0].dato).tipo == STRING_) {
        (yyval.dato).tipo = STRING_;
        (yyval.dato).palabra = sumarCadena((yyvsp[-2].dato).palabra,(yyvsp[0].dato).palabra);
    } else {
        printf("operación con tipos de datos incompatibles\n");
        (yyval.dato).tipo = UNDEF_;
    }
    printf("expr + expr\t");
}
#line 2162 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 592 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( (yyvsp[-2].dato).tipo == NUMBER_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
        (yyval.dato).tipo = NUMBER_;
        (yyval.dato).numero = (yyvsp[-2].dato).numero - (yyvsp[0].dato).numero;
    } else if ((yyvsp[-2].dato).tipo == STRING_ && (yyvsp[0].dato).tipo == STRING_) {
        (yyval.dato).tipo = STRING_;
        (yyval.dato).palabra = restarCadena((yyvsp[-2].dato).palabra,(yyvsp[0].dato).palabra);
    } else {
        (yyval.dato).tipo = UNDEF_;
        printf("operación con tipos de datos incompatibles\n");
    }
    printf("expr - expr\t");
}
#line 2180 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 605 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( (yyvsp[-2].dato).tipo == NUMBER_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
        (yyval.dato).tipo = NUMBER_;
        if ( (yyvsp[0].dato).numero == 0.0 ) {
            printf("no se puede dividir entre cero.");
            (yyval.dato).numero = 0;
            (yyval.dato).tipo = NUMBER_;
        } else
            (yyval.dato).numero = (yyvsp[-2].dato).numero / (yyvsp[0].dato).numero;
    } else {
        (yyval.dato).tipo = UNDEF_;
        printf("operación con tipos de datos incompatibles\n");
    }
    printf("expr / expr\t");
}
#line 2200 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 620 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( (yyvsp[-2].dato).tipo == NUMBER_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
        (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = (yyvsp[-2].dato).numero * (yyvsp[0].dato).numero;
    } else {
        (yyval.dato).tipo = UNDEF_;
        printf("operación con tipos de datos incompatibles\n");
    }
    printf("expr * expr\t");
}
#line 2215 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 630 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( (yyvsp[-2].dato).tipo == NUMBER_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
        (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = (int)(yyvsp[-2].dato).numero % (int)(yyvsp[0].dato).numero;
    } else {
        (yyval.dato).tipo = UNDEF_;
        printf("operación con tipos de datos incompatibles\n");
    }
    printf("expr % expr\t");
}
#line 2230 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 640 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ((yyvsp[-3].dato).tipo == UNDEF_ || (yyvsp[-1].dato).tipo == UNDEF_) {
        printf("expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else if ((yyvsp[-3].dato).tipo == STRING_ && (yyvsp[-1].dato).tipo == STRING_) {
        (yyval.dato).tipo = STRING_;
        (yyval.dato).palabra = divCadena((yyvsp[-3].dato).palabra,(yyvsp[-1].dato).palabra);
    } else {
        printf("expr inválida, solo puede usarse este operador entre cadenas\n");
        (yyval.dato).tipo = UNDEF_;
    }
    printf("DIV(expr,expr)\t");
}
#line 2248 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 653 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if ( (yyvsp[-3].dato).tipo == UNDEF_ || (yyvsp[-1].dato).tipo == UNDEF_ ) {
        printf("expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else if ( (yyvsp[-3].dato).tipo == STRING_ && (yyvsp[-1].dato).tipo == NUMBER_ ) {
        (yyval.dato).tipo = STRING_;
        (yyval.dato).palabra = powCadena((yyvsp[-3].dato).palabra,(int)(yyvsp[-1].dato).numero);
    } else if ( (yyvsp[-3].dato).tipo == NUMBER_ && (yyvsp[-1].dato).tipo == NUMBER_ ) {
        (yyvsp[-3].dato).numero = (int)(yyvsp[-3].dato).numero;
        for (int i =1; i <(int)(yyvsp[-1].dato).numero ;i++)
            (yyvsp[-3].dato).numero *= (yyvsp[-3].dato).numero;
        (yyval.dato).tipo = NUMBER_;
        (yyval.dato).numero = (yyvsp[-3].dato).numero;
    } else {
        printf("expr inválida, solo puede usarse este operador entre cadenas\n");
        (yyval.dato).tipo = UNDEF_;
    }
    printf("DIV(expr,expr)\t");
}
#line 2272 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 672 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if (!existeSimbolo((yyvsp[0].palabra))) {
        printf("no existe el símbolo, expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else {
        Simbolo *sim = obtenerSimbolo((yyvsp[0].palabra));
        if (sim->tipo == INT_ ) {
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = sim->valor.entero;
        } else if (sim->tipo == DOUBLE_) {
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = sim->valor.decimal;
        } else if (sim->tipo == STRING_){
            (yyval.dato).tipo = STRING_;
            (yyval.dato).palabra = sim->valor.palabra;
        }
    }
    printf("ID\t");
}
#line 2296 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 691 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if (!existeSimbolo((yyvsp[-2].palabra))) {
        printf("no existe el símbolo, expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else if( (yyvsp[0].dato).tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo((yyvsp[-2].palabra));
        if (sim->tipo == INT_ && (yyvsp[0].dato).tipo == NUMBER_){
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = sim->valor.entero + (yyvsp[0].dato).numero;
        } else if (sim->tipo == DOUBLE_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = sim->valor.decimal + (yyvsp[0].dato).numero;
        } else if (sim->tipo == STRING_ && (yyvsp[0].dato).tipo == STRING_ ){
            (yyval.dato).tipo = STRING_;
            (yyval.dato).palabra = sumarCadena(sim->valor.palabra,(yyvsp[0].dato).palabra);
        }
    }
    printf("ID + expr\t");
}
#line 2322 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 712 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if (!existeSimbolo((yyvsp[-2].palabra))) {
        printf("no existe el símbolo, expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else if( (yyvsp[0].dato).tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo((yyvsp[-2].palabra));
        if (sim->tipo == INT_ && (yyvsp[0].dato).tipo == NUMBER_){
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = sim->valor.entero - (yyvsp[0].dato).numero;
        } else if (sim->tipo == DOUBLE_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = sim->valor.decimal - (yyvsp[0].dato).numero;
        } else if (sim->tipo == STRING_ && (yyvsp[0].dato).tipo == STRING_ ){
            (yyval.dato).tipo = STRING_;
            (yyval.dato).palabra = restarCadena(sim->valor.palabra,(yyvsp[0].dato).palabra);
        }
    }
    printf("ID - expr\t");
}
#line 2348 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 733 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if (!existeSimbolo((yyvsp[-2].palabra))) {
        printf("no existe el símbolo, expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else if( (yyvsp[0].dato).tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo((yyvsp[-2].palabra));
        if (sim->tipo == INT_ && (yyvsp[0].dato).tipo == NUMBER_){
            (yyval.dato).tipo = NUMBER_;
            if ( (yyvsp[0].dato).numero == 0.0 ) {
                printf("No se puede dividir entre cero\n");
                (yyval.dato).numero = 0;
            } else
                (yyval.dato).numero = sim->valor.entero / (yyvsp[0].dato).numero;
            (yyval.dato).tipo = NUMBER_;
        } else if ( sim->tipo == DOUBLE_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
            if ( (yyvsp[0].dato).numero == 0.0 ) {
                printf("No se puede dividir entre cero\n");
                (yyval.dato).numero = 0;
            } else
                (yyval.dato).numero = sim->valor.decimal / (yyvsp[0].dato).numero;
            (yyval.dato).tipo = NUMBER_;
        } else if ( sim->tipo == STRING_ && (yyvsp[0].dato).tipo == STRING_ ){
            (yyval.dato).tipo = UNDEF_;
            printf("expr inválida, para dividir cadenas use DIV\n");
        }
    }
    printf("ID / expr\t");
}
#line 2383 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 763 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if (!existeSimbolo((yyvsp[-2].palabra))) {
        printf("no existe el símbolo, expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else if( (yyvsp[0].dato).tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo((yyvsp[-2].palabra));
        if (sim->tipo == INT_ && (yyvsp[0].dato).tipo == NUMBER_){
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = sim->valor.entero * (yyvsp[0].dato).numero;
        } else if (sim->tipo == DOUBLE_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = sim->valor.decimal * (yyvsp[0].dato).numero;
        } else if (sim->tipo == STRING_ && (yyvsp[0].dato).tipo == STRING_ ){
            (yyval.dato).tipo = UNDEF_;
            printf("expr inválida, para multiplicar cadenas use POW\n");
        }
    }
    printf("ID * expr\t");
}
#line 2409 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 784 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if (!existeSimbolo((yyvsp[-2].palabra))) {
        printf("no existe el símbolo, expr inválida\n");
        (yyval.dato).tipo = UNDEF_;
    } else if( (yyvsp[0].dato).tipo == UNDEF_ ) {
        printf("expr inválida\n");
    } else {
        Simbolo *sim = obtenerSimbolo((yyvsp[-2].palabra));
        if (sim->tipo == INT_ && (yyvsp[0].dato).tipo == NUMBER_){
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = (int)sim->valor.entero % (int)(yyvsp[0].dato).numero;
        } else if (sim->tipo == DOUBLE_ && (yyvsp[0].dato).tipo == NUMBER_ ) {
            (yyval.dato).tipo = NUMBER_;
            (yyval.dato).numero = (int)sim->valor.decimal % (int)(yyvsp[0].dato).numero;
        } else if (sim->tipo == STRING_ && (yyvsp[0].dato).tipo == STRING_ ){
            (yyval.dato).tipo = UNDEF_;
            printf("expr inválida, para multiplicar cadenas use POW\n");
        }
    }
    printf("ID % expr\t");
}
#line 2435 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 809 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[0].decimal); }
#line 2441 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 810 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[-2].decimal) + (yyvsp[0].decimal);    }
#line 2447 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 811 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[-2].decimal) - (yyvsp[0].decimal);    }
#line 2453 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 812 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[-2].decimal) * (yyvsp[0].decimal);    }
#line 2459 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 813 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    for(int i = 1; i<(int)(yyvsp[-1].decimal); i++)
        (yyvsp[-3].decimal) *= (yyvsp[-3].decimal);
    (yyval.decimal) = (int)(yyvsp[-3].decimal);
}
#line 2469 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 818 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (int)(yyvsp[-2].decimal) % (int)(yyvsp[0].decimal);    }
#line 2475 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 819 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { if( (yyvsp[0].decimal) == 0.0f ) { printf("El denominador no debe ser cero\n"); (yyval.decimal)=0; } else { (yyval.decimal) = (yyvsp[-2].decimal) / (yyvsp[0].decimal); } }
#line 2481 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 820 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[-2].entero) + (yyvsp[0].decimal);    }
#line 2487 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 821 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[-2].entero) - (yyvsp[0].decimal);    }
#line 2493 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 822 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[-2].entero) * (yyvsp[0].decimal);    }
#line 2499 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 823 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (int)(yyvsp[-2].entero) % (int)(yyvsp[0].decimal);    }
#line 2505 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 824 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { if( (yyvsp[0].decimal) == 0.0f ) { printf("El denominador no debe ser cero\n"); (yyval.decimal)=0; } else { (yyval.decimal) = (yyvsp[-2].entero) / (yyvsp[0].decimal); } }
#line 2511 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 825 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[-2].decimal) + (yyvsp[0].entero);    }
#line 2517 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 826 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[-2].decimal) - (yyvsp[0].entero);    }
#line 2523 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 827 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (yyvsp[-2].decimal) * (yyvsp[0].entero);    }
#line 2529 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 828 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    for(int i = 1; i<(yyvsp[-1].entero); i++)
        (yyvsp[-3].decimal) *= (yyvsp[-3].decimal);
    (yyval.decimal) = (int)(yyvsp[-3].decimal);
}
#line 2539 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 833 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = (int)(yyvsp[-2].decimal) % (int)(yyvsp[0].entero);    }
#line 2545 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 834 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { if( (yyvsp[0].entero) == 0 ) { printf("El denominador no debe ser cero\n"); (yyval.decimal)=0; } else { (yyval.decimal) = (yyvsp[-2].decimal) / (yyvsp[0].entero); } }
#line 2551 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 835 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.decimal) = -(yyvsp[0].decimal); }
#line 2557 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 839 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {  (yyval.palabra) = (yyvsp[-1].palabra); }
#line 2563 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 840 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.palabra) = sumarCadena((yyvsp[-2].palabra),(yyvsp[0].palabra)); }
#line 2569 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 841 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.palabra) = restarCadena((yyvsp[-2].palabra),(yyvsp[0].palabra)); }
#line 2575 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 842 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {  (yyval.palabra) = divCadena((yyvsp[-3].palabra),(yyvsp[-1].palabra));  }
#line 2581 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 843 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    if( (yyvsp[-1].entero) < 0 ) {
        //printf("menor a cero. Cadena invertida:\n%s",invertirCadena($3));
        (yyval.palabra) = powCadena(invertirCadena((yyvsp[-3].palabra)),(yyvsp[-1].entero)*-1);
    } else if ( (yyvsp[-1].entero) == 0) {
        (yyval.palabra) = (yyvsp[-3].palabra);
    } else {
        (yyval.palabra) = powCadena((yyvsp[-3].palabra),(yyvsp[-1].entero));
    }

}
#line 2597 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 857 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.entero) = (yyvsp[0].entero); }
#line 2603 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 858 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.entero) = (yyvsp[-2].entero) + (yyvsp[0].entero); }
#line 2609 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 859 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.entero) = (yyvsp[-2].entero) - (yyvsp[0].entero); }
#line 2615 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 860 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.entero) = (yyvsp[-2].entero) * (yyvsp[0].entero); }
#line 2621 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 861 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.entero) = (yyvsp[-2].entero) % (yyvsp[0].entero); }
#line 2627 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 862 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    {
    for(int i = 1; i<(yyvsp[-1].entero); i++)
        (yyvsp[-3].entero) *= (yyvsp[-3].entero);
    (yyval.entero) = (yyvsp[-3].entero);
}
#line 2637 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 867 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { if((yyvsp[0].entero) == 0)  { printf("El denominador no debe ser cero\n"); (yyval.entero)=0; } else { (yyval.entero) = (yyvsp[-2].entero) / (yyvsp[0].entero); }    }
#line 2643 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 868 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1646  */
    { (yyval.entero) = -(yyvsp[0].entero); }
#line 2649 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
    break;


#line 2653 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/build/parser.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 871 "/home/lalo/Dropbox/escom/Compiladores/practicas/05/ejemplo2.y" /* yacc.c:1906  */


TablaSimbolos table; // global

int main() {
  table.first = NULL;
  yyparse();
  return 0;
}

Simbolo * obtenerSimbolo(char *name){
    for (Simbolo *i = table.first; i != NULL; i = i->next)
        if (compararCadena(name,i->nombre))
            return i;
}

void agregarSimbolo(char *nombre,int tipo, Valor *valor) {
    Simbolo *i;

    if (table.first == NULL ) {
        i = malloc(sizeof(Simbolo));
        i->nombre = nombre;
        i->tipo = tipo;
        i->valor = *valor;
        i->next = NULL;
        table.first = i;
    } else {

    for (i  = table.first ; i->next != NULL; i = i->next)
        ;

    i->next = malloc(sizeof(Simbolo));
    i->next->nombre = nombre;
    i->next->tipo = tipo;
    i->next->valor = *valor;
    i->next->next = NULL;
    }
    //imprimirSimbolo(table.first->next);
    imprimirTabla();
}

void imprimirSimbolo(Simbolo *i){
    switch (i->tipo) {
    case INT_:
        printf("%s\t\tint\t%d\n",i->nombre, i->valor.entero);
        break;
    case DOUBLE_:
        printf("%s\t\tdouble\t%f\n",i->nombre, i->valor.decimal);
        break;
    case STRING_:
        printf("%s\t\tstring\t%s\n",i->nombre, i->valor.palabra);
        break;
    case ARR_:
        printf("%s[%d]\tarray double\n",i->nombre, i->valor.tamArr);
        break;
    default:
        printf("%s\tint\t%d\n",i->nombre, i->valor.entero);
        printf("algo anda mal\n");
        break;
    }
}
char existeSimbolo(char*nombre){

    for (Simbolo *i = table.first; i != NULL; i = i->next)
        if (compararCadena(nombre,i->nombre))
            return 1;
    return 0;

}
void imprimirTabla(){
    printf("----------------------------------------------------\n");
    printf("Nombre\t\t tipo\tvalor\n");

    for (Simbolo *i = table.first; i != NULL; i = i->next)
        imprimirSimbolo(i);
}

int longitudCadena(char *a) {
    int i;
    for ( i = 0; a[i] != '\0'; i++)
        ;
    return i;
}

char isBinA(char*a, char*b) {
    int sizeA = longitudCadena(a);
    int sizeB = longitudCadena(b);

    if ( sizeB > sizeA )//es mayor la longitud de b, terminamos
        return 0;
    //Si 'b' está en 'a'...

    for ( int i = 0; i<sizeA; i++ )//recorremos cadena 'a'
        if ( a[i] != '\0' && compararCadena(a+i,b) )
            return 1;

    return 0;
}

char * restarCadena(char *a, char *b) {

    int sizeA = longitudCadena(a);
    int sizeB = longitudCadena(b);
    int size = sizeA;

    //no interesa alojar más espacio del necesario
    //total, termina de imprimir la cadena al encontrar el primer '\0'
    char * str = malloc(size+1);

    //limpiamos cadena
    for (int i = 0; i < size+1; i++)
        str[i] = 0;


    //verificamos que la cadena b esté contenida en 'a'
    if (!isBinA(a,b))//si no está, regresamos simplemente 'a'
        return a;

    //quitamos la primer instancia de 'b'

    for (int i = 0; i < sizeA; i++)
        if (a[i] != '\0' && compararCadena(a+i,b)) {
            //copiamos lo anterior de la cadena
            for ( int j = 0; j < i; j++)
                str[j] = a[j];

            //copiamos lo que falta
            for ( int j = i+sizeB; j < size+1; j++){
                //printf("char: %c\n",a[j]);
                str[j-sizeB] = a[j];
            }

            //marcamos fin de cadena
            str[size+1-sizeB] = '\0';
            break;
        }

    return str;

}
char * sumarCadena(char *a, char *b){

    int sizeA = longitudCadena(a);
    int sizeB = longitudCadena(b);
    int size = sizeA+sizeB;

    char * str = malloc(size+1);

    //limpiamos cadena
    for (int i = 0; i < size; i++)
        str[i] = 0;


    //copiamos primer cadena
    for (int i = 0; i < sizeA; i++)
        *(str+i) = a[i];

    //copiamos segunda cadena
    for (int i = 0; i < sizeB; i++)
        *(str+sizeA+i) = b[i];

    str[size+1] = '\0'; //marcamos el fin de la cadena
    return str;
}

char * invertirCadena(char *a) {
    int size = longitudCadena(a);
    char * str = malloc(size);
    int i,j;
    for (i = size-1, j=0; i>=0;i--,j++)
        str[j] = a[i];

    str[j+1]='\0';

    return str;
}

char compararCadena(char *a, char *b) {
    int sizeB = longitudCadena(b);

    for (int i = 0; i < sizeB; i++)
        if (a[i] != b[i])
            return 0;

    return 1;
}
void copiarCadena(char *str, char *a, int sizeB) {

    //copiamos
    for (int i = 0; i < sizeB; i++)
        str[i] = a[i];
}
char *divCadena(char*a,char*b){

    char * str = a;//es el max tam que puede tener la cadena

    for(int i = 0; i < longitudCadena(a); i++)
        str = restarCadena(str,b);
    return str;
}
char *powCadena(char*a,int b){
    char * str = a;
    for (int i =0; i<b-1; i++)
        str = sumarCadena(str,a);
    return str;
}
void yyerror (char *s) {
  printf ("--%s--\n", s);
}

int yywrap() {
  return 1;
}
