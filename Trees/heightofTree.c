#include<stdio.h>
#include<stdlib.h>
struct tree
{
	struct tree *left,*right;
	int data;
};

void printTree(struct tree *head)
{
	if(head != NULL)
	{
		printTree(head->left);
		printf("%d ", head->data);
		printTree(head->right);
	}
}

int calHeight(struct tree *head)
{
	if(head == NULL)
		return 0;
	int l = calHeight(head->left);
	int r = calHeight(head->right);
	if(l>r)
		return ++l;
	else
		return ++r;
}

struct tree *insert(struct tree *head,int data)
{
	if(head == NULL)
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
	struct tree *head=NULL;
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
	printTree(head);
	printf("\n");
	printf("Height of the tree is : %d\n", calHeight(head));
}