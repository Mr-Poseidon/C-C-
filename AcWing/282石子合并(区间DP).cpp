#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=310;

int s[N];//维护前缀和
int f[N][N];//维护区间最小代价
int n;

int main()
{
    memset(f,0x3f,sizeof f);//求最小值，初始化为最大值
    
    cin>>n;//输入
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]+=s[i-1];//计算前缀和
        f[i][i]=0;//本身代价为0
    }
    
    for(int len=2;len<=n;len++)//遍历区间长度
        for(int i=1;i+len-1<=n;i++)//遍历区间起点
        {
            int j=i+len-1;//区间终点
            for(int k=i;k<j;k++)//枚举区间断点
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
        }
            
    
    cout<<f[1][n];//输出1-n这个区间的最小代价
    return 0;
}
