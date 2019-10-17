#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std; 

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

void printSpiralOrder(struct tree *head)
{
	stack<tree *> s1;  	//for right to left
	stack<tree *> s2;	//for left to right

	s1.push(head);

	while(s1.empty() == false || s2.empty() == false)
	{
		while(s1.empty() == false)
		{
			struct tree *temp = s1.top();
			s1.pop();
			cout<<temp->data<<" ";
			if(temp->right)
				s2.push(temp->right);
			if(temp->left)
				s2.push(temp->left);
		}
		while(s2.empty() == false)
		{
			struct tree *temp = s2.top();
			s2.pop();
			cout<<temp->data<<" ";
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		}
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
	else if(data > head->data)
		head->right = insert(head->right,data);

	return head;
}

int main()
{
	struct tree *head = NULL;
	head = insert(head,10);
	insert(head,7);
	insert(head,15);
	insert(head,1);
	insert(head,9);
	insert(head,12);
	insert(head,17);
	cout<<"Normal Tree Print : \n";
	printTree(head);
	cout<<"Spiral Level Order Tree Print : \n";
	printSpiralOrder(head);
}