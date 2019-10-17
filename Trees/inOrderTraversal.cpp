#include<iostream>
using namespace std;

struct tree
{
	int data;
	struct tree *left,*right;
};

void inOrderPrint(struct tree *head)
{
	if(head!=NULL)
	{
		inOrderPrint(head->left);
		cout<<head->data<<" ";
		inOrderPrint(head->right);
	}
}

struct tree *newNode(int data)
{
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct tree *insert(struct tree *head,int data)
{
	if(head == NULL)
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
	struct tree *head = NULL;
	head = insert(head,4);
	insert(head,2);
	insert(head,5);
	insert(head,3);
	insert(head,1);
	inOrderPrint(head);
}