#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	set<int> s;
	s.clear();
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(1);
	for(set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<" ";
	}//�������� 
	cout<<endl;
	s.insert(6);
	for(auto x:s)
	{
		cout<<x<<" ";	
	} //�������� 
	cout<<endl;
	
	int hav=s.count(2);//��������2����1��0 
	cout<<hav<<endl;
	int hav2=s.count(9);//��������2����1��0
	cout<<hav2<<endl;
	
	s.erase(4);//ɾ��4 
	for(auto x:s)
	{
		cout<<x<<" ";
	 } 
	 cout<<endl;
}
