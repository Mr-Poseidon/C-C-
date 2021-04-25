#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=25;

char g[N][N];//维护图
bool vis[N][N];//维护访问情况
int n,m;

int dfs(int x,int y)//深搜，返回访问的点的数量
{
    int ans=1;//本身就是一个点
    vis[x][y]=true;//标记
    
    int d[4][2]={0,-1,-1,0,0,1,1,0};//四个方向
    for(int i=0;i<4;i++)
    {
        int nx=x+d[i][0],ny=y+d[i][1];
        
        if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//越界
        if(vis[nx][ny] || g[nx][ny]=='#')continue;//访问过或者是障碍
        
        ans+=dfs(nx,ny);//深搜
    }
    return ans;//返回结果
}

int main()
{
    while(cin>>m>>n && n && m)//多组测试数据
    {
        for(int i=0;i<n;i++)cin>>g[i];//输入图
        
        int x,y;
        for(int i=0;i<n;i++)//寻找起点
            for(int j=0;j<m;j++)
                if(g[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
        
        memset(vis,0,sizeof vis);//初始化访问情况
        cout<<dfs(x,y)<<endl;//深搜并输出结果
    }
    return 0;
}
