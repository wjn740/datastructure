#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int
IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack
CreateStack(void)
{
    Stack S;
    S = malloc(sizeof(struct Node));
    if(S==NULL) {
        printf("Out of space!!!\n");
        exit(1);
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}
void
MakeEmpty(Stack S)
{
    if(S==NULL) {
        printf("Must use CreateStack first\n");
        exit(1);
    }else {
        while(!IsEmpty(S))
            Pop(S);
    }
}
void
Push(ElementType X, Stack S)
{
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("Out of space!!!\n");
        exit(1);
    }else {
        TmpCell->Element = X;
        TmpCell->Next = S->Next; /*previous insert*/
        S->Next = TmpCell;
    }
}
ElementType
Top(Stack S)
{
    if (!IsEmpty(S)) {
        return S->Next->Element;
    }
    printf("Empty Stack\n");
    return 0;
}
void
Pop(Stack S)
{
    PtrToNode FirstCell;
    if(IsEmpty(S)) {
        printf("Empty stack\n");
        exit(1);
    }else{
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        free(FirstCell);
    }
}
