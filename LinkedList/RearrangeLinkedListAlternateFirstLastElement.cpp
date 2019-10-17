#include<iostream>
#include <deque> 
using namespace std;

struct node
{
	struct node *next;
	int data;
};

struct node *alternateNode(struct node *head)
{
	struct node *ptr = head;
	deque<int> d;
	while(ptr != NULL)
	{
		d.push_back(ptr->data);
		ptr = ptr->next;
	}
	int i=0;
	ptr = head;
	while(!d.empty())
	{
		if(i%2 == 0)
		{
			ptr->data = d.front();
			d.pop_front();
		}
		else
		{
			ptr->data = d.back();
			d.pop_back();
		}
		ptr = ptr->next;
		i++;
	}
	return head;
}

int main()
{
    struct node *head=NULL,*temp,*ptr;
	for(int i=1;i<9;i++)
	{
		ptr = (struct node*)malloc(sizeof(struct node));
		ptr->data = i;
		ptr->next = NULL;
		if(head == NULL)
		{
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
		}
	}

	head = alternateNode(head);

	temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}