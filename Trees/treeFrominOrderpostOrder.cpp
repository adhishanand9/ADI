#include<iostream>
using namespace std; 

struct tree
{
	int data;
	struct tree *left,*right;
};

int searchIndex(char in[],int s,int e,char value);

void printTree(struct tree *head)
{
	if(head!=NULL)
	{
		cout<<head->data<<" ";
		printTree(head->left);
		printTree(head->right);
	}
}

struct tree *newNode(int data)
{
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct tree *buildTree(char in[],char post[],int s,int e)
{
	static int postIndex = e;

	if(s>e)
		return NULL;

	struct tree *temp = newNode(post[postIndex--]);

	if(s == e)
		return temp;

	int index = searchIndex(in,s,e,temp->data);

	temp->right = buildTree(in,post,index+1,e);	
	temp->left = buildTree(in,post,s,index-1);

	return temp;
}

int searchIndex(char in[],int s,int e,char value)
{
	int i;
	for(int i=s;i<=e;i++)
	{
		if(in[i] == value)
			return i;
	}
	return -1;
}

int main()  
{  
    char in[] = {4,8,2,5,1,6,3,7};  
    char post[] = {8,4,5,2,6,7,3,1};  
    int len = sizeof(in) / sizeof(in[0]);  
    struct tree *head = buildTree(in, post, 0, len - 1);  
  
    cout << "Pre traversal of tree is \n";  
    printTree(head);  
}  