#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int N=100010;

int par[N];//par[k]存点k的父节点

int find(int x)//查根
{
    if(x==par[x])return x;
    return par[x]=find(par[x]);//路径压缩
}

void merge(int a,int b)//合并
{
    a=find(a);
    b=find(b);
    if(a==b)return;
    
    par[b]=a;
    return;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++)par[i]=i;//初始化
    
    char op[2];
    int a,b;
    while(m--)
    {
        scanf("%s",op);
        
        if(op[0]=='M')
        {
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        else
        {
            scanf("%d%d",&a,&b);
            if(find(a)==find(b))puts("Yes");//判断是否连通
            else puts("No");
        }
    }
    return 0;
}
