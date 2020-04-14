#include<iostream>
using namespace std;
int map[6][5] = { 0 };
bool visited[6][5] = { false };
int mi = 999999;
void DFS(int x, int y, int step)
{
	int tx=0, ty=0;
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	if (x == 4 && y == 3)    //�������Ŀ��λ�ã��������
	{
		if (step < mi)
			mi = step;
		return;
	}
	for (int k = 0;k < 4;k++)    //���ĸ����򶼳���һ��
	{
		tx = x+next[k][0];   //tx ty������һ��Ҫ�ߵ�λ��
		ty = y+next[k][1];
		if (tx < 1 || tx>5 || ty < 1 || ty>4)  //�������Խ�磬����
			continue;
		if (visited[tx][ty] == false && map[tx][ty] == 0)   //��������������ߣ�û���ϰ�û�з��ʹ�
		{
			visited[tx][ty] = true;   //������1һ��
			DFS(tx, ty, step + 1);
			visited[tx][ty] = false;
		}
	}
	return;
}
int main()
{
	map[1][3] = 1;
	map[3][3] = 1;
	map[4][2] = 1;
	map[5][4] = 1;
	visited[1][1] = true;
	DFS(1, 1, 0);
	cout << mi;
}
