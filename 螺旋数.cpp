#include<stdio.h>
void h(int a[300][300],int f,int k);
int m=0;
int main()
{
    int a[300][300];
    int T,i,j,f,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&f);
        h(a,f,0);
        for(j=1;j<=f;j++)
        {
            for(k=0;k<f-j;k++)
                printf(" ");
            for(i=0;i<f+j-2;i++)
                printf("%d ",a[j-1][i]);
            printf("%d",a[j-1][i]);
            printf("\n");
        }
        for(j=f+1;j<2*f;j++)
        {
            for(k=0;k<j-f;k++)printf(" ");
            for(i=0;i<2*f-2-(j-f);i++)
                printf("%d ",a[j-1][i]);
            printf("%d",a[j-1][i]);
            printf("\n");
        }
    }
}
void h(int a[300][300],int f,int k)
{
    int i,j,p=0;
    for(i=k;p<f;i++,p++)
    {
        a[k][i]=m%10;
        m++;
    }
    for(j=k+1,p=1;p<f;p++,j++,i++)
    {
        a[j][i]=m%10;
        m++;
    }
    i=i-2;
    for(p=1;p<f;p++,j++,i--)
    {
        a[j][i]=m%10;m++;
    }
    j--;
    for(p=1;p<f;p++,i--)
    {
        a[j][i]=m%10;
        m++;
    }
    i++;
    j--;
    for(p=1;p<2*f-2;p++,j--)
    {
        a[j][i]=m%10;
        m++;
    }
    f--;
    k++;
    if(f>0)
        h(a,f,k);
    if(f==0)
        m=0;
}
