#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int N=25;

char mp[N][N];//维护图
int vis[N][N];//判断是否走过
int n,m;

int dfs(int x,int y)//深搜
{
    int ans=0;
    if(x>0 && x<=n && y>0 && y<=m && mp[x][y]=='.' && vis[x][y]==0)//符合条件
    {
        vis[x][y]=1;
        ans++;//记录本身
        
        //四个方向可以走到的数量
        ans+=dfs(x+1,y);
        ans+=dfs(x,y+1);
        ans+=dfs(x-1,y);
        ans+=dfs(x,y-1);
    }
    return ans;//返回结果
}

int main()
{
    while(cin>>m>>n && n && m)//数据组数
    {
        memset(vis,0,sizeof vis);//初始化标记
        
        int x,y;
        for(int i=1;i<=n;i++)//输入图
            for(int j=1;j<=m;j++)
            {
                cin>>mp[i][j];
                
                if(mp[i][j]=='@')//标记起点
                {
                    x=i;
                    y=j;
                    mp[x][y]='.';
                }
            }
        
        cout<<dfs(x,y)<<endl;//深搜，输出结果
    }
    return 0;
}
