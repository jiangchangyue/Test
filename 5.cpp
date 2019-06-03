#include<stdio.h>
#include<stdlib.h>
const int MAXSIZE=1000;

typedef struct{
	int i,j;//行下标，列下标
	int e;//该非零元的元素值
}Triple;

typedef struct{
	Triple data[MAXSIZE+1];//非零元三元组表
	int m,n,len;//矩阵的行数、列数和非零元素个数
}TSMatrix;

void InitTriple(TSMatrix *T)
{
	T->m=100;
	T->n=100;
	T->len=0;
}

void EnterTriple(TSMatrix *T,int i,int j,int e)
{
	T->data[T->len].i=i;
	T->data[T->len].j=j;
	T->data[T->len].e=e;
	T->len++;
}

void TraverseTriple(TSMatrix *T)
{
	int w;
	for(w=0;w<T->len;w++)
	{
	  printf("%d %d %d\n",T->data[w].i,T->data[w].j,T->data[w].e);
	}
}

void SumTriple(TSMatrix *A,TSMatrix *B,TSMatrix *C)
{
	int x=0,y=0;
	while(x<A->len&&y<B->len)
	{
		if(A->data[x].i<B->data[y].i)
		{
			EnterTriple(C,A->data[x].i,A->data[x].j,A->data[x].e);
			x++;
		}//if(A->data[x].i<B->data[y].i)
		 else if(A->data[x].i==B->data[y].i)
		 {
				 if(A->data[x].j<B->data[y].j)
				 {
                 	EnterTriple(C,A->data[x].i,A->data[x].j,A->data[x].e);
					x++;
				 }
				 else if(A->data[x].j==B->data[y].j)
				 {
					 EnterTriple(C,A->data[x].i,A->data[x].j,A->data[x].e+B->data[y].e);
					 x++;
					 y++;
				 }
				 else if(A->data[x].j>B->data[y].j)
				 {
					 EnterTriple(C,B->data[x].i,B->data[x].j,B->data[x].e);
					 y++;
				 }
		
		 }//else if(A->data[x].i==B->data[y].i)
		 else if(A->data[x].i>B->data[y].i)
		 {
			 EnterTriple(C,B->data[y].i,B->data[y].j,B->data[y].e);
			 y++;
		 }
	}//while
	while(x<A->len)
	{
		EnterTriple(C,A->data[x].i,A->data[x].j,A->data[x].e);
		x++;
	}
	while(y<B->len)
	{
		EnterTriple(C,B->data[y].i,B->data[y].j,B->data[y].e);
		 y++;
	}
}//void

int main()
{
	int x,xn,y,yn;
	int i,j,e;
	TSMatrix A,B,C;
	InitTriple(&A);
	InitTriple(&B);
	InitTriple(&C);

	printf("please input the numbers of A:");
	scanf("%d",&xn);
	for(int k=0;k<xn;k++)
	{
		printf("please input A:");
		scanf("%d%d%d",&i,&j,&e);
		EnterTriple(&A,i,j,e);
	}

	printf("please input the numbers of B:");
	scanf("%d",&yn);
	for(int t=0;t<yn;t++)
	{
		printf("please input B:");
		scanf("%d%d%d",&i,&j,&e);
		EnterTriple(&B,i,j,e);
	}

	SumTriple(&A,&B,&C);
	TraverseTriple(&C);
	return 0;
}