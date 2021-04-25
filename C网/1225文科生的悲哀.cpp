#include<iostream>
using namespace std;

int n,dp[10005][4]={0,0,0,0,1,1,1,1};//政治、历史、地理、综合 
int mod=7654321;

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=dp[i-1][1]%mod;
		dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
		dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
		dp[i][3]=dp[i-1][2]%mod;
	}
	cout<<dp[n][0];
	return 0;
	
}
