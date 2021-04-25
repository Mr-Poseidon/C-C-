#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

const int N=810,M=1500*2,INF=0x3f3f3f3f;
typedef long long ll;

int h[N],e[M],w[M],ne[M],idx;//�ڽӱ�
int cow[N];//ά��ÿͷţ���ڵ�����
int dis[N];//ά������
bool vis[N];//ά������״̬

int p,n,m;

void add(int a,int b,int c)//����
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

ll spfa(int u)//��uΪ��㵽ÿ����ľ���
{
    //��ʼ������ͷ���״̬
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    
    queue<int> q;//�������
    q.push(u);
    dis[u]=0;
    vis[u]=true;
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        vis[t]=false;
        
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(dis[j]>dis[t]+w[i])
            {
                dis[j]=dis[t]+w[i];
                if(!vis[j])
                {
                    q.push(j);
                    vis[j]=true;
                }
            }
        }
    }
  
    //�����u��ÿ����ţ�����������ܾ���
    ll sum=0;
    for(int i=0;i<p;i++)
        sum+=dis[cow[i]];
    
    return sum;
}
int main()
{
    cin>>p>>n>>m;//����
    for(int i=0;i<p;i++)cin>>cow[i];
    
    memset(h,-1,sizeof h);//��ʼ���ڽӱ�
    for(int i=0;i<m;i++)//����ͼ
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }
    
    ll ans=INF;//��ʼ�����
    for(int i=1;i<=n;i++)//��ÿһ������Ϊ�����spfa
    {
        ll t=spfa(i);
        if(t>INF)continue;//�����볬��INF˵���еĵ��޷�����
        else ans=min(ans,t);//ά����̾���
    }
    
    cout<<ans;//������
    return 0;
    
}

