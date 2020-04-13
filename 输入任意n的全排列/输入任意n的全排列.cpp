#include<iostream>
using namespace std;
typedef struct Node
{
	int num=0;
	bool outHand = false;
}Node;
int n;
Node list[10];
void DFS(int step)
{
	if (step == n+1)    //判断边界，此时所有数都放到了容器中
	{
		for (int i = 1;i <= n;i++)
			cout << list[i].num;       //输出容器中的状态
		cout << endl;
		return;   //返回到堆栈中上一个递归状态
	}
	for (int i = 1;i <= n;i++)//尝试每一种可能
	{
		if (list[i].outHand == false)//前提是这个n还没有放进去
		{
			list[step].num = i;   //把1到n放到容器list中
			list[i].outHand = true;    //改变状态
			DFS(step + 1);    //继续递归下一步
			list[i].outHand= false;//下一步完事后，肯定是要换一个数的，所以我们把之前的数收回去
		}
	}
	return;//所有可能都完事的时候，返回。
}
int main()
{
	cin >> n;
	DFS(1);
}


//#include<bits/stdc++.h>
//#include<iostream>
//using namespace std;
//struct Node
//{
//	int num=0;
//	int flag=0;
//}; 
//int n;
//Node sstack[10];
//void DFS(int a)
//{
//	if(a==n+1)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			cout<<sstack[i].num;
//		}
//		cout<<endl;
//		return;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(sstack[i].flag==0)
//		{
//			sstack[a].num=i;
//			sstack[i].flag=1;
//			DFS(a+1);
//			sstack[i].flag=0;
//		}
//	}
//	return;
//}
//int main()
//{
//	cin>>n;
//	DFS(1);
//	return 0;
//}
