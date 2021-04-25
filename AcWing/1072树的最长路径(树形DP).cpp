#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=10010,M=20010;

int h[N],e[M],w[M],ne[M],idx;//邻接表维护树 
int n;
int ans;//维护直径

void add(int a,int b,int c)//插入邻接表
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int father)//深搜
{
    //初始化为0可以避免负权路径
    int dist=0;//代表从当前节点往下走的最长路径
    int d1=0,d2=0;//代表往下走的两条最长路径和次长路径
    
    for(int i=h[u];i!=-1;i=ne[i])//遍历每一个子节点
    {
        int j=e[i];
        if(j==father)continue;//若下一个节点是根节点、则跳过
        int d=dfs(j,u)+w[i];//下一个点往下走的最长路径+两点之间的权值
        dist=max(dist,d);//判断是不是最长
        
        if(d>=d1)d2=d1,d1=d;//维护两个最长路径
        else if(d>d2)d2=d;
    }
    
    ans=max(ans,d1+d2);//维护最长直径，如果是直径上面的点就会更新，否则不会更新
    return dist;
}
int main()
{
    memset(h,-1,sizeof h);//初始化邻接表
    
    cin>>n;//输入
    for(int i=0;i<n-1;i++)//插入邻接表,注意：只有n-1条无向边
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);//树的边是无向边、所以要插入两条边
        add(b,a,c);
    }
    
    dfs(1,-1);//深搜
    
    cout<<ans;//输出结果
    return 0;
}

