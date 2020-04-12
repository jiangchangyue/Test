#include<stdio.h>
#include "h1.h"
void p22();
void p1()
{
	h1();
	printf("this is p1! I will use p2's function!\n");
	p22();
}
void p12()
{
	printf("this is p1,Thank you p2 for using my function!\n");
}