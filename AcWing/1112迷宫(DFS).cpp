#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=110;

char g[N][N];//ά��ͼ
bool vis[N][N];//ά���Ƿ���ʹ�
int T,n;
int ax,ay,bx,by;

bool dfs(int x,int y)//����
{
    if(x<0 || x>=n || y<0 || y>=n)return false;//Խ��
    if(vis[x][y])return false;//���ʹ���
    if(g[x][y]=='#')return false;//�ϰ�
    
    if(x==bx && y==by)return true;//�յ�
    
    vis[x][y]=true;//���
    
    int d[4][2]={0,-1,-1,0,0,1,1,0};
    
    for(int i=0;i<4;i++)//�����ĸ�����
    {
        int nx=x+d[i][0],ny=y+d[i][1];
        
        if(dfs(nx,ny))return true;//��һ����������
    }
    
    return false;//�ĸ�����û�취�ߵ�
}

int main()
{
    cin>>T;
    while(T--)//�����������
    {
        cin>>n;//����
        for(int i=0;i<n;i++)cin>>g[i];
        cin>>ax>>ay>>bx>>by;
        
        memset(vis,0,sizeof(vis));//��ǳ�ʼ��
        
        if(dfs(ax,ay))puts("YES");//���Ե���
        else puts("NO");//�޷�����
    }
    return 0;
}
