#include<iostream>
#include<algorithm>
#define maxn 202
using namespace std;

int a[maxn],dp[maxn][maxn]={0},n,ans;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)//断环成链 
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int len=2;len<=n;len++)//区间大小枚举 
    {
        for(int i=1;i+len-1<2*n;i++)//区间起点枚举 
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)//左右子珠划分枚举 
            {
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);//状态转移方程 
            }
        }
    }
    for(int i=1;i<=n;i++)//所有链条的最大值枚举 
        ans=max(ans,dp[i][i+n-1]);
    cout<<ans;
    return 0;
    
}
