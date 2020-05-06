#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string.h>
using namespace std;
int judge(char a,char b)//判断运算符优先级，优先级大返回1，否则返回0 
{
	if((a=='+'||a=='-')&&(b=='*'||b=='/'))
		return 0;
	else return 1;
}
int calculate(int a,int b,char c)//进行运算 
{
	if(c=='+')return a+b;
	if(c=='-')return b-a;
	if(c=='*')return a*b;
	if(c=='/')return b/a;
}
int main()
{
	int n;//输入用例 
	cin>>n;
	vector<string> ans;//存放结果
	while(n--)
	{
		stack<int> a;//存放数字 
		stack<char> b;//存放运算符
		char s[10];
		cin>>s;//读入用例 
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
			{
				if(b.empty()) b.push(s[i]);//符号栈为空，符号入栈 
				else
				{
					int t=judge(b.top(),s[i]);//判断当前符号与栈顶符号优先级 
					if(t==0) b.push(s[i]);//优先级不大，入栈 
					else
					{
						int m1=a.top();
						a.pop();
						int m2=a.top();
						a.pop();
						int c=b.top();
						b.pop();
						a.push(calculate(m1,m2,c));//否则数字栈弹出两数字运算后入数字栈 
						b.push(s[i]);
					}
				}
			}
			else a.push(s[i]-'0');//数字入数字栈 
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
		while(!b.empty())//符号栈不为空，连续运算 
		{
			int m1=a.top();//数字栈弹出两个数字 
			a.pop();
			int m2=a.top();
			a.pop();
			char c=b.top();//符号栈弹出一个符号 
			b.pop();
			a.push(calculate(m1,m2,c));//运算结果入数字栈 
		}
		if(a.top()==24) ans.push_back("Yes");//判断结果存入向量 
		else ans.push_back("No");
	} 
	for(auto x:ans)
	{
		cout<<x<<endl;//打印结果 
	}
	return 0;
}
