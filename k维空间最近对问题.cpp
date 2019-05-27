#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int k;
    cin>>k;
    int a[5][k];
    int i,j,s;
    for(i=0;i<5;i++)
        for(j=0;j<k;j++)
            cin>>a[i][j];
    double num,sum=0,minum;
    for(s=0;s<k;s++)
    {
        sum=sum+(a[1][s]-a[0][s])*(a[1][s]-a[0][s]);
    }
    minum=sqrt(sum);
    sum=0;
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            for(s=0;s<k;s++)
            {
                sum=sum+(a[j][s]-a[i][s])*(a[j][s]-a[i][s]);
            }
            num=sqrt(sum);
            if(minum>num)
                minum=num;
        }
    }
    cout<<minum<<endl;
}
