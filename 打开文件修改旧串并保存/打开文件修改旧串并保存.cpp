// 打开文件修改旧串并保存.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

int main(int argc, char* argv[])
{
	ifstream myfile1("data1.txt",ios::in);
	if(!myfile1)
	{
		cerr<<"File open error!"<<endl;
		exit (1);
	}
	
	string sstr,newstr;
	cout<<"输入要替换的旧字符："<<endl;
	cin>>sstr;
	cout<<"输入要替换的新字符："<<endl;
	cin>>newstr;
	int pos;
	int flag=0;
	ofstream myfile2("data2.txt",ios::out);
	if(!myfile2)
	{
		cerr<<"File open error!"<<endl;
		exit (1);
	}
	while (!myfile1.eof())
	{
		string text;
		myfile1>>text;
		if((pos = text.find(sstr)) == string::npos)
		{   
			cout<<text<<endl;
		}
		else
		{
			text.replace(pos,sstr.length(),newstr);
			cout<<text<<endl;
		}
		myfile2<<text<<endl;
	}
	myfile1.close();
	myfile2.close();
	return 0;
}

