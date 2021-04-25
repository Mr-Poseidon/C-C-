#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=18;

int w[N],n,W;//w[i]维护第i只猫的权值，共n只猫，缆车最大重量W

int gw[N];//维护第i只缆车的目前的总重量
int gc,ans;//gc维护目前共有gc辆缆车，ans维护最少的缆车数量

void dfs(int kk)
{
    if(gc>=ans)return;//如果缆车数已经大于等于最小的情况，则停止搜索
    if(kk==n)//如果所有猫都安排完
    {
        ans=min(ans,gc);//维护最小值
        return;//返回
    }
    
    for(int i=0;i<gc;i++)//遍历每一组缆车的情况
        if(gw[i]+w[kk]<=W)//如果第kk只猫可以安排在第i辆缆车中
        {
            gw[i]+=w[kk];//标记
            dfs(kk+1);//深搜
            gw[i]-=w[kk];//取消标记
        }

    //租一辆新的缆车
    gw[gc]+=w[kk];//标记
    gc++;//缆车数量+1
    dfs(kk+1);//深搜
    gc--;//恢复缆车数量
    gw[gc]-=w[kk];//取消标记
    
    return;
}

int main()
{
    cin>>n>>W;//输入
    for(int i=0;i<n;i++)cin>>w[i];
    
    gc=0;//缆车数量初始化
    ans=n;//最多租赁n只缆车
    dfs(0);//深搜
    
    cout<<ans;//输出结果
    return 0;
}

