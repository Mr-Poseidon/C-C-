#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510;

int g[N][N];//g[a][b]代表从a到b的距离
int dis[N];//dis维护从某个点到达其他点的最短距离
bool vis[N];//判断是否访问过

int n,m;

int dijkstra(int a,int b)//a为起点，b为终点
{
    memset(dis,0x3f,sizeof dis);//初始化距离 
    dis[a]=0;//起点到自身的距离为0 
    
    for(int i=0;i<n;i++)//遍历所有的点
    {
        int t=-1;//标记变量，代表当前距离最短的点
        for(int j=1;j<=n;j++)//遍历所有的点
            if(!vis[j] && (t==-1 || dis[j]<dis[t]))//点未访问过或者距离不是最小
                t=j;
        
        vis[t]=true;//标记该点
        
        for(int j=1;j<=n;j++)//计算从该点出发到其他点的距离最小值
            dis[j]=min(dis[j],dis[t]+g[t][j]);
    }
    
    if(dis[b]==0x3f3f3f3f)return -1;//无法到达终点
    else return dis[b];//可以到达终点
}


int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);//初始化图
    
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=min(g[a][b],c);//重边取最小值
    }
    
    int t=dijkstra(1,n);
    
    printf("%d",t);
    
    return 0;
}

