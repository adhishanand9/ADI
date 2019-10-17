#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void nthNode(struct node *head,int n)
{
	struct node *temp = head;
	int count = 1;
	while(temp!=NULL)
	{
		if(count == n)
		{
			printf("%d\n", temp->data);
			break;
		}
		count++;
		temp = temp->next;
	}
}

int main()
{
	for(int i=11;i<16;i++)
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
	nthNode(head,3);
}