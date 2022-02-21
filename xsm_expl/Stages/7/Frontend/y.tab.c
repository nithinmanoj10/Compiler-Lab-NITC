/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "ast.y"
	extern char yytext[];
	#define YYDEBUG_LEXER_TEXT yytext

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <limits.h>
	#include "ast.h"
	#include "../Backend/codegen.h"
	#include "../Data_Structures/loopStack.h"
	#include "../Data_Structures/GSTable.h"
	#include "../Data_Structures/LSTable.h"
	#include "../Data_Structures/typeTable.h"
	#include "../Data_Structures/paramStruct.h"
	#include "../Data_Structures/classTable.h"
	#include "../Data_Structures/memberFuncList.h"
	#include "../Functions/xsm_library.h"
	#include "../Functions/xsm_syscalls.h"
	#include "../Functions/stackMemory.h"
	#include "../Functions/stringMan.h"
	#include "../Functions/label.h"

	int yylex(void);
	void yyerror(char const *s);
	int statementCount = 0;
	int typeFieldCount = 0;
	int tupleFieldCount = 0;
	char* fileName;
	FILE* filePtr;
#line 35 "ast.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	struct ASTNode* node;
	struct LSTNode* lstnode;
	struct TypeTable* TTNode;
	struct FieldList* FLNode;
	struct ClassTable* CTNode;
	struct MemberFuncList* MFLNode;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 67 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ID 257
