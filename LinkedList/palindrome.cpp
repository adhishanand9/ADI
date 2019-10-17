#include<iostream>
#include<stack>
using namespace std;

struct node
{
	struct node *next;
	int data;
};

int checkPalindrome(struct node *head)
{
	struct node *temp = head;
	stack<int> s;
	while(temp!=NULL)
	{
		s.push(temp->data);
		temp=temp->next;
	}
	while(head!=NULL)
	{
		int i = s.top();
		if(head->data!=i)
			return 0;
		s.pop();
		head=head->next;
	}
	return 1;
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
	int n = checkPalindrome(head);

	if(n==1)
		cout<<"Yes";
	else
		cout<<"No";
}