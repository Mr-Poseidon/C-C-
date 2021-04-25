#include<iostream>
using namespace std;

const int N=155,M=N*N;
typedef pair<int,int> PII;
#define x first 
#define y second

int n,m;
char g[N][N];//维护图
bool vis[N][N];//维护是否访问过
int step[N][N];//维护步数

PII q[M];//单调队列
int hh,tt;

void bfs(int sx,int sy,int ex,int ey)
{
    hh=tt=0;
    q[tt++]={sx,sy};//起点入队
    vis[sx][sy]=true;//标记
    step[sx][sy]=0;//起点步数为0
    
    while(hh<tt)
    {
        PII p=q[hh++];
        
        if(p.x==ex && p.y==ey)return;//终点
        
        int dir[8][2]={-2,-1,-2,1,2,-1,2,1,-1,-2,1,-2,-1,2,1,2};//八个方向
        for(int i=0;i<8;i++)
        {
            int nx=p.x+dir[i][0],ny=p.y+dir[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//越界
            if(g[nx][ny]=='*' || vis[nx][ny])continue;//障碍物或者访问过
            
            q[tt++]={nx,ny};//入队
            vis[nx][ny]=true;//标记
            step[nx][ny]=step[p.x][p.y]+1;//记录步数
        }
    }
}

int main()
{
    cin>>m>>n;
    
    int sx,sy,ex,ey;//维护起点和终点坐标
    for(int i=0;i<n;i++)//输入
        for(int j=0;j<m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='K')//起点特殊处理
            {
                sx=i;
                sy=j;
                g[i][j]=='.';
            }
            if(g[i][j]=='H')//终点特殊处理
            {
                ex=i;
                ey=j;
                g[i][j]=='.';
            }
        }
        
    bfs(sx,sy,ex,ey);//广搜
    
    cout<<step[ex][ey];//输出终点步数
    return 0;
}
