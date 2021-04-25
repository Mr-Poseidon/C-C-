#include<iostream>
#include<algorithm> 
using namespace std;
const int N=1e7+5;

int par[N];
int si[N];

void init(int n)//初始化 
{
	for(int i=0;i<=n;i++)
	{
		par[i]=i;
		si[i]=1;
	}
}
int find(int n)//查根 
{
	if(par[n]!=n)return par[n]=find(par[n]);
	else return n;
}
void merge(int x,int y)//合并集合 
{
	x=find(x);
	y=find(y);
	if(x==y)return;
	
	par[y]=x;//将x的根赋给y 
	si[x]+=si[y];//维护集合大小 
}
int main()
{
	int n;
	while(cin>>n)
	{
		init(N);
		
		for(int i=0;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			merge(a,b);
		}
		
		int ans=0;
		for(int i=1;i<=N;i++)
			ans=max(ans,si[i]);
		cout<<ans<<endl;
	}
	return 0;
}
