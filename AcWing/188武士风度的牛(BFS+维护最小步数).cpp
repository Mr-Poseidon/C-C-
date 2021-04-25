#include<iostream>
using namespace std;

const int N=155,M=N*N;
typedef pair<int,int> PII;
#define x first 
#define y second

int n,m;
char g[N][N];//ά��ͼ
bool vis[N][N];//ά���Ƿ���ʹ�
int step[N][N];//ά������

PII q[M];//��������
int hh,tt;

void bfs(int sx,int sy,int ex,int ey)
{
    hh=tt=0;
    q[tt++]={sx,sy};//������
    vis[sx][sy]=true;//���
    step[sx][sy]=0;//��㲽��Ϊ0
    
    while(hh<tt)
    {
        PII p=q[hh++];
        
        if(p.x==ex && p.y==ey)return;//�յ�
        
        int dir[8][2]={-2,-1,-2,1,2,-1,2,1,-1,-2,1,-2,-1,2,1,2};//�˸�����
        for(int i=0;i<8;i++)
        {
            int nx=p.x+dir[i][0],ny=p.y+dir[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//Խ��
            if(g[nx][ny]=='*' || vis[nx][ny])continue;//�ϰ�����߷��ʹ�
            
            q[tt++]={nx,ny};//���
            vis[nx][ny]=true;//���
            step[nx][ny]=step[p.x][p.y]+1;//��¼����
        }
    }
}

int main()
{
    cin>>m>>n;
    
    int sx,sy,ex,ey;//ά�������յ�����
    for(int i=0;i<n;i++)//����
        for(int j=0;j<m;j++)
        {
            cin>>g[i][j];
            if(g[i][j]=='K')//������⴦��
            {
                sx=i;
                sy=j;
                g[i][j]=='.';
            }
            if(g[i][j]=='H')//�յ����⴦��
            {
                ex=i;
                ey=j;
                g[i][j]=='.';
            }
        }
        
    bfs(sx,sy,ex,ey);//����
    
    cout<<step[ex][ey];//����յ㲽��
    return 0;
}
