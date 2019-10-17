#include<stdio.h>  
#include<stdlib.h>  

struct node 
{
	int data;
	struct node *next;
};
struct node *head;

int main()
{
	
	for(int i=1;i<=5;i++)
	{
		struct node *ptr,*temp;
		ptr = (struct node*)malloc(sizeof(struct node));
   
		ptr->data = i;
		if(head == NULL)
		{
			ptr->next = NULL;
			head = ptr;
		}
		else
		{
			temp = head;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = NULL;
		}
	
	}

	struct node *t;
	t = head;
	while(t!=NULL)
	{
		printf("%d\n", t->data);
		t = t->next;
	}

}