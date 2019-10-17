#include<iostream>
#include<list>
using namespace std;

int size = 10;
list<int> *table = new list<int>[size];

int hashFunction(int data)
{
	return data%size;
}

void insert(int data)
{
	int index = hashFunction(data);
	table[index].push_back(data);
}

void deleteData(int data)
{
	int index = hashFunction(data);
	
	list<int> :: iterator it;
	for(it=table[index].begin();it!=table[index].end();it++)
	{
		if(*it == data)
			break;
	}
	table[index].erase(it);
}

void display()
{
	for(int i=0;i<size;i++)
	{
		cout<<i;
		for(int x : table[i])
			cout<<"-->"<<x;
		cout<<"\n";
	}
}

int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,21,12,22,15,25};
	for(int i=0;i<16;i++)
		insert(a[i]);
	display();
	cout<<"After Deletion\n";
	deleteData(5);
	display();
	return 0;
}