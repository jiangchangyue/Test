#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[30];
	int t,k=0;
	do
	{
		cin>>t;
		a[k]=t;
		k++;
	}while(t!=0);
	int num=0;
	int b[k];
	for(int i=0;i<k;i++)
	{
		if((a[i]==1))
		{
			b[i]=1;
		}
		if((a[i]==2&&a[i-1]==1)||(a[i]==2&&i==0))
		{
			b[i]=2;
		}
		if(a[i]==2&&a[i-1]==2)
		{
			b[i]=b[i-1]+2;
		}
	}
	for(int i=0;i<k-1;i++)
	{
		num+=b[i];
	}
	cout<<num<<endl;
	return 0;
}
