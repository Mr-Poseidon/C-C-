#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int N=100010;

//par[k]为k节点的父节点，si[k]为k节点所在连通块中点的数量
int par[N],si[N];
int n,m;

int find(int x)//查找根节点
{
    if(par[x]==x)return x;
    return par[x]=find(par[x]);//路径压缩
}

bool same(int a,int b)//判断是否连通
{
    return find(a)==find(b);
}

void merge(int a,int b)//合并
{
    a=find(a);
    b=find(b);
    if(a==b)return;//已经连通则返回
    
    par[a]=b;//将a所属连通块并入b中
    si[b]+=si[a];//维护b连通块中点的数量
    return;
}



int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++)par[i]=i,si[i]=1;
    
    char op[10];
    int a,b;
    
    while(m--)
    {
        scanf("%s",op);
        
        if(!strcmp(op,"C"))//合并操作
        {
            scanf("%d%d",&a,&b);
            merge(a,b);
        }
        else if(!strcmp(op,"Q1"))//查询是否连通操作
        {
            scanf("%d%d",&a,&b);
            if(same(a,b))puts("Yes");
            else puts("No");
        }
        else//查询连通块中的点数
        {
            scanf("%d",&a);
            printf("%d\n",si[find(a)]);
        }
    }
    return 0;
}
