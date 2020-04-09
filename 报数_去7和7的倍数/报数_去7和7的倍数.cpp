#include<iostream>
using namespace std;
int judge(int i)
{
	while(i)
	{
		int a=i%10;
		i=i/10;
		if(a==7)return 1;
	}
	return 0;
}
int main()
{
	int N;
	cin>>N;
	int *a[102];
	int i=1;
	int j=0;
	int flag=0;
	int a1=0,a2=0,a3=0,a4=0;
	while(1)
	{
		int flag2=0;
		a[j]=new int[4];
		for(int k=0;k<4;k++)
		{
			if((i%7)&&(judge(i)==0))
			{//cout<<i<<" ";
				a[j][k]=i;
				flag++;
				if(flag==N)
				{
					flag2=1;
					break;
				}
			}
			else
			{
				if(k==0)a1++;
				else if(k==1)a2++;
				else if(k==2)a3++;
				else a4++;
			}
			i++;
		}//cout<<endl;
		if(flag2==1)break;
		j++;
	}
	cout<<a1<<endl<<a2<<endl<<a3<<endl<<a4<<endl;
	return 0;
}
