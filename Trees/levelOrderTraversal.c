#include <stdio.h> 
#include <stdlib.h>

struct tree
{
	struct tree *left,*right;
	int data;
};

void enqueue(struct tree **, int *, struct tree *); 
struct tree *dequeue(struct tree **, int *); 


void printTree(struct tree *head)
{
	if(head != NULL)
	{
		printTree(head->left);
		printf("%d ",head->data);
		printTree(head->right);
	}
}

void printLevelOrder(struct tree *head)
{
	int front = 0,rear=0;
	struct tree **queue = (struct tree**)malloc(sizeof(struct tree*)*500);
	struct tree *temp = head;

	while(temp)
	{
		printf("%d ",temp->data);

		if(temp->left)
			enqueue(queue,&rear,temp->left);
		if(temp->right)
			enqueue(queue,&rear,temp->right);

		temp = dequeue(queue,&front);
	}
}

void enqueue(struct tree **queue,int *rear,struct tree *newNode)
{
	queue[*rear] = newNode; 
	(*rear)++;
}

struct tree *dequeue(struct tree **queue,int *front)
{
	(*front)++;
	return queue[*front-1];
}

struct tree *insert(struct tree *head,int data)
{
	if(head==NULL)
	{
		struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}

	if(data < head->data)
		head->left = insert(head->left,data);
	else if(data > head->data)
		head->right = insert(head->right,data);
}

int main()
{
	struct tree *head;
	head = insert(head,50);
	insert(head,25);
	insert(head,100);
	insert(head,70);
	insert(head,110);
	insert(head,120);
	insert(head,105);
	insert(head,30);
	insert(head,12);
	insert(head,20);
	insert(head,6);
	insert(head,22);
	insert(head,18);
	insert(head,3);
	insert(head,1);
	printf("Normal Tree Print\n");
	printTree(head);
	printf("\n");
	printf("Level Order Traversal is : \n");
	printLevelOrder(head);
}