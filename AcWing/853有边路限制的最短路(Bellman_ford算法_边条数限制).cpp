#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510,M=10005;

//边
struct Edge{
    int a,b,w;//w代表a点到b点的距离
}e[M];

int dis[N],backup[N];//dis维护本次迭代的距离，backup维护上一次迭代的距离
int n,m,k;//n代表点数，m代表边数，k代表最多不经过多少条边（即最多的迭代次数）


//bellman_ford算法的特点：可以限制经过的边的数量
//算法时间复杂度O(nm) 
int bellman_ford(int a,int b)//a代表起点，b代表终点
{
    memset(dis,0x3f,sizeof dis);//初始化距离
    dis[a]=0;//起点距离为0
    
    for(int i=0;i<k;i++)//迭代
    {
        memcpy(backup,dis,sizeof dis);
        for(int j=0;j<m;j++)//遍历所有的边
        {
            int a=e[j].a,b=e[j].b,w=e[j].w;
            if(dis[b]>backup[a]+w)//松弛条件
                dis[b]=backup[a]+w;
        }
    }
    
    //本题若存在负权环，减去的值最大不超过500*10000=5e6,所以大于5e6即为无法到达
    if(dis[b]>0x3f3f3f3f/2)return -1;
    else return dis[b];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    
    for(int i=0;i<m;i++)//输入边
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        e[i]={a,b,c};
    }
    
    int t=bellman_ford(1,n);
    
    if(t==-1)puts("impossible");//输出结果
    else printf("%d",t);
    
    return 0;
}
