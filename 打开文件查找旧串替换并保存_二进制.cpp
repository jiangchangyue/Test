// 打开文件查找旧串替换并保存_二进制.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char* argv[])
{
	string text1;
	cin>>text1;
	fstream myfile1;
	myfile1.open("data.dat",ios::binary|ios::out|ios::trunc);
	if(!myfile1)
	{
		cerr<<"File open error!"<<endl;
		exit (1);
	}
	myfile1.write(text1.c_str(),text1.size()+1);
	myfile1.close();
	string sstr,newstr;
	cout<<"输入要替换的旧字符："<<endl;
	cin>>sstr;
	cout<<"输入要替换的新字符："<<endl;
	cin>>newstr;
	int pos;
	int flag=0;
	fstream myfile2;
	myfile2.open("data.dat",ios::binary|ios::out|ios::in);
	if(!myfile2)
	{
		cerr<<"File open error!"<<endl;
		exit (1);
	}
	string text;
	while(!myfile2.eof())
	{
		myfile2.read((char *)text.c_str(),text1.size()+1);
		cout<<text<<endl;
		if((pos = text.find(sstr)) == string::npos)
		{   
			cout<<text<<endl;
		}
		else
		{
			text.replace(pos,sstr.length(),newstr);
			cout<<text<<endl;
		}
		myfile2.write(text.c_str(),text.size()+1);
	}
	myfile2.close();
	//printf("Hello World!\n");
	return 0;
}