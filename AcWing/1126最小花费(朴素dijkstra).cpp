#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=2010;

double w[N][N];//ά����֮��Ļ���
double dis[N];//ά��������֮���������
bool vis[N];
int n,m,A,B;

//��ΪҪ�������ʡ�����ά�����ֵ
void dijkstra()
{
    memset(dis,0,sizeof dis);
    dis[A]=1;
    
    for(int i=1;i<=n;i++)
    {
        int t=-1;
        for(int j=1;j<=n;j++)
            if(!vis[j] && (t==-1 || dis[t]<dis[j]))
                t=j;
                
        vis[t]=true;
        
        for(int j=1;j<=n;j++)
            dis[j]=max(dis[j],dis[t]*w[t][j]);//״̬ת�Ʒ���
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    
    memset(w,0,sizeof w);//����ͼ
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        w[a][b]=w[b][a]=max(w[a][b],(100-c)/100.0);//ά����Сֵ
    }
    scanf("%d%d",&A,&B);//��������
    
    dijkstra();
    
    printf("%.8lf",100.0/dis[B]);//������
    return 0;
    
}
