#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=105;

int w[N][N];//维护方格的费用
int f[N][N];//维护方格的最小值
int n;

int main()
{
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&w[i][j]);
    
    memset(f,0x3f,sizeof f);//维护最小值、初始化为最大值
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==1 && j==1)f[i][j]=w[i][j];//第一个格子最小值就是费用
            else
            {
                //控制边界，由于题目步数限制、所以只能 向下 或者 向右 走
                if(i>1)f[i][j]=min(f[i][j],f[i-1][j]);//从上面走下来
                if(j>1)f[i][j]=min(f[i][j],f[i][j-1]);//从左边走过来
                f[i][j]+=w[i][j];//加上本方格的费用
            }

    printf("%d",f[n][n]);//输出结果
    return 0;
}
