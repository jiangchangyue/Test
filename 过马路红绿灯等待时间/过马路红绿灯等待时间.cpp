#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,y,g;
	cin>>r>>y>>g;
	int n;
	cin>>n;
	int a[n][2]; 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>a[i][j];
		}
	}
	int num=0;
	for(int i=0;i<n;i++)
	{
		switch(a[i][0])
		{
			case 0:
			case 1:
				num+=a[i][1];
				break;
			case 2:
				num+=a[i][1]+r;
				break;		
		}
	}
	cout<<num<<endl;
	return 0;
}
