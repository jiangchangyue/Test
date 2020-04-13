#include<iostream>
#include<math.h>
using namespace std;
struct Stu
{
	int num;
	Stu *prior;
	Stu *next;
}; 
int main()
{
	int n;
	cin>>n;
	Stu *head=new Stu();
	Stu *r;
	r=head;
	r->prior=NULL;
	for(int i=0;i<n;i++)
	{
		Stu *a=new Stu();
		a->num=i+1;
		r->next=a;
		a->prior=r;
		r=a;
	}
	Stu *tail=new Stu();
	r->next=tail;
	tail->prior=r;
	tail->next=NULL;
	int q;
	cin>>q;
	int tp1,tp2;
	for(int t=0;t<q;t++)
	{
		cin>>tp1>>tp2;
		r=head;
		for(int i=0;i<n;i++)
		{
			r=r->next;
			if(r->num==tp1)break;
		}
		if(tp2>0)
		{
			for(int i=0;i<tp2;i++)
			{
				Stu *p=r->next;
				r->prior->next=p;
				p->prior=r->prior;
				p->next->prior=r;
				r->next=p->next;
				p->next=r;
				r->prior=p;
			}
		}
		if(tp2<0)
		{
			tp2=-tp2;
			for(int i=0;i<tp2;i++)
			{
				Stu *p=r->prior;
				r->next->prior=p;
				p->next=r->next;
				p->prior->next=r;
				r->prior=p->prior;
				p->prior=r;
				r->next=p;
			}
		}
	}
	r=head;
	for(int i=0;i<n;i++)
	{
		r=r->next;
		cout<<r->num<<" ";
	}
	cout<<endl;
	return 0;
}
