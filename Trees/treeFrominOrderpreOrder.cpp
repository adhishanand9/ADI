#include<iostream>
using namespace std; 

struct tree
{
	char data;
	struct tree *left,*right;
};

int searchIndex(char in[],int s,int e,char value);

void printTree(struct tree *head)
{
	if(head!=NULL)
	{
		printTree(head->left);
		cout<<head->data<<" ";
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

struct tree *buildTree(char in[],char pre[],int s,int e)
{
	static int preIndex = 0;

	if(s>e)
		return NULL;

	struct tree *temp = newNode(pre[preIndex++]);

	if(s == e)
		return temp;

	int index = searchIndex(in,s,e,temp->data);

	temp->left = buildTree(in,pre,s,index-1);
	temp->right = buildTree(in,pre,index+1,e);

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
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };  
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };  
    int len = sizeof(in) / sizeof(in[0]);  
    struct tree *head = buildTree(in, pre, 0, len - 1);  
  
    cout << "Inorder traversal of tree is \n";  
    printTree(head);  
}  