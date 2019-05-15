#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int temp[10000],num_place[100000],num[100000];
int nbit,n;

//������������λ��
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
         //�Ƚ������ʼ�������½�Ҫ��¼�ж��ٸ�λ������ͬ�����ֵĸ���
         for(int j=0;j<10;j++)
           num_place[j]=0;

        //t��������ӵ�λ��ʼ����ֵλ����¼����
        for(int j=0;j<n;j++)
        {
            t=(num[j]/radix)%10;
            ++num_place[t];
        }

        //�ۼӣ��������С�����ָ����ж��ٸ�����Ϊ���µ� temp[num_place[t]]=num[j]����
        for(int j=1;j<10;j++)
          num_place[j]+=num_place[j-1];

       //�Ӻ��濪ʼ�ѣ�Ϊʲô�أ��Ҹ��˵��������Ϊ�����ڵ��Ǵ�С��������򣬶�����Ҫ�����λ�������ģ�����
       //������濪ʼ�ҡ�
        for(int j=n-1;j>=0;j--)
        {
            t=(num[j]/radix)%10;
            --num_place[t];//�滻��λ��
            temp[num_place[t]]=num[j];
        }

        radix*=10;
        for(int j=0;j<n;j++)
          num[j]=temp[j];

        for(int j=0;j<n;j++)
        {
            printf("%.*i ",nbit,temp[j]);//�����������ʽ�������ٶȰɡ�����
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
