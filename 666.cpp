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

//建立二叉链表
void CreateBiTree(BiTree &T)
{
	//在先序遍历二叉树过程中输入结点字符，建立二叉链表存储结构
	//指针T指向所建二叉树的根结点
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;
	else
	{
		T=new BiTNode;//生成根结点
		T->data=ch;
		CreateBiTree(T->lchild);//递归建左子树
		CreateBiTree(T->rchild);//递归建右子树
	}
}

//求二叉树的树深
void BiTreeDepth(BiTree T,int h, int &depth)
{//h为T指向的结点所在层次，T指向二叉树的根，则h的初值为1
	//depth为当前求得的最大层次，其初值为0
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
{//层次遍历
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
    //树为空，直接返回
    if (tree == NULL)
    {
        exit(-1);
    }
    QueueInit(q);
    //先将根节点入队
    QueuePush(q, tree);
    while (QueueEmpty(           q))
    {
        //出队保存队头并访问
        BTNode* front = QueueFront(&q);
        printf("%c", front->_data);
        QueuePop(&q);
        //将出队结点的左子树根入队
        if (front->_left)
            QueuePush(&q, front->_left);
        //将出队结点的右子树根入队
        if (front->_right)
            QueuePush(&q, front->_right);
    }
}
int main()
{
	int i,j,d,h,depth;
	char tag[80][80];
	memset(tag,0,sizeof(tag));
	printf("请按顺序输入字母(若输入字符'#'，则表明该二叉树为空树)：");
	BiTree tree=Build();
	d=BiTreeDepth(tree,h,depth);
	printf("树的深度为:%d\n",&d);
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
	printf("层序遍历如下:");
	LevelOrderBinaryTree(t);
	printf("\n");
	printf("树的深度：");
	int m=0;
	BiTreeDepth(t,1,m);
	printf("%d\n",m-1);
	printf("树：\n");
	print(t,0);
	printf("\n");
}

