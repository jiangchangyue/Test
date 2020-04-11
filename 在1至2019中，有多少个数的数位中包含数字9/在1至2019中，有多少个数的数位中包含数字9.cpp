#include<iostream>
using namespace std;
int main()
{//在1至2019中，有多少个数的数位中包含数字9？
	int num=0;
	for(int i=1;i<=2019;i++)
	{
		int k=i;
		while(k)
		{
			//cout<<"++++++";
			int j=k%10;
			int t=i;
			k=k/10;
			if(j==9)
			{
				cout<<t<<endl;
				num++;
				break;
			}
		}
	}
	cout<<num<<endl;
}
