#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double *p;
    p=new double [n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(p[j]>p[j+1])
            {
                double t;
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        double m;
        m=(p[i]+p[i+1])/2;
        p[i+1]=m;
    }
    cout<<(int)p[n-1]<<endl;
}
