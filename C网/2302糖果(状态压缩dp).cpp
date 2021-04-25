#include<iostream>
#include<cstring>
using namespace std;

int n,m,k;
int s[105],dp[(1<<20)+5];

int main()//O(n*(2^m)) 
{
	memset(dp,-1,sizeof(dp));
	memset(s,-1,sizeof(s));
	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)//储存每包糖果的状态，并标记 
	{
		int sum=0;//集合的总状态 
		int t;
		for(int j=0;j<k;j++)
		{
			cin>>t;
			sum|=(1<<(t-1));//存入元素状态 
		}
		s[i]=sum;//储存状态 
		dp[sum]=1;//标记 
	}
	
	for(int i=0;i<n;i++)//输入状态枚举 
	{
		for(int j=0;j<(1<<m);j++)//所有集合状态枚举
		{
			if(dp[j]==-1)continue;
			if(dp[j|s[i]]==-1)dp[j|s[i]]=dp[j]+dp[s[i]];
			else dp[j|s[i]]=min(dp[j|s[i]],dp[j]+dp[s[i]]);
		} 
	}
	//根据不同的要求，可以输出不同元素状态下的结果 
	cout<<dp[(1<<m)-1];//代表全集状态的结果 
	return 0;
}
