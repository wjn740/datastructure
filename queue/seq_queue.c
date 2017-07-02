#include <stdio.h>

typedef int datatype;
#define MAXSIZE 8
typedef struct {
	datatype data[MAXSIZE];
	int front;
	int rear;
}sequeue;

sequeue Q;

int full(sequeue *q)
{
	return (q->rear+1)%MAXSIZE == q->front;
}

int enqueue(sequeue *queue, datatype x)
{
	if (!full(queue)) {
		queue->rear=(queue->rear+1)%MAXSIZE;
		queue->data[queue->rear] = x;
	}else {
		printf("Queue has been full, %d not add\n", x);
	}
	return 0;
}

int empty(sequeue *queue)
{
	return queue->front == queue->rear;	
}

int dequeue(sequeue *queue)
{
	if (!empty(queue)) {
		queue->front = (queue->front+1)%MAXSIZE;
		return queue->data[queue->front];
	}
}

int
main(int argc, char **argv)
{
	int a;
	Q.front=Q.rear=0;
	while(1) {
		scanf("%d", &a);
		if (a==-1) {
			break;
		}
		enqueue(&Q,a);
	}

	while(!empty(&Q)) {
		a=dequeue(&Q);
		printf("%d\n",a);
	}
	return 0;
}
