#include <stdio.h>
#include <stdlib.h>	
    char huase[4][10]={"红桃","黑桃","方片","梅花"};
	char *dianshu[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"	};
	int hua[4] = {0,1,2,3};
	int dian[13] ;//对应的字符数组都存在相应的数字数组
	int s1=0,s2 = 0;
	int wanjia1[2][15],wanjia2[2][15];//两个玩家
	int mark[2][15] = {0};//对已有牌进行标记
	int w1,w2;//对用户输入进行比较
	int flag=1;//标志变量

	void fapai();
	void shuchu(int p[2][15],int i1,int m[2][15],int i2 );
	int A(int p[2][15],int i);
void main()
{

	int d1,d2;//记录玩家1的首轮发牌点数
	
		for( int i =0;i<12;i++)
		{
			dian[i] = i+1;
			if(i>9)
			dian[i] = 10;
		}
		//首发牌
		printf("游戏开始，发牌开始");
		while(s1<2)
		{
			fapai(wanjia1[2][15],s1);
			d1 = A(wanjia1[2][15],s1);
			printf("您现在的点数为%d",d1);
		}
		while(s2<2)
		{
			fapai(wanjia2[2][15],s2);
			d2= A(wanjia2[2][15],s2);
			printf("您现在的点数为%d",d2);
		}
		while(flag)
		{
			void shuchu(wanjia1[2][15],s1,wanjia2[2][15],s2);
		}
}


int fapai(int p[2][15],int i)//指针传递，把发过的牌记录在二维数组里
{
	int m,n;
	while(1)
	{
		m = rand()%4; 
		n = rand()%13;
	if(mark[m][n]==0)
	{
		p[0][i] =  hua[m];
		p[1][i] = dian[n];
		printf("您现在的牌为%s%s/n",huase[m],dianshu[n]);
		return dian[n];
		mark[m][n] = 1;
		i++;
		break;
	}
	else
		continue;	
	
}
//判断a为几的函数
int A(int p[2][15],int i)//p代表玩家，i代表已有牌数
{
	int a=0;
	int k =0;
	int n;
	int m ;
	for(m =0;m<i;m++)
	{
		a=a+p[1][m];
		if(p[1][m] == 1)
			k = k+1;//k记录有几张a牌
	}
    if(a+10K>21)
		n = a+10k-10;
	else 
		n= a+10k;
	if(a+10k>31)
		n =a+10k-20;
	else
		 n = a+10k-10;
	if(a+10k>41)
		n=a+10k-30;
	else
		n = a+10k-20;
	if(a+10k>51) 
		n=a+10k-40; 
	else
		n = a+10k-30;
	return n;//设置A初始化值为十一，返回牌的点数
}
//人机交互，输出部分。
void shuchu(int p[2][15],int i1,int m[2][15],int i2 )
{
	int m,n,o,j;   
	printf("请玩家1输入您的选择，0代表不继续要牌，1代表要牌/n");
	scanf("%d",&m);
	if(m==1)
	{
		fapai(p[2][15],i1);
		n = A(p[2][15],i1)
		printf("您现在的点数为%d",n);
		if(n>21)
			printf("对不起，您爆牌了~ ~ ~");
		    n =0;
	}
	else
	{
		n = A(p[2][15],i1);
		printf("此轮您选择不要牌，您的点数为%d",n);
	}
	printf("请玩家2输入您的选择");
	scanf("%d",&o);
	if(o==1)
	{
		fapai(m[2][15],i2);
		j = A(w[2][15],i2);
		printf("您现在的点数为"%d");
			if(j>21)
				printf("对不起您爆牌了~ ~ ~");
			    j =0;
	}
	else
	{
		j = A(w[2][15],i2);
		printf("您选择放弃要牌,您现在的点数为%d",j);
	}
	if(o==0&&m==0)
	{
		printf("两位玩家均选择放弃，游戏结束");
		if(n>j)
			printf("赢家为玩家1");
		else if(j>n)
			printf("赢家为玩家2");
		else
			printf("玩家一二平局");
		flag =0；
		return 0;
	}
	


}
//逻辑部分，要牌的几种情况



    





	 


