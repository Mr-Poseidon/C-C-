#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=110,M=N*2;

int h[N],e[M],w[M],ne[M],idx;//邻接表维护树
int f[N][N];//f[i][j]维护i这个点选择j个树枝的最大值
int n,m;//n个点、m个树枝

void add(int a,int b,int c)//插入邻接表
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int father)
{
    for(int i=h[u];~i;i=ne[i])//枚举每一个子节点
    {
        if(e[i]==father)continue;//跳过父节点
        
        dfs(e[i],u);//深搜
        
        //f[u][j]=max(f[u][j],f[u][j-k-1]+f[e[i]][k]+w[i]);
        //                    父节点选了j-k-1个树枝，子节点选了k个树枝，-1是因为还要加上本次的树枝(权值)
        for(int j=m;j>0;j--)//枚举背包体积------体积为0，即为不选、值必为0
            for(int k=0;k<=j-1;k++)//枚举物品个数------子节点最多选j-1个、因为本次也要占一个
                f[u][j]=max(f[u][j],f[u][j-k-1]+f[e[i]][k]+w[i]);//状态转移方程
    }
}

int main()
{
    memset(h,-1,sizeof h);//初始化邻接表
    
    cin>>n>>m;//输入
    for(int i=0;i<n-1;i++)//插入邻接表
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    
    dfs(1,-1);//深搜
    
    cout<<f[1][m];//输出结果
    return 0;
}
