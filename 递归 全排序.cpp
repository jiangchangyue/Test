#include<stdio.h>
#include<memory.h>
void find(int k);
int num[3]={7,8,9};
int pos[3];
int main()
{
    memset(pos,0,sizeof(pos));
    find(0);
}
void find(int k)
{
    int i;
    if(k==3)
    {
        printf("%d%d%d\n",pos[0],pos[1],pos[2]);
        return;
    }
    for(i=0;i<3;i++)
    {
        if(pos[i]==0)
        {
            pos[i]=num[k];
            find(k+1);
            pos[i]=0;
        }
    }
}
