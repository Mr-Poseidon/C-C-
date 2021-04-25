#include<iostream>
#include<algorithm>
using namespace std;

const int N=1010;

int a[4]={10,20,50,100};//代表书的价格

int f[N];//f[i]维护钱数为i时可购买的书的方案数
int m;

int main()
{
    cin>>m;
    f[0]=1;//钱数为0时不买也是一种方案
    
    for(int i=0;i<4;i++)//遍历书的种类
        for(int j=a[i];j<=m;j++)//遍历钱数、完全背包优化：从前往后遍历
            f[j]=f[j]+f[j-a[i]];//不买和买的方案数总和
    
    cout<<f[m];
    return 0;
}
