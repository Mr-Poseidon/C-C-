#include<iostream>
#include<cstring>
using namespace std;

const int N=100010;

int h[N],e[N*2],ne[N*2],idx;//邻接表
int q[N],hh,tt;//模拟队列

int in[N];//入度
int n,m;

void insert(int a,int b)//插入邻接表
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int topsort()//拓扑排序
{
    //将所有入度为0的点入队
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            q[tt++]=i;
        
    while(hh<tt)
    {
        int p=q[hh++];
        
        for(int i=h[p];i!=-1;i=ne[i])//遍历p点走向的所有节点
        {
            int j=e[i];
            in[j]--;//该点入度-1
            
            if(in[j]==0)q[tt++]=j;//入度为0，入队
        }
    }
    
    return tt==n;//一共有tt为n说明有n-1个点入队、全部节点入队，存在拓扑排序
}

int main()
{
    memset(h,-1,sizeof h);//初始化邻接表
    
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        insert(a,b);//有向图只插入一次
        in[b]++;//入度节点+1
    }
    
    if(topsort())//存在拓扑排序
    {
        for(int i=0;i<n;i++)printf("%d ",q[i]);//输出
        puts("");
    }
    else puts("-1");//不存在拓扑排序
    
    return 0;
}