#define NUM 258
#define STRING 259
#define INITIALIZE 260
#define ALLOC 261
#define FREE 262
#define NULL_ 263
#define BEGIN_ 264
#define END 265
#define MAIN 266
#define READ 267
#define WRITE 268
#define PLUS 269
#define MINUS 270
#define MUL 271
#define DIV 272
#define MOD 273
#define AMPERSAND 274
#define BREAKPOINT 275
#define TYPE 276
#define ENDTYPE 277
#define TUPLE 278
#define IF 279
#define THEN 280
#define ELSE 281
#define ENDIF 282
#define WHILE 283
#define DO 284
#define ENDWHILE 285
#define BREAK 286
#define CONTINUE 287
#define AND 288
#define OR 289
#define NOT 290
#define DECL 291
#define ENDDECL 292
#define INT 293
#define STR 294
#define RETURN 295
#define SELF 296
#define CLASS 297
#define ENDCLASS 298
#define EQ 299
#define NEQ 300
#define LT 301
#define LTE 302
#define GT 303
#define GTE 304
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,   41,   41,   46,   46,   47,
   29,   35,   35,   34,   28,   28,   28,   42,   48,   48,
   33,   40,   39,   50,   50,   51,   49,    1,    1,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    3,
    4,    5,    5,    5,    5,   15,   14,    6,    6,    9,
   10,   11,   12,   13,   43,   43,   54,   54,   55,   55,
   30,   30,   30,   30,   56,   56,   57,   57,   57,   57,
   57,   20,   38,   37,   37,   36,   32,   32,   27,   52,
   52,   52,   58,   59,   59,   59,   59,   59,   19,   19,
   19,   18,   44,   44,    7,   60,   61,   63,   63,   63,
   63,   63,   17,   62,   62,   62,   64,   64,   65,   65,
   31,   31,   31,   31,   66,   66,   67,   67,   67,   45,
   68,   16,   53,   53,   53,   23,   24,   22,   25,   25,
   69,   69,   21,   21,   26,   26,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,
};
static const YYINT yylen[] = {                            2,
    5,    4,    3,    4,    2,    3,    0,    2,    1,    4,
    1,    2,    1,    3,    1,    1,    1,    3,    2,    1,
    5,    4,    1,    2,    1,    6,    1,    3,    2,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    2,
    2,    3,    6,    4,    3,    1,    3,    7,    5,    5,
    5,    1,    1,    1,    3,    2,    2,    1,    3,    4,
    1,    1,    1,    2,    3,    1,    1,    4,    4,    1,
    4,    2,    3,    3,    1,    2,    1,    1,    1,    3,
    1,    0,    2,    1,    1,    2,    2,    1,    3,    1,
    0,    1,    2,    1,    1,    5,    5,    1,    1,    2,
    2,    1,    5,    3,    0,    2,    2,    1,    3,    4,
    1,    1,    1,    2,    3,    1,    1,    4,    2,    7,
    2,    5,    1,    1,    1,    4,    5,    4,    2,    5,
    6,    4,    3,    3,    1,    4,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    3,    1,    1,    4,    4,    2,    2,    1,    1,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,   11,    0,    0,    9,    0,    0,    0,
    0,    0,    6,    8,   63,    0,   56,   61,   62,    0,
    0,   58,   23,   20,    0,    0,    0,  102,    0,    0,
    0,    3,   94,    0,    0,    0,   17,   15,   16,    0,
   13,    0,   64,    0,    0,    0,    0,    0,    0,   66,
   55,   57,    0,   18,   19,    0,    2,  121,  100,  101,
    4,   93,    0,   95,    0,    0,    0,   10,   12,    0,
    0,   72,   77,   78,    0,   75,    0,    0,    0,    0,
   59,    0,    0,    1,    0,    0,    0,    0,   14,   88,
    0,    0,    0,   81,    0,    0,   79,   76,    0,   73,
    0,   60,   65,    0,    0,    0,    0,  113,    0,  106,
  111,  112,    0,    0,  108,    0,    0,    0,    0,   86,
   87,    0,   69,   83,   68,   74,   71,    0,    0,   25,
   21,  114,    0,    0,    0,    0,  116,  104,  107,    0,
    0,    0,    0,   54,    0,    0,    0,   52,   53,    0,
    0,   30,   31,   32,   33,   34,   35,   36,   37,   38,
    0,  125,  123,  124,    0,    0,   39,   96,   97,    0,
   80,    0,   22,    0,   24,    0,  119,    0,    0,  109,
    0,    0,    0,  159,  160,  161,    0,    0,    0,    0,
    0,    0,    0,  153,    0,    0,    0,    0,    0,    0,
    0,    0,   29,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  110,  115,    0,    0,    0,    0,
  157,  156,  150,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   28,    0,    0,  133,    0,
    0,    0,  134,    0,  120,    0,  118,    0,    0,   90,
    0,    0,    0,  151,    0,    0,  139,  140,  141,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   47,  103,  128,  126,    0,    0,    0,    0,
    0,  154,    0,    0,  132,    0,   49,   50,   51,  127,
    0,   26,    0,   89,    0,    0,  122,  131,   48,
};
static const YYINT yydgoto[] = {                          2,
  150,  151,  152,  153,  154,  155,   65,  259,  156,  157,
  158,  159,  160,  202,  245,  211,  117,  260,  261,   47,
  193,  162,  163,  164,  165,  166,   98,   40,    5,   20,
  113,   75,   24,   41,   42,   76,   77,   48,   25,   83,
    3,   10,   11,   31,   32,    6,    7,   26,  107,  129,
  130,   93,  167,   21,   22,   49,   50,   94,   95,   33,
   34,   86,   35,  114,  115,  136,  137,   36,  194,
};
static const YYINT yysindex[] = {                      -248,
 -221,    0, -260,    0,  -68, -234,    0, -211, -178, -188,
 -230, -169,    0,    0,    0, -126,    0,    0,    0,  -38,
 -203,    0,    0,    0,   24, -242, -230,    0, -103, -114,
 -230,    0,    0,   54,  -79,  155,    0,    0,    0,  -73,
    0, -118,    0,  -26,  -47, -129,  178, -143,  -19,    0,
    0,    0,  -80,    0,    0, -230,    0,    0,    0,    0,
    0,    0,  -67,    0,  187,  199,  192,    0,    0, -144,
   20,    0,    0,    0,   -5,    0,   -6, -144,  -15, -143,
    0, -169, -138,    0, -172,   16, -144,  160,    0,    0,
   11,   13,  104,    0,   31,  201,    0,    0, -129,    0,
  125,    0,    0, -169,   44, -138,  197,    0,   69,    0,
    0,    0,   22, -141,    0,  551,  204,  138,  -67,    0,
    0, -144,    0,    0,    0,    0,    0,   76, -196,    0,
    0,    0,  239,   77, -127,   34,    0,    0,    0,  -42,
  206,  206,   84,    0,  206,  206,  551,    0,    0,  -70,
  290,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   40,    0,    0,    0,  -40,  305,    0,    0,    0,   91,
    0,  -18,    0,  103,    0,  106,    0,   48, -127,    0,
  206,  206,  -20,    0,    0,    0,  108,  109,  206,  315,
  206,  434,   -7,    0,  434,  319,  384,  346,  572,  206,
  322,  117,    0,  206,  128,  349,  355,  356,  129,  551,
  272, -144,  364,  312,    0,    0,  434,  221,  206,  206,
    0,    0,    0,  151,  121,  206,  206,  206,  206,  206,
  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,
  551,  551,  206,  434,  347,    0,  348,  434,    0,  375,
  376,  206,    0,  -70,    0,  144,    0,  357,  434,    0,
  145,  257,  379,    0,  -16,  -16,    0,    0,    0,  268,
  440,  246,  246,  -99,  -99,  -99,  -99,  150,  434,  488,
  509,  337,    0,    0,    0,    0,  142,  161,  368,  206,
  206,    0,    0,  206,    0,  551,    0,    0,    0,    0,
  369,    0,  434,    0,  158,  530,    0,    0,    0,
};
static const YYINT yyrindex[] = {                      -223,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  436,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  183,  190,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   67,    0,    0,   73,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  175,    0,    0,    0,    0,    0,    0,  159,
    0,    0,    0,    0,    0,    0,    0,  159,    0,    0,
    0,    0,    0,    0,    0,    0,  159,    0,    0,    0,
  194,  195,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  183,  328,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  175,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   79,    0,    0,    0,    0,    0,    0,  409,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   37,    0,  -41,    0,    0,    0,    0,    0,    0,    0,
    0,  397,    1,    0,  399,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  159,    0,    0,    0,    0,  400,    0,  163,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  163,    0,
    0,    0,    0,  401,    0,    0,    0,  402,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  422,  171,    0,
    0,    0,    0,    0,    7,   43,    0,    0,    0,  391,
  413,  149,  182,   36,   68,   74,   99,    0,  414,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   57,
    0,    0,  -35,  163,    0,    0,    0,    0,    0,    0,
    0,    0,  415,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
 -137, -146,    0,    0,    0,    0,    0,  362,    0,    0,
    0,    0,    0,  222,    0,    0,    0,  184, -222,    0,
 -100,    0,    0,    0,    0,    0,    0,  -72,    0,    0,
    0,    0,  452,  -34,  403,  380,    0,  370,    0,    0,
    0,    0,  476,  -14,    3,    0,  481,    0,    0,    0,
  359,  -66,    0,    0,  468,  447,  417,  377,    0,  -30,
    0,  381,    0,    0,  387,  363,  326,    0,    0,
};
#define YYTABLESIZE 859
static const YYINT yytable[] = {                        158,
   62,   46,  158,  201,  135,  155,   68,   69,  155,  199,
  136,  101,   56,   70,   23,  161,  278,  158,  181,  219,
  118,  212,    4,  155,   80,   62,   28,    1,   80,   57,
    8,  128,  239,   61,  100,    4,    9,   99,  205,   81,
   89,  152,   13,  102,  152,   15,  161,  137,  182,  161,
  137,  158,  201,   15,   12,   54,  174,  155,   84,  152,
   37,   46,   29,   30,   71,  137,   16,    7,  106,   69,
  220,  305,  254,    7,   16,   62,  144,  179,   23,  144,
   17,   18,   19,  138,  108,  205,  138,   37,   51,   18,
   19,  179,  180,  152,  144,  173,   38,   39,  161,  137,
  204,  138,    8,  280,  281,  109,  215,  201,  145,  161,
   67,  145,   90,   44,  146,  108,   70,  146,   28,  110,
  111,  112,  117,   38,   39,   67,  145,   45,  144,  133,
   43,   70,  146,  201,  201,  138,  109,  117,   37,  147,
  161,  161,  147,  134,  123,  256,   53,  122,   91,   92,
  138,  111,  112,  161,  105,   30,   60,  147,  306,  201,
  145,  264,   58,   73,   74,  127,  146,   59,  122,  226,
  227,  228,  229,  230,   38,   39,   63,   64,  169,  161,
  161,  122,  300,   67,  289,  292,  140,  122,  291,  142,
  295,  147,  142,  291,   66,  161,  141,  142,  308,   82,
  143,  291,   82,   91,  144,  161,   91,  142,  145,   72,
   82,   92,  146,  147,   92,  148,  149,   78,   44,  206,
  207,  208,  143,   85,  200,  143,   87,  158,  158,  158,
  158,  158,   45,  155,  155,  155,  155,  155,  158,   88,
  143,  142,  158,  158,  155,  191,  158,  158,  155,  155,
   89,   97,  155,  155,  228,  229,  230,  158,  158,  158,
  158,  158,  158,  155,  155,  155,  155,  155,  155,  152,
  152,  152,  152,  152,  143,  137,  137,   96,  133,  116,
  152,  120,  119,  121,  152,  152,  137,  124,  152,  152,
  137,  137,  134,  125,  137,  137,  129,  129,  129,  152,
  152,  152,  152,  152,  152,  137,  137,  137,  137,  137,
  137,  138,  138,  258,   59,  144,  130,  130,  130,  144,
  144,  131,  138,  144,  144,  132,  138,  138,  168,  176,
  138,  138,  172,  177,  144,  144,  144,  144,  144,  144,
  196,  138,  138,  138,  138,  138,  138,  145,  203,  293,
  209,  145,  145,  146,  210,  145,  145,  146,  146,  213,
  224,  146,  146,  214,  221,  222,  145,  145,  145,  145,
  145,  145,  146,  146,  146,  146,  146,  146,  147,  240,
  246,  247,  147,  147,  249,  253,  147,  147,  250,  226,
  227,  228,  229,  230,  251,  252,  255,  147,  147,  147,
  147,  147,  147,  212,  257,  283,  284,  263,  231,  232,
  226,  227,  228,  229,  230,  285,  286,  290,  294,  233,
  234,  235,  236,  237,  238,  301,  302,  307,  142,  231,
  232,  148,  142,  142,  148,    5,  142,  142,  105,   98,
  233,  234,  235,  236,  237,  238,   99,  142,  142,  148,
   84,   85,   27,  149,  135,   40,  149,   41,   42,   46,
   45,  143,  183,  184,  185,  143,  143,  136,  186,  143,
  143,  149,   44,   43,  304,  288,  187,   55,  126,  188,
  143,  143,  135,  148,  104,   27,   14,  175,   52,  226,
  227,  228,  229,  230,   79,  189,  103,  178,  171,  170,
  139,  190,  192,  195,  216,  149,  197,  198,  231,  232,
    0,    0,    0,    0,  226,  227,  228,  229,  230,  233,
  234,  235,  236,  237,  238,  226,  227,  228,  229,  230,
    0,    0,    0,    0,    0,    0,  226,  227,  228,  229,
  230,    0,  217,  218,  231,  232,  235,  236,  237,  238,
  223,    0,  225,    0,    0,  233,  234,  235,  236,  237,
  238,  244,    0,    0,    0,  248,  233,  234,  235,  236,
  237,  238,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  262,    0,    0,    0,    0,    0,  265,  266,  267,
  268,  269,  270,  271,  272,  273,  274,  275,  276,  277,
    0,  279,    0,    0,  282,  226,  227,  228,  229,  230,
    0,    0,    0,  287,  226,  227,  228,  229,  230,    0,
  242,  299,    0,    0,  231,  232,    0,    0,    0,  242,
    0,    0,    0,  231,  232,  233,  234,  235,  236,  237,
  238,    0,    0,    0,  233,  234,  235,  236,  237,  238,
    0,  303,  226,  227,  228,  229,  230,    0,    0,    0,
    0,    0,    0,  241,    0,    0,    0,    0,    0,    0,
  148,  231,  232,    0,  148,  148,    0,    0,  148,  148,
    0,    0,  233,  234,  235,  236,  237,  238,    0,    0,
    0,    0,  149,    0,    0,    0,  149,  149,    0,    0,
    0,  149,  226,  227,  228,  229,  230,    0,  226,  227,
  228,  229,  230,    0,    0,    0,    0,    0,    0,    0,
    0,  231,  232,    0,    0,    0,    0,  231,    0,    0,
    0,    0,  233,  234,  235,  236,  237,  238,  233,  234,
  235,  236,  237,  238,  140,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  141,  142,    0,    0,  143,    0,
    0,    0,  144,    0,    0,  140,  145,    0,  296,  297,
  146,  147,    0,  148,  149,  141,  142,    0,    0,  143,
    0,    0,    0,  144,    0,    0,  140,  145,    0,    0,
    0,  146,  147,  298,  148,  149,  141,  142,    0,    0,
  143,    0,    0,    0,  144,    0,    0,  140,  145,    0,
    0,  309,  146,  147,    0,  148,  149,  141,  142,    0,
    0,  143,    0,    0,    0,  144,    0,    0,  140,  145,
    0,    0,    0,  146,  147,    0,  148,  149,  141,  142,
    0,    0,  143,    0,    0,    0,  144,    0,    0,    0,
  145,    0,    0,    0,  243,  147,    0,  148,  149,
};
static const YYINT yycheck[] = {                         41,
   31,   40,   44,  150,   46,   41,  125,   42,   44,  147,
   46,   78,   27,   40,  257,  116,  239,   59,   61,   40,
   87,   40,  257,   59,   44,   56,  257,  276,   44,   27,
  291,  104,   40,   31,   41,  257,  297,   44,   46,   59,
   59,   41,  277,   59,   44,  257,  147,   41,   91,  150,
   44,   93,  199,  257,  123,  298,  129,   93,   56,   59,
  257,   40,  293,  294,   91,   59,  278,  291,   83,  104,
   91,  294,  210,  297,  278,  106,   41,   44,  257,   44,
  292,  293,  294,   41,  257,   46,   44,  257,  292,  293,
  294,   44,   59,   93,   59,  292,  293,  294,  199,   93,
   61,   59,  291,  241,  242,  278,   59,  254,   41,  210,
   44,   44,  257,  257,   41,  257,   44,   44,  257,  292,
  293,  294,   44,  293,  294,   59,   59,  271,   93,  257,
  257,   59,   59,  280,  281,   93,  278,   59,  257,   41,
  241,  242,   44,  271,   41,  212,  123,   44,  293,  294,
  292,  293,  294,  254,  293,  294,  271,   59,  296,  306,
   93,   41,  266,  293,  294,   41,   93,  271,   44,  269,
  270,  271,  272,  273,  293,  294,  123,  257,   41,  280,
  281,   44,   41,  257,   41,   41,  257,   44,   44,   41,
   41,   93,   44,   44,   40,  296,  267,  268,   41,   41,
  271,   44,   44,   41,  275,  306,   44,   59,  279,  257,
  291,   41,  283,  284,   44,  286,  287,   40,  257,  260,
  261,  262,   41,  291,  295,   44,   40,  269,  270,  271,
  272,  273,  271,  269,  270,  271,  272,  273,  280,   41,
   59,   93,  284,  285,  280,   40,  288,  289,  284,  285,
   59,  257,  288,  289,  271,  272,  273,  299,  300,  301,
  302,  303,  304,  299,  300,  301,  302,  303,  304,  269,
  270,  271,  272,  273,   93,  269,  270,  258,  257,  264,
  280,  271,  123,  271,  284,  285,  280,  257,  288,  289,
  284,  285,  271,   93,  288,  289,  260,  261,  262,  299,
  300,  301,  302,  303,  304,  299,  300,  301,  302,  303,
  304,  269,  270,   93,  271,  280,  260,  261,  262,  284,
  285,  125,  280,  288,  289,  257,  284,  285,  125,   91,
  288,  289,  257,  257,  299,  300,  301,  302,  303,  304,
  257,  299,  300,  301,  302,  303,  304,  280,   59,   93,
   46,  284,  285,  280,  264,  288,  289,  284,  285,  257,
   46,  288,  289,  258,  257,  257,  299,  300,  301,  302,
  303,  304,  299,  300,  301,  302,  303,  304,  280,   61,
   59,  265,  284,  285,  257,  257,  288,  289,   40,  269,
  270,  271,  272,  273,   40,   40,  125,  299,  300,  301,
  302,  303,  304,   40,   93,   59,   59,  257,  288,  289,
  269,  270,  271,  272,  273,   41,   41,   61,   40,  299,
  300,  301,  302,  303,  304,  265,   59,   59,  280,  288,
  289,   41,  284,  285,   44,    0,  288,  289,  264,  257,
  299,  300,  301,  302,  303,  304,  257,  299,  300,   59,
  257,  257,  125,   41,   46,   59,   44,   59,   59,   59,
   59,  280,  257,  258,  259,  284,  285,   46,  263,  288,
  289,   59,   59,   59,  291,  254,  271,   26,   99,  274,
  299,  300,  113,   93,   82,   10,    6,  129,   21,  269,
  270,  271,  272,  273,   48,  290,   80,  135,  122,  119,
  114,  296,  141,  142,  179,   93,  145,  146,  288,  289,
   -1,   -1,   -1,   -1,  269,  270,  271,  272,  273,  299,
  300,  301,  302,  303,  304,  269,  270,  271,  272,  273,
   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
  273,   -1,  181,  182,  288,  289,  301,  302,  303,  304,
  189,   -1,  191,   -1,   -1,  299,  300,  301,  302,  303,
  304,  200,   -1,   -1,   -1,  204,  299,  300,  301,  302,
  303,  304,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  220,   -1,   -1,   -1,   -1,   -1,  226,  227,  228,
  229,  230,  231,  232,  233,  234,  235,  236,  237,  238,
   -1,  240,   -1,   -1,  243,  269,  270,  271,  272,  273,
   -1,   -1,   -1,  252,  269,  270,  271,  272,  273,   -1,
  284,  285,   -1,   -1,  288,  289,   -1,   -1,   -1,  284,
   -1,   -1,   -1,  288,  289,  299,  300,  301,  302,  303,
  304,   -1,   -1,   -1,  299,  300,  301,  302,  303,  304,
   -1,  290,  269,  270,  271,  272,  273,   -1,   -1,   -1,
   -1,   -1,   -1,  280,   -1,   -1,   -1,   -1,   -1,   -1,
  280,  288,  289,   -1,  284,  285,   -1,   -1,  288,  289,
   -1,   -1,  299,  300,  301,  302,  303,  304,   -1,   -1,
   -1,   -1,  280,   -1,   -1,   -1,  284,  285,   -1,   -1,
   -1,  289,  269,  270,  271,  272,  273,   -1,  269,  270,
  271,  272,  273,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  288,  289,   -1,   -1,   -1,   -1,  288,   -1,   -1,
   -1,   -1,  299,  300,  301,  302,  303,  304,  299,  300,
  301,  302,  303,  304,  257,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,   -1,   -1,  271,   -1,
   -1,   -1,  275,   -1,   -1,  257,  279,   -1,  281,  282,
  283,  284,   -1,  286,  287,  267,  268,   -1,   -1,  271,
   -1,   -1,   -1,  275,   -1,   -1,  257,  279,   -1,   -1,
   -1,  283,  284,  285,  286,  287,  267,  268,   -1,   -1,
  271,   -1,   -1,   -1,  275,   -1,   -1,  257,  279,   -1,
   -1,  282,  283,  284,   -1,  286,  287,  267,  268,   -1,
   -1,  271,   -1,   -1,   -1,  275,   -1,   -1,  257,  279,
   -1,   -1,   -1,  283,  284,   -1,  286,  287,  267,  268,
   -1,   -1,  271,   -1,   -1,   -1,  275,   -1,   -1,   -1,
  279,   -1,   -1,   -1,  283,  284,   -1,  286,  287,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 304
#define YYUNDFTOKEN 376
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,"'.'",0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,"'='",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"ID","NUM","STRING","INITIALIZE","ALLOC","FREE","NULL_","BEGIN_","END",
"MAIN","READ","WRITE","PLUS","MINUS","MUL","DIV","MOD","AMPERSAND","BREAKPOINT",
"TYPE","ENDTYPE","TUPLE","IF","THEN","ELSE","ENDIF","WHILE","DO","ENDWHILE",
"BREAK","CONTINUE","AND","OR","NOT","DECL","ENDDECL","INT","STR","RETURN",
"SELF","CLASS","ENDCLASS","EQ","NEQ","LT","LTE","GT","GTE",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock",
"start : TypeDefBlock ClassDefBlock GDeclBlock MainBlock",
"start : TypeDefBlock GDeclBlock MainBlock",
"start : TypeDefBlock GDeclBlock FDefBlock MainBlock",
"start : TypeDefBlock GDeclBlock",
"TypeDefBlock : TYPE TypeDefList ENDTYPE",
"TypeDefBlock :",
"TypeDefList : TypeDefList TypeDef",
"TypeDefList : TypeDef",
"TypeDef : TypeID '{' FieldDeclList '}'",
"TypeID : ID",
"FieldDeclList : FieldDeclList FieldDecl",
"FieldDeclList : FieldDecl",
"FieldDecl : TypeName ID ';'",
"TypeName : INT",
"TypeName : STR",
"TypeName : ID",
"ClassDefBlock : CLASS ClassDefList ENDCLASS",
"ClassDefList : ClassDefList ClassDef",
"ClassDefList : ClassDef",
"ClassDef : ClassName '{' ClassMembers MethodDefns '}'",
"ClassMembers : DECL FieldDeclList MethodDeclList ENDDECL",
"ClassName : ID",
"MethodDeclList : MethodDeclList MethodDecl",
"MethodDeclList : MethodDecl",
"MethodDecl : TypeName ID '(' ParamList ')' ';'",
"MethodDefns : FDefBlock",
"Slist : Slist Stmt ';'",
"Slist : Stmt ';'",
"Stmt : inputStmt",
"Stmt : outputStmt",
"Stmt : assignStmt",
"Stmt : ifStmt",
"Stmt : whileStmt",
"Stmt : doWhileStmt",
"Stmt : breakStmt",
"Stmt : continueStmt",
"Stmt : breakPointStmt",
"Stmt : DynamicMemStmt",
"inputStmt : READ expr",
"outputStmt : WRITE expr",
"assignStmt : ID '=' expr",
"assignStmt : ID '[' expr ']' '=' expr",
"assignStmt : MUL ID '=' expr",
"assignStmt : Field '=' expr",
"retVal : expr",
"retStmt : RETURN retVal ';'",
"ifStmt : IF expr THEN Slist ELSE Slist ENDIF",
"ifStmt : IF expr THEN Slist ENDIF",
"whileStmt : WHILE expr DO Slist ENDWHILE",
"doWhileStmt : DO Slist WHILE expr ENDWHILE",
"breakStmt : BREAK",
"continueStmt : CONTINUE",
"breakPointStmt : BREAKPOINT",
"GDeclBlock : DECL GDeclList ENDDECL",
"GDeclBlock : DECL ENDDECL",
"GDeclList : GDeclList GDecl",
"GDeclList : GDecl",
"GDecl : GType GIDList ';'",
"GDecl : GType TupleDecl GIDList ';'",
"GType : INT",
"GType : STR",
"GType : ID",
"GType : TUPLE ID",
"GIDList : GIDList ',' GID",
"GIDList : GID",
"GID : ID",
"GID : ID '[' NUM ']'",
"GID : ID '(' ParamList ')'",
"GID : GPtrID",
"GID : GPtrID '(' ParamList ')'",
"GPtrID : MUL ID",
"TupleDecl : '(' TupleFieldDeclList ')'",
"TupleFieldDeclList : TupleFieldDeclList ',' TupleFieldDecl",
"TupleFieldDeclList : TupleFieldDecl",
"TupleFieldDecl : TupleFieldType TupleFieldName",
"TupleFieldType : INT",
"TupleFieldType : STR",
"TupleFieldName : ID",
"ParamList : ParamList ',' Param",
"ParamList : Param",
"ParamList :",
"Param : ParamType ID",
"ParamType : INT",
"ParamType : STR",
"ParamType : INT MUL",
"ParamType : STR MUL",
"ParamType : ID",
"ArgList : ArgList ',' Arg",
"ArgList : Arg",
"ArgList :",
"Arg : expr",
"FDefBlock : FDefBlock FDef",
"FDefBlock : FDef",
"FID : ID",
"FDef : FuncSign '{' LDeclBlock FBody '}'",
"FuncSign : FuncType FID '(' ParamList ')'",
"FuncType : INT",
"FuncType : STR",
"FuncType : INT MUL",
"FuncType : STR MUL",
"FuncType : ID",
"FBody : BEGIN_ Slist retStmt END ';'",
"LDeclBlock : DECL LDeclList ENDDECL",
"LDeclBlock :",
"LDeclBlock : DECL ENDDECL",
"LDeclList : LDeclList LDecl",
"LDeclList : LDecl",
"LDecl : LType LIDList ';'",
"LDecl : LType TupleDecl LIDList ';'",
"LType : INT",
"LType : STR",
"LType : ID",
"LType : TUPLE ID",
"LIDList : LIDList ',' LID",
"LIDList : LID",
"LID : ID",
"LID : ID '[' NUM ']'",
"LID : MUL ID",
"MainBlock : MainFunc '(' ')' '{' LDeclBlock MBody '}'",
"MainFunc : INT MAIN",
"MBody : BEGIN_ Slist retStmt END ';'",
"DynamicMemStmt : AllocStmt",
"DynamicMemStmt : FreeStmt",
"DynamicMemStmt : InitializeStmt",
"AllocStmt : DynaMemID ALLOC '(' ')'",
"FreeStmt : DynaMemID FREE '(' expr ')'",
"InitializeStmt : DynaMemID INITIALIZE '(' ')'",
"DynaMemID : ID '='",
"DynaMemID : ID '[' expr ']' '='",
"FieldFunction : SELF '.' ID '(' ArgList ')'",
"FieldFunction : Field '(' ArgList ')'",
"Field : Field '.' ID",
"Field : FieldID '.' ID",
"FieldID : ID",
"FieldID : ID '[' expr ']'",
"expr : expr PLUS expr",
"expr : expr MINUS expr",
"expr : expr MUL expr",
"expr : expr DIV expr",
"expr : expr MOD expr",
"expr : expr EQ expr",
"expr : expr NEQ expr",
"expr : expr LT expr",
"expr : expr LTE expr",
"expr : expr GT expr",
"expr : expr GTE expr",
"expr : expr AND expr",
"expr : expr OR expr",
"expr : NOT expr",
"expr : '(' expr ')'",
"expr : Field",
"expr : FieldFunction",
"expr : ID '(' ArgList ')'",
"expr : ID '[' expr ']'",
"expr : AMPERSAND ID",
"expr : MUL ID",
"expr : ID",
"expr : NUM",
"expr : STRING",
"expr : NULL_",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 884 "ast.y"

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at statement %d\n", s, statementCount);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yydebug = 0;
		filePtr = fopen("../Target_Files/round1.xsm", "w");
		writeXexeHeader(filePtr);
		TypeTableCreate();
		yyparse();
	}
	else{
		printf("\nEnter Filename\n");
		exit(1);
	}

	printf("\n✅ Successfully Compiled: Target code saved in target.xsm\n");
	
	char targetFile[50];
	sprintf(targetFile, "%s.xsm", argv[1]);

	return 0;
}
#line 735 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 72 "ast.y"
	{}
