#include<stdio.h>
#include<string.h>
void GetNext(char* p,int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
int KmpSearch(char* s, char* p)
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    int next[pLen];
    GetNext(p,next);
    while (i < sLen && j < pLen)
    {
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j + 1;
    else
        return -1;
}
int main()
{
    char a[10],b[10];
    gets(a);
    gets(b);
    int x=KmpSearch(a,b);
    printf("%d\n",x);
}

