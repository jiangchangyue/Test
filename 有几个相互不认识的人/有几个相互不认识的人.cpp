#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int num;
	int whe;
	int a[100];	
	stu()
	{
		memset(a,0,sizeof(a));
	}
};
int main()
{
	int n,m;
	cin>>n>>m;
	int r[m][2];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>r[i][j];
		}
	}
	stu st[n];
	for(int i=0;i<n;i++)
	{
		st[i].num=i+1;
		st[i].whe=0;
		st[i].a[st[i].num-1]=1;
		for(int j=0;j<m;j++)
		{
			if(r[j][0]==st[i].num)
			{
				st[i].a[r[j][1]-1]=1;
				st[r[j][1]-1].a[st[i].num-1]=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<st[i].num<<endl;
		cout<<st[i].whe<<endl;
		for(int j=0;j<n;j++)
		{
			cout<<st[i].a[j];
		}cout<<endl<<endl;
	}
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(st[i].whe==0)
		{
			st[i].whe=1;
			for(int j=0;j<n;j++)
			{
				if(st[i].a[j]==0&&st[j].whe==0)
				{	
					st[j].whe=1;
				}
			}
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}

//40
//50
//25 32
//5 27
//29 7
//11 27
//10 15
//17 11
//17 14
//17 13
//4 14
//40 3
//20 19
//38 5
//32 38
//32 33
//13 15
//15 39
//38 19
//36 9
//15 6
//34 7
//11 39
//37 12
//12 11
//10 30
//18 35
//30 2
//23 14
//23 16
//9 31
//20 29
//25 10
//33 34
//16 17
//12 18
//16 22
//15 14
//20 34
//26 17
//10 8
//12 5
//37 7
//29 22
//2 28
//1 15
//12 27
//18 14
//19 27
//16 34
//27 39
//40 37

