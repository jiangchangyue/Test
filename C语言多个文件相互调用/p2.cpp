#include<stdio.h>
#include "h2.h"
void p12();
void p2()
{
	h2();
	printf("this is p2! I will use p1's function!\n");
	p12();
}
void p22()
{
	printf("this is p2,Thank you p1 for using my function!\n");
}