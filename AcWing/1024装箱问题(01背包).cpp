#include<iostream>
#include<algorithm>
using namespace std;

const int N=20010;

//本题中的物品体积既是体积、又是价值

int f[N];//维护01背包
int n,m;

int main()
{
    cin>>m>>n;//输入体积、物品个数
    
    for(int i=0;i<n;i++)//遍历物品个数
    {
        int v;
        cin>>v;//输入体积
        
        for(int j=m;j>=v;j--)//维护01背包的最大值
            f[j]=max(f[j],f[j-v]+v);
    }
    
    cout<<m-f[m];//输出最小的剩余空间
    return 0;
}
