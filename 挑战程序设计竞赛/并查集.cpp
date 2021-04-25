#include<iostream>
using namespace std;

int par[100000];//父亲 
int rank[100000];//树的深度 

void init(int n)//初始化 
{
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
		rank[i]=0;
	}	
}

int find(int x)//查询树的根 
{
	if(par[x]==x)return x;
	else return par[x]=find(par[x]);
}

void unite(int x,int y)//合并x和y所属集合 
{
	x=find(x);
	y=find(y);
	if(x==y)return; 
	
	if(rank[x]<rank[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
} 

bool same(int x,int y)//判断是否同一个集合 
{
	return find(x)==find(y);
}

int main()
{
	return 0; 
} 
