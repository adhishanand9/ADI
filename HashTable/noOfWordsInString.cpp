#include<iostream>
using namespace std;

int countWords(char *str)
{
	int state = 0;
	int count = 0;
	while(*str)
	{
		if(*str == ' ' || *str == '\n' || *str == '\t')
			state = 0;
		else if(state == 0)
		{
			state = 1;
			count++;
		}
		str++;
	}
	return count;
}

int main()
{
	char s[] = "rajat rishabh ridhav  adhish  arihant";
	cout<<"Total words are : "<<countWords(s);
}