break;
case 2:
#line 73 "ast.y"
	{}
break;
case 3:
#line 74 "ast.y"
	{}
break;
case 4:
#line 75 "ast.y"
	{}
break;
case 5:
#line 76 "ast.y"
	{	
																		printf("\n⛔ No Code Provided\n");
																		exit(1);
																	}
break;
case 6:
#line 85 "ast.y"
	{ printTypeTable(); }
break;
case 8:
#line 89 "ast.y"
	{}
break;
case 9:
#line 90 "ast.y"
	{}
break;
case 10:
#line 94 "ast.y"
	{ 
													if (typeFieldCount > 8){
														printf("\nError: User defined type %s has more than 8 fields\n", yystack.l_mark[-3].TTNode->typeName);
														exit(1);
													}

													FLPrint(yystack.l_mark[-3].TTNode->typeName); 
													yystack.l_mark[-3].TTNode->typeCategory = TYPE_USER_DEFINED;
													yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-1].FLNode;
													yystack.l_mark[-3].TTNode->size = typeFieldCount;

													fieldListTail = NULL;
													fieldListHead = NULL;
													typeFieldCount = 0;
												}
break;
case 11:
#line 111 "ast.y"
	{ yyval.TTNode = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); }
break;
case 12:
#line 114 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
													fieldListTail->next = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[-1].FLNode;
												}
