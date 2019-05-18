#include<stdio.h>
#include<string.h>
int ViolentMatch(char* s, char* p)
{
    int sLen = strlen(s);
    int pLen = strlen(p);
    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if (j == pLen)
        return i-j+1;
    else
        return -1;
}
int main()
{
    char a[10],b[10];
    gets(a);
    gets(b);
    int x=ViolentMatch(a,b);
    printf("%d\n",x);
}
