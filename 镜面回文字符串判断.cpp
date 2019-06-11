#include<iostream>
#include<string.h>
using namespace std; 
char a[100],b[100];
int main()
{
	while(cin>>a)
	{
		int flag1=0,flag2=0;
		int len=strlen(a);
		int i,j;
		i=0,j=len-1;
		while(i<=j)
		{
			if((a[i]=='0'&&a[j]=='O')||(a[i]=='O'&&a[j]=='0'))
			{
				i++;
				j--;
				continue;
			}
			if(a[i]!=a[j])
				break;
			i++;
			j--;
		}
		if(i>=j)
			flag1=1;
		j=len-1;
		for(i=0;i<len;i++)
		{
			if(a[i]=='B'||a[i]=='C'||a[i]=='D'||a[i]=='F'||a[i]=='G'||a[i]=='K'||a[i]=='N'||a[i]=='P'||a[i]=='Q'||a[i]=='R'||a[i]=='4'||a[i]=='6'||a[i]=='7'||a[i]=='9')
               break;
            if(a[i]=='E')
				b[j--]='3';
			else if(a[i]=='J')
				b[j--]='L';
			else if(a[i]=='L')
				b[j--]='J';
			else if(a[i]=='S')
				b[j--]='2';
			else if(a[i]=='Z')
				b[j--]='5';
			else if(a[i]=='2')
				b[j--]='S';
			else if(a[i]=='3')
				b[j--]='E';
			else if(a[i]=='5')
				b[j--]='Z';
			else if(a[i]=='0')
				b[j--]='O';
			else if(a[i]=='O')
				b[j--]='0';
			else b[j--]=a[i];
		}
		for(i=0;i<len;i++)
		{
			if((a[i]=='0'&&b[i]=='O')||(a[i]=='O'&&b[i]=='0'))
				continue;
			if(a[i]!=b[i])
				break;
		}
		if(i==(len))
			flag2=1;
		if(flag1==1&&flag2==1)
			cout<<a<<" -- is a mirrored palindrome."<<endl<<endl;
		else if(flag1==1&&flag2==0)
			cout<<a<<" -- is a regular palindrome."<<endl<<endl;
		else if(flag1==0&&flag2==1)
			cout<<a<<" -- is a mirrored string."<<endl<<endl;
		else if(flag1==0&&flag2==0)
			cout<<a<<" -- is not a palindrome."<<endl<<endl;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	return 0;
}

