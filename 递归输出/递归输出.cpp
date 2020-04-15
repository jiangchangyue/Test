#include<iostream>
using namespace std;
void digui(long long n)
{
	int m=n%10;
	n=n/10;
	if(n==0)
	{
		cout<<m<<"-";
		return;
	}
	else	
		digui(n);
	cout<<m<<"-";
}
int main()
{
	long long n;
	cin>>n;
	digui(n);
	cout<<endl;
	return 0;
}
