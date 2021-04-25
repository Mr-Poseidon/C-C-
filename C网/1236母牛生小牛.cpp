#include<iostream>
using namespace std;

int n;
int dp[52][4]={0,0,0,0,1,0,0,0};

int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][1];
		dp[i][3]=dp[i-1][3]+dp[i-1][2];
		dp[i][0]=dp[i][3];
	}
	cout<<dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3];
	return 0;
} 
