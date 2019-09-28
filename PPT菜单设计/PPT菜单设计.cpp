// PPT菜单设计.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Text
{
private:
	char *text;
	int len;
public:
	Text(){}
	Text(char *a)
	{
		int l=strlen(a);
		text=new char[l+1];
		strcpy(text,a);
		text[l]='\0';
		len=l;
	}
	void save(fstream &file)
	{
		file.write(text,(len+1)*sizeof(char));
	}
	void Open(fstream &file)
	{
		char *TEXT;
		TEXT=new char[len+1];
		file.read(reinterpret_cast<char *>(TEXT),(len+1)*sizeof(char));
		cout<<"文件已打开!"<<endl;
	}
	void Display()
	{
		cout<<text<<endl;
	}
	~Text()
	{
		delete []text;
	}
};
class PPTpage
{
private:
	Text *TEXT;
public:
	friend class Text;
	PPTpage(){}
	void creat()
	{
		char a[100];
		cout<<"输入一个字符串：";
		cin>>a;
		TEXT=new Text(a);
	}
	void save(fstream &file)
	{
		TEXT->save(file);
	}
	void open(fstream &file)
	{
		TEXT->Open(file);
	}
	void Display()
	{
		TEXT->Display();
	}
	~PPTpage(){}
};

class CDocument
{
private:
	char a[100];
	static int num;
	vector<PPTpage *> wj;
public:
	CDocument(){}
	void creat()
	{
		int flag=0;
		Addpage();
		while(1)
		{
			cout<<"添加一页PPT：1"<<endl;
			cout<<"结束添加：0"<<endl;
			int q;
			cin>>q;
			switch(q)
			{
			case 1:
					Addpage();
					break;
			case 0:
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
	}
	void Addpage()
	{
		num++;
		PPTpage *p=new PPTpage();
		p->creat();
		wj.push_back(p);
	}
	void save(fstream &file,char *a)
	{
		file.write(a,strlen(a)*sizeof(char));
		for(int i=0;i<wj.size();i++)
			wj[i]->save(file);
	}
	void open(fstream &file)
	{
		/*wj.clear();
		while(!file.eof())
		{
			PPTpage *page=new PPTpage();
			page->open(file);
			wj.push_back(page);
		}*/
		for(int i=0;i<wj.size();i++)
			wj[i]->open(file);
	}
	void Display()
	{
		for(int i=0;i<wj.size();i++)
			wj[i]->Display();
		cout<<"The Cdocument has "<<num<<" pages! "<<endl;
	}
	~CDocument(){}
};
int	CDocument::num=0;
int main(int argc, char* argv[])
{
	vector<CDocument *> Doc;
	
	while(1)
	{
		CDocument *doc=NULL;
		while(1)
		{
			cout<<"创建：1"<<endl;
			cout<<"保存：2"<<endl;
			cout<<"打开：3"<<endl;
			cout<<"显示：4"<<endl;
			cout<<"退出：0"<<endl;
			cout<<"再建一个新文件：9"<<endl;
			int a;
			cin>>a;
			int flag=0;
			switch(a)
			{
			case 9:
				{
					flag=1;
					break;
				}
			case 0:
				exit(1);
			case 1:
				{
					doc=new CDocument();
					doc->creat();
					break;
				}
			case 2:
				{
					char aa[10];
					cout<<"保存文件名称：";
					cin>>aa;
					fstream file1;
					file1.open(aa,ios::binary|ios::out);
					if(!file1)
					{
						cerr<<"file open or crect error!"<<endl;
						exit(1);
					}
					doc->save(file1,aa);
					file1.close();
					Doc.push_back(doc);
					break;
				}
			case 3:	
				{
					char ww[10];
					cout<<"输入要打开的文件：";
					cin>>ww;
					fstream file2;
					file2.open(ww,ios::binary|ios::out|ios::in);
					if(!file2)
					{
						cerr<<"file open or crect error!"<<endl;
						exit(1);
					}
					/*if(doc!=NULL) delete doc;
					doc=new CDocument();*/
					doc->open(file2);
					file2.close();
					break;
				}
			case 4:
				{
					if(doc==NULL) exit(1);
					doc->Display();
					break;
				}
			}
			if(flag==1) break;
		}
	}
	//printf("Hello World!\n");
	return 0;
}

