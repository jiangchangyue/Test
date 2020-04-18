#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin>>n;
	stack<int> a;
	for(int i=0;i<n;i++)
	{
		int tem;
		cin>>tem;
		a.push(tem);
	}
	int sum=1;
	int t=a.top();
	a.pop();
	while(!a.empty())
	{
		if(a.top()!=t)
		{
			sum++;
			t=a.top();
		}
		a.pop();
	}
	cout<<sum<<endl;
	return 0;
}
