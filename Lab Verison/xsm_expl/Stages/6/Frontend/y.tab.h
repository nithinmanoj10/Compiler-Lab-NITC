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
#define EQ 296
#define NEQ 297
#define LT 298
#define LTE 299
#define GT 300
#define GTE 301
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
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
