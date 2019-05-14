// �Ͻ�˹��������̾���_��ģ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 200
#define INF 0
typedef struct _graph
{
    char vexs[MAX];       // ���㼯��
    int vexnum;           // ������
    int edgnum;           // ����
    int matrix[MAX][MAX]; // �ڽӾ���
}Graph, *PGraph;
 
// �ߵĽṹ��
typedef struct _EdgeData
{
    char start; // �ߵ����
    char end;   // �ߵ��յ�
    int weight; // �ߵ�Ȩ��
}EData;

/*
 * Dijkstra���·����
 * ����ͳ��ͼ(G)��"����vs"������������������·����
 *
 * ����˵����
 *        G -- ͼ
 *       vs -- ��ʼ����(start vertex)��������"����vs"��������������·����
 *     prev -- ǰ���������顣����prev[i]��ֵ��"����vs"��"����i"�����·����������ȫ�������У�λ��"����i"֮ǰ���Ǹ����㡣
 *     dist -- �������顣����dist[i]��"����vs"��"����i"�����·���ĳ��ȡ�
 *0/
void dijkstra(Graph G, int vs, int prev[], int dist[])
{
    int i,j,k;
    int min;
    int tmp;
    int flag[MAX];      // flag[i]=1��ʾ"����vs"��"����i"�����·���ѳɹ���ȡ��
 
    // ��ʼ��
    for (i = 0; i < G.vexnum; i++)
    {
        flag[i] = 0;              // ����i�����·����û��ȡ����
        prev[i] = 0;              // ����i��ǰ������Ϊ0��
        dist[i] = G.matrix[vs][i];// ����i�����·��Ϊ"����vs"��"����i"��Ȩ��
    }
 
    // ��"����vs"������г�ʼ��
    flag[vs] = 1;
    dist[vs] = 0;
 
    // ����G.vexnum-1�Σ�ÿ���ҳ�һ����������·����
    for (i = 1; i < G.vexnum; i++)
    {
        // Ѱ�ҵ�ǰ��С��·����
        // ������δ��ȡ���·���Ķ����У��ҵ���vs����Ķ���(k)��
        min = INF;
        for (j = 0; j < G.vexnum; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        // ���"����k"Ϊ�Ѿ���ȡ�����·��
        flag[k] = 1;
 
        // ������ǰ���·����ǰ������
        // �������Ѿ�"����k�����·��"֮�󣬸���"δ��ȡ���·���Ķ�������·����ǰ������"��
        for (j = 0; j < G.vexnum; j++)
        {
            tmp = (G.matrix[k][j]==INF ? INF : (min + G.matrix[k][j])); // ��ֹ���
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }
 
    // ��ӡdijkstra���·���Ľ��
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

// �����鶼���±�1��ʼ
double dist[maxnum];     // ��ʾ��ǰ�㵽Դ������·������
int prev[maxnum];     // ��¼��ǰ���ǰһ�����
double c[maxnum][maxnum];   // ��¼ͼ�������·������
int n, line;             // ͼ�Ľ������·����

void Dijkstra(int n, int v, double *dist, int *prev, double c[maxnum][maxnum])
{
    bool s[maxnum];    // �ж��Ƿ��Ѵ���õ㵽S������
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0;     // ��ʼ��δ�ù��õ�
        if(dist[i] == maxint)
            prev[i] = 0;
        else
            prev[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;

    // ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
    // һ��S����������V�ж��㣬dist�ͼ�¼�˴�Դ�㵽������������֮������·������
         // ע���Ǵӵڶ����ڵ㿪ʼ����һ��ΪԴ��
    for(i=2; i<=n; ++i)
    {
        double tmp = maxint;
        int u = v;
        // �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
                tmp = dist[j];
            }
        s[u] = 1;    // ��ʾu���Ѵ���S������

        // ����dist
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

// ���Ҵ�Դ��v���յ�u��·���������
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
    // �����鶼���±�1��ʼ

    cin >> n;// ��������
    cin >> line;// ����·����
    int p, q;
	double len;          // ����p, q���㼰��·������

    // ��ʼ��c[][]Ϊmaxint
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;

    for(i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;
        if(len < c[p][q])       // ���ر�
        {
            c[p][q] = len;      // pָ��q
            c[q][p] = len;      // qָ��p��������ʾ����ͼ
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

			// ���·������
		cout << "���·������: " << dist[120]<< endl;

				// ·��
		cout << "·��Ϊ: ";
		searchPath(prev, 94, 120);
		/*Dijkstra(120, 1, dist, prev, c);

		// ���·������
		cout << "���·������: " << dist[120] << endl;

		// ·��
		cout << "·��Ϊ: ";
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
				cout << "���·������: " << dist[j] << endl;
				cout << "·��Ϊ: ";
				searchPath(prev, i, j);
				//file<<"���·������: " << dist[j] << endl<< "·��Ϊ: ";
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
				cout << "���·������: " << dist[bb[j]]<< endl;
				cout << "·��Ϊ: ";
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
				cout << "���·������: " << dist[bbb[j]]<< endl;
				cout << "·��Ϊ: ";
				searchPath(prev,aaa[i],bbb[j]);
			}
		}
	}
	return 0;
}
