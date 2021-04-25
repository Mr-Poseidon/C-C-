#include<iostream>
#include<cstring>
#define INF 1e7
using namespace std;

struct edge{
	int from,to,cost;
};


edge ed[10000];

int d[10000];
int v,e;

void shortest_path(int s)//从s到各点的最短权重（不存在负权环） 
{
	for(int i=0;i<v;i++)
		d[i]=INF;
	d[s]=0;
	
	while(1)//一直遍历所有边，直到不再进行松弛操作 
	{
		bool update=false;
		for(int i=0;i<e;i++)//遍历所有边 
		{
			edge e=ed[i];
			//起点距离存在，终点的距离>起点距离+该边权值 
			if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost)//松弛操作 
			{
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(update!=true)break;
	}
	return;
}
bool find_negative_loop()//判断是否存在负权环 
{
	memset(d,0,sizeof(d));
	
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<e;j++)
		{
			edge e=ed[j];
			if(d[e.to]>d[e.from]+e.cost)
			{
				d[e.to]=d[e.from]+e.cost;
				if(i==v-1)return true;//超出最大值，存在负权环 
			}	
		}
	}
	return false; 
} 
int main()
{
	return 0;
} 
