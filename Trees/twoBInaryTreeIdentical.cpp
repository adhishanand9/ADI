#include<iostream>
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

int isIdentical(struct tree *head1,struct tree *head2)
{
	if(head1 == NULL && head2 == NULL)
		return 1;
	else if(head1 != NULL && head2 == NULL)
		return 0; 
	else if(head1 == NULL && head2 != NULL)
		return 0; 
	else
	{
		if(head1->data == head2->data && isIdentical(head1->left,head2->left) && isIdentical(head1->right,head2->right))
			return 1;
		else
			return 0;
	}

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
	int n1,n2,no;
	struct tree *head1 = NULL,*head2 = NULL;
	cout<<"Enter size of Tree 1 - ";
	cin>>n1;
	cout<<"Enter size of Tree 2 - ";
	cin>>n2;
	cout<<"Enter Tree 1 elements : ";
	cin>>no;
	head1 = insert(head1,no);
	for(int i=0;i<n1-1;i++)
	{
		cin>>no;
		insert(head1,no);
	}
	cout<<"Enter Tree 2 elements : ";
	cin>>no;
	head2 = insert(head2,no);
	for(int i=0;i<n2-1;i++)
	{
		cin>>no;
		insert(head2,no);
	}
	cout<<"Tree 1 is : ";
	printTree(head1);
	cout<<"\nTree 2 is : ";
	printTree(head2);

	if(isIdentical(head1,head2))
		cout<<"\nYes both are same";
	else
		cout<<"\nNo";
}