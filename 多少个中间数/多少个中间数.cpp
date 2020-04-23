#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    if(n%2==0)
    {
        if(a[n/2]==a[n/2-1])
        {
        	int i=n/2-2,j=n/2+1;
        	while(i>=0&&j<n)
        	{
        		if(a[i]!=a[j])
        		{
        			if(a[i]!=a[n/2]&&a[j]!=a[n/2])
        			{
        				cout<<a[n/2]<<endl;
        				break;
					}
					else
					{
						cout<<"-1"<<endl;
	        			break;
					}
				}
				i--;
				j++;
			}
			if(i==-1||j==n)cout<<a[n/2]<<endl;
		}
		else 
			cout<<"-1"<<endl;
    }
    else
	{
		if(a[n/2-1]==a[n/2]||a[n/2+1]==a[n/2])
		{
			if(a[n/2-1]==a[n/2+1])
	        {
	        	int i=n/2-2,j=n/2+2;
	        	while(i>=0&&j<n)
	        	{
	        		if(a[i]!=a[j])
	        		{
	        			if(a[i]!=a[n/2]&&a[j]!=a[n/2])
	        			{
	        				cout<<a[n/2]<<endl;
	        				break;
						}
						else
						{
							cout<<"-1"<<endl;
		        			break;
						}
					}
					i--;
					j++;
				}
				if(i==-1||j==n)cout<<a[n/2]<<endl;
			}
			else
				cout<<"-1"<<endl;
		}
		else
			cout<<a[n/2]<<endl;
	}
	return 0;
}
