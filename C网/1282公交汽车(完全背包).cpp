/*
完全背包 
*/ 

#include<iostream>
#include<algorithm>
using namespace std;

int n,a[11],dp[12][102];

int main()
{
	for(int i=1;i<=10;i++)
		cin>>a[i];
	cin>>n;
	
	//注意此处和背包略有不同 
	for(int i=0;i<=n;i++)//数据初始化
		dp[0][i]=i*a[1];
	
	for(int i=1;i<=10;i++)//物品种类-车票种类 
	{
		for(int j=0;j<=n;j++)//背包容量遍历-车程遍历 
		{
			dp[i][j]=dp[i-1][j];
			int acount=j/i;
			for(int k=1;k<=acount;k++)//车票数量遍历 
				//状态转移方程 
				dp[i][j]=min( dp[i][j] , dp[i-1][j-i*k] + a[i]*k );
		}
	}
	cout<<dp[10][n]<<endl;
	return 0;
} 
