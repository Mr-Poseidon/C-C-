#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=105;
typedef pair<int,int> PII;

int n,m;
int g[N][N];//����ͼ
int vis[N][N];//��¼�Ƿ���ʹ�
int d[N][N];//�����㵽���ľ���


PII q[N*N];//ģ�����
int hh,tt;
int dir[4][2]={0,1,1,0,0,-1,-1,0};//�������ĸ�����

void bfs()
{
    memset(vis,-1,sizeof(vis));//��ʼ����¼
    //������
    d[1][1]=0;
    q[0]={1,1};
    
    while(hh<=tt)//�Ӳ�Ϊ��
    {
        PII p=q[hh++];
        
        for(int i=0;i<4;i++)
        {
            //�����һ������
            int x=p.first+dir[i][0];
            int y=p.second+dir[i][1];
            
            if(x>0 && x<=n && y>0 && y<=m && g[x][y]!=1 && vis[x][y]==-1)//��һ�����������
            {
                vis[x][y]=1;//��¼�õ�
                d[x][y]=d[p.first][p.second]+1;//��¼����
                q[++tt]={x,y};//�õ����
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);//����
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&g[i][j]);
            
    bfs();//����
    
    printf("%d",d[n][m]);//���
    
    return 0;
}

