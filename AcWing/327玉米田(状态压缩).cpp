#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=15,M=12,mod=1e8;

int f[N][1<<M];//f[i][a]维护前i行状态为a的方案数
int w[N];//w[i]维护第i行的非法状态（1代表非法、不肥沃；0代表合法、肥沃）
vector<int> state;//维护所有合法状态
vector<int> head[1<<M];//邻接表维护状态之间的转移关系
int n,m;

//注意： == 的优先级大于 & 所有有用到 & 的地方都要加（） 
 
//判断该状态是否有两个相邻的1
bool check(int state)
{
    for(int i=0;i<m;i++)
        if((state>>i & 1) && (state>>(i+1) & 1))
            return false;
    return true;
}

int main()
{
    cin>>n>>m;//输入
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)//记录所有非法土地
        {
            int t;
            cin>>t;
            w[i]<<=1;
            w[i]+=t;
        }
        w[i]=~w[i];//将记录取反、即1代表非法、0代表合法可以种植
    }
    
    //筛选出所有合法状态
    for(int i=0;i<(1<<m);i++)
        if(check(i))
            state.push_back(i);
    
    //筛选出每一个状态可以从哪个上一个状态合法转移过来
    for(int i=0;i<state.size();i++)//遍历每个状态a
        for(int j=0;j<state.size();j++)//遍历每个状态b
            if((state[i]&state[j])==0)//判断状态b是否能转移到a
                head[i].push_back(j);//是的话记录状态下标
    
    f[0][0]=1;//最开始那一行什么都不种是合法的一种方案
    for(int i=1;i<=n+1;i++)//遍历每一行
        for(int a=0;a<state.size();a++)//遍历所有状态
            if((state[a]&w[i])==0)//判断该状态是否冲突、即种在了非法（不肥沃）的土地上
                for(vector<int>::iterator b=head[a].begin();b!=head[a].end();b++)//*b代表的是可以合法转移到状态state[a]的下标
                    f[i][state[a]]=(f[i][state[a]]+f[i-1][state[*b]])%mod;//状态转移方程
    
    cout<<f[n+1][0];//输出所有可行的方案、即种到n+1行、且n+1行什么都不种的方案
    return 0;
}
