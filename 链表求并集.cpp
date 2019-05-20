#include<stdio.h>
#include<malloc.h>
struct Node
{
    int num;
    struct Node *next;
};
Node *create_linklist()
{
    Node *head,*tail,*pnew;
    int num;
    head=(Node *)malloc(sizeof(Node));
    if(head==NULL)
        exit(-1);
    head->next=NULL;
    tail=head;
    printf("请输入一批数,输入0表示结束：\n");
    while(1)
    {
        scanf("%d",&num);
        if(num<=0)
        break;
        pnew=(Node *)malloc(sizeof(Node));
        if(pnew==NULL)
            exit(-1);
        pnew->num=num;
        pnew->next=NULL;
        tail->next=pnew;
        tail=pnew;
    }
    return (head);
}
void insert_linklist(Node *head,Node *pnew,int i)
{
    Node *p;
    int j;
    p=head;
    for(j=0;j<i&&p!=NULL;j++)
    {
        p=p->next;
    }
    if(p==NULL)
        return;
    pnew->next=p->next;
    p->next=pnew;
}
void delete_linklist(Node *head,int i)
{
    Node *p,*q;
    int j;
    if(i==0)
        return;
    p=head;
    for(j=1;j<i&&p->next!=NULL;j++)
    {
        p=p->next;
    }
    if(p->next==NULL)
        return;
    q=p->next;
    p->next=q->next;
    free(q);
}
void display_linklist(Node *head)
{
    Node *p;
    for(p=head->next;p!=NULL;p=p->next)
        printf("%d ",p->num);
    printf("\n");
}
int listlength(Node *head)
{
    Node *p;
    p=head;
    int k=0;
    while(p)
    {
        p=p->next;
        k++;
    }
    return k;
}
int listdelete(Node *head)
{
    Node *p;
    int j;
    p=head;
    p=p->next;
    j=p->num;
    p=p->next;
    free(p);
    return j;
}
int locateelem(Node *head,int j)
{
    Node *p;
    p=head->next;
    int z=0;
    while(p)
    {
        if(j==(p->num))
            z=1;
        p=p->next;
    }
    return z;
}
int main()
{
    Node *La,*Lb,*pnew;
    La=create_linklist();
    if(La==NULL)
        exit(-1);
        printf("创建的链表为：\n");
        display_linklist(La);
        Lb=create_linklist();
    if(Lb==NULL)
        exit(-1);
        printf("创建的链表为：\n");
        display_linklist(Lb);
        int f;
        f=listlength(Lb);
        Node *p;
        p=Lb->next;
        for(int i=1;i<f;i++)
        {
            int g;
            g=p->num;
            p=p->next;
            int z;
            z=locateelem(La,g);
            if(z==0)
            {
                pnew=(Node *)malloc(sizeof(Node));
                    if(pnew==NULL)
                        exit(-1);
                    pnew->num=g;
                    int k;
                    k=listlength(La);
                        insert_linklist(La,pnew,k-1);
            }

        }
    printf("结果为：");
    display_linklist(La);
}
