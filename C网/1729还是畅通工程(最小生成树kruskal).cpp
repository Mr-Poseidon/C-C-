#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge{//边的结构体 
	int v1,v2,cost;
};
bool cmp(edge a,edge b)
{
	return a.cost<b.cost;
}

int n,par[105],countt;
vector<edge> E;//边栈 

int init(int n)//初始化 
{
	for(int i=0;i<=n;i++)par[i]=i;
	countt=n;
	E.clear();
}
int find(int x)//查根 
{
	if(x==par[x])return x;
	else return par[x]=find(par[x]);
}
bool same(int a,int b)//是否同集 
{
	return find(a)==find(b);
}
void merge(int a,int b)//合并 
{
	a=find(a);
	b=find(b);
	if(a==b)return;
	
	par[b]=a;
	countt--;
}

int kruskal()//kruskal算法 
{
	sort(E.begin(),E.end(),cmp);
	int ans=0;
	
	for(int i=0;i<E.size();i++)
	{
		if(!same(E[i].v1,E[i].v2))
		{
			merge(E[i].v1,E[i].v2);
			ans+=E[i].cost;
		}
		if(countt==1)break;
	}
	return ans;
}

int main()
{
	while(cin>>n && n!=0)
	{
		init(n);//初始化 
		
		for(int i=0;i<n*(n-1)/2;i++)//输入 
		{
			edge t;
			cin>>t.v1>>t.v2>>t.cost;
			E.push_back(t);
		}
		
		cout<<kruskal()<<endl;//输出最小生成树 
	}
	return 0;
}
