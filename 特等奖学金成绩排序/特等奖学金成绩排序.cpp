#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int n;
	int s[101];
}; 
void sort(stu *a,int st,int n,int m)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=st;j<n-i-1+st;j++)
		{
			if(a[j].s[m]<a[j+1].s[m])
			{
				stu temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
} 
int look(stu *a,int n,int st,int m)
{
	int sum=1;
	for(int i=st;i<n;i++)
	{
		if(a[i].s[m]==a[i+1].s[m])
			sum++;
		else break;
	}
	return sum;
}
void show(stu *a,int n,int m)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i].n<<" ";
		for(int j=0;j<m;j++)
		{
			cout<<a[i].s[j]<<" ";
		}
		cout<<endl;
	}
	cout<<"-------------------"<<endl;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	stu a[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i].s[j];
			a[i].n=i+1;
		}
	}
	int flag=0;
	sort(a,0,n,0);
	//show(a,n,m);
	for(int i=0;i<n;i++)
	{
		int flag2=0;
		for(int j=0;j<m;j++)
		{
			flag2=0;
			if(look(a,n,i,j)==1)
			{
				for(int w=0;w<m;w++)
				{
					if(a[i].s[w]<85)
					{
						flag2++;
					}
				}
				if(flag2==0)
				{
					cout<<a[i].n<<" ";
					flag++;
					break;
				}
				else continue;
			}
			else
			{
				int d=look(a,n,i,j);
				sort(a,i,d,j+1);
				//show(a,n,m);
			}
		}
		if(flag==k)
		{
			cout<<endl;
			break;
		}
	}
	cout<<endl;
	return 0;
}
