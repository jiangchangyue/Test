#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int cha=n-m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<a[i]<<" "<<endl;
//	}
//	cout<<cha<<endl;
	
	while(cha--)
	{
		int min=1000000,k;
		for(int i=0;i<n;i++)
		{
			if((a[i]!=-1)&&(min>a[i]))
			{
				min=a[i];
				k=i;
			}
		}
		//cout<<min<<"+"<<a[k]<<endl;
		a[k]=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]!=-1)
		{
			cout<<a[i]<<" "; 
		}
	}
	cout<<endl;
	return 0;
}
