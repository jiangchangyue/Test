#include<iostream>
using namespace std;
int p[1000000];//���鼯�ļ�������
int Find(int x)//Ѱ�Ҹ��ڵ��Լ�·��ѹ��
{
    int pp,temp;
    pp=x;
    while(x!=p[x])
        x=p[x];
    while(pp!=x)//·��ѹ��
    {
        temp=p[pp];
        p[pp]=x;
        pp=temp;
    }
    return x;
}
int main()
{
    int cnt;
    int m,n;
    cin>>m>>n;//���볤�Ϳ�
    cnt=m*n;//�����м���������м�������
    for(int i=0; i<=n*m; i++)
        p[i]=i;//��ʼ��ÿ�����ϵĸ��ڵ㶼���Լ�
    int k;
    cin>>k;
    for(int i=0; i<k; i++)
    {
        int a,b;
        cin>>a>>b;
        int aa=Find(a);//��������������ļ��ϲ��Ǹ��Ͱ�������ӵ�һ��������
        int bb=Find(b);
        if(aa!=bb)
        {
            p[aa]=p[bb];
            cnt--;//ÿ���ϳ�һ�����ϵ�ʱ�򼯺������ͻ���ʧһ��
        }
    }
    cout<<cnt<<endl;//�����������м�������
}


/*#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int r[m][n];
    int s[m*n][m*n];
    memset(s,0,sizeof(s));
    int d=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=d;
            d++;
        }
    }
    int k;
    cin>>k;
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        for(int i=0;i<m*n;i++)
        {
            for(int j=0;j<m*n;j++)
            {
                if(s[i][j]==a||s[i][j]==b)
                {

                }
            }
        }
    }
}*/
