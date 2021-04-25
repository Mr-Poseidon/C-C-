#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=100010,M=200010;//无向图、所以边的数量要开2倍

int h[N],e[M],ne[M],idx;//邻接表，
int color[N];//维护每个点的颜色
int n,m;

void add(int a,int b)//插入邻接表
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int u,int c)//u代表点，c代表颜色
{
    color[u]=c;//染色
    
    for(int i=h[u];i!=-1;i=ne[i])//遍历该点所有的邻接边
    {
        int j=e[i];
        if(!color[j])//未染色
        {
            if(!dfs(j,c*-1))return false;//深搜、并且变换颜色，若冲突，返回false
        }
        else if(color[j]==c)return false;//已经染色、和邻接点冲突，返回false
    }
    return true;//该点所有的邻接点染色都正确，返回true
}

int main()
{
    memset(h,-1,sizeof h);//邻接表初始化
    scanf("%d%d",&n,&m);
    
    while(m--)//输入边
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);//无向图要维护两条边
    }
    
    bool f=true;//标记变量
    for(int i=1;i<=n;i++)//遍历所有的点
    {
        if(!color[i])//如果没有染色
        {
            if(!dfs(i,1))//深搜染色，存在冲突
            {
                f=false;//改变标记
                break;
            }
        }
    }
    
    if(f)puts("Yes");//是二分图
    else puts("No");//不是二分图
    
    return 0;
}
