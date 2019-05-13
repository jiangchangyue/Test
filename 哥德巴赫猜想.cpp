#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main()
{
   int a;
   int b,c,d,e,f,g,h;
   while(scanf("%d",&a)!=EOF)
   {
       b=1;
       do
       {
           b=b+1;
           c=a-b;
           f=0,h=0;
           for(int i=2;i<b;i++)
           {
               e=b%i;
               if(!e)
                {
                    f++;
                    break;
                }
           }
           for(int j=2;j<c;j++)
           {
               g=c%j;
               if(!g)
                {
                    h++;
                    break;
                }
           }
       }while(f!=0||h!=0);
       printf("%d+%d\n",b,c);
   } return 0;
}
