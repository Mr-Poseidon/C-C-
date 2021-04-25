#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=50;

int n,m;//n个物品，能承受的最大重量为m
int w[N];//维护各个物品的重量
int weights[1<<25],cnt;//维护第一次搜索，所有可能出现的结果
int ans=0;//维护最大值

void dfs1(int u,int s,int k)//u代表搜到第u个数，s代表前面几个数的总权值，k代表只能搜k个数
{
    if(u==k)//越界
    {
        weights[cnt++]=s;//记录
        return;
    }
    
    dfs1(u+1,s,k);//不选第u个数
    if(s<=m-w[u])dfs1(u+1,s+w[u],k);//选择第u个数，可行性剪枝：s+w[u]<=m,为了防止溢出，写成：s<=m-w[u]
}

void dfs2(int u,int s)
{
    if(u==n)
    {
        int k=upper_bound(weights,weights+cnt,m-s)-weights;//二分查找，返回大于m-s的第一个值的坐标
        ans=max(ans,s+weights[k-1]);//维护最大值，k-1即为小于等于m-s的最大的数的坐标
        return;
    }
    
    dfs2(u+1,s);//不选第u个数
    if(s<=m-w[u])dfs2(u+1,s+w[u]);//选择第u个数，可行性剪枝：s+w[u]<=m,为了防止溢出，写成：s<=m-w[u]
}

int main()
{
    cin>>m>>n;//输入
    for(int i=0;i<n;i++)cin>>w[i];
    
    //优化搜索顺序，从大到小开始搜索
    sort(w,w+n);//从小到大排序
    reverse(w,w+n);//翻转
    
    int k=n/2+2;//二分深搜
    
    dfs1(0,0,k);//第一次搜索
    
    sort(weights,weights+cnt);//排序
    cnt=unique(weights,weights+cnt)-weights;//去重
    
    dfs2(k,0);//第二次搜索
    
    cout<<ans;//输出结果
    return 0;
}

