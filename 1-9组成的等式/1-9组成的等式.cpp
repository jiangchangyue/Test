#include<iostream>
using namespace std;
bool outHand[10] = { false };
int list[10] = { 0 };
int total = 0;
void DFS(int step)
{
	if (step == 10)   //结束条件1，把9个数全填进去了
	{
		if (list[1] * 100 + list[2] * 10 + list[3]     //结束条件2，满足等式
			+ list[4] * 100 + list[5] * 10 + list[6]
			== list[7]*100 + list[8]*10 + list[9])
		{
			total++;
		}
		return;
 
	}
	for (int i = 1;i <= 9;i++)  //尝试每一种可能
	{
		if (outHand[i] == false)
		{
			list[step] = i;    //将这种情况放到容器中
			outHand[i] = true;  //标记
			DFS(step + 1);  //开始填下一个空
			outHand[i] = false;//再拿出来
		}
	}
	return;
}
int main()
{
	DFS(1);
	cout << total / 2;
}
