#include <iostream>
#include <cstdlib>
using namespace std;

struct tree
{
    struct tree *left,*right;
    int data;
};

void printTree(tree *root)
{
    if(root!=NULL)
    {
        printTree(root->left);
        cout<<root->data<<"\n";
        printTree(root->right);
    }
}

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

int areSametree(struct tree* t1, struct tree* t2)
{
  if(t1==NULL && t2==NULL)
    return 1;
  else if(t1!=NULL && t2==NULL)
    	return 0;
    else if(t1==NULL && t2!=NULL)
        return 0;

  if(t1->data==t2->data && areSametree(t1->right,t2->right) && areSametree(t1->left,t2->left))
    return 1;
  else
    return 0;
}

int main()
{
    struct tree *n1 = NULL;
    n1 = insert(n1,10);
    insert(n1,15);
    insert(n1,2);
    insert(n1,1);
    insert(n1,5);

    struct tree *n2 = NULL;
    n2 = insert(n2,10);
    insert(n2,15);
    insert(n2,2);
    insert(n2,1);
    insert(n2,5);

    if(areSametree(n1,n2))
    	cout<<"Yes";
    else
    	cout<<"No";
	return 0;
}
