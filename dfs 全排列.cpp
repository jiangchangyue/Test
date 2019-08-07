//#include<bits/stdc++.h>
//using namespace std;
//#include<stdio.h>
//int n,a[12],book[12];
//void dfs(int step)
//{
//	if(step==n+1)
//		{
//			for(int j=1;j<=n;j++)
//			printf("%d",a[j]);
//			printf(" ");
//			return ;
//		}
//	for(int i=1;i<=n;i++)
//	{
//		if(book[i]==0)
//		{
//			a[step]=i;
//			book[i]=1;
//			dfs(step+1);
//			book[i]=0;
//		}
//	}
//   	
//}	
//int main()
//{
//    scanf("%d",&n);	
//	dfs(1);
//	return 0;
//}

































#include<bits/stdc++.h>
using namespace std;
int n,a[1<<3],b[1<<3];
void dfs(int step)
{
	if(step==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<a[i];
		}
		cout<<" ";
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(b[i]==0)
			{
				a[step]=i;
				b[i]=1;
				dfs(step+1);
				b[i]=0;
			}
		}
	}
} 
int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
