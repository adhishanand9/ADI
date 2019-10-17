#include<iostream>
#include<algorithm>
using namespace std;

string findPrefix(string arr[],int n)
{
	sort(arr,arr+n);
	
	int minLen = min(arr[0].size(),arr[n-1].size());

	string f = arr[0];
	string l = arr[n-1];

	int i=0;
	while(i<minLen && f[i] == l[i])
		i++;

	string pre = f.substr(0,i);
	return pre;
}

int main()
{
	string arr[] = {"geeks", "geek", "geezer", "geeksgeeksforgeekzs"};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<findPrefix(arr,n)<<"\n";
}