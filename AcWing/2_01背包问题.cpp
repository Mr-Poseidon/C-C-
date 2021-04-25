#include<iostream>
#include<algorithm>
using namespace std;

const int N=1005;

int f[N];//优化成一维
int v[N],w[N];//v[i],w[i]维护物品的体积和价值
int n,m;//物品个数，背包容量


int main()
{
    cin>>n>>m;//输入
    for(int i=1;i<=n;i++)cin>>v[i]>>w[i];
    
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)//由于每次更新需要用到前面的数据、所以从后往前更新
            f[j]=max(f[j],f[j-v[i]]+w[i]);//状态转移方程
    
    cout<<f[m]<<endl;
    return 0;
}
