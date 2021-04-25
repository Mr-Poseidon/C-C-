#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510,M=100010;

int h[N],e[M],ne[M],idx;//邻接表
int match[N];//右半部点匹配的左半部的点
bool vis[N];//判断是否访问过
int n1,n2,m;

void add(int a,int b)//插入邻接表
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

bool find(int x)//查询左半部x点的匹配情况
{
    for(int i=h[x];i!=-1;i=ne[i])//遍历邻接表
    {
        int j=e[i];
        if(!vis[j])//未访问过
        {
            vis[j]=true;//标记
            //match可以存储之前左半部点的匹配情况
            if(match[j]==0 || find(match[j]))//如果右半部的点未匹配或者存在其他匹配
            {
                match[j]=x;//匹配
                return true;//返回可以匹配
            }
        }
    }
    return false;//无法匹配
}

int main()
{
    memset(h,-1,sizeof(h));
    
    scanf("%d%d%d",&n1,&n2,&m);
    
    while(m--)//输入边
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    
    int ans=0;
    for(int i=1;i<=n1;i++)//遍历左半部的点
    {
        memset(vis,false,sizeof vis);//初始化访问情况
        if(find(i))ans++;//存在匹配
    }
    
    printf("%d",ans);//输出答案
    return 0;
}
