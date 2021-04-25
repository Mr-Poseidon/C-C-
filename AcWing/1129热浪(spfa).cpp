#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=2510,M=6200*2+10;//无向图边数*2

int n,m,S,T;
int h[N],e[M],w[M],ne[M],idx;
int dis[N];
int vis[N];

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void spfa()
{
    memset(dis,0x3f,sizeof dis);//初始化距离
    memset(vis,0,sizeof vis);//初始化访问情况
    queue<int> q;//队列
    
    dis[S]=0;
    q.push(S);
    vis[S]=true;
    
    while(!q.empty())
    {
        int t=q.front();//出队
        q.pop();
        vis[t]=false;//取消标记
        
        for(int i=h[t];~i;i=ne[i])//遍历所有邻接的点
        {
            int j=e[i];
            if(dis[t]+w[i]<dis[j])//存在更短路径
            {
                dis[j]=dis[t]+w[i];//更新
                if(!vis[j])//不再队列中
                {
                    q.push(j);//入队
                    vis[j]=true;//标记
                }
            }
        }
        
    }
}
int main()
{
    cin>>n>>m>>S>>T;//输入
    
    memset(h,-1,sizeof h);//初始化邻接表
    for(int i=0;i<m;i++)//输入图
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);//无向图
    }
    
    spfa();
    
    cout<<dis[T];
    return 0;
    
}
