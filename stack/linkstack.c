#include <stdio.h>
       #include <stdlib.h>


typedef int datatype;

typedef struct node
{
	datatype data;
	struct node *next;
}NODE,STACK;

NODE *push(STACK *top, datatype x)
{
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	p->data = x;
	p->next = NULL;
	//@1
	p->next = top;
	//@2
	top=p;
	return top;
}

int empty(STACK *top)
{
	return top==NULL;
}

NODE *pop(STACK *top, datatype *x)
{
	NODE *tmp;
	tmp = top;
	top = top->next;
	*x = tmp->data;
	free(tmp);
	return top;
}


int
main(int argc, char **argv)
{
	STACK *top=NULL;
	int a;
	while(1) {
		scanf("%d",&a);
		if (a==-1) {
			break;
		}
		top=push(top, a);
		if (top==NULL) {
			exit(1);
		}
	}

	while(!empty(top)) {
		top = pop(top, &a);
		printf("%d\n",a);
	}
	return 0;
}
