
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
		for(int i=0;i<vx;i++)//ѡ��û��ʹ�ù����Ҿ�����С�� 
			if(!used[i] && (v==-1 || d[i]<d[v]))
				v=i;
		
		if(v==-1)break;//���е㶼ʹ�ù� 
		used[v]=true;
		
		for(int i=0;i<vx;i++)//����������֮�����ĵ� 
			d[i]=min(d[i],d[v]+cost[v][i]);
	}
}

int main()
{
	return 0;
}


/* 
//���Ż��� 
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
typedef pair<int,int> P;//first-��̾��룬second-������

int vx;
vector<edge> g[maxv];//�ڽӱ�-g[v][i]Ϊ����v��i����̾����Ȩֵ 
int d[maxv];

void dijstra(int s)//O(E*logV) 
{
	//pair����Ĭ��firstС����ǰ����first��ȣ���Ƚ�second 
	priority_queue< P,vector<P>,greater<P>() > que;
	fill(d,d+vx,INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty())
	{
		P p=que.top();
		que.pop();
		int v=p.second;//��¼���� 
		
		if(d[v]>p.first)//�����ɳ����� 
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

