/*#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
int main()
{
    char ch;
    int a;
    while( scanf("%c%d",&ch,&a)!=EOF){
        //;
        fflush(stdin);
        //cin>>ch>>a;
         if(ch=='@') return 0;
         int j = 0;
          for(int i=a;i>0;i--)
                {
                    if(i==a)
                    cout<<setw(i)<<ch<<endl;
                    if(i<(a)&&i>1)
                        {
                          j = j + 2;
                          cout<<setw(i)<<ch<<setw(j)<<ch<<endl;
                        }
                    if(i==1)
                        for(int o=0;o<(2*a-1);o++)
                            cout<<ch;
                }
            cout<<endl<<endl;
    }
    return 0;
}*/
/*#include<stdio.h>
int main()
{
    char ch;
    int a;
    while(scanf("%c%d",&ch,&a)!=EOF)
    {
        //fflush(stdin);
        if(ch=='@') return 0;
        int j=0;
        for(int i=a;i>0;i--)
        {
            if(i==a)
                for(int o=0;o<(a-1);o++)
                printf(" ");
            printf("%c",ch);
            printf("\n");
            /*if(i<a&&i>1)
                for(int p=1;p<(a-1);p++)
                {
                    for(int q=1;q<(a-p);q++)
                        printf(" ");
                    printf("%c",ch);break;
                    j=j+2;
                    for(int r=1;r<j;r++)
                        printf(" ");
                    printf("%c",ch);
                    printf("\n");break;
                }
            if(i==1)
                for(int s=0;s<(2*a-1);s++)
                    printf("%c",ch);
                    printf("\n\n");*//*
        }
    }
}*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,t,k,h,f=0;
    char a;
    while(scanf("%c",&a)!=EOF&&a!='@')
    {

        scanf("%d",&n);
        if(n==1)//��Ϊ���������********
        {
            if(f)
               printf("\n");
            f=1;
            printf("%c\n",a);
            getchar(); //���ջس�����Ҫ��������a�����س��ˡ�
            continue;
        }
        if(f)
           printf("\n");
        f=1;
        t=2*n-1;
        for(i=0;i<t/2;i++)//�����һ�С�
            printf(" ");
        printf("%c\n",a);
        k=t/2;
        h=1;
        if(k>1)
        {
            while(k--)
            {
                for(i=0;i<k;i++)            //�����i��(1<i<n)ǰ��ġ�
                    printf(" ");
                printf("%c",a);
                for(i=0;i<h;i++)            //�����i��(1<i<n)�����
                    printf(" ");
              printf("%c\n",a);
              h+=2;
              if(k==1) //k==1ʱ�Ѿ�ѭ�����ˣ�
                  break;
            }
        }
        for(i=0;i<t;i++)//������һ�С�
            printf("%c",a);
        printf("\n");
        getchar(); //���ջس�����Ҫ��������a�����س��ˡ�
    }
    return 0;
}

