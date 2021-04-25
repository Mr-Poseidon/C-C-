#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=510,INF=0x3f3f3f3f;

int g[N][N];
int dis[N];
bool vis[N];
int n,m;


int prim()
{
    memset(dis,0x3f,sizeof(dis));//��ʼ������
    
    int sum=0;//��С�������Ĵ�С
    for(int i=0;i<n;i++)//����n��
    {
        int t=-1;
        for(int j=1;j<=n;j++)//�Ҿ�����С������û��ʹ�ù��ĵ�
            if(!vis[j] && (t==-1 || dis[j]<dis[t]))
                t=j;
                
        vis[t]=true;//���
        if(i && dis[t]==INF)return INF;//����ҵ��ĵ㣬���������˵�����ﲻ�ˡ�û����С������
        if(i)sum+=dis[t];//����·��
        
        for(int j=1;j<=n;j++)//������С�ĵ㵽������ľ���
            dis[j]=min(dis[j],g[t][j]);
    }
    return sum;//������С������
}

int main()
{
    memset(g,0x3f,sizeof(g));//��ʼ���ڽӾ���
    
    scanf("%d%d",&n,&m);
    
    while(m--)//�����
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=g[b][a]=min(g[a][b],c);//�ر�ȡ��Сֵ������ͼ�����߶�Ҫ��ֵ
    }
    
    int t=prim();
    
    if(t==INF)puts("impossible");
    else printf("%d",t);
    
    return 0;
}
