#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *PtrToNode;
typedef PtrToNode Tree;

typedef int ElementType;

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
};

Tree Insert(Tree T, ElementType X)
{
	if (NULL==T) {
		T=(Tree)malloc(sizeof(struct TreeNode));
		if (NULL==T) {//out of memory
			perror("malloc");
			exit(1);
		}
		T->Element = X;
		T->Left=T->Right=NULL;
	}else {//Non-empty Tree
		if (X < T->Element) {
			T->Left=Insert(T->Left, X);
		}
		if (X > T->Element) {
			T->Right=Insert(T->Right, X);
		}
	}

	return T;
}
void preorder(Tree Y)
{
	if(NULL==Y) return;
	printf("%d\n",Y->Element);
	preorder(Y->Left);
	preorder(Y->Right);
}
void inorder(Tree Y)
{
	if(NULL==Y) return;
	inorder(Y->Left);
	printf("%d\n",Y->Element);
	inorder(Y->Right);
}
void postorder(Tree Y)
{
	if(NULL==Y) return;
	postorder(Y->Left);
	postorder(Y->Right);
	printf("%d\n",Y->Element);
}

int
main( int argc, char *argv[] )
{
    	Tree T=NULL;
	ElementType data=-1;
	while(1) {
		scanf("%d",&data);
		if (-1 == data) {
			break;
		}
		T=Insert(T, data);
	}
	preorder(T);
	printf("================\n");
	inorder(T);
	printf("================\n");
	postorder(T);
	return 0;
}
