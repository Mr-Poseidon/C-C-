#include<cstdio>
#include<iostream>
using namespace std;

typedef pair<int,int> PII;
#define x first 
#define y second
const int N=1010,M=N*N;

char g[N][N];
bool vis[N][N];
int step[N][N];
int n,m;

PII q[M];
int hh,tt;

//单源起点、多源终点、可以将终点看成起点、反向BFS即可求出答案

int main()
{
    cin>>n>>m;//输入图
    for(int i=0;i<n;i++)scanf("%s",g[i]);
    
    hh=tt=0;//初始化单调队列
    for(int i=0;i<n;i++)//将所有为1的点入队、并标记、初始化步数为0
        for(int j=0;j<m;j++)
            if(g[i][j]=='1')
            {
                q[tt++]={i,j};
                vis[i][j]=true;
                step[i][j]=0;
            }
            
    //BFS
    while(hh<tt)
    {
        PII p=q[hh++];
        
        int d[4][2]={0,-1,-1,0,0,1,1,0};
        
        for(int i=0;i<4;i++)//遍历四个方向
        {
            int nx=p.x+d[i][0],ny=p.y+d[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//越界
            if(vis[nx][ny])continue;//访问过
            
            q[tt++]={nx,ny};//入队
            vis[nx][ny]=true;//标记
            step[nx][ny]=step[p.x][p.y]+1;//距离+1
        }
    }
    
    for(int i=0;i<n;i++)//输出所有的距离情况
    {
        for(int j=0;j<m;j++)cout<<step[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