break;
case 13:
#line 120 "ast.y"
	{ 
													yystack.l_mark[0].FLNode->fieldIndex = 0;
													fieldListHead = yystack.l_mark[0].FLNode;
													fieldListTail = yystack.l_mark[0].FLNode;
													yyval.FLNode = yystack.l_mark[0].FLNode;
				 								}
break;
case 14:
#line 128 "ast.y"
	{ 
													yyval.FLNode = FLCreateNode(yystack.l_mark[-1].node->nodeName, yystack.l_mark[-2].TTNode); 
													++typeFieldCount;
												}
break;
case 15:
#line 134 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 16:
#line 135 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 17:
#line 136 "ast.y"
	{ yyval.TTNode = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 18:
#line 143 "ast.y"
	{ CTPrint(); }
break;
case 19:
#line 146 "ast.y"
	{}
break;
case 20:
#line 147 "ast.y"
	{}
break;
case 21:
#line 153 "ast.y"
	{ 
														FLPrint(yystack.l_mark[-4].CTNode->className);
														MFLPrint(yystack.l_mark[-4].CTNode->className);

														/* adding the class to the Type Table*/
														if (typeFieldCount > 8) {
															printf("\nError: Class %s has more than 8 fields\n", yystack.l_mark[-4].CTNode->className);
															exit(1);	
														}
														/* $$ = TTInstall($1->className, typeFieldCount, $1->memberField);*/
														/* $$->typeCategory = TYPE_CLASS;*/

														fieldListTail = NULL;
														fieldListHead = NULL;
														typeFieldCount = 0;

														memFuncListHead = NULL;
														memFuncListTail = NULL;
														currentClassTable = NULL;
					 								}
break;
case 22:
#line 178 "ast.y"
	{
														currentClassTable->memberField = yystack.l_mark[-2].FLNode;
														currentClassTable->virtualFunctionPtr = memFuncListHead;
														currentClassTable->fieldCount = fieldListTail->fieldIndex + 1;
														currentClassTable->methodCount = memFuncListTail->funcPosition;
													}
break;
case 23:
#line 186 "ast.y"
	{ 
														yyval.CTNode = CTInstall(yystack.l_mark[0].node->nodeName, NULL);
														currentClassTable = yyval.CTNode;
													}
break;
case 24:
#line 192 "ast.y"
	{}
break;
case 25:
#line 193 "ast.y"
	{}
break;
case 26:
#line 196 "ast.y"
	{ 
														MFLInstall(yystack.l_mark[-4].node->nodeName, yystack.l_mark[-5].TTNode, paramListHead);
														/*  printParamList(paramListHead); */
														flushParamList();
													}
break;
case 27:
#line 203 "ast.y"
	{}
break;
case 28:
#line 208 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[-1].node); }
break;
case 29:
#line 209 "ast.y"
	{}
break;
case 39:
#line 216 "ast.y"
	{ ++statementCount; }
break;
case 40:
#line 219 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, READ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 41:
#line 222 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WRITE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 42:
#line 225 "ast.y"
	{ 
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); 
												}
