#include<iostream>
#include<algorithm>
#define maxe 10000
#define maxv 10000
using namespace std;

struct edge{
	int v1,v2,cost;
};
bool cmp(edge a,edge b)
{
	return a.cost<b.cost;
}
edge es[maxe];
int V,E;


int par[maxv];
int rank[maxv];

void init_union_find(int v)///并查集初始化 
{
	for(int i=0;i<=v;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
	return;
} 
int find(int x)//查找根节点 
{
	if(par[x]==x)return x;
	else return par[x]=find(par[x]);
}
bool same(int x,int y)
{
	return find(x)==find(y);
} 
void unite(int x,int y)//合并两个集合 
{
	x=find(x);
	y=find(y);
	if(x==y)return;//同集 
	
	if(rank[x]<rank[y])
		rank[x]=y;
	else
	{
		rank[y]=x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
	return;
}

int kruskal()//O(E*logV)
{
	sort(es,es+E,cmp);//边的权值排序 
	init_union_find(V);//并查集初始化
	int ans=0;
	
	for(int i=0;i<E;i++)
	{
		edge e=es[i];
		if(!same(e.v1,e.v2))
		{
			unite(e.v1,e.v2);//合并集
			ans+=e.cost;
		}
	}
	return ans;
} 

int main()
{
	return 0;
} 
