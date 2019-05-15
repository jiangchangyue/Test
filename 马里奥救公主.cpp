/*#include<iostream>
using namespace std;
int a[100000],s[100000],ss[100000];
int main()
{
    int T;
    cin>>T;
    int e=1;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int b,c,d;
        for(int k=0;k<m;k++)
        {
            int flag=0;
            cin>>b>>c>>d;
            for(int i=0;i<=c-b;i++)
            {
                ss[i]=a[i+b];
            }
            for(int i=0;i<=c-b-1;i++)
            {
               for(int j=i+1;j<=c-b;j++)
               {
                  if(ss[i]>ss[j])
                  {
                      int t;
                      t=ss[i];
                      ss[i]=ss[j];
                      ss[j]=t;
                  }
               }
            }
            for(int i=0;i<=c-b;i++)
            {
                if(d>=ss[i])
                {
                    flag++;
                }
                else
                    break;
            }
            s[k]=flag;
        }
        cout<<"Case "<<e<<":"<<endl;
        for(int i=0;i<m;i++)
            cout<<s[i]<<endl;
        e++;
    }
}*/
#include<stdio.h>
int main()
{
    int y=0,m=0,n=0;
    for(int i=1;i<=10;i++)
    {
        m++,if(2*i<=10)
        {
            for(int j=2*i;j<=10;j++)
            {
                y=y+i*j,n++;
            }
        }
    }
    printf("%d %d\n",m,n);
}
