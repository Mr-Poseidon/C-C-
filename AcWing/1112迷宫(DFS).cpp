#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=110;

char g[N][N];//维护图
bool vis[N][N];//维护是否访问过
int T,n;
int ax,ay,bx,by;

bool dfs(int x,int y)//深搜
{
    if(x<0 || x>=n || y<0 || y>=n)return false;//越界
    if(vis[x][y])return false;//访问过了
    if(g[x][y]=='#')return false;//障碍
    
    if(x==bx && y==by)return true;//终点
    
    vis[x][y]=true;//标记
    
    int d[4][2]={0,-1,-1,0,0,1,1,0};
    
    for(int i=0;i<4;i++)//遍历四个方向
    {
        int nx=x+d[i][0],ny=y+d[i][1];
        
        if(dfs(nx,ny))return true;//下一个方向深搜
    }
    
    return false;//四个方向都没办法走到
}

int main()
{
    cin>>T;
    while(T--)//多组测试数据
    {
        cin>>n;//输入
        for(int i=0;i<n;i++)cin>>g[i];
        cin>>ax>>ay>>bx>>by;
        
        memset(vis,0,sizeof(vis));//标记初始化
        
        if(dfs(ax,ay))puts("YES");//可以到达
        else puts("NO");//无法到达
    }
    return 0;
}
