#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int f=count(v.begin(),v.end(),a[i]);
		v.push_back(a[i]);
		if(i==n-1)cout<<f+1<<endl;
		else cout<<f+1<<" ";
	}
	return 0;
}
