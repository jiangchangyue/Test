#include<iostream>
#include<math.h>
using namespace std;
int main()
{//1200000�ж��ٸ�Լ��
	int num=0;
	for(int i=1;i<=1200000/2;i++)
	{
		if(1200000%i==0)
		{
			num++;
			cout<<i<<endl;
		}
	} 
	cout<<num<<"**"<<endl;
	return 0;
}
