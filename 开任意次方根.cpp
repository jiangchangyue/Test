#include<bits/stdc++.h>
using namespace std;
double xqrt(int x,int n)
{
	double x1=1;
	double x2;
	do{
		x2=x1;
		x1=x1-(pow(x1,n)-x)/(n*pow(x1,n-1));
	} while(fabs(x2-x1)>1e-8);
	return x1;
}
int main()
{
	int m,n;
	cin>>m>>n; 
	cout<<xqrt(m,n)<<endl;
	return 0;
}
