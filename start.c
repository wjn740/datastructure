#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int data[100];
	int last;
}LINK;

typedef struct {
	char a[404];
}abc;

LINK *L;

int
main(int argc, char **argv)
{

	L=(LINK*)malloc(sizeof(abc));
	L->last = -1;
	printf("%p\n",L);
	printf("%d\n",L->last);
	return 0;
}
