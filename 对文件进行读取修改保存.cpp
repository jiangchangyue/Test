#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("duru\\caonim.txt","r+");
    if(fp1==NULL)
    {
        exit(-1);
    }
    char a[200];
    fscanf(fp1,"%s",a);
    int t=strlen(a);
    for(int i=0;i<t;i++)
    {
        if(a[i]>='a'&&a[i]<='z')
        {
            a[i]=a[i]-32;
        }
    }
    printf("%s\n",a);
    fclose(fp1);
    fp2=fopen("duchu\\caonim.txt","w");
    if(fp2==NULL)
        exit(-1);
    fprintf(fp2,"%s",a);
    fclose(fp2);
}
