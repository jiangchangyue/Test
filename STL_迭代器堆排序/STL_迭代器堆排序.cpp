// STL_������������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	const int size=10;
	int a[10]={10,3,8,11,20,7,19,5,16,1};
	vector<int>v(a,a+10);
	ostream_iterator<int>output(cout," ");
	cout<<"����ǰ��"<<endl;
	copy(v.begin(),v.end(),output);
	
	make_heap(v.begin(),v.end());
	cout<<endl<<"���Ѻ�"<<endl;
	copy(v.begin(),v.end(),output);

	sort_heap(v.begin(),v.end());
	cout<<endl<<"�����"<<endl;
	copy(v.begin(),v.end(),output);
	return 0;
}

