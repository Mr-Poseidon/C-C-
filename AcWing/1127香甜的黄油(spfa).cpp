#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=810,M=1500*2,INF=0x3f3f3f3f;
typedef long long ll;

int h[N],e[M],w[M],ne[M],idx;//邻接表
int cow[N];//维护每头牛所在的牧场
int dis[N];//维护距离
bool vis[N];//维护访问状态

int p,n,m;

void add(int a,int b,int c)//插入
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

ll spfa(int u)//以u为起点到每个点的距离
{
    //初始化距离和访问状态
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    
    queue<int> q;//处理起点
    q.push(u);
    dis[u]=0;
    vis[u]=true;
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        vis[t]=false;
        
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(dis[j]>dis[t]+w[i])
            {
                dis[j]=dis[t]+w[i];
                if(!vis[j])
                {
                    q.push(j);
                    vis[j]=true;
                }
            }
        }
    }
  
    //计算点u到每个奶牛所在牧场的总距离
    ll sum=0;
    for(int i=0;i<p;i++)
        sum+=dis[cow[i]];
    
    return sum;
}
int main()
{
    cin>>p>>n>>m;//输入
    for(int i=0;i<p;i++)cin>>cow[i];
    
    memset(h,-1,sizeof h);//初始化邻接表
    for(int i=0;i<m;i++)//输入图
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    
    ll ans=INF;//初始化结果
    for(int i=1;i<=n;i++)//以每一个点作为起点做spfa
    {
        ll t=spfa(i);
        if(t>INF)continue;//若距离超过INF说明有的点无法到达
        else ans=min(ans,t);//维护最短距离
    }
    
    cout<<ans;//输出结果
    return 0;
    
}

