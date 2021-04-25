#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=10010,M=N*2,INF=0x3f3f3f3f;


int h[N],e[M],w[M],ne[M],idx;//邻接表维护树 
int d1[N],d2[N],p1[N],p2[N];//d1,d2维护最长、次长路径长度，P1,p2维护最长、次长路径的方向 
int up[N];//up维护向上走的路径长度 
int n;

void add(int a,int b,int c)//插入邻接表 
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs_d(int u,int father)//求向下走的最长路径
{
    d1[u]=d2[u]=-INF;//向下走的两条路径初始化
    
    for(int i=h[u];i!=-1;i=ne[i])//遍历每个子节点
    {
        int j=e[i];
        if(j==father)continue;//父节点就跳过
        
        int d=dfs_d(j,u)+w[i];//求出子节点的最长路径+该边权值、就是本个节点的最长路径
        
        if(d>=d1[u])//本条路径现在是最长的
        {
            d2[u]=d1[u],d1[u]=d;//维护两条最长路径
            p2[u]=p1[u],p1[u]=j;//维护路径的方向
        }
        else if(d>d2[u])d2[u]=d,p2[u]=j;//维护次长路径与方向
    }
    
    if(d1[u]==-INF)d1[u]=d2[u]=0;//没有更新、说明是叶子节点、向下的最长、次长路径都为0
    
    return d1[u];//返回最长向下路径
}

void dfs_u(int u,int father)//求向上走的最长路径
{
    //if(father==-1)up[u]=0;//根节点向上的路径为0
    
    for(int i=h[u];i!=-1;i=ne[i])//遍历所有子节点
    {
        int j=e[i];
        if(j==father)continue;//父节点就跳过
        
        //子节点向上走的最大路径=max(根节点的向上路径 , 根节点的向下路径（其中包括本个子节点，注意分情况）)
        /*
            如果子节点 是 根节点最长向下路径中的一个节点，子节点向上路径则为：
                max(根节点次长向下路径，根节点向上路径)+边权值
            否则，如果子节点 不是 根节点最长向下路径中的一个节点，子节点向上路径则为：
                max(根节点最长向下路径，根节点向上路径)+边权值)
        */
        if(p1[u]==j)up[j]=max(up[u],d2[u])+w[i];//子节点在最长路径中
        else up[j]=max(up[u],d1[u])+w[i];//子节点不在最长路径中
        
        dfs_u(j,u);//继续向下更新 子节点的子节点 向上走的路径
    }
}

int main()
{
    memset(h,-1,sizeof h);//初始化邻接表
    
    cin>>n;//输入
    for(int i=0;i<n-1;i++)//插入邻接表
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);//无向边、插入两次
    }
    
    dfs_d(1,-1);//必须先算出所有向下走的路径
    
    dfs_u(1,-1);//更新向上走的路径
    
    int ans=INF;
    for(int i=1;i<=n;i++)ans=min(ans,max(up[i],d1[i]));//向上走或者向下走求最大值、再从最大值中维护最小值
    
    cout<<ans;//输出结果
    return 0;
}
