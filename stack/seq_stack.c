#include <stdio.h>

typedef int datatype;

#define MAXSIZE 64

typedef struct {
	datatype data[MAXSIZE];
	int top;
}SEQSTACK;

SEQSTACK stack;

int empty(void)
{
	return stack.top == -1;
}

int push(datatype a)
{
	if (stack.top==MAXSIZE-1)
		return -1;
	stack.top++;
	stack.data[stack.top]=a;
}

int pop(void)
{
	return !empty()?stack.data[stack.top--]:-1;
}
int
main(int argc, char **argv)
{
	int a;
	//clear stack
	stack.top=-1;

	while(1) {
		scanf("%d",&a);
		if (a==-1) {
			break;
		}
		a=push(a);
		if (a==-1) {
			break;
		}
	}

	while(!empty()) {
		a=pop();
		printf("%d\n",a);
	}
	return 0;
}
