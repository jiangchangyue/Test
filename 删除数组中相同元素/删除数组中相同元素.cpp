// 删除数组中相同元素.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include<iostream>
#include<ctime>
using namespace std;

int main(int argc, char* argv[])
{
	clock_t start,end;
	double time;
	int n;
	cin>>n;
	int *a;
	a=new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	start=clock();
	for(i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]==a[j])
			{
				a[j]=0;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i])
			cout<<a[i];
	}
	end=clock();
	time=double(end-start)/CLOCKS_PER_SEC;
	cout<<endl;
	cout<<time<<endl;
	cout<<endl;
	//printf("Hello World!\n");
	return 0;
}*/
/*#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

int main()
{
	clock_t start,end;
	double time;
	int n;
	cin>>n;
	int *a;
	a=new int [n];
	for(int i=0;i<n;i++)
	{
		//cin>>a[i];
		a[i]=rand()%100;
		cout<<a[i]<<"**";
	}
	start=clock();
	int b[1000]={0};
	for(i=0;i<n;i++)
	{
		if(b[a[i]]==0)
			b[a[i]]=a[i];
	}
	for(i=0;i<1000;i++)
	{
		if(b[i]!=0)
			cout<<b[i]<<" ";
	}
	end=clock();
	time=double(end-start)/CLOCKS_PER_SEC;
	cout<<endl<<time<<endl;
	return 0;
}*/
#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

void main()
{
	clock_t start,end;
	double time;
	int n;
	cout<<"输入数组长度:";
	cin>>n;
	int *a;
	int i,j;
	a=new int [n];
	cout<<endl<<"随机生成的数组为:";
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<" ";
	}
	cout<<endl<<endl<<"去除相同项后的数组:";
	start=clock();
	int k=1;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
			if(a[j]==a[i]) break;
		if(j>=k) 
		{
			a[k]=a[i];
			k++;
		}
	}
	for(i=0;i<k;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	end=clock();
	time=double(end-start)/CLOCKS_PER_SEC;
	cout<<endl<<"运行时间:"<<time<<endl;
}