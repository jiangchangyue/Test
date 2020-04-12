#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	vector<string> a;
	a.push_back("hello ");
	a.push_back("world");
	
	for(string word : a)
	{
		cout<<word;
	}	
} 
