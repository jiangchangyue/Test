#include<iostream>
#include<map>
using namespace std;
map<int,int> mp;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int g;
		cin>>g;
		mp[i]=g;
	}	
	for(int j=0;j<n;j++)
	{
		cout<<mp[j]<<endl;
	}
	return 0;
}
