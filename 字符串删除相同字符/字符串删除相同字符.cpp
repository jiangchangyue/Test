#include<bits/stdc++.h>
using namespace std;
char a[105];
void DelPack()
{
	int len=strlen(a);
	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			if(a[i]==a[j])
			{
				for(int k=j;k<len-1;k++)
				{
					a[k]=a[k+1];
				}
				for(int k=i;k<len-1;k++)
				{
					a[k]=a[k+1];
				}
				len-=2;
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
} 
int main()
{
	cin>>a;
	DelPack();
	return 0;
}
