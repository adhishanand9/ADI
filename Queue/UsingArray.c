#include<stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE];
int front = 0;
int size = 0;

int isEmpty() 
{ 
    if(front>size-1)
      return 1;
    else
      return 0;
}

void enqueue(int data)
{
	if(size == MAX_SIZE-1)
	{
		printf("StackOverflow\n");
		return;
	}
	A[size++] = data;
}

int dequeue()
{
	if(size == 0)
	{
		printf("No element to pop\n");
		return 0;
	}
	return A[front++];
}

int frontEle()
{
	if(isEmpty())
		return 0;
	return A[front];
}

int rear()
{
	if(isEmpty())
		return 0;
	return A[size-1];
}

int main()
{
	enqueue(1);
	enqueue(2);
	printf("Front Element is : %d\n",frontEle());
	dequeue();
	printf("Front Element is : %d\n",frontEle());
	enqueue(3);
	printf("Rear Element is : %d\n",rear());
}