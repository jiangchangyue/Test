// string类_统计某一单词出现次数.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int IsAlp(char c)
{
	if(c>='a'&&c<='z'||c>='A'&&c<='Z')
		return 1;
	else return 0;
}
int main(int argc, char* argv[])
{
	string a="ab cc js jc jdm cc ckl dm cfvf vmv dvi dv";
	string b;
	cout<<"查找的单词：";
	cin>>b;
	string::iterator itr=a.begin();
	int pos1(0),pos2(0);
	int num(0);
	while((pos2=a.find(b,pos1))!=string::npos)
	{
		if((pos2==0||!IsAlp(itr[pos2]-1))&&(pos2+b.length()==a.length()||!IsAlp(itr[pos2+b.length()])))
		{
			num++;
			pos1=pos2+b.length();
		}
		else
			pos1++;
	}
	cout<<"fine word  "<<b<<"  "<<num<<"  ci"<<endl;
	//printf("Hello World!\n");
	return 0;
}

//#include<bits/stdc++.h>
/*#include<iostream>
using namespace std;
map<string,int> mp;
int main()
{
	freopen("text.txt","r",stdin);
	string a;
	while(cin>>a) if(a.length()>1)++mp[a];
	vector<pair<int,string>> v;
	for(auto x:mp) v.push_back(make_pair(x.second,x.first));
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=size()-10;--i)
		cout<<v[i].second<<":"<<v[i].first<<"次"<<endl;
	return 0;
}*/
