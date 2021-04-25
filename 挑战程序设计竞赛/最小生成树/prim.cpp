#include<iostream>
#include<algorithm>
#define maxv 10000
#define INF 1e7
using namespace std;

int cost[maxv][maxv];//cost[i][j]-顶点i到j的权值 
int mincost[maxv];//mincost[i]-到达i点的最小权值 
bool used[maxv];//是否走过 
int V;//定点数数 

int prim()//O(V^2)
{
	fill(mincost,mincost+V,INF);
	fill(used,used+V,false);
	
	mincost[0]=0;
	int ans=0;
	
	while(1)
	{
		int v=-1;
		for(int i=0;i<V;i++)//遍历选择最短距离点 
			if(!used[i] && (v==-1 || mincost[i]<mincost[v]))
				v=i;
		
		if(v==-1)break;
		used[v]=true;
		
		//此处与Dijkkstra不同 
		ans+=mincost[v];//将最短距离加到结果
		
		for(int i=0;i<V;i++)
			mincost[i]=min(mincost[i],cost[v][i]);
	}
	return ans;
}
 
int main()
{
	return 0;
}