break;
case 43:
#line 229 "ast.y"
	{	 
													yystack.l_mark[-5].node = lookupID(yystack.l_mark[-5].node);	
													yystack.l_mark[-5].node->left = yystack.l_mark[-3].node;
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, NULL, yystack.l_mark[0].node);
												}
break;
case 44:
#line 234 "ast.y"
	{
													yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);	
													struct ASTNode* mulNode;
													if (yystack.l_mark[-2].node->typeTablePtr == typeTableINTPtr)
														mulNode = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[-2].node, NULL);

													if (yystack.l_mark[-2].node->typeTablePtr == typeTableSTRPtr)
														mulNode = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[-2].node, NULL);
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, mulNode, NULL, yystack.l_mark[0].node);
												}
break;
case 45:
#line 244 "ast.y"
	{
													yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node);
												}
break;
case 46:
#line 251 "ast.y"
	{}
break;
case 47:
#line 254 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, RETURN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-1].node, NULL, NULL); }
break;
case 48:
#line 259 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-5].node, yystack.l_mark[-3].node, yystack.l_mark[-1].node); }
break;
case 49:
#line 260 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, IF_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, yystack.l_mark[-1].node, NULL); }
break;
case 50:
#line 263 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 51:
#line 266 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, DO_WHILE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-1].node); }
break;
case 52:
#line 269 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAK_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 53:
#line 272 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, CONTINUE_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 54:
#line 275 "ast.y"
	{ yyval.node = TreeCreate(typeTableVOID, BREAKPOINT_NODE, NULL, INT_MAX, NULL, NULL, NULL, NULL); }
