#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string.h>
using namespace std;
int judge(char a,char b)//�ж���������ȼ������ȼ��󷵻�1�����򷵻�0 
{
	if((a=='+'||a=='-')&&(b=='*'||b=='/'))
		return 0;
	else return 1;
}
int calculate(int a,int b,char c)//�������� 
{
	if(c=='+')return a+b;
	if(c=='-')return b-a;
	if(c=='*')return a*b;
	if(c=='/')return b/a;
}
int main()
{
	int n;//�������� 
	cin>>n;
	vector<string> ans;//��Ž��
	while(n--)
	{
		stack<int> a;//������� 
		stack<char> b;//��������
		char s[10];
		cin>>s;//�������� 
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
			{
				if(b.empty()) b.push(s[i]);//����ջΪ�գ�������ջ 
				else
				{
					int t=judge(b.top(),s[i]);//�жϵ�ǰ������ջ���������ȼ� 
					if(t==0) b.push(s[i]);//���ȼ�������ջ 
					else
					{
						int m1=a.top();
						a.pop();
						int m2=a.top();
						a.pop();
						int c=b.top();
						b.pop();
						a.push(calculate(m1,m2,c));//��������ջ���������������������ջ 
						b.push(s[i]);
					}
				}
			}
			else a.push(s[i]-'0');//����������ջ 
		}
//		while(!a.empty())
//		{
//			cout<<a.top()<<endl;
//			a.pop();
//		}
//		while(!b.empty())
//		{
//			cout<<b.top()<<endl;
//			b.pop();
//		}
		while(!b.empty())//����ջ��Ϊ�գ��������� 
		{
			int m1=a.top();//����ջ������������ 
			a.pop();
			int m2=a.top();
			a.pop();
			char c=b.top();//����ջ����һ������ 
			b.pop();
			a.push(calculate(m1,m2,c));//������������ջ 
		}
		if(a.top()==24) ans.push_back("Yes");//�жϽ���������� 
		else ans.push_back("No");
	} 
	for(auto x:ans)
	{
		cout<<x<<endl;//��ӡ��� 
	}
	return 0;
}
