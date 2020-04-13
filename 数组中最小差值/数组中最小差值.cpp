#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	int b[n-1];
	for(int i=1;i<n;i++)
	{
		b[i-1]=a[i]-a[i-1];
	}
	for(int i=0;i<n-1-1;i++)
	{
		for(int j=0;j<n-i-2;j++)
		{
			if(b[j]>b[j+1])
			{
				int temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			} 
		}
	} 
	cout<<b[0]<<endl;
	return 0;
}
