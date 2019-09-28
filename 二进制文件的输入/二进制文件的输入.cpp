// 二进制文件的输入.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char* argv[])
{
	char *name[3]={"Antony","John","Tom"};
	float score[3]={85.5,90,60};
	fstream binfile1;
	binfile1.open("record.dat",ios::binary|ios::out|ios::trunc);
	if(!binfile1)
	{
		cerr<<"record.dat open error!"<<endl;
		exit(1);
	}
	for(int i=0;i<3;i++)
	{
		binfile1.write(name[i],8*sizeof(char));
		binfile1.write((char *)&score[i],sizeof(float));
	}
	binfile1.close();
	char namee[8];
	float scoree;
	fstream binfile2;
	binfile2.open("record.dat",ios::binary|ios::in);
	if(!binfile2)
	{
		cerr<<"record.dat open errorrrr!"<<endl;
		exit(1);
	}
	while(!binfile2.eof())
	{
		binfile2.read(reinterpret_cast<char *>(namee),8*sizeof(char));
		binfile2.read(reinterpret_cast<char *>(&scoree),sizeof(float));
		cout<<namee<<'\t'<<scoree<<endl;
	}
	binfile2.close();
	//printf("Hello World!\n");
	return 0;
}

