#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "../Frontend/ast.h"
#include "../Data_Structures/loopStack.h"
#include "../Functions/reg.h"
#include "../Functions/xsm_syscalls.h"
#include "../Functions/label.h"

int codeGen(struct ASTNode *root, FILE *filePtr)
{

	// for NULL node
	if (root == NULL)
		return 1;

	// if its a NUM or VARIABLE (array variable as well)
	if (root->nodeType == CONST_INT_NODE || root->nodeType == CONST_STR_NODE || root->nodeType == ID_NODE)
		return 1;

	// for a IF Node
	if (root->nodeType == IF_NODE)
	{

		int labelIfEnd = getLabel();
		int labelElseEnd = 0;

		codeGenWhile(filePtr, root->left, labelIfEnd, 1);
		codeGen(root->middle, filePtr);

		if (root->right != NULL)
		{

			labelElseEnd = getLabel();
			fprintf(filePtr, "JMP L%d\n", labelElseEnd);
		}

		fprintf(filePtr, "L%d:\n", labelIfEnd);

		if (root->right != NULL)
		{
			codeGen(root->right, filePtr);
			fprintf(filePtr, "L%d:\n", labelElseEnd);
		}
		return 1;
	}

	// for a WHILE Node
	if (root->nodeType == WHILE_NODE)
	{

		int labelStart = getLabel();
		int labelEnd = getLabel();

		struct loopStackNode *labelStartNode = createLSNode(labelStart);
		struct loopStackNode *labelEndNode = createLSNode(labelEnd);

		pushLSNode(labelStartNode, labelEndNode);

		fprintf(filePtr, "L%d:\n", labelStart);
		codeGenWhile(filePtr, root->left, labelEnd, 1);
		codeGen(root->right, filePtr);
		fprintf(filePtr, "JMP L%d\n", labelStart);
		fprintf(filePtr, "L%d:\n", labelEnd);

		popLSNode();

		return 1;
	}

	// for a DO WHILE Node
	if (root->nodeType == DO_WHILE_NODE)
	{

		int labelStart = getLabel();
		int labelEnd = getLabel();

		struct loopStackNode *labelStartNode = createLSNode(labelStart);
		struct loopStackNode *labelEndNode = createLSNode(labelEnd);

		pushLSNode(labelStartNode, labelEndNode);

		fprintf(filePtr, "L%d:\n", labelStart);
		codeGen(root->left, filePtr);
		codeGenWhile(filePtr, root->right, labelStart, 2);
		fprintf(filePtr, "L%d:\n", labelEnd);

		popLSNode();

		return 1;
	}

	// for a BREAK Node
	if (root->nodeType == BREAK_NODE)
	{

		if (LSisEmpty() == 0)
			fprintf(filePtr, "JMP L%d\n", getEndLabel());

		return 1;
	}

	// for a CONTINUE Node
	if (root->nodeType == CONTINUE_NODE)
	{

		if (LSisEmpty() == 0)
			fprintf(filePtr, "JMP L%d\n", getStartLabel());

		return 1;
	}

	// for a BREAKPOINT Node
	if (root->nodeType == BREAKPOINT_NODE)
	{

		fprintf(filePtr, "BRKP\n");
		return 1;
	}

	codeGen(root->left, filePtr);
	codeGen(root->right, filePtr);

	// for an "=" OPERATOR Node
	if (root->nodeType == ASGN_NODE)
	{

		int resultRegNo = evalExprTree(filePtr, root->right);
		fprintf(filePtr, "MOV [R%d], R%d\n", getVariableAddress(filePtr, root->left), resultRegNo);
		freeReg();
		freeReg();
	}

	// for a READ Node
	if (root->nodeType == READ_NODE)
	{

		int varAddrReg = getVariableAddress(filePtr, root->left);
		INT_6(filePtr, -1, varAddrReg);
		freeReg();
	}

	// for a WRITE Node
	if (root->nodeType == WRITE_NODE)
	{

		int resultRegNo = evalExprTree(filePtr, root->left);
		INT_7(filePtr, -2, resultRegNo);
		freeReg();
	}

	return 1;
}

int initVariables(FILE *filePtr)
{

	int reg1 = getReg();

	fprintf(filePtr, "MOV R%d, 0\n", reg1);

	for (int i = 0; i < 26; ++i)
		fprintf(filePtr, "PUSH R%d\n", reg1);

	freeReg();
	return 1;
}

int codeGenWhile(FILE *filePtr, struct ASTNode *root, int label, int option)
{

	struct ASTNode *LHS;
	struct ASTNode *RHS;
	int reg1, reg2;

	LHS = root->left;
	RHS = root->right;

	reg1 = evalExprTree(filePtr, LHS);
	reg2 = evalExprTree(filePtr, RHS);

	if (root->nodeType == EQ_NODE)
		fprintf(filePtr, "EQ R%d, R%d\n", reg1, reg2);

	if (root->nodeType == NE_NODE)
		fprintf(filePtr, "NE R%d, R%d\n", reg1, reg2);

	if (root->nodeType == LT_NODE)
		fprintf(filePtr, "LT R%d, R%d\n", reg1, reg2);

	if (root->nodeType == LE_NODE)
		fprintf(filePtr, "LE R%d, R%d\n", reg1, reg2);

	if (root->nodeType == GT_NODE)
		fprintf(filePtr, "GT R%d, R%d\n", reg1, reg2);

	if (root->nodeType == GE_NODE)
		fprintf(filePtr, "GE R%d, R%d\n", reg1, reg2);

	if (option == 1)
		fprintf(filePtr, "JZ R%d, L%d\n", reg1, label);

	if (option == 2)
		fprintf(filePtr, "JNZ R%d, L%d\n", reg1, label);

	freeReg();
	freeReg();

	return 1;
}
