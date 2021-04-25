#include<iostream>
#include<algorithm>
#define maxv 10000
#define INF 1e7
using namespace std;

int cost[maxv][maxv];//cost[i][j]-����i��j��Ȩֵ 
int mincost[maxv];//mincost[i]-����i�����СȨֵ 
bool used[maxv];//�Ƿ��߹� 
int V;//�������� 

int prim()//O(V^2)
{
	fill(mincost,mincost+V,INF);
	fill(used,used+V,false);
	
	mincost[0]=0;
	int ans=0;
	
	while(1)
	{
		int v=-1;
		for(int i=0;i<V;i++)//����ѡ����̾���� 
			if(!used[i] && (v==-1 || mincost[i]<mincost[v]))
				v=i;
		
		if(v==-1)break;
		used[v]=true;
		
		//�˴���Dijkkstra��ͬ 
		ans+=mincost[v];//����̾���ӵ����
		
		for(int i=0;i<V;i++)
			mincost[i]=min(mincost[i],cost[v][i]);
	}
	return ans;
}
 
int main()
{
	return 0;
}
