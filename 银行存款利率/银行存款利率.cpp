#include<bits/stdc++.h>
int main()
{
	float a,b;
	scanf("%f%f",&a,&b);
	float m=a+(((a*b)/100)-(((a*b)/100)*0.05));
	printf("%.2f\n",m);
	return 0;
}
