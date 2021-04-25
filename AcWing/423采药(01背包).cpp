#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=1010;

int f[N];//f[i]维护体积为i时背包可装的最大价值
int n,m;//n-物品个数，m-背包体积

int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)//遍历物品个数
    {
        int v,w;
        cin>>v>>w;//输入体积、权值
        
        for(int j=m;j>=v;j--)//更新01背包
            f[j]=max(f[j],f[j-v]+w);
    }
    
    cout<<f[m];//输出结果
    return 0;
}
