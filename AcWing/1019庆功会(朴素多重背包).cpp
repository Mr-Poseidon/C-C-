#include<iostream>
#include<algorithm>
using namespace std;

const int M=6010;

int f[M];
int n,m;

int main()
{
    cin>>n>>m;
    
    for(int i=0;i<n;i++)//遍历物品个数
    {
        int v,w,s;//输入
        cin>>v>>w>>s;
        
        for(int j=m;j>=v;j--)//遍历体积
            for(int k=1;k<=s && k*v<=j ;k++)//遍历物品数量
                f[j]=max(f[j],f[j-k*v]+k*w);
    }
    cout<<f[m];//输出
    return 0;
}

