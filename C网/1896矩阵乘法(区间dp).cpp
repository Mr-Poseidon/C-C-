#include<iostream>
#include<algorithm>
using namespace std;

long long int n,a[1005],dp[1005][1005];

int main()
{
	cin>>n;
	for(int i=1;i<=n+1;i++)
		cin>>a[i];

	//数据初始化
	for(int i=1;i<n;i++)//区间左边界 
		for(int j=i+1;j<=n;j++)//区间右边界 
			dp[i][j]=1e14; 
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
	
	for(int len=2;len<=n;len++)//区间大小枚举
		//区间起点枚举，注意 i+len-1 为区间结点，需要控制在n内 
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			for(int k=i;k<j;k++)//区间断点决策枚举 
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
		}
	cout<<dp[1][n];
	return 0;
}
