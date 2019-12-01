#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*typedef struct
{
	int typenum;
	char *word;
}WORD;*/

class WORD
{
public:
	int typenum;
	char *word;
	WORD(){}
};

string input;
char token[255] = " ";
int p_input;
int p_token;
char ch;
char* rwtab[] = {"begin","if","then","while","do","end"}; /*关键字数组*/

WORD scaner(); 

void main()
{
	int over = 1;
	
	WORD oneword;
	p_input = 0;
	fstream fp1;
	fp1.open("in.txt",ios::in);
	if(!fp1)
	{
		cerr<<"error!"<<endl;
		exit(1);
	}
	while(!fp1.eof())
	{
		getline(fp1,input);
		cout<<input<<endl;
	}
	fp1.close();

	fstream fp2;
	fp2.open("output.txt",ios::out|ios::trunc);

	 do /*对源程序进行分析，直至结束符*/
	{			
		oneword = scaner();		
		printf("(%d,%s)\n",oneword.typenum,oneword.word);
		fp2<<"("<<oneword.typenum<<","<<oneword.word<<")"<<endl;
	}while(ch !='\0');
	fp2.close();
}

/*读取input数组中的一个字符到ch中*/
char m_getch(){
	ch = input[p_input];
	p_input = p_input +1;
	return(ch);
}

/*去除空格*/
void getbc(){
	while(ch == ' '||ch ==10){
		ch = input[p_input];
		p_input = p_input+1;
	}
}

/*把字母或数字拼接在一起*/
void concat(){
	token[p_token] = ch;
	p_token = p_token + 1;
	token[p_token] = '\0';
}

/*判断是否为字母*/
int letter(){
	if(ch >='a'&&ch <='z'||ch >= 'A'&&ch <='Z')
		return 1;
	else
		return 0;
}

/*判断是否为数字*/
int digit(){
	if(ch >='0'&&ch <='9')
		return 1;
	else
		return 0;
}

/*与关键字表格对比*/
int reserve(){
	int n=0;
	for(n;n<6;n++){
	if(strcmp(rwtab[n],token) == 0)
		return n+1;
	}
	return 10;
} 

/*回退字符*/
void retract(){
	p_input = p_input-1;
}

/*char *dtb()
{
	char a1[5]={0},a2[5]={0};
	int i=0;
	if(ch>='0'&&ch<='9')
	{
		input[p_input]=ch;
		int num=(int)ch;
		while(num)
		{
			char temp=(char)(num%2);
			num=num/2;
			a1[i++]=temp;
		}
	}
	int j=0;
	while(i)
	{
		a2[j++]=a1[--i];
	}
	return a2;
}*/

WORD scaner(){
	WORD myword;
	myword.typenum =10;
	myword.word ="";
	p_token = 0;
	m_getch();
	getbc();
	if(letter())
	{
		while(letter()||digit()){
			concat();           /*先拼接字母 光标后退一个格回到上一格的位置 再与关键字表对比*/
			m_getch();
		}
		retract();
		myword.typenum = reserve();       
		myword.word = token;
		return(myword);
	}
	else if(digit())
	{
		while(digit()){
			concat();
			m_getch();
		}
		retract();
		myword.typenum =11;
		myword.word =token;
		return(myword);
	}
	else switch(ch){
		case'=':  
			m_getch();
			if(ch == '='){
				myword.typenum = 39;
				myword.word = "==";
				return(myword);
			}
			retract();
			myword.typenum =25;
			myword.word = "=";
			return(myword);
			break;

		case':':  
			m_getch();
			if(ch == '='){
				myword.typenum = 18;
				myword.word = ":=";
				return(myword);
			}
			retract();
			myword.typenum =17;
			myword.word = ":";
			return(myword);
			break;

		case'>':  
			m_getch();
			if(ch == '=')
			{
				myword.typenum = 24;
				myword.word = ">=";
				return(myword);
			}
			retract();
			myword.typenum =23;
			myword.word = ">";
			return(myword);
			break;
		case'<':  
			m_getch();
			if(ch == '>')
			{
				myword.typenum = 21;
				myword.word = "<>";
				return(myword);
			}
			else if(ch == '=')
			{
				myword.typenum = 22;
				myword.word = "<=";
				return(myword);
			}
			else if(ch == '<')
			{
				myword.typenum = 22;
				myword.word = "<<";
				return(myword);
			}
			else
			{
				retract();
				myword.typenum =20;
				myword.word = "<";
				return(myword);
				break;
			}

		case'+':
			myword.typenum =13;
			myword.word = "+";
			return(myword);
			break;

		case'-':
			myword.typenum =14;
			myword.word = "-";
			return(myword);
			break;

		case'*':
			myword.typenum =15;
			myword.word = "*";
			return(myword);
			break;

		case'/':
			m_getch();//首字符为/,再读取下一个字符判断
			if (ch == '*') // 说明读取到的是注释
			{
				m_getch();
				while(ch != '*')
				{
					m_getch();//注释没结束之前一直读取注释，但不输出
					if(ch == '*')
					{
						m_getch();
						if(ch == '/')//注释结束
						{
							myword.typenum = 999;
							myword.word = "注释";
							return (myword);
							break;
						}
					}
				}
			}
            else
            {
                retract();//读取到的下个字符不是*，即不是注释，则要回退，直接输出/
				myword.typenum = 16;
                myword.word = "/";
                return (myword);
                break;
             }

		case';':
			myword.typenum =26;
			myword.word = ";";
			return(myword);
			break;

		case'(':
			myword.typenum =27;
			myword.word = "(";
			return(myword);
			break;

		case')':
			myword.typenum =28;
			myword.word = ")";
			return(myword);
			break;

		case'[':
			myword.typenum =29;
			myword.word = "[";
			return(myword);
			break;

		case']':
			myword.typenum =30;
			myword.word = "]";
			return(myword);
			break;

		case'{':
			myword.typenum =31;
			myword.word = "{";
			return(myword);
			break;

		case'}':
			myword.typenum =32;
			myword.word = "}";
			return(myword);
			break;

		case',':
			myword.typenum =33;
			myword.word = ",";
			return(myword);
			break;

		case'!':
			m_getch();
			if (ch == '=')
			{
				myword.typenum = 40;
				myword.word = "!=";
				return(myword);
				break;
			}
			retract();
			myword.typenum = -1;
			myword.word = "ERROR";
			return(myword);
			break;

		case'"':
			myword.typenum =41;
			myword.word = "\"";
			return(myword);
			break;

		case'#':
			myword.typenum =0;
			myword.word = "#";
			return(myword);
			break;

		case'\0':
			myword.typenum =1000;
			myword.word = "over";
			return(myword);
			break;
		
		default:
			myword.typenum =-1;
			myword.word = "error";
			return(myword);
	}
}