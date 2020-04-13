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
	if (step == n+1)    //�жϱ߽磬��ʱ���������ŵ���������
	{
		for (int i = 1;i <= n;i++)
			cout << list[i].num;       //��������е�״̬
		cout << endl;
		return;   //���ص���ջ����һ���ݹ�״̬
	}
	for (int i = 1;i <= n;i++)//����ÿһ�ֿ���
	{
		if (list[i].outHand == false)//ǰ�������n��û�зŽ�ȥ
		{
			list[step].num = i;   //��1��n�ŵ�����list��
			list[i].outHand = true;    //�ı�״̬
			DFS(step + 1);    //�����ݹ���һ��
			list[i].outHand= false;//��һ�����º󣬿϶���Ҫ��һ�����ģ��������ǰ�֮ǰ�����ջ�ȥ
		}
	}
	return;//���п��ܶ����µ�ʱ�򣬷��ء�
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
