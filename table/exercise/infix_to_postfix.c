#include <stdio.h>
#include <ctype.h>
#include "stack.h"
#include <stdlib.h>

void handle(int, Stack);
void cleanstack(Stack);
int array[512];
int array2[512];

int
main( int argc, char *argv[] )
{
	int c;
    int i=0,j=0;
    int size;
    Stack S; 
    while((c=getchar()) != '\n') {
        array[i]=c;
        i++;
    }
    array[i]=c;
    i=0;

    S = CreateStack();

    j=0;
    while((c=(array[i++])) != '\n') {
        if (isalpha(c)) {
            putchar(c);
        }else {
            handle(c,S);
        }
    }
    cleanstack(S);
	return 0;
}
void cleanstack(Stack S)
{
    while(!IsEmpty(S)) {
        putchar(Top(S));
        Pop(S);
    }
}
void handle(int c, Stack S)
{
    int top;
    if (c=='(') 
        goto push;
    if (c==')') {/*handle ')'*/
        if(!IsEmpty(S)) {/*check stack*/
            while(Top(S) != '('){
                putchar(Top(S));
                Pop(S);
            }
            Pop(S);/*drop '(' in stack*/
        }else {/*error*/
            printf("lost '(' in stack\n");
            exit(1);
        }
    }
    
    if (!IsEmpty(S)) {
       top=Top(S); 
       if (precedence(top,c)) {
            putchar(Top(S));
            Pop(S);
       }
    }
push:
    Push(c,S);
    return;
}
int precedence(int top, int c)
{
    int result;
    if (c=='+' || c=='-') {
        return 1;
    }

    switch (top) {/*c=='*' or c=='/'*/
    case '*':
    case '/':
        return 1;
    case '+':
    case '-':
        return 0;
    }
    return 0;
}
