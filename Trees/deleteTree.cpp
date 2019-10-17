#include<iostream>
using namespace std; 

struct tree
{
	int data;
	struct tree *left = NULL,*right = NULL;
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

void deleteNodes(struct tree *head)
{
	if(head == NULL)
		return;

	deleteNodes(head->left);
	deleteNodes(head->right);

	cout<<"Deleted Node"<<head->data<<"\n";
	free(head);
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

	return head;
}

int main()
{
	struct tree *head = NULL;
	head = insert(head,50);
	insert(head,25);
	insert(head,100);
	insert(head,70);
	insert(head,30);
	insert(head,12);
	cout<<"Normal Tree Print\n";
	printTree(head);
	cout<<"\nDeleting Nodes\n";
	deleteNodes(head);
}