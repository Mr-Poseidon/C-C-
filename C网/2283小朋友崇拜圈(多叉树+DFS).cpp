#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int par[100005];//存崇拜小朋友的编号 
int vis[100005];//判断是否访问过，闭环 
int ans=0;//答案 

void dfs(int x)
{
	if(vis[x]==1)return;//闭环中的数,剪枝,否则超时 
	
	int v[100005]={0};//判断是否在队列中 
	queue<int> q;
	
	v[x]=1;
	q.push(x);
	
//	cout<<endl;
//	cout<<x<<" ";
	while(1)
	{
		x=par[x];
//		cout<<x<<" ";
		if(x==q.front())//如果回到队头说明形成圈 
		{
			int t=q.size();
			ans=max(ans,t);//取最大值 
			while(!q.empty())
			{
				vis[q.front()]=1;//标记闭环 
				q.pop();
			}
			return;
		}
		
		if(v[x]==1)//在队列中，说明没有形成圈 
			return;
		
		v[x]=1;
		q.push(x);
	}
}

int main()
{
	int n;
	cin>>n;//输入 
	for(int i=1;i<=n;i++)
		cin>>par[i];
		

	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)//深搜 
		dfs(i);
	
	cout<<ans<<endl;//输出 
	return 0;	
} 
