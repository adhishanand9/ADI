#include<iostream>
#include<algorithm>
using namespace std;

int findAnagram(string s1,string s2)
{
	if(s1.length() != s2.length())
		return 0;

	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());

	for(int i=0;i<s1.length();i++)
		if(s1[i]!=s2[i])
			return 0;

	return 1;	
}

int main()
{
	string s1,s2;
	cout<<"Enter String 1 : ";
	cin>>s1;
	cout<<"Enter String 2 : ";
	cin>>s2;
	if(findAnagram(s1,s2))
		cout<<"Strings are Anagram of each other\n";
	else
		cout<<"Strings are not Anagram of each other\n";
}