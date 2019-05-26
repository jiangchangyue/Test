#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct node
{
    int adjvex;
    struct node *next;
}EdgeNode;
typedef struct vnode
{
    int vertex;
    EdgeNode *firstedge;
}VertexNode;
void CreateAdjlist(VertexNode g[],int e,int n)
{
    EdgeNode *p;
    int i,j,k;
    printf("Input data of vetex(0~n-1);\n");
    for(i=1;i<=n;i++)
    {
        g[i].vertex=i;
        g[i].firstedge=NULL;
    }
    for(k=1;k<=e;k++)
    {
        printf("Input edge of(i,j):");
        scanf("%d%d",&i,&j);
        p=(EdgeNode*)malloc(sizeof(EdgeNode));
        p->adjvex=j;
        p->next=g[i].firstedge;
        g[i].firstedge=p;
        p=(EdgeNode*)malloc(sizeof(EdgeNode));
        p->adjvex=i;
        p->next=g[j].firstedge;
        g[j].firstedge=p;
    }
}
void AdlistPrint(VertexNode g[],int n)
{
    int i;
    EdgeNode *p;
    for(i=1;i<=n;i++)
    {
        p=g[i].firstedge;
        printf("%d:",g[i].vertex);
        while (p!=NULL)
        {
            printf("%d->",p->adjvex);
            p=p->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    VertexNode g[MAXSIZE];
    CreateAdjlist(g,4,4);
    AdlistPrint(g,4);
    return 0;
}
