#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int **p;
	p=new int *[n];
	int *q,*t;
	q=new int[n];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		q[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		p[i]=new int [m];
		for(int j=0;j<m;j++)
		{
			cin>>p[i][j];
		}
		for(int j=1;j<m;j++)
		{
			if(p[i][j]<=0)
			{
				p[i][j]=p[i][j]+p[i][j-1];
			}
			else
			{
				if(p[i][j]<p[i][j-1])
				{
					q[i]=1;
				}
			}
		} 
		sum=sum+p[i][m-1];
	}

	int d=0,e=0;
	for(int i=0;i<n;i++)
	{
		d=d+q[i];
	}
	for(int i=0;i<n;i++)
	{
		if(q[i]==1)
		{
			if(i==0)
			{
				if(q[n-1]==1&&q[i+1]==1)
				{
					e++;
				}
			}
			else if(i==(n-1))
			{
				if(q[0]==1&&q[i-1]==1)
				{
					e++;
				}
			}
			else
			{
				if(q[i-1]==1&&q[i+1]==1)
				{
					e++;
				}
			}
		}
	}
	cout<<sum<<" "<<d<<" "<<e<<endl;
	return 0;
}

/*
5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0
*/
