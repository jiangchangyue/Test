#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int max=0;
	for(int i=0;i<n;i++)
	{
		int sum=0;
		for(int j=0;j<m;j++)
		{
			int w=i+j; 
			if(w>(n-1))
			{
				w%=n;
			}
			sum=sum+a[w];
		} 
		if(max<sum)
			max=sum;
	} 
	cout<<max<<endl;
	return 0;
}
