#include<bits/stdc++.h>
using namespace std;
int lcm(int a,int b)
{
	int n=a,k=b;
	if(a<b)
	{
		int t=a;
		a=b;
		b=t;
	}
	int m=a%b;
	while(m)
	{
		int c=a,v=b;
		a=v;
		b=c%v;
		m=a%b;
	}
	return n*k/b;
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<lcm(a,b);
	return 0;
}
