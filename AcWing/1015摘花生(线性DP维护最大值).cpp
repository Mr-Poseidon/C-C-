#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=105;

int T,n,m;
int w[N][N];//维护权值
int f[N][N];//维护走到点（i，j）的最大值

int main()
{
    scanf("%d",&T);//输入数据组数
    
    while(T--)
    {
        scanf("%d%d",&n,&m);//输入矩阵大小
        
        for(int i=1;i<=n;i++)//输入图
            for(int j=1;j<=m;j++)
                scanf("%d",&w[i][j]);
                
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                f[i][j]=max(f[i-1][j],f[i][j-1])+w[i][j];//状态转移方程
                
        printf("%d\n",f[n][m]);//输出结果
    }
    return 0;
}
