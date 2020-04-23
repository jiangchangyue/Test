#include<iostream>
using namespace std;
int n;
int a[1000];
void quick(int left,int right)
{
	int i,j,t,temp;
	if(left>right)return;
	
	temp=a[left];
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]>=temp&&i<j)
		{
			j--;
		}
		while(a[i]<=temp&&i<j)
		{
			i++;
		}
		
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[left]=a[i];//基准数归位 
	a[i]=temp;
	
	quick(left,i-1);
	quick(i+1,right);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quick(0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
