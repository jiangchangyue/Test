#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	int y;
}; 
int n;
node a[1001];
bool istrash(int x,int y)
{
	for(int i=0;i<n;i++)
	{
		if(a[i].x==x&&a[i].y==y)
			return true;
	}
	return false;
}
bool isstation(node t)
{
	if(istrash(t.x-1,t.y)&&istrash(t.x+1,t.y)&&istrash(t.x,t.y-1)&&istrash(t.x,t.y+1))
		return true;
	else return false; 
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	int score[5]={0};
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(isstation(a[i]))
		{
			if(istrash(a[i].x-1,a[i].y+1))count++;
			if(istrash(a[i].x+1,a[i].y+1))count++;
			if(istrash(a[i].x-1,a[i].y-1))count++;
			if(istrash(a[i].x+1,a[i].y-1))count++;
			score[count]++;
			count=0;
		}
	}
	for(int i=0;i<5;i++)
	{
		cout<<score[i]<<endl;
	}
	return 0;
}
