#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char prog[100],token[8],ch;//prog[100]�������洢Ҫ����Ķ���token������ؼ��ֱȽϣ�ch�����洢һ���ַ�
char *keyword[6]={"begin","if","then","while","do","end"};//�ؼ��ֱ�
int syn,p,i,n;
//syn���ֱ��룬pΪprog�����ָ�룬mΪtoken�����ָ�룬nΪrwtab�����ָ�룬sumΪ�ʷ����������������ֵ��С
 
void factor();//��ʽ factor
void expression();//���ʽ expression
void yucu();
void term();//�� term
void statement();// ��� statement
void lrparser();
void scaner();//ɨ����
 
int main()
{
    p=0;
	cout<<"please input a string (end with '#'):"<<endl;
    /*�������ж�ȡҪ����Ķ��󣬲��洢��prog[]������*/
    do
    {
		ch=getchar();
        prog[p++]=ch;
    }while(ch!='#');
 
    p=0;
    scaner();//��Ҫ��ɸ�ֵ�ֱ���ȴʷ���������
	lrparser();//���ø��ֵݹ��ӳ�������﷨�����Ĺ���
	getchar();
	return 0;
}
 
/*���ø��ֵݹ��ӳ�������﷨�����Ĺ���*/
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
        if(syn==0)//����#��flag=0
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
    while(syn==26)//�ֺ�
    {
        scaner();   
        statement();         
    }
}
 
void statement()
{
    if(syn==10)//letter
    {
        scaner();        /*����һ�����ʷ���*/
        if(syn==18)//:=
        {
            scaner();      /*����һ�����ʷ���*/
            expression();    
        }
        else
        {
			cout<<"�﷨����!"<<endl;
        }
    }
    else
    {
		cout<<"�﷨����"<<endl;
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
 
void factor()//��ʽ������
{
    if((syn==10)||(syn==11))//��ʶ��������
    {
        scaner();
    }
    else if(syn==27)//��ͷ�������ţ�
    {
        scaner();          
        expression();      
 
        if(syn==28)//���������ţ�
        {
            scaner();          
        }
        else
        {
			cout<<"�﷨�����Ƿ�ȱ��')'"<<endl;
        }
    }
    else
    {
		cout<<"�﷨����!"<<endl;
    }
    return;
}
   
/*��Ҫ��ɸ�ֵ�ֱ���ȴʷ���������*/
void scaner()//ɨ�������ʷ�����������
{
    for(n=0;n<8;n++)//��ʼ��token
        token[n]='\0';
    n=0;//mΪtoken��ָ��
    ch=prog[p++];//����ָ��+1
 
    while(ch==' ')//�����ո�+1
        ch=prog[p++];
 
    if(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A')))//������ĸ
    {
        do
        {
            token[n++]=ch;
            ch=prog[p++];//p+1,�´�ѭ��ʹ��
        }while(((ch<='z')&&(ch>='a'))||((ch<='Z')&&(ch>='A'))||((ch>='0')&&(ch<='9')));
        syn=10;//10����ĸ��ͷ
 
        /*�б��Ƿ�Ϊ�ؼ���*/
        for(n=0;n<6;n++)//nΪrwtab��ָ��
        if(strcmp(token,keyword[n])==0)//strcmp����ֵΪ0��������������С��ͬ
        {
            syn=n+1;
        }
		p--;
    }
    else if((ch>='0')&&(ch<='9'))//��������
    {
		p--;
        do
        {
			token[n++]=prog[p++];
            ch=prog[p];
        }while((ch>='0')&&(ch<='9'));
        syn=11;//����
		return;
    }
    /*�����ֺ���ĸ��ͷ�������������*/
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
					p--;//����
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
				cout<<"�ʷ�����"<<endl;
				break;
		}
	}
}