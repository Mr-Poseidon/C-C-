#include<cstdio>
#include<iostream>
using namespace std;

typedef pair<int,int> PII;
#define x first 
#define y second
const int N=1010,M=N*N;

char g[N][N];
bool vis[N][N];
int step[N][N];
int n,m;

PII q[M];
int hh,tt;

//��Դ��㡢��Դ�յ㡢���Խ��յ㿴����㡢����BFS���������

int main()
{
    cin>>n>>m;//����ͼ
    for(int i=0;i<n;i++)scanf("%s",g[i]);
    
    hh=tt=0;//��ʼ����������
    for(int i=0;i<n;i++)//������Ϊ1�ĵ���ӡ�����ǡ���ʼ������Ϊ0
        for(int j=0;j<m;j++)
            if(g[i][j]=='1')
            {
                q[tt++]={i,j};
                vis[i][j]=true;
                step[i][j]=0;
            }
            
    //BFS
    while(hh<tt)
    {
        PII p=q[hh++];
        
        int d[4][2]={0,-1,-1,0,0,1,1,0};
        
        for(int i=0;i<4;i++)//�����ĸ�����
        {
            int nx=p.x+d[i][0],ny=p.y+d[i][1];
            
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;//Խ��
            if(vis[nx][ny])continue;//���ʹ�
            
            q[tt++]={nx,ny};//���
            vis[nx][ny]=true;//���
            step[nx][ny]=step[p.x][p.y]+1;//����+1
        }
    }
    
    for(int i=0;i<n;i++)//������еľ������
    {
        for(int j=0;j<m;j++)cout<<step[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}
