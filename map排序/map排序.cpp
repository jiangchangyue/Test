#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string.h>
using namespace std;

bool cmp(pair<char,int> a,pair<char,int> b)
{
	return a.second>b.second;
}

int main()
{
	map<char,int> m;
	map<char,int>::iterator mit;
	m['a']=5;
	m['f']=4;
	m['b']=3;
	m['g']=6;
	m['e']=7;
	m['q']=8;
	m['t']=2;
	m['j']=9;
	
	vector<pair<char,int>> v;
	for(mit=m.begin();mit!=m.end();mit++)
	{
		v.push_back(pair<char,int>(mit->first,mit->second));
	}
	sort(v.begin(),v.end(),cmp);
	for(auto x:v)
	{
		cout<<x.first<<" "<<x.second<<endl;
	}
	return 0;
}
