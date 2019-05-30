#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int e,f=0,h,m=0,n,x;
        if(a==0&&b==0)
        exit(-1);
        for(int i=a;i<=b;i++)
        {
            x=i;
            while(x>0)
            {
                e=x%10;
                if(e==4)
                {
                    f++;
                    break;
                }
                x=x/10;
                if(x<=0)
                    continue;
                h=x%10;
                if((e==2&&h==6)||h==4)
                {
                    m++;
                    break;
                }
                x=x/10;
            }
        }
        n=b-a-f-m+1;
        printf("%d\n",n);
    }
        return 0;
}
