#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=12,M=110,K=1<<10;
typedef long long LL;//本题数据量过大、结果溢出、所以要开LL

LL f[N][M][K];
vector<int> state;//维护所有的合法状态
vector<int> head[K];//head[i]维护所有可以转移到 i状态 的邻接表
int cnt[K];//cnt[i]维护 i这个状态 的1的个数、即摆放的国王的数量
int n,m;

/*
    本题中用状态中1的位置代表国王摆放的位置
    心得：
        1.处理合法的状态
        2.邻接表处理状态之间的转移关系
*/

//存在相邻的两个国王的状态是不合法的
bool check(int state)
{
    for(int i=0;i<n;i++)
        if((state>>i & 1) && (state>>(i+1) & 1))//判断进制中是否有相邻的两个1
            return false;//存在相邻的两个1
    return true;//不存在
}

//计算该状态的二进制中1的个数，即国王的个数
int count(int state)
{
    int ans=0;
    for(int i=0;i<n;i++)ans+=state>>i&1;
    return ans;
}

int main()
{
    cin>>n>>m;
    
    for(int i=0;i<(1<<n);i++)//过滤出所有的合法状态
        if(check(i))
        {
            state.push_back(i);
            cnt[i]=count(i);
        }
            
    
    // 处理出哪个合法的状态可以转移到 i这个状态 中来，相当于剪枝
    // a&b==0 保证了没有两个1在同一列，a|b 保证了没有两个1在同一行
    for(int i=0;i<state.size();i++)
        for(int j=0;j<state.size();j++)
        {
            int a=state[i],b=state[j];
            
            if(((a&b)==0) && (check(a|b)))
                head[i].push_back(j);
        }
    
    f[0][0][0]=1;//第0行，一个国王也不放，且状态是0 是合法的一种方案
    
    for(int i=1;i<=n+1;i++)//遍历每一行
        for(int j=0;j<=m;j++)//遍历改行可以放置的国王数量
            for(int a=0;a<state.size();a++)//遍历这种情况中的状态a
                for(vector<int>::iterator b=head[a].begin();b!=head[a].end();b++)//遍历可以到达状态a的所有合法状态
                {
                    int c=cnt[state[a]];//计算出当前a这个状态已经摆放的国王数量
                    
                    if(j>=c)//如果需要摆放的数量 大等于 已经摆放的
                        f[i][j][a]+=f[i-1][j-c][*b];//状态转移方程
                }
                
    cout<<f[n+1][m][0];//输出n+1行，总共摆放了m个国王，且最后一行没摆放、即状态为0的结果
    return 0;
}


