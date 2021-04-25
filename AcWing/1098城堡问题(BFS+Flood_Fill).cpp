#include<iostream>
#include<algorithm>
using namespace std;

const int N=55,M=N*N;
typedef pair<int,int> PII;
#define x first
#define y second

int g[N][N];//ά��ÿ����������
bool vis[N][N];//ά�������Ƿ񱻷��ʹ�
int n,m;

PII q[M];
int hh,tt;

int bfs(int sx,int sy)//�����ж���ͨ�������ط����������
{
    hh=tt=0;
    q[tt++]={sx,sy};//������
    vis[sx][sy]=true;//���
    
    int area=0;//�������
    int dir[4][2]={0,-1,-1,0,0,1,1,0};//�ĸ�����
    while(hh<tt)
    {
        PII p=q[hh++];//����
        area++;//���ӵ�ʱ���¼�������
        
        for(int i=0;i<4;i++)//�����ĸ�����
        {
            int nx=p.x+dir[i][0],ny=p.y+dir[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//Խ������
            if(vis[nx][ny])continue;//�Ѿ����ʹ�������
            if(g[p.x][p.y]>>i&1)continue;//����ǽ�桢����
            
            q[tt++]={nx,ny};//���
            vis[nx][ny]=true;//���
        }
    }
    return area;//���ط������
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)//����ÿ����������
        for(int j=0;j<m;j++)
            cin>>g[i][j];
            
    int cnt=0,area=0;//��¼�����������ķ������
    for(int i=0;i<n;i++)//����ÿһ������
        for(int j=0;j<m;j++)
            if(!vis[i][j])
            {
                cnt++;
                area=max(area,bfs(i,j));//ά�����ķ������
            }
    
    cout<<cnt<<endl;//���
    cout<<area<<endl;
    return 0;
}

