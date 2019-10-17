#include<stdio.h>
#include<stdlib.h>

struct tree
{
	struct tree *left,*right;
	int data;
};

void printTree(struct tree *root)
{
	if(root!=NULL)
	{
		printTree(root->left);
		printf("%d\n", root->data);
		printTree(root->right);
	}
}

struct tree *newNode(int item)
{
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

struct tree *insert(struct tree *head,int data)
{
	if(head==NULL)
	{
		return newNode(data);
	}
	if(data < head->data)
		head->left = insert(head->left,data);
	else if(data > head->data)
		head->right = insert(head->right,data);
	return head;
} 

int main()
{
	struct tree *head=NULL;
	head = insert(head,10);
	insert(head,15);
	insert(head,2);
	insert(head,5);
	insert(head,1);
	printTree(head);
}

/* output - 1 2 5 15 */