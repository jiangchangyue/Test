#include<iostream>
using namespace std;
struct A
{
    char a[5]={0};
    int x,y;
    float m;
};
int main()
{
    int n;
    cin>>n;
    A *p;
    p=new struct A [n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
            cin>>p[i].a[j];
        cin>>p[i].x>>p[i].y;
    }
    for(int i=0;i<n;i++)
    {
        p[i].m=p[i].x*p[i].x+p[i].y*p[i].y;
    }
    float max=0,min=200;
    int ma,mi;
    for(int i=0;i<n;i++)
    {
        if(p[i].m>max)
        {
            max=p[i].m;
            ma=i;
        }
        if(p[i].m<min)
        {
            min=p[i].m;
            mi=i;
        }
    }
     cout<<p[mi].a<<' ';
     cout<<p[ma].a<<endl;
}
