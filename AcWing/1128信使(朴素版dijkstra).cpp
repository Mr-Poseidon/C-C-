#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=105,M=205;

int n,m;
int w[N][N];
int dis[N];
bool vis[N];

void dijkstra()//���ذ�dijkstra
{
    memset(dis,0x3f,sizeof dis);//�����ʼ��
    
    dis[1]=0;//������Ϊ0
    
    for(int i=0;i<n;i++)//����ÿһ����
    {
        int t=-1;
        for(int j=1;j<=n;j++)//����ÿһ���㣬ѡ��δ����ľ�����С�ĵ�
            if(!vis[j] && (t==-1 || dis[j]<dis[t]))
                t=j;
        
        if(t==-1)break;//���е㶼�����
        vis[t]=true;//���
        
        for(int j=1;j<=n;j++)//�����õ㵽�������е�ľ���
            if(dis[t]+w[t][j]<dis[j])//����
                dis[j]=dis[t]+w[t][j];
    }
    
}

int main()
{
    cin>>n>>m;
    
    memset(w,0x3f,sizeof w);//��ʼ��ͼ
    
    for(int i=0;i<m;i++)//����ͼ
    {
        int a,b,c;
        cin>>a>>b>>c;
        w[a][b]=w[b][a]=c;
    }
    
    dijkstra();

    //�������еĵ㣬ѡ���������ĵ�ľ��뼴Ϊ���
    int ans=-1;
    for(int i=1;i<=n;i++)ans=max(ans,dis[i]);
    
    if(ans==0x3f3f3f3f)puts("-1");//�����޷�����ĵ�
    else cout<<ans<<endl;
    
    return 0;
}
