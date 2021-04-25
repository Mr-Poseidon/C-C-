#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010,M=110,INF=0x3f3f3f3f;

//f[i][j][0]-前i天，已经进行了j次交易，并且手中 没有股票
//f[i][j][1]-前i天，已经进行了j次交易，并且手中 有股票
int f[N][M][2];
int w[N];
int n,m;

//定义:买入的时候就算一次交易

int main()
{
    cin>>n>>m;//输入
    for(int i=1;i<=n;i++)cin>>w[i];
    
    //初始化
    memset(f,-0x3f,sizeof f);
    for(int i=0;i<=n;i++)f[i][0][0]=0;//前i天中，进行0次交易，且手中没有股票是合法的
    
    for(int i=1;i<=n;i++)//遍历天数
        for(int j=1;j<=m;j++)//遍历交易次数
        {
            //状态转移方程
            f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]+w[i]);//不卖、卖出
            f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][0]-w[i]);//不买、买入
        }

        
    //最多进行m次交易、可能在少于m次交易的时候出现最大值
    int ans=0;
    for(int i=0;i<=m;i++)ans=max(ans,f[n][i][0]);//前n天中，进行了i次交易、且手中没有股票
    
    cout<<ans;//输出结果
    
    return 0;
    
}
