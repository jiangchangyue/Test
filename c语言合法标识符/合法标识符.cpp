#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *f(char *a)
{
	int len=strlen(a);
	int i;
	int flag=0;
	if(a[0]!='_'&&!(a[0]>='a'&&a[0]<='z'))
	{
		for(i=1;i<len;i++)
		{
			if(a[i]=='_'||(a[i]>='a'&&a[i]<='z'))
			{
				flag=i;
				break;
			}
		}
	}
	for(i=flag;i<flag+len;i++)
	{
		a[i-flag]=a[i];
	}
	len=len-flag;
	int k=0;
	for(i=1;i<len;i++)
	{
		if(a[i]=='_'||(a[i]>='a'&&a[i]<='z')||(a[i]>='0'&&a[i]<='9'))
		{
			continue;
		}
		else
		{
			int j;
			for(j=i;j<len-1;j++)
			{
				a[j]=a[j+1];
			}
			len--;
			i--;
		}
	}
	char *c=(char *)malloc(len*sizeof(char));
	for(i=0;i<len;i++)
	{
		c[i]=a[i];
	}
	return c;
}
int main()
{
	char a[100];
	scanf("%s",a);
	char *b;
	b=f(a);
	printf("%s",b);
	printf("\n");
	return 0;
}
		
