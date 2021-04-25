/*
lower_bound()计算下界
upper_bound()计算上界
equal_range()计算区间 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int n,len;
int a[1005],dp[1005];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	len=1;
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		//新数>=序列末尾的数,由于是不下降序列，存在相同的数，所以要= 
		if(a[i]>=dp[len]) 
			dp[++len]=a[i];//加入序列 
		else
		{
			//计算新数的上界下标
			int t=upper_bound(dp+1,dp+1+len,a[i])-dp;
			dp[t]=a[i];
		}
	}
	cout<<len<<endl;
	return 0;
}
