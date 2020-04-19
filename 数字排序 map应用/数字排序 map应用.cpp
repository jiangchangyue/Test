#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b)
{
	return (a.second>b.second||(a.second==b.second&&a.first<b.first));
}

int main()
{
	map<int,int> m;
	map<int,int>::iterator mit;
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		m[temp]++;
	}
//	typedef pair<int,int> p;
//	vector<pair<int,int>> vc;
//	for(mit=m.begin();mit!=m.end();mit++)
//	{
//		vc.push_back(pair<int,int>(mit->first,mit->second));
//	}
	typedef pair<int,int> p;
	vector<p> vc;
	for(mit=m.begin();mit!=m.end();mit++)
	{
		vc.push_back(p(mit->first,mit->second));
	}
	sort(vc.begin(),vc.end(),cmp);
	for(auto it:vc)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
	return 0;
}
