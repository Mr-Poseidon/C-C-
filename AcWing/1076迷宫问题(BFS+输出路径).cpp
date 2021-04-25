#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef pair<int,int> PII;
#define x first 
#define y second

const int N=1010,M=N*N;

int g[N][N];
bool vis[N][N];
int n;

PII q[M];
int hh,tt;
PII pre[N][N];

void bfs(int sx,int sy,int ex,int ey)
{
    hh=tt=0;
    q[tt++]={sx,sy};//������
    vis[sx][sy]=true;//���
    pre[sx][sy]={sx,sy};//������һ����Ϊ����
    
    while(hh<tt)
    {
        PII p=q[hh++];
        
        if(p.x==ex && p.y==ey)return;//����Ѿ��ѵ��յ�ͽ�������
        
        int dir[4][2]={-1,0,0,1,1,0,0,-1};//�ĸ�����
        for(int i=0;i<4;i++)
        {
            int nx=p.x+dir[i][0],ny=p.y+dir[i][1];//��һ������
            
            if(nx<0 || nx>=n || ny<0 || ny>=n)continue;//Խ��
            if(g[nx][ny]==1 || vis[nx][ny])continue;//ǽ�������Ѿ��߹�
            
            q[tt++]={nx,ny};//���
            vis[nx][ny]=true;//���
            pre[nx][ny]=p;//��¼��һ�����ɱ����߹�ȥ
        }
    }
    return;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)//����
        for(int j=0;j<n;j++)
            cin>>g[i][j];
    
    bfs(n-1,n-1,0,0);//���ѣ����յ������ѡ��������·��
    
    //���·��
    PII t={0,0};
    do
    {
        cout<<t.x<<" "<<t.y<<endl;
        t=pre[t.x][t.y];
    }while(t!=pre[t.x][t.y]);//����һ��·�����ڱ�������յ�
    cout<<n-1<<" "<<n-1;//����յ�
    
    return 0;
}
