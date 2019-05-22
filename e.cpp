#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        int a[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
               a[i][j]=0;
            }
        }
        for(int j=0;j<m;j++)
        {
            int len;
            cin>>len;
            int num;
            for(int k=0;k<len;k++)
            {
                cin>>num;
                a[j][num-1]=num;
            }
        }
        int sum=0;

        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<m;j++)
            {
                if(a[j][i]==0)
                {
                    flag=1;
                }
            }
            if(flag==0)sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
