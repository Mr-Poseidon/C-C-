#include<iostream>
#include<algorithm>
#define maxn 202
using namespace std;

int n,a[maxn],dp[maxn][maxn]={0},ans=0;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];//断环成链
    }
       
    
    for(int len=2;len<=n;len++)//合并区间大小枚举
    {
        for(int i=1;i+len-1<2*n;i++)//区间起点枚举
        {
            int j=i+len-1;//区间终点
            for(int k=i;k<j;k++)//区间划分枚举:将区间分成 i~k 和 k+1~j 左右两个部分
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);//状态转移公式 
        }
    }
    
    for(int i=1;i<=n;i++)//枚举所有可能的结果
        ans=max(ans,dp[i][i+n-1]);
    cout<<ans;
    return 0;
}
