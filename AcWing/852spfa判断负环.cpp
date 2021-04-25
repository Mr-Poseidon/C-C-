#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=10010;

int h[N],e[N],w[N],ne[N],idx;
int dis[N],cnt[N];//dis[]维护距离，cnt[]维护经过的边的数量，当边数达到n时说明存在负环
bool vis[N];
int n,m;

void insert(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int spfa()
{
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    
    queue<int> q;
    for(int i=1;i<=n;i++)//全部入队，避免不是完全连通图
    {
        q.push(i);
        vis[i]=true;
    }
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        vis[t]=false;
    
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dis[j]>dis[t]+w[i])
            {
                dis[j]=dis[t]+w[i];
                cnt[j]=cnt[t]+1;
                
                if(cnt[j]>=n)return -1;//经过的边数到达n，说明存在负环、不存在最短路
                if(!vis[j])
                {
                    q.push(j);
                    vis[j]=true;
                }
            }
        }
    }
    
    return 1;//不存在负环 
}


int main()
{
    memset(h,-1,sizeof(h));
    
    scanf("%d%d",&n,&m);
    
    while(m--)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        insert(a,b,w);
    }
    
    if(spfa()==-1)puts("Yes");
    else puts("No");
    
    return 0;
}
