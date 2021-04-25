#include<iostream>
#include<algorithm> 
#include<cstring>
#define maxn 100005
using namespace std;

typedef long long int ll;


struct Orders{
	ll ts,id;
};

ll n,m,t;
Orders ord[maxn];//订单 
ll f[maxn];//优先级 
ll q[maxn];//优先级队列 
ll is_ord[maxn];//某时刻是否有订单 


int main()
{
	memset(f,0,sizeof(f));
	memset(q,0,sizeof(q));
	
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
		cin>>ord[i].ts>>ord[i].id;
	
	for(int i=1;i<=t;i++)//时刻枚举 
	{
		memset(is_ord,0,sizeof(is_ord));//重置 
		
		for(int j=1;j<=m;j++)//遍历订单 
			if(ord[j].ts==i)
			{
				f[ord[j].id]+=2;//优先级+2 
				is_ord[ord[j].id]=1;//标记 
			}
			
		for(int j=1;j<=n;j++)//遍历商家 
		{
			if(f[j]>0 && is_ord[j]==0)//优先级>0又没有订单 
				f[j]--;
			
			if(f[j]>5)//加入优先级队列 
				q[j]=1;
			else if(f[j]<=3)//请出优先级队列
				q[j]=0;
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)//计算在优先队列中的商家 
		if(q[i]==1)
			ans++;
	cout<<ans;	
	return 0;
} 
