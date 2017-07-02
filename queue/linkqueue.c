#include <stdio.h>
#include <stdlib.h>


typedef int datatype;
typedef struct node {
	datatype data;
	struct node *next;
}NODE,QUEUE;

NODE *queue[2];
#define front 0
#define rear 1
#if 0
enum {
front=0,
rear=1,
};
#endif

int empty(NODE *Q[])
{
	return Q[0] == Q[1];
}

datatype dequeue(QUEUE **queue)
{
	NODE *tmp;
	datatype a;
	if (!empty(queue)) {
		if (queue[front]->next == queue[rear]) {
			a=queue[rear]->data;
			free(queue[rear]);
			queue[rear]=queue[front];
		}else {
			tmp = (queue[front])->next;
			queue[front]->next = tmp->next;
			a = tmp->data;
			free(tmp);
		}
		return a;
	}
}
int enqueue(NODE** queue, datatype x)
{
	queue[rear]->next=(NODE*)malloc(sizeof(NODE));
	queue[rear] = queue[rear]->next;
	queue[rear]->data = x;
	queue[rear]->next = NULL;
}

int
main(int argc, char **argv)
{
	int a;
	queue[front]=queue[rear]=(NODE *)malloc(sizeof(NODE));
	queue[front]->next=NULL;
	queue[front]->data=-1;
	while(1) {
		scanf("%d",&a);
		if (a==-1) {
			break;
		}
		enqueue(queue,a);
	}

	while(!empty(queue)) {
		a = dequeue(queue);
		printf("%d\n",a);
	}
	return 0;
}
