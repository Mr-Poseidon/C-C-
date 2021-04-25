#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

/*
    求方案数必须把数据先读进来
    背包问题物品顺序不影响最终的最大值
    从后往前求最值、然后从前往后判断该物品是否要选
    由于涉及到选还是不选、背包不能将 物品的维度 优化掉
*/

int f[N][N];
int v[N],w[N];
int n,m;

int main()
{
    cin>>n>>m;//输入数据
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    
    for(int i=n;i>0;i--)//从后往前做背包
        for(int j=0;j<=m;j++)//遍历体积
        {
            f[i][j]=f[i+1][j];//不选、继承上一个物品的价值
            if(j>=v[i])//可以选
                f[i][j]=max(f[i][j],f[i+1][j-v[i]]+w[i]);//判断最大值
        }
        
    
    //避免向下继承、所以要判断体积 j>=v[i]
        
    int j=m;//j代表体积
    for(int i=1;i<=n;i++)//从前往后判断 是否选 第i个物品
        if(j>=v[i] && f[i][j]==f[i+1][j-v[i]]+w[i])//如果选和不选结果一样、根据题目要求字典序最小、那必选
        {
            cout<<i<<" ";//输出选择的物品序号
            j-=v[i];//体积要减掉
        }
    
    return 0;
}
