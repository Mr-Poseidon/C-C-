#include<iostream>
#include<algorithm>
using namespace std;
const int N=310;

int n,m;
int f[N][N],a[N][N];//f-��¼�����a-��¼ͼ 
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};//�ĸ����� 

int dp(int x,int y)
{
    if(f[x][y])return f[x][y];
    f[x][y]=1;
    
    for(int i=0;i<4;i++)//�����ĸ����� 
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx&&ny&&nx<=n&&ny<=m&&a[x][y]<a[nx][ny])
            f[x][y]=max(f[x][y],dp(nx,ny)+1);//ÿ����ֻ��¼���ֵ 
    }
    return f[x][y];
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)//����ͼ 
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
            
    int ans=0;
    for(int i=1;i<=n;i++)//����ÿ���� 
        for(int j=1;j<=m;j++)
            ans=max(ans,dp(i,j));
    cout<<ans;//������ 
    return 0;
}
