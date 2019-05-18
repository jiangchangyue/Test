/*#include<iostream>
using namespace std;

int main(){
    int n;
    int maxNum =100000;
    int a[maxNum];
    for(long i=0;i<maxNum;i++){
        if(i==0){
            a[i]=7;
        }else if(i==1){
            a[i] = 11;
        }else{
            a[i] = a[i-1]+a[i-2];
        }
    }
    while(1){
        cin>>n;
    if(a[n]%3==0){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    }

}*/
/*#include<iostream>
#include<stdio.h>
using namespace std;
int F(int n)
    {
        if(n==0)
            return 7;
        else if(n==1)
            return 11;
        else { return F(n-1)+F(n-2);
        }
    }
    int main()
    {
        int n;
while(scanf("%d",&n)!=EOF)
{
    if(F(n)%3==0)
        printf("yes\n");
        else
            printf("no\n");
}
 return 0;
   }*/
   /*#include<iostream>
   #include<stdio.h>
   using namespace std;
   int main()
   {
       int a,b;
       while(1){cin>>a>>b;
       cout<<a+b<<endl;}
       return 0;
   }*/
   #include<iostream>
#include<cmath>
#define N 20
using namespace std;
double det(double a[N][N],int n);
int main()
{
    int steps;
    double arr[N][N];
    double D;
        cout<<"阶数：\n";
        while(cin>>steps&&steps!='#')
  {
        cout<<"输入：\n";
        for(int i=0;i<steps;i++)
            for(int j=0;j<steps;j++)
            cin>>arr[i][j];
        D=det(arr,steps);
        cout<<"结果："<<D<<endl<<endl;
            cout<<"继续 阶数(或输入#结束)：\n";
  }
return 0;
}
double det(double a[N][N],int n)
{
    double D;
    if(n==1){D=a[0][0];return D;}
    if(n==2){D=a[0][0]*a[1][1]-a[0][1]*a[1][0];return D;}
    if(n>=3)
    {
        D=0.0;
        double line1[N];
        double temp[N][N];
        for(int i=0;i<n;i++)
            {line1[i]=a[i][0]*pow(-1,i+2);}
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                temp[i][j]=a[i][j+1];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int r=i;r<n-1;r++)
            {
                for(int c=0;c<n;c++)
                {
                    a[r][c]=temp[r+1][c];
                }
            }
            D+=line1[i]*det(a,n-1);
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n;j++)
                    a[i][j]=temp[i][j];
            }
        }
        return D;
    }
}


