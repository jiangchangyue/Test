#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n; 
	n/=10;
	int b=n%5;
	if(b>=3)
		cout<<n/5*7+b+1<<endl;
	else
		cout<<n/5*7+b<<endl;
	return 0;
}
