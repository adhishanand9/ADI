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

struct tree *calAncestor(struct tree *head,int n1,int n2)
{
	if(head == NULL)
		return NULL;

	if(head->data == n1 || head->data == n2)
		return head;

	struct tree *lRoot = calAncestor(head->left,n1,n2);
	struct tree *rRoot = calAncestor(head->right,n1,n2);

	if(lRoot && rRoot)
		return head;

	return (lRoot != NULL)? lRoot : rRoot;
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
	cout<<"Normal Tree Print\n";
	printTree(head);
	cout<<"\n Lowest Common Ancestor : "<<calAncestor(head,18,22)->data;
}