// 动态输入矩形与圆信息并保存.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
fstream file,file1,file2;
class Rect
{
private:
	int X,Y;
	int L,W;
public:
	Rect(){}
	Rect(int x,int y,int l,int w)
	{
		X=x;
		Y=y;
		L=l;
		W=w;
	}
	void save()
	{
		file<<X<<Y<<L<<W<<endl;
	}
	void save1()
	{
		file1<<X<<Y<<L<<W<<endl;
	}
	~Rect(){}
};
class Circle
{
private:
	int X,Y;
	int R;
public:
	Circle(){}
	Circle(char x,char y,char r)
	{
		X=x;
		Y=y;
		R=r;
	}
	void save()
	{
		file<<X<<Y<<R<<endl;
	}
	void save1()
	{
		file1<<X<<Y<<R<<endl;
	}
	 ~Circle(){}
};
int main(int argc, char* argv[])
{
	char aa[10];
	cout<<"保存文件名称：";
	cin>>aa;
	file.open(aa,ios::out);
	if(!file)
	{
		cerr<<"file open or crect error!"<<endl;
		exit(1);
	}
	int nR,nC;
	cout<<"请输入矩形的个数："<<endl;
	cin>>nR;
	file<<nR<<endl;
	Rect *a[100];
	for(int i=0;i<nR;i++)
	{
		int x,y,l,w;
		cin>>x>>y>>l>>w;
		a[i]=new Rect(x,y,l,w);
	}
	cout<<"请输入圆的个数："<<endl;
	cin>>nC;
	file<<nC<<endl;
	Circle *b[100];
	for(int j=0;j<nC;j++)
	{
		int x,y,r;
		cin>>x>>y>>r;
		b[j]=new Circle(x,y,r);
	}
	for(i=0;i<nR;i++)
	{
		a[i]->save();
	}
	for(j=0;j<nC;j++)
	{
		b[j]->save();
	}
	file.close();
	file.open(aa,ios::in);
	if(!file)
	{
		cerr<<"file open or crect error!"<<endl;
		exit(1);
	}
	int t;
	file>>t;
	while(!file.eof())
	{
		cout<<t<<endl;
		file>>t;
	}
	file.close();
	file1.open(aa,ios::out|ios::app);
	if(!file1)
	{
		cerr<<"file open or crect error!"<<endl;
		exit(1);
	}
	cout<<"是否继续添加  1：是    0：否"<<endl;
	int w;
	cin>>w;
	if(w==0) exit(1);
	else 
	{
		cout<<"矩形个数："<<endl;
		cin>>nR;
		file1<<nR<<endl;
		Rect *a[100];
		for(i=0;i<nR;i++)
		{
			int x,y,l,w;
			cin>>x>>y>>l>>w;
			a[i]=new Rect(x,y,l,w);
		}
		cout<<"圆的个数："<<endl;
		cin>>nC;
		file1<<nC<<endl;
		Circle *b[100];
		for(j=0;j<nC;j++)
		{
			int x,y,r;
			cin>>x>>y>>r;
			b[j]=new Circle(x,y,r);
		}
		for(i=0;i<nR;i++)
		{
			a[i]->save1();
		}
		for(j=0;j<nC;j++)
		{
			b[j]->save1();
		}
		file1.close();
		file2.open(aa,ios::in);
		if(!file2)
		{
			cerr<<"file open or crect error!"<<endl;
			exit(1);
		}
		file2>>t;
		while(!file2.eof())
		{
			cout<<t<<endl;
			file2>>t;
		}
		file2.close();
	}
	//printf("Hello World!\n");
	return 0;
}