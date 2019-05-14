#include<iostream>
using namespace std;
int escf(int n,int m)
{
	if(n==1)return m;
	if(n%2==0)
	{
		n=n/2;
		m=2*m;
		return escf(n,m);
	}
	else
	{
		n=(n-1)/2;
		int k=m;
		m=2*m;
		return k+escf(n,m);
	} 
}
int main()
{
	int n,m;
	cin>>n>>m;
	int num=escf(n,m);
	cout<<num<<endl;
}
