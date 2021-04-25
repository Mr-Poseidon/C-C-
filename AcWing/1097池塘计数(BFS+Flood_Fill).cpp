#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define x first
#define y second

const int N=1010,M=N*N;
typedef pair<int,int> PII;

char g[N][N];//ά��ͼ
int n,m;
bool vis[N][N];//ά���Ƿ���ʹ�

PII q[M];//ά����������
int hh,tt;

void bfs(int sx,int sy)//��������������ͨ��
{
    hh=tt=0;
    q[tt++]={sx,sy};//������
    vis[sx][sy]=true;//���
    
    while(hh<tt)
    {
        PII p=q[hh++];//ȡ��ͷ
        
        for(int i=p.x-1;i<=p.x+1;i++)
            for(int j=p.y-1;j<=p.y+1;j++)
            {
                if(i==p.x && j==p.y)continue;//����Ǳ�������
                if(i<0 || i>=n || j<0 || j>=m)continue;//Խ�硢����
                if(g[i][j]=='W' && !vis[i][j])//��ˮ�ز���û�з��ʹ�
                {
                    q[tt++]={i,j};//���
                    vis[i][j]=true;//���
                }
            }
    }
}
int main()
{
    scanf("%d%d",&n,&m);//����
    for(int i=0;i<n;i++)scanf("%s",g[i]);
    
    int cnt=0;
    for(int i=0;i<n;i++)//����ÿһ����
        for(int j=0;j<m;j++)
            if(g[i][j]=='W' && !vis[i][j])
            {
                bfs(i,j);
                cnt++;
            }
             
    printf("%d\n",cnt);//�����ͨ����
    return 0;
}

