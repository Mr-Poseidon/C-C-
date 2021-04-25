#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,l,k;
//dp[i][0或1] - 0代表不来，1代表来
//parent[i] - 存放i的父节点
//map[i] - 记录i点是否走过
int dp[6005][2],parent[6005],map[6005];

void dfs(int root,int n)
{
	map[root]=1;
	for(int i=1;i<=n;i++)//寻找子节点
	{
		if(parent[i]==root && map[i]==0)
		{
			dfs(i,n);
			dp[root][1]+=dp[i][0];//父来 
			//父不来，子可以来也可以不来
			dp[root][0]+=max(dp[i][1],dp[i][0]); 
		}
	}
}

int main()
{
	memset(dp,0,sizeof(dp));
	memset(parent,0,sizeof(parent));
	memset(map,0,sizeof(map));
	
	cin>>n;//员工数 
	for(int i=1;i<=n;i++)//对应员工的活跃值 
		cin>>dp[i][1];
	while(cin>>l>>k && l!=0 && k!=0)//员工对应的导师 
		parent[l]=k;
		
	for(int i=1;i<=n;i++)//找出根节点 
	{
		if(parent[i]==i)
		{
			k=i;
			break;
		}
	}
	dfs(k,n);//深搜 
	cout<<max(dp[k][0],dp[k][1]);//输出结果 
	return 0;
}

