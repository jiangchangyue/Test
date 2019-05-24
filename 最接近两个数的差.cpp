#include<iostream>
using namespace std;
void insertt(int *a,int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0&&t<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertt(a,n);
    int c[n-1];
    for(int i=0;i<n-1;i++)
    {
        c[i]=a[i+1]-a[i];
    }
    insertt(c,n-1);
    cout<<c[0]<<endl;
}
