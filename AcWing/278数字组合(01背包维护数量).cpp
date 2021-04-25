#include<iostream>
#include<algorithm>
using namespace std;

const int N=10010;

int f[N];//f[i]维护和为i时的方案数
int n,m;

int main()
{
    cin>>n>>m;
    f[0]=1;//和为0时，不选也是一种方案
    
    for(int i=0;i<n;i++)//遍历数的个数
    {
        int v;
        cin>>v;
        for(int j=m;j>=v;j--)
            f[j]=f[j]+f[j-v];//选和不选的方案数总和
    }
    cout<<f[m];//输出
    return 0;
}
