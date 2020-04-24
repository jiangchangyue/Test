#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
int main()
{
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<long long> t;
	int b,c1,c2,c3;
	long long sum;
	while(m--)
	{
		cin>>b;
		if(b==2)
		{
			cin>>c1>>c2;
			sum=0;
			for(int i=c1-1;i<c2;i++)
			{
				sum+=a[i];
			}
			t.push_back(sum);
		}
		else if(b==1)
		{
			cin>>c1>>c2>>c3;
			for(int i=c1-1;i<c2;i++)
			{
				if(a[i]%c3==0)
					a[i]/=c3;
			}
		}
	}
	for(auto x:t)
		cout<<x<<endl;
	return 0;
}
