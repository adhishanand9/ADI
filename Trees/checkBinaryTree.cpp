#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

struct tree
{
	int data;
	struct tree *left,*right;
};

void printTree(struct tree *head)
{
	if(head != NULL)
	{
		printTree(head->left);
		cout<<head->data<<" ";
		printTree(head->right);
	}
}

int IsBst(struct tree *head,int min,int max)
{
	if(head == NULL)
		return 1;

	if(head->data < min || head->data > max)
		return 0;

	return IsBst(head->left,min,head->data-1) && IsBst(head->right,head->data+1,max);
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
	if(data > head->data)
		head->right = insert(head->right,data);

	return head;
}

int main()
{
	struct tree *head = NULL;
	head = insert(head,4);
	insert(head,5);
	insert(head,2);
	insert(head,1);
	insert(head,3);
	cout<<"Normal Tree Print\n";
	printTree(head);
	if(IsBst(head,INT_MIN,INT_MAX))
		cout<<"\nYes Bst Tree";
	else
		cout<<"No";
}