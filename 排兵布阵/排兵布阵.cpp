#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n,m;
int a[50005],c[50005];
int lowbit(int x)
{
	return x&(-x);
}
void updata(int i,int k)
{
	while(i<=n)
	{
		c[i]+=k;
		i+=lowbit(i);
	}
}
int getsum(int i)
{
	int res=0;
	while(i>0)
	{
		res+=c[i];
		i-=lowbit(i);
	}
	return res;
}

int main(){
    int t;
    cin>>t;
    for(int tot = 1; tot <= t; tot++)
	{
        cout << "Case " << tot << ":" << endl;
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        cin>>n;
        for(int i = 1; i <= n; i++)
		{
            cin>>a[i];
            updata(i,a[i]);   //�����ֵ��ʱ��Ҳ�൱�ڸ�����ֵ
        }
        string s;
        int x,y;
        while(cin>>s && s[0] != 'E')
		{
            cin>>x>>y;
            if(s[0] == 'Q')
			{    //��Ͳ���
                int sum = getsum(y) - getsum(x-1);    //x-y�����Ҳ�͵���1-y����ͼ�ȥ1-(x-1)�����
                cout << sum << endl;
            }
            else if(s[0] == 'A')
			{
                updata(x,y);
            }
            else if(s[0] == 'S')
			{
                updata(x,-y);    //��ȥ��������Ϊ�����෴��
            }
        }
    }
    return 0;
}

