#include<stdio.h>
struct Y
{
    float a,b,c;
}d[1000],e;
int main()
{
    int i,j,n,m;
    float t=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%f",&d[i].a);
    }
    for(i=0;i<n;i++)
    {
        scanf("%f",&d[i].b);
    }
    for(i=0;i<n;i++)
    {
        d[i].c=d[i].b/d[i].a;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(d[j].c<d[j+1].c)
            {
                e=d[j];
                d[j]=d[j+1];
                d[j+1]=e;
            }
        }
    }
    float p=0;
    int r,k;
    if(m<=d[0].a)
    {
        t=d[0].c*m;
    }
    else
    {
    for(i=0;i<n;i++)
        {
            p=p+d[i].a;
            if(p>=m)
            {
                r=i;
                k=(int)(p-m);
                break;
            }
        }
        for(i=0;i<=r;i++)
        {
            t=t+d[i].b;
        }
        t=t-d[r].c*k;
        /*i=0;
        do
        {
            if(d[i].a>=m)
            {
                t=t+m*d[i].c;
                m=0;
            }
            else
            {
                t=t+d[i].b;
                m=m-d[i].a;
            }
            i++;
            if(i>=n)
                break;
        }while(m);*/
    }
    printf("%.2f\n",t);
    return 0;
}

