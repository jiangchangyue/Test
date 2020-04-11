//#include<iostream>
//using namespace std;
//int main()
//{
//	long long n;
//	cin>>n;
//	long long a[n+1],b[n+1];
//	for(long long i=1;i<n+1;i++)
//	{
//		cin>>a[i];
//		b[i]=0;
//	}
//	int num=0;
//	for(long long i=1;i<n-1;i++)
//	{//cout<<a[i]<<"+";
//		int flag=0;
//		for(long long j=(i+1);j<n;j++)
//		{//cout<<a[j]<<"++";
//			if(a[j]>a[i])
//			{
//				for(long long p=(j+1);p<n+1;p++)
//				{//cout<<a[p]<<"+++"<<endl;
//					if(a[p]>a[j])
//					{
//						//cout<<a[i]<<"<"<<a[j]<<"<"<<a[p]<<endl;
//						flag=1;
//						break;
//					}
//				}
//			}
//			if(flag==1&&b[j]==0)
//			{
//				b[j]++;
//				num++;
//			}
//		}
//	}
//	cout<<num<<endl;
//}

#include<iostream>
using namespace std;
int main()
{
	int a[10000],n,i,sum=0,j,k;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n-2;i++)
	{
		for(j=i+1;j<n-1;j++)
			{
				for(k=j+1;k<n;k++)
					{
						if(a[i]<a[j] && a[j]<a[k])
						{	
							sum++;
							a[j]=0;
							break;
						}
					}
			}
	}
	cout<<sum<<endl;
	return 0;
}
