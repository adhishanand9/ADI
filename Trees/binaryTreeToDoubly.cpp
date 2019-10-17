#include<iostream>
#include <cstdlib>
using namespace std;

struct tree
{
    int data;
    tree *left;
    tree *right;
};

struct tree *newNode(int item) 
{ 
    struct tree *temp =  (struct tree *)malloc(sizeof(struct tree)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

struct tree* insert(struct tree* node, int data) 
{ 
    if (node == NULL) 
		return newNode(data); 
  
    if (data < node->data) 
        node->left  = insert(node->left, data); 
    else if (data > node->data) 
        node->right = insert(node->right, data);    
  
    return node; 
} 

void treetodoubly(tree *root, tree **head)
{
    if (root == NULL)
		return;
    static tree* prev = NULL;
    treetodoubly(root->left, head);
    if (prev == NULL)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    treetodoubly(root->right, head);
}

void printdoubly(struct tree *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->right;
        
    }
}

int main()
{
    tree *root=NULL;
    int n,i=0,data=0;
    cin>>n;
    while(n > i)
    {
    	cin>>data;
    	if(root==NULL)
    	root=insert(root,data);
    	else
    	insert(root,data);
    	i++;
	}
    
    struct tree *head=NULL;
    treetodoubly(root,&head);
    printdoubly(head);
    return 0;
}
