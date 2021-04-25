#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;
#define x first 
#define y second

const int N=1010,M=N*N;

int g[N][N];
bool vis[N][N];
int n;

PII q[M];
int hh,tt;
PII pre[N][N];

void bfs(int sx,int sy,int ex,int ey)
{
    hh=tt=0;
    q[tt++]={sx,sy};//起点入队
    vis[sx][sy]=true;//标记
    pre[sx][sy]={sx,sy};//起点的上一个点为本身
    
    while(hh<tt)
    {
        PII p=q[hh++];
        
        if(p.x==ex && p.y==ey)return;//如果已经搜到终点就结束搜索
        
        int dir[4][2]={-1,0,0,1,1,0,0,-1};//四个方向
        for(int i=0;i<4;i++)
        {
            int nx=p.x+dir[i][0],ny=p.y+dir[i][1];//下一个坐标
            
            if(nx<0 || nx>=n || ny<0 || ny>=n)continue;//越界
            if(g[nx][ny]==1 || vis[nx][ny])continue;//墙、或者已经走过
            
            q[tt++]={nx,ny};//入队
            vis[nx][ny]=true;//标记
            pre[nx][ny]=p;//记录下一个点由本点走过去
        }
    }
    return;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)//输入
        for(int j=0;j<n;j++)
            cin>>g[i][j];
    
    bfs(n-1,n-1,0,0);//广搜，从终点往回搜、方便输出路径
    
    //输出路径
    PII t={0,0};
    do
    {
        cout<<t.x<<" "<<t.y<<endl;
        t=pre[t.x][t.y];
    }while(t!=pre[t.x][t.y]);//当下一个路径等于本身就是终点
    cout<<n-1<<" "<<n-1;//输出终点
    
    return 0;
}
