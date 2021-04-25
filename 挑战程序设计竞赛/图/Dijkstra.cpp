
#include<iostream>
#include<algorithm>
#define maxv 10000
#define INF 1e7
using namespace std;

int cost[maxv][maxv];
int d[maxv];
int used[maxv];
int vx;


void dijkstra(int s)//O(V^2) 
{
	fill(used,used+vx,false);
	fill(d,d+vx,INF);
	
	d[s]=0;
	
	while(1)
	{
		int v=-1;
		for(int i=0;i<vx;i++)//选择没有使用过，且距离最小点 
			if(!used[i] && (v==-1 || d[i]<d[v]))
				v=i;
		
		if(v==-1)break;//所有点都使用过 
		used[v]=true;
		
		for(int i=0;i<vx;i++)//遍历所有与之相连的点 
			d[i]=min(d[i],d[v]+cost[v][i]);
	}
}

int main()
{
	return 0;
}


/* 
//堆优化版 
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define maxv 10000
#define INF 1e7
using namespace std;

struct edge{
	int to,cost;
};
typedef pair<int,int> P;//first-最短距离，second-顶点编号

int vx;
vector<edge> g[maxv];//邻接表-g[v][i]为顶点v到i的最短距离和权值 
int d[maxv];

void dijstra(int s)//O(E*logV) 
{
	//pair排序默认first小的在前，若first相等，则比较second 
	priority_queue< P,vector<P>,greater<P>() > que;
	fill(d,d+vx,INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty())
	{
		P p=que.top();
		que.pop();
		int v=p.second;//记录顶点 
		
		if(d[v]>p.first)//符合松弛条件 
		{
			for(int i=0;i<g[v].size();i++)
			{
				edge e=g[v][i];
				if(d[e.to]>d[v]+e.cost)
				{
					d[e.to]=d[v]+e.cost;
					que.push(P(d[e.to],e.to));
				}
			} 
		}
		else
			continue;
	}
}

int main()
{
	return 0;
} 
*/ 

