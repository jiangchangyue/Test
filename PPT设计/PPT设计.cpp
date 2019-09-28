// PPT设计.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;

class CGraph
{
private:
	char *type;
	char *color;
	int linewidth;
	char *Text;
	int X,Y;
public:
	CGraph(){}
	CGraph(int x,int y,char *text,char *Type,char *Color,int Linewidth)
	{
		X=x,Y=y;
		int m=strlen(Color);
		color=new char[m+1];
		strcpy(color,Color);
		int n=strlen(Type);
		type=new char[n+1];
		strcpy(type,Type);
		linewidth=Linewidth;
		int len=strlen(text);
		Text=new char[len+1];
		strcpy(Text,text);
	}
	void reset(int x,int y,char *text,char *Type,char *Color,int Linewidth)
	{
		X=x,Y=y;
		int m=strlen(Color);
		color=new char[m+1];
		strcpy(color,Color);
		int n=strlen(Type);
		type=new char[n+1];
		strcpy(type,Type);
		linewidth=Linewidth;
		int len=strlen(text);
		Text=new char[len+1];
		strcpy(Text,text);
	}
	void show()
	{
		cout<<"the type is:"<<type<<endl;
		cout<<"the color is:"<<color<<endl;
		cout<<"the linewidth is:"<<linewidth<<endl;
		cout<<"Text: "<<Text<<endl;
		cout<<"Coordinate: "<<"("<<X<<","<<Y<<")"<<endl;
	}
	void save(fstream &file)
	{
		file.write((char*)&X,sizeof(int));
		file.write((char*)&Y,sizeof(int));
		int len1,len2,len3;
		len1=strlen(Text);
		len2=strlen(type);
		len3=strlen(color);
		file.write((char*)&len1,sizeof(int));
		file.write((char*)&len2,sizeof(int));
		file.write((char*)&len3,sizeof(int));
		file.write(Text,(len1+1)*sizeof(char));
		file.write(type,(len2+1)*sizeof(char));
		file.write(color,(len3+1)*sizeof(char));
		file.write((char*)&linewidth,sizeof(int));
	}
	void Open(fstream &file)
	{
		int len1,len2,len3;
		file.read((char *)&X,sizeof(int));
		file.read((char *)&Y,sizeof(int));
		file.read((char*)&len1,sizeof(int));
		file.read((char*)&len2,sizeof(int));
		file.read((char*)&len3,sizeof(int));
		file.read(reinterpret_cast<char *>(Text),(len1+1)*sizeof(char));
		file.read(reinterpret_cast<char *>(type),(len2+1)*sizeof(char));
		file.read(reinterpret_cast<char *>(color),(len3+1)*sizeof(char));
		file.read((char *)&linewidth,sizeof(int));
	}
	void Alter(){}
};
class Crect:virtual public CGraph
{
private:
	int L,W;	
public:
	Crect(){}
	Crect(int x,int y,int l,int w,char *text,char *type,char *color,int linewidth):CGraph(x,y,text,type,color,linewidth)
	{
		L=l;
		W=w;
	}
	Crect(int l,int w)
	{
		L=l;
		W=w;
	}
	void recreat(int x,int y,int l,int w,char *text,char *type,char *color,int linewidth)
	{
		CGraph(x,y,text,type,color,linewidth);
		L=l;
		W=w;
	}
	void show()
	{
ll:cout<<"按1展示动画"<<endl;
		int a;
		cin>>a;
		if(a==1)
			animation();
		else
		{
			cout<<"error!";
			goto ll;
		}
		//CGraph::show();
		//cout<<"Length: "<<L<<" "<<"Wide: "<<W<<endl;
		//cout<<"Area: "<<Getarea()<<endl;
	}
	int Getarea()
	{
		return L*W;
	}
	void save(fstream &file)
	{
		CGraph::save(file);
		file.write((char*)&L,sizeof(int));
		file.write((char*)&W,sizeof(int));
	}
	void Open(fstream &file)
	{
		CGraph::Open(file);
		file.read((char *)&L,sizeof(int));
		file.read((char *)&W,sizeof(int));
	}
	void animation()
	{
		cout<<"从左侧飞入"<<endl;
		CGraph::show();
		cout<<"Length: "<<L<<" "<<"Wide: "<<W<<endl;
	}
	void Alter()
	{
		int x,y,l,w;
		char *type;
		char *color;
		int linewidth;
		char *text;
		cout<<"请依次输入矩形基本信息：（坐标，长，宽，文本，颜色，类型，线粗）"<<endl;
		text=new char[];
		color=new char[];
		type=new char[];
		cin>>x>>y>>l>>w>>text>>color>>type>>linewidth;
		recreat(x,y,l,w,text,color,type,linewidth);
	}
	~Crect(){}
};
class Circle:virtual public CGraph
{
private:
	int R;
public:
	Circle(){}
	Circle(int x,int y,int r,char *text,char *type,char *color,int linewidth):CGraph(x,y,text,type,color,linewidth)
	{
		R=r;
	}
	void recreat(int x,int y,int r,char *text,char *type,char *color,int linewidth)
	{
		CGraph(x,y,text,type,color,linewidth);
		R=r;
	}
	Circle(int r)
	{
		R=r;
	}
	double Getarea()
	{
		return 3.14*R*R;
	}
	void show()
	{
ll:cout<<"按1展示动画"<<endl;
		int a;
		cin>>a;
		if(a==1)
			animation();
		else
		{
			cout<<"error!";
			goto ll;
		}
		//CGraph::show();
		//cout<<"radius: "<<R<<endl;
		//cout<<"Area: "<<Getarea()<<endl;
	}
	void save(fstream &file)
	{
		CGraph::save(file);
		file.write((char*)&R,sizeof(int));
	}
	void Open(fstream &file)
	{
		CGraph::Open(file);
		file.read((char *)&R,sizeof(int));
		cout<<"文件已打开!"<<endl;
	}
	void animation()
	{
		cout<<"从右侧飞入"<<endl;
		CGraph::show();
		cout<<"radius: "<<R<<endl;
	}
	void Alter()
	{
		int x,y,r;
		char *type;
		char *color;
		int linewidth;
		char *text;
		cout<<"请依次输入圆形基本信息：（坐标，半径，文本，颜色，类型，线粗）"<<endl;
		text=new char[];
		color=new char[];
		type=new char[];
		cin>>x>>y>>r>>text>>color>>type>>linewidth;
		recreat(x,y,r,text,color,type,linewidth);
	}
	~Circle(){}
};
/*class CCircleRect:public Crect,public Circle
{
public:
	CCircleRect(int x,int y,int l,int w,int r,char *text,char *color,char *type,int linewidth)
		:Crect(l,w),Circle(r),CGraph(x,y,text,color,type,linewidth){}

	void recreat(int x,int y,int l,int w,int rr,char *text,char *color,char *type,int linewidth)
	{
		Crect(l,w);
		Circle(rr);
		CGraph(x,y,text,color,type,linewidth);
	}
	void animation()
	{
		cout<<"从下侧飞入"<<endl;
		CGraph::show();
	}
	void show()
	{
ll:cout<<"按1展示动画"<<endl;
		int a;
		cin>>a;
		if(a==1)
			animation();
		else
		{
			cout<<"error!";
			goto ll;
		}
	}
	void save(fstream &file)
	{
		CGraph::save(file);
	}
	void Open(fstream &file)
	{
		cout<<"文件已打开!"<<endl;
	}
	void Alter()
	{
		int x,y,r,l,w;
		char *type;
		char *color;
		int linewidth;
		char *text;
		cout<<"请输入圆角矩形的基本信息：（坐标，长，宽，半径，文本，颜色，类型，线粗）"<<endl;
		text=new char[];
		color=new char[];
		type=new char[];
		cin>>y>>l>>w>>r>>text>>color>>type>>linewidth;
		recreat(x,y,l,w,r,text,color,type,linewidth);
	}

};*/
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
	void recreat(char *a)
	{
		int l=strlen(a);
		text=new char[l+1];
		strcpy(text,a);
		text[l]='\0';
		len=l;
	}
	void save(fstream &file)
	{
		file.write((char *)&len,sizeof(int));
		file.write(text,(len+1)*sizeof(char));
	}
	void Open(fstream &file)
	{
		cout<<"33";
		file.read((char *)&len,sizeof(int));
		cout<<len<<" ";
		cout<<"44";
		this->len=len;
		cout<<len<<" ";
		text=new char[len];
		file.read(reinterpret_cast<char *>(text),(len+1)*sizeof(char));
		cout<<"55";
		cout<<"文件已打开!"<<endl;
	}
	void Display()
	{
		cout<<text<<endl;
	}
	void Alter()
	{
		char a[100];
		cout<<"输入一个字符串：";
		cin>>a;
		recreat(a);
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
	vector<CGraph *> G;
	int i,j,k;
public:
	PPTpage(){}
	PPTpage(PPTpage &a)
	{
		TEXT=a.TEXT;
		G=a.G;
		i=a.i;
		j=a.j;
		k=a.k;
	}
	void creat()
	{
		char a[100];
		cout<<"输入一个字符串：";
		cin>>a;
		TEXT=new Text(a);
		cout<<"请输入矩形、圆、圆角矩形的个数："<<endl;
		int I,J;
		cin>>I>>J;
		i=I;
		j=J;
//		k=K;
		GetCrect(I);
		GetCircle(J);
		//CCircleRect_(K);
	}
	void creat_1()
	{
		char a[100];
		cout<<"输入一个字符串：";
		cin>>a;
		TEXT=new Text(a);
	}
	void Alter()
	{
		cout<<"想要修改的信息："<<endl;
		cout<<"文本框：1"<<endl;
		cout<<"矩形：2"<<endl;
		cout<<"圆：3"<<endl;
		cout<<"圆角矩形：4"<<endl;
		int l;
		cin>>l;
		switch(l)
		{
		case 1:
			{
				TEXT->Alter();
				break;
			}
		case 2:
			{
				cout<<"想要修改的矩形："<<endl;
				int num;
				cin>>num;
				G[num-1]->Alter();
				break;
			}
		case 3:
			{
				cout<<"想要修改的圆："<<endl;
				int num;
				cin>>num;
				G[num-1]->Alter();
				break;
			}
		/*case 4:
			{
				cout<<"想要修改的圆角矩形："<<endl;
				int num;
				cin>>num;
				G[num-1]->Alter();
				break;
			}*/
		}
	}
	void save(fstream &file)
	{
		TEXT->save(file);
		file.write((char*)&i,sizeof(int));
		file.write((char*)&j,sizeof(int));
		for(int j=0;j<i;j++)
		{
			G[j]->save(file);
		}
		for(int k=i;k<i+j;k++)
		{
			G[k]->save(file);
		}
	}
	void open(fstream &file)
	{
		int i;
		int j;
		cout<<"22"<<endl;
		TEXT->Open(file);
		file.read((char *)&i,sizeof(int));
		file.read((char *)&j,sizeof(int));
		this->i=i;
		this->j=j;
		cout<<i<<" "<<j<<"hhhhhhh";
		for(int l=0;l<i;l++)
		{
			G[l]->Open(file);
		}
		for(int k=i;k<i+j;k++)
		{
			G[k]->Open(file);
		}
	}
	void Display()
	{
		TEXT->Display();
		cout<<"the amount of Crect is:"<<i<<endl;
		cout<<"the amount of Circlie is: "<<j<<endl;
		for(int m=0;m<i;m++)
		{
			G[m]->show();
			cout<<endl;
		}
		for(int n=i;n<i+j;n++)
		{
			G[n]->show();
			cout<<endl;
		}
		/*for(int c=i+j;c<i+j+k;c++)
		{
			G[c]->show();
			cout<<endl;
		}*/
	}
	void GetCrect(int I)
	{
		int x,y,l,w;
		char *type;
		char *color;
		int linewidth;
		char *text;
		cout<<"请依次输入矩形基本信息：（坐标，长，宽，文本，颜色，类型，线粗）"<<endl;
		for(int m=0;m<I;m++)
		{
			text=new char[];
			color=new char[];
			type=new char[];
			cin>>x>>y>>l>>w>>text>>color>>type>>linewidth;
			CGraph *A=new Crect(x,y,l,w,text,color,type,linewidth);
			G.push_back(A);
		}	
	}
	void GetCircle(int J)
	{
		int x,y,r;
		char *type;
		char *color;
		int linewidth;
		char *text;
		cout<<"请依次输入圆形基本信息：（坐标，半径，文本，颜色，类型，线粗）"<<endl;
		for(int m=0;m<J;m++)
		{
			text=new char[];
			color=new char[];
			type=new char[];
			cin>>x>>y>>r>>text>>color>>type>>linewidth;
			CGraph *B=new Circle(x,y,r,text,color,type,linewidth);
			G.push_back(B);
		}
	}
	/*void CCircleRect_(int K)
	{
		int x,y,r,l,w;
		char *type;
		char *color;
		int linewidth;
		char *text;
		cout<<"请输入圆角矩形的基本信息：（坐标，长，宽，半径，文本，颜色，类型，线粗）"<<endl;
		for(int o=0;o<K;o++)
		{
			text=new char[];
			color=new char[];
			type=new char[];
			cin>>y>>l>>w>>r>>text>>color>>type>>linewidth;
			CGraph *C=new CCircleRect(x,y,l,w,r,text,color,type,linewidth);
			G.push_back(C);
		}
	}*/

	~PPTpage(){}
};
vector<PPTpage *> temp;
class CDocument
{
private:
	char a[100];
	vector<PPTpage *> wj;
	vector<PPTpage *>::iterator it1;
	vector<CGraph *>::iterator it;
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
		PPTpage *p=new PPTpage();
		p->creat();
		wj.push_back(p);
	}
	void save(fstream &file,char *a)
	{
		cout<<strlen(a)<<"77777777";
		int lt=strlen(a);
		file.write((char *)&lt,sizeof(int));
		file.write(a,(lt+1)*sizeof(char));
		int count=wj.size();
		file.write((char *)&count,sizeof(int));
		for(int i=0;i<wj.size();i++)
			wj[i]->save(file);
	}
	void open(fstream &file)
	{
		char a[10];
		int lt;
		file.read((char *)&lt,sizeof(int));
		file.read(reinterpret_cast<char *>(a),(lt+1)*sizeof(char));
		cout<<"文件名："<<a<<endl;
		vector<PPTpage *>().swap(temp);
		int count;
		file.read((char *)&count,sizeof(int));
		cout<<"count  "<<count<<" ";
		cout<<"hello";
		for(int i=0;i<count;i++)
		{cout<<"11"<<endl;
			PPTpage *page=new PPTpage();
			page->open(file);
			temp.push_back(page);
		}
	}
	void Display()
	{
		for(int i=0;i<temp.size();i++)
			temp[i]->Display();
		cout<<"The Cdocument has "<<temp.size()<<" pages! "<<endl;
	}
	void Delete(int x)
	{
		it1=wj.begin();
		for(int h=0;h<x-1;h++)
			it1++;
		wj.erase(it1);
		for(int i=0;i<wj.size();i++)
			wj[i]->Display();
	}
	void Alter(int x)
	{
		it1=wj.begin();
		for(int h=0;h<x-1;h++)
			it1++;
		wj[x-1]->Alter();
		
		wj[x-1]->Display();
	}
	void copy(int x)
	{
		int i = 0;
		for(it1 = wj.begin(); i < x; i++,it1++);
		it1--;
		wj.push_back(new PPTpage(**it1));
	}
	~CDocument(){}
};
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
			cout<<"删除：5"<<endl;
			cout<<"修改：6"<<endl;
			cout<<"复制：7"<<endl;
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
					if(doc!=NULL) delete doc;
					doc=NULL;
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
			case 5:
				{
					cout<<"想要删除的页："<<endl;
					int x;
					cin>>x;
					doc->Delete(x);
					break;
				}
			case 6:
				{
					cout<<"想要修改的页："<<endl;
					int x;
					cin>>x;
					doc->Alter(x);
					break;
				}
			case 7:
				{
					cout<<"想要复制的页："<<endl;
					int x;
					cin>>x;
					doc->copy(x);
					break;
				}
			}
			if(flag==1) break;
		}
	}
	//printf("Hello World!\n");
	return 0;
}



