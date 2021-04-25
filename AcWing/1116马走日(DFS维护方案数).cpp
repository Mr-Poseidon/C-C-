#include<iostream>
#include<cstring>
using namespace std;

const int N=15;

bool vis[N][N];
int n,m,x,y;
int ans;

void dfs(int x,int y,int cnt)//深搜，x,y代表目前的坐标，cnt代表目前的坐标是搜到的第几个点
{
    if(cnt==n*m)//全部搜到
    {
        ans++;
        return;
    }
    
    vis[x][y]=true;//标记
    
    int d[8][2]={-1,-2,1,-2,-2,-1,-2,1,-1,2,1,2,2,-1,2,1};
    for(int i=0;i<8;i++)//遍历八个方向
    {
        int nx=x+d[i][0],ny=y+d[i][1];
        
        if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//越界
        if(vis[nx][ny])continue;//访问过
        
        dfs(nx,ny,cnt+1);
    }
    
    vis[x][y]=false;//取消标记
    return;
}

int main()
{
    int T;
    cin>>T;
    while(T--)//多组测试数据
    {
        cin>>n>>m>>x>>y;//输入
        
        //初始化数据
        memset(vis,0,sizeof vis);
        ans=0;
        
        dfs(x,y,1);//深搜
        
        cout<<ans<<endl;//输出答案
    }
    return 0;
}
