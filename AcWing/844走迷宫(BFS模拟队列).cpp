#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=105;
typedef pair<int,int> PII;

int n,m;
int g[N][N];//代表图
int vis[N][N];//记录是否访问过
int d[N][N];//各个点到起点的距离


PII q[N*N];//模拟队列
int hh,tt;
int dir[4][2]={0,1,1,0,0,-1,-1,0};//遍历的四个方向

void bfs()
{
    memset(vis,-1,sizeof(vis));//初始化记录
    //起点入队
    d[1][1]=0;
    q[0]={1,1};
    
    while(hh<=tt)//队不为空
    {
        PII p=q[hh++];
        
        for(int i=0;i<4;i++)
        {
            //求出下一个方向
            int x=p.first+dir[i][0];
            int y=p.second+dir[i][1];
            
            if(x>0 && x<=n && y>0 && y<=m && g[x][y]!=1 && vis[x][y]==-1)//下一个方向可以走
            {
                vis[x][y]=1;//记录该点
                d[x][y]=d[p.first][p.second]+1;//记录距离
                q[++tt]={x,y};//该点入队
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);//输入
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&g[i][j]);
            
    bfs();//广搜
    
    printf("%d",d[n][m]);//输出
    
    return 0;
}