break;
case 55:
#line 280 "ast.y"
	{
												GSTPrint(); 
												printTypeTable();					
												initStackBP(filePtr);
												printGlobalParamList();
											}
break;
case 56:
#line 286 "ast.y"
	{}
break;
case 57:
#line 289 "ast.y"
	{}
break;
case 58:
#line 290 "ast.y"
	{}
break;
case 59:
#line 293 "ast.y"
	{}
break;
case 60:
#line 294 "ast.y"
	{ 
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												FLPrint(yystack.l_mark[-3].TTNode->typeName);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentGDeclType = NULL;
												currentCDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 61:
#line 309 "ast.y"
	{ currentGDeclType = TTLookUp("int"); }
break;
case 62:
#line 310 "ast.y"
	{ currentGDeclType = TTLookUp("str"); }
break;
case 63:
#line 311 "ast.y"
	{ 
												/* for user-defined types						*/
												currentGDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
												if(currentGDeclType == NULL) {

													/* for class types*/
													currentCDeclType = CTLookUp(yystack.l_mark[0].node->nodeName);

													if (currentCDeclType == NULL) {
														printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
														exit(1);
													}
												}
			 								}
break;
case 64:
#line 325 "ast.y"
	{ 
												if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
													printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
													exit(1);
												}					
												currentGDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
												yyval.TTNode = currentGDeclType;
											}
break;
case 65:
#line 335 "ast.y"
	{}
break;
case 66:
#line 336 "ast.y"
	{}
break;
case 67:
#line 339 "ast.y"
	{ 
												int varSize;

												if (currentGDeclType != NULL)
													varSize = (currentGDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentGDeclType->size);
												if (currentCDeclType != NULL)
													varSize = currentCDeclType->fieldCount;	

												GSTInstall(yystack.l_mark[0].node->nodeName, currentGDeclType, varSize, NULL); 
											}
break;
case 68:
#line 349 "ast.y"
	{
												if (yystack.l_mark[-1].node->intConstVal < 1) {
													printf("\nArray Declaration expects valid size\n");
													exit(1);
												}
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, yystack.l_mark[-1].node->intConstVal, NULL); 
											}
break;
case 69:
#line 356 "ast.y"
	{
												GSTInstall(yystack.l_mark[-3].node->nodeName, currentGDeclType, -1, getParamListHead());
												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 70:
#line 362 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1, NULL);	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("str*"), 1, NULL);	
											}
break;
case 71:
#line 369 "ast.y"
	{
												if (strcmp(currentGDeclType->typeName, "int") == 0)
													GSTInstall(yystack.l_mark[-3].node->nodeName, TTLookUp("int*"), -1, getParamListHead());	

												if (strcmp(currentGDeclType->typeName, "str") == 0)
													GSTInstall(yystack.l_mark[-3].node->nodeName, TTLookUp("str*"), -1, getParamListHead());

												flushParamList();
												paramCount = 0;
												currentParamType = TTLookUp("void");
											}
break;
case 72:
#line 382 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 73:
#line 387 "ast.y"
	{ 
																	yyval.FLNode = yystack.l_mark[-1].FLNode; 

																	if (currentGDeclType != NULL)
																		currentGDeclType->size = tupleFieldCount;
																	if (currentLDeclType != NULL)
																		currentLDeclType->size = tupleFieldCount;		
																}
break;
case 74:
#line 397 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = fieldListTail->fieldIndex + 1;
																	fieldListTail->next = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[-2].FLNode;
																}
break;
case 75:
#line 403 "ast.y"
	{
																	yystack.l_mark[0].FLNode->fieldIndex = 0;
																	fieldListHead = yystack.l_mark[0].FLNode;
																	fieldListTail = yystack.l_mark[0].FLNode;
																	yyval.FLNode = yystack.l_mark[0].FLNode;
																}
break;
case 76:
#line 411 "ast.y"
	{
																	yyval.FLNode = FLCreateNode(yystack.l_mark[0].node->nodeName, yystack.l_mark[-1].TTNode);
																	++tupleFieldCount;
																}
break;
case 77:
#line 417 "ast.y"
	{ yyval.TTNode = TTLookUp("int"); }
break;
case 78:
#line 418 "ast.y"
	{ yyval.TTNode = TTLookUp("str"); }
break;
case 79:
#line 421 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 80:
#line 429 "ast.y"
	{}
break;
case 81:
#line 430 "ast.y"
	{}
break;
case 82:
#line 431 "ast.y"
	{}
break;
case 83:
#line 434 "ast.y"
	{ 
											paramListInstall(currentParamType, yystack.l_mark[0].node->nodeName);
											++paramCount;	
										}
break;
case 84:
#line 440 "ast.y"
	{ currentParamType = TTLookUp("int"); }
break;
case 85:
#line 441 "ast.y"
	{ currentParamType = TTLookUp("str"); }
break;
case 86:
#line 442 "ast.y"
	{  }
break;
case 87:
#line 443 "ast.y"
	{  }
