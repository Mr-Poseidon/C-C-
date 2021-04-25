#include<iostream>
#include<algorithm>
using namespace std;

int n,m,map[1005][1005];
int t,v;

int main()//朴素完全背包 
{
    cin>>n>>m;
    for(int i=0;i<=m;i++)
        map[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t>>v;//输入体积和价值 
        for(int j=0;j<=m;j++)
        {
            int acount=j/t;//计算物品可放置的最大数量 
            map[i][j]=map[i-1][j];//不放 
            for(int k=1;k<=acount;k++)
                if(j>=k*t)//思考：此处的判断是否可去掉！！！ 
                    map[i][j]=max(map[i][j],map[i-1][j-k*t]+k*v);//注意此处动态转移 
        }
    }
    cout<<map[n][m]<<endl;
    return 0;
}

/************************************分割线******************************************/                             
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1005;

int f[N];//优化成一维
int v[N],w[N];//维护物品的体积和价值
int n,m;//n个物品，m个空间

int main()//将完全背包的循环优化掉 
{
    cin>>n>>m;//输入
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    
    for(int i=1;i<=n;i++)
        for(int j=v[i];j<=m;j++)//根据完全背包公式、推出每次数据更新都需要用到前面的值、所以从前往后更新
            f[j]=max(f[j],f[j-v[i]]+w[i]);//状态转移方程
    
    cout<<f[m]<<endl;
    return 0;
}
