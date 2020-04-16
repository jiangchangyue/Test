#include<iostream>
#include<algorithm>
#include<string.h>
#include<time.h>
#include<vector>
#include<set>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int a=1,b=2;
	swap(a,b);
	cout<<a<<" "<<b<<endl<<endl<<endl;
	
	
	
	int c[10]={1,5,6,9,8,0,4,3,7,2};
	sort(c,c+10);
	for(int i=0;i<10;i++)
		cout<<c[i];
	cout<<endl<<endl<<endl;
	
	
	sort(c,c+10,cmp);
	for(int i=0;i<10;i++)
		cout<<c[i];
	cout<<endl<<endl<<endl;
	
	
	int d[5]={1,2,3,4,5};
	reverse(d,d+5);
	for(int i=0;i<5;i++)
		cout<<d[i];
	cout<<endl<<endl<<endl;
	
	string s="qwer";
	reverse(s.begin(),s.end());
	cout<<s<<endl<<endl<<endl;
	
	
	int e=4,f=6;
	int g=__gcd(e,f);//求最大公约数
	cout<<g<<endl<<endl<<endl; 
	
	
	int o[8]={1,2,4,4,9,12,12,15};
	int pos1=lower_bound(o,o+8,4)-o;//插入有序序列中第一个合适的位置 
	int pos2=upper_bound(o,o+8,4)-o;//插入有序序列中最后一个合适的位置
	cout<<pos1<<" "<<pos2<<endl<<endl<<endl;
	vector<int> h;
	h.push_back(1);
	h.push_back(2);
	h.push_back(4);
	h.push_back(4);
	h.push_back(9);
	h.push_back(12);
	h.push_back(12);
	h.push_back(15);
	vector<int>::iterator it;
	it=lower_bound(h.begin(),h.end(),4);
//	cout<<h[it]<<endl<<endl<<endl;
	
	int l[]={1,2,3};
	do
	{
		cout<<l[0]<<" "<<l[1]<<" "<<l[2]<<endl<<endl<<endl;
	}while(next_permutation(l,l+3));//全排列
	
	
	int m[]={1,3,5,7,9,2,2,2,1,1};
	sort(m,m+10);
	int len=unique(m,m+10)-m;//去重 
	for(int i=0;i<len;i++)
		cout<<m[i]<<" ";
	cout<<endl<<endl<<endl; 
	
	int n[1024];
	for(int i=0;i<1024;i++)
		n[i]=i;
	srand(time(NULL));
	random_shuffle(n,n+1024);//随机打乱 
	for(int i=0;i<1024;i++)
		cout<<n[i]<<" ";
	cout<<endl<<endl<<endl;
}
