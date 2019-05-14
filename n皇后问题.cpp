#include<bits/stdc++.h>
using namespace std;
int x[100]={-1};
int Place(int k)
{
	for(int i=0;i<k;i++)
	{
		if(x[i]==x[k]||abs(i-k)==abs(x[i]-x[k]))
			return 1;
	}
	return 0;
}
void Queen(int n)
{
	int k=0;
	int flag=0;
	while(k>=0)
	{
		x[k]++;
		while(x[k]<n&&Place(k)==1)
			x[k]++;
		if(x[k]<n&&k==n-1)
		{
			for(int i=0;i<n;i++)
			{
				cout<<x[i]+1<<" ";
			}
			cout<<endl;
			//return ;
			flag=1;
		}
		if(x[k]<n&&k<n-1)
			k=k+1;
		else
			x[k--]=-1;
	}
	if(flag==0)    
		cout<<"нч╫Б"<<endl;
}
int main()
{
	int n;
	cin>>n;
	Queen(n);
	return 0;
}
