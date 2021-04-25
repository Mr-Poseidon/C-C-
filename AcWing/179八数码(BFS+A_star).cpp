#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<queue>
#include<cmath>
using namespace std;

typedef pair<int,string> PIS;
#define x first
#define y second

//在八数码或者十五数码中，只有逆序对的数量是偶数时、才有解
//BFS+IDA*算法，一个点可能入队两次，类似dijistra算法、但是终点只在第一次出队的时候距离最短

string a,b;//a存初始的状态、b存没有x的状态、方便求逆序对
unordered_map<string,int> dis;//维护每个状态的距离
unordered_map<string,string> path;//维护每个状态的行动记录
priority_queue<PIS,vector<PIS>,greater<PIS>> q;//维护（真实距离+估值距离）的优先队列

char moves[4]={'u','l','r','d'};//代表四个方向上的四个状态
int d[4][2]={-1,0,0,-1,0,1,1,0};//对应的四个方向-上左右下


int f(string s)//估值函数-求每个状态中每个数值的曼哈顿路径
{
    int ans=0;
    for(int i=0;i<s.size();i++)
        if(s[i]!='x')//是x则跳过
        {
            int t=s[i]-'1';//求出正确的位置
            ans+=abs(i/3 - t/3)+abs(i%3 - t%3);//求该值与正确位置的曼哈顿路径的值
        }
    return ans;//返回该状态对应的曼哈顿路径值的总和
}

void bfs(string state)//广搜
{
    dis[state]=0;//起点距离为0
    path[state]="";//起点行动记录为空
    q.push({0+f(state),state});//入队
    
    while(q.size())
    {
        PIS p=q.top();
        q.pop();
        
        state=p.y;//取状态
        if(state=="12345678x")return;//到达终点、结束
        
        int xs;
        for(int i=0;i<9;i++)//求出该状态中x所在的位置
            if(state[i]=='x')
            {
                xs=i;
                break;
            }
        
        for(int i=0;i<4;i++)//搜索四个方向
        {
            // xs/3 代表行, xs%3 代表列 
            int nx=xs/3+d[i][0],ny=xs%3+d[i][1];//计算下一个方向的行列
            if(nx<0 || nx>=3 || ny<0 || ny>=3)continue;//越界
            
            int nxs=nx*3+ny;//求出下一个方向所对应的位置
            
            swap(state[xs],state[nxs]);//交换、扩展成下一个状态
            if(dis.count(state)==0 || dis[state]+1>dis[p.y])//该状态不存在 或者 该状态可以更新 
            {
                dis[state]=dis[p.y]+1;//距离+1
                path[state]=path[p.y]+moves[i];//更新行动记录
                q.push({dis[state]+f(state),state});//入队
            }
            swap(state[xs],state[nxs]);//恢复状态
        }
    }
    return;
}
int main()
{
    for(int i=0;i<9;i++)//输入
    {
        char t;
        cin>>t;
        a+=t;
        if(t!='x')b+=t;
    }
    
    int cnt=0;
    for(int i=0;i<8;i++)//求起始状态的逆序数对
        for(int j=i+1;j<8;j++)
            if(b[i]>b[j])
                cnt++;
    
    if(cnt%2!=0)cout<<"unsolvable"<<endl;//逆序数对为奇数，无解
    else//逆序数对为偶数、深搜并输出行动路径
    {
        bfs(a);
        cout<<path["12345678x"]<<endl;
    }
    
    return 0;
}
