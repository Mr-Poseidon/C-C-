#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1010,M=N*N;
typedef pair<int,int> PII;
#define x first
#define y second

int g[N][N];//维护地图
bool vis[N][N];//维护访问情况
int n;

PII q[M];//维护单调队列
int hh,tt;

void bfs(int sx,int sy,bool& isp,bool& isv)//广搜，isp代表是山峰，isv代表是山谷
{
    hh=tt=0;
    q[tt++]={sx,sy};//起点入队
    vis[sx][sy]=true;//标记
    
    while(hh<tt)
    {
        PII p=q[hh++];
        
        for(int i=p.x-1;i<=p.x+1;i++)//遍历八个方向
            for(int j=p.y-1;j<=p.y+1;j++)
            {
                if(i==p.x && j==p.y)continue;//本身、跳过
                if(i<0 || i>=n || j<0 || j>=n)continue;//越界、跳过
                
                if(g[i][j]==g[sx][sy] && !vis[i][j])//等于本身、又没有访问过、入队
                {
                    q[tt++]={i,j};
                    vis[i][j]=true;
                }
                else if(g[i][j]!=g[sx][sy])//不等于本身、肯定是周边
                {
                    if(g[i][j]<g[sx][sy])isv=false;//周边小于本身、本身就肯定不是山谷
                    else isp=false;//周边大于本身、本身肯定不是山峰
                }
            }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)//输入
        for(int j=0;j<n;j++)
            cin>>g[i][j];
    
    int peak=0,valley=0;//维护山峰、山谷的数量
    for(int i=0;i<n;i++)//遍历每一个点
        for(int j=0;j<n;j++)
            if(!vis[i][j])//未访问过
            {
                bool isp=true,isv=true;
                bfs(i,j,isp,isv);//此处山峰和山谷的bool值传的是地址
                if(isp)peak++;//如果是山峰
                if(isv)valley++;//如果是山谷
            }
    
    cout<<peak<<" "<<valley;//输出
    return 0;
}

