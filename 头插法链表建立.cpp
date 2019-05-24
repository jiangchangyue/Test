#include<stdio.h>
#include<stdlib.h>
struct Data
{
    int num;
    struct Data *next;
};
int main()
{
    int data,i;
    struct Data *head,*p;
    head=(struct Data *)malloc(sizeof(struct Data));
    head->next=NULL;
    for(i=0;i<10;i++)
    {
        scanf("%d",&data);
        p=(struct Data *)malloc(sizeof(struct Data));
        p->num=data;
        p->next=head->next;
        head->next=p;
    }
    while(p)
    {
        printf("%d ",p->num);
        p=p->next;
    }
}
