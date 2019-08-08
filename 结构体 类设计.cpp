//#include<bits/stdc++.h>
//using namespace std;
#include<stdio.h>
struct node
{
	int a,b;
	void init(int a,int b)
	{
		this->a=a;
		this->b=b;
	}
	int mutlip()
	{
		int area=a*b;
		return area;	
	}
}; 
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	node d;
	d.init(a,b);
//	cout<<d.mutlip()<<endl;
	printf("%d\n",d.mutlip());
	return 0;
}
