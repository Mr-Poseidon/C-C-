#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=50010;

int h[N],e[N],ne[N],idx;//邻接表维护树
int sum[N];//sum[i]维护数i的因数和
bool son[N];//son[i]判断数i是不是子节点、true是、false不是
int n;
int ans;//维护答案

void add(int a,int b)//插入邻接表
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u)//深搜
{
    int d1=0,d2=0;//最长、次长距离
    
    for(int i=h[u];~i;i=ne[i])//枚举所有子节点
    {
        int j=e[i];
        int d=dfs(j)+1;//所有子节点的变换次数 + 1等于本数的变换次数
        
        if(d>d1)d2=d1,d1=d;//更新最长、次长距离
        else if(d>d2)d2=d;
    }
    ans=max(ans,d1+d2);//更新直径
    
    return d1;//返回最长距离
}

int main()
{
    memset(h,-1,sizeof(h));//初始化邻接表
    
    cin>>n;
    for(int i=1;i<=n;i++)//枚举因子
        for(int j=2;j<=n/i;j++)//枚举i的j倍数
            sum[i*j]+=i;//加上i*j的因子i
    
    for(int i=2;i<=n;i++)//从2开始枚举，因为1的因数和为0，变换数字必须为正整数，所以1不行
        if(i>sum[i])//如果数i大于数i的因数和
        {
            add(sum[i],i);//添加
            son[i]=true;//标记
        }
    
    for(int i=1;i<=n;i++)//遍历所有的点
        if(!son[i])//不为子节点、即为根节点
            dfs(i);//深搜
    
    cout<<ans;//输出结果
    return 0;
}

