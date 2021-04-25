#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=6010;

int h[N],e[N],ne[N],idx;//维护邻接表
int happy[N];//维护每个人的快乐值
int f[N][2];//f[i][0]代表 不选 i这个人的快乐值，f[i][1]代表 选 i这个人的快乐值
bool has_father[N];//维护某点是否有父节点
int n;

void insert(int a,int b)//插入邻接表
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int k)//深搜
{
    if(f[k][0]!=0)return;//如果该点已经走过、直接返回
    
    f[k][1]=happy[k];//选择k这个人要加上k的快乐值
    
    for(int i=h[k];i!=-1;i=ne[i])//遍历k的子节点
    {
        int j=e[i];
        
        dfs(j);//深搜j点
        
        f[k][0]+=max(f[j][0],f[j][1]);//不选k时，k的子节点可以选也可以不选
        f[k][1]+=f[j][0];//选k时，k的子节点只能不选
    }
}

int main()
{
    memset(h,-1,sizeof h);//初始化邻接表
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>happy[i];//输入每个人的快乐值
    
    for(int i=0;i<n-1;i++)//输入邻接表
    {
        int a,b;
        cin>>a>>b;
        insert(b,a);
        has_father[a]=true;//记录该点有父节点
    }
    
    int root;
    for(int i=1;i<=n;i++)//找到根节点，即上司
        if(!has_father[i])
            root=i;
    
    dfs(root);//由根节点开始向下深搜
    
    printf("%d",max(f[root][0],f[root][1]));//根节点选与不选的最大值即为答案
    return 0;
}

