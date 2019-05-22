#include<iostream>
using namespace std;
double xie(int a,int b,int c,int d)
{
    if((c-a)==0) return 100000;
    else
    {
        double num=(double)(d-b)/(c-a);
        return num;
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n][2];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                cin>>a[i][j];
            }
        }
        double num=10000000;
        for(int i=0;i<n-1;i++)
        {
             for(int j=i+1;j<n;j++)
             {
                 double temp=xie(a[i][0],a[i][1],a[j][0],a[j][1]);
                 if(temp==100000)
                  continue;
                 if(num>temp)
                    num=temp;
             }
        }
        printf("%.3lf\n",num);
    }
    return 0;
}
