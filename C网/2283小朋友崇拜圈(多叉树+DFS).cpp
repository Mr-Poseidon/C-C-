#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int par[100005];//����С���ѵı�� 
int vis[100005];//�ж��Ƿ���ʹ����ջ� 
int ans=0;//�� 

void dfs(int x)
{
	if(vis[x]==1)return;//�ջ��е���,��֦,����ʱ 
	
	int v[100005]={0};//�ж��Ƿ��ڶ����� 
	queue<int> q;
	
	v[x]=1;
	q.push(x);
	
//	cout<<endl;
//	cout<<x<<" ";
	while(1)
	{
		x=par[x];
//		cout<<x<<" ";
		if(x==q.front())//����ص���ͷ˵���γ�Ȧ 
		{
			int t=q.size();
			ans=max(ans,t);//ȡ���ֵ 
			while(!q.empty())
			{
				vis[q.front()]=1;//��Ǳջ� 
				q.pop();
			}
			return;
		}
		
		if(v[x]==1)//�ڶ����У�˵��û���γ�Ȧ 
			return;
		
		v[x]=1;
		q.push(x);
	}
}

int main()
{
	int n;
	cin>>n;//���� 
	for(int i=1;i<=n;i++)
		cin>>par[i];
		

	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)//���� 
		dfs(i);
	
	cout<<ans<<endl;//��� 
	return 0;	
} 
