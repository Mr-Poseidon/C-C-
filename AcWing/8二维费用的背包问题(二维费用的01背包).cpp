#include<iostream>
#include<algorithm>
using namespace std;

const int N=110;

int f[N][N];
int n,V1,V2;

int main()
{
    cin>>n>>V1>>V2;
    
    for(int i=0;i<n;i++)//遍历物品数量
    {
        int v1,v2,w;//输入两个费用和价值
        cin>>v1>>v2>>w;
        
        for(int j=V1;j>=v1;j--)//二维01背包
            for(int k=V2;k>=v2;k--)
                f[j][k]=max(f[j][k],f[j-v1][k-v2]+w);//状态转移方程 
    }
    cout<<f[V1][V2];//输出结果
    return 0;
}
