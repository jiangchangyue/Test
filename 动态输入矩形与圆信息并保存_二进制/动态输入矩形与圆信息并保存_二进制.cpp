// 动态输入矩形与圆信息并保存_二进制.cpp : Defines the entry point for the console application.
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
		file.write((char *)&X,sizeof(int));
		file.write((char *)&Y,sizeof(int));
		file.write((char *)&L,sizeof(int));
		file.write((char *)&W,sizeof(int));
	}
	void save1()
	{
		file1.write((char *)&X,sizeof(int));
		file1.write((char *)&Y,sizeof(int));
		file1.write((char *)&L,sizeof(int));
		file1.write((char *)&W,sizeof(int));
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
		file.write((char *)&X,sizeof(int));
		file.write((char *)&Y,sizeof(int));
		file.write((char *)&R,sizeof(int));
	}
	void save1()
	{
		file1.write((char *)&X,sizeof(int));
		file1.write((char *)&Y,sizeof(int));
		file1.write((char *)&R,sizeof(int));
	}
	 ~Circle(){}
};
int main(int argc, char* argv[])
{
	char aa[10];
	cout<<"保存文件名称：";
	cin>>aa;
	file.open(aa,ios::binary|ios::out);
	if(!file)
	{
		cerr<<"file open or crect error!"<<endl;
		exit(1);
	}
	int nR,nC;
	cout<<"请输入矩形的个数："<<endl;
	cin>>nR;
	file.write((char *)&nR,sizeof(int));
	Rect *a[100];
	for(int i=0;i<nR;i++)
	{
		int x,y,l,w;
		cin>>x>>y>>l>>w;
		a[i]=new Rect(x,y,l,w);
	}
	for(i=0;i<nR;i++)
	{
		a[i]->save();
	}
	cout<<"请输入圆的个数："<<endl;
	cin>>nC;
	file.write((char *)&nC,sizeof(int));
	Circle *b[100];
	for(int j=0;j<nC;j++)
	{
		int x,y,r;
		cin>>x>>y>>r;
		b[i]=new Circle(x,y,r);
	}
	for(j=0;j<nC;j++)
	{
		b[i]->save();
	}
	file.close();
	file.open(aa,ios::binary|ios::in);
	if(!file)
	{
		cerr<<"file open or crect error!"<<endl;
		exit(1);
	}
	int t;
	file.read(reinterpret_cast<char *>(&t),sizeof(int));
	while(!file.eof())
	{
		cout<<t<<endl;
		file.read(reinterpret_cast<char *>(&t),sizeof(int));
	}
	cout<<endl;
	file.close();
	//printf("Hello World!\n");
	file1.open(aa,ios::binary|ios::out|ios::app);
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
		file1.write((char *)&nR,sizeof(int));
		Rect *a[100];
		for(i=0;i<nR;i++)
		{
			int x,y,l,w;
			cin>>x>>y>>l>>w;
			a[i]=new Rect(x,y,l,w);
		}
		cout<<"圆的个数："<<endl;
		cin>>nC;
		file1.write((char *)&nC,sizeof(int));
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
		file2.read(reinterpret_cast<char *>(&t),sizeof(int));
		while(!file2.eof())
		{
			cout<<t<<endl;
			file2.read(reinterpret_cast<char *>(&t),sizeof(int));
		}
		file2.close();
	}
	return 0;
}





