#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int **p;
	p=new int *[n]; 
	for(int i=0;i<n;i++)
	{
		p[i]=new int [m+3];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			cin>>p[i][j];
			p[i][m+1]=0;
			p[i][m+2]=0;
		}
	}
	int sum=0,max=0,flag=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			p[i][m+1]=p[i][m+1]+p[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m+1;j++)
		{
			p[i][m+2]=p[i][m+2]+p[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		sum=sum+p[i][m+1];
	}
	max=p[0][m+2];
	for(int i=0;i<n;i++)
	{
		if(max>p[i][m+2])
		{
			max=p[i][m+2];
			flag=i+1;
		}
	}
	cout<<sum<<" "<<flag<<" "<<abs(max)<<endl;
	return 0;
}
