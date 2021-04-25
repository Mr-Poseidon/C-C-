#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=20,M=1<<N;

int w[N][N];//维护点到点的权值
int f[M][N];//f[i][j]维护 i 这个状态中，从其他点走到 j 这个点的最短路径
int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)//输入权值图
        for(int j=0;j<n;j++)
            cin>>w[i][j];
    
    memset(f,0x3f,sizeof f);//求最小值，初始化最大值
    f[1][0]=0;//1代表0这个点已经走过、0走到0权值为0，0为起点
    
    for(int i=0;i<1<<n;i++)//遍历所有状态
        for(int j=0;j<n;j++)//遍历这个状态中可以作为终点的点
            if(i>>j&1)//如果这个点存在，就作为终点
                for(int k=0;k<n;k++)//遍历所有可能的上一个点
                //  if((i>>k&1)&&(j!=k)) ——此处也可写成这样 
                    if((i-(1<<j))>>k&1)//先扣去本身的点，避免自身转移，如果存在上一个点就转移
                        // i-(1<<j)扣掉终点的值即为上一个点的状态,k为上一个点的二进制位置
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+w[k][j]);
    
    // (1<<n)-1 表示所有点都走过的状态，n-1代表终点的点
    cout<<f[(1<<n)-1][n-1];
    return 0;
}
