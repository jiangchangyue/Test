#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char prog[100],token[8],ch;//prog[100]，用来存储要处理的对象，token用来与关键字比较，ch用来存储一个字符
char *keyword[6]={"begin","if","then","while","do","end"};//关键字表
int syn,p,i,n;
//syn是种别码，p为prog数组的指针，m为token数组的指针，n为rwtab数组的指针，sum为词法分析器里的数字数值大小
 
void factor();//因式 factor
void expression();//表达式 expression
void yucu();
void term();//项 term
void statement();// 语句 statement
void lrparser();
void scaner();//扫描器
 
int main()
{
    p=0;
	cout<<"please input a string (end with '#'):"<<endl;
    /*从命令行读取要处理的对象，并存储在prog[]数组中*/
    do
    {
		ch=getchar();
        prog[p++]=ch;
    }while(ch!='#');
 
    p=0;
    scaner();//主要完成赋值种别码等词法分析功能
	lrparser();//调用各种递归子程序，完成语法分析的过程
	getchar();
	return 0;
}
 
/*调用各种递归子程序，完成语法分析的过程*/
void lrparser()
{
    if(syn==1)//begin
    {     
        yucu();          
    }
    else
    {
		cout<<"error!"<<endl;
    }
	if(syn==6)//end
    {
        scaner();
        if(syn==0)//出现#且flag=0
			cout<<"success!"<<endl;
		else
		{	
			cout<<"the string haven't got an '#'!"<<endl;
		}
    }
    else
    {	
		cout<<"the string haven't got an 'end'!"<<endl;
    }
}
 
void yucu()
{
	scaner();
    statement();         
    while(syn==26)//分号
    {
        scaner();   
        statement();         
    }
}
 
void statement()
{
    if(syn==10)//letter
    {
        scaner();        /*读下一个单词符号*/
        if(syn==18)//:=
        {
            scaner();      /*读下一个单词符号*/
            expression();    
        }
        else
        {
			cout<<"语法错误!"<<endl;
        }
    }
    else
    {
		cout<<"语法错误！"<<endl;
    }
    return;
}
 
void expression()
{
    term();
    while((syn==13)||(syn==14))//+-
    {
        scaner();           
        term();               
    }
    return;
}
 
void term()
{
    factor();
    while((syn==15)||(syn==16))//*/
    {
        scaner();             
        factor();              
    }
    return;
}
 
void factor()//因式处理函数
{
    if((syn==10)||(syn==11))//标识符，数字
    {
        scaner();
    }
    else if(syn==27)//开头是左括号（
    {
        scaner();          
        expression();      
 
        if(syn==28)//出现右括号）
        {
            scaner();          
        }
        else
        {
			cout<<"语法错误！是否缺少')'"<<endl;
        }
    }
    else
    {
		cout<<"语法错误!"<<endl;
    }
    return;
}
   
/*主要完成赋值种别码等词法分析功能*/
void scaner()//扫描器，词法分析器内容
{
    for(n=0;n<8;n++)//初始化token
        token[n]='\0';
    n=0;//m为token的指针
    ch=prog[p++];//数组指针+1
 
    while(ch==' ')//遇到空格+1
        ch=prog[p++];
 
    if(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A')))//遇到字母
    {
        do
        {
            token[n++]=ch;
            ch=prog[p++];//p+1,下次循环使用
        }while(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A'))||((ch>='0')&&(ch<='9')));
        syn=10;//10，字母开头
 
        /*判别是否为关键字*/
        for(n=0;n<6;n++)//n为rwtab的指针
        if(strcmp(token,keyword[n])==0)//strcmp返回值为0，则两个参数大小相同
        {
            syn=n+1;
        }
		p--;
    }
    else if((ch>='0')&&(ch<='9'))//遇到数字
    {
		p--;
        do
        {
			token[n++]=prog[p++];
            ch=prog[p];
        }while((ch>='0')&&(ch<='9'));
        syn=11;//数字
		return;
    }
    /*除数字和字母开头以外的其他符号*/
    else
    {
		switch(ch)
		{
			case '<':
				token[0]=ch;
				ch=prog[p++];
				if(ch=='>')
				{
					token[1]=ch;
					syn=21;
				}
				else if(ch=='=')
				{
					token[1]=ch;
					syn=22;
				}
				else
				{
					syn=20;
					p--;//回溯
				}
				break;
 
			case '>':
				token[0]=ch;
				ch=prog[p++];
				if(ch=='=')
				{
					token[1]=ch;
					syn=24;
				}
				else
				{
					syn=23;
					p--;
				}
				break;
 
			case ':':
				token[0]=ch;
				ch=prog[p++];
				if(ch=='=')
				{
					token[1]=ch;
					syn=18;
				}
				else
				{
					syn=17;
					p--;
				}
				break;
 
			case '+':
				syn=13;
				token[0]=ch;
				break;
 
			case '-':
				syn=14;
				token[0]=ch;
				break;
 
			case '*':
				syn=15;
				token[0]=ch;
				break;
 
			case '/':
				syn=16;
				token[0]=ch;
				break;
 
			case '(':
				syn=27;
				token[0]=ch;
				break;
 
			case ')':
				syn=28;
				token[0]=ch;
				break;
 
			case '=':
				syn=25;
				token[0]=ch;
				break;
 
			case ';':
				syn=26;
				token[0]=ch;
				break;
 
			case '#':
				syn=0;
				token[0]=ch;
				break;
 
			default:
				syn=-1;
				cout<<"词法出错！"<<endl;
				break;
		}
	}
}