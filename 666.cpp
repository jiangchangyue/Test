/*#include<stdio.h>
#include<iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const MAXSIZE=100;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;
}*BiTree;


BiTree Build()
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
		return NULL;
		BiTree tree=new BiTNode;
		tree->data=ch;
		tree->lchild=Build();
		tree->rchild=Build();
	return tree;
}

//������������
void CreateBiTree(BiTree &T)
{
	//����������������������������ַ���������������洢�ṹ
	//ָ��Tָ�������������ĸ����
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;
	else
	{
		T=new BiTNode;//���ɸ����
		T->data=ch;
		CreateBiTree(T->lchild);//�ݹ齨������
		CreateBiTree(T->rchild);//�ݹ齨������
	}
}

//�������������
void BiTreeDepth(BiTree T,int h, int &depth)
{//hΪTָ��Ľ�����ڲ�Σ�Tָ��������ĸ�����h�ĳ�ֵΪ1
	//depthΪ��ǰ��õ�����Σ����ֵΪ0
	if(T)
	{
		if(h>depth) depth=h;
		BiTreeDepth(T->lchild ,h+1,depth);
		BiTreeDepth(T->rchild ,h+1,depth);
	}
}

char tag[100][100];
int m,w=0,deep;
int Levelorder(BiTree tree,int m,int w, int q)
{//��α���
	if(tree)
	{
		if(q==0)
		{
			m=pow(2.0,deep);
			tag[++w][m]=tree->data;
			int ww=w,uu=w,mm=m,nn=m;
			deep--;
			Levelorder(tree->lchild,mm,ww,-1);
			deep++;
			Levelorder(tree->rchild,nn,uu,1);
		}
		else if(q==-1)
		{
			m-=pow(2.0,deep);
			tag[++w][m]=tree->data;
			int ww=w,uu=w,mm=m,nn=m;
			deep--;
			Levelorder(tree->lchild,mm,ww,-1);
			Levelorder(tree->rchild,nn,uu,1);
			deep++;
		}
		else if(q==1)
		{
			m+=pow(2.0,deep)+1;
			tag[++w][m]=tree->data;
			int ww=w,uu=w,mm=m,nn=m;
			deep--;
			Levelorder(tree->lchild,mm,ww,-1);
			Levelorder(tree->rchild ,nn,uu,1);
		}
	}
	return 0;
}
void Levelorder(BiTree tree)
{
    Queue q;
    //��Ϊ�գ�ֱ�ӷ���
    if (tree == NULL)
    {
        exit(-1);
    }
    QueueInit(q);
    //�Ƚ����ڵ����
    QueuePush(q, tree);
    while (QueueEmpty(           q))
    {
        //���ӱ����ͷ������
        BTNode* front = QueueFront(&q);
        printf("%c", front->_data);
        QueuePop(&q);
        //�����ӽ��������������
        if (front->_left)
            QueuePush(&q, front->_left);
        //�����ӽ��������������
        if (front->_right)
            QueuePush(&q, front->_right);
    }
}
int main()
{
	int i,j,d,h,depth;
	char tag[80][80];
	memset(tag,0,sizeof(tag));
	printf("�밴˳��������ĸ(�������ַ�'#'��������ö�����Ϊ����)��");
	BiTree tree=Build();
	d=BiTreeDepth(tree,h,depth);
	printf("�������Ϊ:%d\n",&d);
	Levelorder(tree,m,w,0);
	for(i=0;i<=10;i++)
	{
		for(j=0;j<=64;j++)
		{
			if(tag[i][j])
				printf("%c",tag[i][j]);
			else
				printf(" ");
		}
		
	}
	return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct treeNode{
	treeNode *left;
	treeNode *right;
	char data;
}*TreeNode;
 
typedef struct queueNode{
	TreeNode data;
	queueNode *next;
}*QueueNode;
 
typedef struct queue{
	QueueNode front;
	QueueNode rear;
}*Queue;

void Build(TreeNode &t)
{
	char ch;
	cin>>ch;
	if(ch=='#') {t=NULL;}
	else 
	{
		t=new treeNode;
		t->data=ch;
		Build(t->left);
		Build(t->right);
	}
}
 
Queue init(Queue &q){
	q->front=new queueNode;
	q->front->next=NULL;
	q->rear=q->front;
	return q;
}
 
void Enqueue(Queue &q,TreeNode t){
	QueueNode New=new queueNode;
	New->data=t;
	New->next=NULL;
	q->rear->next=New;
	q->rear=New;
}
 
TreeNode Dequeue(Queue &q){
	QueueNode pTemp=new queueNode;
	pTemp=q->front->next;
	if(pTemp->next==NULL){
		q->rear=q->front;
	}else{
		q->front->next=pTemp->next;
	}
	TreeNode x=pTemp->data;
	free(pTemp);
	return x;
}
 
void LevelOrderBinaryTree(TreeNode t){
	Queue q=new queue;
	q=init(q);
	Enqueue(q,t);
	while(q->rear!=q->front){
		TreeNode x=Dequeue(q);
		cout<<x->data<<" ";
		if(x->left){
			Enqueue(q,x->left);
		}
		if(x->right){
			Enqueue(q,x->right);
		}
	}
}

void inorder_zhong(TreeNode t)
{
	if(t)
	{
		inorder_zhong(t->left);
		cout<<t->data<<" ";
		inorder_zhong(t->right);
	}
}

void inorder_hou(TreeNode t)
{
	if(t)
	{
		inorder_hou(t->left);
		inorder_hou(t->right);
		cout<<t->data<<" ";
	}
}

void BiTreeDepth(TreeNode t,int h, int &depth)
{
	if(t)
	{
		if(h>depth) depth=h;
		BiTreeDepth(t->left ,h+1,depth);
		BiTreeDepth(t->right ,h+1,depth);
	}
}

void print(TreeNode t,int level)
{
	int i=0;
	if(t==NULL)return;
	print(t->right,level+1);
	for(i=0;i<level;i++)
		printf("   ");
	printf("%c\n",t->data);
	print(t->left,level+1);
}

void main(){
	TreeNode t;
	Build(t);
	printf("�����������:");
	LevelOrderBinaryTree(t);
	printf("\n");
	printf("������ȣ�");
	int m=0;
	BiTreeDepth(t,1,m);
	printf("%d\n",m-1);
	printf("����\n");
	print(t,0);
	printf("\n");
}

