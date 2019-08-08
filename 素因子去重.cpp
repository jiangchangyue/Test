#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	int e=sqrt(n);
	long long p=1;
	int flag=0;
	for(int i=2;i<e;i++)
	{
		if(n%i==0)
		{
			p=p*i;
			while(n%i==0) n=n/i;
		}
	}
	if(n>1)p=p*n;
	cout<<p<<endl;
	return 0;
}
