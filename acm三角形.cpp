/*#include<stdio.h>
int main()
{
    double m,n,z;
    int c;
    scanf("%d",&c);
    for(int i=0;i<c;i++){
        scanf("%lf%lf%lf",&m,&n,&z);
        if(m+n>z&&m+z>n&&n+z>m)
            printf("YES\n");
        else
            printf("NO\n");
    }return 0;
}*/
#include<stdio.h>
int a[100];
double b[100];
int main()
{
    int m=0;
    for(int i=0;i<4;i++)
        scanf("%d",&a[i]);
    for(int i=3;i>=0;i--)
        printf("%d",a[i]);
    return 0;
}
