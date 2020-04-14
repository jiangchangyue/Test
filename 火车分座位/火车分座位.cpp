#include<bits/stdc++.h>
using namespace std;
struct ps
{
	int flg=0;
	int who;
};
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ps b[20][5];
	int flag;
	int flag2=0;
	int flag3=0;
	int fl;
	for(int k=0;k<n;k++)
	{
		flag=0;
		fl=0;
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(b[i][j].flg==0)
				{
					if((5-j)>=a[k])
					{
						for(int d=j;d<a[k]+j;d++)
						{
							b[i][d].flg=1;
							b[i][d].who=k;
						}
						flag=1;
					}
				}
				if(flag==1)
				{
					fl=1;
					break;
				}
			}
			if(fl==1)break;
		}
		if(flag==0)
		{
			for(int i=0;i<20;i++)
			{
				for(int j=0;j<5;j++)
				{
					if(flag2==a[k])
					{
						flag3=1;
						break;
					}
					if(b[i][j].flg==0)
					{
						b[i][j].flg=1;
						b[i][j].who=k;
						flag2++;
					}
				}
				if(flag3==1)break;
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<20;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(b[i][j].flg==1&&b[i][j].who==k)
				{
					cout<<i*5+j+1<<" ";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
