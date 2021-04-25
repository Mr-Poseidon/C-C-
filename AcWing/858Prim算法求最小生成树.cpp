#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510,INF=0x3f3f3f3f;

int g[N][N];
int dis[N];
bool vis[N];
int n,m;


int prim()
{
    memset(dis,0x3f,sizeof(dis));//初始化距离
    
    int sum=0;//最小生成树的大小
    for(int i=0;i<n;i++)//迭代n次
    {
        int t=-1;
        for(int j=1;j<=n;j++)//找距离最小、并且没有使用过的点
            if(!vis[j] && (t==-1 || dis[j]<dis[t]))
                t=j;
                
        vis[t]=true;//标记
        if(i && dis[t]==INF)return INF;//如果找到的点，距离无穷大、说明到达不了、没有最小生成树
        if(i)sum+=dis[t];//加入路径
        
        for(int j=1;j<=n;j++)//更新最小的点到其它点的距离
            dis[j]=min(dis[j],g[t][j]);
    }
    return sum;//返回最小生成树
}

int main()
{
    memset(g,0x3f,sizeof(g));//初始化邻接矩阵
    
    scanf("%d%d",&n,&m);
    
    while(m--)//输入边
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=g[b][a]=min(g[a][b],c);//重边取最小值，无向图两条边都要赋值
    }
    
    int t=prim();
    
    if(t==INF)puts("impossible");
    else printf("%d",t);
    
    return 0;
}
