#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
char a[2000][500];
struct _bus
{
    char bianhao[6];
    char shoufei[20];
    char xianlu[80][6];
    char huilai[80][6];
}bus[522];
int main()
{
    char str[500];
    FILE *fp;
    fp=fopen("1.1 公汽线路信息.txt","r");
    if(fp==NULL)
        return 0;
    int n=0,i;
    while(fgets(a[n],500,fp)!=NULL)
        n++;
    int k=0,f=0;
    for(i=0;i<n;i++)
    {
        if(a[i][0]=='L')
        {
            strcpy(bus[k].bianhao,a[i]);
            strcpy(bus[k].shoufei,a[i+1]);
            char b[2];
            b[0]=a[i+2][0],b[1]=a[i+2][1];
            if(strncmp(b,"上",2)==0)
            {
                strcpy(str,a[i+2]);
                int m=strlen(str)-1;
                int p=5;
                while(p<m)
                {
                    if(str[p]=='S')
                    {
                        for(int l=0;l<5;l++)
                        {
                            bus[k].xianlu[f][l]=str[p];
                            p++;
                        }
                        f++;
                    }
                    p++;
                }
                p=5;
                f=0;
                strcpy(str,a[i+3]);
                m=strlen(str)-1;
                while(p<m)
                {
                    if(str[p]=='S')
                    {
                        for(int l=0;l<5;l++)
                        {
                            bus[k].huilai[f][l]=str[p];
                            p++;
                        }
                        f++;
                    }
                    p++;
                }
            }
            else if(strncmp(b,"环",2)==0)
            {
                strcpy(str,a[i+2]);
                int m=strlen(str)-1;
                int p=5;
                f=0;
                while(p<m)
                {
                    if(str[p]=='S')
                    {
                        for(int l=0;l<5;l++)
                        {
                            bus[k].xianlu[f][l]=str[p];
                            p++;
                        }
                        f++;
                    }
                    p++;
                }
                for(int j=0;j<f;j++)
                {
                    strcpy(bus[k].huilai[j],bus[k].xianlu[f]);
                    f--;
                }
            }
            else
            {
                strcpy(str,a[i+2]);
                int m=strlen(str)-1;
                int p=0;
                f=0;
                while(p<m)
                {
                    if(str[p]=='S')
                    {
                        for(int l=0;l<5;l++)
                        {
                            bus[k].xianlu[f][l]=str[p];
                            p++;
                        }
                        f++;
                    }
                    p++;
                }
                for(int j=0;j<f;j++)
                {
                    strcpy(bus[k].huilai[j],bus[k].xianlu[f]);
                    f--;
                }
            }
            k++;
        }
        else if(a[i][0]=='T')
        {
            strcpy(bus[k].bianhao,a[i]);
            strcpy(bus[k].shoufei,a[i+1]);
            char b[2];
            b[0]=a[i+2][0],b[1]=a[i+2][1];
            if(strncmp(b,"环",2)==0)
            {
                strcpy(str,a[i+2]);
                int m=strlen(str)-1;
                int p=5;
                f=0;
                while(p<m)
                {
                    if(str[p]=='D')
                    {
                        for(int l=0;l<3;l++)
                        {
                            bus[k].xianlu[f][l]=str[p];
                            p++;
                        }
                        f++;
                    }
                    p++;
                }
                for(int j=0;j<f;j++)
                {
                    strcpy(bus[k].huilai[j],bus[k].xianlu[f]);
                    f--;
                }
            }
            else
            {
                strcpy(str,a[i+2]);
                int m=strlen(str)-1;
                int p=0;
                f=0;
                while(p<m)
                {
                    if(str[p]=='D')
                    {
                        for(int l=0;l<3;l++)
                        {
                            bus[k].xianlu[f][l]=str[p];
                            p++;
                        }
                        f++;
                    }
                    p++;
                }
                for(int j=0;j<f;j++)
                {
                    strcpy(bus[k].huilai[j],bus[k].xianlu[f]);
                    f--;
                }
            }
            k++;
        }
    }
    printf("请依次输入出发点与目的地：\n");
    char c[6],d[6];
    scanf("%s%s",c,d);
    int x=0,y=0,j;
    for(i=0;i<k;i++)
    {
        x=0;
        y=0;
        for(j=0;j<80;j++)
        {
            x=0;
            y=0;
            if(strcmp(c,bus[i].xianlu[j])==0)
            {
                x=j+1;
                for(int w=x;w<80;w++)
                {
                    if(strcmp(d,bus[i].xianlu[w])==0)
                    {
                        y=w+1;
                        break;
                    }
                }
                if(x<y)
                {
                    printf("您可选择的线路有：\n");
                    printf("%s",bus[i].bianhao);
                    printf("共经过%d站\n",y-x+1);
                    if(strncmp(bus[i].bianhao,"T1",1)==0)
                    {
                        printf("共经历%.1f分钟\n",(y-x)*2.5);
                    }
                    else
                        printf("共经历%d分钟\n",(y-x)*3);
                    if(strncmp(bus[i].shoufei,"分段计价。",2)==0)
                    {
                        if((y-x+1)>0&&(y-x+1)<=20)
                            printf("票价1元\n");
                        else if((y-x+1)>20&&(y-x+1)<=40)
                            printf("票价2元\n");
                        else
                            printf("票价3元\n");
                    }
                    else if(strncmp(bus[i].shoufei,"票价3元。",2)==0)
                        printf("票价3元\n");
                    else
                        printf("票价1元\n");
                    break;
                }
            }
            else if(strcmp(c,bus[i].huilai[j])==0)
            {
                x=j+1;
                for(int w=x;w<80;w++)
                {
                    if(strcmp(d,bus[i].xianlu[w])==0)
                    {
                        y=w+1;
                        break;
                    }
                }
                if(x<y)
                {
                    printf("您可选择的线路有：\n");
                    printf("%s",bus[i].bianhao);
                    printf("共经过%d站\n",y-x+1);
                    if(strncmp(bus[i].bianhao,"T1",1)==0)
                    {
                        printf("共经历%.1f分钟\n",(y-x)*2.5);
                    }
                    else
                        printf("共经历%d分钟\n",(y-x)*3);
                    if(strncmp(bus[i].shoufei,"分段计价。",2)==0)
                    {
                        if((y-x+1)>0&&(y-x+1)<=20)
                            printf("票价1元\n");
                        else if((y-x+1)>20&&(y-x+1)<=40)
                            printf("票价2元\n");
                        else
                            printf("票价3元\n");
                    }
                    else if(strncmp(bus[i].shoufei,"票价3元。",2)==0)
                        printf("票价3元\n");
                    else
                        printf("票价1元\n");
                    break;
                }
            }
        }
    }
    fclose(fp);
    return 0;
}
