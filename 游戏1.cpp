#include <stdio.h>
#include <stdlib.h>	
    char huase[4][10]={"����","����","��Ƭ","÷��"};
	char *dianshu[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"	};
	int hua[4] = {0,1,2,3};
	int dian[13] ;//��Ӧ���ַ����鶼������Ӧ����������
	int s1=0,s2 = 0;
	int wanjia1[2][15],wanjia2[2][15];//�������
	int mark[2][15] = {0};//�������ƽ��б��
	int w1,w2;//���û�������бȽ�
	int flag=1;//��־����

	void fapai();
	void shuchu(int p[2][15],int i1,int m[2][15],int i2 );
	int A(int p[2][15],int i);
void main()
{

	int d1,d2;//��¼���1�����ַ��Ƶ���
	
		for( int i =0;i<12;i++)
		{
			dian[i] = i+1;
			if(i>9)
			dian[i] = 10;
		}
		//�׷���
		printf("��Ϸ��ʼ�����ƿ�ʼ");
		while(s1<2)
		{
			fapai(wanjia1[2][15],s1);
			d1 = A(wanjia1[2][15],s1);
			printf("�����ڵĵ���Ϊ%d",d1);
		}
		while(s2<2)
		{
			fapai(wanjia2[2][15],s2);
			d2= A(wanjia2[2][15],s2);
			printf("�����ڵĵ���Ϊ%d",d2);
		}
		while(flag)
		{
			void shuchu(wanjia1[2][15],s1,wanjia2[2][15],s2);
		}
}


int fapai(int p[2][15],int i)//ָ�봫�ݣ��ѷ������Ƽ�¼�ڶ�ά������
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
		printf("�����ڵ���Ϊ%s%s/n",huase[m],dianshu[n]);
		return dian[n];
		mark[m][n] = 1;
		i++;
		break;
	}
	else
		continue;	
	
}
//�ж�aΪ���ĺ���
int A(int p[2][15],int i)//p������ң�i������������
{
	int a=0;
	int k =0;
	int n;
	int m ;
	for(m =0;m<i;m++)
	{
		a=a+p[1][m];
		if(p[1][m] == 1)
			k = k+1;//k��¼�м���a��
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
	return n;//����A��ʼ��ֵΪʮһ�������Ƶĵ���
}
//�˻�������������֡�
void shuchu(int p[2][15],int i1,int m[2][15],int i2 )
{
	int m,n,o,j;   
	printf("�����1��������ѡ��0��������Ҫ�ƣ�1����Ҫ��/n");
	scanf("%d",&m);
	if(m==1)
	{
		fapai(p[2][15],i1);
		n = A(p[2][15],i1)
		printf("�����ڵĵ���Ϊ%d",n);
		if(n>21)
			printf("�Բ�����������~ ~ ~");
		    n =0;
	}
	else
	{
		n = A(p[2][15],i1);
		printf("������ѡ��Ҫ�ƣ����ĵ���Ϊ%d",n);
	}
	printf("�����2��������ѡ��");
	scanf("%d",&o);
	if(o==1)
	{
		fapai(m[2][15],i2);
		j = A(w[2][15],i2);
		printf("�����ڵĵ���Ϊ"%d");
			if(j>21)
				printf("�Բ�����������~ ~ ~");
			    j =0;
	}
	else
	{
		j = A(w[2][15],i2);
		printf("��ѡ�����Ҫ��,�����ڵĵ���Ϊ%d",j);
	}
	if(o==0&&m==0)
	{
		printf("��λ��Ҿ�ѡ���������Ϸ����");
		if(n>j)
			printf("Ӯ��Ϊ���1");
		else if(j>n)
			printf("Ӯ��Ϊ���2");
		else
			printf("���һ��ƽ��");
		flag =0��
		return 0;
	}
	


}
//�߼����֣�Ҫ�Ƶļ������



    





	 


