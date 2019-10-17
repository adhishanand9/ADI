#include<iostream>
#include<stack>
using namespace std;

struct node
{
	struct node *next;
	int data;
};

struct node *reverseUsingStack(struct node *head)
{
	stack<node *> s;
	struct node *ptr = head;
	while(ptr->next != NULL)
	{
		s.push(ptr);
		ptr=ptr->next;
	}
	head = ptr;
	while(!s.empty())
	{
		ptr->next = s.top();
		ptr = ptr->next;
		s.pop();
	}
	ptr->next = NULL;
	return head;
}

int main()
{
	struct node *head=NULL,*temp,*ptr;
	for(int i=1;i<6;i++)
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
	head = reverseUsingStack(head);

    temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}