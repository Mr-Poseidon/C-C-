#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=105,M=205;

int n,m;
int w[N][N];
int dis[N];
bool vis[N];

void dijkstra()//朴素版dijkstra
{
    memset(dis,0x3f,sizeof dis);//距离初始化
    
    dis[1]=0;//起点距离为0
    
    for(int i=0;i<n;i++)//遍历每一个点
    {
        int t=-1;
        for(int j=1;j<=n;j++)//遍历每一个点，选出未处理的距离最小的点
            if(!vis[j] && (t==-1 || dis[j]<dis[t]))
                t=j;
        
        if(t==-1)break;//所有点都处理过
        vis[t]=true;//标记
        
        for(int j=1;j<=n;j++)//遍历该点到其他所有点的距离
            if(dis[t]+w[t][j]<dis[j])//更新
                dis[j]=dis[t]+w[t][j];
    }
    
}

int main()
{
    cin>>n>>m;
    
    memset(w,0x3f,sizeof w);//初始化图
    
    for(int i=0;i<m;i++)//输入图
    {
        int a,b,c;
        cin>>a>>b>>c;
        w[a][b]=w[b][a]=c;
    }
    
    dijkstra();

    //遍历所有的点，选出距离最大的点的距离即为结果
    int ans=-1;
    for(int i=1;i<=n;i++)ans=max(ans,dis[i]);
    
    if(ans==0x3f3f3f3f)puts("-1");//存在无法到达的点
    else cout<<ans<<endl;
    
    return 0;
}
