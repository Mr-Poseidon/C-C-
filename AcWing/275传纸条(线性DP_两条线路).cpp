#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=55;

int f[N*2][N][N];//f[k][i][j],k维护步数,i维护路线一的行,j维护路线二的行
int w[N][N];//维护权值
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>w[i][j];
    
    for(int k=2;k<=n+m;k++)//k同时代表两条路线的单独步数
        for(int i1=1;i1<=n;i1++)//i1代表路线一的行
            for(int i2=1;i2<=n;i2++)//i2代表路线二的行
            {
                int j1=k-i1,j2=k-i2;
                if(1<=j1 && j1<=m && 1<=j2 && j2<=m)
                {
                    
                    int t=w[i1][j1];
                    if(i1!=i2)t+=w[i2][j2];//不同的点才能传两次
                    
                    int &x=f[k][i1][i2];
                    x=max(x,f[k-1][i1-1][i2]);//下右
                    x=max(x,f[k-1][i1][i2-1]);//右下
                    x=max(x,f[k-1][i1-1][i2-1]);//下下
                    x=max(x,f[k-1][i1][i2]);//右右
                    
                    x+=t;//加上权值
                }
            }
    
    cout<<f[n+m][n][n];//输出结果
    return 0;
}
