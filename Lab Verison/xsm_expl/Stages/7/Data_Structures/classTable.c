#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "paramStruct.h"
#include "typeTable.h"
#include "classTable.h"

struct ClassTable *classTableHead = NULL;
struct ClassTable *classTableTail = NULL;
struct ClassTable *currentClassTable = NULL;
struct ClassTable *currentCDeclType = NULL;
struct ClassTable *currentFieldCType = NULL;

struct ClassTable *CTInstall(char *className, char *parentClassName)
{

    struct ClassTable *newCTNode = (struct ClassTable *)malloc(sizeof(struct ClassTable));
    newCTNode->className = (char *)malloc(sizeof(className));

    strcpy(newCTNode->className, className);
    newCTNode->memberField = NULL;
    newCTNode->virtualFunctionPtr = NULL;
    newCTNode->parentPtr = NULL; // Just for stage 7
    newCTNode->classIndex = (classTableTail == NULL) ? (0) : (classTableTail->classIndex + 1);
    newCTNode->fieldCount = 0;
    newCTNode->methodCount = 0;
    newCTNode->next = NULL;

    if (classTableHead == NULL && classTableTail == NULL)
    {
        classTableHead = newCTNode;
        classTableTail = newCTNode;
        return newCTNode;
    }

    classTableTail->next = newCTNode;
    classTableTail = newCTNode;

    return newCTNode;
}

struct ClassTable *CTLookUp(char *className)
{
    if (classTableHead == NULL && classTableTail == NULL)
        return NULL;

    struct ClassTable *traversalPtr = classTableHead;

    while (traversalPtr != NULL)
    {
        if (strcmp(traversalPtr->className, className) == 0)
            return traversalPtr;
        traversalPtr = traversalPtr->next;
    }

    return traversalPtr;
}

int verifyClassField(struct ClassTable *classTablePtr, char *fieldName)
{

    struct FieldList *classFieldList = classTablePtr->memberField;

    while (classFieldList != NULL)
    {
        if (strcmp(classFieldList->fieldName, fieldName) == 0)
            return 1;
        classFieldList = classFieldList->next;
    }

    return 0;
}

void CTPrint()
{
    struct ClassTable *traversalPtr = classTableHead;

    printf("\n\nš Class Table\n\n");

    printf("classIndex          className     memberField  virtualFunctionPtr       parentPtr  fieldCount  methodCount\n");
    printf("āāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāā\n\n");

    while (traversalPtr != NULL)
    {
        printf("%10d", traversalPtr->classIndex);
        printf("%19s", traversalPtr->className);
        printf("%16p", traversalPtr->memberField);

        if (traversalPtr->virtualFunctionPtr == NULL)
            printf("%20s", "-");
        else
            printf("%20p", traversalPtr->virtualFunctionPtr);

        if (traversalPtr->parentPtr == NULL)
            printf("%16s", "-");
        else
            printf("%16p", traversalPtr->parentPtr);

        printf("%12d", traversalPtr->fieldCount);
        printf("%13d\n", traversalPtr->methodCount);

        traversalPtr = traversalPtr->next;
    }

    printf("\nāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāāā\n\n");
}
