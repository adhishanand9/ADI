#include<iostream>
using namespace std; 

struct tree
{
	int data;
	struct tree *left,*right;
};

void printTree(struct tree *root)
{
	if(root!=NULL)
	{
		printTree(root->left);
		cout<<head->data<<" ";
		printTree(root->right);
	}
}

struct tree *newNode(int data)
{
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct tree *treeFromArray(int arr[],struct tree *head,int i,int n)
{
	if(i<n)
	{
		struct tree *temp = newNode(arr[i]);
		head = temp;

		head->left = treeFromArray(arr,head->left,2 * i + 1,n);
		head->right = treeFromArray(arr,head->right,2 * i + 2,n);
	}
	return head;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,6,6,6};
	int n = sizeof(arr)/sizeof(arr[0]);	
	struct tree *head = treeFromArray(arr,head,0,n);
	printTree(head);
}