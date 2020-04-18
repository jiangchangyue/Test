#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	a[n]=10000000; 
	sort(a,a+n);
	int flag;
	int max=0;
	int num=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			num++;
		}
		if(a[i]!=a[i+1])
		{
			if(max<num)
			{
				max=num;
				flag=a[i];
				
			}
			else if(max==num)
			{
				if(flag>a[i])
					flag=a[i];
			}
			num=1;
		}
	}
	cout<<flag<<endl;
	return 0;
}

//#include<iostream>
//#include<map>
//using namespace std;
//int main()
//{
//	map<int,int> m;
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		int temp;
//		cin>>temp;
//		m[temp]++;
//	}
//	int ans,max=0;
//	for(auto it:m)
//	{
//		if(it.second>max)//second表示m[]的值 
//		{
//			max=it.second;
//			ans=it.first;//first表示[]里的下标 
//		}
//	}
//	cout<<ans<<endl;
//	return 0;
//}
