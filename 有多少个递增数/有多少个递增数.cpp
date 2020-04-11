#include<iostream>
using namespace std;
int main()
{
	long long a;
	cin>>a;
	int num=0;
	for(long long i=1;i<=a;i++)
	{
		int flag=0;
		long long k=i;
		while(k)
		{
			int j=k%10;
			k/=10;
			int l=k%10;
			if(j<k)
			{
				flag=1; 
				break;
			}  
		}
		if(flag==0)
		{
			num++;
			//cout<<i<<endl;
		}
	}
	cout<<num<<endl;
}


