#include<iostream>
#include<algorithm>
using namespace std;

const int N=55,M=N*N;
typedef pair<int,int> PII;
#define x first
#define y second

int g[N][N];//维护每个房间的情况
bool vis[N][N];//维护房间是否被访问过
int n,m;

PII q[M];
int hh,tt;

int bfs(int sx,int sy)//广搜判断连通量，返回房间面积数量
{
    hh=tt=0;
    q[tt++]={sx,sy};//起点入队
    vis[sx][sy]=true;//标记
    
    int area=0;//房间面积
    int dir[4][2]={0,-1,-1,0,0,1,1,0};//四个方向
    while(hh<tt)
    {
        PII p=q[hh++];//出队
        area++;//出队的时候记录房间面积
        
        for(int i=0;i<4;i++)//遍历四个方向
        {
            int nx=p.x+dir[i][0],ny=p.y+dir[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//越界跳过
            if(vis[nx][ny])continue;//已经访问过、跳过
            if(g[p.x][p.y]>>i&1)continue;//存在墙面、跳过
            
            q[tt++]={nx,ny};//入队
            vis[nx][ny]=true;//标记
        }
    }
    return area;//返回房间面积
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)//输入每个房间的情况
        for(int j=0;j<m;j++)
            cin>>g[i][j];
            
    int cnt=0,area=0;//记录房间数和最大的房间面积
    for(int i=0;i<n;i++)//遍历每一个房间
        for(int j=0;j<m;j++)
            if(!vis[i][j])
            {
                cnt++;
                area=max(area,bfs(i,j));//维护最大的房间面积
            }
    
    cout<<cnt<<endl;//输出
    cout<<area<<endl;
    return 0;
}

