#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    char a[15][15];
    while(T--)
    {
        int m=0,n=0;
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<15;j++)
            {
                scanf("%c",&a[i][j]);
            }
        }
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<11;j++)
            {
                if(a[i][j]=='B'&&a[i][j+1]=='B'&&a[i][j+2]=='B'&&a[i][j+3]=='B'&&a[i][j+4]=='B')
                    m=1;
                if(a[i][j]=='W'&&a[i][j+1]=='W'&&a[i][j+2]=='W'&&a[i][j+3]=='W'&&a[i][j+4]=='W')
                    n=1;
                if(i<=11&&a[i][j]=='B'&&a[i+1][j]=='B'&&a[i+2][j]=='B'&&a[i+3][j]=='B'&&a[i+4][j]=='B')
                    m=1;
                if(i<=11&&a[i][j]=='W'&&a[i+1][j]=='W'&&a[i+2][j]=='W'&&a[i+3][j]=='W'&&a[i+4][j]=='W')
                    n=1;
                if(i<=11&&a[i][j]=='B'&&a[i+1][j+1]=='B'&&a[i+2][j+2]=='B'&&a[i+3][j+3]=='B'&&a[i+4][j+4]=='B')
                    m=1;
                if(i<=11&&a[i][j]=='W'&&a[i+1][j+1]=='W'&&a[i+2][j+2]=='W'&&a[i+3][j+3]=='W'&&a[i+4][j+4]=='W')
                    n=1;
            }
        }
        for(int i=0;i<15;i++)
        {
            for(int j=0;j<15;j++)
            {
                if(j>=4&&i<=11&&a[i][j]=='B'&&a[i-1][j-1]=='B'&&a[i-2][j-2]=='B'&&a[i-3][j-3]=='B'&&a[i-4][j-4]=='B')
                    m=1;
                if(j>=4&&i<=11&&a[i][j]=='W'&&a[i+1][j-1]=='W'&&a[i+2][j-2]=='W'&&a[i+3][j-3]=='W'&&a[i+4][j-4]=='W')
                    n=1;
            }
        }
        if(m==1&&n==0)
            printf("Black\n");
        else if(m==0&&n==1)
            printf("White\n");
        else if(m==0&&n==0)
            printf("None\n");
        else if(m==1&&n==1)
            printf("Both\n");
    }
    return 0;
}
