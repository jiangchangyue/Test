#include<bits/stdc++.h>
using namespace std;
int a[1000];
int CompactIntegers(int num)
{
	int k=num;
	int h=0;
	while(1)
	{
		h=k;
		for(int i=0;i<k;i++)
		{
			if(a[i]==0)
			{
				k--;
				int j=i+1;
				int t=i; 
				while(j<num)
				{
					a[t]=a[j];
					j++;
					t++;
				}
			}
		}
		if(h==k)break;
	}
	return k;
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int num=CompactIntegers(n);
	cout<<num<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<a[i]<<" "; 
	}
	cout<<endl;
	return 0;
}
