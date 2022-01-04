%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "ast.h"

	int yylex(void);
	void yyerror(char const *s);
	int lineCount = 0;
	char* fileName;
%}

%union {
	struct ASTNode* node;
}

%type <node> start Slist Stmt inputStmt outputStmt assignStmt ifStmt VARIABLE expr NUM

%token BEGIN_ END READ WRITE VARIABLE NUM PLUS MINUS MUL DIV EQUAL COLON SEMICOLON 
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE

%left EQUAL
%left EQ NEQ
%left LT LTE GT GTE
%left PLUS MINUS
%left MUL DIV

%%

start 	: BEGIN_ COLON Slist END SEMICOLON	{

							printf("\n💥 Finished\n");
							printAST($3);						
	
				}

	| BEGIN_ COLON END SEMICOLON		{	
							printf("\n⛔ No Code Provided\n");
							exit(1);
						}
	;

Slist	: Slist Stmt SEMICOLON 	{$$ = createASTNode(0, 1, 6, "C", $1, NULL, $2);}
	| Stmt SEMICOLON	{}				
	;

Stmt	: inputStmt | outputStmt | assignStmt | ifStmt	{}
	;

inputStmt : READ expr	 		{$$ = createASTNode(0, 1, 4, "R", $2, NULL, NULL); ++lineCount;}
	  ;

outputStmt : WRITE expr 		{$$ = createASTNode(0, 1, 5, "W", $2, NULL, NULL); ++lineCount;}
	   ;

assignStmt : VARIABLE EQUAL expr	{$$ = createASTNode(0, 1, 3, "=", $1, NULL, $3); ++lineCount;}
	   ;

ifStmt	: IF expr THEN COLON Slist ELSE COLON Slist ENDIF
	{
		$$ = createASTNode(0, 2, 7, "I", $2, $5, $8);  
		++lineCount;	
	}
	| IF expr THEN COLON Slist ENDIF {$$ = createASTNode(0, 2, 7, "I", $2, $5, NULL); ++lineCount;}
	;

whileStmt : WHILE expr DO COLON Slist ENDWHILE {$$ = createASTNode(0, 2, 7, "W", $2, NULL, $5); ++lineCount;}

expr	: expr PLUS expr	{$$ = createASTNode(0, 1, 3, "+", $1, NULL, $3);}
	| expr MINUS expr 	{$$ = createASTNode(0, 1, 3, "-", $1, NULL, $3);}
	| expr MUL expr 	{$$ = createASTNode(0, 1, 3, "*", $1, NULL, $3);}
	| expr DIV expr		{$$ = createASTNode(0, 1, 3, "/", $1, NULL, $3);}
	| expr EQ expr		{$$ = createASTNode(0, 2, 3, "==", $1, NULL, $3);}
	| '(' expr ')'		{$$ = $2;}
	| VARIABLE		{$$ = $1;}
	| NUM			{$$ = $1;}
	;

%%

void yyerror(char const *s){
	printf("\n❌ ast.y | Error: %s, at line %d\n", s, lineCount+1);
	exit(1);
}

int main(int argc, char* argv[]){

	if (argc > 1){
		yyparse();
	}
	else{
		printf("\nEnter Filename\n");
		exit(1);
	}

	printf("\n✅ Successfully Compiled: Target code saved in %s.xsm\n", argv[1]);
	
	char targetFile[50];
	sprintf(targetFile, "%s.xsm", argv[1]);

	return 0;
}