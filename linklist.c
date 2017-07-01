#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}LINK,NODE;

LINK *L;//代表一个链表

void insert(NODE *node)
{
	if (L == NULL) {
		L=node;
	}else {
		node->next = L;
		L=node;
	}
}
void printlist(void)
{
	NODE *p = L;

	while(p) {
		printf("%d\n",p->data);
		p=p->next;
	}
}

NODE *find_previous(int x)
{
	NODE *p;
	p=L;
	while(p->next && p->next->data!=x) {
		p=p->next;
	}
	return p;
}
int islast(NODE *p)
{
	return p->next==NULL;	
}

void delete(int y)
{
	NODE *p;
	NODE *q;

	if (!L)
		return;

	if (L->data == y) {
		q=L;
		L=L->next;
	}else {
		p = find_previous(y);
		if (!islast(p)) {
			q=p->next;
			p->next=q->next;
		}
	}
	free(q);

	return;
}

int
main(int argc, char **argv)
{
	NODE *p;
	int x;
	while(1) {
		p=(NODE *)malloc(sizeof(NODE));
		scanf("%d",&p->data);
		if (p->data == -1) {
			break;
		}
		p->next = NULL;
		insert(p);
	}

	printlist();

	while(1) {
	printf("input delete element:");
	scanf("%d",&x);
	delete(x);

	printlist();

	}
	return 0;
}
