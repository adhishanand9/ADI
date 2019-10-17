#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void nthNodeFromLast(struct node *head,int n)
{
	struct node *temp = head;
	int len = 0;
	while(temp != NULL)
	{
		temp = temp->next;
		len++;
	}
	if(len<n)
		return;
	
	temp = head;

	for(int i=1;i<len-n;i++)
	{
		temp = temp->next;
	}

	temp->next = temp->next->next;

	//printf("%d\n", temp->data);

}

int main()
{
	for(int i=1;i<6;i++)
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
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = NULL;
		}
	}
	nthNodeFromLast(head,1);

	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}