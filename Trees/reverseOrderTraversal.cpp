#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
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
		cout<<head->data<<" ";
		printTree(head->right);
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

void printReverseOrder(struct tree *head)
{
	stack<tree *> S;	
	queue<tree *> Q;
	Q.push(head);
	while(Q.empty() == false)
	{
		head = Q.front();
		Q.pop();
		S.push(head);
		if(head->right)
			Q.push(head->right);
		if(head->left)
			Q.push(head->left);
	}
	while(S.empty() == false)
	{
		head = S.top();
		cout<<head->data<<" ";
		S.pop();
	}
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
	cout<<"\n";
	cout<<"Reversal Order Tree\n";
	printReverseOrder(head);
	return 0;
}