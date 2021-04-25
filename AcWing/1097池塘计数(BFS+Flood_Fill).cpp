#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define x first
#define y second

const int N=1010,M=N*N;
typedef pair<int,int> PII;

char g[N][N];//维护图
int n,m;
bool vis[N][N];//维护是否访问过

PII q[M];//维护单调队列
int hh,tt;

void bfs(int sx,int sy)//广搜搜索所有连通块
{
    hh=tt=0;
    q[tt++]={sx,sy};//起点入队
    vis[sx][sy]=true;//标记
    
    while(hh<tt)
    {
        PII p=q[hh++];//取队头
        
        for(int i=p.x-1;i<=p.x+1;i++)
            for(int j=p.y-1;j<=p.y+1;j++)
            {
                if(i==p.x && j==p.y)continue;//如果是本身、跳过
                if(i<0 || i>=n || j<0 || j>=m)continue;//越界、跳过
                if(g[i][j]=='W' && !vis[i][j])//是水池并且没有访问过
                {
                    q[tt++]={i,j};//入队
                    vis[i][j]=true;//标记
                }
            }
    }
}
int main()
{
    scanf("%d%d",&n,&m);//输入
    for(int i=0;i<n;i++)scanf("%s",g[i]);
    
    int cnt=0;
    for(int i=0;i<n;i++)//遍历每一个点
        for(int j=0;j<m;j++)
            if(g[i][j]=='W' && !vis[i][j])
            {
                bfs(i,j);
                cnt++;
            }
             
    printf("%d\n",cnt);//输出连通块数
    return 0;
}

