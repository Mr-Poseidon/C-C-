#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510;

int g[N][N];//g[a][b]�����a��b�ľ���
int dis[N];//disά����ĳ���㵽�����������̾���
bool vis[N];//�ж��Ƿ���ʹ�

int n,m;

int dijkstra(int a,int b)//aΪ��㣬bΪ�յ�
{
    memset(dis,0x3f,sizeof dis);//��ʼ������ 
    dis[a]=0;//��㵽����ľ���Ϊ0 
    
    for(int i=0;i<n;i++)//�������еĵ�
    {
        int t=-1;//��Ǳ���������ǰ������̵ĵ�
        for(int j=1;j<=n;j++)//�������еĵ�
            if(!vis[j] && (t==-1 || dis[j]<dis[t]))//��δ���ʹ����߾��벻����С
                t=j;
        
        vis[t]=true;//��Ǹõ�
        
        for(int j=1;j<=n;j++)//����Ӹõ������������ľ�����Сֵ
            dis[j]=min(dis[j],dis[t]+g[t][j]);
    }
    
    if(dis[b]==0x3f3f3f3f)return -1;//�޷������յ�
    else return dis[b];//���Ե����յ�
}


int main()
{
    scanf("%d%d",&n,&m);
    memset(g,0x3f,sizeof g);//��ʼ��ͼ
    
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=min(g[a][b],c);//�ر�ȡ��Сֵ
    }
    
    int t=dijkstra(1,n);
    
    printf("%d",t);
    
    return 0;
}

