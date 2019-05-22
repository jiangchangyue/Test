#include<iostream>
using namespace std;
char a[100];
int sed;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int z1=0,z2=0,z3=0;
        int flag=0;
        cin>>a;
        cin>>sed;
        int shi=sed/3600;
        sed=sed%3600;
        int fen=sed/60;
        sed=sed%60;
        int miao=sed%60;
        int shi1=(a[0]-'0')*10+(a[1]-'0');
        int fen1=(a[3]-'0')*10+(a[4]-'0');
        int miao1=(a[6]-'0')*10+(a[7]-'0');
        z1=(miao1+miao)/60;
        miao1=(miao1+miao)%60;
        fen1=fen1+z1+fen;
        z2=fen1/60;
        fen1=fen1%60;
        shi1=shi1+shi+z2;
        flag=shi1/24;
        shi1=shi1%24;
        printf("%02d:%02d:%02d +%dd\n",shi1,fen1,miao1,flag);
    }
    return 0;
}
