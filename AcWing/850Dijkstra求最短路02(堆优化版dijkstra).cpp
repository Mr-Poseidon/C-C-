#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=150010;
typedef pair<int,int> PII;

int h[N],e[N],w[N],ne[N],idx;//e[]代表下一个点，w[]代表该点到下一个点的距离
int dis[N];//dis[]代表起点至所有点的距离
bool vis[N];//判断是否访问过
int n,m;

int insert(int a,int b,int c)//插入边和权值
{
    //b代表下一个点、c代表a到b的距离
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

//堆优化版dijkstra算法时间复杂度为O(MlogM)
//该算法不能用在存在负权环的图中、否则会出现死循环 
int dijkstra(int a,int b)//a代表起点，b代表终点
{
    //初始化距离和访问情况
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    dis[a]=0;//起点距离为0
    
    //因为vector从尾部进出，所以用greater<>,注意和queue从尾部进头部出的结构区分开来
    priority_queue<PII,vector<PII>,greater<PII>> heap;//创建一个小根堆
    heap.push({0,a});//入队
    
    while(!heap.empty())
    {
        PII t=heap.top();
        heap.pop();
        
        int distance=t.first,v=t.second;
        if(vis[v])continue;//如果该点访问过,跳过
        vis[v]=true;//标记
        
        //此操作的时间复杂度为O(M)，因为总共只有M条边
        for(int i=h[v];i!=-1;i=ne[i])//遍历该点可以到达的所有点
        {
            int j=e[i];//下一个点
            if(dis[j]>distance+w[i])//从这个点到下一个点距离更短，会出现距离更短的原因是存在这条边
            {
                dis[j]=distance+w[i];//更新
                heap.push({dis[j],j});//入队，该操作时间复杂度为O(logM)
            }
        }
    }
    
    if(dis[b]==0x3f3f3f3f)return -1;//不存在最短距离
    else return dis[b];
}



int main()
{
    memset(h,-1,sizeof(h));//初始化邻接表
    
    scanf("%d%d",&n,&m);//输入点数和边数
    
    while(m--)//输入边和权值
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        insert(a,b,c);//插入边
    }
    
    int t=dijkstra(1,n);//计算最短距离
    
    printf("%d",t);
    return 0;
}
