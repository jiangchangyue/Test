#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	long n,max,min;
	cin>>n;
	double a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(a[0]>a[n-1])
	{
		max=a[0];
		min=a[n-1];
	}
	else
	{
		max=a[n-1];
		min=a[0];
	}
	double mid;
	if(n%2==1)mid=a[n/2];
	else mid=(a[n/2]+a[(n/2)-1])/2;
	if(mid==(int)mid)
	{
		cout<<max<<" "<<(int)mid<<" "<<min<<endl;
	}
	else
	{
		cout<<max<<" ";
		cout<<setiosflags(ios::fixed)<<setprecision(1)<<mid<<" ";
		cout<<min;	
	}
	return 0;
}
