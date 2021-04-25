#include<iostream>
#include<cstring>
using namespace std;

const int N=100010;

int n,m;

int h[N],e[2*N],ne[2*N],idx;//邻接表
bool vis[N];//判断是否访问过

int q[N],hh,tt;//模拟队列
int d[N];//存储距离


void insert(int k,int x)//插入邻接表
{
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;
}

void bfs()
{
    
    d[1]=0;//从1开始，1的距离为0
    vis[1]=true;//标记
    q[0]=1;//入队
    
    while(hh<=tt)
    {
        int p=q[hh++];//出队
        
        if(p==n)//搜得到
        {
            cout<<d[p];
            return;
        }
        
        for(int i=h[p];i!=-1;i=ne[i])//广搜
        {
            int j=e[i];//邻接的节点
            if(!vis[j])//未访问过
            {
                d[j]=d[p]+1;//距离+1
                vis[j]=true;//标记
                q[++tt]=j;//入队
            }
        }
    }
    cout<<"-1";//搜不到
    return;
}

int main()
{
    memset(h,-1,sizeof(h));//初始化邻接表
    
    cin>>n>>m;//输入
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        insert(a,b);//有向图只插入一次
    }
    
    bfs();//广搜
    
    return 0;
}
