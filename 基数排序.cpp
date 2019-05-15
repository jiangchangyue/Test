#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int temp[10000],num_place[100000],num[100000];
int nbit,n;

//计算出最大数的位数
int count_bit()
{
    int max=0,count=0,temp;
    for(int i=0;i<n;i++)
    {
        count=1;
        temp=num[i];
        while(temp>0)
        {
            temp=temp/10;
            count++;
        }
        if(max<count)
            max=count;
    }
    // printf("max=%d\n",max-1);
    return max-1;
}

void RadixSort()
{
    int radix=1,t;
     nbit=count_bit();
  memset(temp,0,sizeof(temp));

     for(int i=1;i<=nbit;i++)
     {
         //先将数组初始化，等下将要记录有多少个位数是相同的数字的个数
         for(int j=0;j<10;j++)
           num_place[j]=0;

        //t用来保存从低位开始的数值位，记录个数
        for(int j=0;j<n;j++)
        {
            t=(num[j]/radix)%10;
            ++num_place[t];
        }

        //累加，计算比它小的数字个数有多少个，是为等下的 temp[num_place[t]]=num[j]操作
        for(int j=1;j<10;j++)
          num_place[j]+=num_place[j-1];

       //从后面开始搜，为什么呢，我个人的理解是因为是现在的是从小到大的排序，而等下要插入的位置是最后的，所以
       //从最后面开始找。
        for(int j=n-1;j>=0;j--)
        {
            t=(num[j]/radix)%10;
            --num_place[t];//替换的位置
            temp[num_place[t]]=num[j];
        }

        radix*=10;
        for(int j=0;j<n;j++)
          num[j]=temp[j];

        for(int j=0;j<n;j++)
        {
            printf("%.*i ",nbit,temp[j]);//如果这个输出格式不懂，百度吧。。。
              //printf("%d ",temp[j]);
        }
        printf("\n");
     }
    return ;
}

int main()
{
     int i;
  while(scanf("%d",&n)==1)
  {
    for(i=0;i<n;i++)
     {
         scanf("%d",&num[i]);
     }

     RadixSort();
}
    return 0;
}
