#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	char a[n][m];
	int b[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			b[i][j]=0;
		}
	}
	int k;
	cin>>k;
	for(int t=0;t<k;t++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]=='g')
				b[i][j]=1;
			}
		} 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(b[i][j]==1)
				{
					if(i>0&&i<n-1&&j>0&&j<m-1)
					{
						if(a[i-1][j]=='.')a[i-1][j]='g';
						if(a[i+1][j]=='.')a[i+1][j]='g';
						if(a[i][j-1]=='.')a[i][j-1]='g';
						if(a[i][j+1]=='.')a[i][j+1]='g';
					}
					if(i==0&&j>0&&j<m-1)
					{
						if(a[i+1][j]=='.')a[i+1][j]='g';
						if(a[i][j-1]=='.')a[i][j-1]='g';
						if(a[i][j+1]=='.')a[i][j+1]='g';
					}
					if(i==n-1&&j>0&&j<m-1)
					{
						if(a[i-1][j]=='.')a[i-1][j]='g';
						if(a[i][j-1]=='.')a[i][j-1]='g';
						if(a[i][j+1]=='.')a[i][j+1]='g';
					}
					if(j==0&&i>0&&i<n-1)
					{
						if(a[i-1][j]=='.')a[i-1][j]='g';
						if(a[i+1][j]=='.')a[i+1][j]='g';
						if(a[i][j+1]=='.')a[i][j+1]='g';
					}
					if(j==m-1&&i>0&&i<n-1)
					{
						if(a[i-1][j]=='.')a[i-1][j]='g';
						if(a[i+1][j]=='.')a[i+1][j]='g';
						if(a[i][j-1]=='.')a[i][j-1]='g';
					}
					if(i==0&&j==0)
					{
						if(a[i+1][j]=='.')a[i+1][j]='g';
						if(a[i][j+1]=='.')a[i][j+1]='g';
					}
					if(i==0&&j==m-1)
					{
						if(a[i+1][j]=='.')a[i+1][j]='g';
						if(a[i][j-1]=='.')a[i][j-1]='g';
					}
					if(i==n-1&&j==0)
					{
						if(a[i-1][j]=='.')a[i-1][j]='g';
						if(a[i][j+1]=='.')a[i][j+1]='g';
					}
					if(i==n-1&&j==m-1)
					{
						if(a[i-1][j]=='.')a[i-1][j]='g';
						if(a[i][j-1]=='.')a[i][j-1]='g';
					}
				}
			}
		} 
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