break;
case 88:
#line 444 "ast.y"
	{ currentParamType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 89:
#line 453 "ast.y"
	{ yyval.node = insertToArgList(yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 90:
#line 454 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 91:
#line 455 "ast.y"
	{}
break;
case 92:
#line 458 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 93:
#line 464 "ast.y"
	{}
break;
case 94:
#line 465 "ast.y"
	{}
break;
case 95:
#line 468 "ast.y"
	{ 
															/* Check for function in GST		*/
															if(GSTLookup(yystack.l_mark[0].node->nodeName) == NULL){

																if (currentClassTable == NULL) {
																	printf("\nFunction %s() not declared globally\n", yystack.l_mark[0].node->nodeName);
																	exit(1);
																}
															
																/* if not in GST, search in current Class Table*/
																if (MemberFuncLookUp(currentClassTable, yystack.l_mark[0].node->nodeName) == NULL) {
																	printf("\nFunction %s() not declared in class %s\n", yystack.l_mark[0].node->nodeName, currentClassTable->className);
																	exit(1);
																}

															}
															yyval.node = yystack.l_mark[0].node; 
															setCurrentFuncName(yystack.l_mark[0].node->nodeName);
														}
break;
case 96:
#line 490 "ast.y"
	{
															char* currentFuncName = getCurrentFuncName();

															/* // TODO: Pls check!!!*/
															/* // addFunctionLST(currentFuncName, LSTHead);	*/
															
															/* fprintf(filePtr, "F%d:\n", GSTLookup(currentFuncName)->fLabel);*/
															/* initFuncCalle(filePtr, paramCount);*/

															/* printASTTable($4, 0);*/
															/* codeGen($4, filePtr);*/

															LSTPrint();
															flushLST();
															paramCount = 0;
														}
break;
case 97:
#line 508 "ast.y"
	{
															verifyFunctionSignature(yystack.l_mark[-3].node->nodeName);
															/* LSTAddParams();*/
															flushParamList();
														}
break;
case 98:
#line 514 "ast.y"
	{ currentFDefType = TTLookUp("int"); }
break;
case 99:
#line 515 "ast.y"
	{ currentFDefType = TTLookUp("str"); }
break;
case 100:
#line 516 "ast.y"
	{ currentFDefType = TTLookUp("int*"); }
break;
case 101:
#line 517 "ast.y"
	{ currentFDefType = TTLookUp("str*"); }
break;
case 102:
#line 518 "ast.y"
	{ currentFDefType = TTLookUp(yystack.l_mark[0].node->nodeName); }
break;
case 103:
#line 521 "ast.y"
	{
															/* struct ASTNode* funcBodyStmt = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, $2, NULL, $3);*/
															/* $$ = funcBodyStmt;*/
														}
break;
case 105:
#line 531 "ast.y"
	{  
											/* printTupleList();*/
										}
break;
case 106:
#line 534 "ast.y"
	{}
break;
case 107:
#line 537 "ast.y"
	{}
break;
case 108:
#line 538 "ast.y"
	{}
break;
case 109:
#line 541 "ast.y"
	{}
break;
case 110:
#line 542 "ast.y"
	{
												yystack.l_mark[-3].TTNode->typeCategory = TYPE_TUPLE;				
												yystack.l_mark[-3].TTNode->fields = yystack.l_mark[-2].FLNode; 
												yystack.l_mark[-3].TTNode->size = tupleFieldCount;

												FLPrint(yystack.l_mark[-3].TTNode->typeName);

												fieldListTail = NULL;
												fieldListHead = NULL;
												currentLDeclType = NULL;
												tupleFieldCount = 0;
											}
break;
case 111:
#line 556 "ast.y"
	{ currentLDeclType = TTLookUp("int"); }
break;
case 112:
#line 557 "ast.y"
	{ currentLDeclType = TTLookUp("str"); }
break;
case 113:
#line 558 "ast.y"
	{ 
											currentLDeclType = TTLookUp(yystack.l_mark[0].node->nodeName);
											if(currentLDeclType == NULL) {
												printf("\nType %s undeclared before use\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}
										}
break;
case 114:
#line 565 "ast.y"
	{
											if (TTLookUp(yystack.l_mark[0].node->nodeName) != NULL){
												printf("\nType Error: Tuple %s decalred twice\n", yystack.l_mark[0].node->nodeName);
												exit(1);
											}					
											currentLDeclType = TTInstall(yystack.l_mark[0].node->nodeName, 0, NULL); 
											yyval.TTNode = currentLDeclType;
										}
break;
case 115:
#line 575 "ast.y"
	{}
break;
case 116:
#line 576 "ast.y"
	{}
break;
case 117:
#line 579 "ast.y"
	{ 
											int varSize = (currentLDeclType->typeCategory == TYPE_USER_DEFINED) ? (1) : (currentLDeclType->size);							
											LSTInstall(yystack.l_mark[0].node->nodeName, currentLDeclType, varSize); 
										}
break;
case 118:
#line 583 "ast.y"
	{
											if (yystack.l_mark[-1].node->intConstVal < 1) {
												printf("\nArray Declaration expects valid size\n");
												exit(1);
											}
											LSTInstall(yystack.l_mark[-3].node->nodeName, currentLDeclType, yystack.l_mark[-1].node->intConstVal); 
										}
break;
case 119:
#line 590 "ast.y"
	{
											if(strcmp(currentLDeclType->typeName, "int") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	

											if(strcmp(currentLDeclType->typeName, "str") == 0)
												LSTInstall(yystack.l_mark[0].node->nodeName, TTLookUp("int*"), 1);	
										}
break;
case 120:
#line 606 "ast.y"
	{
														char* currentFuncName = getCurrentFuncName();

														/* TODO: Check!!!*/
														/* addFunctionLST(currentFuncName, LSTHead);	*/

														fprintf(filePtr, "F0:\n");
														initFuncCalle(filePtr, paramCount);

														printASTTable(yystack.l_mark[-1].node, 0);
														codeGen(yystack.l_mark[-1].node, filePtr);
														LSTPrint();
														flushLST();
														paramCount = 0;
												
														/* printFLT();*/
													}
break;
case 121:
#line 625 "ast.y"
	{ setCurrentFuncName("int main"); }
break;
case 122:
#line 628 "ast.y"
	{
														struct ASTNode* statementList = TreeCreate(typeTableVOID, SLIST_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														yyval.node = statementList;
													}
break;
case 126:
#line 643 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 127:
#line 649 "ast.y"
	{
															yystack.l_mark[-4].node = lookupID(yystack.l_mark[-4].node);
															yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-4].node, NULL, yystack.l_mark[-3].node);
														}
break;
case 128:
#line 656 "ast.y"
	{
															yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
															yyval.node = TreeCreate(typeTableVOID, ASGN_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-3].node, NULL, yystack.l_mark[-2].node);
														}
break;
case 129:
#line 662 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 130:
#line 663 "ast.y"
	{
															yyval.node = yystack.l_mark[-4].node;
															yyval.node->left = yystack.l_mark[-2].node;	
														}
break;
case 131:
#line 673 "ast.y"
	{}
break;
case 132:
#line 674 "ast.y"
	{
														/* verify whether the user passed the right arguments for */
														/* a class member function*/
														struct ASTNode* classVariablePtr = yystack.l_mark[-3].node;
														struct ASTNode* classFunctionPtr = yystack.l_mark[-3].node->right;

														while (classFunctionPtr->right != NULL) {
															classVariablePtr = classVariablePtr->right;
															classFunctionPtr = classFunctionPtr->right;
														}

														verifyClassFuncArgs(classVariablePtr, yystack.l_mark[-1].node);
													}
break;
case 133:
#line 692 "ast.y"
	{
												struct ASTNode* traversalPtr = yystack.l_mark[-2].node;
												while (traversalPtr->right != NULL){
													traversalPtr = traversalPtr->right;
												}

												struct TypeTable* lastFieldType = traversalPtr->typeTablePtr;
												traversalPtr->nodeType = FIELD_NODE;

												if(lastFieldType == typeTableINTPtr || lastFieldType == typeTableSTRPtr){
													printf("\n. operator cannot be used for non User Defined variable\n");
													exit(1);
												}
												
												struct FieldList* fieldListEntry = FLLookUp(lastFieldType, NULL,yystack.l_mark[0].node->nodeName);

												/* if field is not present in the field list*/
												if(fieldListEntry == NULL){
													printf("\nUndeclared field \"%s\" used in variable %s\n", yystack.l_mark[0].node->nodeName, traversalPtr->nodeName);
													exit(1);
												}

												yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
												traversalPtr->right = yystack.l_mark[0].node;
												yyval.node = yystack.l_mark[-2].node;
												yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
											}
break;
case 134:
#line 719 "ast.y"
	{
												/* Checking if ID($1) exists in LST or GST*/
												yystack.l_mark[-2].node = lookupID(yystack.l_mark[-2].node);

												int isClassVariable = (yystack.l_mark[-2].node->classTablePtr == NULL) ? (0) : (1);

												/* for non-class variables*/
												if (yystack.l_mark[-2].node->typeTablePtr != NULL) {
													if (yystack.l_mark[-2].node->typeTablePtr->typeCategory == TYPE_USER_DEFINED)
														yystack.l_mark[-2].node->nodeType = FIELD_NODE;

													else if (yystack.l_mark[-2].node->typeTablePtr->typeCategory == TYPE_TUPLE)
														yystack.l_mark[-2].node->nodeType = TUPLE_NODE;
													
													else {
														printf("\n. operator can only be used for User-Defined and class variables\n");
														exit(1);
													}
												}

												/* if it is not a class variable*/
												if (yystack.l_mark[-2].node->classTablePtr == NULL) {
													printf("\n. operator can only be used for User-Defined and class variables\n");
													exit(1);
												}
												else {
													yystack.l_mark[-2].node->nodeType = FIELD_NODE;
												}

												/* for non-class variables*/
												if (!isClassVariable){
													struct FieldList* fieldListEntry = FLLookUp(yystack.l_mark[-2].node->typeTablePtr, NULL,yystack.l_mark[0].node->nodeName);

													/* if field is not present in the field list*/
													if(fieldListEntry == NULL){
														printf("\nUndeclared field \"%s\" used in variable %s\n", yystack.l_mark[0].node->nodeName, yystack.l_mark[-2].node->nodeName);
														exit(1);
													}

													yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
													yystack.l_mark[0].node->classTablePtr = NULL;
													yystack.l_mark[-2].node->right = yystack.l_mark[0].node;
													yyval.node = yystack.l_mark[-2].node;
													yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
													yyval.node->classTablePtr = NULL;
												}								

												/* for class variable*/
												if (isClassVariable) {

													/* check if the field belongs to the class*/
													struct FieldList* fieldListEntry = FLLookUp(NULL, yystack.l_mark[-2].node->classTablePtr, yystack.l_mark[0].node->nodeName);
													struct MemberFuncList* funcListEntry = MemberFuncLookUp(yystack.l_mark[-2].node->classTablePtr, yystack.l_mark[0].node->nodeName); 

													if (fieldListEntry != NULL){
														printf("\nIt is a class field member\n");

														yystack.l_mark[0].node->typeTablePtr = fieldListEntry->type;
														yystack.l_mark[0].node->classTablePtr = NULL;
														yystack.l_mark[-2].node->right = yystack.l_mark[0].node;
														yyval.node = yystack.l_mark[-2].node;
														yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
														yyval.node->classTablePtr = NULL;
													}
													else if (funcListEntry != NULL){
														printf("\nIt is a class function member\n");

														yystack.l_mark[0].node->typeTablePtr = funcListEntry->funcType;
														yystack.l_mark[0].node->classTablePtr = NULL;
														yystack.l_mark[-2].node->right = yystack.l_mark[0].node;
														yyval.node = yystack.l_mark[-2].node;
														yyval.node->typeTablePtr = yystack.l_mark[0].node->typeTablePtr;
														yyval.node->classTablePtr = NULL;
													}
													else {
														printf("\nClass Error: Unknown class member %s in %s.%s\n", yystack.l_mark[0].node->nodeName, yystack.l_mark[-2].node->nodeName, yystack.l_mark[0].node->nodeName);
														exit(1);
													}
												}
											}
break;
case 135:
#line 801 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 136:
#line 802 "ast.y"
	{
												yyval.node = yystack.l_mark[-3].node;
												yyval.node->left = yystack.l_mark[-1].node;
											}
break;
case 137:
#line 812 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, PLUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 138:
#line 813 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MINUS_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 139:
#line 814 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 140:
#line 815 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, DIV_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 141:
#line 816 "ast.y"
	{ yyval.node =  TreeCreate(typeTableINT, MOD_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 142:
#line 817 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, EQ_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 143:
#line 818 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 144:
#line 819 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 145:
#line 820 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, LE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 146:
#line 821 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 147:
#line 822 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, GE_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 148:
#line 823 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, AND_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 149:
#line 824 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, OR_NODE, NULL, INT_MAX, NULL, yystack.l_mark[-2].node, NULL, yystack.l_mark[0].node); }
break;
case 150:
#line 825 "ast.y"
	{ yyval.node =  TreeCreate(typeTableBOOL, NOT_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL); }
break;
case 151:
#line 826 "ast.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 152:
#line 827 "ast.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 153:
#line 828 "ast.y"
	{  }
break;
case 154:
#line 829 "ast.y"
	{ 
										/* check if ID is a type constructor*/
										struct TypeTable* idTTEntry = TTLookUp(yystack.l_mark[-3].node->nodeName);

										/* if its a Tuple Constructor		*/
										if (idTTEntry != NULL && idTTEntry->typeCategory == TYPE_TUPLE){
											verifyTupleFields(idTTEntry, yystack.l_mark[-1].node);
											yyval.node = TreeCreate(idTTEntry, TUPLE_CONSTRUCTOR_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL);
											yyval.node->argListHead = yystack.l_mark[-1].node;
										}

										/* if its a function*/
										if(idTTEntry == NULL){
											yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);	
											verifyFunctionArguments(yystack.l_mark[-3].node->nodeName, yystack.l_mark[-1].node);	
											yyval.node = TreeCreate(getFunctionType(yystack.l_mark[-3].node->nodeName), FUNC_NODE, yystack.l_mark[-3].node->nodeName, INT_MAX, NULL, NULL, NULL, NULL); 
											yyval.node->argListHead = yystack.l_mark[-1].node;
											yyval.node->GSTEntry = yystack.l_mark[-3].node->GSTEntry;
										}
									}
break;
case 155:
#line 849 "ast.y"
	{	
										yystack.l_mark[-3].node = lookupID(yystack.l_mark[-3].node);
										if (yystack.l_mark[-1].node->typeTablePtr != typeTableINT){
											printf("\nArray Indexing expects INT Data Type\n");
											exit(1);
										}
										yystack.l_mark[-3].node->left = yystack.l_mark[-1].node;	
										yyval.node = yystack.l_mark[-3].node;
									}
break;
case 156:
#line 858 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINT || yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINTPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTR || yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTRPtr, AMP_NODE, NULL, INT_MAX, NULL, yystack.l_mark[0].node, NULL, NULL);	
									}
break;
case 157:
#line 866 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										if (yystack.l_mark[0].node->typeTablePtr == typeTableINTPtr)
											yyval.node = TreeCreate(typeTableINT, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);

										if (yystack.l_mark[0].node->typeTablePtr == typeTableSTRPtr)
											yyval.node = TreeCreate(typeTableSTR, MUL_NODE, NULL, INT_MAX, NULL, NULL, yystack.l_mark[0].node, NULL);	
									}
break;
case 158:
#line 874 "ast.y"
	{
										yystack.l_mark[0].node = lookupID(yystack.l_mark[0].node);
										yyval.node = yystack.l_mark[0].node;
									}
break;
case 159:
#line 878 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 160:
#line 879 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
case 161:
#line 880 "ast.y"
	{yyval.node = yystack.l_mark[0].node;}
break;
#line 1977 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}