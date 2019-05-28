#include<iostream>
using namespace std;
int main()
{
	int a;
	cin>>a;
	int n=-1;
	a=a+1;
	while(a>0)
	{
		n++;
		a=a/2;
	}
	int k=1;
	for(int i=0;i<n-1;i++)
	{
		k=k*2;
	}
	int a[n][k];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2*i;j++)
		{
			cin>>a[i-1][j];
		}
	}
}
