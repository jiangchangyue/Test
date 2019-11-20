#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define OK 1
#define FALSE -1
#define TRUE 1
#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;
#define MAXQSIZE 10;

typedef int SElemType;
typedef struct
{
SElemType *elem;
int top;
int base;
int down;
int stacksize;
int length;
//int incrementsize;
}SqStack;

void InitStack_Sq(SqStack &S)
{//������ջ
int maxsize=STACK_INIT_SIZE;
//int incresize=STACKINCREMENT;
S.elem=new int[maxsize];
S.top=0;
S.base=99;
S.down=1;
S.stacksize=maxsize;
S.length=0;
//S.incrementsize=incresize;
}

void GetTop_Sq(SqStack S,SElemType &e)
{//�õ�ջ��Ԫ�ص�ֵ������e����
if(S.top==0) exit(-1);
e=S.elem[S.top];
}

void Pop_Sq_top(SqStack &S,SElemType &e)
{//��ջ
if(S.top==0)
 exit(-1);
e=S.elem[S.top--];
S.length--;
}
void Pop_Sq_base(SqStack &S,SElemType &e)
{//��ջ
if(S.base==0)
exit(-1);
e=S.elem[++S.base];
}

int StackLength(SqStack S)
{//����S��Ԫ�ظ���
	return S.length;
}

void Push_Sq_top(SqStack &S,SElemType e)
{//��ջ
if(S.top==S.stacksize)
exit(-1);
S.elem[++S.top]=e;
S.length++;
}
void Push_Sq_base(SqStack &S,SElemType e)
{//��ջ
if(S.base==S.top)
exit(-1);
S.elem[S.base--]=e;
}

typedef int QElemType;
const int QUEUE_INIT_SIZE=100;

typedef struct{
QElemType *elem;
int front;
int rear;
int queuesize;
}SqQueue;

void InitQueue_Sq(SqQueue &Q,int maxsize=QUEUE_INIT_SIZE)
{
Q.elem=new QElemType[maxsize+1];
Q.queuesize=maxsize+1;
Q.front=Q.rear=0;
}//InitQueue_Sq

void EnQueue_Sq(SqQueue &Q,QElemType e)
{
Q.elem[Q.rear]=e;
Q.rear=(Q.rear+1)%Q.queuesize;
}//EnQueue_Sq

int DeQueue_Sq(SqQueue &Q,QElemType &e)
{
if(Q.front==Q.rear)
return FALSE;
e=Q.elem[Q.front];
Q.front=(Q.front+1)%Q.queuesize;
return TRUE;
}//DeQueue_Sq

int QueueEmpty_Sq(SqQueue Q)
{
if(Q.front==Q.rear)
return (1);
else
return (0);
}//QueueEmpty


int GetHead_Sq(SqQueue Q,QElemType &e)
{
if(Q.front==Q.rear)
return FALSE;
e=Q.elem[Q.front];
return e;
}// GetHead_Sq

int QueueLength(SqQueue Q)
{//���ض���Ԫ�ظ���
	return Q.rear-Q.front;
}

int StackTraverse(SqStack S)
{//��ջ�׵�ջ���������Ԫ��
printf("Garage status ( %d cars ):\n",StackLength(S));
printf("___________________________\n");
printf(" ");
while(S.top>=S.down)
{
	printf("%d ",S.elem[S.down++]);
}
printf("\n___________________________\n");
return OK;
}

int QueueTraverse(SqQueue Q)
{//�Ӷ������������Ԫ��
int i;
printf("Sidewak status (%d cars):\n",QueueLength(Q));
printf("___________________________\n");
printf(" ");
i=Q.front;
while(i!=Q.rear)
{
	printf("%d ",Q.elem[Q.front++]);
i=(i+1)%MAXQSIZE;
}
printf("\n___________________________\n");
return OK;
}

void DestroyStack(SqStack &S)
{
	S.top=0;
	S.base=0;
	delete []S.elem;
}

void DestroyQueue(SqQueue &Q)
{
	Q.front=NULL;
	Q.rear=NULL;
	delete []Q.elem;
}

int main()
{
	int a=0,b=0;
	char c;
	int no=1;//����
	SqStack S;
	SqQueue Q;

	InitStack_Sq(S);//������ջ
	InitQueue_Sq(Q);//��������
	printf("Garage status ( %d cars ):\n",a);
	printf("___________________________\n");
	printf("\n");
	printf("___________________________\n");
	printf("Sidewak status (%d cars):\n",b);
	printf("___________________________\n");
	printf("\n");
	printf("___________________________\n");
	printf("Input your order follow the instruction bellow");
	printf("   (Garage capacity: 5. Sidewalk capacity: 5)\n");
	printf("   I:In\n");
	printf("   O:Out\n");
	printf("   X:Exit\n");
	while(1)
	{

		a=StackLength(S);//aΪ��ջ��Ԫ�صĸ���
		b=QueueLength(Q);//bΪ������Ԫ�صĸ���
		printf("Input your order:");
		//fflush(stdin);
		//scanf("%c",&c);
		cin>>c;
		if(c=='I')
		{//�û�Ҫͣ��
			if(a<5)
			{
				Push_Sq_top(S,no++);
				StackTraverse(S);
				QueueTraverse(Q);
			}
			else if(a>=5&&b<5)
			{
				EnQueue_Sq(Q,no++);
				StackTraverse(S);
				QueueTraverse(Q);
			}
			else if(b>=5)
				printf("FULL!\n");
		}

		else if(c=='O')
		{//�û�Ҫ����
			int s;
			printf("ѡ��Ҫ�����ĳ���\n");
			scanf("%d",&s);
		if(a==0||s<1)
		printf("ERROR!");
		else
		{
			int e=0,f=0;
			GetTop_Sq(S,e);
				if(s==e)
				{
					Pop_Sq_top(S,f);
					DeQueue_Sq(Q,e);
					Push_Sq_top(S,e);
					StackTraverse(S);
					QueueTraverse(Q);
				}
				else
				{
					while(1)
					{
						Pop_Sq_top(S,f);
						Push_Sq_base(S,f);
						GetTop_Sq(S,e);
						if(s==e)
						{
							Pop_Sq_top(S,f);
							while(S.base<99)
							{
								Pop_Sq_base(S,e);
								Push_Sq_top(S,e);
							}
							DeQueue_Sq(Q,e);

							Push_Sq_top(S,e);
							StackTraverse(S);
							QueueTraverse(Q);
							break;
						}
					}
				}
		}
		}
		else if(c=='X')
		{//��������
		printf("������");
		break;
		}
		}
	DestroyStack(S);//�ݻٶ�ջ
	DestroyQueue(Q);//�ݻٶ���
}
