//1.编写一shell程序,读入学生姓名与三门功课成绩，求每个学生的三门课程总分，以及所有学生各门功课的的平均分。
#include<iostream>
#include<string.h>
using namespace std;
class Stu
{
public:
	char *name;
	float class1;
	float class2;
	float class3;
	Stu(){}
	void set(char *a,float cls1,float cls2,float cls3)
	{
		int len=strlen(a);
		name=new char[len+1];
		strcpy(name,a);
		class1=cls1;
		class2=cls2;
		class3=cls3;
	}
	float getsum()
	{
		float sum=class1+class2+class3;
		return sum;
	}
	float getaverage()
	{
		return getsum()/3;
	}
}; 
int main()
{
	int n;
	cout<<"Input the number of student：";
	cin>>n;
	Stu stu[n];
	int i;
	char name[10];
	float class1;
	float class2;
	float class3;
	for(i=0;i<n;i++)
	{
		cout<<"student"<<i+1<<":"<<endl;
		cout<<"name:";
		cin>>name;
		cout<<"class1:";
		cin>>class1;
		cout<<"class2:";
		cin>>class2;
		cout<<"class3:";
		cin>>class3;
		stu[i].set(name,class1,class2,class3);
		cout<<endl;
	}
	for(i=0;i<n;i++)
	{
		cout<<stu[i].name<<"'s sum of class is:"<<stu[i].getsum()<<endl;
		cout<<stu[i].name<<"'s average of class is:"<<stu[i].getaverage()<<endl<<endl;
	}
	return 0;
} 
