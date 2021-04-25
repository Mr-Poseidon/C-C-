#include<iostream>
#include<algorithm>
#define maxv 1000
using namespace std;

int d[maxv][maxv];
int v;

/*
	执行一次可以算出 任意顶点 至 任意顶点 的最短距离
	距离不存在时设为INF
	可以处理存在 负边 的情况 
	执行后，若存在d[i][i]为负数，则存在负圈 
*/
void floyd_warshall()
{
	for(int k=0;k<v;k++)//必须先遍历经过点
		for(int i=0;i<v;i++)//起点遍历
			for(int j=0;j<v;j++)//终点遍历
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);//起点~经过点 + 经过点~终点 
}

int main()
{
	return 0;
}
