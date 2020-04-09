#include<bits/stdc++.h>
using namespace std;
int judge(int n)
{
	if(n==2||n==3)return 1;
	if(n>3)
	{
		for(int i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)return 0;
		}
		return 1;
	}
	return 0;
}
int main()
{
	int N;
	cin>>N;
	int sum=1;
	int flag=0;
	int i=2;
	while(1)
	{
		if(flag==N)break;
		if(judge(i)==1)
		{
			sum=sum*(i%50000);
			flag++;
		}
		i++;
	}
	cout<<sum%50000<<endl;
	return 0;	
} 
