#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int N=25;
typedef pair<int,int> PII;

char mp[N][N];//维护图
int vis[N][N];//判断是否走过
int n,m;

int dir[4][2]={1,0,0,1,-1,0,0,-1};//四个方向

int main()
{
    while(cin>>m>>n && n && m)//数据组数
    {
        queue<PII> q;//队列
        int ans=0;//答案
        memset(vis,0,sizeof vis);//初始化标记
        
        for(int i=1;i<=n;i++)//输入图
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
                
                if(mp[i][j]=='@')//标记起点、入队
                {
                    q.push({i,j});
                    ans++;
                }
            }
                
        
        while(!q.empty())//广搜
        {
            PII p=q.front();//出队
            q.pop();
            
            for(int i=0;i<4;i++)//遍历四个方向
            {
                int x=p.first+dir[i][0];
                int y=p.second+dir[i][1];
                
                if(x>0 && x<=n && y>0 && y<=m && vis[x][y]==0 && mp[x][y]=='.')//符合条件
                {
                    vis[x][y]=1;//标记
                    ans++;//可以走到的数量+1
                    q.push({x,y});//入队
                }
            }
        }
        
        cout<<ans<<endl;//输出结果
    }
    return 0;
}
