#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=25;

char g[N][N];//ά��ͼ
bool vis[N][N];//ά���������
int n,m;

int dfs(int x,int y)//���ѣ����ط��ʵĵ������
{
    int ans=1;//�������һ����
    vis[x][y]=true;//���
    
    int d[4][2]={0,-1,-1,0,0,1,1,0};//�ĸ�����
    for(int i=0;i<4;i++)
    {
        int nx=x+d[i][0],ny=y+d[i][1];
        
        if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//Խ��
        if(vis[nx][ny] || g[nx][ny]=='#')continue;//���ʹ��������ϰ�
        
        ans+=dfs(nx,ny);//����
    }
    return ans;//���ؽ��
}

int main()
{
    while(cin>>m>>n && n && m)//�����������
    {
        for(int i=0;i<n;i++)cin>>g[i];//����ͼ
        
        int x,y;
        for(int i=0;i<n;i++)//Ѱ�����
            for(int j=0;j<m;j++)
                if(g[i][j]=='@')
                {
                    x=i;
                    y=j;
                }
        
        memset(vis,0,sizeof vis);//��ʼ���������
        cout<<dfs(x,y)<<endl;//���Ѳ�������
    }
    return 0;
}
