#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

const int N=110,M=1<<10;

//注意：本题使用滚动数组，i&1 即可让数组滚动、因为每个数都是奇偶交替的 

int f[2][M][M];//滚动数组-f[i][a][b]维护摆放到第i行、且第i行状态为a，第i-1行状态为b所可以摆放的最大值
int w[N];//w[i]维护第i行的地形情况、1代表山地、0代表平地
vector<int> state;//维护所有合法状态，即在同一行中炮兵无法互相攻击到的状态
int cnt[M];//cnt[i]维护i这个状态中含有的炮兵数量，即1的数量
int n,m;

//判断在同一行中是否能互相攻击到，是-不合法false，不是-合法true
bool check(int state)
{
    for(int i=0;i<m;i++)
        if((state>>i & 1) && (state>>i+1 & 1 | state>>i+2 & 1))
            return false;
    return true;
}

//计算该状态中的炮兵数量
int count(int state)
{
    int ans=0;
    for(int i=0;i<m;i++)ans+=state>>i&1;
    return ans;
}

int main()
{
    cin>>n>>m;//输入
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            if(c=='H')
                w[i]+=1<<j;
        }
    
    //筛选出合法状态
    for(int i=0;i<(1<<m);i++)
        if(check(i))
        {
            state.push_back(i);
            cnt[i]=count(i);
        }
        
    for(int i=1;i<=n+2;i++)//枚举 第i行 的炮兵阵地
        for(int j=0;j<state.size();j++)//枚举 第i行 的状态
            for(int k=0;k<state.size();k++)//枚举 第i-1行 的状态
                for(int u=0;u<state.size();u++)//枚举 第i-2行 的状态
                {
                    int a=state[j],b=state[k],c=state[u];
                    if((a&b) | (a&c) | (b&c))continue;//三层状态不能互相攻击到，如果能互相攻击，就跳过
                    if((a&w[i]) | (b&w[i-1]) | (c&w[i-2]))continue;//炮兵存在放在山地的情况，所以跳过
                    f[i & 1][a][b]=max(f[i & 1][a][b],f[i-1 & 1][b][c]+cnt[a]);//状态转移方程
                }
                
    cout<<f[n+2 & 1][0][0];//结果是摆放到第i+2行、且i+1不摆放，i+2也不摆放的值
    return 0;
}

