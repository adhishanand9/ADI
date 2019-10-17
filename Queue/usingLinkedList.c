#include<stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *front,*rear;
};

void enqueue(struct queue *q,int data)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	if(q->rear == NULL)
	{
		q->front = q->rear = newNode;
		return;
	}

	q->rear->next = newNode;
	q->rear = newNode;
}

int dequeue(struct queue *q)
{
	if(q->front == NULL)
		return 0;

	struct node *temp = q->front;
	q->front = q->front->next;

	if(q->front == NULL)
		q->rear = NULL;

	int d = temp->data;
	free(temp);
	return d;
}

int main()
{
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->front = q->rear = NULL;
	enqueue(q,1);
	enqueue(q,2);
	printf("Dequeue Element is : %d\n",dequeue(q));
	enqueue(q,3);
	printf("Dequeue Element is : %d\n",dequeue(q));
	enqueue(q,4);
	printf("Dequeue Element is : %d\n",dequeue(q));
}