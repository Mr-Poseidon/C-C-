#include<iostream>
using namespace std;

const int N=2e5+10;

int n,m;
bool vis[N];//维护每个点的访问情况
int step[N];//维护每个点的步数
int q[N],hh,tt;//单调队列

void bfs(int s,int e)//广搜
{
    hh=tt=0;
    q[tt++]=s;//入队
    vis[s]=true;//标记
    step[s]=0;//起点步数为0
    
    while(hh<tt)
    {
        int p=q[hh++];
        if(p==e)return;
        
        int d[3][2]={1,-1,1,1,2,0};//维护三个方向
        for(int i=0;i<3;i++)
        {
            int np=p*d[i][0]+d[i][1];//下一个点
            
            if(np<0 || np>2*e)continue;//越界
            if(vis[np])continue;//已经访问过
            
            q[tt++]=np;//入队
            vis[np]=true;//标记
            step[np]=step[p]+1;//步数+1
        }
    }
}

int main()
{
    cin>>n>>m;
    
    if(n>m)cout<<n-m;//如果牛在人前面
    else 
    {
        //牛在人后面
        bfs(n,m);
        cout<<step[m];
    }
    return 0;
}
