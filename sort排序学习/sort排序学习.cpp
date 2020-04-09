#include<bits/stdc++.h>
using namespace std;
typedef struct student
{
	char StuID[20];
	int CProblemNum;
	int StuGrade;
}student;

bool cmp(student a,student b)
{
	if(a.StuGrade!=b.StuGrade)
	{
		return a.StuGrade>b.StuGrade;
	}
	else return a.StuGrade<b.StuGrade;
}
int main()
{
	int N;
	cin>>N;
	student Student[N+1];
	for(int i=0;i<N;i++)
	{
		//cin>>Student[i].StuID;
		//cin>>Student[i].CProblemNum;
		cin>>Student[i].StuGrade;
	}
	cout<<"before sort"<<endl;
	for(int i=0;i<N;i++)
	{
		cout<<"Student["<<i+1<<"].StuGrade="<<Student[i].StuGrade<<"  "; 
	}
	cout<<endl;
	sort(Student,Student+N,cmp);
	cout<<"after sort:"<<endl;
	for(int i=0;i<N;i++)
	{
		cout<<"Student["<<i+1<<"].StuGrade="<<Student[i].StuGrade<<"  ";
	}
	cout<<endl;
	return 0;
}
