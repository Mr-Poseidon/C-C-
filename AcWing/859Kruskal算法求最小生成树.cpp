#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010,M=200010;

struct Edge{
    int a,b,w;//代表a到b的权值为w
    
    bool operator<(const Edge &e)const{
        return w<e.w;
    }
}e[M];//维护边的数据

int par[N];//维护并查集
int n,m;

int find(int x)//查根
{
    if(par[x]==x)return x;
    return par[x]=find(par[x]);
}

int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<m;i++)//输入边
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        e[i]={a,b,w};
    }
    
    sort(e,e+m);//排序
    for(int i=0;i<=n;i++)par[i]=i;//并查集初始化
    
    //sum代表最小生成树的值，cnt代表树中边的数量
    //最小生成树一定由n-1条边构成、若边数小于n-1说明图不完全连通,无法构成最小生成树
    int sum=0,cnt=0;
    for(int i=0;i<m;i++)//遍历每一条边
    {
        int a=e[i].a,b=e[i].b,w=e[i].w;
        
        a=find(a),b=find(b);
        if(a!=b)//若不在同一个集合中、说明还未连通
        {
            par[a]=b;//合并
            sum+=w;//权值加入最小生成树中
            cnt++;//边数+1
        }
    }
    
    if(cnt<n-1)puts("impossible");//不存在最小生成树
    else printf("%d",sum);//存在、输出
    
    return 0;
}
