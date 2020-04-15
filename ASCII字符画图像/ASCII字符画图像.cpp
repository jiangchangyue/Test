#include<bits/stdc++.h>
using namespace std;
int n,m,q;
char a[1000][1000];
int book[1000][1000];
void dfs(int x,int y,char c)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	if(x>n-1||x<0||y>m-1||y<0)return;
	if(a[x][y]=='-'||a[x][y]=='|'||a[x][y]=='+')return;
	if(book[x][y]==1)return;
	a[x][y]=c;
	book[x][y]=1;
	int tx,ty;
	for(int i=0;i<4;i++)
	{
		tx=x+next[i][0];
		ty=y+next[i][1];
		dfs(tx,ty,c);
	}
}
void huaxian(int x1,int y1,int x2,int y2)
{
	if(x1==x2)
	{
		int max=y1>y2?y1:y2;
		int min=y1<y2?y1:y2;
		for(int i=min;i<max+1;i++)
		{
			if(a[x1][i]=='-')
			{
				a[x1][i]='+'; 
			} 
			else
			{
				a[x1][i]='|';	
			} 
		}
	}
	if(y1==y2)
	{
		int max=x1>x2?x1:x2;
		int min=x1<x2?x1:x2;
		for(int i=min;i<max+1;i++)
		{
			if(a[i][y1]=='|')
			{
				a[i][y1]='+'; 
			} 
			else
			{
				a[i][y1]='-';	
			} 
		}
	}
}
int main()
{
	cin>>n>>m>>q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			a[i][j]='.';
		}
	}
//	for(int i=m-1;i>=0;i--)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<a[j][i];
//		}
//		cout<<endl;
//	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<a[i][j];
//		}
//		cout<<endl;
//	}
	char bb;
	int b[5];
	memset(book,0,sizeof(book));
	for(int t=0;t<q;t++)
	{
		cin>>b[0];
		if(b[0]==1)
		{
			for(int i=1;i<3;i++)
			{
				cin>>b[i];
			}
			cin>>bb;
			dfs(b[1],b[2],bb);
			memset(book,0,sizeof(book));
		}
		else if(b[0]==0)
		{
			for(int i=1;i<5;i++)
			{
				cin>>b[i];
			}
			huaxian(b[1],b[2],b[3],b[4]);
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<a[i][j];
//		}
//		cout<<endl;
//	}
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[j][i];
		}
		cout<<endl;
	}
	return 0;
}
