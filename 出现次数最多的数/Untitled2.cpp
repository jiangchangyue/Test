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
	int k,max=0,temp=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			temp++;
		}
		else
		{
			if(max<temp)
			{
				max=temp;
				k=a[i-1];
			}
			temp=1;
		}
	}
	cout<<k<<endl;
	return 0;
}
