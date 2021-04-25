#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=20;

int n;
int q[N];//存放临时的序列
int w[5][N];//维护每一次最开始的序列

//q[i]+1=a[i+1] 说明q[i]的后继是合法的

int f()//估值函数
{
    int cnt=0;//维护不合法的后继个数
    for(int i=0;i+1<n;i++)
        if(q[i]+1!=q[i+1])
            cnt++;
    return (cnt+2)/3;//因为每次移动最多修复三个后继，所以最少都还需要操作 ( cnt+2 )/3 次
}

bool dfs(int u,int depth)//迭代加深、深搜
{
    if(u+f()>depth)return false;//本次的操作次数加上预估的最少的操作次数大于限制的层数、直接返回false
    if(f()==0)return true;//所有后继都是合法的
    
    for(int len=1;len<=n;len++)//遍历操作序列的长度
        for(int l=0;l+len-1<n;l++)//遍历起点
        {
            int r=l+len-1;//计算出终点
            
            for(int k=r+1;k<n;k++)//遍历插入的位置
            {
                memcpy(w[u],q,sizeof(q));//记录原本的序列
                
                //取出连续的一段并插入，q存放的是新的序列
                int x=l;
                for(int y=r+1;y<=k;y++,x++)q[x]=w[u][y];
                for(int y=l;y<=r;y++,x++)q[x]=w[u][y];
                if(dfs(u+1,depth))return true;
                
                memcpy(q,w[u],sizeof(w[u]));//恢复原本的序列
            }
        }
    return false;//搜索失败
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;//输入
        for(int i=0;i<n;i++)cin>>q[i];
        
        int depth=0;//迭代加深的层数
        while(depth<5)//在5层以内
        {
            if(dfs(0,depth))break;//可以到达就break
            depth++;
        }
        
        //输出结果
        if(depth<5)cout<<depth<<endl;
        else puts("5 or more");
    }
    return 0;
}
