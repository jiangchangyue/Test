#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *p;
    p=new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int t=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                j++;
                if(j>=n)
                    break;
            }
            t=t+(p[i]*10+p[j]);
        }
    }
    cout<<t<<endl;
}
