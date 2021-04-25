#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=410,INF=0x3f3f3f3f;//环形问题要开双倍空间

int f[N][N],g[N][N];//f[i][j]维护第i堆到第j堆石子的最小值，g[i][j]维护最大值
int w[N],s[N];//w[i]维护第i堆石子的权值，s[i]维护前缀和
int n;

int main()
{
    cin>>n;//输入
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        w[n+i]=w[i];//断环成链
    }
    
    for(int i=1;i<=2*n;i++)s[i]=s[i-1]+w[i];//前缀和
    
    //初始化
    memset(f,0x3f,sizeof f);
    memset(g,-0x3f,sizeof g);
    
    for(int len=1;len<=n;len++)//枚举长度
        for(int l=1;l+len-1<=n*2;l++)//枚举左端点
        {
            int r=l+len-1;//右端点,注意：上行右端点是可以到达最右边的终点的
            
            if(len==1)f[l][r]=g[l][r]=0;//长度为1，花费为0
            else//长度不为1就枚举断点
            {
                for(int k=l;k<r;k++)//枚举断点
                {
                    //状态转移方程，s[r]-s[l-1]代表本次合并需要花费的权值
                    f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);//维护最小值
                    g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]+s[r]-s[l-1]);//维护最大值
                }
            }
        }
        

    int minv=INF,maxv=-INF;//结果初始化
    for(int i=1;i<=n;i++)//枚举起点
    {
        minv=min(minv,f[i][i+n-1]);//求最小值
        maxv=max(maxv,g[i][i+n-1]);//求最大值
    }
    
    cout<<minv<<endl<<maxv;//输出
    return 0;
}



