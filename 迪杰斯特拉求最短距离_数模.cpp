// 迪杰斯特拉求最短距离_数模.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 200
#define INF 0
typedef struct _graph
{
    char vexs[MAX];       // 顶点集合
    int vexnum;           // 顶点数
    int edgnum;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph, *PGraph;
 
// 边的结构体
typedef struct _EdgeData
{
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重
}EData;

/*
 * Dijkstra最短路径。
 * 即，统计图(G)中"顶点vs"到其它各个顶点的最短路径。
 *
 * 参数说明：
 *        G -- 图
 *       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
 *     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
 *     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 *0/
void dijkstra(Graph G, int vs, int prev[], int dist[])
{
    int i,j,k;
    int min;
    int tmp;
    int flag[MAX];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
 
    // 初始化
    for (i = 0; i < G.vexnum; i++)
    {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G.matrix[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }
 
    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;
 
    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G.vexnum; i++)
    {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INF;
        for (j = 0; j < G.vexnum; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;
 
        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G.vexnum; j++)
        {
            tmp = (G.matrix[k][j]==INF ? INF : (min + G.matrix[k][j])); // 防止溢出
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }
 
    // 打印dijkstra最短路径的结果
    printf("dijkstra(%c): \n", G.vexs[vs]);
    for (i = 0; i < G.vexnum; i++)
        printf("  shortest(%c, %c)=%d\n", G.vexs[vs], G.vexs[i], dist[i]);
}

int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	return 0;
}*/

/*#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
using namespace std;
const int maxnum = 800;
const double maxint = 999999.0000;

// 各数组都从下标1开始
double dist[maxnum];     // 表示当前点到源点的最短路径长度
int prev[maxnum];     // 记录当前点的前一个结点
double c[maxnum][maxnum];   // 记录图的两点间路径长度
int n, line;             // 图的结点数和路径数

void Dijkstra(int n, int v, double *dist, int *prev, double c[maxnum][maxnum])
{
    bool s[maxnum];    // 判断是否已存入该点到S集合中
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0;     // 初始都未用过该点
        if(dist[i] == maxint)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;

    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
         // 注意是从第二个节点开始，第一个为源点
    for(i=2; i<=n; ++i)
    {
        double tmp = maxint;
        int u = v;
        // 找出当前未使用的点j的dist[j]最小值
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              // u保存当前邻接点中距离最小的点的号码
                tmp = dist[j];
            }
        s[u] = 1;    // 表示u点已存入S集合中

        // 更新dist
        for(j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<maxint)
            {
                double newdist = dist[u] + c[u][j];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}

// 查找从源点v到终点u的路径，并输出
void searchPath(int *prev,int v, int u)
{
    int que[maxnum];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=1; --i)
        if(i != 1)
            cout << que[i] << " -> ";
        else
            cout << que[i] << endl;
}

int main()
{
    freopen("input3.txt", "r", stdin);
    // 各数组都从下标1开始

    cin >> n;// 输入结点数
    cin >> line;// 输入路径数
    int p, q;
	double len;          // 输入p, q两点及其路径长度

    // 初始化c[][]为maxint
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;

    for(i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;
        if(len < c[p][q])       // 有重边
        {
            c[p][q] = len;      // p指向q
            c[q][p] = len;      // q指向p，这样表示无向图
        }
    }

    for(i=1; i<=n; ++i)
        dist[i] = maxint;
    for(i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            printf("%-15lf", c[i][j]);
        printf("\n");
    }

		Dijkstra(120,94, dist, prev, c);

			// 最短路径长度
		cout << "最短路径长度: " << dist[120]<< endl;

				// 路径
		cout << "路径为: ";
		searchPath(prev, 94, 120);
		/*Dijkstra(120, 1, dist, prev, c);

		// 最短路径长度
		cout << "最短路径长度: " << dist[120] << endl;

		// 路径
		cout << "路径为: ";
		searchPath(prev, 1, 120);*/
	/*for(i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			Dijkstra(j, i, dist, prev, c);
			if(dist[j]==999999)
			{
				continue;
			}
			else
			{
				cout << "最短路径长度: " << dist[j] << endl;
				cout << "路径为: ";
				searchPath(prev, i, j);
				//file<<"最短路径长度: " << dist[j] << endl<< "路径为: ";
			}
		}
	}
}*/


/*#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int maxnum = 800;
const double maxint = 999999;

double dist[maxnum];     
int prev[maxnum];    
double c[maxnum][maxnum];   
int n, line;            
void Dijkstra(int n, int v, double *dist, int *prev, double c[maxnum][maxnum])
{
    bool s[maxnum];    
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0;     
        if(dist[i] == maxint)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;
    for(i=2; i<=n; ++i)
    {
        double tmp = maxint;
        int u = v;
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              
                tmp = dist[j];
            }
        s[u] = 1;  
        for(j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<maxint)
            {
                double newdist = dist[u] + c[u][j];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}
void searchPath(int *prev,int v, int u)
{
    int que[maxnum];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=1; --i)
        if(i != 1)
            cout << que[i] << " -> ";
        else
            cout << que[i] << endl;
}
int main()
{
    freopen("input3.txt", "r", stdin);
    cin >> n;
    cin >> line;
    int p, q;
	double len; 
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;

    for(i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;
        if(len < c[p][q])      
        {
            c[p][q] = len;     
            c[q][p] = len;     
        }
    }
    for(i=1; i<=n; ++i)
        dist[i] = maxint;
	int aa[19]={1,10,11,16,22,24,27,31,34,36,42,64,65,79,94,106,123,141,145};
	int bb[2]={63,120};
	
	for(i=0;i<19;i++)
	{
		for(int j=0;j<2;j++)
		{
			Dijkstra(bb[j],aa[i], dist, prev, c);
			if(dist[bb[j]]==999999)
				continue;
			else
			{
				cout << "最短路径长度: " << dist[bb[j]]<< endl;
				cout << "路径为: ";
				searchPath(prev,aa[i],bb[j]);
			}
		}
	}
	return 0;
}*/


#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int maxnum = 800;
const double maxint = 999999;

double dist[maxnum];     
int prev[maxnum];    
double c[maxnum][maxnum];   
int n, line;            
void Dijkstra(int n, int v, double *dist, int *prev, double c[maxnum][maxnum])
{
    bool s[maxnum];    
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0;     
        if(dist[i] == maxint)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;
    for(i=2; i<=n; ++i)
    {
        double tmp = maxint;
        int u = v;
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              
                tmp = dist[j];
            }
        s[u] = 1;  
        for(j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<maxint)
            {
                double newdist = dist[u] + c[u][j];
                if(newdist < dist[j])
                {
                    dist[j] = newdist;
                    prev[j] = u;
                }
            }
    }
}
void searchPath(int *prev,int v, int u)
{
    int que[maxnum];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = prev[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = prev[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=1; --i)
        if(i != 1)
            cout << que[i] << " -> ";
        else
            cout << que[i] << endl;
}
int main()
{
    freopen("input3.txt", "r", stdin);
    cin >> n;
    cin >> line;
    int p, q;
	double len; 
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;
    for(i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;
        if(len < c[p][q])      
        {
            c[p][q] = len;     
            c[q][p] = len;     
        }
    }
    for(i=1; i<=n; ++i)
        dist[i] = maxint;  
	int aa[37]={1,2,4,5,6,7,9,10,11,12,13,14,16,22,24,27,31,34,36,42,63,64,65,67,75,76,79,94,100,106,109,120,122,123,141,145,149};
	int bb[37]={1,2,4,5,6,7,9,10,11,12,13,14,16,22,24,27,31,34,36,42,63,64,65,67,75,76,79,94,100,106,109,120,122,123,141,145,149};
	double min=999999;
	int s=0;
	for(i=0;i<37;i++)
	{
		double sum=0;
		for(int j=0;j<37;j++)
		{
			if(i==j) continue;
			Dijkstra(bb[j],aa[i], dist, prev, c);
			if(dist[bb[j]]==999999)continue;
			sum=sum+dist[bb[j]];
		}
		if(min>sum)
		{
			min=sum;
			s=i;
		}
	}
	cout<<aa[s]<<endl;
	int aaa[37]={1,2,4,5,6,7,9,10,11,12,13,14,16,22,24,27,31,34,36,42,63,64,65,67,75,76,79,94,100,106,109,120,122,123,141,145,149};
	int bbb[3]={63,120,145};
	
	for(i=0;i<37;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(aaa[i]==bbb[j])continue;
			Dijkstra(bbb[j],aaa[i], dist, prev, c);
			if(dist[bbb[j]]==999999)
				continue;
			else
			{
				cout << "最短路径长度: " << dist[bbb[j]]<< endl;
				cout << "路径为: ";
				searchPath(prev,aaa[i],bbb[j]);
			}
		}
	}
	return 0;
}
