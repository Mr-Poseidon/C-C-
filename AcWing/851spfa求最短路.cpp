#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=100010;

int h[N],e[N],w[N],ne[N],idx;
int dis[N];
bool vis[N];//判断某个点是不是在队中
int n,m;

void insert(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}


//spfa的算法复杂度为O(m),可能退化为O(nm)
//该算法在出现负权环的时候尽管会出现队列冗余、但不会进入死循环 
//spfa算法算是在 朴素dijkstra 和 堆优化版的dijkstra 之间的一种折中算法 
int spfa(int a,int b)
{
    memset(dis,0x3f,sizeof(dis));//初始化
    dis[a]=0;//起点距离为0
    
    //创建队列入队和标记,队列中存放距离被松弛过的点
    queue<int> q;
    q.push(a);
    vis[a]=true;
    
    while(!q.empty())
    {
        int t=q.front();//出队
        q.pop();
        vis[t]=false;
        
        for(int i=h[t];i!=-1;i=ne[i])//遍历所有该点可以到达的点
        {
            int j=e[i];
            if(dis[j]>dis[t]+w[i])//可以松弛
            {
                dis[j]=dis[t]+w[i];
                if(!vis[j])//如果不在队中
                {
                    vis[j]=true;//标记
                    q.push(j);//入队
                }
            }
        }
    }
    
    //存在负权边,所以dis>0x3f3f3f3f-1e9即为不可到达
    if(dis[b]>0x3f3f3f3f/2)return -1;
    else return dis[b];
}

int main()
{
    memset(h,-1,sizeof(h));//初始化邻接表
    scanf("%d%d",&n,&m);
    
    while(m--)//插入边
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        insert(a,b,w);
    }
    
    int t=spfa(1,n);
    
    if(t==-1)puts("impossible");
    else printf("%d",t);
    
    return 0;
}
