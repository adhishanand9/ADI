#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

void mirror(struct Node* node)
{
	if (node == NULL)
		return;
	else
	{
		struct Node* temp;
		mirror(node->left);
		mirror(node->right);

		temp	 = node->left;
		node->left = node->right;
		node->right = temp;
	}
}
//USING QUEUE
/*
void mirror(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    // Do BFS. While doing BFS, keep swapping
    // left and right children
    while (!q.empty())
    {
        // pop top node from queue
        Node* curr = q.front();
        q.pop();

        // swap left child with right child
        swap(curr->left, curr->right);

        // push left and right children
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

*/
int areMirror(Node* a, Node* b)
{
    if (a==NULL && b==NULL)
        return true;

    if (a==NULL || b == NULL)
        return false;

    return  a->data == b->data &&
            areMirror(a->left, b->right) &&
            areMirror(a->right, b->left);
}

void inOrder(struct Node* node)
{
	if (node == NULL)
		return;

	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}
void deleteTree(node* node)
{
    if (node == NULL) return;

    deleteTree(node->left);
    deleteTree(node->right);

    cout << "\n Deleting node: " << node->data;
    free(node);
}
void printLevelOrder(Node *root)
{
    if (root == NULL)  return;

    queue<Node *> q;

    q.push(root);

    while (q.empty() == false)
    {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != NULL)
            q.push(node->left);

        if (node->right != NULL)
            q.push(node->right);
    }
} 

int main()
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Inorder traversal of the constructed"
		<< " tree is" << endl;
	inOrder(root);
	mirror(root);

	cout << "\nInorder traversal of the mirror tree"
		<< " is \n";
	inOrder(root);

	return 0;
}
