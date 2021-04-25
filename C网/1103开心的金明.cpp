#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long int ll;

int n,m;
ll dp[26][30000];

int main()
{
	memset(dp,0,sizeof(dp));
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)//物品个数遍历 
	{
		int v,w;
		cin>>v>>w;
		for(int j=0;j<=n;j++)//价值遍历 
		{
			if(j>=v)
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v]+v*w);//状态转移 
			else
				dp[i][j]=dp[i-1][j];//状态转移 
		}
	}
	cout<<dp[m][n];//输出 
	return 0;
}
