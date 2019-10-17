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
		printf("%d ", head->data);
		printTree(head->right);
	}
}


int heightOfTree(struct tree *head)
{
	if(head == NULL)
		return 0;
	int l = heightOfTree(head->left);
	int r = heightOfTree(head->right);

	if(l > r)
		return ++l;
	else
		return ++r;
}

int maxNumber(int a,int b)
{
	return (a >= b)? a : b;
}

int checkDiameter(struct tree *head)
{
	if(head == NULL)
		return 0;
	
	int lheight = heightOfTree(head->left);
	int rheight = heightOfTree(head->right);

	int ldiameter = checkDiameter(head->left);
	int rdiameter = checkDiameter(head->right);

	return max(lheight+rheight+1,max(ldiameter,rdiameter));
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
	cout<<"\n"<<checkDiameter(head);
}