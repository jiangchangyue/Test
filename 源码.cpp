#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int M;
char a1[] = "Serial";
char a2[] = ".println(\"";
char b[] = "\");";
char c[] = "delay(";
char d[] = ");";

void main()
{
	char str[400][400];
	char nu[400][5];
	int num[400];
	int x, n, i, j, k;

	scanf("%d",&x);

	scanf("%d",&n);

	FILE *fp;

	fp = fopen("data.txt","r");

	if (fp == NULL)
	{
		printf("文件不存在!\n");
		exit(0);
	}
	
	for(i = 0; i < 400; i++)
	{
		fscanf(fp,"%s",&str[i]);
		if(str[i][0] != '#')
			break;
	}
    
	M = i;

	fclose(fp);

	for(i = 0; i < M; i++)
	{
		for(j = 0; str[i][j] != 'T'; j++);
		j++;
		for(k = 0; str[i][j] != '\0'; j++,k++)
			nu[i][k] = str[i][j];
		nu[i][k] = '\0';
	}
	
	for(i = 0; i < M; i++)
	{
		num[i] = atoi(nu[i]);
		num[i] = num[i]*n/1000;
	}

	//输出数据
	fp = fopen("output.txt","w");
	if (fp == NULL)
	{
		printf("文件不存在!\n");
		exit(0);
	}

	for (i = 0;i < M; i++)
	{
		if(x != -1)
		{
		fprintf(fp,"%s",a1);
		fprintf(fp,"%d",x);
		fprintf(fp,"%s",a2);
		for(j = 0; str[i][j] != 'T'; j++)
			fprintf(fp,"%c",str[i][j]);
		fprintf(fp,"%c",str[i][j]);
		fprintf(fp,"%d",num[i]);
		fprintf(fp,"%s\n",b);
		fprintf(fp,"%s",c);
		fprintf(fp,"%d",num[i]);
		fprintf(fp,"%s\n",d);
		}

		if(x == -1)
		{
		fprintf(fp,"%s",a1);
		fprintf(fp,"%s",a2);
		for(j = 0; str[i][j] != 'T'; j++)
			fprintf(fp,"%c",str[i][j]);
		fprintf(fp,"%c",str[i][j]);
		fprintf(fp,"%d",num[i]);
		fprintf(fp,"%s\n",b);
		fprintf(fp,"%s",c);
		fprintf(fp,"%d",num[i]);
		fprintf(fp,"%s\n",d);
		}

	}
	fclose(fp);
}