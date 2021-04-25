#include<iostream>
#include<algorithm>
using namespace std;

const int N=11,M=16;

int w[N][M];//维护每组物品的价值 
int f[N][M];//维护最优解、求方案不能优化掉第一维 
int way[N];//记录每组选择的物品序号 
int n,m;//n-物品组数，m-背包体积 

//注意：本题物品的体积（设备数）等于 物品的序号（第几个物品）

int main()
{
    cin>>n>>m;//输入
    for(int i=1;i<=n;i++)//遍历物品组数
        for(int j=1;j<=m;j++)//依次输入物品的价值
            cin>>w[i][j];
    
    for(int i=1;i<=n;i++)//遍历物品组数
        for(int j=m;j>=0;j--)//遍历背包体积
        {
            f[i][j]=f[i-1][j];//不选
            for(int k=1;k<=j;k++)//依次判断选哪个物品
                f[i][j]=max(f[i][j],f[i-1][j-k]+w[i][k]);
        }
    
    cout<<f[n][m]<<endl;//输出最优解
    
    //输出方案
    int j=m;//最大体积
    for(int i=n;i>0;i--)//从后往前遍历物品组
        for(int k=1;k<=j;k++)//遍历每组中的每个物品
            if(f[i][j]==f[i-1][j-k]+w[i][k])//判断是否继承
            {
                way[i]=k;//记录选择的物品
                j-=k;//扣掉体积，本题物品序号即为体积
                break;
            }
            
    for(int i=1;i<=n;i++)//输出方案
        cout<<i<<" "<<way[i]<<endl;
    
    return 0;
}
