#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[110];
	cin>>a;
	int len=strlen(a);
	int num=1;
	if(a[0]=='a'||a[0]=='e'||a[0]=='i'||a[0]=='o'||a[0]=='u')
	{
		cout<<"no"<<endl;
		return 0;
	}
	for(int i=1;i<len;i++)
	{
		//cout<<a[i-1]<<"++"<<a[i]<<endl;
		if((a[i-1]!='a'&&a[i-1]!='e'&&a[i-1]!='i'&&a[i-1]!='o'&&a[i-1]!='u')&&(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'))
		{
			num++;
			//cout<<num<<"*"<<endl;
		}
		else if((a[i-1]=='a'||a[i-1]=='e'||a[i-1]=='i'||a[i-1]=='o'||a[i-1]=='u')&&(a[i]!='a'&&a[i]!='e'&&a[i]!='i'&&a[i]!='o'&&a[i]!='u'))
		{
			num++;
			//cout<<num<<"**"<<endl;
		}
	}
	if(num==4)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;	
}
