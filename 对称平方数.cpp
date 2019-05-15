#include<iostream>
using namespace std;
int judge(int *a)
{
    int size=sizeof(a)/sizeof(a[0]);
    int i=0,j=size-1;
    while(i<j)
    {
        if(a[i]!=a[j])
            break;
        i++;
        j--;
    }
    if(i==j) return 1;
    else return 0;
}
int *arry(int d)
{
    int a[10],i=0;
    while(d>0)
    {
        a[i]=d%10;
        d=d/10;
        i++;
    }
    for(int j=0;j<sizeof(a)/sizeof(int);j++)
        {
            //cout<<a[j]<<endl;
        }
    return a;
}
int main()
{
    int *b;
    for(int i=1;i<256;i++)
    {

        b=arry(i*i);
        for(int j=0;j<sizeof(b)/sizeof(int);j++)
        {
            cout<<b[j]<<endl;
        }
        //if(judge(b)==1)
            //cout<<i<<endl;
    }
    return 0;
}
