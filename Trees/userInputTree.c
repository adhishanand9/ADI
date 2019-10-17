#include<stdio.h>
#include<stdlib.h>

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

struct tree *insert(struct tree *head,int data)
{
	if(head == NULL)
	{
		struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
		temp->data = data;
		temp->right = temp->left = NULL;
		return temp;
	}

	if(data < head->data)
		head->left = insert(head->left,data);
	else if(data > head->data)
		head->right = insert(head->right,data);

}

int main()
{
	struct tree *head = NULL;
	printf("Enter Element to put in tree and -1 to exit\n");
	int no;
	printf("Enter Element : ");
	scanf("%d",&no);
	if(no != -1)
		head = insert(head,no);
	while(no != -1)
	{
		printf("Enter Element : ");
		scanf("%d",&no);
		if(no != -1)
			insert(head,no);
	}
	printTree(head);
}