#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=200010;

int f[N],w[N];//f[i]维护前i个烽火台中选择的最小值，w[i]维护第i个烽火台的权值
int n,m;
int q[N],hh,tt;//维护单调队列

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];//输入
    
    hh=tt=0;
    q[tt++]=0;//第0个烽火台也算
    for(int i=1;i<=n;i++)
    {
        if(hh<tt && q[hh]<i-m)hh++;//<号是在本身前面的m个数中维护最小值，<=是在本身前面m-1个数中维护最小值
        f[i]=f[q[hh]]+w[i];//在前面m个数中取最小值加上本身的权值可以实现 状态累加
        while(hh<tt && f[q[tt-1]]>f[i])tt--;//出队
        q[tt++]=i;//入队
    }
    
    int ans=2e9;
    for(int i=n-m+1;i<=n;i++)ans=min(ans,f[i]);//维护最小值
    cout<<ans;
    return 0;
}

