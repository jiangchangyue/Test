/*#include<iostream>
using namespace std;
int main()
{
	int a=5;
	while(a)
	{
		int c=a&1;
		cout<<c<<endl;
		a=a>>1;
	}
}*/


#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  long long a,b;
  //scanf("%l64d%l64d",&a,&b);
  cin>>a>>b;
  long long c=a+b;
  int flag=0;
  if(c>0)flag=1;
  int q[10000]={0};
  int k=-1;
  if(c==0)
  	{
  	  cout<<"0"<<endl;
  	  exit(1);
  	}
  while(c)
  {
    q[++k]=abs(c%10);
    c=c/10;
  }
  if(flag==0)
    printf("-");
    int d;
  for(int j=k,d=1;j>=0;j--,d++)
  {
    //printf("%lld",q[j]);
    cout<<q[j];
    if(d%3==0&&j)
      //printf(",");
      cout<<",";
  }
}
