#include<iostream>
using namespace std;
int p[1000000];//并查集的集合数组
int Find(int x)//寻找根节点以及路径压缩
{
    int pp,temp;
    pp=x;
    while(x!=p[x])
        x=p[x];
    while(pp!=x)//路径压缩
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
    cin>>m>>n;//输入长和宽
    cnt=m*n;//假设有几个点就是有几个集合
    for(int i=0; i<=n*m; i++)
        p[i]=i;//初始化每个集合的根节点都是自己
    int k;
    cin>>k;
    for(int i=0; i<k; i++)
    {
        int a,b;
        cin>>a>>b;
        int aa=Find(a);//如果两个点所属的集合不是个就把它们添加到一个集合中
        int bb=Find(b);
        if(aa!=bb)
        {
            p[aa]=p[bb];
            cnt--;//每当合成一个集合的时候集合总数就会消失一个
        }
    }
    cout<<cnt<<endl;//所以输出最后还有几个集合
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
