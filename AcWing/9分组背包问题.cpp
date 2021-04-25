#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;

int v[N][N],w[N][N],s[N];//v[i][j]-第i组第j个物品的体积，v[i][j]-第i组第j个物品的价值，s[i]第i组的物品数量
int f[N];//f[i]维护体积为i时的最大价值
int n,m;//n组物品、背包体积为m


/*
    注：本题必须先遍历背包体积、再遍历每一组的每个物品
*/
int main()
{
    cin>>n>>m;//输入
    for(int i=1;i<=n;i++)//输入i组物品
    {
        cin>>s[i];//输入本组的物品个数
        for(int j=0;j<s[i];j++)//每个物品的体积和价值
            cin>>v[i][j]>>w[i][j];
    }
    
    for(int i=1;i<=n;i++)//遍历每一组物品
        for(int j=m;j>0;j--)//遍历体积
            for(int k=0;k<s[i];k++)//遍历本组物品中的每个物品
                if(v[i][k]<=j)//符合选择条件
                    f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);//状态转移
    
    cout<<f[m];//输出最大值
    return 0;
}
