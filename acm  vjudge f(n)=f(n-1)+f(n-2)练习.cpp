/*#include<stdio.h>
int main()
{
    int n,i,a,b,c;
    while(scanf("%d",&n)!=EOF)
    {
        a=7;
        b=11;
    }
}
/*#include<stdio.h>
int main()
{
int n,i,a,b,c;
while(scanf("%d",&n)!=EOF)
{
a=1;
b=2;
c=3;
for(i=2;i<=n;i++)
{
c=(a+b)%3;
a=b;
b=c;
}
if(c==0)
puts("yes");
else
puts("no");

}
return 0;
}*/
/*#include<stdio.h>
int mod3( int x )
{
    int a,b,c,i;
    if( x == 0 )
        return 7 % 3;
    else if( x == 1 )
        return 11 % 3;
    else
    {
        a = 7; b = 11;
        while( --x > 0 )
        {
            c = ( a + b ) % 3;
            a = b;
            b = c;
        }
        return c % 3;
    }
}
int main( void )
{
    int input;
    while( scanf( "%d", &input ) != EOF )
        if( mod3( input ) == 0 )
            printf( "yes\n" );
        else
            printf( "no\n" );
    return 0;
}*/
#include<stdio.h>
int main()
{
    float a,b;
    scanf("%f%f",&a,&b);
    printf("%f %f",a,b);
    if(a==b)
        printf("yes");
}
