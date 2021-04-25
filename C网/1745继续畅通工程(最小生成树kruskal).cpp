#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge{
	int v1,v2,cost;
};
bool cmp(edge a,edge b)
{
	return a.cost<b.cost;
}

int par[105];
int n,cot;
vector<edge> E;

void init(int n)//初始化并查集 
{
	E.clear();
	cot=0;
	for(int i=0;i<=n;i++)par[i]=i;
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
	cot--; 
}

int kruskal()//kruskal算法 
{
	sort(E.begin(),E.end(),cmp);//排序 
	int ans=0;//生成树的开销 
	
	for(int i=0;i<E.size();i++)
	{
		if(!same(E[i].v1,E[i].v2))//判断是否同集 
		{
			merge(E[i].v1,E[i].v2);//合并 
			ans+=E[i].cost;//加上开销 
		}
		if(cot==1)break;//连通量为1说明全部连通 
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
			int f;
			cin>>t.v1>>t.v2>>t.cost>>f;
			if(f==1)
				merge(t.v1,t.v2);
			else
				E.push_back(t);	
		}
		cout<<kruskal()<<endl;
	}
	
	return 0;
}
