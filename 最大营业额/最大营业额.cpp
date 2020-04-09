#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,M;
	cin>>N>>M;
	long long A[N][M],B[N][M],C[N][M];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>A[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>B[i][j];
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin>>C[i][j];
		}
	}
	long long pro[N][M];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(A[i][j]<B[i][j])
				pro[i][j]=A[i][j]*C[i][j];
			else
				pro[i][j]=B[i][j]*C[i][j];
		}
	}
//	for(int i=0;i<N;i++)
//	{
//		for(int j=0;j<M;j++)
//		{
//			cout<<pro[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	long long sum=0;
	for(int i=0;i<N;i++)
	{
		long long max=0;
		for(int j=0;j<M;j++)
		{
			if(max<pro[i][j])max=pro[i][j];
		}
		sum=sum+max;
	}
	cout<<sum<<endl;
	return 0;
}
