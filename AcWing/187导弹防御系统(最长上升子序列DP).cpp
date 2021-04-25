#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;

int a[N];
int n;
int f[N],g[N];//f[]维护最长上升子序列，g[]维护最长下降子序列
int ans;

void dfs(int i,int su,int sd)//深搜
{
    if(su+sd>=ans)return;//注意此处剪枝，若su+sd>n会超时,注意是>=,等于没写也超时
    if(i==n)//终点
    {
        ans=su+sd;
        return;
    }
    
    int k=0,t;
    while(k<su && f[k]>=a[i])k++;//查找可以插入的序列
    t=f[k];//保存现场
    f[k]=a[i];//更新
    if(k==su) dfs(i+1,su+1,sd);//深搜
    else dfs(i+1,su,sd);
    f[k]=t;//恢复现场

    
    k=0;
    while(k<sd && g[k]<=a[i])k++;//查找可以插入的序列
    t=g[k];//保存现场
    g[k]=a[i];//更新
    if(k==sd) dfs(i+1,su,sd+1);//深搜
    else dfs(i+1,su,sd);
    g[k]=t;//恢复
}

int main()
{
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++)cin>>a[i];
        
        ans=n;//初始化最小值
        dfs(0,0,0);//深搜
        
        cout<<ans<<endl;//输出结果
    }
    return 0;
}
