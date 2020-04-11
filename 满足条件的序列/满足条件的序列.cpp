#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int num=n;
	for(int i=1;i<n;i++)
	{
		int k=n-i;
		num=num+k-1;
	}
	cout<<num<<endl;
	return 0;
}
