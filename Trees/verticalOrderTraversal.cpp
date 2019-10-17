#include <iostream> 
#include <vector> 
#include <map> 
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

void getVerticalOrder(struct tree *head,int height,map< int,vector<int> > &m)
{
	if(head == NULL)
		return;

	m[height].push_back(head->data);

	getVerticalOrder(head->left,height-1,m);

	getVerticalOrder(head->right,height+1,m);
}

void printVerticalOrder(struct tree *head)
{
	map < int,vector<int> > m;
	int height = 0;
	getVerticalOrder(head,height,m);

	map< int,vector<int> > :: iterator it;
	for(it = m.begin();it != m.end();it++)
	{
		for(int i=0;i<it->second.size();i++)
			cout<<it->second[i]<<" ";
		cout<<"\n";
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
	struct tree *head = NULL;
	head = insert(head,10);
	insert(head,7);
	insert(head,12);
	insert(head,5);
	insert(head,8);
	insert(head,11);
	insert(head,15);
	cout<<"Normal Tree Print : \n";
	printTree(head);
	cout<<"Vertical Level Order Tree Print : \n";
	printVerticalOrder(head);
}