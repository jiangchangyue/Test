// 带异常处理嵌套的求二元一次方程的解.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
using namespace std;
/*struct Res
{
	float x1,x2;
};
float quotient(int a,int b)throw(char *)
{
	if(b==0)
		throw("Divide 0!");
	else
		return a/(float)b;
}
Res resolution(int a,int b,int c)throw(int)
{
	Res tmpr;
	try
	{
		if(a==0&&b!=0)
		{
			tmpr.x1=tmpr.x2=quotient(-c,b);
			return tmpr;
		}
		if(b*b-4*a*c<0)
			throw(b);
		tmpr.x1=quotient(-b+sqrt(b*b-4.0*a*c),2*a);
		tmpr.x2=quotient(-b-sqrt(b*b-4.0*a*c),2*a);
		return tmpr;
	}
	catch(char *ErrS)
	{
		cerr<<ErrS<<endl;
	}
}
int main(int argc, char* argv[])
{
	int a,b,c;
	Res r;
	cout<<"Input a,b,c:";
	cin>>a>>b>>c;
	try
	{
		r=resolution(a,b,c);
		cout<<"x1="<<r.x1<<"\tx2="<<r.x2<<endl;
	}
	catch(int)
	{
		cerr<<"Sqrt Negative Exception"<<endl;
	}
	catch(...)
	{
		cerr<<"unexpected or rethrow exception!"<<endl;
	}
	//printf("Hello World!\n");
	return 0;
}*/

int main()
{
	float a,b;
	cin>>a>>b;
	try
	{
		if(b==0)throw("error!");
		float c=a/b;
		cout<<c<<endl;
	}
	catch(char *a)
	{
		cerr<<a<<endl;
	}
	return 0;
}