#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=100010;

int h[N],e[2*N],ne[2*N],idx;//邻接表(于单链表一模一样)
int n,ans=N;
bool vis[N];//判断该节点是否遍历过


void insert(int k,int x)//邻接表插入操作
{
    e[idx]=x,ne[idx]=h[k],h[k]=idx++;
}

int dfs(int k)//深搜
{
    vis[k]=true;
    
    int sum=1,res=0;//sum代表以该节点为根的数的总节点数，该节点本身为1
    
    for(int i=h[k];i!=-1;i=ne[i])//遍历该节点连接的所有子树
    {
        int j=e[i];//取值
        if(!vis[j])//该点未遍历过
        {
            int t=dfs(j);//深搜
            res=max(res,t);//取子树的最大节点数
            sum+=t;//加上子树的节点数
        }
        
    }
    res=max(res,n-sum);//n-sum为去掉以该节点为根的树的另一棵树的节点数
    ans=min(ans,res);//取最小的节点数
    return sum;//返回以该点为根节点的树的节点数
}

int main()
{
    cin>>n;
    
    memset(h,-1,sizeof(h));//初始化邻接表，-1为表尾
    
    for(int i=0;i<n;i++)//输入
    {
        int a,b;
        cin>>a>>b;
        insert(a,b);
        insert(b,a);
    }
    
    dfs(1);//深搜
    
    cout<<ans;//输出
    
    return 0;
}
