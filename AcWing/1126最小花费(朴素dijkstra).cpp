#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2010;

double w[N][N];//维护点之间的汇率
double dis[N];//维护到各点之间的最大汇率
bool vis[N];
int n,m,A,B;

//因为要求最大汇率、所以维护最大值
void dijkstra()
{
    memset(dis,0,sizeof dis);
    dis[A]=1;
    
    for(int i=1;i<=n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!vis[j] && (t==-1 || dis[t]<dis[j]))
                t=j;
                
        vis[t]=true;
        
        for(int j=1;j<=n;j++)
            dis[j]=max(dis[j],dis[t]*w[t][j]);//状态转移方程
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    
    memset(w,0,sizeof w);//输入图
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        w[a][b]=w[b][a]=max(w[a][b],(100-c)/100.0);//维护最小值
    }
    scanf("%d%d",&A,&B);//输入两点
    
    dijkstra();
    
    printf("%.8lf",100.0/dis[B]);//输出结果
    return 0;
    
}
